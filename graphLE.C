


void graphLE(Long64_t entry){

  LendaEvent * event = new LendaEvent();
  flt->SetBranchAddress("Event",&event);

  flt->GetEntry(entry);
  
  event->MakeC();
  
  Double_t x[100];
  Double_t y[100];
  
  for (int i=0;i<100;i++){
    x[i]=i;
    y[i]=event->CTrace[i];
  }

  TGraph *gr = new TGraph(100,x,y);
  
  TCanvas *c = new TCanvas();

  c->cd(1);
  gr->Draw("AL*");

}
