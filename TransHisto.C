





void TransHisto(TH1F* h1){
  
  
  Int_t num = h1->GetNbinsX();
  

  Int_t low = h1->GetXaxis()->GetBinLowEdge(1);
  Int_t high = h1->GetXaxis()->GetBinUpEdge(num);


  TH1F * TransH = new TH1F("TransH","",num,low,high);

  for (int i=0;i<num;i++){
    


    double a1=1.03447e+00;
    double a0=-1.39612e+04;
    double val = h1->GetBinContent(i+1)*a1 + a0;
    TransH->SetBinContent(i+1,val);
  }


}
