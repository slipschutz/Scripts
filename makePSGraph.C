#include "TH2F.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TFile.h"

using namespace std;
void  makePSGraph()
{

  
  int SG_low=6;
  int SG_high=12;
  int LG_low=16;
  int LG_high=26;
  
  const int SG_range=SG_high-SG_low;
  const int LG_range=LG_high-LG_low;
  
  std::stringstream s,name,cmd,cuts;
  TH2F * h[SG_range][LG_range];
  TH1D * proj[SG_range][LG_range];
  
  for (int i=0;i<SG_range;++i){
    for (int j=0;j<LG_range;j++){
      h[i][j]=0;
      proj[i][j]=0;
    }
  }


  
  for (int i=SG_low;i<SG_high;++i){
    for (int j=LG_low;j<LG_high;j++){
      s.str("");
      name.str("");cmd.str("");cuts.str("");

      s<<"run-0301-LG"<<j<<"-SG"<<i<<".root";

      TFile *f = new TFile(s.str().c_str() );
      
      
      if (! f->IsZombie() ){
      
	TTree *flt = f->Get("flt");
	
	name<<"LG"<<j<<"SG"<<i;
	cmd<<"(PulseShape-1):shortGates[2]";
	cuts<<"abs(PulseShape-1)<1";
	
	//	cout<<"i is "<<i <<" j is "<<j<<endl;
	//	cout<<"name is "<<name.str()<<endl;
	//	cout<<"cmd is "<<cmd.str()<<endl;
	//	cout<<"cuts is "<<cuts.str()<<endl;
	cout<<"i "<<i-SG_low<<" j  "<<j-LG_low<<endl;

	h[i-SG_low][j-LG_low]= new TH2F(name.str().c_str(),name.str().c_str(),500,0,30000,2000,-3,3);

	flt->Project(name.str().c_str(),cmd.str().c_str(),cuts.str().c_str());


	flt->Project("hh","PulseShape:shortGates[2]","abs(PulseShape)<3");

      }else{
	cout<<"Got Zombie at SG"<<i<<" LG "<<j<<endl;
      }
	

    }
  }

  TF1 *f1 = new TF1("f1","gaus",0,0.08);
  TF1 *f2  =new TF1("f2","gaus",0.08,0.2);

  TFitResultPtr result1;
  TFitResultPtr result2;

  for (int i=0;i<SG_range;i++){
    for (int j=0;j<LG_range;j++){
      if (h[i][j] !=0){
	int bin1=h[i][j]->GetXaxis()->FindBin(5000);
	int bin2=h[i][j]->GetXaxis()->FindBin(6000);
	proj[i][j] = h[i][j]->ProjectionY("_py",bin1,bin2);
	
	result1=(proj[i][j])->Fit("f1","QSNR");
	result2=(proj[i][j])->Fit("f2","QSNR");
	cout<<"LG "<<j+LG_low<<" SG "<<i+SG_low<<" "<<result2->Value(1)-result1->Value(1)<<endl;
	//cout<<"{"<<result2->Value(1)-result1->Value(1)<<","<<result1->Value(2)<<","<<result2->Value(2)<<"},"<<endl;

      }
    }
    
  }

  return 0;
  


  
  /*TCanvas *C[SG_range];

  stringstream s;
   
  for (int i=0;i<SG_range;i++){
    s.str("");
    s<<"C"<<i;
    C[i]= new TCanvas(s.str().c_str());
    C[i]->Divide(1,LG_range);

    for (int j=0;j<LG_range;j++){

      C[i]->cd(j+1);
      
      if ( h[i][j] != 0){


	cout <<"J "<<j<<" i "<<i<<endl;
	cout<<&(h[i][j])<<endl;
	cout<<(h[i][j])->GetName()<<endl;
	h[i][j]->Draw();
      }else{
	cout<<"A 0"<<endl;
      }
      	//h[i][j]->Draw();

    }
  }
  
  */
  }

