



void MakeTResPlot(){

  gROOT->SetStyle("Pub");

  TGraphErrors * theGraph = gDirectory->Get("Cor3");

  theGraph->SetFillColor(kBlack);

  theGraph->Draw("ALE3");
  theGraph->GetXaxis()->SetRange(0,500);  
  theGraph->GetYaxis()->SetTitle("Timing Resolution [ps]");
  
  theGraph->GetXaxis()->SetTitle("keV_{ee}");
  
  theGraph->SetLineColor(1);
    


}
