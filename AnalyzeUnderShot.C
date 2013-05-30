


void AnalyzeUnderShot(Long64_t entry=0){

  LendaEvent * event = new LendaEvent();
  flt->SetBranchAddress("Event",&event);

  Double_t count=0;
  Double_t total=5000;
  for (int II=0;II<total;II++){

  flt->GetEntry(II);
  
  event->MakeC();
  
  Double_t x[100];
  Double_t y[100];
  
  Double_t sum=0;
  for (int i=0;i<100;i++){
    x[i]=i;
    y[i]=event->CTrace[i];
    if (i<20)
      sum=sum+y[i];
  }
  Double_t avg = sum/20.0;
  Bool_t bad=false;
  for (int i=0;i<100;i++){
    if (y[i] < 0.9*avg)
      bad = true;
  }
  
  if (bad)
    count++;
  
  }
  cout<<"COunt is "<<count<<endl;
  cout<<"frac "<<count/total<<endl;
}
