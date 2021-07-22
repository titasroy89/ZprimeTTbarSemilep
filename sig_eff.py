#from ROOT import TFile, TLegend, TCanvas, TPad, THStack, TF1, TPaveText, TGaxis, SetOwnership, TObject, gStyle,TH1F

import os

import sys
from optparse import OptionParser

from numpy import log10
from array import array




parser = OptionParser()
parser.add_option("-c", "--channel", dest="channel", default="mu",type='str',
                     help="Specify which channel mu or ele? default is mu" )
parser.add_option("--Log","--isLog", dest="isLog", default=True,action="store_true",
                     help="Plot the plots in log ?" )
parser.add_option("--QCD","--isQCD", dest="isQCD", default=False,action="store_true",
                     help="Plot as QCD and others" )
parser.add_option("--signal","--isSignal", dest="isSignal", default=False,action="store_true",
                      help="Plot just signal" )

(options, args) = parser.parse_args()

from ROOT import *
padRatio = 0.25
padOverlap = 0.15

padGap = 0.01


channel = options.channel
Log=options.isLog
QCD = options.isQCD
signal =options.isSignal

if channel=="ele":
	_channelText = "e+jets"
	plotDirectory = "data_pre_plots_ele"
#	_fileDir = "/nfs/dust/cms/user/titasroy/Run2_analysis_DNN/electron/2018/workdir_Zprime_Analysis_electron_DNN_Aug26/NOMINAL"
        _fileDir = "/nfs/dust/cms/user/titasroy/Run2_analysis_DNN/electron/2018/workdir_Nov/NOMINAL"
else:
	_channelText = "#mu+jets"
	plotDirectory = "data_pre_plots_mu"
       # _fileDir = "/nfs/dust/cms/user/titasroy/Run2_analysis_DNN/muon/2018/workdir_Zprime_Analysis_muon_QCDNN_May19/NOMINAL_1"
        _fileDir = "/nfs/dust/cms/user/titasroy/Run2_analysis_DNN/muon/2018/workdir_Zprime_Analysis_muon_Nov/NOMINAL"



gROOT.SetBatch(True)



# Histogram Information:
# [X-axis title, 
#  Y-axis title,
#  Rebinning factor,
#  [x-min,x-max], -1 means keep as is
#  Extra text about region
#  log plot]
regionText ="loose selection"



import CMS_lumi

from Style import *
thestyle = Style()

HasCMSStyle = False
style = None
if os.path.isfile('tdrstyle.C'):
    ROOT.gROOT.ProcessLine('.L tdrstyle.C')
    ROOT.setTDRStyle()
    print "Found tdrstyle.C file, using this style."
    HasCMSStyle = True
    if os.path.isfile('CMSTopStyle.cc'):
        gROOT.ProcessLine('.L CMSTopStyle.cc+')
        style = CMSTopStyle()
        style.setupICHEPv1()
        print "Found CMSTopStyle.cc file, use TOP style if requested in xml file."
if not HasCMSStyle:
    print "Using default style defined in cuy package."
    thestyle.SetStyle()

ROOT.gROOT.ForceStyle()

stackList = { "TTbar":[kRed], "DYJets":[kGreen], "QCD":[kYellow],"WJets":[kBlue], "ST":[kOrange], "Diboson":[kTeal]}
if QCD:
	stackList = { "TTbar":[kRed], "DYJets":[kRed], "QCD":[kYellow],"WJets":[kRed], "ST":[kRed], "Diboson":[kRed]}
if signal:
	stackList = { "ZprimeToTT_M500":[kRed], "ZprimeToTT_M2000":[kYellow],"ZprimeToTT_M3000":[kBlue], "ZprimeToTT_M6000":[kMagenta], "ZprimeToTT_M8000":[kTeal], "ZprimeToTT_M9000":[kGreen]}

#print stackList
#print stackList[2]




CMS_lumi.channelText = _channelText
CMS_lumi.writeChannelText = True
CMS_lumi.writeExtraText = True


H = 600;
W = 800;


# references for T, B, L, R                                                                                                             
T = 0.08*H
B = 0.12*H
L = 0.12*W
R = 0.1*W


# SetOwnership(canvas, False)
# SetOwnership(canvasRatio, False)
# SetOwnership(pad1, False)
# SetOwnership(pad2, False)



legendHeightPer = 0.04
legList = stackList.keys() 
#legList.reverse()

legendStart = 0.69
legendEnd = 0.97-(R/W)

#legend = TLegend(2*legendStart - legendEnd, 1-T/H-0.01 - legendHeightPer*(len(legList)+1), legendEnd, 0.99-(T/H)-0.01)
legend = TLegend(2*legendStart - legendEnd , 0.99 - (T/H)/(1.-padRatio+padOverlap) - legendHeightPer/(1.-padRatio+padOverlap)*round((len(legList)+1)/2.), legendEnd, 0.99-(T/H)/(1.-padRatio+padOverlap))
legend.SetNColumns(2)



_file={}


canvas = TCanvas('c1','c1',W,H)
canvas.SetFillColor(0)
canvas.SetBorderMode(0)
canvas.SetFrameFillStyle(0)
canvas.SetFrameBorderMode(0)
canvas.SetLeftMargin( L/W )
canvas.SetRightMargin( R/W )
canvas.SetTopMargin( T/H )
canvas.SetBottomMargin( B/H )
canvas.SetTickx(0)

canvas.cd()
canvas.ResetDrawn()
canvas.cd()

sum_=0
tree_MC={}

hist={}

if signal:
	histograms = {"met_pt"   : ["missing E_{T} [GeV]", "Events", 10, [50,1500]]}

sample_names = ["ZprimeToTT_M9000", "ZprimeToTT_M8000","ZprimeToTT_M6000", "ZprimeToTT_M3000","ZprimeToTT_M2000","ZprimeToTT_M500"]

legendR={}

for histName in histograms:
	
        legendR[histName] = TLegend(2*legendStart - legendEnd , 0.99 - (T/H)/(1.-padRatio+padOverlap) - legendHeightPer/(1.-padRatio+padOverlap)*round((len(legList)+1)/2.)-0.1, legendEnd, 0.99-(T/H)/(1.-padRatio+padOverlap))

	legendR[histName].SetNColumns(2)

	legendR[histName].SetBorderSize(0)
	legendR[histName].SetFillColor(0)

histName="met_pt"
#print sample_names[1:]
canvas.cd()





for sample in sample_names:
 		
        	print sample, histName
		_file[sample] = TFile("%s/uhh2.AnalysisModuleRunner.MC.%s_2018_0.root"%(_fileDir,sample),"read")
		tree_MC[sample]=_file[sample].Get("AnalysisTree")
#		print "%s>>h_%s_%s(%i,%f,%f)"%(histName,histName,sample,histograms[histName][2],histograms[histName][3][0],histograms[histName][3][1]),"weight*weight_pu*(eta_ele<=2.0 && eta_ele>=-2.0)"
        	tree_MC[sample].Draw("%s>>h_%s_%s(%i,%f,%f)"%(histName,histName,sample,histograms[histName][2],histograms[histName][3][0],histograms[histName][3][1]),"weight*weight_pu","goff")
        	hist[sample] = gDirectory.Get("h_%s_%s"%(histName,sample))
		hist[sample].SetDirectory(0)
		print hist[sample].Integral()
        	hist[sample].SetLineColor(stackList[sample][0])
                hist[sample].SetMarkerColor(stackList[sample][0])
		hist[sample].SetMarkerSize(0)
                hist[sample].SetMarkerStyle(1)
                hist[sample].SetLineStyle(2)
                legendR[histName].AddEntry(hist[sample],sample,'l')
        	hist[sample].SetYTitle(histograms[histName][1])      
                hist[sample].SetXTitle(histograms[histName][0]) 
		print "about to draw:",sample
		if sample=="ZprimeToTT_M9000":
			print "drawing first"
			hist[sample].Draw("hist")
		else:
			hist[sample].Draw("hist,SAME")
legendR[histName].Draw()
		   

canvas.SetLogy(1)	
canvas.SaveAs("%s/%s_signal_fulleta.pdf"%(plotDirectory,histName))
canvas.Clear()


