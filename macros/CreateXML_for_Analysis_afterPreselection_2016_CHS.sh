#!/bin/bash
#where UHH2 code installed
pathGL_code=/nfs/dust/cms/user/karavdia/CMSSW_10_2_10/src/UHH2/
#where (NOT MERGED) trees after preselection stored
#path_data=/nfs/dust/cms/user/karavdia/ZprimeSemiLeptonic/102X_v1/Preselection/RunII_2016v3_CHS/workdir_Zprime_PreSelec_2016v3_2/uhh2.AnalysisModuleRunner. 
path_data=/nfs/dust/cms/user/karavdia/ZprimeSemiLeptonic/102X_v1/Preselection/RunII_2016v3_CHS_muonTight_eleMedium/workdir_Zprime_PreSelec_2016v3_2/uhh2.AnalysisModuleRunner. 

mkdir $pathGL_code/ZprimeSemiLeptonic/data/Skimming_datasets_20190701
cd $pathGL_code/ZprimeSemiLeptonic/data/Skimming_datasets_20190701


# # #MC
# #for sample_name in RSGluonToTT_M-500_2016v3
#for sample_name in RSGluonToTT_M-500_2016v3 RSGluonToTT_M-750_2016v3 RSGluonToTT_M-1000_2016v3 RSGluonToTT_M-1250_2016v3 RSGluonToTT_M-1500_2016v3 RSGluonToTT_M-2500_2016v3 RSGluonToTT_M-3000_2016v3 RSGluonToTT_M-4000_2016v2 RSGluonToTT_M-4500_2016v2 RSGluonToTT_M-5000_2016v2 ZprimeToTTJet_M500_2016v3 ZprimeToTTJet_M750_2016v3 ZprimeToTTJet_M1000_2016v3 ZprimeToTTJet_M1250_2016v3 ZprimeToTTJet_M1500_2016v3 ZprimeToTTJet_M2000_2016v3 ZprimeToTTJet_M2500_2016v3 ZprimeToTTJet_M3000_2016v3 ZprimeToTTJet_M3500_2016v3 ZprimeToTTJet_M4000_2016v3 ZprimeToTT_M500_W50_2016v3 ZprimeToTT_M750_W75_2016v3 ZprimeToTT_M1000_W100_2016v3 ZprimeToTT_M1250_W125_2016v3 ZprimeToTT_M1500_W150_2016v3 ZprimeToTT_M2000_W200_2016v3 ZprimeToTT_M2500_W250_2016v3 ZprimeToTT_M3000_W300_2016v3 ZprimeToTT_M3500_W350_2016v3 ZprimeToTT_M4000_W400_2016v3 ZprimeToTT_M4500_W450_2016v3 ZprimeToTT_M5000_W500_2016v3 ZprimeToTT_M1000_W300_2016v3 ZprimeToTT_M2000_W600_2016v3 ZprimeToTT_M4000_W1200_2016v3 ZprimeToTT_M500_W5_2016v3 ZprimeToTT_M750_W7p5_2016v3 ZprimeToTT_M1000_W10_2016v3 ZprimeToTT_M1250_W12p5_2016v3 ZprimeToTT_M1500_W15_2016v3 ZprimeToTT_M2000_W20_2016v3 ZprimeToTT_M2500_W25_2016v3 ZprimeToTT_M3000_W30_2016v3 ZprimeToTT_M3500_W35_2016v3 ZprimeToTT_M4000_W40_2016v3 ZprimeToTT_M4500_W45_2016v3 ZprimeToTT_M5000_W50_2016v3 QCD_Pt-20to30_EMEnriched_2016v3 QCD_Pt-30to50_EMEnriched_2016v3 QCD_Pt-50to80_EMEnriched_2016v3 QCD_Pt-80to120_EMEnriched_2016v3 QCD_Pt-170to300_EMEnriched_2016v3 QCD_Pt-300toInf_EMEnriched_2016v3 QCD_Pt_15to20_bcToE_2016v3 QCD_Pt_20to30_bcToE_2016v3 QCD_Pt_30to80_bcToE_2016v3 QCD_Pt_80to170_bcToE_2016v3 QCD_Pt_170to250_bcToE_2016v3 QCD_Pt_250toInf_bcToE_2016v3 QCD_Pt-15to20_MuEnrichedPt5_2016v3 QCD_Pt-20to30_MuEnrichedPt5_2016v3 QCD_Pt-30to50_MuEnrichedPt5_2016v3 QCD_Pt-50to80_MuEnrichedPt5_2016v3 QCD_Pt-80to120_MuEnrichedPt5_2016v3 QCD_Pt-120to170_MuEnrichedPt5_2016v3 QCD_Pt-170to300_MuEnrichedPt5_2016v3 QCD_Pt-300to470_MuEnrichedPt5_2016v3 QCD_Pt-470to600_MuEnrichedPt5_2016v3 QCD_Pt-600to800_MuEnrichedPt5_2016v3 QCD_Pt-800to1000_MuEnrichedPt5_2016v3 QCD_Pt-1000toInf_MuEnrichedPt5_2016v3 TT_TuneCUETP8M2T4_2016v3 WJetsToLNu_HT-70To100_2016v3 WJetsToLNu_HT-100To200_2016v3 WJetsToLNu_HT-200To400_2016v3 WJetsToLNu_HT-400To600_2016v3 WJetsToLNu_HT-600To800_2016v3 WJetsToLNu_HT-800To1200_2016v3 WJetsToLNu_HT-1200To2500_2016v3 WJetsToLNu_HT-2500ToInf_2016v3 ST_tW_antitop_5f_inclusiveDecays_2016v3  ST_tW_top_5f_inclusiveDecays_2016v3 ST_t-channel_antitop_2016v3 ST_t-channel_top_2016v3 ST_s-channel_2016v3 WW_2016v3 WZ_2016v3 ZZ_2016v3 DYJetsToLL_M-50_HT-70to100_2016v3 DYJetsToLL_M-50_HT-100to200_2016v3 DYJetsToLL_M-50_HT-200to400_2016v3 DYJetsToLL_M-50_HT-400to600_2016v3 DYJetsToLL_M-50_HT-600to800_2016v3 DYJetsToLL_M-50_HT-800to1200_2016v3 DYJetsToLL_M-50_HT-1200to2500_2016v3 DYJetsToLL_M-50_HT-2500toInf_2016v3
for sample_name in QCD_Pt-120to170_EMEnriched_2016v3 WJetsToLNu_Pt-100To250_2016v3 WJetsToLNu_Pt-250To400_2016v3 WJetsToLNu_Pt-400To600_2016v3 WJetsToLNu_Pt-600ToInf_2016v3
do
    echo $sample_name

       $pathGL_code/scripts/create-dataset-xmlfile ${path_data}"MC."${sample_name}"*.root" MC_$sample_name.xml
       python $pathGL_code/scripts/crab/readaMCatNloEntries.py 10 MC_$sample_name.xml True
done

# # #DATA
# for sample_name in DATA_SingleMuon_Run2016v3B DATA_SingleMuon_Run2016v3C DATA_SingleMuon_Run2016v3D DATA_SingleMuon_Run2016v3E DATA_SingleMuon_Run2016v3F DATA_SingleMuon_Run2016v3G DATA_SingleMuon_Run2016v3H DATA_SingleElectron_Run2016v3B DATA_SingleElectron_Run2016v3C DATA_SingleElectron_Run2016v3D DATA_SingleElectron_Run2016v3E DATA_SingleElectron_Run2016v3F DATA_SingleElectron_Run2016v3G DATA_SingleElectron_Run2016v3H   
# do
#    echo $sample_name 
#    $pathGL_code/scripts/create-dataset-xmlfile ${path_data}"DATA."${sample_name}"*.root" DATA_$sample_name.xml
#    python $pathGL_code/scripts/crab/readaMCatNloEntries.py 10 DATA_$sample_name.xml True

# done
pwd
cd $pathGL_code/ZprimeSemiLeptonic/macros