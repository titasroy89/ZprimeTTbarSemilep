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

#include "UHH2/common/include/NeuralNetworkBase.hpp"


/*
██████  ███████ ███████ ██ ███    ██ ██ ████████ ██  ██████  ███    ██
██   ██ ██      ██      ██ ████   ██ ██    ██    ██ ██    ██ ████   ██
██   ██ █████   █████   ██ ██ ██  ██ ██    ██    ██ ██    ██ ██ ██  ██
██   ██ ██      ██      ██ ██  ██ ██ ██    ██    ██ ██    ██ ██  ██ ██
██████  ███████ ██      ██ ██   ████ ██    ██    ██  ██████  ██   ████
*/


class NeuralNetworkModule: public NeuralNetworkBase {
public:
  explicit NeuralNetworkModule(uhh2::Context&, const std::string & ModelName, const std::string& ConfigName);
  virtual void CreateInputs(uhh2::Event & event) override;
protected:

//cout << "defining NN variables" << endl;


uhh2::Event::Handle<float> h_met_pt;
uhh2::Event::Handle<float> h_st;
uhh2::Event::Handle<float> h_st_jets;
uhh2::Event::Handle<float> h_st_lep;
uhh2::Event::Handle<float> h_npv_pt;
uhh2::Event::Handle<float> h_pt_jet;
uhh2::Event::Handle<float> h_pt_jet1;
uhh2::Event::Handle<float> h_pt_jet2;
uhh2::Event::Handle<float> h_pt_jet3;
uhh2::Event::Handle<float> h_eta_jet;
uhh2::Event::Handle<float> h_eta_jet1;
uhh2::Event::Handle<float> h_eta_jet2;
uhh2::Event::Handle<float> h_eta_jet3;
uhh2::Event::Handle<float> h_phi_jet;
uhh2::Event::Handle<float> h_phi_jet1;
uhh2::Event::Handle<float> h_phi_jet2;
uhh2::Event::Handle<float> h_phi_jet3;
uhh2::Event::Handle<float> h_mass_jet;
uhh2::Event::Handle<float> h_mass_jet1;
uhh2::Event::Handle<float> h_mass_jet2;
uhh2::Event::Handle<float> h_mass_jet3;
uhh2::Event::Handle<float> h_s11;
uhh2::Event::Handle<float> h_s12;
uhh2::Event::Handle<float> h_s13;
uhh2::Event::Handle<float> h_s22;
uhh2::Event::Handle<float> h_s23;
uhh2::Event::Handle<float> h_s33;
uhh2::Event::Handle<float> h_pt_mu;
uhh2::Event::Handle<float> h_eta_mu;
uhh2::Event::Handle<float> h_phi_mu;
uhh2::Event::Handle<float> h_reliso_mu;
uhh2::Event::Handle<float> h_pt_Ak8Puppijets;
uhh2::Event::Handle<float> h_pt_Ak8Puppijet1;
uhh2::Event::Handle<float> h_pt_Ak8Puppijet2;
uhh2::Event::Handle<float> h_pt_Ak8Puppijet3;
uhh2::Event::Handle<float> h_eta_Ak8Puppijets;
uhh2::Event::Handle<float> h_eta_Ak8Puppijet1;
uhh2::Event::Handle<float> h_eta_Ak8Puppijet2;
uhh2::Event::Handle<float> h_eta_Ak8Puppijet3;
uhh2::Event::Handle<float> h_phi_Ak8Puppijets;
uhh2::Event::Handle<float> h_phi_Ak8Puppijet1;
uhh2::Event::Handle<float> h_phi_Ak8Puppijet2;
uhh2::Event::Handle<float> h_phi_Ak8Puppijet3;
uhh2::Event::Handle<float> h_dR_mu_jet;
uhh2::Event::Handle<float> h_dR_mu_Ak8Puppijet;
uhh2::Event::Handle<float> h_dR_jet_Ak8Puppijet;
uhh2::Event::Handle<float> h_ptrel_mu_jet;
uhh2::Event::Handle<float> h_dphi_mu_jet1;
uhh2::Event::Handle<float> h_dphi_mu_Ak8Puppijet1;
uhh2::Event::Handle<float> h_deepjetbscore_jet;
uhh2::Event::Handle<float> h_deepjetbscore_jet1;
uhh2::Event::Handle<float> h_deepjetbscore_jet2;
uhh2::Event::Handle<float> h_deepjetbscore_jet3;
uhh2::Event::Handle<float> h_dphi_mu_MET;
uhh2::Event::Handle<float> h_dphi_jet1_MET;
uhh2::Event::Handle<float> h_weight;
//cout << "end of definitions" << endl;
};

NeuralNetworkModule::NeuralNetworkModule(Context& ctx, const std::string & ModelName, const std::string& ConfigName): NeuralNetworkBase(ctx, ModelName, ConfigName){
  bool debug = false;
  if (debug) cout << "get the NN variables" << endl;

  h_met_pt = ctx.get_handle<float> ("met_pt");
  h_weight = ctx.get_handle<float> ("weight");
  h_st = ctx.get_handle<float> ("st"); 
  h_st_jets = ctx.get_handle<float> ("st_jets");
  h_st_lep = ctx.get_handle<float> ("st_lep");
  h_npv_pt = ctx.get_handle<float> ("npv_pt");
  h_pt_jet = ctx.get_handle<float> ("pt_jet");
  h_pt_jet1 = ctx.get_handle<float> ("pt_jet1");
  h_pt_jet2 = ctx.get_handle<float> ("pt_jet2");
  h_pt_jet3 = ctx.get_handle<float> ("pt_jet3");
  h_eta_jet = ctx.get_handle<float> ("eta_jet");
  h_eta_jet1 = ctx.get_handle<float> ("eta_jet1");
  h_eta_jet2 = ctx.get_handle<float> ("eta_jet2");
  h_eta_jet3 = ctx.get_handle<float> ("eta_jet3");
  h_phi_jet = ctx.get_handle<float> ("phi_jet");
  h_phi_jet1 = ctx.get_handle<float> ("phi_jet1");
  h_phi_jet2 = ctx.get_handle<float> ("phi_jet2");
  h_phi_jet3 = ctx.get_handle<float> ("phi_jet3");
  h_mass_jet = ctx.get_handle<float> ("mass_jet");
  h_mass_jet1 = ctx.get_handle<float> ("mass_jet1");
  h_mass_jet2 = ctx.get_handle<float> ("mass_jet2");
  h_mass_jet3 = ctx.get_handle<float> ("mass_jet3");
  h_s11 = ctx.get_handle<float> ("s11");
  h_s12 = ctx.get_handle<float> ("s12");
  h_s13 = ctx.get_handle<float> ("s13");
  h_s22 = ctx.get_handle<float> ("s22");
  h_s23 = ctx.get_handle<float> ("s23");
  h_s33 = ctx.get_handle<float> ("s33");
  h_pt_mu = ctx.get_handle<float> ("pt_mu");
  h_eta_mu = ctx.get_handle<float> ("eta_mu");
  h_phi_mu = ctx.get_handle<float> ("phi_mu");
  h_reliso_mu = ctx.get_handle<float> ("reliso_mu");
  h_pt_Ak8Puppijets = ctx.get_handle<float> ("pt_Ak8Puppijets");
  h_pt_Ak8Puppijet1 = ctx.get_handle<float> ("pt_Ak8Puppijet1");
  h_pt_Ak8Puppijet2 = ctx.get_handle<float> ("pt_Ak8Puppijet2");
  h_pt_Ak8Puppijet3 = ctx.get_handle<float> ("pt_Ak8Puppijet3");
  h_eta_Ak8Puppijets = ctx.get_handle<float> ("eta_Ak8Puppijets");
  h_eta_Ak8Puppijet1 = ctx.get_handle<float> ("eta_Ak8Puppijet1");
  h_eta_Ak8Puppijet2 = ctx.get_handle<float> ("eta_Ak8Puppijet2");
  h_eta_Ak8Puppijet3 = ctx.get_handle<float> ("eta_Ak8Puppijet3");
  h_phi_Ak8Puppijets = ctx.get_handle<float> ("phi_Ak8Puppijets");
  h_phi_Ak8Puppijet1 = ctx.get_handle<float> ("phi_Ak8Puppijet1");
  h_phi_Ak8Puppijet2 = ctx.get_handle<float> ("phi_Ak8Puppijet2");
  h_phi_Ak8Puppijet3 = ctx.get_handle<float> ("phi_Ak8Puppijet3");
  h_dR_mu_jet = ctx.get_handle<float> ("dR_mu_jet");
  h_dR_mu_Ak8Puppijet = ctx.get_handle<float> ("dR_mu_Ak8Puppijet");
  h_dR_jet_Ak8Puppijet = ctx.get_handle<float> ("dR_jet_Ak8Puppijet");
  h_ptrel_mu_jet = ctx.get_handle<float> ("ptrel_mu_jet");
  h_dphi_mu_jet1 = ctx.get_handle<float> ("dphi_mu_jet1");
  h_dphi_mu_Ak8Puppijet1 = ctx.get_handle<float> ("dphi_mu_Ak8Puppijet1");
  h_deepjetbscore_jet = ctx.get_handle<float> ("deepjetbscore_jet");
  h_deepjetbscore_jet1 = ctx.get_handle<float> ("deepjetbscore_jet1");
  h_deepjetbscore_jet2 = ctx.get_handle<float> ("deepjetbscore_jet2");
  h_deepjetbscore_jet3 = ctx.get_handle<float> ("deepjetbscore_jet3");
  h_dphi_mu_MET = ctx.get_handle<float> ("dphi_mu_MET");
  h_dphi_jet1_MET = ctx.get_handle<float> ("dphi_jet1_MET");
  
  if (debug) cout << "done" << endl;

}

void NeuralNetworkModule::CreateInputs(Event & event){
  bool debug=false;
  NNInputs.clear();
  NNoutputs.clear();
  if (debug) cout << "cleared NN inputs and outputs" << endl;
  string varname[56];
  string scal[56];
  string mean[56];
  string std[56];
  double mean_val[56];
  double std_val[56];
   
  if (debug) cout << "about to get info from norm.txt" << endl;
  ifstream normfile ("/nfs/dust/cms/user/titasroy/UHH2_2020/CMSSW_10_2_10/src/UHH2/NormInfo.txt", ios::in);
  if (normfile.is_open()){

        for(int i = 0; i < 56; ++i)
        {       
            normfile >> varname[i] >> scal[i] >> mean[i] >> std[i]; 
            mean_val[i] = std::stod(mean[i]);
            std_val[i] = std::stod(std[i]);
        }       
    normfile.close();
  }
  if (debug) cout << "about to get tensor flow values" << endl;

  NNInputs.push_back( tensorflow::Tensor(tensorflow::DT_FLOAT, {1, 56}));
  
  NNInputs.at(0).tensor<float, 2>()(0,0)  = (event.get(h_dR_jet_Ak8Puppijet)   - mean_val[0]) / (std_val[0]);
  NNInputs.at(0).tensor<float, 2>()(0,1)  = (event.get(h_dR_mu_Ak8Puppijet)   - mean_val[1]) / (std_val[1]);
  NNInputs.at(0).tensor<float, 2>()(0,2)  = (event.get(h_dR_mu_jet) - mean_val[2]) / (std_val[2]);
  NNInputs.at(0).tensor<float, 2>()(0,3)  = (event.get(h_deepjetbscore_jet)   - mean_val[3]) / (std_val[3]);
  NNInputs.at(0).tensor<float, 2>()(0,4)  = (event.get(h_deepjetbscore_jet1) - mean_val[4]) / (std_val[4]);
  NNInputs.at(0).tensor<float, 2>()(0,5)  = (event.get(h_deepjetbscore_jet2)  - mean_val[5]) / (std_val[5]);

  NNInputs.at(0).tensor<float, 2>()(0,6)  = (event.get(h_deepjetbscore_jet3)   - mean_val[6]) / (std_val[6]);
  NNInputs.at(0).tensor<float, 2>()(0,7)  = (event.get(h_dphi_jet1_MET)   - mean_val[7]) / (std_val[7]);
  NNInputs.at(0).tensor<float, 2>()(0,8)  = (event.get(h_dphi_mu_Ak8Puppijet1) - mean_val[8]) / (std_val[8]);
  NNInputs.at(0).tensor<float, 2>()(0,9)  = (event.get(h_dphi_mu_MET)   - mean_val[9]) / (std_val[9]);
  NNInputs.at(0).tensor<float, 2>()(0,10)  = (event.get(h_dphi_mu_jet1) - mean_val[10]) / (std_val[10]);
  NNInputs.at(0).tensor<float, 2>()(0,11)  = (event.get(h_eta_Ak8Puppijet1)  - mean_val[11]) / (std_val[11]);

  NNInputs.at(0).tensor<float, 2>()(0,12)  = (event.get(h_eta_Ak8Puppijet2)   - mean_val[12]) / (std_val[12]);
  NNInputs.at(0).tensor<float, 2>()(0,13)  = (event.get(h_eta_Ak8Puppijet3 )   - mean_val[13]) / (std_val[13]);
  NNInputs.at(0).tensor<float, 2>()(0,14)  = (event.get(h_eta_Ak8Puppijets) - mean_val[14]) / (std_val[14]);
  NNInputs.at(0).tensor<float, 2>()(0,15)  = (event.get(h_eta_jet)   - mean_val[15]) / (std_val[15]);
  NNInputs.at(0).tensor<float, 2>()(0,16)  = (event.get(h_eta_jet1) - mean_val[16]) / (std_val[16]);
  NNInputs.at(0).tensor<float, 2>()(0,17)  = (event.get(h_eta_jet2)  - mean_val[17]) / (std_val[17]);

  NNInputs.at(0).tensor<float, 2>()(0,18)  = (event.get(h_eta_jet3)   - mean_val[18]) / (std_val[18]);
  NNInputs.at(0).tensor<float, 2>()(0,19)  = (event.get(h_eta_mu)   - mean_val[19]) / (std_val[19]);
  NNInputs.at(0).tensor<float, 2>()(0,20)  = (event.get(h_mass_jet) - mean_val[20]) / (std_val[20]);
  NNInputs.at(0).tensor<float, 2>()(0,21)  = (event.get(h_mass_jet1)   - mean_val[21]) / (std_val[21]);
  NNInputs.at(0).tensor<float, 2>()(0,22)  = (event.get(h_mass_jet2) - mean_val[22]) / (std_val[22]);
  NNInputs.at(0).tensor<float, 2>()(0,23)  = (event.get(h_mass_jet3)  - mean_val[23]) / (std_val[23]);
  
  NNInputs.at(0).tensor<float, 2>()(0,24)  = (event.get(h_met_pt)   - mean_val[24]) / (std_val[24]);
  NNInputs.at(0).tensor<float, 2>()(0,25)  = (event.get(h_npv_pt)   - mean_val[25]) / (std_val[25]);
  NNInputs.at(0).tensor<float, 2>()(0,26)  = (event.get(h_phi_Ak8Puppijet1) - mean_val[26]) / (std_val[26]);
  NNInputs.at(0).tensor<float, 2>()(0,27)  = (event.get(h_phi_Ak8Puppijet2)   - mean_val[27]) / (std_val[27]);
  NNInputs.at(0).tensor<float, 2>()(0,28)  = (event.get(h_phi_Ak8Puppijet3) - mean_val[28]) / (std_val[28]);
  NNInputs.at(0).tensor<float, 2>()(0,29)  = (event.get(h_phi_Ak8Puppijets)  - mean_val[29]) / (std_val[29]);

  NNInputs.at(0).tensor<float, 2>()(0,30)  = (event.get(h_phi_jet)   - mean_val[30]) / (std_val[30]);
  NNInputs.at(0).tensor<float, 2>()(0,31)  = (event.get(h_phi_jet1)   - mean_val[31]) / (std_val[31]);
  NNInputs.at(0).tensor<float, 2>()(0,32)  = (event.get(h_phi_jet2) - mean_val[32]) / (std_val[32]);
  NNInputs.at(0).tensor<float, 2>()(0,33)  = (event.get(h_phi_jet3)   - mean_val[33]) / (std_val[33]);
  NNInputs.at(0).tensor<float, 2>()(0,34)  = (event.get(h_phi_mu) - mean_val[34]) / (std_val[34]);
  NNInputs.at(0).tensor<float, 2>()(0,35)  = (event.get(h_pt_Ak8Puppijet1)  - mean_val[35]) / (std_val[35]);

  NNInputs.at(0).tensor<float, 2>()(0,36)  = (event.get(h_pt_Ak8Puppijet2)     - mean_val[36]) / (std_val[36]);
  NNInputs.at(0).tensor<float, 2>()(0,37)  = (event.get(h_pt_Ak8Puppijet3)   - mean_val[37]) / (std_val[37]);
  NNInputs.at(0).tensor<float, 2>()(0,38)  = (event.get(h_pt_Ak8Puppijets)   - mean_val[38]) / (std_val[38]);
  NNInputs.at(0).tensor<float, 2>()(0,39)  = (event.get(h_pt_jet)   - mean_val[39]) / (std_val[39]);
  NNInputs.at(0).tensor<float, 2>()(0,40)  = (event.get(h_pt_jet1)    - mean_val[40]) / (std_val[40]);
  NNInputs.at(0).tensor<float, 2>()(0,41)  = (event.get(h_pt_jet2) - mean_val[41]) / (std_val[41]);
  NNInputs.at(0).tensor<float, 2>()(0,42)  = (event.get(h_pt_jet3) - mean_val[42]) / (std_val[42]);

  NNInputs.at(0).tensor<float, 2>()(0,43)  = (event.get(h_pt_mu)     - mean_val[43]) / (std_val[43]);
  NNInputs.at(0).tensor<float, 2>()(0,44)  = (event.get(h_ptrel_mu_jet)   - mean_val[44]) / (std_val[44]);
  NNInputs.at(0).tensor<float, 2>()(0,45)  = (event.get(h_reliso_mu)   - mean_val[45]) / (std_val[45]);
  NNInputs.at(0).tensor<float, 2>()(0,46)  = (event.get(h_s11)   - mean_val[46]) / (std_val[46]);
  NNInputs.at(0).tensor<float, 2>()(0,47)  = (event.get(h_s12)    - mean_val[47]) / (std_val[47]);
  NNInputs.at(0).tensor<float, 2>()(0,48)  = (event.get(h_s13) - mean_val[48]) / (std_val[48]);
  NNInputs.at(0).tensor<float, 2>()(0,49)  = (event.get(h_s22) - mean_val[49]) / (std_val[49]);

  NNInputs.at(0).tensor<float, 2>()(0,50)  = (event.get(h_s23)     - mean_val[50]) / (std_val[50]);
  NNInputs.at(0).tensor<float, 2>()(0,51)  = (event.get(h_s33)   - mean_val[51]) / (std_val[51]);
  NNInputs.at(0).tensor<float, 2>()(0,52)  = (event.get(h_st)   - mean_val[52]) / (std_val[52]);
  NNInputs.at(0).tensor<float, 2>()(0,53)  = (event.get(h_st_jets)   - mean_val[53]) / (std_val[53]);
  NNInputs.at(0).tensor<float, 2>()(0,54)  = (event.get(h_st_lep)    - mean_val[54]) / (std_val[54]);
  NNInputs.at(0).tensor<float, 2>()(0,55)  = (event.get(h_weight)    - mean_val[55]) / (std_val[55]);
 
 if (debug) cout << "got all tensor float values" << endl;
 if (NNInputs.size()!=LayerInputs.size()) throw logic_error("NeuralNetworkModule.cxx: Create a number of inputs diffetent wrt. LayerInputs.size()="+to_string(LayerInputs.size()));
 if (debug) cout << "done with getting inputs"<<endl;
}
class ZprimeAnalysisModule_NNimplement : public ModuleBASE {

public:
  explicit ZprimeAnalysisModule_NNimplement(uhh2::Context&);
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

  // AnalysisModules
  unique_ptr<AnalysisModule> LumiWeight_module, PUWeight_module, BTagWeight_module, printer_genparticles;

  // Taggers
  unique_ptr<AK8PuppiTopTagger> TopTaggerPuppi;

  // Mass reconstruction
  unique_ptr<ZprimeCandidateBuilder> CandidateBuilder;

  // Chi2 discriminator
  unique_ptr<ZprimeChi2Discriminator> Chi2DiscriminatorZprime;
  unique_ptr<ZprimeCorrectMatchDiscriminator> CorrectMatchDiscriminatorZprime;

  // Selections
  unique_ptr<Selection> Trigger1_selection, Trigger2_selection, NMuon1_selection, NMuon2_selection, NElectron_selection, TwoDCut_selection, Jet1_selection, Jet2_selection, Met_selection, Chi2_selection, TTbarMatchable_selection, Chi2CandidateMatched_selection, ZprimeTopTag_selection, BlindData_selection;
  std::unique_ptr<uhh2::Selection> met_sel;
  std::unique_ptr<uhh2::Selection> htlep_sel;
  std::unique_ptr<Selection> sel_1btag, sel_2btag;
  std::unique_ptr<Selection> TopJetBtagSubjet_selection;
  //2018 HE veto
  std::unique_ptr<Selection> HEMelectronSelection;
  std::unique_ptr<Selection> HEMjetSelection;
  std::unique_ptr<Selection> HEMtopjetSelection;



  //Handles
  
  Event::Handle<bool> h_is_zprime_reconstructed_chi2, h_is_zprime_reconstructed_correctmatch;
  Event::Handle<float> h_chi2;   
  Event::Handle<float> h_weight;
   
  Event::Handle<float> h_Mttbar; 
  Event::Handle<float> h_MET;
  Event::Handle<float> h_lep1_pt;
  
  
  // Configuration
  bool isMC, ispuppi, islooserselection;
  string Sys_MuonID, Sys_MuonTrigger, Sys_PU, Sys_btag;
  TString sample; 
  int runnr_oldtriggers = 299368; 

  bool is2016v2, is2016v3, is2017v2,is2017, is2018; 
  bool isMuon, isElectron;
  //cout << "setting variables" << endl;
  Event::Handle<float> h_met_pt;
  Event::Handle<float> h_st;
  Event::Handle<float> h_st_jets;
  Event::Handle<float> h_st_lep;
  Event::Handle<float> h_npv_pt;
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
  Event::Handle<float> h_s11;
  Event::Handle<float> h_s12;
  Event::Handle<float> h_s13;
  Event::Handle<float> h_s22;
  Event::Handle<float> h_s23;
  Event::Handle<float> h_s33;
  Event::Handle<float> h_pt_mu;
  Event::Handle<float> h_eta_mu;
  Event::Handle<float> h_phi_mu;
  Event::Handle<float> h_reliso_mu;
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
  Event::Handle<float> h_dR_mu_jet;
  Event::Handle<float> h_dR_mu_Ak8Puppijet;
  Event::Handle<float> h_dR_jet_Ak8Puppijet;
  Event::Handle<float> h_ptrel_mu_jet;
  Event::Handle<float> h_dphi_mu_jet1;
  Event::Handle<float> h_dphi_mu_Ak8Puppijet1;
  Event::Handle<float> h_deepjetbscore_jet;
  Event::Handle<float> h_deepjetbscore_jet1;
  Event::Handle<float> h_deepjetbscore_jet2;
  Event::Handle<float> h_deepjetbscore_jet3;
  Event::Handle<float> h_dphi_mu_MET;
  Event::Handle<float> h_dphi_jet1_MET;


  Event::Handle<std::vector<tensorflow::Tensor> > h_NNoutput;
  Event::Handle<double> h_NNoutput0;
  Event::Handle<double> h_NNoutput1;

  std::unique_ptr<NeuralNetworkModule> NNModule;


  uhh2::Event::Handle<ZprimeCandidate*> h_BestZprimeCandidateChi2;

};


void ZprimeAnalysisModule_NNimplement::book_histograms(uhh2::Context& ctx, vector<string> tags){
  for(const auto & tag : tags){
    string mytag = tag + "_Skimming";
    // book_HFolder(mytag, new TTbarLJHistsSkimming(ctx,mytag));
    mytag = tag+"_General";
    book_HFolder(mytag, new ZprimeSemiLeptonicHists(ctx,mytag));
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

void ZprimeAnalysisModule_NNimplement::fill_histograms(uhh2::Event& event, string tag){
  string mytag = tag + "_Skimming";
  // HFolder(mytag)->fill(event);
  mytag = tag+"_General";
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

/*
█  ██████  ██████  ███    ██ ███████ ████████ ██████  ██    ██  ██████ ████████  ██████  ██████
█ ██      ██    ██ ████   ██ ██         ██    ██   ██ ██    ██ ██         ██    ██    ██ ██   ██
█ ██      ██    ██ ██ ██  ██ ███████    ██    ██████  ██    ██ ██         ██    ██    ██ ██████
█ ██      ██    ██ ██  ██ ██      ██    ██    ██   ██ ██    ██ ██         ██    ██    ██ ██   ██
█  ██████  ██████  ██   ████ ███████    ██    ██   ██  ██████   ██████    ██     ██████  ██   ██
*/

ZprimeAnalysisModule_NNimplement::ZprimeAnalysisModule_NNimplement(uhh2::Context& ctx){
  debug = false;
  for(auto & kv : ctx.get_all()){
    cout << " " << kv.first << " = " << kv.second << endl;
  }
  if (debug) cout <<"in analysis module"<<endl;
  // Important selection values
  islooserselection = (ctx.get("is_looser_selection") == "true");
  double muon_pt(55.);
  double elec_pt(80.);
  double jet1_pt(100.);
  double jet2_pt(50.);
  //  double stlep_plus_met(150.);
  double chi2_max(30.);
  double mtt_blind(3000.);
  int nmuon_min1, nmuon_max1;
  int nmuon_min2, nmuon_max2;
  int nele_min, nele_max;
  string trigger1,trigger2;// trigger3;
  double MET_cut; double HT_lep_cut;
  isMuon = false; isElectron = false;
  if(ctx.get("channel") == "muon") isMuon = true;
  if(ctx.get("channel") == "electron") isElectron = true;

  if(isMuon){//semileptonic muon channel
	trigger1 = "HLT_Mu50_v*";
    if(is2016v2 || is2016v3)
      //trigger2 = "HLT_TkMu50_v*";
            trigger2 = "HLT_Mu50_v*"; //TkMu path does not exist in 2017/2018 and RunB 2016
    else
            trigger2 = "HLT_Mu50_v*"; //TkMu path does not exist in 2017/2018
  
    nmuon_min1 = 1, nmuon_max1 = -1;
    nmuon_min2 = 1, nmuon_max2 = 1;
    nele_min = 0; nele_max = 0;
    MET_cut = 50;
    jet1_pt = 100.;
    HT_lep_cut = 150;



 }
  if(isElectron){//semileptonic electron channel
    nmuon_min1 = 0; nmuon_max1 = 0;
    nmuon_min2 = 0; nmuon_max2 = 0;
    nele_min = 1; nele_max = 1;
    trigger1 = "HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_v*";
    trigger2 = "HLT_Ele115_CaloIdVT_GsfTrkIdT_v*";
    MET_cut = 120;
    jet1_pt = 185.;
    HT_lep_cut = 0;
    //    trigger3 = "HLT\_Ele115_v*";
  }

//No 2D cut for NN 
   //double TwoD_dr = 0.4, TwoD_ptrel = 25.;
   if(islooserselection){
    jet1_pt = 100.;
//    TwoD_dr = 0.2;
  //  TwoD_ptrel = 10.;
    if(isElectron){
	MET_cut = 50;
	}
    //    stlep_plus_met = 100.;
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
  is2018 = (ctx.get("dataset_version").find("2018") != std::string::npos);

  Sys_MuonID = ctx.get("Sys_MuonID");
  Sys_MuonTrigger = ctx.get("Sys_MuonTrigger");
  Sys_PU = ctx.get("Sys_PU");
  Sys_btag = ctx.get("Sys_BTagSF");
  
  if (debug) cout << "done with Sys PU and BTag"<< endl;

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

  // if(is2016v2){
  //   MuonID_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/karavdia/CMSSW_10_2_10/src/UHH2/common/data/2017/MuonID_94X_RunBCDEF_SF_ID.root", "NUM_HighPtID_DEN_genTracks_pair_newTuneP_probe_pt_abseta", 0., "HighPtID", true, Sys_MuonID));
  //   MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/karavdia/CMSSW_10_2_11/src/UHH2/common/data/2017/MuonTrigger_EfficienciesAndSF_RunBtoF_Nov17Nov2017.root", "Mu50_PtEtaBins/pt_abseta_ratio", 0.5, "Trigger", true, Sys_MuonTrigger));
  // }
  if(is2018){
     MuonID_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/titasroy/UHH2_2020/CMSSW_10_2_10/src/UHH2/common/data/2018/Muon_ID_SF_RunABCD.root", "NUM_HighPtID_DEN_TrackerMuons_pair_newTuneP_probe_pt_abseta", 0., "HighPtID", true, Sys_MuonID));
     MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/titasroy/UHH2_2020/CMSSW_10_2_10/src/UHH2/common/data/2018/Muon_Trigger_Eff_SF_AfterMuonHLTUpdate.root", "Mu50_OR_OldMu100_OR_TkMu100_PtEtaBins/pt_abseta_ratio", 0.5, "Trigger", true, Sys_MuonTrigger));
   }

  // Selection modules
  Trigger1_selection.reset(new TriggerSelection(trigger1));
  Trigger2_selection.reset(new TriggerSelection(trigger2));
  NMuon1_selection.reset(new NMuonSelection(nmuon_min1, nmuon_max1));
  NMuon2_selection.reset(new NMuonSelection(nmuon_min2, nmuon_max2));
  NElectron_selection.reset(new NElectronSelection(nele_min, nele_max));
  //TwoDCut_selection.reset(new TwoDCut(TwoD_dr, TwoD_ptrel));
   
  
  if (debug) cout << " done with lep and trigger" <<endl;		
			

  Jet1_selection.reset(new NJetSelection(1, -1, JetId(PtEtaCut(jet1_pt, 2.4))));
  Jet2_selection.reset(new NJetSelection(2, -1, JetId(PtEtaCut(jet2_pt, 2.4))));
  
  //  STlepPlusMet_selection.reset(new STlepPlusMetCut(stlep_plus_met, -1.));
  met_sel.reset(new METCut  (MET_cut   , uhh2::infinity));
  htlep_sel.reset(new HTlepCut(HT_lep_cut, uhh2::infinity));
  Chi2_selection.reset(new Chi2Cut(ctx, 0., chi2_max));
  TTbarMatchable_selection.reset(new TTbarSemiLepMatchableSelection());
  Chi2CandidateMatched_selection.reset(new Chi2CandidateMatchedSelection(ctx));
  ZprimeTopTag_selection.reset(new ZprimeTopTagSelection(ctx));
  BlindData_selection.reset(new BlindDataSelection(ctx, mtt_blind));

  // 2018 veto issue

  HEMelectronSelection.reset(new HEM_electronSelection(ctx));
  HEMtopjetSelection.reset(new HEM_topjetSelection(ctx));
  HEMjetSelection.reset(new HEM_jetSelection(ctx));

  if (debug) cout << "done with veto"<<endl;

  TopTaggerPuppi.reset(new AK8PuppiTopTagger(ctx));

  // Zprime candidate builder
  CandidateBuilder.reset(new ZprimeCandidateBuilder(ctx, mode));

  // Zprime discriminators
  Chi2DiscriminatorZprime.reset(new ZprimeChi2Discriminator(ctx));
  h_is_zprime_reconstructed_chi2 = ctx.get_handle<bool>("is_zprime_reconstructed_chi2");
  CorrectMatchDiscriminatorZprime.reset(new ZprimeCorrectMatchDiscriminator(ctx));
  h_is_zprime_reconstructed_correctmatch = ctx.get_handle<bool>("is_zprime_reconstructed_correctmatch");
  h_BestZprimeCandidateChi2 = ctx.get_handle<ZprimeCandidate*>("ZprimeCandidateBestChi2");
  h_chi2 = ctx.declare_event_output<float> ("rec_chi2"); 
  h_MET = ctx.declare_event_output<float> ("met_pt");
  h_Mttbar = ctx.declare_event_output<float> ("Mttbar");
  h_lep1_pt = ctx.declare_event_output<float> ("lep1_pt");
  if (debug) cout << "after met and chi2 declare"<<endl;





  // btag 
  //
//  CSVBTag::wp btag_wp = CSVBTag::WP_TIGHT; // b-tag workingpoint
  //JetId id_btag = CSVBTag(btag_wp);

  // DeepCSVBTag::wp btag_wp = DeepCSVBTag::WP_TIGHT; // b-tag workingpoint
  // JetId id_btag = DeepCSVBTag(btag_wp);

  //DeepJetBTag::wp btag_wp = DeepJetBTag::WP_TIGHT; // b-tag workingpoint
  //JetId id_btag = DeepJetBTag(btag_wp);

  sel_1btag.reset(new NJetSelection(1, 1, id_btag));
  sel_2btag.reset(new NJetSelection(2,-1, id_btag));


  TopJetBtagSubjet_selection.reset(new ZprimeBTagFatSubJetSelection(ctx));

  if (debug) cout << "done with all sel"<<endl;

  // Book histograms
  vector<string> histogram_tags = {"Weights", "Muon1", "Trigger", "Muon2", "Electron1", "TwoDCut", "Jet1", "Jet2", "MET", "HTlep","MatchableBeforeChi2Cut", "NotMatchableBeforeChi2Cut", "CorrectMatchBeforeChi2Cut", "NotCorrectMatchBeforeChi2Cut", "Chi2", "Matchable", "NotMatchable", "CorrectMatch", "NotCorrectMatch", "TopTagReconstruction", "NotTopTagReconstruction", "Btags2", "Btags1","TopJetBtagSubjet","DNN_output0","DNN_output1", "DNN_output0_TopTag","DNN_output1_TopTag","DNN_output0_NoTopTag","DNN_output1_NoTopTag","DNN_output0_Chi2","DNN_output1_Chi2"};
  book_histograms(ctx, histogram_tags);


  h_met_pt = ctx.get_handle<float> ("met_pt");
  h_weight = ctx.get_handle<float> ("weight");
  h_st = ctx.get_handle<float> ("st"); 
  h_st_jets = ctx.get_handle<float> ("st_jets");
  h_st_lep = ctx.get_handle<float> ("st_lep");
  h_npv_pt = ctx.get_handle<float> ("npv_pt");
  h_pt_jet = ctx.get_handle<float> ("pt_jet");
  h_pt_jet1 = ctx.get_handle<float> ("pt_jet1");
  h_pt_jet2 = ctx.get_handle<float> ("pt_jet2");
  h_pt_jet3 = ctx.get_handle<float> ("pt_jet3");
  h_eta_jet = ctx.get_handle<float> ("eta_jet");
  h_eta_jet1 = ctx.get_handle<float> ("eta_jet1");
  h_eta_jet2 = ctx.get_handle<float> ("eta_jet2");
  h_eta_jet3 = ctx.get_handle<float> ("eta_jet3");
  h_phi_jet = ctx.get_handle<float> ("phi_jet");
  h_phi_jet1 = ctx.get_handle<float> ("phi_jet1");
  h_phi_jet2 = ctx.get_handle<float> ("phi_jet2");
  h_phi_jet3 = ctx.get_handle<float> ("phi_jet3");
  h_mass_jet = ctx.get_handle<float> ("mass_jet");
  h_mass_jet1 = ctx.get_handle<float> ("mass_jet1");
  h_mass_jet2 = ctx.get_handle<float> ("mass_jet2");
  h_mass_jet3 = ctx.get_handle<float> ("mass_jet3");
  h_s11 = ctx.get_handle<float> ("s11");
  h_s12 = ctx.get_handle<float> ("s12");
  h_s13 = ctx.get_handle<float> ("s13");
  h_s22 = ctx.get_handle<float> ("s22");
  h_s23 = ctx.get_handle<float> ("s23");
  h_s33 = ctx.get_handle<float> ("s33");
  h_pt_mu = ctx.get_handle<float> ("pt_mu");
  h_eta_mu = ctx.get_handle<float> ("eta_mu");
  h_phi_mu = ctx.get_handle<float> ("phi_mu");
  h_reliso_mu = ctx.get_handle<float> ("reliso_mu");
  h_pt_Ak8Puppijets = ctx.get_handle<float> ("pt_Ak8Puppijets");
  h_pt_Ak8Puppijet1 = ctx.get_handle<float> ("pt_Ak8Puppijet1");
  h_pt_Ak8Puppijet2 = ctx.get_handle<float> ("pt_Ak8Puppijet2");
  h_pt_Ak8Puppijet3 = ctx.get_handle<float> ("pt_Ak8Puppijet3");
  h_eta_Ak8Puppijets = ctx.get_handle<float> ("eta_Ak8Puppijets");
  h_eta_Ak8Puppijet1 = ctx.get_handle<float> ("eta_Ak8Puppijet1");
  h_eta_Ak8Puppijet2 = ctx.get_handle<float> ("eta_Ak8Puppijet2");
  h_eta_Ak8Puppijet3 = ctx.get_handle<float> ("eta_Ak8Puppijet3");
  h_phi_Ak8Puppijets = ctx.get_handle<float> ("phi_Ak8Puppijets");
  h_phi_Ak8Puppijet1 = ctx.get_handle<float> ("phi_Ak8Puppijet1");
  h_phi_Ak8Puppijet2 = ctx.get_handle<float> ("phi_Ak8Puppijet2");
  h_phi_Ak8Puppijet3 = ctx.get_handle<float> ("phi_Ak8Puppijet3");
  h_dR_mu_jet = ctx.get_handle<float> ("dR_mu_jet");
  h_dR_mu_Ak8Puppijet = ctx.get_handle<float> ("dR_mu_Ak8Puppijet");
  h_dR_jet_Ak8Puppijet = ctx.get_handle<float> ("dR_jet_Ak8Puppijet");
  h_ptrel_mu_jet = ctx.get_handle<float> ("ptrel_mu_jet");
  h_dphi_mu_jet1 = ctx.get_handle<float> ("dphi_mu_jet1");
  h_dphi_mu_Ak8Puppijet1 = ctx.get_handle<float> ("dphi_mu_Ak8Puppijet1");
  h_deepjetbscore_jet = ctx.get_handle<float> ("deepjetbscore_jet");
  h_deepjetbscore_jet1 = ctx.get_handle<float> ("deepjetbscore_jet1");
  h_deepjetbscore_jet2 = ctx.get_handle<float> ("deepjetbscore_jet2");
  h_deepjetbscore_jet3 = ctx.get_handle<float> ("deepjetbscore_jet3");
  h_dphi_mu_MET = ctx.get_handle<float> ("dphi_mu_MET");
  h_dphi_jet1_MET = ctx.get_handle<float> ("dphi_jet1_MET");

  if (debug) cout << "about to get NN"<<endl;
  h_NNoutput = ctx.get_handle<std::vector<tensorflow::Tensor>>("NNoutput");
  h_NNoutput0 = ctx.declare_event_output<double>("NNoutput0");
  h_NNoutput1 = ctx.declare_event_output<double>("NNoutput1");
  if (debug) cout << "declared  NN"<<endl;
  NNModule.reset( new NeuralNetworkModule(ctx, "/nfs/dust/cms/user/titasroy/UHH2_2020/CMSSW_10_2_10/src/UHH2/model.pb", "/nfs/dust/cms/user/titasroy/UHH2_2020/CMSSW_10_2_10/src/UHH2/model.config.pbtxt"));
  if (debug) cout << "loaded  NN model"<<endl;

}
  

/*
██████  ██████   ██████   ██████ ███████ ███████ ███████
██   ██ ██   ██ ██    ██ ██      ██      ██      ██
██████  ██████  ██    ██ ██      █████   ███████ ███████
██      ██   ██ ██    ██ ██      ██           ██      ██
██      ██   ██  ██████   ██████ ███████ ███████ ███████
*/

bool ZprimeAnalysisModule_NNimplement::process(uhh2::Event& event){



  if (debug)  cout<<" run.event: "<<event.run<<". "<< event.event<<endl;

  // Initialize reco flags with false
  event.set(h_is_zprime_reconstructed_chi2, false);
  event.set(h_is_zprime_reconstructed_correctmatch, false);
  event.set(h_chi2,-100);
  //if (debug)  cout<<" doing event.set"<<endl; 
  event.set(h_MET,0);
  //if (debug)  cout<<" after MET"<<endl;
  event.set(h_weight,-100.);
//  if (debug)  cout<<" after weight"<<endl;
  event.set(h_Mttbar,0);
  event.set(h_lep1_pt,0);






  event.set(h_dR_jet_Ak8Puppijet,0);
  event.set(h_dR_mu_Ak8Puppijet,0);
  event.set(h_dR_mu_jet,0);
  event.set(h_deepjetbscore_jet,0);
  event.set(h_deepjetbscore_jet1,0);
  event.set(h_deepjetbscore_jet2,0);
  event.set(h_deepjetbscore_jet3,0);
  event.set(h_dphi_jet1_MET,0);
  event.set(h_dphi_mu_Ak8Puppijet1,0);
  event.set(h_dphi_mu_MET,0);
  event.set(h_dphi_mu_jet1,0);
  event.set(h_eta_Ak8Puppijet1,0);
  event.set(h_eta_Ak8Puppijet2,0);
  event.set(h_eta_Ak8Puppijet3,0);
  event.set(h_eta_Ak8Puppijets,0);
  event.set(h_eta_jet,0);
  event.set(h_eta_jet1,0);
  event.set(h_eta_jet2,0);
  event.set(h_eta_jet3,0);
  event.set(h_eta_mu,0);
  event.set(h_mass_jet,0);
  event.set(h_mass_jet1,0);
  event.set(h_mass_jet2,0);
  event.set(h_mass_jet3,0);
  event.set(h_met_pt,0);
  event.set(h_npv_pt,0);
  event.set(h_phi_Ak8Puppijet1,0);
  event.set(h_phi_Ak8Puppijet2,0);
  event.set(h_phi_Ak8Puppijet3,0);
  event.set(h_phi_Ak8Puppijets,0);
  event.set(h_phi_jet,0);
  event.set(h_phi_jet1,0);
  event.set(h_phi_jet2,0);
  event.set(h_phi_jet3,0);
  event.set(h_phi_mu,0);
  event.set(h_pt_Ak8Puppijet1,0);
  event.set(h_pt_Ak8Puppijet2,0);
  event.set(h_pt_Ak8Puppijet3,0);
  event.set(h_pt_Ak8Puppijets,0);
  event.set(h_pt_jet,0);
  event.set(h_pt_jet1,0);
  event.set(h_pt_jet2,0);
  event.set(h_pt_jet3,0);
  event.set(h_pt_mu,0);
  event.set(h_ptrel_mu_jet,0);
  event.set(h_reliso_mu,0);
  event.set(h_s11,0);
  event.set(h_s12,0);
  event.set(h_s13,0);
  event.set(h_s22,0);
  event.set(h_s23,0);
  event.set(h_s33,0);
  event.set(h_st,0);
  event.set(h_st_jets,0);
  event.set(h_st_lep,0);
  //event.set(h_weight_sfmu_Trigger,0);
  
  


  
  
  //if (debug)  cout<<" after MET, weight, ttbar"<<endl;
  event.set(h_NNoutput0, 0);
  event.set(h_NNoutput1, 0);
  
  // Printing
  // if(!event.isRealData) printer_genparticles->process(event);

  // TODO Apply things that should've been done in the pre-selection already... Fix pre-selection and then remove these steps
  if(isMuon) muon_cleaner->process(event);
  if(isElectron) electron_cleaner->process(event);
  if (debug)  cout<<" after cleaning "<<endl;
  // Weight modules
  LumiWeight_module->process(event);
  // in fisrt round re-weighting is switched off
  PUWeight_module->process(event);
  BTagWeight_module->process(event);
  if (debug)  cout<<" after BTag module, about to check Muon ID module"<<endl;
  if(isMuon){
    MuonID_module->process(event);
    if(debug)  cout<<"MuonID ok"<<endl;
  }
  // Run top-tagging
  TopTaggerPuppi->process(event);
 // fill_histograms(event, "Weights");

  //if (debug)  cout<<" about to do trigger"<<endl;
  if(!(Trigger1_selection->passes(event)|| Trigger2_selection->passes(event))) return false;
  
  if(isMuon && is2018 && !isMC && event.run>319077){
       if (HEMjetSelection->passes(event)) return false;
       if (HEMtopjetSelection->passes(event)) return false;
 }
 // if (debug)  cout<<"done with muons"<<endl;
  if(isMuon){
    if(!NMuon1_selection->passes(event)) return false;
   // fill_histograms(event, "Muon1");
    MuonTrigger_module->process_onemuon(event, 0);
    fill_histograms(event, "Trigger");
    if(!NMuon2_selection->passes(event)) return false;
    //fill_histograms(event, "Muon2");
  
}
 // if (debug)  cout<<"done with normal selection muons"<<endl;
  if(isElectron && is2018 && !isMC && event.run>319077){
       if (HEMjetSelection->passes(event)) return false;
       if (HEMelectronSelection->passes(event)) return false;
       if (HEMtopjetSelection->passes(event)) return false;
 }
  if (debug)  cout<<"done with data electrons"<<endl;
 
  //if (debug) cout << "Event number is : "<< event.run <<endl;
  
  if (debug) cout << "number of electrons before electron selection: "<<event.electrons->size()<<endl;
  
  
  if(isElectron){
	
  	if(!NElectron_selection->passes(event)) return false;
    //            if (debug) cout << "should not be here" << endl;
  		fill_histograms(event, "Electron1");
	}

  //if (debug) cout << "number of electrons after " << event.electrons->size()<<endl;
  //if((event.muons->size()+event.electrons->size()) != 1) return false; //veto events without leptons or with too many 
  if(debug) cout<<"N leptons ok: Nelectrons="<<event.electrons->size()<<" Nmuons="<<event.muons->size()<<endl;

  //if(!TwoDCut_selection->passes(event)) return false;
  //fill_histograms(event, "TwoDCut");

  // Here, the Zprime must be reconstructed (we ensured to have >= 2 AK4 jets, >= 1 muon)
  CandidateBuilder->process(event);
  Chi2DiscriminatorZprime->process(event);
  CorrectMatchDiscriminatorZprime->process(event);

  if(sample.Contains("_blinded")){
    if(!BlindData_selection->passes(event)) return false;
  }
  
  if(debug) cout<<"done with leptons"<<endl;

	
			
  
  
   //     if(debug) cout<<"should not be here"<<endl;
  if(!Jet1_selection->passes(event)) return false;
 // fill_histograms(event, "Jet1");

  if(!Jet2_selection->passes(event)) return false;
//  fill_histograms(event, "Jet2");
 
  if(debug) cout<<"done with Jets"<<endl;
  // if(!STlepPlusMet_selection->passes(event)) return false;
  // fill_histograms(event, "STlepPlusMet");

  // MET selection
  if(!met_sel->passes(event)) return false;
  //fill_histograms(event, "MET");
  if(debug) cout<<"before HTlep"<<endl;
  if(isMuon){
    if(!htlep_sel->passes(event)) return false;
   // if(debug) cout<<"passes HTlep"<<endl;
    //fill_histograms(event, "HTlep");
    if(debug) cout<<"HTlep is ok"<<endl;
  }

  if(TTbarMatchable_selection->passes(event)) fill_histograms(event, "MatchableBeforeChi2Cut");
  else fill_histograms(event, "NotMatchableBeforeChi2Cut");
  if(Chi2CandidateMatched_selection->passes(event)) fill_histograms(event, "CorrectMatchBeforeChi2Cut");
  else fill_histograms(event, "NotCorrectMatchBeforeChi2Cut");
  if(debug) cout<<"Chi2CandidateMatched_selection is ok"<<endl;
  if(!Chi2_selection->passes(event)) return false;
  fill_histograms(event, "Chi2");
  if(debug) cout<<"Chi2_selection is ok"<<endl;

  if(TTbarMatchable_selection->passes(event)) fill_histograms(event, "Matchable");
  else fill_histograms(event, "NotMatchable");

  if(Chi2CandidateMatched_selection->passes(event)) fill_histograms(event, "CorrectMatch");
  else fill_histograms(event, "NotCorrectMatch");

  if(ZprimeTopTag_selection->passes(event)) fill_histograms(event, "TopTagReconstruction");
  else fill_histograms(event, "NotTopTagReconstruction");

  //Test with b-tagging
  if(sel_2btag->passes(event)) fill_histograms(event, "Btags2");
  if(sel_1btag->passes(event)) fill_histograms(event, "Btags1");

  if(TopJetBtagSubjet_selection->passes(event)) fill_histograms(event, "TopJetBtagSubjet");
  if(debug) cout<<"TopJetBtagSubjet_selection is ok"<<endl;

  
  if(isElectron && is2018 && isMC){
       if (HEMjetSelection->passes(event) || HEMelectronSelection->passes(event)|| HEMtopjetSelection->passes(event)){
              event.weight=event.weight*0.35;
       if (debug)  cout<<"done with MC electrons 2018"<<endl;
   }
  }
  if(isMuon && is2018 && isMC){
       if (debug)  cout<<"check muons MC"<<endl;
       if (HEMjetSelection->passes(event) || HEMtopjetSelection->passes(event)) event.weight=event.weight*0.35;
      
   
  }
  if (debug) cout << "moving on " << endl;
  //Fill some vars for monitoring and comparison
  bool is_zprime_reconstructed_chi2 = event.get(h_is_zprime_reconstructed_chi2); 
  if(is_zprime_reconstructed_chi2){
    ZprimeCandidate* BestZprimeCandidate = event.get(h_BestZprimeCandidateChi2);
    //float chi2 = BestZprimeCandidate->discriminator("chi2_total");
    if(debug) cout<<" about to set chi2 and Mttbar vars " << endl;
    event.set(h_chi2,BestZprimeCandidate->discriminator("chi2_total"));
    if(debug) cout<<" done with chi2 " << endl;
    event.set(h_Mttbar,BestZprimeCandidate->Zprime_v4().M());
     if(debug) cout<<" done with Mttbar " << endl;
  }
  if(debug) cout<<"Set ttbar reconstruction vars for monitoring"<<endl;

  event.set(h_weight,event.weight);

  event.set(h_npv_pt,event.pvs->size());

  event.set(h_MET,event.met->pt());
  if (isElectron){
	event.set(h_lep1_pt,event.electrons->at(0).pt());
  }
  if (isMuon){
        event.set(h_lep1_pt,event.muons->at(0).pt());
  }
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

  event.set(h_st,st);
  event.set(h_st_jets,st_jets);
  event.set(h_st_lep,st_lep);
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
//      event.set(h_dR_ele_jet,dR_ele_jet);
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
      event.set(h_deepjetbscore_jet3,jets->at(i).btag_DeepJet());
    }
  }
  if(debug) cout<<" doing Sphericity tensors"<<endl;
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

  event.set(h_s11,s11);
  event.set(h_s12,s12);
  event.set(h_s13,s13);
  event.set(h_s22,s22);
  event.set(h_s23,s23);
  event.set(h_s33,s33);
 
   if(debug) cout<<" done with Sphericity tensors"<<endl;
  // Muons
  int Nmuons = muons->size();
  //event.set(h_N_mu,Nmuons);

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

    //event.set(h_pt_ele,electrons->at(i).pt());
    //event.set(h_eta_ele,electrons->at(i).eta());
    //event.set(h_phi_ele,electrons->at(i).phi());
    //event.set(h_reliso_ele,electrons->at(i).relIso());
    if(electrons->at(i).has_tag(Electron::twodcut_dRmin) && electrons->at(i).has_tag(Electron::twodcut_pTrel)){
   //   event.set(h_dRmin_ele_jet,electrons->at(i).get_tag(Electron::twodcut_dRmin));
      //event.set(h_ptrel_ele_jet,electrons->at(i).get_tag(Electron::twodcut_pTrel));
    }
      for(unsigned int j=0; j<jets->size(); j++){
       if(j==0){
      // event.set(h_dphi_ele_jet1,deltaPhi(electrons->at(i),jets->at(j)));
       //event.set(h_dphi_ele_MET,deltaPhiMET(electrons->at(i),event.met));
       }
      }
      for(unsigned int k=0; k<event.toppuppijets->size(); k++){
       if(k==0){
       //event.set(h_dphi_ele_Ak8Puppijet1,deltaPhi(electrons->at(i),event.toppuppijets->at(k)));
       }
      }
  }

  if(debug) cout<<" done with electrons"<<endl;
  // Ak8 Puppi jets
  if (debug) cout<< "about to do AK8Puppijets" << endl;
  vector<TopJet>* AK8Puppijets = event.toppuppijets;
  unsigned int NAK8Puppijets = 0;
  for(unsigned int i=0; i<AK8Puppijets->size(); i++){
    if(AK8Puppijets->at(i).numberOfDaughters()<2) continue;
    NAK8Puppijets++;

    event.set(h_pt_Ak8Puppijets,AK8Puppijets->at(i).pt());
    event.set(h_eta_Ak8Puppijets,AK8Puppijets->at(i).eta());
    event.set(h_phi_Ak8Puppijets,AK8Puppijets->at(i).phi());
    //event.set(h_mSD_Ak8Puppijets,AK8Puppijets->at(i).softdropmass());

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
      //event.set(h_dR_ele_Ak8Puppijet,dR_ele);
    }

    double dRmin_jet = 99999;
    for(unsigned int j=0; j<event.jets->size(); j++){
      double dR_jet = deltaR(AK8Puppijets->at(i), event.jets->at(j));
      if(dR_jet < dRmin_jet) dRmin_jet = dR_jet;
      event.set(h_dR_jet_Ak8Puppijet,dR_jet);
    }

    if (debug) cout<<" done with dR"<<endl;
    if(i==0){
      event.set(h_pt_Ak8Puppijet1,AK8Puppijets->at(i).pt());
      event.set(h_eta_Ak8Puppijet1,AK8Puppijets->at(i).eta());
      event.set(h_phi_Ak8Puppijet1,AK8Puppijets->at(i).phi());
      //event.set(h_mSD_Ak8Puppijet1,AK8Puppijets->at(i).softdropmass());
    }


  if(i==1){
      event.set(h_pt_Ak8Puppijet2,AK8Puppijets->at(i).pt());
      event.set(h_eta_Ak8Puppijet2,AK8Puppijets->at(i).eta());
      event.set(h_phi_Ak8Puppijet2,AK8Puppijets->at(i).phi());
     // event.set(h_mSD_Ak8Puppijet2,AK8Puppijets->at(i).softdropmass());
    }

    if(i==2){
      event.set(h_pt_Ak8Puppijet3,AK8Puppijets->at(i).pt());
      event.set(h_eta_Ak8Puppijet3,AK8Puppijets->at(i).eta());
      event.set(h_phi_Ak8Puppijet3,AK8Puppijets->at(i).phi());
     // event.set(h_mSD_Ak8Puppijet3,AK8Puppijets->at(i).softdropmass());
    }

  //  event.set(h_N_Ak8Puppijets,NAK8Puppijets);
}

   //Neural network outputs
  if (debug) cout << "starting NN getoutputs" << endl;
  NNModule->process(event);
  if (debug) cout << "done with NNmodule processing events" <<endl;
  std::vector<tensorflow::Tensor> NNoutputs = NNModule->GetOutputs();

  event.set(h_NNoutput0, (double)(NNoutputs[0].tensor<float, 2>()(0,0)));
  event.set(h_NNoutput1, (double)(NNoutputs[0].tensor<float, 2>()(0,1)));
  event.set(h_NNoutput, NNoutputs);

  double out0 = (double)(NNoutputs[0].tensor<float, 2>()(0,0));
  double out1 = (double)(NNoutputs[0].tensor<float, 2>()(0,1));
  vector<double> out_event = {out0, out1};

  double max_score = 0.0;
  for ( int i = 0; i < 2; i++ ) {
    if ( out_event[i] > max_score) {
    max_score = out_event[i];
    }
  }

  if (debug) cout << "Fill NN vars" << endl;
  if (debug) cout << "max_score: "<< max_score<< endl;
  if (debug) cout << "out0: " <<out0<<endl;
  if (debug) cout << "out1: " <<out1<<endl;

  if( out0 == max_score ){
   if (debug) cout << "about to fill histograms for DNN_output0"<< endl;
   fill_histograms(event, "DNN_output0");
   if( ZprimeTopTag_selection->passes(event) ) 
	fill_histograms(event, "DNN_output0_TopTag");
   else fill_histograms(event, "DNN_output0_NoTopTag");
   if( Chi2_selection->passes(event) ) fill_histograms(event, "DNN_output0_Chi2");
    
  }

  if( out1 == max_score ){
    if (debug) cout << "about to fill histograms for DNN_output1"<< endl;
    fill_histograms(event, "DNN_output1");
    if( ZprimeTopTag_selection->passes(event) ) fill_histograms(event, "DNN_output1_TopTag");
    else fill_histograms(event, "DNN_output1_NoTopTag");
    if( Chi2_selection->passes(event) ) fill_histograms(event, "DNN_output1_Chi2");
  }

  if (debug) cout << "done with filling DNN variables" << endl;
    
  event.set(h_weight, 100.);  
  


  return true;
 
}
UHH2_REGISTER_ANALYSIS_MODULE(ZprimeAnalysisModule_NNimplement)
