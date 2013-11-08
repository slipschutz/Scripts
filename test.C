void test() {

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

    TF1 *f1 = new TF1("f1","x-x^3/6",-TMath::Pi(),TMath::Pi());
  TF1 *f2 = new TF1("f2","TMath::Sin(x)",-TMath::Pi(),TMath::Pi());
 
  f1->GetXaxis()->SetLabelSize(0);
  f1->GetXaxis()->SetTickLength(0);
  f1->GetHistogram()->SetMinimum(-2.);
  f1->GetHistogram()->SetMaximum(+2.);
  f1->Draw();
  f2->SetLineColor(kGreen);
  f2->Draw("same");
 
  TGaxis* tgaxis=new TGaxis(-TMath::Pi(),-2.1,TMath::Pi(),-2.1,-180.,180,510,"",0);
  tgaxis->SetTitle("#theta (degree)");
  tgaxis->SetLineWidth(2);
  tgaxis->SetLineColor(kBlue);
  tgaxis->SetTextColor(kBlue);
  tgaxis->SetLabelColor(kBlue);
  tgaxis->SetTextSize(.05);
  tgaxis->SetLabelSize(.05);
  tgaxis->SetTextFont(42);
  tgaxis->SetLabelFont(42);
  tgaxis->CenterTitle(1);
  tgaxis->Draw();
  
  return;
}
