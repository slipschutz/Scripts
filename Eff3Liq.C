
#include <vector>
#include <utility>

//Eff2 is for taking the points from a histogram instead of a tree

void Eff3Liq(TH1F * hN=0){

  Double_t x[71]={0.0075000,
		  0.0250000,
		  0.0450000,
		  0.0650000,
		  0.0850000,
		  0.1050000,
		  0.1250000,
		  0.1500000,
		  0.1800000,
		  0.2100000,
		  0.2400000,
		  0.2800000,
		  0.3300000,
		  0.3800000,
		  0.4300000,
		  0.4800000,
		  0.5300000,
		  0.5800000,
		  0.6300000,
		  0.6800000,
		  0.7300000,
		  0.7800000,
		  0.8300000,
		  0.8800000,
		  0.9300000,
		  1.0025000,
		  1.1000000,
		  1.2000000,
		  1.3000000,
		  1.4000000,
		  1.5000000,
		  1.6000000,
		  1.7000000,
		  1.8000000,
		  1.9000000,
		  2.0500000,
		  2.2500000,
		  2.4500000,
		  2.6500000,
		  2.8500000,
		  3.1000000,
		  3.4000000,
		  3.7000000,
		  4.0000000,
		  4.3000000,
		  4.6000000,
		  4.9000000,
		  5.3000000,
		  5.8000000,
		  6.3000000,
		  6.8000000,
		  7.3000000,
		  7.8000000,
		  8.3000000,
		  8.8000000,
		  9.3000000,
		  9.8000000,
		  10.3000000,
		  10.8000000,
		  11.3000000,
		  11.8000000,
		  12.3000000,
		  12.8000000,
		  13.3000000,
		  13.8000000,
		  14.3250000,
		  15.2500000,
		  16.4000000,
		  17.4000000,
		  18.5000000,
		  19.5500000};
  Double_t ex[71] = {0.0075000,
		     0.0100000,
		     0.0100000,
		     0.0100000,
		     0.0100000,
		     0.0100000,
		     0.0100000,
		     0.0150000,
		     0.0150000,
		     0.0150000,
		     0.0150000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0250000,
		     0.0475000,
		     0.0500000,
		     0.0500000,
		     0.0500000,
		     0.0500000,
		     0.0500000,
		     0.0500000,
		     0.0500000,
		     0.0500000,
		     0.0500000,
		     0.1000000,
		     0.1000000,
		     0.1000000,
		     0.1000000,
		     0.1000000,
		     0.1500000,
		     0.1500000,
		     0.1500000,
		     0.1500000,
		     0.1500000,
		     0.1500000,
		     0.1500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2500000,
		     0.2750000,
		     0.6500000,
		     0.5000000,
		     0.5000000,
		     0.6000000,
		     0.4500000};
  Double_t y[71] ={5.1405333e-02,
		   9.8349500e-02,
		   1.3175000e-01,
		   1.5643750e-01,
		   1.7663350e-01,
		   1.9363550e-01,
		   2.0850400e-01,
		   2.2458900e-01,
		   2.4100000e-01,
		   2.5523733e-01,
		   2.6748400e-01,
		   2.8124000e-01,
		   2.9507200e-01,
		   3.0641600e-01,
		   3.1503400e-01,
		   3.2242800e-01,
		   3.2723000e-01,
		   3.3126800e-01,
		   3.3392000e-01,
		   3.3561000e-01,
		   3.3608000e-01,
		   3.3571400e-01,
		   3.3533800e-01,
		   3.3394000e-01,
		   3.3184000e-01,
		   3.2844632e-01,
		   3.2205000e-01,
		   3.1490200e-01,
		   3.0596700e-01,
		   2.9673300e-01,
		   2.8734700e-01,
		   2.7704000e-01,
		   2.6658000e-01,
		   2.5612000e-01,
		   2.4566000e-01,
		   2.3020050e-01,
		   2.1007500e-01,
		   1.9050950e-01,
		   1.7230650e-01,
		   1.5540000e-01,
		   1.3587233e-01,
		   1.1480600e-01,
		   9.6560667e-02,
		   8.0777667e-02,
		   6.7334333e-02,
		   5.5928667e-02,
		   4.6381333e-02,
		   3.6111800e-02,
		   2.6234400e-02,
		   1.8971620e-02,
		   1.3666760e-02,
		   9.8124400e-03,
		   7.0360200e-03,
		   5.0407600e-03,
		   3.6132800e-03,
		   2.5885200e-03,
		   1.8538120e-03,
		   1.3248120e-03,
		   9.4736800e-04,
		   6.7701400e-04,
		   4.8375800e-04,
		   3.4512600e-04,
		   2.4605200e-04,
		   1.7495000e-04,
		   1.2437880e-04,
		   8.6900727e-05,
		   4.8199615e-05,
		   2.1518400e-05,
		   1.0859600e-05,
		   5.0966000e-06,
		   2.4220667e-06};
  
  Float_t bins[71];

  bins[0]=x[0]-ex[0];//first bin is left side of bin
  for (int i=1;i<70;i++){
    bins[i] = x[i]-ex[i];
  }
  bins[70]=x[70]+ex[70];//last bin to the right side of last bin

  
  TH1F * Yield=new TH1F("Yield","",70,bins);
  TH1F * eff=new TH1F("eff","",70,bins);
  eff->SetDirectory(0);
  Yield->SetDirectory(0);


  TH1D * N2=new TH1D("N2","",200,0,20);
  for(int i=0;i<71;i++){
    //    cout<<h->GetBinLowEdge(i+1)<<" "<<h->GetBinWidth(i+1)+h->GetBinLowEdge(i+1)<<endl;
    Yield->SetBinContent(i+1,y[i]*Yield->GetBinWidth(i+1));
   }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //  Doule_t thresh =53.73; // 26.3 KeV 
  double fudge =10.0;
  Double_t thresh=0;
  stringstream ss112;
  ss112<<"softwareCFDs[0]>0 &&softwareCFDs[1]>0&&NumOfChannelsInEvent==2 && channels[0]==8 && channels[1]==9 &&longGates[1]/shortGates[1]<1.12&&shortGates[1]>200&&ShiftTOFInternal>1.5&&ShiftTOFInternal<100&&sqrt(energies[0]*energies[1])>"<<thresh;

  
  
  //  flt->Draw("TOFEnergy","channels[0]==0&&softwareCFDs[0]>0&&softwareCFDs[1]>0&&softwareCFDs[2]>0&&NumOfChannelsInEvent==3&&channels[2]==9&&longGates[2]/shortGates[2]<1.12&&ShiftTOF>2")


  cout<<gDirectory->GetName()<<endl;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TFile frun354("~/analysis/run354/CoRFL3FG0d3w0run-0354-tw100-softwareCFD.root");
  TH1D * NWithCubicTimes=new TH1D("NWithCubicTimes","",70,bins);
  TH1D * NWithInternalTimes=new TH1D("NWithInternalTimes","",70,bins);


  //  flt->Project("N","TOFEnergy","ErrorBit==0 && NumOfChannelsInEvent==3 && channels[0]==0 && channels[2]==9 &&PulseShape<1.12&&sqrt(energies[0]*energies[1])>53.73");
  flt->Project("NWithCubicTimes","TOFEnergy",ss112.str().c_str());
  flt->Project("NWithInternalTimes","TOFEnergyInternal",ss112.str().c_str());
  NWithCubicTimes->SetDirectory(0);
  NWithInternalTimes->SetDirectory(0);
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TFile frun354bkg("~/analysis/run354/CoRFL3FG0d3w0run-0354-twrandom1000-softwareCFD.root");
  TH1D * RandomBackGround354WithInternalTimes = new TH1D("RandomBackGround354WithInternalTimes","",70,bins);
  flt->Project("RandomBackGround354WithInternalTimes","TOFEnergyInternal",ss112.str().c_str());

  TH1D * RandomBackGround354WithCubicTimes = new TH1D("RandomBackGround354WithCubicTimes","",70,bins);
  flt->Project("RandomBackGround354WithCubicTimes","TOFEnergy",ss112.str().c_str());

  RandomBackGround354WithInternalTimes->SetDirectory(0);
  RandomBackGround354WithCubicTimes->SetDirectory(0);


  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TFile frun355("~/analysis/run358/CoRrun-0358-LG17-SG7.root");
  TH1D * ShadowBarRun=new TH1D("ShadowBarRun","",70,bins);
  TH1D * ShadowBarRunInternalTimes=new TH1D("ShadowBarRunInternalTimes","",70,bins);
  
  flt->Project("ShadowBarRun","TOFEnergy",ss112.str().c_str());
  flt->Project("ShadowBarRunInternalTimes","TOFEnergyInternal",ss112.str().c_str());

  ShadowBarRun->SetDirectory(0);
  ShadowBarRunInternalTimes->SetDirectory(0);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  TFile frun355bkg("~/analysis/run999/CoRrun-0999-tw1000random-softwareCFD-output.root");
  TH1D * ShadowBarRandomBackGround = new TH1D("ShadowBarRandomBackGround","",70,bins);
  flt->Project("ShadowBarRandomBackGround","TOFEnergy",ss112.str().c_str());
  ShadowBarRandomBackGround->SetDirectory(0);

  TH1D * ShadowBarRandomBackGroundInternal = new TH1D("ShadowBarRandomBackGroundInternal","",70,bins);
  flt->Project("ShadowBarRandomBackGroundInternal","TOFEnergyInternal",ss112.str().c_str());
  ShadowBarRandomBackGroundInternal->SetDirectory(0);

  TH1F * hresult= new TH1F ("hresult","",70,bins);
  TH1F * shadowBarSubtracted= new TH1F ("shadowBarSubtracted","",70,bins);
  TH1F * NSubtracted= new TH1F ("NSubtracted","",70,bins);

  Double_t errors[71];
  Double_t errorsNB[71];
  Double_t errorNsub[71];
  Double_t errorShadowSub[71];

  errors[0]=0;
  errorsNB[0]=0;
  errorNsub[0]=0;
  errorShadowSub[0]=0;

  for (int i=1;i<=70;i++){
    Double_t nV, bkgV, bkg355V, bkg354V;
    //cubicTimes
    /*  
    nV= NWithCubicTimes->GetBinContent(i); //data run
    bkgV=ShadowBarRun->GetBinContent( i);//shadow bar run
    bkg355V =ShadowBarRandomBackGround->GetBinContent(i);//random coin build shadow bar
    bkg354V = RandomBackGround354WithCubicTimes->GetBinContent(i);//random coin build normal run
    
*/
    
    //Internal times
    nV= NWithInternalTimes->GetBinContent(i); //data run
    bkgV=ShadowBarRunInternalTimes->GetBinContent( i);//shadow bar run
    bkg355V =ShadowBarRandomBackGroundInternal->GetBinContent(i);//random coin build shadow bar
    bkg354V = RandomBackGround354WithInternalTimes->GetBinContent(i);//random coin build normal run
    



    hresult->SetBinContent(i,nV -(bkgV-(bkg355V/fudge))-(bkg354V/fudge));
    shadowBarSubtracted->SetBinContent(i,bkgV-(bkg355V/fudge));
    NSubtracted->SetBinContent(i,nV-(bkg354V/fudge));


    errorNsub[i]=sqrt( pow(sqrt(nV),2) + pow(sqrt(bkg354V)/fudge,2));
    errorShadowSub[i]=sqrt( pow(sqrt(bkgV),2)+pow(sqrt(bkg355V)/fudge,2) );
    //    errors[i]=sqrt (pow(sqrt(nV),2) + pow(sqrt(bkg354V),2)+pow(sqrt(bkgV),2) + pow(sqrt(bkg355V),2));
    errors[i]=sqrt( pow(errorNsub[i],2)+pow(errorShadowSub[i],2));
  }

  hresult->SetError(errors);
  NSubtracted->SetError(errorNsub);
  shadowBarSubtracted->SetError(errorShadowSub);
  hresult->SetDirectory(0);

  TH1F * hresultNB= new TH1F ("hresultNB","",70,bins);
  TH1F * shadowBarSubtractedNB= new TH1F ("shadowBarSubtractedNB","",70,bins);
  TH1F * NSubtractedNB= new TH1F ("NSubtractedNB","",70,bins);

  TH1D * NWithCubicTimesNB=new TH1D("NWithCubicTimesNB","",70,bins);
  TH1D * NWithInternalTimesNB=new TH1D("NWithInternalTimesNB","",70,bins);

  TH1D * RandomBackGround354WithInternalTimesNB = new TH1D("RandomBackGround354WithInternalTimesNB","",70,bins);
  TH1D * RandomBackGround354WithCubicTimesNB = new TH1D("RandomBackGround354WithCubicTimesNB","",70,bins);
  
  for (int i=1;i<=70;i++){
    hresultNB->SetBinContent(i,hresult->GetBinContent(i)/(hresult->GetBinWidth(i)));
    errorsNB[i]=errors[i]/(hresult->GetBinWidth(i));

    shadowBarSubtractedNB->SetBinContent(i,shadowBarSubtracted->GetBinContent(i)/(shadowBarSubtracted->GetBinWidth(i)));
    errorShadowSub[i]=errorShadowSub[i]/(shadowBarSubtracted->GetBinWidth(i));

    NSubtractedNB->SetBinContent(i,NSubtracted->GetBinContent(i)/(NSubtracted->GetBinWidth(i)));
    errorNsub[i]=errorNsub[i]/(NSubtracted->GetBinWidth(i));
    
    NWithInternalTimesNB->SetBinContent(i,NWithInternalTimes->GetBinContent(i)/NWithInternalTimes->GetBinWidth(i));
    NWithCubicTimesNB->SetBinContent(i,NWithCubicTimes->GetBinContent(i)/NWithCubicTimes->GetBinWidth(i));

    //    RandomBackGround354WithInternalTimesNB->

  }
  hresultNB->SetError(errorsNB);
  NSubtractedNB->SetError(errorNsub);
  shadowBarSubtractedNB->SetError(errorShadowSub);


  /*
  Int_t numEntries = hN->GetNbinsX();
  
  cout<<"NNNNNN "<<numEntries<<endl;

  Double_t time=0;

  Double_t c= 2.99 * TMath::Power(10,8);

  for (int i=1;i<=numEntries;i++){
    
    time = hN->GetBinCenter(i);
    double shiftTime = time*10.0 -(40.6651-3.3444);
    if (time >3){

      time = shiftTime*(1.0/(TMath::Power(10,9)));// put time in secs

      Double_t beta = (1.0/c)*(1.0/time);
      Double_t gamma = 1.0/(TMath::Sqrt(1-beta*beta));
      Double_t KE = (gamma-1)*939.5650; // MEV
      

      // cout<<"time is "<<time<<endl;
      //	    cout<<"Ke is "<<KE<<endl;
      
      //      int bin= N->GetXaxis()->FindBin((Double_t)KE);
      // N->SetBinContent(bin,);
      int bin =N->FindBin((Double_t)KE);
      N->SetBinContent(bin,hN->GetBinContent(i)+N->GetBinContent(bin));
    }
  }*/

 
  
  for (int i=0;i<71;i++){
    eff->SetBinContent(i+1,Double_t((hresult->GetBinContent(i+1)))/(Yield->GetBinContent(i+1)));
    if (i!=70)
      errors[i+1]=errors[i+1]/Yield->GetBinContent(i+1);

  }
  eff->SetError(errors);
  TCanvas * cC = new TCanvas("c");
  cC->cd(1);
  eff->Draw();

  TFile f("EffoutLiq.root","recreate");
  eff->Write();
  hresult->Write();
  NWithCubicTimes->Write();
  NWithInternalTimes->Write();

  NWithCubicTimesNB->Write();
  NWithInternalTimesNB->Write();

  ShadowBarRun->Write();
  ShadowBarRunInternalTimes->Write();
  ShadowBarRandomBackGround->Write();

  RandomBackGround354WithCubicTimes->Write();
  RandomBackGround354WithInternalTimes->Write();

  shadowBarSubtractedNB->Write();
  NSubtractedNB->Write();
  hresultNB->Write();

  Yield->Write();
  shadowBarSubtracted->Write();
  NSubtracted->Write();

  f.Close();

}
