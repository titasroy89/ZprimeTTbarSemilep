#from ROOT import TFile, TLegend, TCanvas, TPad, THStack, TF1, TPaveText, TGaxis, SetOwnership, TObject, gStyle,TH1F
from ROOT import *
import os

import sys
from optparse import OptionParser

from numpy import log10
from array import array


padRatio = 0.25
padOverlap = 0.15

padGap = 0.01

plotDirectory = "pre_elData_MC"
_fileDir = "/nfs/dust/cms/user/titasroy/Run2_analysis_DNN/electron/2018/workdir_eleDec/NOMINAL/"
#_fileDir ="/nfs/dust/cms/user/titasroy/Run2_analysis_DNNimplement/muon/2018/workdir_Zprime_Analysis_muon_NNwithcuts_Oct14/Nominal/"

gROOT.SetBatch(True)

YesLog = True
NoLog=False


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

print stackList
#print stackList[2]



#_channelText = "#mu+jets"
_channelText="e+jets"

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


legendR = TLegend(2*legendStart - legendEnd , 0.99 - (T/H)/(1.-padRatio+padOverlap) - legendHeightPer/(1.-padRatio+padOverlap)*round((len(legList)+1)/2.)-0.1, legendEnd, 0.99-(T/H)/(1.-padRatio+padOverlap))

legendR.SetNColumns(2)

legendR.SetBorderSize(0)
legendR.SetFillColor(0)



legend.SetBorderSize(0)
legend.SetFillColor(0)

_file = {}




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

canvasRatio = TCanvas('c1Ratio','c1Ratio',W,H)
canvasRatio.SetFillColor(0)
canvasRatio.SetBorderMode(0)
canvasRatio.SetFrameFillStyle(0)
canvasRatio.SetFrameBorderMode(0)
canvasRatio.SetLeftMargin( L/W )
canvasRatio.SetRightMargin( R/W )
canvasRatio.SetTopMargin( T/H )
canvasRatio.SetBottomMargin( B/H )
canvasRatio.SetTickx(0)
canvasRatio.SetTicky(0)
canvasRatio.Draw()
canvasRatio.cd()


pad1 = TPad("zxc_p1","zxc_p1",0,padRatio-padOverlap,1,1)
pad2 = TPad("qwe_p2","qwe_p2",0,0,1,padRatio+padOverlap)
pad1.SetLeftMargin( L/W )
pad1.SetRightMargin( R/W )
pad1.SetTopMargin( T/H/(1-padRatio+padOverlap) )
pad1.SetBottomMargin( (padOverlap+padGap)/(1-padRatio+padOverlap) )
pad2.SetLeftMargin( L/W )
pad2.SetRightMargin( R/W )
pad2.SetTopMargin( (padOverlap)/(padRatio+padOverlap) )
pad2.SetBottomMargin( B/H/(padRatio+padOverlap) )
pad1.SetFillColor(0)
pad1.SetBorderMode(0)
pad1.SetFrameFillStyle(0)
pad1.SetFrameBorderMode(0)
pad1.SetTickx(0)
pad1.SetTicky(0)

pad2.SetFillColor(0)
pad2.SetFillStyle(4000)
pad2.SetBorderMode(0)
pad2.SetFrameFillStyle(0)
pad2.SetFrameBorderMode(0)
pad2.SetTickx(0)
pad2.SetTicky(0)


canvasRatio.cd()
pad1.Draw()
pad2.Draw()


canvas.cd()


canvas.ResetDrawn()

stack = THStack("hs","stack")
#SetOwnership(stack,True)
#histName="phi_Ak8Puppijets"
sum_=0
tree_MC={}
tree2_MC={}
hist={}
hist1_={}
histo={}
histograms = {"met_pt"   : ["missing E_{T} [GeV]", "Events", 10, [50,1500]],
	      "phi_Ak8Puppijets": ["#phi^{AK8Puppi jets}", "Events", 35, [-3.5, 3.5]], 
              "phi_jet": ["#phi^{AK4 jets}", "Events", 35, [-3.5, 3.5]],
              "dphi_jet1_MET":["#Delta#phi(jet1, MET)""Events", 40, [0, 4.0]],
              "dphi_mu_MET":  ["#Delta#phi(#mu, MET)""Events", 40, [0, 4.0]],            
              "st"    : ["S_{T} [GeV]", "Events", 50, [0,5000]],
              "deepjetbscore_jet": ["DeepJet b-tag score all AK4 jets", "Events",20, [0, 1]],
              "deepjetbscore_jet1": ["DeppJet b-tag score AK4 jet 1}", "Events",20, [0, 1]],
              "pt_jet1": ["p_{T}^{jet 1} [GeV]", "Events", 20, [100, 900]],
              "pt_jet": ["p_{T}^{jet} [GeV]","Events", 20, [100, 900]],
              "pt_mu":[ "p_{T}^{#mu} [GeV]", "Events",50, [50, 500]],
              "reliso_mu":[ "#mu rel. Iso", "Events", 20, [0, 0.5]],
              "dR_mu_jet":[ "#DeltaR_{min}(#mu, jet)","Events", 60,[ 0, 3]],
              "ptrel_mu_jet":["p_{T}^{rel}(#mu1, jet)", "Events",50, [0, 500]],}


sample_names = ["QCD", "Diboson","ST", "DYJets", "WJets","TTbar"]

for histName in histograms:
	stack = THStack("hs","stack")
	for sample in sample_names:
 		h1=TH1F("h1","h1",10, 50, 1500)
        	print sample, histName
		_file[sample] = TFile("%s/uhh2.AnalysisModuleRunner.MC.%s.root"%(_fileDir,sample),"read")
        	print "%s/uhh2.AnalysisModuleRunner.MC.%s.root"%(_fileDir,sample)
#                histo[sample]=_file[sample].Get("HTlep_General/MET_rebin3")
 #               print " from folder:",sample,histo[sample].Integral() 
		tree_MC[sample]=_file[sample].Get("AnalysisTree")
#                tree_MC[sample].Draw("%s>>h_%s(%i,%i,%f)"%(histName,sample,histograms[histName][2],histograms[histName][3][0],histograms[histName][3][1]),"weight*weight_sfmu_HighPtID*weight_pu*weight_sfmu_Trigger")
		tree_MC[sample].Draw("%s>>h_%s(%i,%i,%f)"%(histName,sample,histograms[histName][2],histograms[histName][3][0],histograms[histName][3][1]),"weight*weight_pu")
		hist[sample] = tree_MC[sample].GetHistogram()
         #       print " with weight :",sample, hist[sample].Integral()

	#	tree2_MC[sample]=_file[sample].Get("AnalysisTree")
         #       tree2_MC[sample].Draw("%s>>h2_%s(%i,%i,%f)"%(histName,sample,histograms[histName][2],histograms[histName][3][0],histograms[histName][3][1]),"weight*weight_pu")
                hist1_[sample] = tree_MC[sample].GetHistogram()
#                print " without weight :",sample, hist1_[sample].Integral()

                
      	  	hist1_[sample].SetFillColor(stackList[sample][0])
        	hist1_[sample].SetLineColor(stackList[sample][0])
                
		legendR.AddEntry(hist1_[sample],sample,'f')       
        	hist1_[sample].SetYTitle(histograms[histName][1])        
		stack.Add(hist1_[sample])     


_file["Data"] = TFile("%s/uhh2.AnalysisModuleRunner.DATA.DATA.root"%(_fileDir),"read")
print "%s/uhh2.AnalysisModuleRunner.DATA.DATA.root"%(_fileDir)

tree = _file["Data"].Get("AnalysisTree")
tree.Draw("%s>>dat_hist(%i,%i,%f)"%(histName,histograms[histName][2],histograms[histName][3][0],histograms[histName][3][1]))
dataHist=tree.GetHistogram()
print "total:",dataHist.Integral()
print "bins:",dataHist.GetNbinsX()
data=dataHist.GetBinContent(1)
print data
dataHist.SetMarkerColor(kBlack)
#dataHist.SetXTitle(histograms[histName][0])
dataHist.SetYTitle(histograms[histName][1])     
dataHist.Draw("pe,x0")
stack.Draw("HIST,SAME")

#stack.Draw("HIST")
#dataHist.Draw("pe,x0,same")    
#stack.Draw('hist')

oneLine = TF1("oneline","1",-9e9,9e9)
oneLine.SetLineColor(kBlack)
oneLine.SetLineWidth(1)
oneLine.SetLineStyle(2)
	

maxVal = stack.GetMaximum()

minVal = 1
minVal = max(stack.GetStack()[0].GetMinimum(),1)
print minVal, maxVal

print "data, top:",dataHist.GetBinContent(1)

print "max stack:",1.5*maxVal
log=1
if log:
	stack.SetMaximum(10**(1.5*log10(maxVal) - 0.5*log10(minVal)))
else:
	stack.SetMaximum(1.7*maxVal)
stack.SetMinimum(minVal)

errorband=stack.GetStack().Last().Clone("error")
errorband.Sumw2()
errorband.SetLineColor(kBlack)
errorband.SetFillColor(kBlack)
errorband.SetFillStyle(3245)
errorband.SetMarkerSize(0)


#canvas.SaveAs("noratio_%s.pdf"%(histName))
canvas.Clear()

canvasRatio.cd()
canvasRatio.ResetDrawn()
canvasRatio.Draw()
canvasRatio.cd()

pad1.Draw()
pad2.Draw()

pad1.cd()

pad1.SetLogy(log)

y2 = pad1.GetY2()

stack.Draw("HIST")

stack.GetXaxis().SetTitle('')
stack.GetYaxis().SetTitle(dataHist.GetYaxis().GetTitle())

stack.SetTitle('')
stack.GetXaxis().SetLabelSize(0)
stack.GetYaxis().SetLabelSize(gStyle.GetLabelSize()/(1.-padRatio+padOverlap))
stack.GetYaxis().SetTitleSize(gStyle.GetTitleSize()/(1.-padRatio+padOverlap))
stack.GetYaxis().SetTitleOffset(gStyle.GetTitleYOffset()*(1.-padRatio+padOverlap))
stack.GetYaxis().SetTitle("Events")

dataHist.Draw("E,X0,SAME")

legendR.AddEntry(dataHist, "Data", 'pe')

ratio = dataHist.Clone("temp")
temp = stack.GetStack().Last().Clone("temp")
print temp.GetNbinsX(), ratio.GetNbinsX()

for i_bin in range(1,temp.GetNbinsX()+1):
       	temp.SetBinError(i_bin,0.)
ratio.Divide(temp)
print ratio.GetNbinsX()
print ratio
print ratio.GetNbinsX()
ratio.SetTitle('')

ratio.GetXaxis().SetLabelSize(gStyle.GetLabelSize()/(padRatio+padOverlap))
ratio.GetYaxis().SetLabelSize(gStyle.GetLabelSize()/(padRatio+padOverlap))
ratio.GetXaxis().SetTitleSize(gStyle.GetTitleSize()/(padRatio+padOverlap))
ratio.GetYaxis().SetTitleSize(gStyle.GetTitleSize()/(padRatio+padOverlap))
ratio.GetYaxis().SetTitleOffset(gStyle.GetTitleYOffset()*(padRatio+padOverlap-padGap))


#up_=ratio.GetMaximum()
#down_=ratio.GetMinimum()

#max_=up_*0.1+up_
#min_=down_-0.1*down_


ratio.GetYaxis().SetRangeUser(0.4,1.6)
ratio.GetYaxis().SetNdivisions(504)
ratio.GetXaxis().SetTitle(histograms[histName][0])
ratio.GetYaxis().SetTitle("Data/MC")
CMS_lumi.CMS_lumi(pad1, 4, 11)
legendR.Draw()
pad2.cd()
	#for i_bin in range(1,errorband.GetNbinsX()):
	#	errorband.SetBinContent(i_bin,1.)
#maxRatio = 1.5
#minRatio = 0.5
ratio.SetMarkerStyle(dataHist.GetMarkerStyle())
ratio.SetMarkerSize(dataHist.GetMarkerSize())
ratio.SetLineColor(dataHist.GetLineColor())
ratio.SetLineWidth(dataHist.GetLineWidth())
ratio.Draw('e,x0')
errorband.Divide(temp)
errorband.Draw('e2,same')
oneLine.Draw("same")
	
	#    pad2.Update()
canvasRatio.Update()
canvasRatio.RedrawAxis()
if log:
	canvasRatio.SaveAs("%s_new_log.pdf"%(histName))
else:
	canvasRatio.SaveAs("%s_new.pdf"%(histName))



