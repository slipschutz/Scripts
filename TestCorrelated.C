

#include <iostream>
#include "TTree.h"
#include "TFile.h"

void TestCorrelated(){

  gSystem->Load("../ddasChannel/libddaschannel-m64.so");

  TFile * f = new TFile("run-0001-00.root","recreate");
  
  TTree * tree = new TTree("dchan","test tree");
  
  ddaschannel * chan = new ddaschannel();
  
  tree->Branch("dchan",&chan);

  
  chan->chanid = 2;
  chan->time = 200;
  tree->Fill();

  chan->chanid = 3;
  chan->time = 200.5;
  tree->Fill();




  chan->chanid = 3;
  chan->time = 300;
  tree->Fill();
  chan->chanid = 1;
  chan->time = 300.5;
  tree->Fill();
  chan->chanid = 2;
  chan->time = 300.5;
  tree->Fill();

  chan->chanid = 3;
  chan->time = 400.5;
  tree->Fill();
  chan->chanid = 1;
  chan->time = 410.6;
  tree->Fill();

  chan->chanid = 1;
  chan->time = 410.62;
  tree->Fill();

  chan->chanid = 1;
  chan->time = 410.1;
  tree->Fill();

  chan->chanid = 2;
  chan->time = 410.2;
  tree->Fill();



  chan->chanid = 3;
  chan->time = 500;
  tree->Fill();
  chan->chanid = 1;
  chan->time = 500.5;
  tree->Fill();
  chan->chanid = 2;
  chan->time = 500.5;
  tree->Fill();




  chan->chanid = 2;
  chan->time = 1500.5;
  tree->Fill();






  tree->Write();
  f->Close();

}
