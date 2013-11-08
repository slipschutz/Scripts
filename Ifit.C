

#include <fstream>
#include "TMinuit.h"

#include <map>


Float_t x[6],y[6],errory[6];
std::map <Double_t,Double_t> theFunction;
int GetLeftIndex(double xVal,vector<double> vec){
  
  int spot=-1;
  for (int i=0;i<vec.size();i++){
    if (vec[i]>=xVal){
      spot=i;
      i=vec.size()+100;
    }
  }
  return spot-1;

}

void defineTheFunction(){
  
  ifstream file;
  file.open("/user/lipschut/RCNP/CalcIAS");

  if (!file.is_open()){
    cout<<"SDSGSDGSGSG"<<endl;
    return;
  }
  
  double t1 ,t2;

  vector <double> CalcX;
  vector <double> CalcY;

  int count=0;


  while (! file.eof()){
    file>>t1>>t2;
    
    
    CalcX.push_back(t1*(3.141592/180)*1000);
    CalcY.push_back(t2);
    cout<<CalcX[count]<<"  "<<CalcY[count]<<endl;
    count++;
  }


  for (int i=0;i<6;i++){
    
    int ind =GetLeftIndex(x[i],CalcX);
    cout<<"ind is "<<ind<<endl;
    double m= (CalcY[ind+1]-CalcY[ind])/(CalcX[ind+1]-CalcX[ind]);
    double b=CalcY[ind]-m*CalcX[ind];
    
    double interpolatedY=m*x[i]+b;
    
    cout<<CalcY[ind]<<"  "<<interpolatedY<<" "<<CalcY[ind+1]<<endl;

    theFunction[x[i]]=interpolatedY;
    
  }
  


}

//______________________________________________________________________________
Double_t func(float x,Double_t *par)
{
  if (theFunction.find(x) != theFunction.end() ){
    
    Double_t value = theFunction[x]*par[0];
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
void Ifit()
{


 x[0]=3.25;
 x[1]=9.75;
 x[2]=16.25;
 x[3]=22.75;
 x[4]=29.25;
 x[5]=35.75;

// the y values

 y[0]= 9.5519;
 y[1]=8.20475;
 y[2]= 6.34345;
 y[3]= 4.19135;
 y[4]= 2.2719;
 y[5]= 1.22845;

 errory[0]= 0.0817;
 errory[1]=0.0519;
 errory[2]= 0.0398;
 errory[3]= 0.036;
 errory[4]=0.0368;
 errory[5]= 0.1049;;

 defineTheFunction();

 
 
 TMinuit *gMinuit = new TMinuit(5);  //initialize TMinuit with a maximum of 5 params
 gMinuit->SetFCN(fcn);
 
 Double_t arglist[10];
 Int_t ierflg = 0;
 
 arglist[0] = 1;
 gMinuit->mnexcm("SET ERR", arglist ,1,ierflg);
 
 // Set starting values and step sizes for parameters
 static Double_t vstart[4] = {1, 1 , 0.1 , 0.01};
 static Double_t step[4] = {0.1 , 0.1 , 0.01 , 0.001};
 gMinuit->mnparm(0, "a1", vstart[0], step[0], 0,0,ierflg);
 
 
 // Now ready for minimization step
 arglist[0] = 500;
 arglist[1] = 1.;
 gMinuit->mnexcm("MIGRAD", arglist ,2,ierflg);
 
 // Print results
 Double_t amin,edm,errdef;
 Int_t nvpar,nparx,icstat;
 gMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
 //gMinuit->mnprin(3,amin);
 
}

