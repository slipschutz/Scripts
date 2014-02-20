








void PlotEnergySpecs(int num){

  cout<<"Run is "<<num<<endl;
  
  stringstream ss;
  
  TH1F * currentHisto;
  
  for (int i=0;i<40;i++){
    ss.str("");
    ss<<"Run"<<num<<"LA"<<i<<".root";
    TFile f(ss.str().c_str());
    
    currentHisto =(TH1F*)gDirectory->Get("ENoOverFlows1");
    if (i==0)
      currentHisto->Draw();
    else if ( i==38)
      currentHisto->Draw("same");

    currentHisto->SetLineColor(i+1);
    currentHisto->SetDirectory(0);
  }



}
