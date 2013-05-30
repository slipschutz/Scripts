

#include <string>
#include "TFile.h"

using namespace std;

int ListRes(){

  gROOT->ProcessLine(".L ../scripts/Res.C");

  std::string list[6]={ "FL4FG0d3w2.5run-0321-2ChG-softwareCFD.root",
			"FL4FG0d4w2.5run-0321-2ChG-softwareCFD.root",
			"FL4FG0d5w2.5run-0321-2ChG-softwareCFD.root",
			"FL4FG0d6w2.5run-0321-2ChG-softwareCFD.root",
			"FL4FG1d4w2.5run-0321-2ChG-softwareCFD.root",
			"FL4FG1d5w2.5run-0321-2ChG-softwareCFD.root"};


  for (int i=0;i<6;i++){
    const char * stupid = list[i].c_str();
    TFile f(stupid);
    Res();

    
  }

  return 0;
}




