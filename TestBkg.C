









void TestBkg(){

  
  TFile * f = new TFile("./TestBkg.root","recreate");
  TTree * tree = new TTree("flt","data");
			
  LendaEvent *e = new LendaEvent();
  tree->Branch("Event",&e);
			
  TRandom3 * r = new TRandom3();
  for (int i=0;i<100000;i++){

    Double_t v =    r->Uniform()*30.0;

    e->pushTime(30);
    e->pushTime(30);
    
    e->pushTime(v);
    
    e->pushEnergy(1);
    e->pushEnergy(1);
    e->pushEnergy(1);

    e->pushLongGate(2);
    e->pushLongGate(2);
    e->pushLongGate(2);


    e->pushShortGate(2);
    e->pushShortGate(2);
    e->pushShortGate(2);

    e->pushCubicTime(e->times[0]);
    e->pushCubicTime(e->times[1]);
    e->pushCubicTime(e->times[2]);

    
    e->pushSoftwareCFD(1);    e->pushSoftwareCFD(1);    e->pushSoftwareCFD(1);
    
    
    e->Finalize();

    tree->Fill();
    e->Clear();
  }

  tree->Write();

  f->Close();
}
