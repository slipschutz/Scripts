


TGraphErrors* TOF_res(){


  Double_t startGamma=4.5;
  Double_t endGamma=5.5;

  const Int_t numProjections=40;
 
  Double_t range=200;
  Double_t startPoint=0;
  Double_t step =(range-startPoint)/numProjections;
  TH1D * projections[numProjections];
  TH1D * projectionsOrig[numProjections];

  Double_t cutE=0;



  LendaEvent * Event = new LendaEvent();
  
  flt->SetBranchAddress("Event",&Event);
  
  Int_t numEntries = flt->GetEntries();
  
  std::stringstream s;
  
  for (int j=0;j<numProjections;j++){

    
    cutE = startPoint + j*step;
    cout<<"On "<<cutE<<endl;
    s<<"E_"<<startPoint+j*step;

    projections[j]=new TH1D(s.str().c_str(),"TOF",1000,-20,20);
    s.str("");
    s<<"OrigE_"<<cutE;
    projectionsOrig[j]=new TH1D(s.str().c_str(),"TOF",1000,-20,20);
    s.str("");
    for (int I=0;I<numEntries;I++){
      
      flt->GetEntry(I);
      
      if ( Event->channels[0] ==2 && Event->channels[2]==8 && TMath::Abs(Event->CorGOE)<0.5 && (Event->PulseShape)<1.04){
	
	if (Event->energiesCor[0]>= cutE && Event->energiesCor[1]>=cutE){
	  
	  projections[j]->Fill(Event->TOFW[0]);
	  projectionsOrig[j]->Fill(Event->ShiftTOF);
	}
	
      }
      
    }
    
  }


  Double_t x[numProjections];
  Double_t y[numProjections];
  Double_t ex[numProjections];
  Double_t ey[numProjections];

  Double_t x1[numProjections];
  Double_t y1[numProjections];
  Double_t ex1[numProjections];
  Double_t ey1[numProjections];

  for (int i=0;i<numProjections;i++){
    x[i]=startPoint + i*step;
    x1[i]=startPoint + i*step;
    ex[i]=0;
    ex1[i]=0;
    y[i]=y1[i]=ey[i]=ey1[i]=0;
  }

  TF1 *f1 = new TF1("f1","gaus",startGamma,endGamma);
  
  TFitResultPtr result;
  for(int i=0;i<numProjections;i++){
    result = projections[i]->Fit("f1","QSNR");
    Int_t status=result;
    if (status==0){
      y[i]=result->Value(2)*2.35*10000;
      ey[i]=result->UpperError(2)*2.35*10000;
    } else {
      y[i]=0;
      ey[i]=0;
    }

    result = projectionsOrig[i]->Fit("f1","QSNR");
    status=result;
    if (status==0){
      y1[i]=result->Value(2)*2.35*10000;
      ey1[i]=result->UpperError(2)*2.35*10000;
    } else {
      y1[i]=0;
      ey1[i]=0;
    }

  }

  TGraphErrors *gr =new TGraphErrors(numProjections,x,y,ex,ey);
  TGraphErrors *grOrig =new TGraphErrors(numProjections,x1,y1,ex1,ey1);
  
  grOrig->SetLineColor(2);
  
  TCanvas *c = new TCanvas("c22");

  c->cd(1);
  gr->Draw("AL*");
  grOrig->Draw("same");
  return gr;
  
}
/*







  if (gROOT->GetListOfSpecials()->IsEmpty()){
    cout<<"NO TCutG found \nMake a PulseShape cut first"<<endl;
    return;
  }

  TH2F * E_vs_TOF =new TH2F("E_vs_TOF","E_vs_TOF",1000,-20,20,1000,0,2000);


  flt->Project("E_vs_TOF","energiesCor[0]:TOFW[1]",
	       "CUTG && channels[0]==2&&abs(ShiftTOF)<20&&abs(CorGOE)<0.5&&channels[2]==8");

  Int_t channel=0;
  const Int_t numProjections=100;

  Double_t range=600;
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
    //    Int_t bin2 = E_vs_TOF->GetYaxis()->FindBin(startPoint+ (i+1)*step);
    Int_t bin2 = E_vs_TOF->GetYaxis()->FindBin(1600);
    x[i]=startPoint+i*step;
    ex[i]=0;
    
    s<<"chan"<<channel<<"__px"<<floor(startPoint+i*step);
    
    projections[i]=E_vs_TOF->ProjectionX(s.str().c_str(),bin1,bin2);
    projections[i]->SetTitle("TOF");
    s.str("");
  }



    
    //    cout<<x[i]<<" "<<ex[i]<<endl;

  }






  return gr;

}
*/
