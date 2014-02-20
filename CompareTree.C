




void CompareTree(){

  TFile * f1 = new TFile("./run-0376-newtest-softwareCFD-output.root");
  TFile * f2 = new TFile("./run-0376-nopacker-softwareCFD-output.root");

  TTree * flt1 = (TTree*)f1->Get("flt");
  TTree * flt2 = (TTree*)f2->Get("flt");

  LendaEvent * e1 = new LendaEvent;
  LendaEvent * e2 = new LendaEvent;
  
  flt1->SetBranchAddress("Event",&e1);
  flt2->SetBranchAddress("Event",&e2);

  for (int i=0;i<10;i++){
    flt1->GetEntry(i);
    flt2->GetEntry(i);
   
    if (e1->N != e2->N){
      cout<<"FAIL"<<endl;
      cout<<"I "<<i<<endl;
      cout<<"e1 "<<e1->N<<"  e2 "<<e2->N<<endl;
      return;
    }
    for (int j=0;j<e1->N ;j++){
      cout<<e1->times[j]<<"   "<<e2->times[j]<<"   "<<e1->times[j]-e2->times[j]<<endl;

      cout<<e1->cubicTimes[j]<<"   "<<e2->cubicTimes[j]<<"   "<<e1->cubicTimes[j]-e2->cubicTimes[j]<<endl;

      cout<<e1->cubicCFDs[j]<<"   "<<e2->cubicCFDs[j]<<e1->cubicCFDs[j]-e2->cubicCFDs[j]<<endl;

    }

    cout<<"$%^&$%^&$%^&*$%^&"<<endl;  
  }
  


}
