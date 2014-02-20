
#include <iostream>
#include <string>
#include <fstream>
#include <TH1F.h>
#include <TH1D.h>
using namespace std;

double GetValue(TFitResultPtr thePtr,double x){
  
  double total=0;
  for (int i=0;i<thePtr->NFreeParameters();i++){
    total=total+ thePtr->Value(i)*TMath::Power(x,i);
  }
  return total;
}

void NormalizeEff(TH1F * theEspectrum){
  TDirectory *cur = gDirectory;
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


  TH1F * CalculatedLiqEff = new TH1F("CalculatedLiqEff","",500,0,10);
  TH1F * CalcESpec = new TH1F("CalcESpec","",500,0,10);
  TH1F * YieldShape = new TH1F("YieldShape","",500,0,10);
 

  ifstream theEffFile;
  theEffFile.open("/user/lipschut/LiqScintEffThresh_595_newBin");
  if ( ! theEffFile.is_open() ){
    cout<<"No Eff file"<<endl;
    return;
  }
  double val1,trash;
  for (int i=0;i<500;i++){
    val1=-1;
    theEffFile>>trash>>val1;
    CalculatedLiqEff->SetBinContent(i+1,val1);
    if (val1!=0&&i>30)
      YieldShape->SetBinContent(i+1,theEspectrum->GetBinContent(i+1)/val1);
    //    cout<<val1<<endl;
  }

  YieldShape->SetDirectory(0);
  YieldShape->Draw();
  
  Float_t bins[71];

  bins[0]=x[0]-ex[0];//first bin is left side of bin
  for (int i=1;i<70;i++){
    bins[i] = x[i]-ex[i];
  }
  bins[70]=x[70]+ex[70];//last bin to the right side of last bin

  
  TH1F * Yield=new TH1F("Yield","",70,bins);

  //  eff->SetDirectory(0);
  //  Yield->SetDirectory(0);




  TH1D * N2=new TH1D("N2","",200,0,20);
  for(int i=0;i<71;i++){
    //    cout<<h->GetBinLowEdge(i+1)<<" "<<h->GetBinWidth(i+1)+h->GetBinLowEdge(i+1)<<endl;
    //    Yield->SetBinContent(i+1,y[i]*Yield->GetBinWidth(i+1));
    Yield->SetBinContent(i+1,y[i]);
   }
  TCanvas * c = new TCanvas();
  c->cd(1);
  Yield->Draw();
  TF1 * f = new TF1("f","[0]+x*[1]+[2]*x^2+[3]*x^3+[4]*x^4+[5]*x^5+[6]*x^6+[7]*x^7+[8]*x^8+[9]*x^9+[10]*x^10+[11]*x^11+[12]*x^12",0,12);
  TFitResultPtr result =Yield->Fit("pol9","SQR","",0,12);



  for (int i=1;i<=500;i++){
 
    Double_t spot=CalculatedLiqEff->GetBinCenter(i);
    Double_t asdf=GetValue(result,spot)*CalculatedLiqEff->GetBinContent(i);;
    CalcESpec->SetBinContent(i,asdf);
  }
  CalcESpec->Scale(100);
  CalcESpec->Draw();
  return;
  double LowEnergyCut=1;
  double HighEnergyCut=10;

  int lowBinInYield = Yield->FindBin(LowEnergyCut);
  int highBinInYield =Yield->FindBin(HighEnergyCut);
  
  int lowBinEspec = theEspectrum->FindBin(LowEnergyCut);
  int highBinEspec = theEspectrum->FindBin(HighEnergyCut);

  int lowBinEff = CalculatedLiqEff->FindBin(LowEnergyCut);
  int highBinEff = CalculatedLiqEff->FindBin(HighEnergyCut);

  cout<<"lowBinEspec "<<lowBinEspec<<endl;
  cout<<"highBinEspec "<<highBinEspec<<endl;
  
  cout<<"lowBinEff "<<lowBinEff<<endl;
  cout<<"highBinEff "<<highBinEff<<endl;
  
  cout<<"lowBinInYield "<<lowBinInYield<<endl;
  cout<<"highBinYield "<<highBinInYield<<endl;

  double TotalInYeild=0;
  for (int i=lowBinInYield;i<highBinInYield;i++){
    TotalInYeild=TotalInYeild+Yield->GetBinContent(i);
  }
  
  double GeoFactor=0.00015953;
  double MeassuredYield=0;
  for (int i=lowBinEspec;i<highBinEspec;i++){
    if ( CalculatedLiqEff->GetBinContent(i)!=0 ){
      MeassuredYield=MeassuredYield+theEspectrum->GetBinContent(i)/
	(CalculatedLiqEff->GetBinContent(i)*GeoFactor);
    }
  }

  cout<<"Meassured Yield "<<MeassuredYield<<endl;
  cout<<"TotalInYeild"<<TotalInYeild<<endl;
  double scaleFactor = MeassuredYield/TotalInYeild;
  cout<<"theScale Factor is "<<scaleFactor<<endl;
  
  TH1F * TrueYield = new TH1F(*Yield);
  TrueYield->Scale(scaleFactor);
  TFile f("TrueYield.root","recreate");
  TrueYield->Write();
  f.Close();
  cur->cd();
  return;
}

