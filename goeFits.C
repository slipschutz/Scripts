
#include "TH2F.h"
#include "TTree.h"
#include "TFile.h"
#include "TFitResultPtr.h"
#include "TFitResult.h"
#include "TGraph.h"
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

TGraphErrors * goeFits(TH2F *h){

  Int_t const num=20;
  
  TH1D * projections[num];


  //GOE goes from -0.6 to 0.6 split into num divisions
  Double_t Range=.6;
  Double_t startPoint=-Range/2;
  Double_t step= Range/num;
  cout<<startPoint<<endl;
  std::stringstream s;
  for (Int_t i=0;i<num;i++){
    Int_t bin1= h->GetYaxis()->FindBin(startPoint +i*step);
    Int_t bin2=h->GetYaxis()->FindBin(startPoint +(i+1)*step);
    std::cout<<bin1<<endl;
    std::cout<<bin2<<endl;
    std::cout<<"**"<<endl;
    s<<"_px"<<i;
    projections[i] = h->ProjectionX(s.str().c_str(),bin1,bin2);
    s.str("");
  }
  
  
  const Double_t * x = calloc(num,sizeof(Double_t));
  const Double_t * y = calloc(num,sizeof(Double_t));

  const Double_t * ex = calloc(num,sizeof(Double_t));
  const Double_t * ey = calloc(num,sizeof(Double_t));
  
  
  for (int i=0;i<num;i++){
    TFitResultPtr result = projections[i]->Fit("gaus","QSN");
    Int_t status = result;///OMG root
    if (status==0){
      
      y[i]=result->Value(1);
      x[i]=startPoint + (i+0.5)*step;
      
      ey[i]=result->UpperError(1);
      ex[i]=0;
      cout<<x[i]<<"  "<<y[i]<<"   "<<result->UpperError(1)<<endl;
    }
  }


  TGraphErrors * gr = new TGraphErrors(num,x,y,ex,ey);
  gr->GetXaxis()->SetTitle("Position on bar");
  gr->GetYaxis()->SetTitle("Centriod of Timing Peak");


  TCanvas *c=new TCanvas();
  c->cd();
  gr->Draw("AL");

  return gr;
}

