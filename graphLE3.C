


#include "TTree.h"
#include <sstream>
#include "TFile.h"
#include "LendaEvent.hh"
#include <vector>
#include "TGraph.h"
#include "TCanvas.h"






void graphLE3(Long64_t entry=0,int num=2,int spot=0){
  
  gROOT->ProcessLine(".L ~/analysis/scripts/LoadStyle.C");
  LoadStyle();

  LendaEvent * event = new LendaEvent();
  
  TTree* flt =(TTree*)gDirectory->Get("flt");
  
  flt->SetBranchAddress("Event",&event);

  flt->GetEntry(entry);

  cout<<event->Traces.size()<<endl;


  int size = (int) event->Traces[spot].size();

  Double_t* x = malloc(size*sizeof(Double_t));
  Double_t* y = malloc(size*sizeof(Double_t));

  Double_t* y1= malloc(size*sizeof(Double_t));
    

  Double_t* y2=malloc(size*sizeof(Double_t));
    

    cout<<"size is "<<size<<endl;
    for (int i=0;i<size;i++){

      x[i]=i*10;
      y[i]=event->Traces[spot][i] -380;
      y1[i]=event->Filters[spot][i];
      y2[i]=event->CFDs[spot][i];
    }
    cout<<"50 "<<event->CFDs[spot][50]<<endl;
    cout<<"50 "<<event->CFDs[spot][51]<<endl;
    cout<<"50 "<<event->CFDs[spot][52]<<endl;
    cout<<"50 "<<event->CFDs[spot][53]<<endl;



    TGraph *gr = new TGraph(size,x,y);
    TGraph *gr1 = new TGraph(size,x,y1);
    TGraph *gr2 = new TGraph(size,x,y2);

    TCanvas *c = new TCanvas();

    c->cd(1);

    gr->SetFillColor(kBlack);
    gr1->SetFillColor(0);
    gr2->SetFillColor(0);

    gr->SetLineColor(kBlack);
    gr1->SetLineColor(kBlue);
    gr2->SetLineColor(kRed);
    gr->SetLineWidth(3);
    gr2->SetLineWidth(3);
    gr1->SetLineWidth(3);

    gr->SetMarkerSize(.7);
    gr1->SetMarkerSize(.7);
    gr2->SetMarkerSize(.7);


    gr->SetMarkerStyle(8);
    gr1->SetMarkerStyle(8);
    gr2->SetMarkerStyle(8);
    TMultiGraph *mg = new TMultiGraph();

    leg = new TLegend(0.7,0.7,1,1);
    leg->SetLineWidth(0);
    leg->SetHeader("");
    leg->AddEntry(gr, "Trace","l");
    leg->AddEntry(gr1,"Fast Filter","l");
    leg->AddEntry(gr2,"CFD Filter","l");

    leg->SetTextSize(.05);
    leg->SetFillColor(kWhite);
    mg->Add(gr);
    mg->Add(gr1);
    mg->Add(gr2);

    mg->SetTitle("Pixie Digital Waveform");
    mg->Draw("a L P");
    mg->GetHistogram()->GetXaxis()->SetTitle("Time [ns]");
    mg->GetHistogram()->GetYaxis()->SetTitle("ADC Channel");
    mg->GetHistogram()->GetYaxis()->SetTitleOffset(1.3);

    leg->Draw();      
    
}
