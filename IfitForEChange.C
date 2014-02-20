

#include <fstream>
#include "TMinuit.h"

#include <map>

Float_t *x;
Float_t *y;
Float_t *errory;

std::map <Double_t,Double_t> theFunction;

void defineTheFunctions(TH1F* fixedHistoGram,TH1F* histogramToVary){

  int NumOfBins = fixedHistoGram->GetNbinsX();
  if (NumOfBins != histogramToVary->GetNbinsX() ){
    cout<<"Bins must be the same"<<endl;
  }
  NumOfBins=10;
  x = (Float_t*)calloc(sizeof(Float_t),NumOfBins);
  y = (Float_t*)calloc(sizeof(Float_t),NumOfBins);
  errory = (Float_t*)calloc(sizeof(Float_t),NumOfBins);
  for (int i=0;i<NumOfBins;i++){
    x[i]= fixedHistoGram->GetBinCenter(i+1);
    y[i]=fixedHistoGram->GetBinContent(i+1);
    errory[i]=0.001;
    theFunction[x[i]]=histogramToVary->GetBinContent(i+1);
  }

}

//______________________________________________________________________________
Double_t func(float x,Double_t *par)
{
  if (theFunction.find(x) != theFunction.end() ){
    
    Double_t value = theFunction[x]*par[0]+par[1];
    return value;
  } else {
    cout<<"CRAP"<<endl;
    return -100;
  }
}

//______________________________________________________________________________
void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{
   const Int_t nbins = 6;
   Int_t i;

//calculate chisquare
   Double_t chisq = 0;
   Double_t delta;
   for (i=0;i<nbins; i++) {
     delta  = (y[i]-func(x[i],par))/errory[i];
     chisq += delta*delta;
   }
   f = chisq;
}

//______________________________________________________________________________
void IfitForEChange(TH1F* fixedHistoGram,TH1F* histogramToVary)
{

  defineTheFunctions(fixedHistoGram,histogramToVary);



 
 
 TMinuit *gMinuit = new TMinuit(5);  //initialize TMinuit with a maximum of 5 params
 gMinuit->SetFCN(fcn);
 
 Double_t arglist[10];
 Int_t ierflg = 0;
 
 arglist[0] = 1;
 // gMinuit->mnexcm("SET ERR", arglist ,1,ierflg);
 
 // Set starting values and step sizes for parameters
 static Double_t vstart[4] = {1, 1 , 0.1 , 0.01};
 static Double_t step[4] = {0.001 , 0.001 , 0.01 , 0.001};
 gMinuit->mnparm(0, "a1", vstart[0], step[0], 0,0,ierflg);
 gMinuit->mnparm(1, "a2", vstart[1], step[1], 0,0,ierflg);
 
 
 // Now ready for minimization step
 arglist[0] = 500;
 arglist[1] = 1.;
 gMinuit->mnexcm("MIGRAD", arglist ,2,ierflg);
 
 // Print results
 Double_t amin,edm,errdef;
 Int_t nvpar,nparx,icstat;
 // gMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
 //gMinuit->mnprin(3,amin);
 
}

