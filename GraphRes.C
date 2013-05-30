

#include <string>
#include "TFile.h"

using namespace std;

int GraphRes(){
  string list[6]={"ResOutFL4FG0d3w2.5run-0321-2ChG-softwareCFD.root",
		  "ResOutFL4FG0d4w2.5run-0321-2ChG-softwareCFD.root",
		  "ResOutFL4FG0d5w2.5run-0321-2ChG-softwareCFD.root",
		  "ResOutFL4FG0d6w2.5run-0321-2ChG-softwareCFD.root",
		  "ResOutFL4FG1d4w2.5run-0321-2ChG-softwareCFD.root",
		  "ResOutFL4FG1d5w2.5run-0321-2ChG-softwareCFD.root"};
   

  if (1==1){
    TLegend * l = new TLegend(0.8,0.8,1,1);
  
    TCanvas * c=new TCanvas("canvas1");
    c->cd(1);
    TFile temp((const char*)list[0].c_str());
    
    Dt1->SetTitle("Dt1");
    Dt1->SetLineColor(1);
    Dt1->Draw("AL");
    l->AddEntry(Dt1,"Internal","l");
    for (int i=0;i<6;i++){
      const char * stupid = list[i].c_str();
      TFile f(stupid);
      
      CDt1->SetLineColor(i+2);
      
      
      CDt1->Draw("same");
      l->AddEntry(CDt1,list[i].substr(6,12).c_str(),"l");
      
      
    }
    l->SetTextSize(.03);
    l->Draw();
  }

  if (1==1){
    TLegend * l = new TLegend(0.8,0.8,1,1);

    TCanvas * c=new TCanvas("canvas2");
    c->cd(1);
    TFile temp((const char*)list[0].c_str());

    Dt2->SetTitle("Dt2");
    Dt2->SetLineColor(1);
    Dt2->Draw("AL");
    l->AddEntry(Dt2,"Internal","l");
    for (int i=0;i<6;i++){
      const char * stupid = list[i].c_str();
      TFile f(stupid);

      CDt2->SetLineColor(i+2);


      CDt2->Draw("same");
      l->AddEntry(CDt2,list[i].substr(6,12).c_str(),"l");


    }
    l->SetTextSize(.03);
    l->Draw();
  }



  if (1==1){
    TLegend * l = new TLegend(0.8,0.8,1,1);

    TCanvas * c=new TCanvas("canvas3");
    c->cd(1);
    TFile temp((const char*)list[0].c_str());

    TD->SetTitle("TimeDiff");
    TD->SetLineColor(1);
    TD->Draw("AL");
    l->AddEntry(TD,"Internal","l");
    for (int i=0;i<6;i++){
      const char * stupid = list[i].c_str();
      TFile f(stupid);

      CTD->SetLineColor(i+2);


      CTD->Draw("same");
      l->AddEntry(CTD,list[i].substr(6,12).c_str(),"l");


    }
    l->SetTextSize(.03);
    l->Draw();
  }









    return 0;

}





