#include "TH1F.h"
#include "TTree.h"
#include "TFile.h"
//
//  sctipt to go through a filtered tree and make energy cuts and
//  fits for the timing peak.  Starts at 0 by defualt and goes to
//  400 KeV.  
// *** Need to manuallly checkthe range of the histogram h and put in the 
// the appropriate calibration numbers

using namespace std;

int timing(Int_t num=0)
{
  const Int_t n=5;
  TH1F * h[n];
  std::stringstream s;
  for (int i=0;i<n;i++){
    s<<"h"<<i;
    h[i] =new TH1F(s.str().c_str(),"",100,10.8,11.8);//run268
    s.str("");
  }
  //  TH1F *h = new TH1F("h","h",100,9.7,10.4);//run116
  // TH1F *h =new TH1F("h","H",50,11.15,11.6);//run270

  
  
  Double_t integral0,integral1,integral2,integral3;
  Int_t numEntries = flt->GetEntries();
  
  Int_t step = 10;
  Double_t timeDiff;
  Int_t fudge = 100000;

  const Int_t max=32;
  Double_t x[n][max];
  Double_t y[n][max];
  Double_t ex[n][max];
  Double_t ey[n][max];
  for(int i=0;i<max;i++){
    for(int k=0;k<n;k++){
      x[k][i]=0;
      y[k][i]=0;
      ex[k][i]=0;
      ey[k][i]=0;
    }
  }

  Double_t timeDiffcor1, timeDiffcor2;
  Double_t timeDiffdtcor1,timeDiffdtcor2;
  flt->SetBranchAddress("Integral0_cor",&integral0);
  flt->SetBranchAddress("Integral1_cor",&integral1);
  flt->SetBranchAddress("Integral2_cor",&integral2);
  flt->SetBranchAddress("Integral3_cor",&integral3);
  flt->SetBranchAddress("Time_Diff",&timeDiff);
  flt->SetBranchAddress("Time_Diffgoecor1",&timeDiffcor1);
  flt->SetBranchAddress("Time_Diffgoecor2",&timeDiffcor2);

  flt->SetBranchAddress("Time_Diffdtcor1",&timeDiffdtcor1);
  flt->SetBranchAddress("Time_Diffdtcor2",&timeDiffdtcor2);


  
  
  for (int j=0;j<max;j++){
 

    Int_t count=0;

    //    cout<<E0<<"  "<<E0H<<endl;
    
    for (Int_t i=0;i<numEntries;++i){
      flt->GetEntry(i);
      
      if ( integral0 > j*step &&
	   integral1 > j*step &&
           integral2 > j*step &&
           integral3 > j*step)
        {
	  h[0]->Fill(timeDiff);
	  h[1]->Fill(timeDiffcor1);
	  h[2]->Fill(timeDiffcor2);
	  h[3]->Fill(timeDiffdtcor1);
	  h[4]->Fill(timeDiffdtcor2);
	  count++;
	}
    }
    
    TFitResultPtr result;

    
    for (int i=0;i<n;i++){
      result = h[i]->Fit("gaus","QSN");
      Int_t status = result;///OMG root
      
      if (status == 0){
	//cout<<"{"<<result->Value(2)*10000*2.35/TMath::Sqrt(2)<<","<<result->UpperError(2)*10000*2.35/TMath::Sqrt(2)<<"},"<<endl;
	x[i][j]=j*step;
	y[i][j]=result->Value(2)*10000*2.35;///TMath::Sqrt(2);
	ex[i][j]=0;
	ey[i][j]=result->UpperError(2)*10000*2.35;///TMath::Sqrt(2);
      }
      h[i]->Reset();
    }
  }
	 
  TGraphErrors *gr = new TGraphErrors(max,x[0],y[0],ex[0],ey[0]);
  gr->GetHistogram()->SetMaximum(1800.);
  gr->GetHistogram()->SetMinimum(500.);
  TCanvas * c1 = new TCanvas("CC");
  c1->cd(1);
  gr->Draw("AL");
  /*
  TGraphErrors *gr = new TGraphErrors(max,x[1],y[1],ex[1],ey[1]);
  gr->SetLineColor(2);
  //  gr->Draw("same");

  TGraphErrors *gr = new TGraphErrors(max,x[2],y[2],ex[2],ey[2]);
  gr->SetLineColor(6);
  gr->Draw("same");

  TGraphErrors *gr = new TGraphErrors(max,x[3],y[3],ex[3],ey[3]);
  gr->SetLineColor(4);
  //gr->Draw("same");


  TGraphErrors *gr = new TGraphErrors(max,x[4],y[4],ex[4],ey[4]);
  gr->SetLineColor(2);
  gr->Draw("same");

  */

  /*


  
  c1->cd();
  gr->Draw("AL");

    h->Delete();
    return 1;*/
}







   //calibrated on run268
    /*Int_t E0=609*num/341;
    Int_t E1=539*num/341;
    Int_t E2=735*num/341;
    Int_t E3=511*num/341;
    */
/*    Int_t E0H=609*(num+step)/341 +fudge;
    Int_t E1H=539*(num+step)/341 +fudge;
    Int_t E2H=735*(num+step)/341 +fudge;
    Int_t E3H=511*(num+step)/341+ fudge;
*/
    //run291 bar 11 23
    /*    Int_t E0=19625*num/341;
    Int_t E1=21375*num/341;
    Int_t E2=23875*num/341;
    Int_t E3=16875*num/341;
    */
    //run292 bar 11 23
/*  Int_t E0=848*num/341;
    Int_t E1=1008*num/341;
    Int_t E2=1416*num/341;
    Int_t E3=564*num/341;

*/
    //run284 on bar 11,23
    /*
    Int_t E0=732*num/341;
    Int_t E1=636*num/341;
    Int_t E2=1020*num/341;
    Int_t E3=310*num/341;
    */
    //calibrated on run269
    /*Int_t E0=1485*num/341;
    Int_t E1=1863*num/341;
    Int_t E2=1504*num/341;
    Int_t E3=2295*num/341;
    
    Int_t E0H=1485*(num+10)/341;
    Int_t E1H=1863*(num+10)/341;
    Int_t E2H=1504*(num+10)/341;
    Int_t E3H=2295*(num+10)/341;
    */

    //run270
    /*
    Int_t E0=5255*num/341;
    Int_t E1=7345*num/341;
    Int_t E2=5445*num/341;
    Int_t E3=8295*num/341;
    */
    //run282
    /*
    Int_t E0=538*num/341;
    Int_t E1=613*num/341;
    Int_t E2=538*num/341;
    Int_t E3=763*num/341;
    */

