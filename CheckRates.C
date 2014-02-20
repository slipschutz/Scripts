

#include "TTree.h"
#include <sstream>
#include "TFile.h"
#include "LendaEvent.hh"
#include <vector>
#include "TGraph.h"
#include "TCanvas.h"




void CheckRates(){

  LendaEvent * event = new LendaEvent();
  
  TTree* flt =(TTree*)gDirectory->Get("flt");
  
  flt->SetBranchAddress("Event",&event);

  int TheChannel=9;
  
  
  Long64_t numEntries = flt->GetEntries();

  cout<<"There are "<<numEntries<<endl;

  for (Long64_t i=0;i<numEntries;i++){
    flt->GetEntry(i);
    
    bool loop=true;
    int count=0;
    int numTriggers;
    Double_t startTime=-1;
    while (loop){
      for (int j=0;j<event->N;j++){
	if (event->channels[j]==TheChannel){
	  if (startTime == -1 ){ // the first one
	    startTime = event->times[j];
	    numTriggers++;
	  } else if ( x0+i*hx0+i*hx0+i*hevent->times[j] {

	  }

	}

      }


    }

    
  }
  
  
  return;
}
