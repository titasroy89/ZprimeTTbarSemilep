#!/bin/bash
#where UHH2 code installed
pathGL_code=/nfs/dust/cms/user/karavdia/CMSSW_10_2_10/src/UHH2/
#where (NOT MERGED) trees after preselection stored
path_data=/nfs/dust/cms/user/karavdia/ZprimeSemiLeptonic/102X_v1/Preselection/RunII_2018/workdir_Zprime_PreSelec_2018_2/uhh2.AnalysisModuleRunner. 

mkdir $pathGL_code/ZprimeSemiLeptonic/data/Skimming_datasets_20190410
cd $pathGL_code/ZprimeSemiLeptonic/data/Skimming_datasets_20190410


# #MC
for sample_name in TTToSemiLeptonic_2018 WJetsToLNu_HT-100To200_2018 WJetsToLNu_HT-1200To2500_2018 WJetsToLNu_HT-200To400_2018 WJetsToLNu_HT-2500ToInf_2018 WJetsToLNu_HT-400To600_2018 WJetsToLNu_HT-600To800_2018 WJetsToLNu_HT-70To100_2018 WJetsToLNu_HT-800To1200_2018 ZprimeToTTJet_M1000_2018 ZprimeToTTJet_M1250_2018 ZprimeToTTJet_M1500_2018 ZprimeToTTJet_M2000_2018 ZprimeToTTJet_M2500_2018 ZprimeToTTJet_M3000_2018 ZprimeToTTJet_M3500_2018 ZprimeToTTJet_M4000_2018 ZprimeToTTJet_M5000_2018 ZprimeToTTJet_M500_2018 ZprimeToTTJet_M6000_2018 ZprimeToTTJet_M7000_2018 ZprimeToTTJet_M750_2018
do
    echo $sample_name

       $pathGL_code/scripts/create-dataset-xmlfile ${path_data}"MC."${sample_name}"*.root" MC_$sample_name.xml
       python $pathGL_code/scripts/crab/readaMCatNloEntries.py 10 MC_$sample_name.xml True
done

#DATA
for sample_name in DATA_EGamma_Run2018A DATA_SingleMuon_Run2018A
do
   echo $sample_name 
   $pathGL_code/scripts/create-dataset-xmlfile ${path_data}"DATA."${sample_name}"*.root" DATA_$sample_name.xml
   python $pathGL_code/scripts/crab/readaMCatNloEntries.py 10 DATA_$sample_name.xml True

done
pwd
cd $pathGL_code/ZprimeSemiLeptonic/macros