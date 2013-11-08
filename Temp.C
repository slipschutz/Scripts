

void Temp(){


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
  double fudge =1.0;
  Double_t thresh=0;
  stringstream ss112;
  ss112<<"softwareCFDs[0]>0 &&softwareCFDs[1]>0&softwareCFDs[2]>0&&NumOfChannelsInEvent==3 && channels[0]==0 && channels[2]==9 &&longGates[2]/shortGates[2]<1.12&&ShiftTOF>1.5&&sqrt(energies[0]*energies[1])>"<<thresh;

  
  
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
  TFile frun354bkg("~/analysis/run354/CoRFL3FG0d3w0run-0354-twrandom100-softwareCFD.root");
  TH1D * RandomBackGround354WithInternalTimes = new TH1D("RandomBackGround354WithInternalTimes","",70,bins);
  flt->Project("RandomBackGround354WithInternalTimes","TOFEnergyInternal",ss112.str().c_str());

  TH1D * RandomBackGround354WithCubicTimes = new TH1D("RandomBackGround354WithCubicTimes","",70,bins);
  flt->Project("RandomBackGround354WithCubicTimes","TOFEnergy",ss112.str().c_str());

  RandomBackGround354WithInternalTimes->SetDirectory(0);
  RandomBackGround354WithCubicTimes->SetDirectory(0);


  TFile frun354bkg2("~/analysis/run354/CoRFL3FG0d3w0run-0354-twrandom1000-softwareCFD.root");
  TH1D * RandomBackGround354WithInternalTimes2 = new TH1D("RandomBackGround354WithInternalTimes2","",70,bins);
  flt->Project("RandomBackGround354WithInternalTimes2","TOFEnergyInternal",ss112.str().c_str());

  TH1D * RandomBackGround354WithCubicTimes2 = new TH1D("RandomBackGround354WithCubicTimes2","",70,bins);
  flt->Project("RandomBackGround354WithCubicTimes2","TOFEnergy",ss112.str().c_str());

  RandomBackGround354WithInternalTimes2->SetDirectory(0);
  RandomBackGround354WithCubicTimes2->SetDirectory(0);
  
  for (int i=1;i<=70;i++){
    cout<< sqrt(RandomBackGround354WithCubicTimes->GetBinContent(i))<<"  ";
    cout<< sqrt(RandomBackGround354WithCubicTimes2->GetBinContent(i))/10.0<<endl;
    
    RandomBackGround354WithCubicTimes2->SetBinContent(i,RandomBackGround354WithCubicTimes2->GetBinContent(i)/10.0);
  }


  TCanvas *c=new TCanvas("C");
  c->Divide(1,2);
  c->cd(1);
  RandomBackGround354WithCubicTimes->Draw("E1");
  c->cd(2);
  RandomBackGround354WithCubicTimes2->Draw("E1");

}
