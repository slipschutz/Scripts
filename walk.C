

#include "TTree.h"
#include "TH2F.h"
#include "TString.h"
#include <sstream>
#include "TCanvas.h"
int walk(){
  
  Int_t const num=20;
  //there are 4 channels and 2 correcions plus original
  TH1D * projections[3][4][num];

  Double_t Range=300;
  Double_t startPoint=60;
  Double_t step= (Range-startPoint)/(Double_t)num;

  TH2F * h_Time_Diff[4];
  TH2F * h_Time_Diffgoecor1[4];
  TH2F * h_Time_Diffgoecor2[4];

  std::stringstream stream,stream2;
  for (int i=0;i<4;i++){
    //original 
    stream<<"Integral"<<i<<"_cor:Time_Diff";
    stream2<<"h"<<i;
    h_Time_Diff[i] = new TH2F(stream2.str().c_str(),"",100,10.5,11.5,100,0,600);
    flt->Project(stream2.str().c_str(),stream.str().c_str());
    //correcion 1
    stream.str("");
    stream2.str("");
    stream<<"Integral"<<i<<"_cor:Time_Diffgoecor1";
    stream2<<"hcor1"<<i;
    h_Time_Diffgoecor1[i]=new TH2F(stream2.str().c_str(),"",100,10.5,11.5,100,0,600);
    flt->Project(stream2.str().c_str(),stream.str().c_str());

    //correction 2
    stream.str("");
    stream2.str("");
    stream<<"Integral"<<i<<"_cor:Time_Diffgoecor2";
    stream2<<"hcor2"<<i;
    h_Time_Diffgoecor2[i]=new TH2F(stream2.str().c_str(),"",100,10.5,11.5,100,0,600);
    flt->Project(stream2.str().c_str(),stream.str().c_str());

    stream.str("");
    stream2.str("");
  }

  std::stringstream s;
  for (Int_t j=0;j<4;j++){
    for (Int_t i=0;i<num;i++){
      Int_t bin1 = h_Time_Diff[j]->GetYaxis()->FindBin(startPoint +i*step);
      Int_t bin2 = h_Time_Diff[j]->GetYaxis()->FindBin(startPoint +(i+1)*step);
      
      s<<"h0_"<<j<<"_px"<<startPoint+i*step<<"_"<<startPoint+(i+1)*step;
      projections[0][j][i] = h_Time_Diff[j]->ProjectionX(s.str().c_str(),bin1,bin2);

      s.str("");
      s<<"h1_"<<j<<"_px"<<startPoint+i*step<<"_"<<startPoint+(i+1)*step;
      projections[1][j][i] = h_Time_Diffgoecor1[j]->ProjectionX(s.str().c_str(),bin1,bin2);
      s.str("");

      s<<"h2_"<<j<<"_px"<<startPoint+i*step<<"_"<<startPoint+(i+1)*step;
      projections[2][j][i] = h_Time_Diffgoecor2[j]->ProjectionX(s.str().c_str(),bin1,bin2);
      s.str("");


    }
  }

  
  TCanvas * c = new TCanvas("c");
  c->Divide(2,2);


  TGraphErrors *graphs[3][4];
  //For each channel make walk plot for each of the corrections
  //for each chanel need 4 parameters for num points 
  //for the 3 different corecions
  //points[k][0][i] for the kth correction the x values for the ith point
  //points[k][1][i] for the kth correction the y values for the ith point
  //points[k][2][i] for the kth correction the ex values for the ith point
  //points[k][3][i] for the kth correction the ey values for the ith point

  Double_t points[3][4][num];

  for (int j=0;j<4;j++){
    for (int k=0;k<3;++k){
      for (int i=0;i<num;++i){
	TFitResultPtr result = projections[k][j][i]->Fit("gaus","QSN");
	Int_t status = result;///OMG root
	if (status==0){
	  points[k][0][i]=((startPoint+i*step)+(startPoint+(i+1)*step))/2.0;
	  points[k][1][i]=result->Value(1);
	  points[k][2][i]=0;//ex is always 0
	  points[k][3][i]=result->UpperError(1);//ey from fit
	  /*
	  ex1[i]=0;
	  x1[i]=((startPoint+i*step)+(startPoint+(i+1)*step))/2.0;
	  y1[i]=result->Value(1);
	  ey1[i]=result->UpperError(1);*/
	}
      }

      
      
      std::stringstream temp;temp.str("");
      graphs[k][j]= new TGraphErrors(num,points[k][0],points[k][1],points[k][2],points[k][3]);
      temp<<"Walk in channel "<<j;
      graphs[0][j]->SetTitle(temp.str().c_str());
      graphs[0][j]->GetXaxis()->SetTitle("Energy [KeV]");
      graphs[0][j]->GetYaxis()->SetTitle("Centriod of Timing Peak");
    }
  }
  
  for (int j=0;j<4;j++){
    c->cd(j+1);
    graphs[0][j]->Draw("AL");
    graphs[1][j]->SetLineColor(6);
    graphs[1][j]->Draw("Same");
    graphs[2][j]->SetLineColor(2);
    graphs[2][j]->Draw("Same");
    }
  return 0;


}
