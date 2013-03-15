#include "TTree.h"
#include <stdlib.h>

#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include <TRandom1.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "TRandom3.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TGraph.h"
#include "TChain.h"



using namespace std;

void graph(Int_t n){


  Int_t chanid;
  Int_t slotid;
  vector<UShort_t> trace;
  UInt_t fUniqueID;
  UInt_t energy;
  Double_t time ; 
  UInt_t timelow; // this used to be usgined long
  UInt_t timehigh; // this used to be usgined long
  UInt_t timecfd ; 

  TChain *inT;
  inT = new TChain("dchan");
  inT->Add("../run294/run-0294-00.root");
  inT->SetMakeClass(1);

  Long64_t totalEntries =(Long64_t)inT->GetEntries();
  cout<<"tot "<<totalEntries<<endl;

  inT->SetBranchAddress("chanid", &chanid);
  inT->SetBranchAddress("fUniqueID", &fUniqueID);
  inT->SetBranchAddress("energy", &energy);
  inT->SetBranchAddress("timelow", &timelow);
  inT->SetBranchAddress("timehigh", &timehigh);
  inT->SetBranchAddress("trace", &trace);
  inT->SetBranchAddress("timecfd", &timecfd);
  inT->SetBranchAddress("slotid", &slotid);
  inT->SetBranchAddress("time", &time);

  TCanvas * c =new TCanvas("c");
  c->Divide(1,2);
  int j=0; int count =0;
  while (j < 2 ){
    inT->GetEntry(n+count);
    if (chanid == 0){
      cout<<"Channel is "<<chanid<<" entry is "<<n+count<<endl;
       
      Double_t x[100];
      Double_t y[100];
      
      
      for (int i=0;i<100;i++){
	x[i]=i;
	y[i]=trace[i];
      }
      
      c->cd(1+j);      
      TGraph *graph = new TGraph(100,x,y);
      std::stringstream s;
      s<<"jentry"<<n+count;
      graph->SetTitle(s.str().c_str());
      s.str("");
      graph->Draw("LA*S");
      j++;
      count++;
    } else {
      
      count++;

    }
  }
  
}
