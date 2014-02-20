





void FindScaleFactor(TH1F* FixedHisto){

  stringstream name;
  double min = 100000;
  int minIndexI=-1;
  int minIndexA=-1;
  TH2F* result = new TH2F("result","",100,0,100,100,0,100);
  for (int i=0;i<100;i++){
    for (int a=0;a<100;a++){
      name.str("");
      name<<"RefScaledE"<<i<<"_"<<a;
      TH1F* current = (TH1F*)gDirectory->Get(name.str().c_str());
      //    current->Scale(20);
      int nBins=current->GetNbinsX() /3;
      double total=0;
      for (int j=0;j<nBins;j++){
	double e = FixedHisto->GetBinContent(j+1);
	double o = current->GetBinContent(j+1);
	double val=((o-e)*(o-e))/e;
	total=total+val;
      }
      result->SetBinContent(i,a,total/nBins);
      if ((total/nBins)<min){
	min = total/nBins;
	minIndexI=i;
	minIndexA=a;
      }
      
      cout<<"I is "<<i<<"  "<<total/nBins<<endl;
    }
  }
  cout<<"Min is "<<min<<" INdex "<<minIndexI<<" "<<minIndexA<<endl;
  


}
