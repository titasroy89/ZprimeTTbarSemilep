#!/bin/bash
#where UHH2 code installed
#where (NOT MERGED) trees after preselection stored
pathGL_code=/nfs/dust/cms/user/titasroy/Unfolding_Ac/CMSSW_10_2_17/src/UHH2/
path_data=/nfs/dust/cms/group/zprime-uhh/Presel_2016_CHS/2D/workdir_Zprime_PreSelec_2016/uhh2.AnalysisModuleRunner.
mkdir $pathGL_code/ZprimeSemiLeptonic/data/Skimming_datasets_2016v3_2D
cd $pathGL_code/ZprimeSemiLeptonic/data/Skimming_datasets_2016v3_2D


 #MC
for sample_name in DYJetsToLL_M-50_HT-70to100_2016v3 DYJetsToLL_M-50_HT-100to200_2016v3 DYJetsToLL_M-50_HT-200to400_2016v3 DYJetsToLL_M-50_HT-400to600_2016v3 DYJetsToLL_M-50_HT-600to800_2016v3 DYJetsToLL_M-50_HT-800to1200_2016v3 DYJetsToLL_M-50_HT-1200to2500_2016v3 DYJetsToLL_M-50_HT-2500toInf_2016v3
do
    echo $sample_name

       $pathGL_code/scripts/create-dataset-xmlfile ${path_data}"MC."${sample_name}"*.root" MC_$sample_name.xml
       python $pathGL_code/scripts/crab/readaMCatNloEntries.py 10 MC_$sample_name.xml True
done

# # #DATA
for sample_name in DATA_SingleMuon_Run2016v3B DATA_SingleMuon_Run2016v3C DATA_SingleMuon_Run2016v3D DATA_SingleMuon_Run2016v3E DATA_SingleMuon_Run2016v3F #DATA_SingleMuon_Run2016v3G DATA_SingleMuon_Run2016v3H 

do
    echo $sample_name 
    $pathGL_code/scripts/create-dataset-xmlfile ${path_data}"DATA."${sample_name}"*.root" DATA_$sample_name.xml
    python $pathGL_code/scripts/crab/readaMCatNloEntries.py 10 DATA_$sample_name.xml True

done
pwd
cd $pathGL_code/ZprimeSemiLeptonic/macros
