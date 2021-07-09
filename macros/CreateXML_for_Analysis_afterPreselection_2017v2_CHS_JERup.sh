#!/bin/bash
#where UHH2 code installed
pathGL_code=/nfs/dust/cms/user/hugobg/UHH2_v2/CMSSW_10_2_17/src/UHH2/
#where (NOT MERGED) trees after preselection stored
path_data=/nfs/dust/cms/group/zprime-uhh/Presel_2017/workdir_Zprime_PreSelec_2017_JERup/ 

mkdir $pathGL_code/ZprimeSemiLeptonic/data/Skimming_datasets_2017_common_CHS_JERup
cd $pathGL_code/ZprimeSemiLeptonic/data/Skimming_datasets_2017_common_CHS_JERup


# #MC

for sample_name in TTToSemiLeptonic_2017v2 #TTToHadronic_2017v2 TTTo2L2Nu_2017v2 WW_2017v2 WZ_2017v2 ZZ_2017v2 ST_t-channel_antitop_2017v2 ST_t-channel_top_2017v2 ST_tW_antitop_5f_inclusiveDecays_2017v2 ST_tW_top_5f_inclusiveDecays_2017v2 ST_s-channel_lepton_2017v2 ST_s-channel_hadronic_2017v2  WJetsToLNu_HT-70To100_2017v2 WJetsToLNu_HT-100To200_2017v2 WJetsToLNu_HT-200To400_2017v2 WJetsToLNu_HT-400To600_2017v2 WJetsToLNu_HT-600To800_2017v2 WJetsToLNu_HT-800To1200_2017v2 WJetsToLNu_HT-1200To2500_2017v2 WJetsToLNu_HT-2500ToInf_2017v2  QCD_HT1000to1500_2017v2 QCD_HT100to200_2017v2 QCD_HT1500to2000_2017v2 QCD_HT2000toInf_2017v2 QCD_HT200to300_2017v2 QCD_HT300to500_2017v2 QCD_HT500to700_2017v2 QCD_HT50to100_2017v2 QCD_HT700to1000_2017v2 DYJetsToLL_M-50_HT-100to200_2017v2 DYJetsToLL_M-50_HT-1200to2500_2017v2 DYJetsToLL_M-50_HT-200to400_2017v2 DYJetsToLL_M-50_HT-2500toInf_2017v2 DYJetsToLL_M-50_HT-400to600_v7_2017v2 DYJetsToLL_M-50_HT-600to800_2017v2 DYJetsToLL_M-50_HT-800to1200_2017v2


do
    echo $sample_name

    echo ${path_data}"MC."${sample_name}"*.root"

       $pathGL_code/scripts/create-dataset-xmlfile ${path_data}"uhh2.AnalysisModuleRunner.MC."${sample_name}"*.root" MC_$sample_name.xml
       python $pathGL_code/scripts/crab/readaMCatNloEntries.py 10 MC_$sample_name.xml True
done

pwd
cd $pathGL_code/ZprimeSemiLeptonic/macros
