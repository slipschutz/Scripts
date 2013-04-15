


TGraphErrors* TOF_pos(){


  Double_t startGamma=-66;
  Double_t endGamma=-64;


  if (gROOT->GetListOfSpecials()->IsEmpty()){
    cout<<"NO TCutG found \nMake a PulseShape cut first"<<endl;
    //    return;
  }


  Int_t channel=0;
  const Int_t numProjections=30;

  Double_t range=1.2;
  Double_t startPoint=-0.6;
  Double_t step =(range-startPoint)/numProjections;
  TH1D * projections[numProjections];

  TH2F * Pos_vs_TOF =new TH2F("Pos_vs_TOF","E_vs_TOF",100,startGamma,endGamma,1000,startPoint,range);
  //TH2F * E_vs_TOF =new TH2F("E_vs_TOF","E_vs_TOF",1000,-20,20,1000,0,100);


  flt->Project("Pos_vs_TOF","CorGOE:ShiftTOF",
         "channels[0]==2&&abs(CorGOE)<0.7&&channels[2]==8&&PulseShape<1.03");

  //flt->Project("E_vs_TOF","energies[1]:TOFW[1]");




  Double_t x[numProjections];
  Double_t y[numProjections];
  Double_t ex[numProjections];
  Double_t ey[numProjections];


  std::stringstream s;
  for (int i=0;i<numProjections;i++){
    Int_t bin1 = Pos_vs_TOF->GetYaxis()->FindBin(startPoint +i*step);
    Int_t bin2 = Pos_vs_TOF->GetYaxis()->FindBin(startPoint+ (i+1)*step);
    ///     Int_t bin2 = channel[j]->GetYaxis()->FindBin(600);
    x[i]=startPoint+i*step;
    ex[i]=0;
    
    s<<"chan"<<channel<<"_px"<<startPoint+i*step<<"_"<<startPoint+(i+1)*step;
    
    projections[i]=Pos_vs_TOF->ProjectionX(s.str().c_str(),bin1,bin2);
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
