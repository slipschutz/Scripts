#include <iostream>

#include <string>
#include "TFile.h"
#include <sstream>
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TFitResult.h"
using namespace std;

int ListGraphAsym(int start=0,int num=8){


  if (start + num >79){
    cout<<"Past range of files"<<endl;
    return 1;
  }
  // FL3FG1d3w40
  std::string list[60]= {"FL3FG0d2w0run-0323--softwareCFD.root",
			 "FL3FG0d2w10run-0323--softwareCFD.root",
			 "FL3FG0d2w20run-0323--softwareCFD.root",
			 "FL3FG0d2w30run-0323--softwareCFD.root",
			 "FL3FG0d3w0run-0323--softwareCFD.root",
			 "FL3FG0d3w10run-0323--softwareCFD.root",
			 "FL3FG0d3w20run-0323--softwareCFD.root",
			 "FL3FG0d3w30run-0323--softwareCFD.root",
			 "FL3FG0d3w40run-0323--softwareCFD.root",
			 "FL3FG1d2w0run-0323--softwareCFD.root",
			 "FL3FG1d2w10run-0323--softwareCFD.root",
			 "FL3FG1d2w20run-0323--softwareCFD.root",
			 "FL3FG1d2w30run-0323--softwareCFD.root",
			 "FL3FG1d2w40run-0323--softwareCFD.root",
			 "FL3FG1d3w0run-0323--softwareCFD.root",
			 "FL3FG1d3w10run-0323--softwareCFD.root",
			 "FL3FG1d3w20run-0323--softwareCFD.root",
			 "FL3FG1d3w30run-0323--softwareCFD.root",
			 "FL3FG1d3w40run-0323--softwareCFD.root",
			 "FL4FG0d2w0run-0323--softwareCFD.root",
			 "FL4FG0d2w10run-0323--softwareCFD.root",
			 "FL4FG0d2w20run-0323--softwareCFD.root",
			 "FL4FG0d2w30run-0323--softwareCFD.root",
			 "FL4FG0d3w0run-0323--softwareCFD.root",
			 "FL4FG0d3w10run-0323--softwareCFD.root",
			 "FL4FG0d3w20run-0323--softwareCFD.root",
			 "FL4FG0d3w40run-0323--softwareCFD.root",
			 "FL4FG1d2w0run-0323--softwareCFD.root",
			 "FL4FG1d2w10run-0323--softwareCFD.root",
			 "FL4FG1d2w20run-0323--softwareCFD.root",
			 "FL4FG1d2w30run-0323--softwareCFD.root",
			 "FL4FG1d2w40run-0323--softwareCFD.root",
			 "FL4FG1d3w0run-0323--softwareCFD.root",
			 "FL4FG1d3w10run-0323--softwareCFD.root",
			 "FL4FG1d3w20run-0323--softwareCFD.root",
			 "FL4FG1d3w30run-0323--softwareCFD.root",
			 "FL4FG1d3w40run-0323--softwareCFD.root",
			 "FL5FG0d2w30run-0323--softwareCFD.root",
			 "FL5FG0d2w40run-0323--softwareCFD.root",
			 "FL5FG0d3w0run-0323--softwareCFD.root"};


			  
  int numOfWindows=1;
  if (num % 8 != 0){
    
  } else {
    numOfWindows= num/8;
  }
  cout<<"number of windows is"<<numOfWindows<<endl;

  TCanvas * c[numOfWindows];
  stringstream st;
  for (int i=0;i<numOfWindows;i++){
    st.str("");
    st<<"c"<<i;
    c[i]= new TCanvas(st.str().c_str());
    c[i]->Divide(2,4.0);
  }

  TH1D *array[num];
  TH1D *arrayCube[num];

  stringstream s;
  stringstream s2;

  int countForWindows=0;

  for (int i=start;i<start+num;i++){
    if (i % 8 == 0 &&i!=0){
      cout<<"i is "<<i<<endl;
      cout<<"count is "<<countForWindows<<endl;
      countForWindows++;
    }
    s.str("");
    s2.str("");
    s<<"h"<<i-start;
    s2<<"Ch"<<i-start;
    c[countForWindows]->cd(i-start+1-countForWindows*8);


    const char * stupid = list[i].c_str();
    TFile f(stupid); //open a file
    
    array[i-start]= new TH1D(s.str().c_str(),stupid,500,0.1,0.6);
    arrayCube[i-start]= new TH1D(s2.str().c_str(),stupid,500,0.1,0.6);
    
    TTree * flt =(TTree*) f.Get("flt");
    /*    
    flt->Project(s.str().c_str(),"(softTimes[0]-softTimes[1])-(GOE*-0.270831+GOE*GOE*0.0483082+GOE*GOE*GOE*-0.964384)",
		 "channels[0]==0&&abs(GOE)<0.4&&energies[0]>1500&&energies[1]>1500&&softwareCFDs[0]>0&&softwareCFDs[1]>0","");
    flt->Project(s2.str().c_str(),"(cubicTimes[0]-cubicTimes[1])-(GOE*-0.268217+GOE*GOE*0.0495688+GOE*GOE*GOE*-0.994124)",
		 "channels[0]==0&&abs(GOE)<0.4&&energies[0]>1500&&energies[1]>1500&&softwareCFDs[0]>0&&softwareCFDs[1]>0","");
    */
    /*
    flt->Project(s.str().c_str(),"(softTimes[0]-softTimes[1])+0.588404*GOE",
		 "channels[0]==0&&abs(GOE)<0.5&&energies[0]+energies[1]>3000&&softwareCFDs[0]>0&&softwareCFDs[1]>0","");
    flt->Project(s2.str().c_str(),"(cubicTimes[0]-cubicTimes[1]+0.587341*GOE)",
		 "channels[0]==0&&abs(GOE)<0.5&&energies[0]+energies[1]>3000&&softwareCFDs[0]>0&&softwareCFDs[1]>0","");

*/
    flt->Project(s.str().c_str(),"(softTimes[0]-softTimes[1])+0.617706*GOE",
		 "channels[0]==0&&abs(GOE)<0.5&&energies[0]+energies[1]>6000&&softwareCFDs[0]>0&&softwareCFDs[1]>0","");
    flt->Project(s2.str().c_str(),"(cubicTimes[0]-cubicTimes[1]+0.617706*GOE)",
		 "channels[0]==0&&abs(GOE)<0.5&&energies[0]+energies[1]>6000&&softwareCFDs[0]>0&&softwareCFDs[1]>0","");

    array[i-start]->SetDirectory(0);
    arrayCube[i-start]->SetDirectory(0);
    //    array[i]->Draw();
    TFitResultPtr r =array[i-start]->Fit("gaus","QS");
    TFitResultPtr r1 =arrayCube[i-start]->Fit("gaus","NQS"); //Don't draw the cubic one
    Double_t temp =r->Chi2()/r->Ndf();
    Double_t temp2 =r1->Chi2()/r1->Ndf();
    cout<<stupid<<" soft "<<temp<<" cubic "<<temp2<<endl;
    stringstream sss;
    sss.str("");
    sss<<stupid<<" soft "<<temp<<" cube "<<temp2;
    array[i-start]->SetTitle(sss.str().c_str());


    arrayCube[i-start]->SetLineColor(6);
    arrayCube[i-start]->Draw("same");    
  }

  return 0;
}




