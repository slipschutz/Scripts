





void sub2histos2(TH1F* h1, TH1F* h2){


  Int_t num = h1->GetNbinsX();
  

  Int_t low = h1->GetXaxis()->GetBinLowEdge(1);
  Int_t high = h1->GetXaxis()->GetBinUpEdge(num);

  cout<<"low is "<<low<<endl;
  cout<<"high is"<<high<<endl;

  for (int i=1;i<=num;i++){
    double val1=h1->GetBinContent(i);
    double val2=h2->GetBinContent(i);
    h1->SetBinContent(i, val1-val2);

  }

}
