#!/bin/bash

StringVal='
DYJetsToLL_M-50_HT-600to800_2018_1.xml
DYJetsToLL_M-50_HT-600to800_2018_2.xml
ST_s-channel_lepton_2018_1.xml
ST_s-channel_lepton_2018_2.xml
ST_s-channel_lepton_2018_3.xml
ST_s-channel_lepton_2018_4.xml
TTTo2L2Nu_2018_1.xml
TTTo2L2Nu_2018_10.xml
TTTo2L2Nu_2018_2.xml
TTTo2L2Nu_2018_3.xml
TTTo2L2Nu_2018_4.xml
TTTo2L2Nu_2018_5.xml
TTTo2L2Nu_2018_6.xml
TTTo2L2Nu_2018_7.xml
TTTo2L2Nu_2018_8.xml
TTTo2L2Nu_2018_9.xml
TTToSemiLeptonic_2018_1.xml
TTToSemiLeptonic_2018_10.xml
TTToSemiLeptonic_2018_11.xml
TTToSemiLeptonic_2018_12.xml
TTToSemiLeptonic_2018_13.xml
TTToSemiLeptonic_2018_14.xml
TTToSemiLeptonic_2018_15.xml
TTToSemiLeptonic_2018_16.xml
TTToSemiLeptonic_2018_17.xml
TTToSemiLeptonic_2018_18.xml
TTToSemiLeptonic_2018_19.xml
TTToSemiLeptonic_2018_2.xml
TTToSemiLeptonic_2018_20.xml
TTToSemiLeptonic_2018_3.xml
TTToSemiLeptonic_2018_4.xml
TTToSemiLeptonic_2018_5.xml
TTToSemiLeptonic_2018_6.xml
TTToSemiLeptonic_2018_7.xml
TTToSemiLeptonic_2018_8.xml
TTToSemiLeptonic_2018_9.xml
WJetsToLNu_HT-1200To2500_2018_1.xml
WJetsToLNu_HT-200To400_2018_1.xml
WJetsToLNu_HT-200To400_2018_2.xml
WJetsToLNu_HT-200To400_2018_3.xml
WJetsToLNu_HT-2500ToInf_2018_1.xml
WJetsToLNu_HT-600To800_2018_1.xml
WJetsToLNu_HT-600To800_2018_2.xml
WJetsToLNu_HT-600To800_2018_3.xml
WJetsToLNu_HT-800To1200_2018_1.xml
'
for val in $StringVal;



do
    sframe_main ${val}
done


