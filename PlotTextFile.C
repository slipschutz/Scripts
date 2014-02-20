


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//int main(int argv, char** argc){

// string s = string (argc[1]);

void PlotTextFile(string s,string name="Graph"){
  cout<<"file is "<<s<<endl;
  ifstream inFile;

  inFile.open(s.c_str(),ios_base::in);
  cout<<inFile.is_open()<<endl;

  
  double var1;
  double var2;
  int count=0;
  while( inFile.good()){
    inFile>>var1>>var2;
    count++;
  }
  
  inFile.clear();
  inFile.seekg(0, ios::beg);
  double * x = calloc(sizeof(double),count);
  double * y = calloc(sizeof(double),count);

  count=0;
  while( inFile.good()){
    inFile>>var1>>var2;
    x[count]=var1;
    y[count]=var2;
    count++;
  }
  
  TFile * temp = new TFile("temp.root","update");
  TGraph * g = new TGraph(count,x,y);
  g->Draw("AL");
  g->SetName(name.c_str());
  g->Write();
  gROOT->GetListOfSpecials()->Add(g);



}
