



#include <iostream>
#include "TFile.h"
#include "TTree.h"



void TimeCor(){


  
  LendaEvent * event = new LendaEvent();
  
  flt->SetBranchAddress("Event",&event);

  Double_t num = flt->GetEntries();
  cout<<"Num entries "<<num<<endl;

  TH1F * time_diff = new TH1F ("time_diff","",5000,-10,10);

  Double_t time1, time2;
  int ch1, ch2;
  Double_t GOE1, GOE2, Dt1,Dt2;


  double GOE_11_max =0.5;
  double GOE_11_min =-0.5;

  double Dt_11_max=0.5;
  double Dt_11_min=0.1;

  double GOE_23_max=0.6;
  double GOE_23_min=0.1;

  double Dt_23_max=0.1;
  double Dt_23_min=-0.1;

  

  for (int i=0;i<num;i++){
    
    flt->GetEntry(i);
    
    time1 = 0.5*(event->times[0]+event->times[1]);
    ch1 = event->channels[0];
    //  GOE1 = event->GOE;
    GOE1=(event->internEnergies[0]-event->internEnergies[1])/(event->internEnergies[0]+event->internEnergies[1]);
    Dt1 = event->Dt;

    flt->GetEntry(i+1);
    ch2 = event->channels[0];
    time2 = 0.5*(event->times[0]+event->times[1]);
    //GOE2 = event->GOE;
    GOE2=(event->internEnergies[0]-event->internEnergies[1])/(event->internEnergies[0]+event->internEnergies[1]);
    Dt2 = event->Dt;
    bool good1=false;
    bool good2=false;

    int count =0;
    if (ch1 != ch2){
      if ( ch1 == 0 ){ //means ith event isbar 11
	if (GOE1>GOE_11_min && GOE1<GOE_11_max && 
	    Dt1>Dt_11_min && Dt1<Dt_11_max){
	  good1=true;
	  count++;
	}
      } 
      
      if ( ch1 == 2 ){//mean ith event is bar 23
	if (GOE1>GOE_23_min && GOE1<GOE_23_max && 
	    Dt1>Dt_23_min &&Dt1<Dt_23_max){
	  good2=true;
	  count++;
	}
      }

      if ( ch2 == 0){ // mean ith +1 event is bar 11
	if (GOE2>GOE_11_min && GOE2<GOE_11_max && 
	    Dt2>Dt_11_min && Dt2<Dt_11_max){
	  good1=true;
	  count++;
	}
      } 
      if (ch2 == 2 ){ //menas ith +1 event is bar 23
	if (GOE2>GOE_23_min && GOE2<GOE_23_max && 
	    Dt2>Dt_23_min &&Dt2<Dt_23_max){
	  good2=true;
	  count++;
	}
      }
      /*
      cout<<"good1 is "<<good1<<endl;
      cout<<"good2 is "<<good2<<endl;
      cout<<"ch1 is "<<ch1<<endl;
      cout<<"ch2 is "<<ch2<<endl;
      cout<<"GOE1 is "<<GOE1<<endl;
      cout<<"GOE2 is "<<GOE2<<endl;
      cout<<"Dt1 is "<<Dt1<<endl;
      cout<<"Dt2 is "<<Dt2<<endl;
      
      int t; cin>>t;
      */

      if (good1 && good2){
	if ( ch1 == 0)
	  time_diff->Fill(time1-time2);
	else if (ch1==2)
	  time_diff->Fill(time2-time1);
      }
    }
    if (i % 10000 ==0 )
      cout<<i<<endl;

  }








}
