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
#include <UHH2/common/include/MCWeight.h>
#include <UHH2/common/include/MuonHists.h>
#include <UHH2/common/include/ElectronHists.h>
#include <UHH2/common/include/JetHists.h>
#include <UHH2/common/include/EventHists.h>

#include <UHH2/ZprimeSemiLeptonic/include/ModuleBASE.h>
#include <UHH2/ZprimeSemiLeptonic/include/ZprimeSemiLeptonicSelections.h>
#include <UHH2/ZprimeSemiLeptonic/include/ZprimeSemiLeptonicModules.h>
#include <UHH2/ZprimeSemiLeptonic/include/TTbarLJHists.h>
#include <UHH2/ZprimeSemiLeptonic/include/ZprimeSemiLeptonicHists.h>
#include <UHH2/ZprimeSemiLeptonic/include/ZprimeSemiLeptonicGeneratorHists.h>
#include <UHH2/ZprimeSemiLeptonic/include/ZprimeCandidate.h>

//#include <UHH2/common/include/TTbarGen.h>
#include <UHH2/common/include/TTbarReconstruction.h>
#include <UHH2/common/include/ReconstructionHypothesisDiscriminators.h>

using namespace std;
using namespace uhh2;

/*
██████  ███████ ███████ ██ ███    ██ ██ ████████ ██  ██████  ███    ██
██   ██ ██      ██      ██ ████   ██ ██    ██    ██ ██    ██ ████   ██
██   ██ █████   █████   ██ ██ ██  ██ ██    ██    ██ ██    ██ ██ ██  ██
██   ██ ██      ██      ██ ██  ██ ██ ██    ██    ██ ██    ██ ██  ██ ██
██████  ███████ ██      ██ ██   ████ ██    ██    ██  ██████  ██   ████
*/

class ZprimeAnalysisModule_forQCDDNN : public ModuleBASE {

public:
  explicit ZprimeAnalysisModule_forQCDDNN(uhh2::Context&);
  virtual bool process(uhh2::Event&) override;
  void book_histograms(uhh2::Context&, vector<string>);
  void fill_histograms(uhh2::Event&, string);

protected:
  bool debug;
  
  // Cleaners (to make sure the pre-selection did everything right)
  std::unique_ptr<MuonCleaner> muon_cleaner;
  std::unique_ptr<ElectronCleaner> electron_cleaner;

  // Scale Factors -- Systematics
  unique_ptr<MCMuonScaleFactor> MuonID_module, MuonTrigger_module;
  unique_ptr<MCElecScaleFactor> ElectronID_module;

  // AnalysisModules
  unique_ptr<AnalysisModule> LumiWeight_module, PUWeight_module, BTagWeight_module, printer_genparticles;

  unique_ptr<AK8PuppiTopTagger> TopTaggerPuppi;


  // Selections
  unique_ptr<Selection> Trigger1_selection, Trigger2_selection, NMuon1_selection, NMuon2_selection, NElectron_selection, TwoDCut_selection, Jet1_selection, Jet2_selection, Met_selection;;

  std::unique_ptr<uhh2::Selection> InvTriangular_selection;
  std::unique_ptr<uhh2::Selection> met_sel;
  std::unique_ptr<uhh2::Selection> htlep_sel;
  std::unique_ptr<Selection> sel_1btag, sel_2btag;
 // 2018 HE veto
  std::unique_ptr<Selection> HEMelectronSelection;
  std::unique_ptr<Selection> HEMjetSelection;
  std::unique_ptr<Selection> HEMtopjetSelection;



  //Handles
  Event::Handle<bool> h_is_zprime_reconstructed_chi2, h_is_zprime_reconstructed_correctmatch;  
  Event::Handle<float> h_weight;
  Event::Handle<float> h_MET;  
  
  Event::Handle<float> h_ST;
  Event::Handle<float> h_STjets;
  Event::Handle<float> h_STlep;
  Event::Handle<float> h_NPV;
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
  Event::Handle<float> h_mass_jet;
  Event::Handle<float> h_mass_jet1;
  Event::Handle<float> h_mass_jet2;
  Event::Handle<float> h_mass_jet3;
  Event::Handle<float> h_S11;
  Event::Handle<float> h_S12;
  Event::Handle<float> h_S13;
  Event::Handle<float> h_S22;
  Event::Handle<float> h_S23;
  Event::Handle<float> h_S33;
  Event::Handle<float> h_pt_mu;
  Event::Handle<float> h_eta_mu;
  Event::Handle<float> h_phi_mu;
  Event::Handle<float> h_reliso_mu;
  Event::Handle<float> h_pt_ele;
  Event::Handle<float> h_eta_ele;
  Event::Handle<float> h_phi_ele;
  Event::Handle<float> h_reliso_ele;
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
  Event::Handle<float> h_dR_mu_jet;
  Event::Handle<float> h_dR_mu_Ak8Puppijet;
  Event::Handle<float> h_dR_ele_jet;
  Event::Handle<float> h_dR_ele_Ak8Puppijet;
  Event::Handle<float> h_dR_jet_Ak8Puppijet;
  Event::Handle<float> h_ptrel_mu_jet;
  Event::Handle<float> h_ptrel_ele_jet;
  Event::Handle<float> h_dphi_mu_jet1;
  Event::Handle<float> h_dphi_ele_jet1;
  Event::Handle<float> h_dphi_mu_Ak8Puppijet1;
  Event::Handle<float> h_dphi_ele_Ak8Puppijet1;
  Event::Handle<float> h_deepjetbscore_jet;
  Event::Handle<float> h_deepjetbscore_jet1;
  Event::Handle<float> h_deepjetbscore_jet2;
  Event::Handle<float> h_deepjetbscore_jet3;
  Event::Handle<float> h_dphi_mu_MET;
  Event::Handle<float> h_dphi_jet1_MET;
  Event::Handle<float> h_dphi_ele_MET;


  // Configuration
  bool isMC, ispuppi, islooserselection, isdataQCD;
  string Sys_MuonTrigger, Sys_PU, Sys_btag;
  string Sys_MuonID, Sys_ElectronID;
  TString sample;
  int runnr_oldtriggers = 299368;

  bool is2016v2, is2016v3, is2017, is2017v2, is2018;
  bool isMuon, isElectron;
};

//void ZprimeAnalysisModule_forQCDDNN::book_histograms(uhh2::Context& ctx, vector<string> tags){
  //for(const auto & tag : tags){
   // string mytag = tag + "_Skimming";
    //book_HFolder(mytag, new TTbarLJHistsSkimming(ctx,mytag));
   // mytag = tag+"_General";
   // book_HFolder(mytag, new ZprimeSemiLeptonicHists(ctx,mytag));
 // }
//}

//void ZprimeAnalysisModule_forQCDDNN::fill_histograms(uhh2::Event& event, string tag){
  //string mytag = tag + "_Skimming";
  //HFolder(mytag)->fill(event);
  //mytag = tag+"_General";
//  HFolder(mytag)->fill(event);
//}

/*
█  ██████  ██████  ███    ██ ███████ ████████ ██████  ██    ██  ██████ ████████  ██████  ██████
█ ██      ██    ██ ████   ██ ██         ██    ██   ██ ██    ██ ██         ██    ██    ██ ██   ██
█ ██      ██    ██ ██ ██  ██ ███████    ██    ██████  ██    ██ ██         ██    ██    ██ ██████
█ ██      ██    ██ ██  ██ ██      ██    ██    ██   ██ ██    ██ ██         ██    ██    ██ ██   ██
█  ██████  ██████  ██   ████ ███████    ██    ██   ██  ██████   ██████    ██     ██████  ██   ██
*/

ZprimeAnalysisModule_forQCDDNN::ZprimeAnalysisModule_forQCDDNN(uhh2::Context& ctx){
  debug = false;
  for(auto & kv : ctx.get_all()){
    cout << " " << kv.first << " = " << kv.second << endl;
  }
  if (debug) cout <<"in analysis module"<<endl;
  // Important selection values
  isMuon = false; isElectron = false;
  if(ctx.get("channel") == "muon") isMuon = true; 
  if(ctx.get("channel") == "electron") isElectron = true;
  islooserselection = (ctx.get("is_looser_selection") == "true");
  isdataQCD = (ctx.get("is_data_QCD") == "true");
  if (debug) cout <<"after booleans"<<endl;
  double muon_pt(55.);
  double elec_pt(80.);
  double jet1_pt(100.);
  double jet2_pt(50.);
  //  double stlep_plus_met(150.);
  //double chi2_max(30.);
  //double mtt_blind(3000.);
  int nmuon_min1, nmuon_max1;
  int nmuon_min2, nmuon_max2;
  int nele_min, nele_max;
  string trigger1,trigger2;// trigger3;
  double MET_cut; double HT_lep_cut;

  if(isMuon){
	trigger1 = "HLT_Mu50_v*";
    	if(is2016v2 || is2016v3)
            trigger2 = "HLT_Mu50_v*"; //TkMu path does not exist in 2017/2018 and RunB 201
    	else
            trigger2 = "HLT_Mu50_v*"; //TkMu path does not exist in 2017/2018
  
    	nmuon_min1 = 1, nmuon_max1 = -1;
    	nmuon_min2 = 1, nmuon_max2 = 1;
    	nele_min = 0; nele_max = 0;
    	MET_cut = 50;
    	HT_lep_cut = 150;

  }
  
  if(isElectron){
    nmuon_min1 = 0; nmuon_max1 = 0;
    nmuon_min2 = 0; nmuon_max2 = 0;
    nele_min = 1; nele_max = 1;
    trigger1 = "HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_v*";
    trigger2 = "HLT_Ele115_CaloIdVT_GsfTrkIdT_v*";
    MET_cut = 50;
    HT_lep_cut = 0;
  }

//No 2D cut for NN 
  double TwoD_dr = 0.4, TwoD_ptrel = 25.;
  if(islooserselection){
    jet1_pt = 100.;
    TwoD_dr = 0.0;
    TwoD_ptrel = 0.;
    
    //stlep_plus_met = 100.;
  }
  
  const MuonId muonID(PtEtaCut(muon_pt, 2.4));
      
  const ElectronId electronID(PtEtaSCCut(elec_pt, 2.5));

  // Configuration
  isMC = (ctx.get("dataset_type") == "MC");
  ispuppi = (ctx.get("is_puppi") == "true");
  TString mode = "chs";
  if(ispuppi) mode = "puppi";
  string tmp = ctx.get("dataset_version");
  sample = tmp;
  
  is2016v2 = (ctx.get("dataset_version").find("2016v2") != std::string::npos);
  is2016v3 = (ctx.get("dataset_version").find("2016v3") != std::string::npos);
  is2017 = (ctx.get("dataset_version").find("2017") != std::string::npos);
  is2017v2 = (ctx.get("dataset_version").find("2017v2") != std::string::npos);
  is2018 = (ctx.get("dataset_version").find("2018") != std::string::npos);
  
  if (isMuon){
  	Sys_MuonID = ctx.get("Sys_MuonID");
  	Sys_MuonTrigger = ctx.get("Sys_MuonTrigger");
  }
  if (isElectron){
	Sys_ElectronID = ctx.get("Sys_ElectronID");
  }
  Sys_PU = ctx.get("Sys_PU");
  Sys_btag = ctx.get("Sys_BTagSF");


  BTag::algo btag_algo = BTag::DEEPJET;
  BTag::wp btag_wp_tight = BTag::WP_TIGHT;
  JetId id_btag = BTag(btag_algo, btag_wp_tight);
  

  // Modules
  printer_genparticles.reset(new GenParticlesPrinter(ctx));
  muon_cleaner.reset(new MuonCleaner(muonID));
  electron_cleaner.reset(new ElectronCleaner(electronID));
  
  LumiWeight_module.reset(new MCLumiWeight(ctx));
  PUWeight_module.reset(new MCPileupReweight(ctx, Sys_PU));
  BTagWeight_module.reset(new MCBTagDiscriminantReweighting(ctx, btag_algo, "jets", Sys_btag));

  if(is2018 and isMuon){
     MuonID_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/titasroy/UHH2_2020/CMSSW_10_2_10/src/UHH2/common/data/2018/Muon_ID_SF_RunABCD.root", "NUM_HighPtID_DEN_TrackerMuons_pair_newTuneP_probe_pt_abseta", 0., "HighPtID", true, Sys_MuonID));
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/titasroy/UHH2_2020/CMSSW_10_2_10/src/UHH2/common/data/2018/Muon_Trigger_Eff_SF_AfterMuonHLTUpdate.root", "Mu50_OR_OldMu100_OR_TkMu100_PtEtaBins/pt_abseta_ratio", 0.5, "Trigger", true, Sys_MuonTrigger));
   }
  if(is2018 and isElectron){
    ElectronID_module.reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/titasroy/UHH2_2020/CMSSW_10_2_10/src/UHH2/common/data/2018/2018_ElectronTight.root", 0., "TightID", Sys_ElectronID));
  }

  // Selection modules
  Trigger1_selection.reset(new TriggerSelection(trigger1));
  Trigger2_selection.reset(new TriggerSelection(trigger2));
  NMuon1_selection.reset(new NMuonSelection(nmuon_min1, nmuon_max1));
  NMuon2_selection.reset(new NMuonSelection(nmuon_min2, nmuon_max2));
  NElectron_selection.reset(new NElectronSelection(nele_min, nele_max));
  TwoDCut_selection.reset(new TwoDCut(TwoD_dr, TwoD_ptrel));
  InvTriangular_selection.reset(new InvTriangularCuts(0.02, 1.5));
   
  if (debug) cout << "after Muon ID file declared" <<endl;
  //cout << "Jet Id : " << JetId << endl;			
			

  Jet1_selection.reset(new NJetSelection(1, -1, JetId(PtEtaCut(jet1_pt, 2.4))));
  Jet2_selection.reset(new NJetSelection(2, -1, JetId(PtEtaCut(jet2_pt, 2.4))));
  
  met_sel.reset(new METCut  (MET_cut   , uhh2::infinity));
  htlep_sel.reset(new HTlepCut(HT_lep_cut, uhh2::infinity));

  // 2018 veto issue

  HEMelectronSelection.reset(new HEM_electronSelection(ctx));
  HEMtopjetSelection.reset(new HEM_topjetSelection(ctx));
  HEMjetSelection.reset(new HEM_jetSelection(ctx));


  TopTaggerPuppi.reset(new AK8PuppiTopTagger(ctx));
  h_is_zprime_reconstructed_chi2 = ctx.get_handle<bool>("is_zprime_reconstructed_chi2");
  h_is_zprime_reconstructed_correctmatch = ctx.get_handle<bool>("is_zprime_reconstructed_correctmatch");
  if (debug) cout << "getting till declare_event"<<endl;
  h_MET = ctx.declare_event_output<float> ("met_pt");
  if (debug) cout << "after met"<<endl;
  h_weight = ctx.declare_event_output<float> ("weight");
  if (debug) cout << "weight"<<endl;
  h_ST = ctx.declare_event_output<float> ("st");
  h_STjets = ctx.declare_event_output<float> ("st_jets");
  h_STlep = ctx.declare_event_output<float> ("st_lep");
  h_NPV = ctx.declare_event_output<float> ("npv_pt");
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
  h_mass_jet = ctx.declare_event_output<float> ("mass_jet");
  h_mass_jet1 = ctx.declare_event_output<float> ("mass_jet1");
  h_mass_jet2 = ctx.declare_event_output<float> ("mass_jet2");
  h_mass_jet3 = ctx.declare_event_output<float> ("mass_jet3");
  h_S11 = ctx.declare_event_output<float> ("s11");
  h_S12 = ctx.declare_event_output<float> ("s12");
  h_S13 = ctx.declare_event_output<float> ("s13");
  h_S22 = ctx.declare_event_output<float> ("s22");
  h_S23 = ctx.declare_event_output<float> ("s23");
  h_S33 = ctx.declare_event_output<float> ("s33");
  h_pt_mu = ctx.declare_event_output<float> ("pt_mu");
  h_eta_mu = ctx.declare_event_output<float> ("eta_mu");
  h_phi_mu = ctx.declare_event_output<float> ("phi_mu");
  h_reliso_mu = ctx.declare_event_output<float> ("reliso_mu");
  h_pt_ele = ctx.declare_event_output<float> ("pt_ele");
  h_eta_ele = ctx.declare_event_output<float> ("eta_ele");
  h_phi_ele = ctx.declare_event_output<float> ("phi_ele");
  h_reliso_ele = ctx.declare_event_output<float> ("reliso_ele");
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
  h_dR_mu_jet = ctx.declare_event_output<float> ("dR_mu_jet");
  h_dR_mu_Ak8Puppijet = ctx.declare_event_output<float> ("dR_mu_Ak8Puppijet");
  h_dR_ele_jet = ctx.declare_event_output<float> ("dR_ele_jet");
  h_dR_ele_Ak8Puppijet = ctx.declare_event_output<float> ("dR_ele_Ak8Puppijet");
  h_dR_jet_Ak8Puppijet = ctx.declare_event_output<float> ("dR_jet_Ak8Puppijet");
  h_ptrel_mu_jet = ctx.declare_event_output<float> ("ptrel_mu_jet");
  h_ptrel_ele_jet = ctx.declare_event_output<float> ("ptrel_ele_jet");
  h_dphi_mu_jet1 = ctx.declare_event_output<float> ("dphi_mu_jet1");
  h_dphi_ele_jet1 = ctx.declare_event_output<float> ("dphi_ele_jet1");
  h_dphi_mu_Ak8Puppijet1 = ctx.declare_event_output<float> ("dphi_mu_Ak8Puppijet1");
  h_dphi_ele_Ak8Puppijet1 = ctx.declare_event_output<float> ("dphi_ele_Ak8Puppijet1");
  h_deepjetbscore_jet = ctx.declare_event_output<float> ("deepjetbscore_jet");
  h_deepjetbscore_jet1 = ctx.declare_event_output<float> ("deepjetbscore_jet1");
  h_deepjetbscore_jet2 = ctx.declare_event_output<float> ("deepjetbscore_jet2");
  h_deepjetbscore_jet3 = ctx.declare_event_output<float> ("deepjetbscore_jet3");
  h_dphi_mu_MET = ctx.declare_event_output<float> ("dphi_mu_MET");
  h_dphi_ele_MET = ctx.declare_event_output<float> ("dphi_ele_MET");
  h_dphi_jet1_MET = ctx.declare_event_output<float> ("dphi_jet1_MET");


  if (debug) cout << "done declaring histograms"<<endl;

//  DeepJetBTag::wp btag_wp = DeepJetBTag::WP_TIGHT; // b-tag workingpoint
 // JetId id_btag = DeepJetBTag(btag_wp);

  
  sel_1btag.reset(new NJetSelection(1, 1, id_btag));
//  cout << "id_btag: "<< id_btag << endl;
  sel_2btag.reset(new NJetSelection(2, -1, id_btag));


  //TopJetBtagSubjet_selection.reset(new ZprimeBTagFatSubJetSelection(ctx));



}


bool ZprimeAnalysisModule_forQCDDNN::process(uhh2::Event& event){


  
  if (debug) cout << " Event number is "<<event.run<<", "<< event.event<<endl;
  if (debug) cout << " is this a Muon channel : " << isMuon <<endl;
  if (debug) cout << " is this an Eelctron channel : " << isElectron <<endl;
  
  
  event.set(h_is_zprime_reconstructed_chi2, false);
  event.set(h_is_zprime_reconstructed_correctmatch,false);
  event.set(h_MET,0);
  event.set(h_weight,0);
  event.set(h_ST,0);
  event.set(h_STjets,0);
  event.set(h_STlep,0);
  event.set(h_NPV,0);
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
  event.set(h_mass_jet,0);
  event.set(h_mass_jet1,0);
  event.set(h_mass_jet2,0);
  event.set(h_mass_jet3,0);
  event.set(h_S11,0);
  event.set(h_S12,0);
  event.set(h_S13,0);
  event.set(h_S22,0);
  event.set(h_S23,0);
  event.set(h_S33,0);
  event.set(h_pt_mu,0);
  event.set(h_eta_mu,0);
  event.set(h_phi_mu,0);
  event.set(h_reliso_mu,0);
  event.set(h_pt_ele,0);
  event.set(h_eta_ele,0);
  event.set(h_phi_ele,0);
  event.set(h_reliso_ele,0);
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
  event.set(h_dR_mu_jet,0);
  event.set(h_dR_mu_Ak8Puppijet,0);
  event.set(h_dR_ele_jet,0);
  event.set(h_dR_ele_Ak8Puppijet,0);
  event.set(h_dR_jet_Ak8Puppijet,0);
  event.set(h_ptrel_mu_jet,0);
  event.set(h_ptrel_ele_jet,0);
  event.set(h_dphi_mu_jet1,0);
  event.set(h_dphi_ele_jet1,0);
  event.set(h_dphi_mu_Ak8Puppijet1,0);
  event.set(h_dphi_ele_Ak8Puppijet1,0);
  event.set(h_deepjetbscore_jet,0);
  event.set(h_deepjetbscore_jet1,0);
  event.set(h_deepjetbscore_jet2,0);
  event.set(h_deepjetbscore_jet3,0);
  event.set(h_dphi_mu_MET,0);
  event.set(h_dphi_ele_MET,0);
  event.set(h_dphi_jet1_MET,0);

  if (debug) cout << "event set" <<endl;

  // TODO Apply things that should've been done in the pre-selection already... Fix pre-selection and then remove these steps

  if(isMuon) muon_cleaner->process(event);
  if(isElectron) electron_cleaner->process(event);
  if (debug)  cout<<" after cleaning "<<endl;
 
  if (debug)  cout<<" about to do trigger"<<endl;
  if(!(Trigger1_selection->passes(event)|| Trigger2_selection->passes(event))) return false;

 
  LumiWeight_module->process(event);
  PUWeight_module->process(event);
  BTagWeight_module->process(event);


  if (debug)  cout<<" after PU and BTag weights"<<endl;
 

 
 
  if(isMuon){
    if(debug)  cout<<"about to check MuonID "<<endl;
    MuonID_module->process(event);
    if(debug)  cout<<"MuonID ok"<<endl;
  }
  
  if (isElectron){
	if(debug)  cout<<"about to check ElectronID "<<endl;
        ElectronID_module->process(event);
    	if(debug)  cout<<"Electron ID ok"<<endl;
  }

  if(debug)  cout<<"done with electron ID ok"<<endl; 
  

  TopTaggerPuppi->process(event);
  
  if(isMuon){
    if(!NMuon1_selection->passes(event)) return false;
    if(!NMuon2_selection->passes(event)) return false;
  
  }
  

  if (debug)  cout<<"done with muon selection" << endl;
    
  if(isElectron){
        if(!NElectron_selection->passes(event)) return false;
       
        }     
  if (debug)  cout<<"done with electron selection" << endl;

    
  if(isMuon && is2018 && !isMC && event.run>319077){
       if (HEMjetSelection->passes(event)) return false;
       if (HEMtopjetSelection->passes(event)) return false;
  }


  if (debug)  cout<<"done with 2018 data muons"<<endl;
  


  if(isElectron && is2018 && !isMC && event.run>319077){
       if (HEMjetSelection->passes(event)) return false;
       if (HEMelectronSelection->passes(event)) return false;
       if (HEMtopjetSelection->passes(event)) return false;
  }
  

  if (debug)  cout<<"done with 2018 data electrons"<<endl;
 
   
  if((event.muons->size()+event.electrons->size()) != 1) return false; //veto events without leptons or with too many 
  if (debug) cout<<"N leptons ok: Nelectrons="<<event.electrons->size()<<" Nmuons="<<event.muons->size()<<endl;


  
  if (debug) cout<<"done with leptons, about to start with jets"<<endl;

	
			
 //AK4 jet selection 
  
  if(!Jet1_selection->passes(event)) return false;

 // cout<< "Jet 1 selection done" << endl; 

  if(!Jet2_selection->passes(event)) return false;
 
  //cout<< "Jet 2 selection done " << endl;

  // MET selection
  if(!met_sel->passes(event)) return false;
 
  if(isMuon){
    if(!htlep_sel->passes(event)) return false;
    if (debug) cout<<"passes HTlep"<<endl;
  }

  if (debug) cout<< "MET selection done, about to do B-tagging selection" << endl;
  
  //BTagging
  
//  if(!sel_2btag->passes(event)) return false; //fill_histograms(event, "Btags2");
//  cout<< "done with 2 btag" << endl;
 // if(!sel_1btag->passes(event))  return false; //fill_histograms(event, "Btags1");
  
 //  cout<< "done with 1 btag" << endl;


  if (debug) cout << " about to do reweighting for 2018 veto" <<endl;  

  if(isElectron && is2018 && isMC){
       if (debug)  cout<<"check electrons MC"<<endl;
       if (HEMjetSelection->passes(event) || HEMelectronSelection->passes(event)|| HEMtopjetSelection->passes(event)){
       if (debug) cout <<"event weight is : "<< event.weight <<endl;
              event.weight=event.weight*0.35;
    }
  }
  
  if (debug)  cout<<"done with 2018 MC electrons"<<endl;
  
  if(isMuon && is2018 && isMC){
       if (debug)  cout<<"check muons MC"<<endl;
       if (HEMjetSelection->passes(event) || HEMtopjetSelection->passes(event)){
              event.weight=event.weight*0.35;
   }
  }

  //Inverted Triangle Cuts

  if(isElectron && isdataQCD){
        
       if (debug) cout << "doing data driven QCD inverted cut" << endl;
       if (!InvTriangular_selection->passes(event)) return false;
       if (debug) cout << "done with driven QCD inverted cut" << endl;   

    }


  if (debug) cout << " Now will fill histograms defined for AnalysisTree" <<endl;  

  event.set(h_weight,event.weight);
  event.set(h_NPV,event.pvs->size());
  event.set(h_MET,event.met->pt());
  
  if(debug) cout<<" done with MET, weight, NPV"<<endl; 

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
  
  if(debug) cout<<" done with ST"<<endl;
  
  // Ak4 jets
   
  //event.set(h_N_jets,jets->size());

  for(unsigned int i=0; i<jets->size(); i++){
    event.set(h_pt_jet,jets->at(i).pt());
    event.set(h_eta_jet,jets->at(i).eta());
    event.set(h_phi_jet,jets->at(i).phi());
    event.set(h_mass_jet,jets->at(i).v4().M());
    event.set(h_deepjetbscore_jet,jets->at(i).btag_DeepJet());

    double dRmin_muon_jet = 99999;
    for(unsigned int j=0; j<event.muons->size(); j++){
      double dR_mu_jet = deltaR(jets->at(i), event.muons->at(j));
      if(dR_mu_jet < dRmin_muon_jet) dRmin_muon_jet = dR_mu_jet;
      event.set(h_dR_mu_jet,dR_mu_jet);
    }

    double dRmin_ele_jet = 99999;
    for(unsigned int j=0; j<event.electrons->size(); j++){
      double dR_ele_jet = deltaR(jets->at(i), event.electrons->at(j));
      if(dR_ele_jet < dRmin_ele_jet) dRmin_ele_jet = dR_ele_jet;
      event.set(h_dR_ele_jet,dR_ele_jet);
    }

    if(i==0){
      event.set(h_pt_jet1,jets->at(i).pt());
      event.set(h_eta_jet1,jets->at(i).eta());
      event.set(h_phi_jet1,jets->at(i).phi());
      event.set(h_mass_jet1,jets->at(i).v4().M());
      event.set(h_deepjetbscore_jet1,jets->at(i).btag_DeepJet());
      event.set(h_dphi_jet1_MET,deltaPhiMET(jets->at(i),event.met));
    }
    else if(i==1){
      event.set(h_pt_jet2,jets->at(i).pt());
      event.set(h_eta_jet2,jets->at(i).eta());
      event.set(h_phi_jet2,jets->at(i).phi());
      event.set(h_mass_jet2,jets->at(i).v4().M());
      event.set(h_deepjetbscore_jet2,jets->at(i).btag_DeepJet());
    }
    else if(i==2){
      event.set(h_pt_jet3,jets->at(i).pt());
      event.set(h_eta_jet3,jets->at(i).eta());
      event.set(h_phi_jet3,jets->at(i).phi());
      event.set(h_mass_jet3,jets->at(i).v4().M());
      //event.set(h_csv_jet3,jets->at(i).btag_combinedSecondaryVertex());
      event.set(h_deepjetbscore_jet3,jets->at(i).btag_DeepJet());
    }
  }
  if(debug) cout<<" doing Sphericity tensors"<<endl;
  
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
 
  if(debug) cout<<" done with Sphericity tensors"<<endl;
  

  // Muons
  int Nmuons = muons->size();
 
  // event.set(h_N_mu,Nmuons);

  for(int i=0; i<Nmuons; i++){

    event.set(h_pt_mu,muons->at(i).pt());
    event.set(h_eta_mu,muons->at(i).eta());
    event.set(h_phi_mu,muons->at(i).phi());
    event.set(h_reliso_mu,muons->at(i).relIso());
    if(muons->at(i).has_tag(Muon::twodcut_dRmin) && muons->at(i).has_tag(Muon::twodcut_pTrel)){
      //event.set(h_dRmin_mu_jet,muons->at(i).get_tag(Muon::twodcut_dRmin));
        event.set(h_ptrel_mu_jet,muons->at(i).get_tag(Muon::twodcut_pTrel));
      }
    for(unsigned int j=0; j<jets->size(); j++){
       if(j==0){
         event.set(h_dphi_mu_jet1,deltaPhi(muons->at(i),jets->at(j)));
         event.set(h_dphi_mu_MET,deltaPhiMET(muons->at(i),event.met));
        }
    }
    for(unsigned int k=0; k<event.toppuppijets->size(); k++){
       if(k==0){
           event.set(h_dphi_mu_Ak8Puppijet1,deltaPhi(muons->at(i),event.toppuppijets->at(k)));
       }
    }

  }

 if(debug) cout<<" done with muons"<<endl;
 
 // Electrons
 int Nelectrons = electrons->size();
  //event.set(h_N_ele,Nelectrons);

  for(int i=0; i<Nelectrons; i++){

    event.set(h_pt_ele,electrons->at(i).pt());
    event.set(h_eta_ele,electrons->at(i).eta());
    event.set(h_phi_ele,electrons->at(i).phi());
    event.set(h_reliso_ele,electrons->at(i).relIso());
    if(electrons->at(i).has_tag(Electron::twodcut_dRmin) && electrons->at(i).has_tag(Electron::twodcut_pTrel)){
     // event.set(h_dRmin_ele_jet,electrons->at(i).get_tag(Electron::twodcut_dRmin));
        event.set(h_ptrel_ele_jet,electrons->at(i).get_tag(Electron::twodcut_pTrel));
    }
    for(unsigned int j=0; j<jets->size(); j++){
       if(j==0){
          event.set(h_dphi_ele_jet1,deltaPhi(electrons->at(i),jets->at(j)));
          event.set(h_dphi_ele_MET,deltaPhiMET(electrons->at(i),event.met));
       }
    }
    for(unsigned int k=0; k<event.toppuppijets->size(); k++){
       if(k==0){
           event.set(h_dphi_ele_Ak8Puppijet1,deltaPhi(electrons->at(i),event.toppuppijets->at(k)));
       }
    }
  }

  if(debug) cout<<" done with electrons"<<endl;
  
  // Ak8 Puppi jets
  

  vector<TopJet>* AK8Puppijets = event.toppuppijets;
  unsigned int NAK8Puppijets = 0;
  if(debug) cout<<"Number of AK8 jets"<<AK8Puppijets->size()<<endl;
  for(unsigned int i=0; i<AK8Puppijets->size(); i++){
    if(debug) cout<<"In AK8 jet loop"<<endl;
    if(AK8Puppijets->at(i).numberOfDaughters()<2) continue;
    NAK8Puppijets++;

    event.set(h_pt_Ak8Puppijets,AK8Puppijets->at(i).pt());
    event.set(h_eta_Ak8Puppijets,AK8Puppijets->at(i).eta());
    event.set(h_phi_Ak8Puppijets,AK8Puppijets->at(i).phi());
    event.set(h_mSD_Ak8Puppijets,AK8Puppijets->at(i).softdropmass());
    if(debug) cout<<" about to do dR"<<endl;
    if(debug) cout<<"number of muons: "<< event.muons->size()<<endl;
    double dRmin_muon = 99999;
    for(unsigned int j=0; j<event.muons->size(); j++){
      if(debug) cout<<"dR: "<<deltaR(AK8Puppijets->at(i), event.muons->at(j))<<endl;
      double dR_mu = deltaR(AK8Puppijets->at(i), event.muons->at(j));
      if(dR_mu < dRmin_muon) dRmin_muon = dR_mu;
      event.set(h_dR_mu_Ak8Puppijet,dR_mu);
    }
    if(debug) cout<<"number of electrons: "<< event.electrons->size()<<endl;
    double dRmin_ele = 99999;
    for(unsigned int j=0; j<event.electrons->size(); j++){
      
      double dR_ele = deltaR(AK8Puppijets->at(i), event.electrons->at(j));
      if(dR_ele < dRmin_ele) dRmin_ele = dR_ele;
      event.set(h_dR_ele_Ak8Puppijet,dR_ele);
    }
    if(debug) cout<<"number of AK4jets"<< event.jets->size()<<endl;
    double dRmin_jet = 99999;
    for(unsigned int j=0; j<event.jets->size(); j++){
      if(debug) cout<<"dR: "<<deltaR(AK8Puppijets->at(i), event.jets->at(j))<<endl;
      double dR_jet = deltaR(AK8Puppijets->at(i), event.jets->at(j));
      if(dR_jet < dRmin_jet) dRmin_jet = dR_jet;
      event.set(h_dR_jet_Ak8Puppijet,dR_jet);
    }

    if(debug) cout<<" done with dR"<<endl;
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

    //event.set(h_N_Ak8Puppijets,NAK8Puppijets);
  }
  if (debug) cout << "DONE"<< endl;

  return true;
}

UHH2_REGISTER_ANALYSIS_MODULE(ZprimeAnalysisModule_forQCDDNN)
