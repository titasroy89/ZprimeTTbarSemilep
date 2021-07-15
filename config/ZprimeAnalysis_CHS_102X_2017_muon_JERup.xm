<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE JobConfiguration PUBLIC "" "JobConfig.dtd" [

<!ENTITY TargetLumi      "41557">
<!ENTITY PREFIX          "uhh2.AnalysisModuleRunner.">
<!ENTITY b_Cacheable     "False">
<!ENTITY NEVT            "-1">

<!ENTITY IS_PUPPI            "true">
<!ENTITY IS_LOOSER_SELECTION "false">
<!ENTITY CHANNEL             "muon">
<!ENTITY OUTPUTdir           "/nfs/dust/cms/user/hugobg/ZPrime_102X/analysis_output/2017_CHS/&CHANNEL;/">

<!ENTITY DATA_EGamma_Run2017v2A       SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_EGamma_Run2017v2A.xml">
<!ENTITY DATA_SingleMuon_Run2017v2A   SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_SingleMuon_Run2017v2A.xml">
<!ENTITY DATA_EGamma_Run2017v2B       SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_EGamma_Run2017v2B.xml">
<!ENTITY DATA_SingleMuon_Run2017v2B   SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_SingleMuon_Run2017v2B.xml">
<!ENTITY DATA_EGamma_Run2017v2C       SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_EGamma_Run2017v2C.xml">
<!ENTITY DATA_SingleMuon_Run2017v2C   SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_SingleMuon_Run2017v2C.xml">
<!ENTITY DATA_EGamma_Run2017v2D       SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_EGamma_Run2017v2D.xml">
<!ENTITY DATA_SingleMuon_Run2017v2D   SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_SingleMuon_Run2017v2D.xml">
<!ENTITY DATA_EGamma_Run2017v2E       SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_EGamma_Run2017v2E.xml">
<!ENTITY DATA_SingleMuon_Run2017v2E   SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_SingleMuon_Run2017v2E.xml">
<!ENTITY DATA_EGamma_Run2017v2F       SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_EGamma_Run2017v2F.xml">
<!ENTITY DATA_SingleMuon_Run2017v2F   SYSTEM  "../data/Skimming_datasets_2017_common_CHS/DATA_DATA_SingleMuon_Run2017v2F.xml">


<!ENTITY TTToSemiLeptonic_2017v2          SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_TTToSemiLeptonic_2017v2.xml">
<!ENTITY TTToHadronic_2017v2              SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_TTToHadronic_2017v2.xml">
<!ENTITY TTTo2L2Nu_2017v2                 SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_TTTo2L2Nu_2017v2.xml">

<!ENTITY WJetsToLNu_HT-70To100_2017v2     SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_WJetsToLNu_HT-70To100_2017v2.xml">
<!ENTITY WJetsToLNu_HT-100To200_2017v2    SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_WJetsToLNu_HT-100To200_2017v2.xml">
<!ENTITY WJetsToLNu_HT-200To400_2017v2    SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_WJetsToLNu_HT-200To400_2017v2.xml">
<!ENTITY WJetsToLNu_HT-400To600_2017v2    SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_WJetsToLNu_HT-400To600_2017v2.xml">
<!ENTITY WJetsToLNu_HT-600To800_2017v2    SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_WJetsToLNu_HT-600To800_2017v2.xml">
<!ENTITY WJetsToLNu_HT-800To1200_2017v2   SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_WJetsToLNu_HT-800To1200_2017v2.xml">
<!ENTITY WJetsToLNu_HT-1200To2500_2017v2  SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_WJetsToLNu_HT-1200To2500_2017v2.xml">
<!ENTITY WJetsToLNu_HT-2500ToInf_2017v2   SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_WJetsToLNu_HT-2500ToInf_2017v2.xml">


<!ENTITY DYJetsToLL_M-50_HT-100to200_2017v2       SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_DYJetsToLL_M-50_HT-100to200_2017v2.xml">
<!ENTITY DYJetsToLL_M-50_HT-200to400_2017v2       SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_DYJetsToLL_M-50_HT-200to400_2017v2.xml">
<!ENTITY DYJetsToLL_M-50_HT-400to600_v7_2017v2    SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_DYJetsToLL_M-50_HT-400to600_v7_2017v2.xml">
<!ENTITY DYJetsToLL_M-50_HT-600to800_2017v2       SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_DYJetsToLL_M-50_HT-600to800_2017v2.xml">
<!ENTITY DYJetsToLL_M-50_HT-800to1200_2017v2      SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_DYJetsToLL_M-50_HT-800to1200_2017v2.xml">
<!ENTITY DYJetsToLL_M-50_HT-1200to2500_2017v2     SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_DYJetsToLL_M-50_HT-1200to2500_2017v2.xml">
<!ENTITY DYJetsToLL_M-50_HT-2500toInf_2017v2      SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_DYJetsToLL_M-50_HT-2500toInf_2017v2.xml">

<!ENTITY WW_2017v2  SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_WW_2017v2.xml">
<!ENTITY WZ_2017v2  SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_WZ_2017v2.xml">
<!ENTITY ZZ_2017v2  SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_ZZ_2017v2.xml">

<!ENTITY ST_tW_antitop_5f_inclusiveDecays  SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_ST_tW_antitop_5f_inclusiveDecays_2017v2.xml">
<!ENTITY ST_tW_top_5f_inclusiveDecays      SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_ST_tW_top_5f_inclusiveDecays_2017v2.xml">
<!ENTITY ST_t-channel_antitop              SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_ST_t-channel_antitop_2017v2.xml">
<!ENTITY ST_t-channel_top                  SYSTEM  "../data/Skimming_datasets_2017_common_CHS/MC_ST_t-channel_top_2017v2.xml">

<!ENTITY QCD_HT50to100        SYSTEM "../data/Skimming_datasets_2017_common_CHS/MC_QCD_HT50to100_2017v2.xml">
<!ENTITY QCD_HT100to200       SYSTEM "../data/Skimming_datasets_2017_common_CHS/MC_QCD_HT100to200_2017v2.xml">
<!ENTITY QCD_HT200to300       SYSTEM "../data/Skimming_datasets_2017_common_CHS/MC_QCD_HT200to300_2017v2.xml">
<!ENTITY QCD_HT300to500       SYSTEM "../data/Skimming_datasets_2017_common_CHS/MC_QCD_HT300to500_2017v2.xml">
<!ENTITY QCD_HT500to700       SYSTEM "../data/Skimming_datasets_2017_common_CHS/MC_QCD_HT500to700_2017v2.xml">
<!ENTITY QCD_HT700to1000      SYSTEM "../data/Skimming_datasets_2017_common_CHS/MC_QCD_HT700to1000_2017v2.xml">
<!ENTITY QCD_HT1000to1500     SYSTEM "../data/Skimming_datasets_2017_common_CHS/MC_QCD_HT1000to1500_2017v2.xml">
<!ENTITY QCD_HT1500to2000     SYSTEM "../data/Skimming_datasets_2017_common_CHS/MC_QCD_HT1500to2000_2017v2.xml">
<!ENTITY QCD_HT2000toInf      SYSTEM "../data/Skimming_datasets_2017_common_CHS/MC_QCD_HT2000toInf_2017v2.xml">

]>

<!--
<ConfigParse NEventsBreak="0" LastBreak="0" FileSplit="5" AutoResubmit="0"/>
<ConfigSGE RAM="2" DISK="2" Mail="condor.desy@gmail.com" Notification="as" Workdir="workdir_Zprime_Analysis_2017v2_CHS"/>
-->

<JobConfiguration JobName="ZprimePreselectionJob" OutputLevel="INFO">
	<Library Name="libSUHH2ZprimeSemiLeptonic"/>
	<Package Name="SUHH2ZprimeSemiLeptonic.par"/>

        <Cycle Name="uhh2::AnalysisModuleRunner" OutputDirectory="&OUTPUTdir;/" PostFix="" TargetLumi="&TargetLumi;">

	  <InputData Lumi="3386024.049" NEventsMax="&NEVT;" Type="MC" Version="ST_tW_antitop_5f_inclusiveDecays_2017v2" Cacheable="&b_Cacheable;">
	    &ST_tW_antitop_5f_inclusiveDecays;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="5192499.578" NEventsMax="&NEVT;" Type="MC" Version="ST_tW_top_5f_inclusiveDecays_2017v2" Cacheable="&b_Cacheable;">
	    &ST_tW_top_5f_inclusiveDecays;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="7582465.388" NEventsMax="&NEVT;" Type="MC" Version="ST_t-channel_antitop_2017v2" Cacheable="&b_Cacheable;">
	    &ST_t-channel_antitop;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="7382334.321" NEventsMax="&NEVT;" Type="MC" Version="ST_t-channel_top_2017v2" Cacheable="&b_Cacheable;">
	    &ST_t-channel_top;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="102425.363" NEventsMax="&NEVT;" Type="MC" Version="WW_2017v2" Cacheable="&b_Cacheable;">
	    &WW_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>
	
	  <InputData Lumi="141347.1014" NEventsMax="&NEVT;" Type="MC" Version="WZ_2017v2" Cacheable="&b_Cacheable;">
	    &WZ_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>
	
	  <InputData Lumi="158854.1186" NEventsMax="&NEVT;" Type="MC" Version="ZZ_2017v2" Cacheable="&b_Cacheable;">
	    &ZZ_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="7337.300986" NEventsMax="&NEVT;" Type="MC" Version="WJetsToLNu_HT-70To100_2017v2" Cacheable="&b_Cacheable;">
	    &WJetsToLNu_HT-70To100_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="23619.32473" NEventsMax="&NEVT;" Type="MC" Version="WJetsToLNu_HT-100To200_2017v2" Cacheable="&b_Cacheable;">
	    &WJetsToLNu_HT-100To200_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="45109.95602" NEventsMax="&NEVT;" Type="MC" Version="WJetsToLNu_HT-200To400_2017v2" Cacheable="&b_Cacheable;">
	    &WJetsToLNu_HT-200To400_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="246073.4588" NEventsMax="&NEVT;" Type="MC" Version="WJetsToLNu_HT-400To600_2017v2" Cacheable="&b_Cacheable;">
	    &WJetsToLNu_HT-400To600_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="1669165.429" NEventsMax="&NEVT;" Type="MC" Version="WJetsToLNu_HT-600To800_2017v2" Cacheable="&b_Cacheable;">
	    &WJetsToLNu_HT-600To800_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="3755900.093" NEventsMax="&NEVT;" Type="MC" Version="WJetsToLNu_HT-800To1200_2017v2" Cacheable="&b_Cacheable;">
	    &WJetsToLNu_HT-800To1200_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="18474748.15" NEventsMax="&NEVT;" Type="MC" Version="WJetsToLNu_HT-1200To2500_2017v2" Cacheable="&b_Cacheable;">
	    &WJetsToLNu_HT-1200To2500_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

	  <InputData Lumi="2558175728" NEventsMax="&NEVT;" Type="MC" Version="WJetsToLNu_HT-2500ToInf_2017v2" Cacheable="&b_Cacheable;">
	    &WJetsToLNu_HT-2500ToInf_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>


	  <InputData Lumi="1" NEventsMax="&NEVT;" Type="DATA" Version="DATA_SingleMuon_Run2017v2B_blinded" Cacheable="&b_Cacheable;">
	    &DATA_SingleMuon_Run2017v2B;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>


          <InputData Lumi="1" NEventsMax="&NEVT;" Type="DATA" Version="DATA_SingleMuon_Run2017v2C_blinded" Cacheable="&b_Cacheable;">
            &DATA_SingleMuon_Run2017v2C;
            <InputTree Name="AnalysisTree" />
            <OutputTree Name="AnalysisTree" />
          </InputData>


          <InputData Lumi="1" NEventsMax="&NEVT;" Type="DATA" Version="DATA_SingleMuon_Run2017v2D_blinded" Cacheable="&b_Cacheable;">
            &DATA_SingleMuon_Run2017v2D;
            <InputTree Name="AnalysisTree" />
            <OutputTree Name="AnalysisTree" />
          </InputData>

          <InputData Lumi="1" NEventsMax="&NEVT;" Type="DATA" Version="DATA_SingleMuon_Run2017v2E_blinded" Cacheable="&b_Cacheable;">
            &DATA_SingleMuon_Run2017v2E;
            <InputTree Name="AnalysisTree" />
            <OutputTree Name="AnalysisTree" />
          </InputData>


          <InputData Lumi="1" NEventsMax="&NEVT;" Type="DATA" Version="DATA_SingleMuon_Run2017v2F_blinded" Cacheable="&b_Cacheable;">
            &DATA_SingleMuon_Run2017v2F;
            <InputTree Name="AnalysisTree" />
            <OutputTree Name="AnalysisTree" />
          </InputData>


	  <InputData Lumi="35279949.78" NEventsMax="&NEVT;" Type="MC" Version="TTToSemiLeptonic_2017v2" Cacheable="&b_Cacheable;">
	    &TTToSemiLeptonic_2017v2;
	    <InputTree Name="AnalysisTree" />
	    <OutputTree Name="AnalysisTree" />
	  </InputData>

          <InputData Lumi="109490.4712" NEventsMax="&NEVT;" Type="MC" Version="TTToHadronic_2017v2" Cacheable="&b_Cacheable;">
            &TTToHadronic_2017v2;
            <InputTree Name="AnalysisTree" />
            <OutputTree Name="AnalysisTree" />
          </InputData>

          <InputData Lumi="7427723.054" NEventsMax="&NEVT;" Type="MC" Version="TTTo2L2Nu_2017v2" Cacheable="&b_Cacheable;">
            &TTTo2L2Nu_2017v2;
            <InputTree Name="AnalysisTree" />
            <OutputTree Name="AnalysisTree" />
          </InputData>


          <InputData Lumi="7.277908556" NEventsMax="&NEVT;" Type="MC" Version="QCD_HT100to200_2017v2" Cacheable="&b_Cacheable;">
            &QCD_HT100to200;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="38.25198123" NEventsMax="&NEVT;" Type="MC" Version="QCD_HT200to300_2017v2" Cacheable="&b_Cacheable;">
            &QCD_HT200to300;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="184.1036189" NEventsMax="&NEVT;" Type="MC" Version="QCD_HT300to500_2017v2" Cacheable="&b_Cacheable;">
            &QCD_HT300to500;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="1873.591467" NEventsMax="&NEVT;" Type="MC" Version="QCD_HT500to700_2017v2" Cacheable="&b_Cacheable;">
            &QCD_HT500to700;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="7406.85562" NEventsMax="&NEVT;" Type="MC" Version="QCD_HT700to1000_2017v2" Cacheable="&b_Cacheable;">
            &QCD_HT700to1000;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="15488.8422" NEventsMax="&NEVT;" Type="MC" Version="QCD_HT1000to1500_2017v2" Cacheable="&b_Cacheable;">
            &QCD_HT1000to1500;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="115192.4158" NEventsMax="&NEVT;" Type="MC" Version="QCD_HT1500to2000_2017v2" Cacheable="&b_Cacheable;">
            &QCD_HT1500to2000;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="290812.8243" NEventsMax="&NEVT;" Type="MC" Version="QCD_HT2000toInf_2017v2" Cacheable="&b_Cacheable;">
            &QCD_HT2000toInf;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="61665.7621" NEventsMax="&NEVT;" Type="MC" Version="DYJetsToLL_M-50_HT-100to200_2017v2" Cacheable="&b_Cacheable;">
            &DYJetsToLL_M-50_HT-100to200_2017v2;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="211739.9445" NEventsMax="&NEVT;" Type="MC" Version="DYJetsToLL_M-50_HT-200to400_2017v2" Cacheable="&b_Cacheable;">
            &DYJetsToLL_M-50_HT-200to400_2017v2;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="1456885.368" NEventsMax="&NEVT;" Type="MC" Version="DYJetsToLL_M-50_HT-400to600_v7_2017v2" Cacheable="&b_Cacheable;">
            &DYJetsToLL_M-50_HT-400to600_v7_2017v2;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="5169237.723" NEventsMax="&NEVT;" Type="MC" Version="DYJetsToLL_M-50_HT-600to800_2017v2" Cacheable="&b_Cacheable;">
            &DYJetsToLL_M-50_HT-600to800_2017v2;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="3984709.669" NEventsMax="&NEVT;" Type="MC" Version="DYJetsToLL_M-50_HT-800to1200_2017v2" Cacheable="&b_Cacheable;">
            &DYJetsToLL_M-50_HT-800to1200_2017v2;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="3312836.292" NEventsMax="&NEVT;" Type="MC" Version="DYJetsToLL_M-50_HT-1200to2500_2017v2" Cacheable="&b_Cacheable;">
            &DYJetsToLL_M-50_HT-1200to2500_2017v2;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>

          <InputData Lumi="91525330.96" NEventsMax="&NEVT;" Type="MC" Version="DYJetsToLL_M-50_HT-2500toInf_2017v2" Cacheable="&b_Cacheable;">
            &DYJetsToLL_M-50_HT-2500toInf_2017v2;
            <InputTree Name="AnalysisTree"/>
            <OutputTree Name="AnalysisTree"/>
          </InputData>


    <UserConfig>
      <Item Name="PrimaryVertexCollection" Value="offlineSlimmedPrimaryVertices"/>
      <Item Name="GenParticleCollection"   Value="GenParticles"/>
      <Item Name="ElectronCollection"      Value="slimmedElectronsUSER"/>
      <Item Name="MuonCollection"          Value="slimmedMuonsUSER"/>
      <Item Name="JetCollection"           Value="jetsAk4CHS"/>
      <Item Name="GenJetCollection"        Value="slimmedGenJets"/>
      <Item Name="TopJetCollection"        Value="jetsAk8CHSSubstructure_SoftDropCHS"/>
      <Item Name="GenTopJetCollection"     Value="genjetsAk8SubstructureSoftDrop"/> <!-- Check odinary ak8GenJetsFat !-->
      <Item Name="TopPuppiJetCollection"   Value="jetsAk8PuppiSubstructure_SoftDropPuppi"/>
      <Item Name="METName"                 Value="slimmedMETsPuppi"/>
      <Item Name="genMETName"              Value="slimmedMETs_GenMET"/>

      <Item Name="lumi_file" Value="/nfs/dust/cms/user/hugobg/UHH2_v2/CMSSW_10_2_17/src/UHH2/common/data/2017/Cert_314472-325175_13TeV_PromptReco_Collisions18_JSON.root"/>
      <Item Name="lumihists_lumi_per_bin" Value="500.0"/>


      <Item Name="pileup_directory"           Value="/nfs/dust/cms/user/hugobg/UHH2_v2/CMSSW_10_2_17/src/UHH2/common/data/2017/MyMCPileupHistogram.root" />
      <Item Name="pileup_directory_data"      Value="/nfs/dust/cms/user/hugobg/UHH2_v2/CMSSW_10_2_17/src/UHH2/common/data/2017/MyDataPileupHistogram2017.root" />
      <Item Name="pileup_directory_data_up"   Value="/nfs/dust/cms/user/hugobg/UHH2_v2/CMSSW_10_2_17/src/UHH2/common/data/2017/MyDataPileupHistogram2017_72383.root" />
      <Item Name="pileup_directory_data_down" Value="/nfs/dust/cms/user/hugobg/UHH2_v2/CMSSW_10_2_17/src/UHH2/common/data/2017/MyDataPileupHistogram2017_66017.root" />


      <Item Name="BTagCalibration" Value = "/nfs/dust/cms/user/hugobg/UHH2_v2/CMSSW_10_2_17/src/UHH2/common/data/2017/DeepFlavour_94XSF_V4_B_F.csv" />

      <Item Name="is_puppi" Value="&IS_PUPPI;"/>
      <Item Name="is_looser_selection" Value="&IS_LOOSER_SELECTION;"/>


      <Item Name="use_sframe_weight"  Value="false"/>
      <Item Name="jersmear_direction" Value="nominal"/>
      <Item Name="jecsmear_direction" Value="nominal"/>
      <Item Name="ScaleVariationMuR" Value="nominal"/>
      <Item Name="ScaleVariationMuF" Value="nominal"/>
      <Item Name="Sys_MuonID"         Value="nominal"/>
      <Item Name="Sys_MuonTrigger"    Value="nominal"/>
      <Item Name="Sys_PU"             Value="central"/>
      <Item Name="Sys_BTagSF"         Value="nominal"/>
      <Item Name="Sys_EleID"         Value="nominal"/>
      <Item Name="Sys_EleTrigger"    Value="nominal"/>
      <Item Name="channel"            Value="&CHANNEL;"/>


      <Item Name="AnalysisModule" Value="ZprimeAnalysisModule"/>
    </UserConfig>



	</Cycle>
</JobConfiguration>