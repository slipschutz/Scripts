#include "TTree.h"
#include <stdlib.h>

#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include <TRandom1.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "TRandom3.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TGraph.h"
#include "TChain.h"



using namespace std;

struct event {

  Double_t long_gate;
  Double_t short_gate;
  Double_t time;
  Int_t channel;

};



bool checkChannels(vector <event> &events){

  bool ch[10];
  for (int i=0;i<10;i++)
    ch[i]=false;
  for (int i=0;i<events.size();i++){
    ch[events[i].channel]=true;    
  }

  if (ch[8]==true){
    if (ch[0]==true && ch[1] == true){
      return true;
    } else if (ch[2] == true && ch[3] == true){
      return true;
    }
    else {
      return false;
    }
  } else {
    return false;
  }


}

void FastFilter(std::vector <UShort_t> &trace,std::vector <Double_t> 
&thisEventsFF,Double_t FL,Double_t FG){

  Double_t sumNum1=0;
  Double_t sumNum2=0;
  
  
  for (int i=0;i< (int) trace.size();i++)
    {
      for (int j= i-(FL-1) ;j<i;j++)
	{
	  if (j>=0)
	    sumNum1 = sumNum1+ trace[j];
	}

      for (int j=i-(2*FL+FG-1);j<i-(FL+FG);j++)
	{
	  if (j>=0)
	    sumNum2 = sumNum2+ trace[j];
	}
      thisEventsFF.push_back(sumNum1-sumNum2);
      sumNum1=0;
      sumNum2=0;
    }//End for    
}

Int_t spot(vector <Double_t> &ff){
  Int_t spot=-1;
  for (int i=30;i<ff.size();++i){
    if (ff[i] > 0 && ff[i+1]<0 && ff[i]-ff[i+1]>10){
      spot =i;
      break;
    }
  }
  return spot;

}


Double_t Integral(std::vector <UShort_t> &trace,int start,int L ){



  int size = trace.size();

  int range =L;

  int  window = floor( trace.size()/10.0);
  Double_t bgk=0;

  for (int i=0;i<window;i++){
    bgk = trace[i]+bgk;
  }
  bgk=bgk/(window);

  Double_t total=0;
  for (int i=start;i<start+L;i++)
    total =total+trace[i];
  

  



  
  return total-(bgk*range);

}




int TOF()
{

  

  Int_t chanid;
  Int_t slotid;
  vector<UShort_t> trace;
  UInt_t fUniqueID;
  UInt_t energy;
  Double_t time ; 
  UInt_t timelow; // this used to be usgined long
  UInt_t timehigh; // this used to be usgined long
  UInt_t timecfd ; 

  TChain *inT;
  inT = new TChain("dchan");
  inT->Add("../run294/run-0294-00.root");
  inT->SetMakeClass(1);

  Long64_t totalEntries =(Long64_t)inT->GetEntries();
  cout<<"tot "<<totalEntries<<endl;
  
  inT->SetBranchAddress("chanid", &chanid);
  inT->SetBranchAddress("fUniqueID", &fUniqueID);
  inT->SetBranchAddress("energy", &energy);
  inT->SetBranchAddress("timelow", &timelow);
  inT->SetBranchAddress("timehigh", &timehigh);
  inT->SetBranchAddress("trace", &trace);
  inT->SetBranchAddress("timecfd", &timecfd);
  inT->SetBranchAddress("slotid", &slotid);
  inT->SetBranchAddress("time", &time);

  TFile * outfile = new TFile("./out.root");

  TTree* out = new TTree("out","");
  Double_t longg, shor;
  
  Double_t long_1, short_1;
  Double_t long_2, short_2;
  Double_t long_3, short_3;

  out->Branch("Long",&longg,"Long/D");
  out->Branch("Shor",&shor,"Shorr/D");

  out->Branch("Long_1",&long_1,"Long_1/D");
  out->Branch("Short_1",&short_1,"Short_1/D");

  out->Branch("Long_2",&long_2,"Long_2/D");
  out->Branch("Short_2",&short_2,"Short_2/D");

  out->Branch("Long_3",&long_3,"Long_3/D");
  out->Branch("Short_3",&short_3,"Short_3/D");



  Double_t tof;
  
  out->Branch("TOF",&tof,"TOF/D");

  longg =0; 
  shor =0;

  
  vector <event> previousEvents;

  int sizeOfRollingWindow =3;
  int count=0;
  for (int i=0;i<totalEntries;i++){
    
    inT->GetEntry(i);
    vector <Double_t> ff;

    int thespot=1;
    if (chanid == 8)  {
      FastFilter(trace,ff,3,0);
      thespot = spot(ff);
      shor= Integral(trace,thespot-2,10);
      longg = Integral(trace,thespot-2,40);
      
      short_1 = Integral(trace,thespot-2,15);
      long_1 = Integral(trace,thespot-2,30);

      short_2 = Integral(trace,thespot-2,15);
      long_2 = Integral(trace,thespot-2,40);

      short_3 = Integral(trace,thespot-2,15);
      long_3 = Integral(trace,thespot-2,20);

      ff.clear();
    } else if (chanid <5 ){
      shor=-1;longg=-1;
    }
    if (previousEvents.size() >=sizeOfRollingWindow){
      if ( checkChannels(previousEvents)){
	//good Event
	Double_t time_1,time_2,time_8;
	for (int q=0;q<3;q++){
	  if (previousEvents[q].channel == 0 ||
	      previousEvents[q].channel == 2)
	    time_1=previousEvents[q].time;
	  else if (previousEvents[q].channel == 1 )
	    time_2=previousEvents[q].time;
	  else if (previousEvents[q].channel == 8)
	    time_8 = previousEvents[q].time;
	}
	tof =TMath::Abs(time_8 - 0.5*(time_1+time_2));
	count++;
	out->Fill();
      }

    }


    if (previousEvents.size() < sizeOfRollingWindow  ) 
      {
	event e;
	e.channel=chanid;
	e.time = time;
	e.long_gate=longg;
	e.short_gate=shor;
	previousEvents.push_back(e);

      }
    else if (previousEvents.size() >= sizeOfRollingWindow )
      {
	//So starting on the fith element 
	previousEvents.erase(previousEvents.begin(),previousEvents.begin() + 1);
	event e;
	e.channel=chanid;
	e.time = time;
	e.long_gate=longg;
	e.short_gate=shor;
	previousEvents.push_back(e);	  
      }    
    

    

    if (i % 10000 ==0)
      cout<<"I is "<<i<<" Count is "<<count<<endl;
  
  }
  outfile->Write();
  return 0;
  
}
