

#include <string>
#include "TFile.h"
#include "TROOT.h"
#include <iostream>

#include "TCanvas.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFitResult.h"

using namespace std;

int ListMaxRes(int start=0,int num=1){


  const int NumOfFiles =60;

  if (start + num > NumOfFiles ){
    cout<<"Only have "<<NumOfFiles <<" files"<<endl;
  }
  
  std::string list[]={"FL3FG0d2w0run-0324--softwareCFD.root",
		      "FL3FG0d2w10run-0324--softwareCFD.root",
		      "FL3FG0d2w20run-0324--softwareCFD.root",
		      "FL3FG0d2w30run-0324--softwareCFD.root",
		      "FL3FG0d2w40run-0324--softwareCFD.root",
		      "FL3FG0d3w0run-0324--softwareCFD.root",
		      "FL3FG0d3w10run-0324--softwareCFD.root",
		      "FL3FG0d3w20run-0324--softwareCFD.root",
		      "FL3FG0d3w30run-0324--softwareCFD.root",
		      "FL3FG0d3w40run-0324--softwareCFD.root",
		      "FL3FG1d2w0run-0324--softwareCFD.root",
		      "FL3FG1d2w10run-0324--softwareCFD.root",
		      "FL3FG1d2w20run-0324--softwareCFD.root",
		      "FL3FG1d2w30run-0324--softwareCFD.root",
		      "FL3FG1d2w40run-0324--softwareCFD.root",
		      "FL3FG1d3w0run-0324--softwareCFD.root",
		      "FL3FG1d3w10run-0324--softwareCFD.root",
		      "FL3FG1d3w20run-0324--softwareCFD.root",
		      "FL3FG1d3w30run-0324--softwareCFD.root",
		      "FL4FG0d2w0run-0324--softwareCFD.root",
		      "FL4FG0d2w30run-0324--softwareCFD.root",
		      "FL4FG0d3w0run-0324--softwareCFD.root",
		      "FL4FG0d3w10run-0324--softwareCFD.root",
		      "FL4FG0d3w20run-0324--softwareCFD.root",
		      "FL4FG0d3w30run-0324--softwareCFD.root",
		      "FL4FG0d3w40run-0324--softwareCFD.root",
		      "FL4FG1d2w0run-0324--softwareCFD.root",
		      "FL4FG1d2w10run-0324--softwareCFD.root",
		      "FL4FG1d2w20run-0324--softwareCFD.root",
		      "FL4FG1d2w30run-0324--softwareCFD.root",
		      "FL4FG1d3w0run-0324--softwareCFD.root",
		      "FL4FG1d3w10run-0324--softwareCFD.root",
		      "FL4FG1d3w20run-0324--softwareCFD.root",
		      "FL4FG1d3w30run-0324--softwareCFD.root",
		      "FL4FG1d3w40run-0324--softwareCFD.root",
		      "FL5FG0d2w0run-0324--softwareCFD.root",
		      "FL5FG0d2w10run-0324--softwareCFD.root",
		      "FL5FG0d2w20run-0324--softwareCFD.root",
		      "FL5FG0d2w30run-0324--softwareCFD.root",
		      "FL5FG0d2w40run-0324--softwareCFD.root",
		      "FL5FG0d3w0run-0324--softwareCFD.root",
		      "FL5FG0d3w20run-0324--softwareCFD.root",
		      "FL5FG0d3w40run-0324--softwareCFD.root",
		      "FL5FG1d2w0run-0324--softwareCFD.root"};


  TCanvas *c = new TCanvas("c");
  c->cd(1);

  for (int i=start;i<start+num;i++){
    const char * stupid = list[i].c_str();
    TFile f(stupid);



    TH1F * h = new TH1F("h","h",100,0.1,0.6);

    TTree *flt = (TTree*)f.Get("flt");

    flt->Project("h","softTimes[0]-softTimes[1]+0.617706*GOE",
    		 "NumOfChannelsInEvent==2&&channels[0]==0&&abs(GOE)<0.6&&softwareCFDs[0]>0 && softwareCFDs[1]>0 && energies[0]>2600 && energies[0]<3600 &&energies[1]>2600&& energies[1]<3600");
    h->SetDirectory(0);



    TFitResultPtr p = h->Fit("gaus","QSN");
    int status = p;
    if (status==0)
      cout<<"The file is "<<stupid<<" "<<p->Value(2)*2.35*10000<<endl;
    
  }

  return 0;
}




