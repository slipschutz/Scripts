

#include <string>
#include "TFile.h"
#include "TROOT.h"
#include <iostream>


using namespace std;

int ListRes(int start=0,int num=1){

  gROOT->ProcessLine(".L ../scripts/Res.C");
  const int NumOfFiles =60;

  if (start + num >= NumOfFiles ){
    cout<<"Only have "<<NumOfFiles <<" files"<<endl;
  }
  
  std::string list[60]= {"FL3FG0d2w0run-0325-2ChG-softwareCFD.root",
			 "FL3FG0d2w10run-0325-2ChG-softwareCFD.root",
			 "FL3FG0d2w20run-0325-2ChG-softwareCFD.root",
			 "FL3FG0d2w30run-0325-2ChG-softwareCFD.root",
			 "FL3FG0d2w40run-0325-2ChG-softwareCFD.root",
			 "FL3FG0d3w0run-0325-2ChG-softwareCFD.root",
			 "FL3FG0d3w10run-0325-2ChG-softwareCFD.root",
			 "FL3FG0d3w20run-0325-2ChG-softwareCFD.root",
			 "FL3FG0d3w30run-0325-2ChG-softwareCFD.root",
			 "FL3FG0d3w40run-0325-2ChG-softwareCFD.root",
			 "FL3FG1d2w0run-0325-2ChG-softwareCFD.root",
			 "FL3FG1d2w10run-0325-2ChG-softwareCFD.root",
			 "FL3FG1d2w20run-0325-2ChG-softwareCFD.root",
			 "FL3FG1d2w30run-0325-2ChG-softwareCFD.root",
			 "FL3FG1d2w40run-0325-2ChG-softwareCFD.root",
			 "FL3FG1d3w0run-0325-2ChG-softwareCFD.root",
			 "FL3FG1d3w10run-0325-2ChG-softwareCFD.root",
			 "FL3FG1d3w20run-0325-2ChG-softwareCFD.root",
			 "FL3FG1d3w30run-0325-2ChG-softwareCFD.root",
			 "FL3FG1d3w40run-0325-2ChG-softwareCFD.root",
			 "FL4FG0d2w0run-0325-2ChG-softwareCFD.root",
			 "FL4FG0d2w10run-0325-2ChG-softwareCFD.root",
			 "FL4FG0d2w20run-0325-2ChG-softwareCFD.root",
			 "FL4FG0d2w30run-0325-2ChG-softwareCFD.root",
			 "FL4FG0d2w40run-0325-2ChG-softwareCFD.root",
			 "FL4FG0d3w0run-0325-2ChG-softwareCFD.root",
			 "FL4FG0d3w10run-0325-2ChG-softwareCFD.root",
			 "FL4FG0d3w20run-0325-2ChG-softwareCFD.root",
			 "FL4FG0d3w30run-0325-2ChG-softwareCFD.root",
			 "FL4FG0d3w40run-0325-2ChG-softwareCFD.root",
			 "FL4FG1d2w0run-0325-2ChG-softwareCFD.root",
			 "FL4FG1d2w10run-0325-2ChG-softwareCFD.root",
			 "FL4FG1d2w20run-0325-2ChG-softwareCFD.root",
			 "FL4FG1d2w30run-0325-2ChG-softwareCFD.root",
			 "FL4FG1d2w40run-0325-2ChG-softwareCFD.root",
			 "FL4FG1d3w0run-0325-2ChG-softwareCFD.root",
			 "FL4FG1d3w10run-0325-2ChG-softwareCFD.root",
			 "FL4FG1d3w20run-0325-2ChG-softwareCFD.root",
			 "FL4FG1d3w30run-0325-2ChG-softwareCFD.root",
			 "FL4FG1d3w40run-0325-2ChG-softwareCFD.root",
			 "FL5FG0d2w0run-0325-2ChG-softwareCFD.root",
			 "FL5FG0d2w10run-0325-2ChG-softwareCFD.root",
			 "FL5FG0d2w20run-0325-2ChG-softwareCFD.root",
			 "FL5FG0d2w30run-0325-2ChG-softwareCFD.root",
			 "FL5FG0d2w40run-0325-2ChG-softwareCFD.root",
			 "FL5FG0d3w0run-0325-2ChG-softwareCFD.root",
			 "FL5FG0d3w10run-0325-2ChG-softwareCFD.root",
			 "FL5FG0d3w20run-0325-2ChG-softwareCFD.root",
			 "FL5FG0d3w30run-0325-2ChG-softwareCFD.root",
			 "FL5FG0d3w40run-0325-2ChG-softwareCFD.root",
			 "FL5FG1d2w0run-0325-2ChG-softwareCFD.root",
			 "FL5FG1d2w10run-0325-2ChG-softwareCFD.root",
			 "FL5FG1d2w20run-0325-2ChG-softwareCFD.root",
			 "FL5FG1d2w30run-0325-2ChG-softwareCFD.root",
			 "FL5FG1d2w40run-0325-2ChG-softwareCFD.root",
			 "FL5FG1d3w0run-0325-2ChG-softwareCFD.root",
			 "FL5FG1d3w10run-0325-2ChG-softwareCFD.root",
			 "FL5FG1d3w20run-0325-2ChG-softwareCFD.root",
			 "FL5FG1d3w30run-0325-2ChG-softwareCFD.root",
			 "FL5FG1d3w40run-0325-2ChG-softwareCFD.root"};



  for (int i=start;i<start+num;i++){
    const char * stupid = list[i].c_str();
    TFile f(stupid);
    Res();

    
  }

  return 0;
}




