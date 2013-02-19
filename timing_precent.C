#include "TH1F.h"
#include "TTree.h"
#include "TFile.h"
int timing_precent(Int_t num=0)
{
  
  TH1F *h = new TH1F("h","h",100,11,11.7);//run268
  //TH1F *h = new TH1F("h","h",100,9.7,10.4);//run116
  
  
  
  Double_t integral0,integral1,integral2,integral3;
  Int_t numEntries = flt->GetEntries();
  

  Double_t timeDiff;
  
  flt->SetBranchAddress("Integral0",&integral0);
  flt->SetBranchAddress("Integral1",&integral1);
  flt->SetBranchAddress("Integral2",&integral2);
  flt->SetBranchAddress("Integral3",&integral3);
  flt->SetBranchAddress("Time_Diff",&timeDiff);

  
  for (int j=0;j<40;j++){



    //run268
      Double_t max0=1000;
    Double_t max1=800;
    Double_t max2=1400;
    Double_t max3=700;
    
    //run116
    /*    Double_t max0=1000;
    Double_t max1=1100;
    Double_t max2=1000;
    Double_t max3=1400;
    */
    Double_t E0=num/100.0 *max0;
    Double_t E1=num/100.0 *max1;
    Double_t E2=num/100.0 *max2;
    Double_t E3=num/100.0 *max3;


    
    for (Int_t i=0;i<numEntries;++i){
      flt->GetEntry(i);
      
      if ( integral0 > E0 && 
	   integral1 > E1 &&
           integral2 > E2 &&
           integral3 > E3  ){
        
	h->Fill(timeDiff);
	
      }
    }
    //    cout<<"count is "<<count<<endl;
    TFitResultPtr result = h->Fit("gaus","QSN");
    Int_t status = result;///OMG root



    if (status == 0){
      cout<<"{"<<result->Value(2)*10000*2.35/TMath::Sqrt(2)<<","<<result->UpperError(2)*10000*2.35/TMath::Sqrt(2)<<"},"<<endl;
      
    }
    
    //    cout<<num<<"   "<<result->Value(2)*10000<<"    "<<result->Value(2)*10000*2.35/TMath::Sqrt(2)<<endl;;
    h->Reset();
    num = num +2;
  }
  h->Delete();
  return 1;
}
