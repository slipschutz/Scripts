


TGraphErrors* TOF_walk(){


  Double_t startGamma=-15.6;
  Double_t endGamma=-14.8;

  if (gROOT->GetListOfSpecials()->IsEmpty()){
    cout<<"NO TCutG found \nMake a PulseShape cut first"<<endl;
    return;
  }

  TH2F * E_vs_TOF =new TH2F("E_vs_TOF","E_vs_TOF",1000,-20,20,1000,0,2000);


  flt->Project("E_vs_TOF","energiesCor[0]:TOFW1",
	       "CUTG && channels[0]==2&&abs(ShiftTOF)<20&&abs(CorGOE)<0.5&&channels[2]==8");

  Int_t channel=0;
  const Int_t numProjections=40;

  Double_t range=1200;
  Double_t startPoint=0;
  Double_t step =(range-startPoint)/numProjections;
  TH1D * projections[numProjections];


  Double_t x[numProjections];
  Double_t y[numProjections];
  Double_t ex[numProjections];
  Double_t ey[numProjections];


  std::stringstream s;
  for (int i=0;i<numProjections;i++){
    Int_t bin1 = E_vs_TOF->GetYaxis()->FindBin(startPoint +i*step);
    Int_t bin2 = E_vs_TOF->GetYaxis()->FindBin(startPoint+ (i+1)*step);
    ///     Int_t bin2 = channel[j]->GetYaxis()->FindBin(600);
    x[i]=startPoint+i*step;
    ex[i]=0;
    
    s<<"chan"<<channel<<"__px"<<floor(startPoint+i*step);
    
    projections[i]=E_vs_TOF->ProjectionX(s.str().c_str(),bin1,bin2);
    projections[i]->SetTitle("TOF");
    s.str("");
  }


  TF1 *f1 = new TF1("f1","gaus",startGamma,endGamma);
  

  TFitResultPtr result;
  for(int i=0;i<numProjections;i++){
    result = projections[i]->Fit("f1","QSNR");
    Int_t status=result;
    if (status==0){
      y[i]=result->Value(1);
      ey[i]=result->UpperError(1);
    } else {
      y[i]=0;
      ey[i]=0;

    }
    
    cout<<y[i]<<" "<<ey[i]<<endl;

  }

  TGraphErrors *gr =new TGraphErrors(numProjections,x,y,ex,ey);
  
  TCanvas *c = new TCanvas("c22");

  c->cd(1);
  gr->Draw("AL*");




  return gr;

}
