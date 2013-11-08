/*
//run321
Double_t Dt1_C[3];
Dt1_C[0]=-0.612753;
Dt1_C[1]=0.0488126;
Dt1_C[2]=0.574782;

Double_t CDt1_C[3];
CDt1_C[0]=-0.597403;
CDt1_C[1]=0.0377225;
CDt1_C[2]=0.550891;


Double_t Dt2_C[3];
Dt2_C[0]=-0.617589;
Dt2_C[1]=0.0982356;
Dt2_C[2]=0.61729;


Double_t CDt2_C[3];
CDt2_C[0]=-0.607457;
CDt2_C[1]=0.0880865;
CDt2_C[2]=0.677314;
*/

/*
//run323
Double_t Dt1_C[3];
Dt1_C[0]=-0.27968;
Dt1_C[1]=0.0731061;
Dt1_C[2]=-0.965463;


Double_t CDt1_C[3];
CDt1_C[0]=-0.266473;
CDt1_C[1]=0.0474731;
CDt1_C[2]=-0.935292;

Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;
*/
/*
//run324
Double_t Dt1_C[3];
Dt1_C[0]=-0.277475;
Dt1_C[1]=0.0805407;
Dt1_C[2]=-1.03989;


Double_t CDt1_C[3];
CDt1_C[0]=-0.266848;
CDt1_C[1]=0.064693;
CDt1_C[2]=-0.929905;


Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;

*/
/*
//run320
Double_t Dt1_C[3];

Dt1_C[0]=-0.265159;
Dt1_C[1]=0.165123;
Dt1_C[2]=-1.12028;


Double_t CDt1_C[3];
CDt1_C[0]=-0.266473;
CDt1_C[1]=0.0474731;
CDt1_C[2]=-0.935292;

Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;

*/
//run328
/*Double_t Dt1_C[3];
Dt1_C[0]=-0.28269;
Dt1_C[1]=0.403179;
Dt1_C[2]=-1.91155;


Double_t CDt1_C[3];
CDt1_C[0]=-0.266473;
CDt1_C[1]=0.0474731;
CDt1_C[2]=-0.935292;

Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;
*/







#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TGraphErrors.h"
#include "TFitResult.h"
#include <iostream>
#include "TMath.h"
#include "LendaEvent.hh"
#include <sstream>
using namespace std;

TGraphErrors* ResCor(){


  //  Double_t startGamma=-65.5;
  // Double_t endGamma=-64.8;


  TTree * flt =(TTree*) gDirectory->Get("flt");

  Double_t startGamma=-0.3-5;
  Double_t endGamma=0+5;

  const Int_t numProjections=40;
 
  Double_t range=600;
  Double_t startPoint=0;
  Double_t step =(range-startPoint)/numProjections;
  
  TH1D * Corrections0[numProjections];
  TH1D * Corrections1[numProjections];
  TH1D * Corrections2[numProjections];
  TH1D * Corrections3[numProjections];
  TH1D * Corrections4[numProjections];
  TH1D * Corrections5[numProjections];

  Double_t cutE=0;

  Double_t maxE=range+startPoint;

  LendaEvent * Event = new LendaEvent();
  
  flt->SetBranchAddress("Event",&Event);
  
  Int_t numEntries = flt->GetEntries();
  
  std::stringstream s;
  
  for (int j=0;j<numProjections;j++){
      cutE = startPoint + j*step;
      s<<"Cor0_"<<j;
      Corrections0[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma,endGamma);
      s.str("");
      s<<"Cor1_"<<j;
      Corrections1[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma,endGamma);
      s.str("");
      s<<"Cor2_"<<j;
      Corrections2[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma,endGamma);
      s.str("");
      s<<"Cor3_"<<j;
      Corrections3[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma,endGamma);
      s.str("");
      s<<"Cor4_"<<j;
      Corrections4[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma,endGamma);
      s.str("");
      s<<"Cor5_"<<j;
      Corrections5[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma,endGamma);
      s.str("");
  }

  //  numEntries=10000;
  for (int I=0;I<numEntries;I++){
    if (I% 10000==0)
      cout<<"on "<<I<<endl;

    flt->GetEntry(I);

    if ( (Event->channels[0]==0 || Event->channels[0]==2)&&TMath::Abs(Event->GOE)<0.6&&
	 Event->energies[0]>0&&Event->energies[1]>0 && Event->NumOfChannelsInEvent==2 &&Event->energiesCor[0]+Event->energiesCor[1]<15000&&Event->softwareCFDs[0]>0&&Event->softwareCFDs[1]>0){
      for (int j=0;j<numProjections;j++){
	
	cutE = startPoint + j*step;
	
	if (Event->energiesCor[0] >=cutE&& Event->energiesCor[1]>=cutE &&
	    Event->energiesCor[0] <maxE&& Event->energiesCor[1]<maxE){
	  
	  if (Event->channels[0]==0){
	    //do channel 0


	    /*Corrections3[j]->Fill(Event->Corrections[3]);
	    Corrections0[j]->Fill(Event->Corrections[0]);
	    Corrections1[j]->Fill(Event->Corrections[1]);
	    Corrections2[j]->Fill(Event->Corrections[2]);
	    Corrections4[j]->Fill(Event->Corrections[4]);
	    Corrections5[j]->Fill(Event->Corrections[5]);
	    */
	
	  } else if(Event->channels[0]==2){
	    //do channel 2
	  }
	} else if (Event->energies[0] + Event->energies[1]>maxE ){
	  //kill the loop over j 
	  j=numProjections+10;
	}
	
      }//end for over j
    } else if (Event->channels[0] ==0 && Event->channels[1]==1&& Event->channels[2]==2&& Event->channels[3]==3 && TMath::Abs(Event->GOE)<0.6&&
	       Event->energies[0]>0&&Event->energies[1]>0 &&Event->energies[3]>0&&Event->energies[3]>0&& Event->NumOfChannelsInEvent==4 &&
	       Event->softwareCFDs[0]>0&& Event->softwareCFDs[1]>0&& Event->softwareCFDs[2]>0&& Event->softwareCFDs[3]>0){
      
      for (int j=0;j<numProjections;j++){
	
        cutE = startPoint + j*step;
	
        if (Event->energiesCor[0] + Event->energiesCor[1]>=cutE && Event->energiesCor[2] + Event->energiesCor[3]>cutE&&
            Event->energiesCor[0] + Event->energiesCor[1]<maxE && Event->energiesCor[2] + Event->energiesCor[3]<maxE){
	  

	  //Stuf for 4 way coincidence
	  
	  
	  Corrections0[j]->Fill(Event->Corrections[0]);
	  Corrections1[j]->Fill(Event->Corrections[1]);
	  Corrections2[j]->Fill(Event->Corrections[2]);
	  Corrections3[j]->Fill(Event->Corrections[3]);

        } else if (Event->energies[0] + Event->energies[1]>maxE || Event->energies[2] + Event->energies[3]>maxE){
          //kill the loop over j
          j=numProjections+10;
        }
      }//end for over j
    }
  }//end main loop over tree
    
  


  Double_t x[numProjections];
  Double_t y[numProjections];
  Double_t ex[numProjections];
  Double_t ey[numProjections];

  Double_t x1[numProjections];
  Double_t y1[numProjections];
  Double_t ex1[numProjections];
  Double_t ey1[numProjections];


  Double_t x2[numProjections];
  Double_t y2[numProjections];
  Double_t ex2[numProjections];
  Double_t ey2[numProjections];

  Double_t x3[numProjections];
  Double_t y3[numProjections];
  Double_t ex3[numProjections];
  Double_t ey3[numProjections];

  Double_t x4[numProjections];
  Double_t y4[numProjections];
  Double_t ex4[numProjections];
  Double_t ey4[numProjections];

  Double_t x5[numProjections];
  Double_t y5[numProjections];
  Double_t ex5[numProjections];
  Double_t ey5[numProjections];

  Double_t Cx[numProjections];
  Double_t Cy[numProjections];
  Double_t Cex[numProjections];
  Double_t Cey[numProjections];

  Double_t Cx1[numProjections];
  Double_t Cy1[numProjections];
  Double_t Cex1[numProjections];
  Double_t Cey1[numProjections];


  Double_t Cx2[numProjections];
  Double_t Cy2[numProjections];
  Double_t Cex2[numProjections];
  Double_t Cey2[numProjections];


  for (int i=0;i<numProjections;i++){
    x[i]=startPoint + i*step;
    x1[i]=startPoint + i*step;
    x2[i]=startPoint + i*step;
    x3[i]=startPoint + i*step;
    x4[i]=startPoint + i*step;
    x5[i]=startPoint + i*step;
    ex[i]=0;
    ex1[i]=0;
    ex2[i]=0;
    ex3[i]=0;
    ex4[i]=0;
    ex5[i]=0;
    y[i]=y1[i]=ey[i]=ey1[i]=0;
    y2[i]=ey2[i]=y3[i]=ey3[i]=0;
    

    Cx[i]=startPoint + i*step;
    Cx1[i]=startPoint + i*step;
    Cx2[i]=startPoint + i*step;
    Cex[i]=0;
    Cex1[i]=0;
    Cex2[i]=0;
    Cy[i]=Cy1[i]=Cey[i]=Cey1[i]=0;
    Cy2[i]=Cey2[i]=0;
  }

  TF1 *f1 = new TF1("f1","gaus",startGamma,endGamma);
  
  TFitResultPtr result;
  for(int i=0;i<numProjections;i++){
    result = Corrections0[i]->Fit("f1","QSNR");
    //x y is from Dt1
    Int_t status=result;
    if (status==0){
      y[i]=result->Value(2)*2.35*10000/TMath::Sqrt(2);
      ey[i]=result->UpperError(2)*2.35*10000/TMath::Sqrt(2);
    } else {
      y[i]=0;
      ey[i]=0;
    }
  

    result = Corrections1[i]->Fit("f1","QSNR");
    //x y is from Dt1
    Int_t status=result;
    if (status==0){
      y1[i]=result->Value(2)*2.35*10000/TMath::Sqrt(2);
      ey1[i]=result->UpperError(2)*2.35*10000/TMath::Sqrt(2);
    } else {
      y1[i]=0;
      ey1[i]=0;
    }
        result = Corrections2[i]->Fit("f1","QSNR");
    //x y is from Dt1
    Int_t status=result;
    if (status==0){
      y2[i]=result->Value(2)*2.35*10000/TMath::Sqrt(2);
      ey2[i]=result->UpperError(2)*2.35*10000/TMath::Sqrt(2);
    } else {
      y2[i]=0;
      ey2[i]=0;
    }



  result = Corrections3[i]->Fit("f1","QSNR");
    //x y is from Dt1
    Int_t status=result;
    if (status==0){
      y3[i]=result->Value(2)*2.35*10000/TMath::Sqrt(2);
      ey3[i]=result->UpperError(2)*2.35*10000/TMath::Sqrt(2);
    } else {
      y3[i]=0;
      ey3[i]=0;
    }
  }    /*  result = Corrections4[i]->Fit("f1","QSNR");
    //x y is from Dt1
    Int_t status=result;
    if (status==0){
      y4[i]=result->Value(2)*2.35*10000/TMath::Sqrt(2);
      ey4[i]=result->UpperError(2)*2.35*10000/TMath::Sqrt(2);
    } else {
      y4[i]=0;
      ey4[i]=0;
    }
    result = Corrections5[i]->Fit("f1","QSNR");
    //x y is from Dt1
    Int_t status=result;
    if (status==0){
      y5[i]=result->Value(2)*2.35*10000/TMath::Sqrt(2);
      ey5[i]=result->UpperError(2)*2.35*10000/TMath::Sqrt(2);
    } else {
      y5[i]=0;
      ey5[i]=0;
    }
    }*/

  TGraphErrors *grCor0 =new TGraphErrors(numProjections,x,y,ex,ey);
  TGraphErrors *grCor1 =new TGraphErrors(numProjections,x1,y1,ex1,ey1);
  TGraphErrors *grCor2 =new TGraphErrors(numProjections,x2,y2,ex2,ey2);
  TGraphErrors *grCor3 =new TGraphErrors(numProjections,x3,y3,ex3,ey3);
  TGraphErrors *grCor4 =new TGraphErrors(numProjections,x4,y4,ex4,ey4);
  TGraphErrors *grCor5 =new TGraphErrors(numProjections,x5,y5,ex5,ey5);

  TGraphErrors *CgrDt1 =new TGraphErrors(numProjections,Cx,Cy,Cex,Cey);
  TGraphErrors *CgrDt2 =new TGraphErrors(numProjections,Cx1,Cy1,Cex1,Cey1);
  TGraphErrors *CgrTimeDiff =new TGraphErrors(numProjections,Cx2,Cy2,Cex2,Cey2);




 
  grCor0->SetName("Cor0");
  grCor1->SetName("Cor1");
  grCor2->SetName("Cor2");
  grCor3->SetName("Cor3");
  grCor4->SetName("Cor4");
  grCor5->SetName("Cor5");
  

  stringstream ss;

  ss<<"ResOut"<< gDirectory->GetFile()->GetName(); 
  cout<<"FIle is "<<ss.str()<<endl;

  TFile * f=new TFile(ss.str().c_str(),"recreate");
  for (int i=0;i<numProjections;i++){
    
    Corrections0[i]->Write();
    Corrections1[i]->Write();
    Corrections2[i]->Write();
    Corrections3[i]->Write();
    Corrections4[i]->Write();
    Corrections5[i]->Write();
     

  }
  grCor0->Write();
  grCor1->Write();
  grCor2->Write();
  grCor3->Write();
  grCor4->Write();
  grCor5->Write();
  TCanvas *c = new TCanvas("c22");
   

  c->cd(1);
  
 

  f->Close();



  return grCor0;
  
}





