



#include <iostream>
#include <vector>
#include "TTree.h"

#include "TFile.h"
#include "ddaschannel.h"


using namespace std;

void TraceCount(){


  ddaschannel *chan = new ddaschannel();

  TFile *inFile = new TFile("./run-0316-00.root");
  
  TTree * t = (TTree*) inFile->Get("dchan");


  t->SetBranchAddress("dchan",&chan);


  Int_t num = (Int_t) t->GetEntries();
  
  cout <<"Num is "<<num<<endl;
  num=5000000;

  double total=0;
  for (int i=0;i<num;i++){
    t->GetEntry(i);
    
    vector <UShort_t> trace = chan->trace;

    double avg =0;
    for (int k=0;k<20;k++)
      avg=avg+trace[k];

    avg=avg/20.0;

    for (int j=0;j<trace.size();j++){
      if ( trace[j] < 0.9*avg ){
	total++;
	j=trace.size()+1;
      }
    }
    if (i % 10000==0)
      cout<<" I is "<<i<<endl;

  }
  cout<<"Total is "<<total<<endl;
  cout<<"ratio is "<<total/num<<endl;
  
}
