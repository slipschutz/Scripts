


Double_t func(Double_t in)
{
  
  return 0.012*in;
}

Double_t func2(Double_t in)
{
  
  return 0.012*in;
}



void BenchLE(){

  TFile *f =new TFile("out.root","recreate");


  TTree * tree = new TTree("flt","Test Tree");

  LendaEvent * event = new LendaEvent();

  tree->Branch("Event",&event);

  TRandom3 *rand = new TRandom3(30523);

  int num=1000000;

  std::vector <UShort_t> trace(100);
  for (int i=0;i<100;i++)
    trace[i]=i;

  Double_t TOF,energy1,energy2,energy3;
  Double_t times[3];

  for (Int_t i=0;i<num;i++){

    energy1 = rand->Uniform()*100;
    energy2 = rand->Uniform()*100;
    
    
    times[0]=rand->Gaus( func(energy1),0.2 );
    times[1]=rand->Gaus( func2(energy2),0.2 );
    times[2] = rand->Gaus(5,0.001);
    

    event->pushTrace(trace);
    event->pushTrace(trace);
    event->pushTrace(trace);

    event->pushLongGate(10);
    event->pushLongGate(10);
    event->pushLongGate(10);

    event->pushShortGate(10);
    event->pushShortGate(10);
    event->pushShortGate(10);

    event->pushEnergy(energy1);
    event->pushEnergy(energy2);
    event->pushEnergy(10);

    event->pushTime(times[0]);
    event->pushTime(times[1]);
    event->pushTime(times[2]);

    event->pushChannel(2);
    event->pushChannel(3);
    event->pushChannel(8);
    
    event->Finalize();
    
    tree->Fill();
    event->Clear();


  }

  f->Write();






}
