#pragma once

#include "FlavorParticle.h"
#include "Tags.h"

class Jet : public FlavorParticle{
public:
    
  enum tag { /* for future use (more b-taggers, etc.) */ };
  
  Jet(){
    m_jetArea = 0;
    m_numberOfDaughters = 0;
    m_neutralEmEnergyFraction = 0;
    m_neutralHadronEnergyFraction = 0;
    m_chargedEmEnergyFraction = 0;
    m_chargedHadronEnergyFraction = 0;
    m_muonEnergyFraction = 0;
    m_photonEnergyFraction = 0;
    m_chargedMultiplicity = 0;
    m_neutralMultiplicity = 0;
    m_muonMultiplicity = 0;
    m_electronMultiplicity = 0;
    m_photonMultiplicity = 0;
    m_btag_simpleSecondaryVertexHighEff = 0;
    m_btag_simpleSecondaryVertexHighPur = 0;
    m_btag_combinedSecondaryVertex = 0;
    m_btag_combinedSecondaryVertexMVA = 0;
    m_btag_jetBProbability = 0;
    m_btag_jetProbability = 0;
    m_JEC_factor_raw = 0;
    m_genjet_index = 0;
  }

  float jetArea() const{return m_jetArea;}
  int numberOfDaughters() const{return m_numberOfDaughters;} 
  float neutralEmEnergyFraction() const{return m_neutralEmEnergyFraction;}
  float neutralHadronEnergyFraction() const{return m_neutralHadronEnergyFraction;}
  float chargedEmEnergyFraction() const{return m_chargedEmEnergyFraction;}
  float chargedHadronEnergyFraction() const{return m_chargedHadronEnergyFraction;}
  float muonEnergyFraction() const{return m_muonEnergyFraction;}
  float photonEnergyFraction() const{return m_photonEnergyFraction;}
  int chargedMultiplicity() const{return m_chargedMultiplicity;}
  int neutralMultiplicity() const{return m_neutralMultiplicity;}
  int muonMultiplicity() const{return m_muonMultiplicity;} 
  int electronMultiplicity() const{return m_electronMultiplicity;}
  int photonMultiplicity() const{return m_photonMultiplicity;}
  float btag_simpleSecondaryVertexHighEff() const{return m_btag_simpleSecondaryVertexHighEff;}
  float btag_simpleSecondaryVertexHighPur() const{return m_btag_simpleSecondaryVertexHighPur;}
  float btag_combinedSecondaryVertex() const{return m_btag_combinedSecondaryVertex;} // combinedInclusiveSecondaryVertexV2BJetTags
  float btag_combinedSecondaryVertexMVA() const{return m_btag_combinedSecondaryVertexMVA;}
  float btag_jetBProbability() const{return m_btag_jetBProbability;}
  float btag_jetProbability() const{return m_btag_jetProbability;}
  float JEC_factor_raw() const{return m_JEC_factor_raw;}
  float get_tag(tag t) const { return tags.get_tag(static_cast<int>(t)); }

  void set_jetArea(float x){m_jetArea=x;}
  void set_numberOfDaughters(int x){m_numberOfDaughters=x;} 
  void set_neutralEmEnergyFraction(float x){m_neutralEmEnergyFraction=x;}
  void set_neutralHadronEnergyFraction(float x){m_neutralHadronEnergyFraction=x;}
  void set_chargedEmEnergyFraction(float x){m_chargedEmEnergyFraction=x;}
  void set_chargedHadronEnergyFraction(float x){m_chargedHadronEnergyFraction=x;}
  void set_muonEnergyFraction(float x){m_muonEnergyFraction=x;}
  void set_photonEnergyFraction(float x){m_photonEnergyFraction=x;}
  void set_chargedMultiplicity(int x){m_chargedMultiplicity=x;}
  void set_neutralMultiplicity(int x){m_neutralMultiplicity=x;}
  void set_muonMultiplicity(int x){m_muonMultiplicity=x;} 
  void set_electronMultiplicity(int x){m_electronMultiplicity=x;}
  void set_photonMultiplicity(int x){m_photonMultiplicity=x;}
  void set_btag_simpleSecondaryVertexHighEff(float x){m_btag_simpleSecondaryVertexHighEff=x;}
  void set_btag_simpleSecondaryVertexHighPur(float x){m_btag_simpleSecondaryVertexHighPur=x;}
  void set_btag_combinedSecondaryVertex(float x){m_btag_combinedSecondaryVertex=x;} // for 72, this is combinedInclusiveSecondaryVertexV2BJetTags
  void set_btag_combinedSecondaryVertexMVA(float x){m_btag_combinedSecondaryVertexMVA=x;}
  void set_btag_jetBProbability(float x){m_btag_jetBProbability=x;}
  void set_btag_jetProbability(float x){m_btag_jetProbability=x;}
  void set_JEC_factor_raw(float x){m_JEC_factor_raw=x;}
  void set_genjet_index(int x){m_genjet_index=x;}
  void set_tag(tag t, float value) { return tags.set_tag(static_cast<int>(t), value); }

  bool pfID() const {
    //pf ID has already been applied when using goodPatJets
    if(numberOfDaughters()>1 
       && neutralHadronEnergyFraction()<0.99
       && neutralEmEnergyFraction()<0.99){
      
      if(fabs(eta())>=2.4)
        return true;
      
      if(chargedEmEnergyFraction()<0.99
        && chargedHadronEnergyFraction()>0
        && chargedMultiplicity()>0)
        return true;   
    }
    return false;
  }


 private:
  
  float m_jetArea;
  int m_numberOfDaughters;
  float m_neutralEmEnergyFraction;
  float m_neutralHadronEnergyFraction;
  float m_chargedEmEnergyFraction;
  float m_chargedHadronEnergyFraction;
  float m_muonEnergyFraction;
  float m_photonEnergyFraction;
  int m_chargedMultiplicity;
  int m_neutralMultiplicity;
  int m_muonMultiplicity;
  int m_electronMultiplicity;
  int m_photonMultiplicity;
  float m_btag_simpleSecondaryVertexHighEff;
  float m_btag_simpleSecondaryVertexHighPur;
  float m_btag_combinedSecondaryVertex;
  float m_btag_combinedSecondaryVertexMVA;
  float m_btag_jetBProbability;
  float m_btag_jetProbability;
  float m_JEC_factor_raw;
  int m_genjet_index;
  
  Tags tags;
};
