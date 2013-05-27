

#include <iomanip>
#include <iostream>
#include <vector>
#include "TTree.h"

#include "TFile.h"



using namespace std;



int temp()
{

  gSystem->Load("../ddasChannel/libddaschannel-m64.so");
  ddaschannel *chan = new ddaschannel();

  TFile *inFile = new TFile("./run-0319-00.root");
  
  TTree * t = (TTree*) inFile->Get("dchan");


  t->SetBranchAddress("dchan",&chan);



  
  ofstream out("./remco.txt");
  
  



  for (int i=0;i<1000000;i++){
    dchan->GetEntry(i);

    double time = chan->timelow + chan->timehigh*TMath::Power(2,32.0);
    double time2 = chan->timecfd/TMath::Power(2,16.0);
    //    out<<chan->chanid<<"  "<<setw(6)<<chan->energy<<"  "<<setw(13)<<setprecision(8)<<time<<"  "<<time2<<endl;
    out<<chan->chanid<<" "<<chan->energy<<" "<<setprecision(16)<<time<<" "<<time2<<endl;
    
    //    cout<<chan->chanid<<"   "<<setprecision(16)<<chan->time<<"   ";
    // dchan->GetEntry(i-1);
    // cout<<time-chan->time<<endl;
      
  }


  

  return 0;

}
