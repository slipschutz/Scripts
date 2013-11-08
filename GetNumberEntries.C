



#include <iostream>
#include <fstream>


using namespace std;

void GetNumberEntries(int num,int numFiles){

  TFile * currentFile;
  TChain * theChain=new TChain("dchan");
  
  stringstream ss;

  for (int i=0;i<numFiles;i++){
    ss.str("");
    currentFile=NULL;
    if (i <10)
      ss<<"run-0"<<num<<"-0"<<i<<".root";
    else
      ss<<"run-0"<<num<<"-"<<i<<".root";

    currentFile = new TFile(ss.str().c_str());
    if (currentFile->IsZombie()){
      break;
    }
    theChain->Add(ss.str().c_str());
  }

  cout<<"qwer"<<theChain->GetEntries()<<endl;

  return;
}
