#!/bin/bash
#jet ID = tight
path=/nfs/dust/cms/user/karavdia/ttbar_semilep_13TeV/RunII_80X_v3/ttbarLJSkimming/ElecID_CutBased_tight_MET50_elecPt50_woEGReg_jetIDtight_slimmedMETs_JLCkey_20180427_JERhybridSFs_jer_up/nfs/dust/cms/user/karavdia/ttbar_semilep_13TeV/RunII_80X_v3/workdir_Skimming_CutBased_03Feb_woEGReg_jer_up/uhh2.AnalysisModuleRunner. 
mkdir /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/ZprimeSemiLeptonic/Skimming_datasets_20180427_JERhybrid_jer_up
cd /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/ZprimeSemiLeptonic/Skimming_datasets_20180427_JERhybrid_jer_up

# path=/nfs/dust/cms/user/karavdia/ttbar_semilep_13TeV/RunII_80X_v3/ttbarLJSkimming/ElecID_CutBased_tight_MET50_elecPt50_woEGReg_jetIDtight_slimmedMETs_JLCkey_20180427_JERhybridSFs_jer_down/nfs/dust/cms/user/karavdia/ttbar_semilep_13TeV/RunII_80X_v3/workdir_Skimming_CutBased_03Feb_woEGReg_jer_down/uhh2.AnalysisModuleRunner. 
# mkdir /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/ZprimeSemiLeptonic/Skimming_datasets_20180427_JERhybrid_jer_down
# cd /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/ZprimeSemiLeptonic/Skimming_datasets_20180427_JERhybrid_jer_down


# #MC
for sample_name in QCD_Pt_15to20_bcToE QCD_Pt_20to30_bcToE QCD_Pt_80to170_bcToE QCD_Pt_170to250_bcToE QCD_Pt_250toInf_bcToE QCD_Pt20to30_EMEnriched QCD_Pt30to50_EMEnriched QCD_Pt50to80_EMEnriched QCD_Pt50to80_EMEnriched QCD_Pt80to120_EMEnriched QCD_Pt120to170_EMEnriched QCD_Pt170to300_EMEnriched QCD_Pt300toInf_EMEnriched GJets_HT-100To200 GJets_HT-200To400 GJets_HT-400To600 GJets_HT-600ToInf GJets_HT-40To100 TTbar_part1 TTbar_part2 WJetsToLNu_Pt-100To250 WJetsToLNu_Pt-250To400 WJetsToLNu_Pt-400To600 WJetsToLNu_Pt-600ToInf DYJetsToLL_M-50_HT-70to100 DYJetsToLL_M-50_HT-100to200 DYJetsToLL_M-50_HT-200to400 DYJetsToLL_M-50_HT-400to600 DYJetsToLL_M-50_HT-600to800 DYJetsToLL_M-50_HT-800to1200 DYJetsToLL_M-50_HT-1200to2500 DYJetsToLL_M-50_HT-2500toInf QCD_HT100to200 QCD_HT200to300 QCD_HT300to500 QCD_HT500to700 QCD_HT700to1000 QCD_HT1000to1500 QCD_HT1500to2000 QCD_HT2000toInf ST_s ST_tW_antitop ST_tW_top ST_t-channel_top ST_t-channel_antitop WW WZ ZZ WJetsToLNu_Pt-100To250__B WJetsToLNu_Pt-250To400__B WJetsToLNu_Pt-400To600__B WJetsToLNu_Pt-600ToInf__B WJetsToLNu_Pt-100To250__C WJetsToLNu_Pt-250To400__C WJetsToLNu_Pt-400To600__C WJetsToLNu_Pt-600ToInf__C WJetsToLNu_Pt-100To250__L WJetsToLNu_Pt-250To400__L WJetsToLNu_Pt-400To600__L WJetsToLNu_Pt-600ToInf__L ST_s ST_tW_antitop ST_tW_top ST_t-channel_top ST_t-channel_antitop WJetsToLNu_Pt-000To050__B WJetsToLNu_Pt-050To100__B  WJetsToLNu_Pt-000To050__C WJetsToLNu_Pt-050To100__C WJetsToLNu_Pt-000To050__L WJetsToLNu_Pt-050To100__L
#for sample_name in QCD_Pt_15to20_bcToE QCD_Pt_20to30_bcToE QCD_Pt_80to170_bcToE QCD_Pt_170to250_bcToE QCD_Pt_250toInf_bcToE QCD_Pt20to30_EMEnriched QCD_Pt30to50_EMEnriched QCD_Pt50to80_EMEnriched QCD_Pt50to80_EMEnriched QCD_Pt80to120_EMEnriched QCD_Pt120to170_EMEnriched QCD_Pt170to300_EMEnriched QCD_Pt300toInf_EMEnriched GJets_HT-100To200 GJets_HT-200To400 GJets_HT-400To600 GJets_HT-600ToInf GJets_HT-40To100
# for sample_name in TTbar_part1 TTbar_part2 WJetsToLNu_Pt-100To250 WJetsToLNu_Pt-250To400 WJetsToLNu_Pt-400To600 WJetsToLNu_Pt-600ToInf DYJetsToLL_M-50_HT-70to100 DYJetsToLL_M-50_HT-100to200 DYJetsToLL_M-50_HT-200to400 DYJetsToLL_M-50_HT-400to600 DYJetsToLL_M-50_HT-600to800 DYJetsToLL_M-50_HT-800to1200 DYJetsToLL_M-50_HT-1200to2500 DYJetsToLL_M-50_HT-2500toInf QCD_HT100to200 QCD_HT200to300 QCD_HT300to500 QCD_HT500to700 QCD_HT700to1000 QCD_HT1000to1500 QCD_HT1500to2000 QCD_HT2000toInf ST_s ST_tW_antitop ST_tW_top ST_t-channel_top ST_t-channel_antitop WW WZ ZZ
#for sample_name in WJetsToLNu_Pt-100To250__B WJetsToLNu_Pt-250To400__B WJetsToLNu_Pt-400To600__B WJetsToLNu_Pt-600ToInf__B
#for sample_name in WJetsToLNu_Pt-100To250__B WJetsToLNu_Pt-250To400__B WJetsToLNu_Pt-400To600__B WJetsToLNu_Pt-600ToInf__B WJetsToLNu_Pt-100To250__C WJetsToLNu_Pt-250To400__C WJetsToLNu_Pt-400To600__C WJetsToLNu_Pt-600ToInf__C WJetsToLNu_Pt-100To250__L WJetsToLNu_Pt-250To400__L WJetsToLNu_Pt-400To600__L WJetsToLNu_Pt-600ToInf__L TTbar_part1 TTbar_part2 WW WZ ZZ DYJetsToLL_M-50_HT-70to100 DYJetsToLL_M-50_HT-100to200 DYJetsToLL_M-50_HT-200to400 DYJetsToLL_M-50_HT-400to600 DYJetsToLL_M-50_HT-600to800 DYJetsToLL_M-50_HT-800to1200 DYJetsToLL_M-50_HT-1200to2500 DYJetsToLL_M-50_HT-2500toInf QCD_HT100to200 QCD_HT200to300 QCD_HT300to500 QCD_HT500to700 QCD_HT700to1000 QCD_HT1000to1500 QCD_HT1500to2000 QCD_HT2000toInf ST_s ST_tW_antitop ST_tW_top ST_t-channel_top ST_t-channel_antitop 
#for sample_name in QCD_Pt-15to20_MuEnrichedPt5 QCD_Pt-20to30_MuEnrichedPt5 QCD_Pt-30to50_MuEnrichedPt5 QCD_Pt-50to80_MuEnrichedPt5 QCD_Pt-80to120_MuEnrichedPt5 QCD_Pt-120to170_MuEnrichedPt5 QCD_Pt-170to300_MuEnrichedPt5 QCD_Pt-300to470_MuEnrichedPt5 QCD_Pt-470to600_MuEnrichedPt5 QCD_Pt-600to800_MuEnrichedPt5 QCD_Pt-800to1000_MuEnrichedPt5 QCD_Pt-1000toInf_MuEnrichedPt5
#for sample_name in TTbar_part1 TTbar_part2
#for sample_name in WJetsToLNu_Pt-000To050__B WJetsToLNu_Pt-050To100__B  WJetsToLNu_Pt-000To050__C WJetsToLNu_Pt-050To100__C WJetsToLNu_Pt-000To050__L WJetsToLNu_Pt-050To100__L 
#for sample_name in TTbar_part1 WW WZ ZZ WJetsToLNu_Pt-000To050 WJetsToLNu_Pt-050To100 WJetsToLNu_Pt-100To250 WJetsToLNu_Pt-250To400 WJetsToLNu_Pt-400To600 WJetsToLNu_Pt-600ToInf DYJetsToLL_M-50_HT-70to100 DYJetsToLL_M-50_HT-100to200 DYJetsToLL_M-50_HT-200to400 DYJetsToLL_M-50_HT-400to600 DYJetsToLL_M-50_HT-600to800 DYJetsToLL_M-50_HT-800to1200 DYJetsToLL_M-50_HT-1200to2500 DYJetsToLL_M-50_HT-2500toInf QCD_HT100to200 QCD_HT200to300 QCD_HT300to500 QCD_HT500to700 QCD_HT700to1000 QCD_HT1000to1500 QCD_HT1500to2000 QCD_HT2000toInf ST_s ST_tW_antitop ST_tW_top ST_t-channel_top ST_t-channel_antitop EWKWMinus2Jets_WToLNu EWKWPlus2Jets_WToLNu
#for sample_name in TTJets_Dilept TTJets_SingleLeptFromT TTJets_SingleLeptFromTbar GJets_HT-40To100 GJets_HT-100To200 GJets_HT-200To400 GJets_HT-400To600 GJets_HT-600ToInf
#for sample_name in EWKWMinus2Jets_WToLNu EWKWPlus2Jets_WToLNu
# #for sample_name in TTbar_part1
# # for sample_name in DYJetsToLL_M-50_HT-200to400
#for sample_name in TTbar_part1 WW WZ ZZ
#for sample_name in WJetsToLNu_Pt-000To050 WJetsToLNu_Pt-050To100

#for sample_name in WJetsToLNu_Pt-100To250 WJetsToLNu_Pt-250To400 WJetsToLNu_Pt-400To600 WJetsToLNu_Pt-600ToInf
#for sample_name in DYJetsToLL_M-50_HT-70to100 DYJetsToLL_M-50_HT-100to200 DYJetsToLL_M-50_HT-200to400 DYJetsToLL_M-50_HT-400to600 DYJetsToLL_M-50_HT-600to800 DYJetsToLL_M-50_HT-800to1200 DYJetsToLL_M-50_HT-1200to2500 DYJetsToLL_M-50_HT-2500toInf
#for sample_name in QCD_HT100to200 QCD_HT200to300 QCD_HT300to500 QCD_HT500to700 QCD_HT700to1000 QCD_HT1000to1500 QCD_HT1500to2000 QCD_HT2000toInf
#for sample_name in ST_s ST_tW_antitop ST_tW_top ST_t-channel_top ST_t-channel_antitop
 do
       echo $sample_name
       /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/scripts/create-dataset-xmlfile ${path}"MC."${sample_name}"*.root" MC_$sample_name.xml
# #      /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/scripts/create-multi-dataset-xmlfiles.py ${path}"MC."${sample_name}"*.root" MC_$sample_name.xml

       python /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/scripts/crab/readaMCatNloEntries.py 10 MC_$sample_name.xml True
done

#DATA
#for sample_name in DATA_SingleElectron_Run2016B DATA_SingleElectron_Run2016C DATA_SingleElectron_Run2016D DATA_SingleElectron_Run2016E DATA_SingleElectron_Run2016F DATA_SingleElectron_Run2016G DATA_SingleElectron_Run2016H
for sample_name in DATA_SingleMuon_Run2016B DATA_SingleMuon_Run2016C DATA_SingleMuon_Run2016D DATA_SingleMuon_Run2016E DATA_SingleMuon_Run2016F DATA_SingleMuon_Run2016G DATA_SingleMuon_Run2016H  DATA_SingleElectron_Run2016B DATA_SingleElectron_Run2016C DATA_SingleElectron_Run2016D DATA_SingleElectron_Run2016E DATA_SingleElectron_Run2016F DATA_SingleElectron_Run2016G DATA_SingleElectron_Run2016H
#for sample_name in DATA_SinglePhoton_Run2016B DATA_SinglePhoton_Run2016C DATA_SinglePhoton_Run2016D DATA_SinglePhoton_Run2016E DATA_SinglePhoton_Run2016F DATA_SinglePhoton_Run2016G DATA_SinglePhoton_Run2016H
do
   echo $sample_name 
#   echo ${path}"DATA."${sample_name}"*.root"
   /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/scripts/create-dataset-xmlfile ${path}"DATA."${sample_name}"*.root" DATA_$sample_name.xml
#   /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/scripts/create-multi-dataset-xmlfiles.py ${path}"DATA."${sample_name}"*.root" DATA_$sample_name.xml
     python /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/scripts/crab/readaMCatNloEntries.py 10 DATA_$sample_name.xml True
done

#rm uhh2.AnalysisModuleRunner.*
#rm TEMPLATE_*
#cd /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/ZprimeSemiLeptonic/config/
pwd
cd /nfs/dust/cms/user/karavdia/CMSSW_8_0_27/src/UHH2/ZprimeSemiLeptonic/macros