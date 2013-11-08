









void Graph2Randoms(){
  TCanvas * c = new TCanvas("c");


  TFile *fileFudge = new TFile("~/analysis/run354/EffoutWithFudge.root");
  
  

  TH1F * h = (TH1F*) gDirectory->Get("ShadowBarRandomBackGround");
  Double_t error[71];
  for (int i=1;i<71;i++){
    error[i]=sqrt(h->GetBinContent(i))/10;
  }

  c->cd(1);
  h->Scale(1.0/10.0);
  h->SetError(error);
  h->Draw();
    
  TFile *fileNoFudge = new TFile("~/analysis/run355/Effout.root");
  
  

  TH1F * h2 = (TH1F*) gDirectory->Get("ShadowBarRandomBackGround");
  
  c->cd(1);
  h2->SetLineColor(kRed);
  h2->Draw("sameE1");
    
  




}
