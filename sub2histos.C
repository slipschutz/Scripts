





void sub2histos(TH1F* h1, TH1F* h2){


  Int_t num = h1->GetNbinsX();
  

  Int_t low = h1->GetXaxis()->GetBinLowEdge(1);
  Int_t high = h1->GetXaxis()->GetBinUpEdge(num);

  cout<<"low is "<<low<<endl;
  cout<<"high is"<<high<<endl;

  TH1F * hresult= new TH1F ("hresult","",num,low,high);

  for (int i=1;i<=num;i++){
    hresult->SetBinContent(i, h1->GetBinContent(i)-h2->GetBinContent(i));

  }

}
