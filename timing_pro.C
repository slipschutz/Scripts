


int timing_pro(){



  TH2F *channel[4];
  std::stringstream name;
  std::stringstream line;
  for (int i=0;i<4;i++){
    name.str(""); line.str("");
    name<<"ch"<<i;
    line<<"Integral"<<i<<"_cor:Time_Diff";
    channel[i]= new TH2F(name.str().c_str(),"",100,10.5,11.5,100,0,600);
    flt->Project(name.str().c_str(),line.str().c_str());
  }

  
  const Int_t numProjections=30;
  Double_t range=350;
  Double_t startPoint=50;
  Double_t step =(range-startPoint)/numProjections;
  TH1D * projections[4][numProjections];

  std::stringstream s;
  for (int j=0;j<4;j++){
    for (int i=0;i<numProjections;i++){
      Int_t bin1 = channel[j]->GetYaxis()->FindBin(startPoint +i*step);
      Int_t bin2 = channel[j]->GetYaxis()->FindBin(startPoint +(i+1)*step);
      ///     Int_t bin2 = channel[j]->GetYaxis()->FindBin(600);
      s<<"chan"<<j<<"__px"<<startPoint+i*step<<"_"<<startPoint+(i+1)*step;
      
      projections[j][i]=channel[j]->ProjectionX(s.str().c_str(),bin1,bin2);
      s.str("");
    }
  }

  Double_t points[3][4][numProjections];
  int k=0;
  
  
  for (int j=0;j<4;j++){
    for (int i=0;i<numProjections;i++){
      TFitResultPtr result = projections[j][i]->Fit("gaus","QSN");
      Int_t status = result;///OMG root
      if (status==0){
	points[k][0][i]=((startPoint+i*step)+(startPoint+(i+1)*step))/2.0;
	points[k][1][i]=result->Value(2)*10000*2.35/TMath::Sqrt(2);
	points[k][2][i]=0;//ex is always 0
	points[k][3][i]=result->UpperError(2)*10000*2.35/TMath::Sqrt(2);//ey from fit
	
      }
    }
    TGraphErrors *gr = new TGraphErrors(numProjections,points[k][0],points[k][1],points[k][2],points[k][3]);
    gr->SetLineColor(j+1);
    if (j==0)
      gr->Draw("AL");
    else
      gr->Draw("same");
  }
  
  return 0;

}
