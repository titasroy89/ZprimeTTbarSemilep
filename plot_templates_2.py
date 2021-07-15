#! /usr/bin/env python
from ROOT import *
import ROOT
import sys
import numpy

### Dictionaries of samples
#samplelist = {'wjets','ttbar_others','vv','qcd','singletop','dy', 'ttbar_semi'}
signal = {'ttbar_semi'}
backgrounds = {'wjets','ttbar_others','vv','qcd','singletop','dy'}

### Dictionary of different topological regions, used in DeltaY.root file
### SR1T=boosted, SR0T=semi-resolved, CR1=resolved
topology ={'SR1T', 'SR0T', 'CR1'} 

### Dictionaries of systematic uncertainties
#systematics = {'hfstats1','toptag','muID','miswtag','lfstats2','hf','pileup','muHLT','lf','pt_rew','hfstats2','lfstats1','cferr1','cferr2','jes','HT','muon_rec','pdf','q2'}#,'jer','jec'}

### systematics approved by group
#systematics = {'Top_pT_rew', 'q2', 'ISR', 'FSR', 'hdamp', 'pileup', 'muID', 'muon_rec', 'muHLT', 'jes', 'jer', 'HT', 'toptag', 'misttag', 'pdf'}
### same as above minus toptag
#systematics = {'Top_pT_rew', 'q2', 'ISR', 'FSR', 'hdamp', 'pileup', 'muID', 'muon_rec', 'muHLT', 'jes', 'jer', 'HT', 'misttag', 'pdf'}

### confirmed systematics in Input_unfolding_data.root
systematics = {'pt_rew', 'pileup', 'muID', 'muon_rec', 'muHLT', 'jes', 'HT', 'misttag', 'miswtag'}

### systematics missing from Input_... use with DeltaY.root and sum over appropriate topologies
#systematics = {'q2', 'ISR', 'FSR', 'hdamp', 'jer', 'toptag', 'pdf'}

#btag_syst = {'hf', 'hfstats1', 'hfstats2', 'lf', 'lfstats1', 'lfstats2', 'cferr1', 'cferr2', 'jes'}
#signal_syst = {'Top_pT_rew', 'q2', 'ISR', 'FSR', 'hdamp', 'pileup', 'muID', 'muon_rec', 'muHLT', 'jes', 'jer', 'HT', 'toptag', 'misttag', 'pdf'}


### Specify the root file to pull histos from
fin = TFile('Input_undfolding_data.root', 'open')
#fin = TFile('DeltaY.root', 'open')
padRatio = 0.25
padOverlap = 0.15

padGap = 0.01


H = 600;
W = 800;
T = 0.08*H
B = 0.12*H
L = 0.12*W
R = 0.1*W

### Initializing variables needed later
nominalhist = {}
nominalhistDraw = {}
systvarhist = {}
systvarhistDraw = {}
systvarhistRatio = {}
systvarhistRatioDraw = {}
canvas_Bkg = {}
pad1 = {}
pad2 = {}

## Variables needed for DeltaY code
hsys = {}
hsystUp = {}
hsystDown = {}
hsysDraw = {}
hsystUpDraw = {}
hsystDownDraw = {}

### Needed for histo aesthetics
gROOT.SetBatch(kTRUE)
gROOT.UseCurrentStyle()
gStyle.SetOptStat(0)
gStyle.SetOptTitle(0)



'''
### This function loops over backgrounds and systematics of interest and sums up all histograms returning a single histo
def add_SandB_histos(backgrounds, systematics_of_interest):
    ### flag1 will set the histo of the initial sample then add the remaining ones
    flag1 = True
    for samp in backgrounds:
         ### flag2 will set histo of initial systematic then add the remaining ones ###
        flag2 = True
        for syst in systematics_of_interest:
            nominalhist[samp+syst] = fin.Get(samp+'_nominal')
            ### only first loop will enter and label histogram of first systematic as h1 to allow summation of remaining systematics
            if flag2:
                hsyst = fin.Get(samp+'_nominal')
                flag2 = False
                continue
            hsyst.Add(nominalhist[samp+syst])
        ### only first loop will enter and label histogram of first sample as hsamps
        if flag1:
            hsamps = hsyst
            flag1 = False
            continue
        hsamps.Add(hsyst)            
    return hsamps

#x = add_SandB_histos(backgrounds, btag_syst)
#print x


### This function loops over a set of somples and sums up all histograms returning a single histo
def add_SampleHistos(samples):
    ### flag will set the histo of the initial sample then add the remaining ones
    flag = True
    for samp in samples:
	nominalhist[samp] = fin.Get(samp+'_nominal')
	### only first loop will enter and label histogram of first sample as hsamps
        if flag:
	    hsamps = fin.Get(samp+'_nominal')
            hsamps.Sumw2()
	    flag = False
            continue
        #hsamps.Sumw2()
	hsamps.Add(nominalhist[samp])
    return hsamps

#backgrounds_sum = add_SampleHistos(backgrounds)
#print 'The sum of all the backgrounds is stored in', backgrounds_sum

'''



### loop/sum over samples of a given systematic and return a single histo for each systematic 
### use this when pulling histos from Input_undfolding_data.root
syst = 'pt_rew'
samp = 'ttbar_semi'

#for syst in systematics:
    #for samp in backgrounds:
        #print 'First line inside the loop, syst is', syst, 'and samp is', samp
        #flag = True
        # only first histogram will enter and initialize  to allow summation of remaining backgrounds
        #if flag:
hsyst = fin.Get(samp+'_nominal')
hsystUp = fin.Get(samp+'_'+syst+'Up')
hsystDown = fin.Get(samp+'_'+syst+'Down')
            #if (hsyst == None or hsystUp == None or hsystDown == None):
            #    print 'one of the above histograms was not found in the root file'
            #    continue
hsyst.Sumw2()
hsystUp.Sumw2()
hsystDown.Sumw2()
            #flag = False
            #continue
        # Initializing remaining nominal/Up/Down histograms
        #nominalhist[samp] = fin.Get(samp+'_nominal')
        #systvarhist[samp+syst+'Up'] = fin.Get(samp+'_'+syst+'Up')
        #systvarhist[samp+syst+'Down'] = fin.Get(samp+'_'+syst+'Down')

        # Remaining histograms  are added to initial
        #hsyst.Add(nominalhist[samp])
        #hsystUp.Add(systvarhist[samp+syst+'Up'])
        #hsystDown.Add(systvarhist[samp+syst+'Down'])

    # Setting canvas and legend
canvas_Bkg = TCanvas("SystVariation_"+samp+syst,"SystVariation_"+samp+syst,W,H)
legend = TLegend(.7,.70,.9,.9)

    # Setting pad for nominal and up/down hisotgrams
pad1 = TPad("pad1", "pad1", 0., 0.4, 1., 1.) #Upper plot will be in pad1
#pad1 = TPad("pad1", "pad1", 0., 0, 1., 0.3(1-0.02))
#pad1.SetBottomMargin(0.0) # Upper and lower plot are not joined
#pad1.SetGridx()         # Vertical grid


#pad1 = TPad("zxc_p1","zxc_p1",0,padRatio-padOverlap,1,1)
pad1.SetLeftMargin( L/W )
pad1.SetRightMargin( R/W )
pad1.SetTopMargin(T/H/(1-padRatio+padOverlap))
pad1.SetBottomMargin( (padOverlap+padGap)/(1-padRatio+padOverlap) )
#pad1.SetBottomMargin(0.0)
pad1.SetFillColor(0)
pad1.SetBorderMode(0)
pad1.SetFrameFillStyle(0)
pad1.SetFrameBorderMode(0)
pad1.SetTickx(0)
pad1.SetTicky(0)
pad1.SetBottomMargin(0.01) # Upper and lower plot are not joined
pad1.SetGridx()  
pad1.Draw()             # Draw the upper pad: pad1
pad1.cd() 


    # Drawing up/down/nominal histogarams and setting axes/title/marker
hsystUpDraw = hsystUp.DrawClone('hist')
a = hsystUpDraw.GetMaximum()
hsystUpDraw.GetYaxis().SetRangeUser(0,a*1.05)
#hsystUpDraw.GetXaxis().SetTitle("| #Delta y |")
hsystUpDraw.GetXaxis().SetLabelSize(0)
hsystUpDraw.GetYaxis().SetTitle('Events')
hsystUpDraw.GetYaxis().CenterTitle(True)
#hsystUpDraw.GetYaxis().SetTitleOffset(1)
#hsystUpDraw.GetYaxis().SetTitleFont(43)
hsystUpDraw.GetYaxis().SetTitleSize(0.05)
hsystUpDraw.SetLineColor(kRed)
hsystDownDraw = hsystDown.DrawClone('hist same')
hsystDownDraw.SetLineColor(kBlue)
hsystDraw = hsyst.DrawClone('ep same')
hsystDraw.SetMarkerStyle(20)
hsystDraw.SetMarkerSize(0.33)
hsystDraw.SetMarkerColor(kBlack)
hsystDraw.SetLineColor(kBlack)
    
    # Drawing legend 
legend.AddEntry(hsystDraw,'nominal','lp')
legend.AddEntry(hsystUpDraw,'top-pT Up','lp')
legend.AddEntry(hsystDownDraw,'top-pT Down','lp')
legend.Draw()

latex = ROOT.TLatex()
latex.SetTextSize(0.045)
latex.SetTextAlign(11)
latex.DrawLatex(-1.9,a*1.06,'CMS preliminary')
    
latex2 = ROOT.TLatex()
latex2.SetTextSize(0.045)
latex2.SetTextAlign(11)
latex2.DrawLatex(1.1,a*1.06,"58.8 fb^{-1} (13 TeV)")
   
    # Creating 2nd pad
canvas_Bkg.cd()          # Go back to the main canvas before defining pad2
pad2 = TPad("pad2", "pad2", 0, 0.01, 1, 0.4)
#pad2 = TPad("pad2", "pad2", 0., 0., 1., 0.29)
#pad2 = TPad("qwe_p2","qwe_p2",0,0,1,padRatio+padOverlap)
pad2.SetLeftMargin( L/W )
pad2.SetRightMargin( R/W )
pad2.SetTopMargin(0)
#pad2.SetTopMargin( (padOverlap)/(padRatio+padOverlap) )
pad2.SetBottomMargin( B/H/(padRatio+padOverlap) )

pad2.SetFillColor(0)
pad2.SetFillStyle(4000)
pad2.SetBorderMode(0)
pad2.SetFrameFillStyle(0)
pad2.SetFrameBorderMode(0)
pad2.SetTickx(0)
pad2.SetTicky(0)
pad2.SetGridx() # vertical grid
pad2.Draw()
pad2.cd()      # pad2 becomes the current pad
    
    # Draw Variation/Nominal histogram
systvarhistRatio[samp+syst+'__plus__ratio'] = hsystUpDraw.Clone(samp+syst+'Up_Ratio')
systvarhistRatio[samp+syst+'__plus__ratio'].Divide(hsystDraw)
systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetRangeUser(0.6,1.4)
systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetNdivisions(5,5,0)
systvarhistRatio[samp+syst+'__plus__ratio'].SetMarkerStyle(1)
systvarhistRatio[samp+syst+'__plus__ratio'].Draw('l')
systvarhistRatio[samp+syst+'__plus__ratio'].SetTitle("")

systvarhistRatio[samp+syst+'__plus__ratio'].GetXaxis().SetTitle("| #Delta y |")
systvarhistRatio[samp+syst+'__plus__ratio'].GetXaxis().CenterTitle(True)
systvarhistRatio[samp+syst+'__plus__ratio'].GetXaxis().SetTitleSize(0.08)
systvarhistRatio[samp+syst+'__plus__ratio'].GetXaxis().SetTitleOffset(0.6)
systvarhistRatio[samp+syst+'__plus__ratio'].GetXaxis().SetLabelSize(.05)
systvarhistRatio[samp+syst+'__plus__ratio'].GetXaxis().SetLabelOffset(0.004)

systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetTitle("Ratio")
systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetTitleSize(17)
systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetTitleFont(43)
systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetTitleOffset(1.4)
systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().CenterTitle(True)
systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetLabelFont(43)
systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetLabelSize(9)

systvarhistRatio[samp+syst+'__minus__ratio'] = hsystDownDraw.Clone(samp+syst+'Down_Ratio')
systvarhistRatio[samp+syst+'__minus__ratio'].Divide(hsystDraw)
systvarhistRatio[samp+syst+'__minus__ratio'].GetYaxis().SetTitle("")
systvarhistRatio[samp+syst+'__minus__ratio'].GetYaxis().SetTitleSize(10)
systvarhistRatio[samp+syst+'__minus__ratio'].SetMarkerStyle(1)
systvarhistRatio[samp+syst+'__minus__ratio'].SetTitle("")
systvarhistRatio[samp+syst+'__minus__ratio'].Draw('h same')
pad2.Update()  
    # Save canvas as pdf
canvas_Bkg.SaveAs("SystVariation_"+syst+samp+'.pdf')

'''


def set_canvleg():
    # Setting canvas and legend
    global canvas_Bkg
    canvas_Bkg = TCanvas("SystVariation_"+samp+syst,"SystVariation_"+samp+syst,800,600)
    global legend
    legend = TLegend(.7,.70,.9,.9)

def set_pad1():
    # Setting pad for nominal and up/down hisotgrams
    pad1[samp+syst] = TPad("pad1", "pad1", 0., 0.3, 1., 1.); # Upper plot will be in pad1
    pad1[samp+syst].SetBottomMargin(5); # Upper and lower plot are not joined
    pad1[samp+syst].SetGridx();         # Vertical grid
    pad1[samp+syst].Draw();             # Draw the upper pad: pad1
    pad1[samp+syst].cd();               # pad1 becomes the current pad

def draw_histos():
    # Drawing up/down/nominal histogarams and setting axes/title/marker
    global hsystUpDraw
    hsystUpDraw = hsystUp.DrawClone('hist')
    global a
    a = hsystUp.GetMaximum()
    hsystUpDraw.GetYaxis().SetRangeUser(0,a*1.05)
    hsystUpDraw.GetXaxis().SetTitle("| #Delta y |")
    hsystUpDraw.GetYaxis().SetTitle('Events')
    hsystUpDraw.SetLineColor(kRed)
    global hsystDownDraw
    hsystDownDraw = hsystDown.DrawClone('hist same')
    hsystDownDraw.SetLineColor(kBlue)
    global hsystDraw
    hsystDraw = hsyst.DrawClone('ep same')
    hsystDraw.SetMarkerStyle(20)
    hsystDraw.SetMarkerSize(0.6)
    hsystDraw.SetMarkerColor(kBlack)
    hsystDraw.SetLineColor(kBlack)

def draw_legend():
    # Define and draw legend
    legend.AddEntry(hsystDraw,'nominal', 'lp')
    legend.AddEntry(hsystUpDraw, syst+'Up', 'lp')
    legend.AddEntry(hsystDownDraw, syst+'Down', 'lp')
    legend.Draw()

def latex1():
    latex = ROOT.TLatex()
    latex.SetTextSize(0.045)
    latex.SetTextAlign(11)
    latex.DrawLatex(-1.9,a*1.06,'CMS preliminary')

def latex2():
    latex2 = ROOT.TLatex()
    latex2.SetTextSize(0.045)
    latex2.SetTextAlign(11)
    latex2.DrawLatex(1.1,a*1.06,"58.8 fb^{-1} (13 TeV)")

def set_pad2():
    # Creating 2nd pad
    canvas_Bkg.cd();          # Go back to the main canvas before defining pad2
    global pad2
    pad2 = TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
    pad2.SetTopMargin(5);
    pad2.SetBottomMargin(5);
    pad2.SetGridx(); # vertical grid
    pad2.Draw();
    pad2.cd();      # pad2 becomes the current pad

def draw_ratiohisto():
    # Draw Variation/Nominal histogram
    systvarhistRatio[samp+syst+'__plus__ratio'] = hsystUpDraw.Clone(samp+syst+'Up_Ratio')
    systvarhistRatio[samp+syst+'__plus__ratio'].Divide(hsystDraw)
    systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetRangeUser(0.6,1.4)
    systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetNdivisions(5,5,0) 
    systvarhistRatio[samp+syst+'__plus__ratio'].GetXaxis().SetTitle("")
    systvarhistRatio[samp+syst+'__plus__ratio'].SetMarkerStyle(1)
    systvarhistRatio[samp+syst+'__plus__ratio'].Draw('l')
    systvarhistRatio[samp+syst+'__plus__ratio'].SetTitle("")
    systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetTitle("Ratio")
    systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetTitleSize(20)
    systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetTitleFont(43)
    systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetTitleOffset(0.75)
    systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetLabelFont(43)
    systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().SetLabelSize(15)
    systvarhistRatio[samp+syst+'__plus__ratio'].GetYaxis().CenterTitle(True)
    systvarhistRatio[samp+syst+'__minus__ratio'] = hsystDownDraw.Clone(samp+syst+'Down_Ratio')
    systvarhistRatio[samp+syst+'__minus__ratio'].GetYaxis().SetTitle("")
    systvarhistRatio[samp+syst+'__minus__ratio'].GetYaxis().SetTitleSize(10)
    systvarhistRatio[samp+syst+'__minus__ratio'].Divide(hsystDraw)
    systvarhistRatio[samp+syst+'__minus__ratio'].SetMarkerStyle(1)
    systvarhistRatio[samp+syst+'__minus__ratio'].Draw('same') 


### loop through the three topologies and sum all histos of corresponding systematics of a given sample and plot each systematic
### use this when pulling histos from DeltaY.root
samp = 'Ttbar'
syst = 'toptag'
tplgy = 'SR1T'
#for syst in signal_syst:
    #topology = 'SR1T'
    #flag = True
    #for tplgy in topology:
        # top tagging syst will be produced from the Boosted topology only whereas the rest will be produced from the sum of all three topologies
        #if (syst == 'toptag' and tplgy != 'SR1T'):
        #    continue
hsyst = fin.Get('/'+tplgy+'/'+samp+'/nominal')
hsystUp = fin.Get('/'+tplgy+'/'+samp+'/'+syst+'Up')
hsystDown = fin.Get('/'+tplgy+'/'+samp+'/'+syst+'Down')


        #if (syst == 'toptag' and tplgy == 'SR1T'):
        #    # Initializing nominal/Up/Down histogram
        #    hsyst = fin.Get('/'+tplgy+'/'+samp+'/nominal')
        #    hsystUp = fin.Get('/'+tplgy+'/'+samp+'/'+syst+'Up')
        #    hsystDown = fin.Get('/'+tplgy+'/'+samp+'/'+syst+'Down')
        #    break
        # only first histogram will enter and initialize  to allow summation of remaining topologies
        #if flag:
        #    hsyst = fin.Get('/'+tplgy+'/'+samp+'/nominal')
        #    hsystUp = fin.Get('/'+tplgy+'/'+samp+'/'+syst+'Up')
        #    hsystDown = fin.Get('/'+tplgy+'/'+samp+'/'+syst+'Down')
        #    hsyst.Sumw2()
        #    hsystUp.Sumw2()
        #    hsystDown.Sumw2()
        #    flag = False
        #    continue
        # Initializing remaining nominal/Up/Down histograms
        #nominalhist[samp] = fin.Get('/'+tplgy+'/'+samp+'/nominal')
        #systvarhist[samp+syst+'Up'] = fin.Get('/'+tplgy+'/'+samp+'/'+syst+'Up')
        #systvarhist[samp+syst+'Down'] = fin.Get('/'+tplgy+'/'+samp+'/'+syst+'Down')
        #if systvarhist[samp+syst+'Up'] == None or systvarhist[samp+syst+'Down'] == None: # Not sure if I should keep this safety measure
        #    continue
        # Remaining histograms  are added to initial
        #hsyst.Add(nominalhist[samp])
        #hsystUp.Add(systvarhist[samp+syst+'Up'])
        #hsystDown.Add(systvarhist[samp+syst+'Down'])
    # Setting canvas and legend and pad for nominal and up/down hisotgrams
set_canvleg()
set_pad1()
    # Drawing up/down/nominal histogarams and setting axes/title/marker
draw_histos()
    # Drawing legend
draw_legend()
    # Do latex stuff
latex1()
latex2()
    # Creating 2nd pad
set_pad2()
    # Draw Variation/Nominal histogram
draw_ratiohisto()
    # Save canvas as pdf
canvas_Bkg.SaveAs('SystVariation_'+samp+syst+'Boosted.pdf') 

'''


