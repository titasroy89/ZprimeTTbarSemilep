#include <iostream>
#include <memory>

#include <UHH2/core/include/AnalysisModule.h>
#include <UHH2/core/include/Event.h>
#include <UHH2/core/include/Selection.h>
#include "UHH2/common/include/PrintingModules.h"

#include <UHH2/common/include/CleaningModules.h>
#include <UHH2/common/include/NSelections.h>
#include <UHH2/common/include/LumiSelection.h>
#include <UHH2/common/include/TriggerSelection.h>
#include <UHH2/common/include/JetCorrections.h>
#include <UHH2/common/include/ObjectIdUtils.h>
#include <UHH2/common/include/MuonIds.h>
#include <UHH2/common/include/ElectronIds.h>
#include <UHH2/common/include/JetIds.h>
#include <UHH2/common/include/TopJetIds.h>
#include <UHH2/common/include/TTbarGen.h>
#include <UHH2/common/include/Utils.h>
#include <UHH2/common/include/AdditionalSelections.h>
#include "UHH2/common/include/LuminosityHists.h"
#include <UHH2/common/include/MuonHists.h>
#include <UHH2/common/include/ElectronHists.h>
#include <UHH2/common/include/JetHists.h>
#include <UHH2/common/include/EventHists.h>
#include <UHH2/common/include/CommonModules.h>

#include <UHH2/ZprimeSemiLeptonic/include/ModuleBASE.h>
#include <UHH2/ZprimeSemiLeptonic/include/ZprimeSemiLeptonicSelections.h>
#include <UHH2/ZprimeSemiLeptonic/include/ZprimeSemiLeptonicModules.h>
#include <UHH2/ZprimeSemiLeptonic/include/ZprimeSemiLeptonicPreselectionHists.h>
#include <UHH2/ZprimeSemiLeptonic/include/ZprimeSemiLeptonicGeneratorHists.h>

using namespace std;

class ZprimePreselectionModule_commonmodules : public ModuleBASE {

public:
  explicit ZprimePreselectionModule_commonmodules(uhh2::Context&);
  virtual bool process(uhh2::Event&) override;
  void book_histograms(uhh2::Context&, vector<string>);
  void fill_histograms(uhh2::Event&, string);
  void init_TopJEC_JLC(uhh2::Context& ctx);

protected:


  // Corrections
  std::unique_ptr<CommonModules>   common;
  std::unique_ptr<YearSwitcher> topjet_corrector_MC, topjet_corrector_data;
  std::shared_ptr<RunSwitcher> topjec_switcher_16, topjec_switcher_17, topjec_switcher_18;
  std::unique_ptr<YearSwitcher> topjet_subjet_corrector_MC, topjet_subjet_corrector_data;
  std::shared_ptr<RunSwitcher> topjec_subjet_switcher_16, topjec_subjet_switcher_17, topjec_subjet_switcher_18;
  std::unique_ptr<YearSwitcher> TopJLC_MC,  TopJLC_data;
  std::shared_ptr<RunSwitcher> TopJLC_switcher16, TopJLC_switcher17, TopJLC_switcher18;


  std::unique_ptr<GenericJetResolutionSmearer>     TopJER_smearer;
  std::unique_ptr<GenericJetResolutionSmearer>     TopJER_puppi_smearer;


  // Cleaners
  std::unique_ptr<MuonCleaner>                     muon_cleaner;
  std::unique_ptr<ElectronCleaner>                 electron_cleaner;

  std::unique_ptr<JetCleaner>                      jet_IDcleaner, jet_cleaner1, jet_cleaner2;
  std::unique_ptr<TopJetCleaner>                   topjet_IDcleaner, topjet_cleaner, topjet_puppi_IDcleaner, topjet_puppi_cleaner;



  // Selections
  //std::unique_ptr<uhh2::Selection> lumi_sel;
  //std::unique_ptr<uhh2::AndSelection> metfilters_sel;

  std::unique_ptr<uhh2::Selection> genflavor_sel;

  std::unique_ptr<uhh2::Selection> jet1_sel;
  std::unique_ptr<uhh2::Selection> jet2_sel;
  std::unique_ptr<uhh2::Selection> met_sel;

  bool isMC, ispuppi;

  std::unique_ptr<Hists> lumihists;
  TString METcollection;


  // Runnumbers for applying different corrections


  bool is2016v2, is2016v3, is2017, is2018;



  // NN vars

  Event::Handle<float> h_MET;
  Event::Handle<float> h_ST;
  Event::Handle<float> h_STjets;
  Event::Handle<float> h_STlep;
  Event::Handle<float> h_NPV;
  Event::Handle<float> h_N_jets;
  Event::Handle<float> h_pt_jet;
  Event::Handle<float> h_pt_jet1;
  Event::Handle<float> h_pt_jet2;
  Event::Handle<float> h_pt_jet3;
  Event::Handle<float> h_eta_jet;
  Event::Handle<float> h_eta_jet1;
  Event::Handle<float> h_eta_jet2;
  Event::Handle<float> h_eta_jet3;
  Event::Handle<float> h_phi_jet;
  Event::Handle<float> h_phi_jet1;
  Event::Handle<float> h_phi_jet2;
  Event::Handle<float> h_phi_jet3;
  Event::Handle<float> h_m_jet;
  Event::Handle<float> h_m_jet1;
  Event::Handle<float> h_m_jet2;
  Event::Handle<float> h_m_jet3;
  Event::Handle<float> h_csv_jet;
  Event::Handle<float> h_csv_jet1;
  Event::Handle<float> h_csv_jet2;
  Event::Handle<float> h_csv_jet3;
  Event::Handle<float> h_S11;
  Event::Handle<float> h_S12;
  Event::Handle<float> h_S13;
  Event::Handle<float> h_S22;
  Event::Handle<float> h_S23;
  Event::Handle<float> h_S33;
  Event::Handle<float> h_N_mu;
  Event::Handle<float> h_pt_mu;
  Event::Handle<float> h_eta_mu;
  Event::Handle<float> h_phi_mu;
  Event::Handle<float> h_reliso_mu;
  Event::Handle<float> h_N_ele;
  Event::Handle<float> h_pt_ele;
  Event::Handle<float> h_eta_ele;
  Event::Handle<float> h_phi_ele;
  Event::Handle<float> h_reliso_ele;
  Event::Handle<float> h_N_Ak8Puppijets;
  Event::Handle<float> h_pt_Ak8Puppijets;
  Event::Handle<float> h_pt_Ak8Puppijet1;
  Event::Handle<float> h_pt_Ak8Puppijet2;
  Event::Handle<float> h_pt_Ak8Puppijet3;
  Event::Handle<float> h_eta_Ak8Puppijets;
  Event::Handle<float> h_eta_Ak8Puppijet1;
  Event::Handle<float> h_eta_Ak8Puppijet2;
  Event::Handle<float> h_eta_Ak8Puppijet3;
  Event::Handle<float> h_phi_Ak8Puppijets;
  Event::Handle<float> h_phi_Ak8Puppijet1;
  Event::Handle<float> h_phi_Ak8Puppijet2;
  Event::Handle<float> h_phi_Ak8Puppijet3;
  Event::Handle<float> h_mSD_Ak8Puppijets;
  Event::Handle<float> h_mSD_Ak8Puppijet1;
  Event::Handle<float> h_mSD_Ak8Puppijet2;
  Event::Handle<float> h_mSD_Ak8Puppijet3;
  Event::Handle<float> h_dR_mu_Ak8Puppijet;
  Event::Handle<float> h_dR_ele_Ak8Puppijet;
  Event::Handle<float> h_dR_jet_Ak8Puppijet;
  Event::Handle<float> h_dRmin_mu_jet;
  Event::Handle<float> h_dRmin_ele_jet;
  Event::Handle<float> h_ptrel_mu_jet;
  Event::Handle<float> h_ptrel_ele_jet;
  Event::Handle<float> h_dphi_mu_jet1;
  Event::Handle<float> h_dphi_ele_jet1;
  Event::Handle<float> h_dphi_mu_Ak8Puppijet1;
  Event::Handle<float> h_dphi_ele_Ak8Puppijet1;

};

void ZprimePreselectionModule_commonmodules::book_histograms(uhh2::Context& ctx, vector<string> tags){
  for(const auto & tag : tags){
    string mytag = tag+"_General";
    book_HFolder(mytag, new ZprimeSemiLeptonicPreselectionHists(ctx,mytag));
    mytag = tag+"_Muons";
    book_HFolder(mytag, new MuonHists(ctx,mytag));
    mytag = tag+"_Electrons";
    book_HFolder(mytag, new ElectronHists(ctx,mytag));
    mytag = tag+"_Jets";
    book_HFolder(mytag, new JetHists(ctx,mytag));
    mytag = tag+"_Event";
    book_HFolder(mytag, new EventHists(ctx,mytag));
    mytag = tag+"_Generator";
    book_HFolder(mytag, new ZprimeSemiLeptonicGeneratorHists(ctx,mytag));
  }
}

void ZprimePreselectionModule_commonmodules::fill_histograms(uhh2::Event& event, string tag){
  string mytag = tag+"_General";
  HFolder(mytag)->fill(event);
  mytag = tag+"_Muons";
  HFolder(mytag)->fill(event);
  mytag = tag+"_Electrons";
  HFolder(mytag)->fill(event);
  mytag = tag+"_Jets";
  HFolder(mytag)->fill(event);
  mytag = tag+"_Event";
  HFolder(mytag)->fill(event);
  mytag = tag+"_Generator";
  HFolder(mytag)->fill(event);
}

void ZprimePreselectionModule_commonmodules::init_TopJEC_JLC(uhh2::Context& ctx){ 
  //jec files for top jet JEC
  // Parameters for JEC & JLC sets
  std::string jec_tag_2016, jec_ver_2016;
  std::string jec_tag_2017, jec_ver_2017;
  std::string jec_tag_2018, jec_ver_2018;
  std::string jec_jet_coll, jec_subjet_coll; 
  std::string top_puppi, top_CHS;


  jec_tag_2016 = "Summer16_07Aug2017";
  jec_ver_2016 = "11";

  jec_tag_2017 = "Fall17_17Nov2017";
  jec_ver_2017 = "32";

  jec_tag_2018 = "Autumn18";
  jec_ver_2018 = "19";

  if(ispuppi){
    jec_jet_coll = "AK8PFPuppi";
    jec_subjet_coll = "AK4PFPuppi";
  }
  else{
    jec_jet_coll = "AK8PFchs";
    jec_subjet_coll = "AK4PFchs";
  }
  top_puppi = "toppuppijets";
  top_CHS = "topjets";
  
  if(isMC){
    topjet_corrector_MC.reset(new YearSwitcher(ctx));
    topjet_subjet_corrector_MC.reset(new YearSwitcher(ctx));
    TopJLC_MC.reset(new YearSwitcher(ctx));

    if (!ispuppi){//CHS
      topjet_corrector_MC->setup2016(std::make_shared<TopJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2016, jec_ver_2016, jec_jet_coll)));
      topjet_corrector_MC->setup2017(std::make_shared<TopJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2017, jec_ver_2017, jec_jet_coll)));
      topjet_corrector_MC->setup2018(std::make_shared<TopJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2018, jec_ver_2018, jec_jet_coll)));
                  
      topjet_subjet_corrector_MC->setup2016(std::make_shared<SubJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2016, jec_ver_2016, jec_subjet_coll)));
      topjet_subjet_corrector_MC->setup2017(std::make_shared<SubJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2017, jec_ver_2017, jec_subjet_coll)));
      topjet_subjet_corrector_MC->setup2018(std::make_shared<SubJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2018, jec_ver_2018, jec_subjet_coll)));
      
      TopJLC_MC->setup2016(std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesMC(jec_tag_2016, jec_ver_2016, jec_jet_coll),top_CHS));
      TopJLC_MC->setup2017(std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesMC(jec_tag_2017, jec_ver_2017, jec_jet_coll),top_CHS));
      TopJLC_MC->setup2018(std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesMC(jec_tag_2018, jec_ver_2018, jec_jet_coll),top_CHS));
      

    }
    else{//puppi
      topjet_corrector_MC->setup2016(std::make_shared<GenericTopJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2016, jec_ver_2016, jec_jet_coll),top_puppi));
      topjet_corrector_MC->setup2017(std::make_shared<GenericTopJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2017, jec_ver_2017, jec_jet_coll),top_puppi));
      topjet_corrector_MC->setup2018(std::make_shared<GenericTopJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2018, jec_ver_2018, jec_jet_coll),top_puppi));
            
      topjet_subjet_corrector_MC->setup2016(std::make_shared<GenericSubJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2016, jec_ver_2016, jec_subjet_coll),top_puppi));
      topjet_subjet_corrector_MC->setup2017(std::make_shared<GenericSubJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2017, jec_ver_2017, jec_subjet_coll),top_puppi));
      topjet_subjet_corrector_MC->setup2018(std::make_shared<GenericSubJetCorrector>(ctx, JERFiles::JECFilesMC(jec_tag_2018, jec_ver_2018, jec_subjet_coll),top_puppi));
      
      TopJLC_MC->setup2016(std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesMC(jec_tag_2016, jec_ver_2016, jec_jet_coll),top_puppi));
      TopJLC_MC->setup2017(std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesMC(jec_tag_2017, jec_ver_2017, jec_jet_coll),top_puppi));
      TopJLC_MC->setup2018(std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesMC(jec_tag_2018, jec_ver_2018, jec_jet_coll),top_puppi));
      
    }
  }
  //Data
  else{
    topjec_switcher_16.reset(new RunSwitcher(ctx, "2016"));
    topjec_subjet_switcher_16.reset(new RunSwitcher(ctx, "2016"));
    TopJLC_switcher16.reset(new RunSwitcher(ctx, "2016"));
    
    for (const auto & runItr : runPeriods2016) { // runPeriods defined in common/include/Utils.h
      if(!ispuppi){
	topjec_switcher_16->setupRun(runItr, std::make_shared<TopJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2016, jec_ver_2016, jec_jet_coll, runItr)));
	topjec_subjet_switcher_16->setupRun(runItr, std::make_shared<SubJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2016, jec_ver_2016, jec_subjet_coll, runItr)));
	TopJLC_switcher16->setupRun(runItr, std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesDATA(jec_tag_2016, jec_ver_2016, jec_jet_coll, runItr),top_CHS));
      }
      else{
	topjec_switcher_16->setupRun(runItr, std::make_shared<GenericTopJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2016, jec_ver_2016, jec_jet_coll, runItr),top_puppi));
	topjec_subjet_switcher_16->setupRun(runItr, std::make_shared<GenericSubJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2016, jec_ver_2016, jec_subjet_coll, runItr),top_puppi));
	TopJLC_switcher16->setupRun(runItr, std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesDATA(jec_tag_2016, jec_ver_2016, jec_jet_coll, runItr),top_puppi));
      }
    }

    topjec_switcher_17.reset(new RunSwitcher(ctx, "2017"));
    topjec_subjet_switcher_17.reset(new RunSwitcher(ctx, "2017"));
    TopJLC_switcher17.reset(new RunSwitcher(ctx, "2017"));
    for (const auto & runItr : runPeriods2017) { // runPeriods defined in common/include/Utils.h                                                                           
      if(!ispuppi){
        topjec_switcher_17->setupRun(runItr, std::make_shared<TopJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2017, jec_ver_2017, jec_jet_coll, runItr)));
	topjec_subjet_switcher_17->setupRun(runItr, std::make_shared<SubJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2016, jec_ver_2016, jec_subjet_coll, runItr)));
	TopJLC_switcher17->setupRun(runItr, std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesDATA(jec_tag_2016, jec_ver_2016, jec_jet_coll, runItr),top_CHS));
      }
      else{
        topjec_switcher_17->setupRun(runItr, std::make_shared<GenericTopJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2017, jec_ver_2017, jec_jet_coll, runItr),top_puppi));
	topjec_subjet_switcher_17->setupRun(runItr, std::make_shared<GenericSubJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2017, jec_ver_2017, jec_subjet_coll, runItr),top_puppi));
	TopJLC_switcher17->setupRun(runItr, std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesDATA(jec_tag_2017, jec_ver_2017, jec_jet_coll, runItr),top_puppi));
      }
    }
    topjec_switcher_18.reset(new RunSwitcher(ctx, "2018"));
    topjec_subjet_switcher_18.reset(new RunSwitcher(ctx, "2018"));
    TopJLC_switcher18.reset(new RunSwitcher(ctx, "2018"));
    for (const auto & runItr : runPeriods2018) { // runPeriods defined in common/include/Utils.h                                                                           
      if(!ispuppi){
        topjec_switcher_18->setupRun(runItr, std::make_shared<TopJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2018, jec_ver_2018, jec_jet_coll, runItr)));
	topjec_subjet_switcher_18->setupRun(runItr, std::make_shared<SubJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2018, jec_ver_2018, jec_subjet_coll, runItr)));
	TopJLC_switcher18->setupRun(runItr, std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesDATA(jec_tag_2018, jec_ver_2018, jec_jet_coll, runItr),top_CHS));
      }
      else{
        topjec_switcher_18->setupRun(runItr, std::make_shared<GenericTopJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2018, jec_ver_2018, jec_jet_coll, runItr),top_puppi));
	topjec_subjet_switcher_18->setupRun(runItr, std::make_shared<GenericSubJetCorrector>(ctx, JERFiles::JECFilesDATA(jec_tag_2018, jec_ver_2018, jec_subjet_coll, runItr),top_puppi));
	TopJLC_switcher18->setupRun(runItr, std::make_shared<JetLeptonCleaner_by_KEYmatching>(ctx, JERFiles::JECFilesDATA(jec_tag_2018, jec_ver_2018, jec_jet_coll, runItr),top_puppi));
      }
    }

    topjet_corrector_data.reset(new YearSwitcher(ctx));
    topjet_corrector_data->setup2016(topjec_switcher_16);
    topjet_corrector_data->setup2017(topjec_switcher_17);
    topjet_corrector_data->setup2018(topjec_switcher_18);

    topjet_subjet_corrector_data.reset(new YearSwitcher(ctx));
    topjet_subjet_corrector_data->setup2016(topjec_subjet_switcher_16);
    topjet_subjet_corrector_data->setup2017(topjec_subjet_switcher_17);
    topjet_subjet_corrector_data->setup2018(topjec_subjet_switcher_18);
    
    TopJLC_data.reset(new YearSwitcher(ctx));
    TopJLC_data->setup2016(TopJLC_switcher16);
    TopJLC_data->setup2017(TopJLC_switcher17);
    TopJLC_data->setup2018(TopJLC_switcher18);

   }


}




ZprimePreselectionModule_commonmodules::ZprimePreselectionModule_commonmodules(uhh2::Context& ctx){

  for(auto & kv : ctx.get_all()){
    cout << " " << kv.first << " = " << kv.second << endl;
  }

  //// CONFIGURATION
  // const std::string& _METcollection = ctx.get("METName");
  const TString METcollection = ctx.get("METName");
  const bool isMC = (ctx.get("dataset_type") == "MC");
  const bool ispuppi = (ctx.get("is_puppi") == "true");
  is2016v2 = (ctx.get("dataset_version").find("2016v2") != std::string::npos);
  is2016v3 = (ctx.get("dataset_version").find("2016v3") != std::string::npos);
  is2017 = (ctx.get("dataset_version").find("2017") != std::string::npos);
  is2018 = (ctx.get("dataset_version").find("2018") != std::string::npos);
 
  cout << "Is this running on puppi: " << ispuppi << endl;

  ElectronId eleID;  MuonId muID;
  if(is2017 || is2018){
    eleID = ElectronID_Fall17_tight_noIso;//ToDo: compare cutBased without iso and MVA-based via wp in UHH2
    muID      = MuonID(Muon::CutBasedIdGlobalHighPt);
  }
  if(is2016v2 || is2016v3){
    //eleID = ElectronID_Summer16_tight_noIso;//ToDo: compare cutBased without iso and MVA-based via wp in UHH2
    //muID      = MuonID(Muon::Highpt);
    eleID = ElectronID_Summer16_medium_noIso;
    muID  = MuonID(Muon::CutBasedIdTight); // see more muonIDs https://github.com/cms-sw/cmssw/blob/master/DataFormats/MuonReco/interface/Muon.h#L201
  }
  double electron_pt(50.);
  double muon_pt(55.);
  double jet1_pt(50.);
  double jet2_pt(20.);
  double MET(0.);

  // COMMON MODULES




  /******************************************************************/

  /* GEN Flavor selection [W+jets flavor-splitting] */
  if(ctx.get("dataset_version").find("WJets") != std::string::npos){

    if     (ctx.get("dataset_version").find("_B") != std::string::npos) genflavor_sel.reset(new GenFlavorSelection("b"));
    else if(ctx.get("dataset_version").find("_C") != std::string::npos) genflavor_sel.reset(new GenFlavorSelection("c"));
    else if(ctx.get("dataset_version").find("_L") != std::string::npos) genflavor_sel.reset(new GenFlavorSelection("l"));

    else genflavor_sel.reset(new uhh2::AndSelection(ctx));
  }
  else genflavor_sel.reset(new uhh2::AndSelection(ctx));
  /**************************************************/

  ////

  // Cleaning: Mu, Ele, Jets
  const MuonId muonID(AndId<Muon>(PtEtaCut(muon_pt, 2.4), muID));
  const ElectronId electronID(AndId<Electron>(PtEtaSCCut(electron_pt, 2.5), eleID));
  const JetPFID jetID_CHS(JetPFID::WP_TIGHT_CHS); 
  const JetPFID jetID_PUPPI(JetPFID::WP_TIGHT_PUPPI); 

  muon_cleaner.reset(new MuonCleaner(muonID));
  electron_cleaner.reset(new ElectronCleaner(electronID));
  //  jet_IDcleaner.reset(new JetCleaner(ctx, jetID_CHS));
  jet_IDcleaner.reset(new JetCleaner(ctx, jetID_PUPPI));
  jet_cleaner1.reset(new JetCleaner(ctx, 15., 3.0));
  jet_cleaner2.reset(new JetCleaner(ctx, 30., 2.4));
  topjet_IDcleaner.reset(new TopJetCleaner(ctx, jetID_CHS, "topjets"));
  topjet_cleaner.reset(new TopJetCleaner(ctx, TopJetId(PtEtaCut(400., 2.4)), "topjets"));
  topjet_puppi_IDcleaner.reset(new TopJetCleaner(ctx, jetID_PUPPI, "toppuppijets"));
  topjet_puppi_cleaner.reset(new TopJetCleaner(ctx, TopJetId(PtEtaCut(400., 2.4)), "toppuppijets"));

  //set up JEC and JLC
  init_TopJEC_JLC(ctx);
  
  if(isMC){
    //    ctx.declare_event_input<std::vector<Particle> >(ctx.get("TopJetCollectionGEN"), "topjetsGEN");
    if(is2016v2 || is2016v3){

      TopJER_smearer.reset(new GenericJetResolutionSmearer(ctx, "topjets", "gentopjets", JERSmearing::SF_13TeV_Summer16_25nsV1, "2016/Summer16_25nsV1_MC_PtResolution_AK8PFchs.txt"));
      TopJER_puppi_smearer.reset(new GenericJetResolutionSmearer(ctx, "toppuppijets", "gentopjets", JERSmearing::SF_13TeV_Summer16_25nsV1, "2016/Summer16_25nsV1_MC_PtResolution_AK8PFPuppi.txt"));
    }
    
    if(is2017){

      TopJER_smearer.reset(new GenericJetResolutionSmearer(ctx, "topjets", "gentopjets", JERSmearing::SF_13TeV_Fall17_V3, "2017/Fall17_V3_MC_PtResolution_AK8PFchs.txt"));
      TopJER_puppi_smearer.reset(new GenericJetResolutionSmearer(ctx, "toppuppijets", "gentopjets", JERSmearing::SF_13TeV_Fall17_V3, "2017/Fall17_V3_MC_PtResolution_AK8PFPuppi.txt"));
    }
    
    // Was NOT used yet, 2017 JER SFs were used in previous 2018 iteration!
    if(is2018){

      TopJER_smearer.reset(new GenericJetResolutionSmearer(ctx, "topjets", "gentopjets", JERSmearing::SF_13TeV_Autumn18_RunABCD_V4, "2018/Autumn18_V4_MC_PtResolution_AK8PFchs.txt"));
      TopJER_puppi_smearer.reset(new GenericJetResolutionSmearer(ctx, "toppuppijets", "gentopjets", JERSmearing::SF_13TeV_Autumn18_RunABCD_V4, "2018/Autumn18_V4_MC_PtResolution_AK8PFPuppi.txt"));
    }
    
  }

  //// EVENT SELECTION
  jet1_sel.reset(new NJetSelection(1, -1, JetId(PtEtaCut(jet1_pt, 2.4))));
  jet2_sel.reset(new NJetSelection(2, -1, JetId(PtEtaCut(jet2_pt, 2.4))));
  met_sel  .reset(new METCut  (MET   , uhh2::infinity));



  /// common module for JEC, JLC, etc
  common.reset(new CommonModules());
  common->switch_jetlepcleaner(true);
  common->disable_mcpileupreweight();
  //  common->disable_mclumiweight();
  //  common->disable_lumisel();
  //  common->disable_metfilters();
  common->disable_pvfilter();
  common->disable_jetpfidfilter();
  common->switch_jetPtSorter(false);
  common->switch_metcorrection(true);
  common->init(ctx);



  h_MET = ctx.declare_event_output<float> ("met");
  h_ST = ctx.declare_event_output<float> ("st");
  h_STjets = ctx.declare_event_output<float> ("st_jets");
  h_STlep = ctx.declare_event_output<float> ("st_lep");
  h_NPV = ctx.declare_event_output<float> ("npv_pt");
  h_N_jets = ctx.declare_event_output<float> ("N_jets");
  h_pt_jet = ctx.declare_event_output<float> ("pt_jet");
  h_pt_jet1 = ctx.declare_event_output<float> ("pt_jet1");
  h_pt_jet2 = ctx.declare_event_output<float> ("pt_jet2");
  h_pt_jet3 = ctx.declare_event_output<float> ("pt_jet3");
  h_eta_jet = ctx.declare_event_output<float> ("eta_jet");
  h_eta_jet1 = ctx.declare_event_output<float> ("eta_jet1");
  h_eta_jet2 = ctx.declare_event_output<float> ("eta_jet2");
  h_eta_jet3 = ctx.declare_event_output<float> ("eta_jet3");
  h_phi_jet = ctx.declare_event_output<float> ("phi_jet");
  h_phi_jet1 = ctx.declare_event_output<float> ("phi_jet1");
  h_phi_jet2 = ctx.declare_event_output<float> ("phi_jet2");
  h_phi_jet3 = ctx.declare_event_output<float> ("phi_jet3");
  h_m_jet = ctx.declare_event_output<float> ("m_jet");
  h_m_jet1 = ctx.declare_event_output<float> ("m_jet1");
  h_m_jet2 = ctx.declare_event_output<float> ("m_jet2");
  h_m_jet3 = ctx.declare_event_output<float> ("m_jet3");
  h_csv_jet = ctx.declare_event_output<float> ("csv_jet");
  h_csv_jet1 = ctx.declare_event_output<float> ("csv_jet1");
  h_csv_jet2 = ctx.declare_event_output<float> ("csv_jet2");
  h_csv_jet3 = ctx.declare_event_output<float> ("csv_jet3");
  h_S11 = ctx.declare_event_output<float> ("s11");
  h_S12 = ctx.declare_event_output<float> ("s12");
  h_S13 = ctx.declare_event_output<float> ("s13");
  h_S22 = ctx.declare_event_output<float> ("s22");
  h_S23 = ctx.declare_event_output<float> ("s23");
  h_S33 = ctx.declare_event_output<float> ("s33");
  h_N_mu = ctx.declare_event_output<float> ("N_mu");
  h_pt_mu = ctx.declare_event_output<float> ("pt_mu");
  h_eta_mu = ctx.declare_event_output<float> ("eta_mu");
  h_phi_mu = ctx.declare_event_output<float> ("phi_mu");
  h_reliso_mu = ctx.declare_event_output<float> ("reliso_mu");
  h_N_ele = ctx.declare_event_output<float> ("N_ele");
  h_pt_ele = ctx.declare_event_output<float> ("pt_ele");
  h_eta_ele = ctx.declare_event_output<float> ("eta_ele");
  h_phi_ele = ctx.declare_event_output<float> ("phi_ele");
  h_reliso_ele = ctx.declare_event_output<float> ("reliso_ele");
  h_N_Ak8Puppijets = ctx.declare_event_output<float> ("N_Ak8Puppijets");
  h_pt_Ak8Puppijets = ctx.declare_event_output<float> ("pt_Ak8Puppijets");
  h_pt_Ak8Puppijet1 = ctx.declare_event_output<float> ("pt_Ak8Puppijet1");
  h_pt_Ak8Puppijet2 = ctx.declare_event_output<float> ("pt_Ak8Puppijet2");
  h_pt_Ak8Puppijet3 = ctx.declare_event_output<float> ("pt_Ak8Puppijet3");
  h_eta_Ak8Puppijets = ctx.declare_event_output<float> ("eta_Ak8Puppijets");
  h_eta_Ak8Puppijet1 = ctx.declare_event_output<float> ("eta_Ak8Puppijet1");
  h_eta_Ak8Puppijet2 = ctx.declare_event_output<float> ("eta_Ak8Puppijet2");
  h_eta_Ak8Puppijet3 = ctx.declare_event_output<float> ("eta_Ak8Puppijet3");
  h_phi_Ak8Puppijets = ctx.declare_event_output<float> ("phi_Ak8Puppijets");
  h_phi_Ak8Puppijet1 = ctx.declare_event_output<float> ("phi_Ak8Puppijet1");
  h_phi_Ak8Puppijet2 = ctx.declare_event_output<float> ("phi_Ak8Puppijet2");
  h_phi_Ak8Puppijet3 = ctx.declare_event_output<float> ("phi_Ak8Puppijet3");
  h_mSD_Ak8Puppijets = ctx.declare_event_output<float> ("mSD_Ak8Puppijets");
  h_mSD_Ak8Puppijet1 = ctx.declare_event_output<float> ("mSD_Ak8Puppijet1");
  h_mSD_Ak8Puppijet2 = ctx.declare_event_output<float> ("mSD_Ak8Puppijet2");
  h_mSD_Ak8Puppijet3 = ctx.declare_event_output<float> ("mSD_Ak8Puppijet3");
  h_dR_mu_Ak8Puppijet = ctx.declare_event_output<float> ("dR_mu_Ak8Puppijet");
  h_dR_ele_Ak8Puppijet = ctx.declare_event_output<float> ("dR_ele_Ak8Puppijet");
  h_dR_jet_Ak8Puppijet = ctx.declare_event_output<float> ("dR_jet_Ak8Puppijet");
  h_dRmin_mu_jet = ctx.declare_event_output<float> ("dRmin_mu_jet");
  h_dRmin_ele_jet = ctx.declare_event_output<float> ("dRmin_ele_jet");
  h_ptrel_mu_jet = ctx.declare_event_output<float> ("ptrel_mu_jet");
  h_ptrel_ele_jet = ctx.declare_event_output<float> ("ptrel_ele_jet");
  h_dphi_mu_jet1 = ctx.declare_event_output<float> ("dphi_mu_jet1");
  h_dphi_ele_jet1 = ctx.declare_event_output<float> ("dphi_ele_jet1");
  h_dphi_mu_Ak8Puppijet1 = ctx.declare_event_output<float> ("dphi_mu_Ak8Puppijet1");
  h_dphi_ele_Ak8Puppijet1 = ctx.declare_event_output<float> ("dphi_ele_Ak8Puppijet1");

  // Book histograms
  vector<string> histogram_tags = {"Input", "Lumiselection", "Metfilters", "Lepton1", "JetID", "JetCleaner1", "JetCleaner2", "TopjetCleaner", "Jet1", "Jet2", "MET"};
  book_histograms(ctx, histogram_tags);


  lumihists.reset(new LuminosityHists(ctx, "lumi"));
}


bool ZprimePreselectionModule_commonmodules::process(uhh2::Event& event){

  event.set(h_MET,0);
  event.set(h_ST,0);
  event.set(h_STjets,0);
  event.set(h_STlep,0);
  event.set(h_NPV,0);
  event.set(h_N_jets,0);
  event.set(h_pt_jet,0);
  event.set(h_pt_jet1,0);
  event.set(h_pt_jet2,0);
  event.set(h_pt_jet3,0);
  event.set(h_eta_jet,0);
  event.set(h_eta_jet1,0);
  event.set(h_eta_jet2,0);
  event.set(h_eta_jet3,0);
  event.set(h_phi_jet,0);
  event.set(h_phi_jet1,0);
  event.set(h_phi_jet2,0);
  event.set(h_phi_jet3,0);
  event.set(h_m_jet,0);
  event.set(h_m_jet1,0);
  event.set(h_m_jet2,0);
  event.set(h_m_jet3,0);
  event.set(h_csv_jet,0);
  event.set(h_csv_jet1,0);
  event.set(h_csv_jet2,0);
  event.set(h_csv_jet3,0);
  event.set(h_S11,0);
  event.set(h_S12,0);
  event.set(h_S13,0);
  event.set(h_S22,0);
  event.set(h_S23,0);
  event.set(h_S33,0);
  event.set(h_N_mu,0);
  event.set(h_pt_mu,0);
  event.set(h_eta_mu,0);
  event.set(h_phi_mu,0);
  event.set(h_reliso_mu,0);
  event.set(h_N_ele,0);
  event.set(h_pt_ele,0);
  event.set(h_eta_ele,0);
  event.set(h_phi_ele,0);
  event.set(h_reliso_ele,0);
  event.set(h_N_Ak8Puppijets,0);
  event.set(h_pt_Ak8Puppijets,0);
  event.set(h_pt_Ak8Puppijet1,0);
  event.set(h_pt_Ak8Puppijet2,0);
  event.set(h_pt_Ak8Puppijet3,0);
  event.set(h_eta_Ak8Puppijets,0);
  event.set(h_eta_Ak8Puppijet1,0);
  event.set(h_eta_Ak8Puppijet2,0);
  event.set(h_eta_Ak8Puppijet3,0);
  event.set(h_phi_Ak8Puppijets,0);
  event.set(h_phi_Ak8Puppijet1,0);
  event.set(h_phi_Ak8Puppijet2,0);
  event.set(h_phi_Ak8Puppijet3,0);
  event.set(h_mSD_Ak8Puppijets,0);
  event.set(h_mSD_Ak8Puppijet1,0);
  event.set(h_mSD_Ak8Puppijet2,0);
  event.set(h_mSD_Ak8Puppijet3,0);
  event.set(h_dR_mu_Ak8Puppijet,0);
  event.set(h_dR_ele_Ak8Puppijet,0);
  event.set(h_dR_jet_Ak8Puppijet,0);
  event.set(h_dRmin_mu_jet,0);
  event.set(h_dRmin_ele_jet,0);
  event.set(h_ptrel_mu_jet,0);
  event.set(h_ptrel_ele_jet,0);
  event.set(h_dphi_mu_jet1,0);
  event.set(h_dphi_ele_jet1,0);
  event.set(h_dphi_mu_Ak8Puppijet1,0);
  event.set(h_dphi_ele_Ak8Puppijet1,0);

  //  cout<<"Getting started... "<<event.event<<endl;
  fill_histograms(event, "Input");
  fill_histograms(event, "Lumiselection");


  // GEN ME quark-flavor selection
  if(!event.isRealData){
    if(!genflavor_sel->passes(event)) return false;
  }

  //// LEPTON selection
  muon_cleaner->process(event);
  sort_by_pt<Muon>(*event.muons);

  electron_cleaner->process(event);
  sort_by_pt<Electron>(*event.electrons);

  const bool pass_lep1 = ((event.muons->size() >= 1) || (event.electrons->size() >= 1));
  if(!pass_lep1) return false;

  fill_histograms(event, "Lepton1");
  //  cout<<"Lepton1 ... "<<event.event<<endl;

  //// JET selection
  jet_IDcleaner->process(event);
  fill_histograms(event, "JetID");

  //  cout<<"JetID ... "<<event.event<<endl;
  if(!common->process(event)) return false;

  //Topjet
  if(isMC){
  topjet_corrector_MC->process(event);
  topjet_subjet_corrector_MC->process(event);
  TopJLC_MC->process(event);
  }
   else{
   topjet_corrector_data->process(event);
   topjet_subjet_corrector_data->process(event);
   TopJLC_data->process(event);
   }
  

  jet_cleaner1->process(event);
  sort_by_pt<Jet>(*event.jets);
  fill_histograms(event, "JetCleaner1");
  //cout<<"JetCleaner1 ... "<<event.event<<endl;
  // Lepton-2Dcut variables
  for(auto& muo : *event.muons){

    float    dRmin, pTrel;
    std::tie(dRmin, pTrel) = drmin_pTrel(muo, *event.jets);

    muo.set_tag(Muon::twodcut_dRmin, dRmin);
    muo.set_tag(Muon::twodcut_pTrel, pTrel);
  }

 for(auto& ele : *event.electrons){

    float    dRmin, pTrel;
    std::tie(dRmin, pTrel) = drmin_pTrel(ele, *event.jets);

    ele.set_tag(Electron::twodcut_dRmin, dRmin);
    ele.set_tag(Electron::twodcut_pTrel, pTrel);
  }
 jet_cleaner2->process(event);
  sort_by_pt<Jet>(*event.jets);
  fill_histograms(event, "JetCleaner2");
  //cout<<"JetCleaner2 ... "<<event.event<<endl;

  topjet_IDcleaner->process(event);
  topjet_cleaner->process(event);
  sort_by_pt<TopJet>(*event.topjets);

  topjet_puppi_IDcleaner->process(event);
  topjet_puppi_cleaner->process(event);
  sort_by_pt<TopJet>(*event.toppuppijets);
  fill_histograms(event, "TopjetCleaner");
  //  cout<<"TopjetCleaner ... "<<event.event<<endl;

  // 1st AK4 jet selection
  const bool pass_jet1 = jet1_sel->passes(event);
  if(!pass_jet1) return false;
  fill_histograms(event, "Jet1");

  // 2nd AK4 jet selection
  const bool pass_jet2 = jet2_sel->passes(event);
  if(!pass_jet2) return false;
  fill_histograms(event, "Jet2");

  // MET selection
  const bool pass_met = met_sel->passes(event);
  if(!pass_met) return false;
  fill_histograms(event, "MET");



////////////////////////////////////////////////
// Variables for NN
////////////////////////////////////////////////

  // General
  event.set(h_NPV,event.pvs->size());

  event.set(h_MET,event.met->pt());

  double st = 0., st_jets = 0., st_lep = 0.;
  vector<Jet>* jets = event.jets;
  vector<Electron>* electrons = event.electrons;
  vector<Muon>* muons = event.muons;
  for(unsigned int i=0; i<jets->size(); i++){
           st_jets += jets->at(i).pt();
  }
  for(unsigned int i=0; i<electrons->size(); i++){
           st_lep += electrons->at(i).pt();
  }
  for(unsigned int i=0; i<muons->size(); i++){
           st_lep += muons->at(i).pt();
  }
  st = st_jets + st_lep + event.met->pt();

  event.set(h_ST,st);
  event.set(h_STjets,st_jets);
  event.set(h_STlep,st_lep);

  // Ak4 jets
  event.set(h_N_jets,jets->size());

  for(unsigned int i=0; i<jets->size(); i++){
    event.set(h_pt_jet,jets->at(i).pt());
    event.set(h_eta_jet,jets->at(i).eta());
    event.set(h_phi_jet,jets->at(i).phi());
    event.set(h_m_jet,jets->at(i).v4().M());
    event.set(h_csv_jet,jets->at(i).btag_combinedSecondaryVertex());


    if(i==0){
      event.set(h_pt_jet1,jets->at(i).pt());
      event.set(h_eta_jet1,jets->at(i).eta());
      event.set(h_phi_jet1,jets->at(i).phi());
      event.set(h_m_jet1,jets->at(i).v4().M());
      event.set(h_csv_jet1,jets->at(i).btag_combinedSecondaryVertex());
    }
    else if(i==1){
      event.set(h_pt_jet2,jets->at(i).pt());
      event.set(h_eta_jet2,jets->at(i).eta());
      event.set(h_phi_jet2,jets->at(i).phi());
      event.set(h_m_jet2,jets->at(i).v4().M());
      event.set(h_csv_jet2,jets->at(i).btag_combinedSecondaryVertex());
    }
    else if(i==2){
      event.set(h_pt_jet3,jets->at(i).pt());
      event.set(h_eta_jet3,jets->at(i).eta());
      event.set(h_phi_jet3,jets->at(i).phi());
      event.set(h_m_jet3,jets->at(i).v4().M());
      event.set(h_csv_jet3,jets->at(i).btag_combinedSecondaryVertex());
    }
  }

  // Sphericity tensor
  double s11 = -1., s12 = -1., s13 = -1., s22 = -1., s23 = -1., s33 = -1., mag = -1.;
  for(const Jet jet : *event.jets){
    mag += (jet.v4().Px()*jet.v4().Px()+jet.v4().Py()*jet.v4().Py()+jet.v4().Pz()*jet.v4().Pz());
    s11 += jet.v4().Px()*jet.v4().Px();
    s12 += jet.v4().Px()*jet.v4().Py();
    s13 += jet.v4().Px()*jet.v4().Pz();
    s22 += jet.v4().Py()*jet.v4().Py();
    s23 += jet.v4().Py()*jet.v4().Pz();
    s33 += jet.v4().Pz()*jet.v4().Pz();
  }

  s11 = s11 / mag;
  s12 = s12 / mag;
  s13 = s13 / mag;
  s22 = s22 / mag;
  s23 = s23 / mag;
  s33 = s33 / mag;

  event.set(h_S11,s11);
  event.set(h_S12,s12);
  event.set(h_S13,s13);
  event.set(h_S22,s22);
  event.set(h_S23,s23);
  event.set(h_S33,s33);


  // Muons
  int Nmuons = muons->size();
  event.set(h_N_mu,Nmuons);

  for(int i=0; i<Nmuons; i++){

    event.set(h_pt_mu,muons->at(i).pt());
    event.set(h_eta_mu,muons->at(i).eta());
    event.set(h_phi_mu,muons->at(i).phi());
    event.set(h_reliso_mu,muons->at(i).relIso());
    if(muons->at(i).has_tag(Muon::twodcut_dRmin) && muons->at(i).has_tag(Muon::twodcut_pTrel)){
      event.set(h_dRmin_mu_jet,muons->at(i).get_tag(Muon::twodcut_dRmin));
      event.set(h_ptrel_mu_jet,muons->at(i).get_tag(Muon::twodcut_pTrel));
    }
      for(unsigned int j=0; j<jets->size(); j++){
       if(j==0){
       event.set(h_dphi_mu_jet1,deltaPhi(muons->at(i),jets->at(j)));
       }
      }
      for(unsigned int k=0; k<event.toppuppijets->size(); k++){
       if(k==0){
       event.set(h_dphi_mu_Ak8Puppijet1,deltaPhi(muons->at(i),event.toppuppijets->at(k)));
       }
      }
  }


  // Electrons
  int Nelectrons = electrons->size();
  event.set(h_N_ele,Nelectrons);

  for(int i=0; i<Nelectrons; i++){

    event.set(h_pt_ele,electrons->at(i).pt());
    event.set(h_eta_ele,electrons->at(i).eta());
    event.set(h_phi_ele,electrons->at(i).phi());
    event.set(h_reliso_ele,electrons->at(i).relIso());
    if(electrons->at(i).has_tag(Electron::twodcut_dRmin) && electrons->at(i).has_tag(Electron::twodcut_pTrel)){
      event.set(h_dRmin_ele_jet,electrons->at(i).get_tag(Electron::twodcut_dRmin));
      event.set(h_ptrel_ele_jet,electrons->at(i).get_tag(Electron::twodcut_pTrel));
    }
      for(unsigned int j=0; j<jets->size(); j++){
       if(j==0){
       event.set(h_dphi_ele_jet1,deltaPhi(electrons->at(i),jets->at(j)));
       }
      }
      for(unsigned int k=0; k<event.toppuppijets->size(); k++){
       if(k==0){
       event.set(h_dphi_ele_Ak8Puppijet1,deltaPhi(electrons->at(i),event.toppuppijets->at(k)));
       }
      }
  }


  // Ak8 Puppi jets
  vector<TopJet>* AK8Puppijets = event.toppuppijets;
  unsigned int NAK8Puppijets = 0;
  for(unsigned int i=0; i<AK8Puppijets->size(); i++){
//    if(AK8Puppijets->at(i).numberOfDaughters()<2) continue;
    NAK8Puppijets++;
  
    event.set(h_pt_Ak8Puppijets,AK8Puppijets->at(i).pt());
    event.set(h_eta_Ak8Puppijets,AK8Puppijets->at(i).eta());
    event.set(h_phi_Ak8Puppijets,AK8Puppijets->at(i).phi());
    event.set(h_mSD_Ak8Puppijets,AK8Puppijets->at(i).softdropmass());

    double dRmin_muon = 99999;
    for(unsigned int j=0; j<event.muons->size(); j++){
      double dR_mu = deltaR(AK8Puppijets->at(i), event.muons->at(j));
      if(dR_mu < dRmin_muon) dRmin_muon = dR_mu;
      event.set(h_dR_mu_Ak8Puppijet,dR_mu);
    }

    double dRmin_ele = 99999;
    for(unsigned int j=0; j<event.electrons->size(); j++){
      double dR_ele = deltaR(AK8Puppijets->at(i), event.electrons->at(j));
      if(dR_ele < dRmin_ele) dRmin_ele = dR_ele;
      event.set(h_dR_ele_Ak8Puppijet,dR_ele);
    }

    double dRmin_jet = 99999;
    for(unsigned int j=0; j<event.jets->size(); j++){
      double dR_jet = deltaR(AK8Puppijets->at(i), event.jets->at(j));
      if(dR_jet < dRmin_jet) dRmin_jet = dR_jet;
      event.set(h_dR_jet_Ak8Puppijet,dR_jet);
    }


    if(i==0){
      event.set(h_pt_Ak8Puppijet1,AK8Puppijets->at(i).pt());
      event.set(h_eta_Ak8Puppijet1,AK8Puppijets->at(i).eta());
      event.set(h_phi_Ak8Puppijet1,AK8Puppijets->at(i).phi());
      event.set(h_mSD_Ak8Puppijet1,AK8Puppijets->at(i).softdropmass());
    }

    if(i==1){
      event.set(h_pt_Ak8Puppijet2,AK8Puppijets->at(i).pt());
      event.set(h_eta_Ak8Puppijet2,AK8Puppijets->at(i).eta());
      event.set(h_phi_Ak8Puppijet2,AK8Puppijets->at(i).phi());
      event.set(h_mSD_Ak8Puppijet2,AK8Puppijets->at(i).softdropmass());
    }

    if(i==2){
      event.set(h_pt_Ak8Puppijet3,AK8Puppijets->at(i).pt());
      event.set(h_eta_Ak8Puppijet3,AK8Puppijets->at(i).eta());
      event.set(h_phi_Ak8Puppijet3,AK8Puppijets->at(i).phi());
      event.set(h_mSD_Ak8Puppijet3,AK8Puppijets->at(i).softdropmass());
    }

    event.set(h_N_Ak8Puppijets,NAK8Puppijets);
  }


  return true;

}

UHH2_REGISTER_ANALYSIS_MODULE(ZprimePreselectionModule_commonmodules)
