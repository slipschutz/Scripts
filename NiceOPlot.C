



void NiceOPlot(TH1F* h1, TH1F* h2,TH1F* h3=0) {

  /*  TH1F* h1 = new TH1F(*h);
  h1->SetName("h1");
  for (int i=1;i<1600;i++){

    if ( h1->GetBinContent(i)-1.71292 >0){
      h1->SetBinContent(i,h1->GetBinContent(i)-1.71292);
    }else {
      if ( h1->GetXaxis()->GetBinCenter(i) <31)
	cout<<h1->GetXaxis()->GetBinCenter(i)<<i<<" value "<<h1->GetBinContent(i)-1.71292<<endl;
    }
  }
  */


  gROOT->ProcessLine(".L ~/analysis/scripts/LoadStyle.C");
  LoadStyle();
  
  
  h1->UseCurrentStyle();
  h2->UseCurrentStyle();


  if (gPad == NULL){
    TCanvas * c = new TCanvas("_c8S24");
  }
  
  
  if (h3 !=0 ){
    h3->UseCurrentStyle();
    gPad->GetCanvas()->Clear();
    gPad->GetCanvas()->Divide(1,2);
  }
    


  gPad->GetCanvas()->cd(1);
  h1->SetLineColor(kRed);
  h1->Draw();
  h2->SetLineColor(kBlue);
  h2->Draw("same");

  h1->GetXaxis()->SetTitleSize(0.06);
  h1->GetXaxis()->SetTitleOffset(0.95);
  h1->GetXaxis()->SetTitle("Time of Flight [clock tics]");

  if (h3!=0){
    gPad->GetCanvas()->cd(2);
    h3->SetMaximum(h1->GetMaximum());
    h3->Draw();
    h3->GetXaxis()->SetTitleSize(0.06);
    h3->GetXaxis()->SetTitleOffset(0.95);
    h3->GetXaxis()->SetTitle("Time of Flight [clock tics]");

  }

  gPad->GetCanvas()->cd(1);
  leg = new TLegend(0.7,0.7,1,1);
  leg->SetLineWidth(1);
  leg->SetFillColor(kWhite);
  leg->SetHeader("");
  leg->AddEntry(h1, "Original Spectrum","l");
  leg->AddEntry(h2,"Background Sub.","l");
  leg->AddEntry(h3,"Background","l");

  leg->Draw();
  gROOT->ForceStyle();

}
