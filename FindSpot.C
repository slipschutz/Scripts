//
// script to find the bin value coresponding to the 2/3 of the maximum 
// of first compton edge.  
// 
// Adjust the start and end variables before use
//



#include <string>
#include <iostream>

#include "TList.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"




int FindSpot (TH1F* h,int start=100,int endd=200)
{

  
  int  binStart = h->FindBin(start);
  int binEnd = h->FindBin(endd);


  cout<<"Bin start "<<binStart<<endl;

  cout<<"Bin end "<<binEnd<<endl;

  Double_t max =0;

  //find the max
  int maxBin=-1;
  for(int i=binStart ; i<binEnd ;i++){
    if ( h->GetBinContent(i) > max)
      {
	max = h->GetBinContent(i);
	maxBin=i;
      }
  }

  max= (1/3.0)*(max+h->GetBinContent(maxBin-1)+
		h->GetBinContent(maxBin+1));

  cout<<"The Maximum value is "<< max <<endl;


  cout<<"Max bin is "<<maxBin<<endl;

  Double_t twoThirdmax = (2.0/3.0)*max;

  cout<<"twoThirdMax value is "<<twoThirdmax<<endl;

  for (int i=maxBin;i<binEnd;i++){


    if ( h->GetBinContent(i) <= twoThirdmax ){
      cout<<"bin is "<<i <<" Bin center is "<<h->GetBinCenter(i)<<endl;
      cout<<"bin width/2 is "<<h->GetBinWidth(i)/2.0<<endl;
      cout<<"341.0/num "<<341.0/h->GetBinCenter(i)<<endl;
      break;
    }

  }
  return 0;
}
