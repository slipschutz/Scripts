


void graphLE(Long64_t entry=0,int num=2){

  LendaEvent * event = new LendaEvent();
  flt->SetBranchAddress("Event",&event);

  TCanvas *c = new TCanvas("c1");
  TCanvas *c1 = new TCanvas("c2");
  TCanvas *c2 = new TCanvas("c3");
  

  if (num !=0 ){
    c.Divide(2,num/2);
    c1.Divide(2,num/2);
    c2.Divide(2,num/2);
    
  }
  if (num % 2 !=0){
    cout<<"Use even number"<<endl;
    return;

  }
  

  for (int j=entry;j<num+entry;j++){

    flt->GetEntry(j);
    
    event->MakeC();
    
    Double_t x[100];
    Double_t y[100];

    Double_t y1[100];
    

    Double_t y2[100];
    
    for (int i=0;i<100;i++){
      x[i]=i;
      y[i]=event->CTrace[i];
      y1[i]=event->CFilter[i];
      y2[i]=event->CCFD[i];
    }
    
    TGraph *gr = new TGraph(100,x,y);
    TGraph *gr1 = new TGraph(100,x,y1);
    TGraph *gr2 = new TGraph(100,x,y2);
       
    gr->SetTitle("Traces");
    gr1->SetTitle("Filters");
    gr2->SetTitle("CFDs");
    
    c->cd(j+1-entry);
    gr->Draw("AL*");

    c1->cd(j+1-entry);
    gr1->Draw("AL*");

    c2->cd(j+1-entry);
    gr2->Draw("AL*");


  }
}
