






TGraph* temp2(TGraphErrors * in){

  double x ,y;

  Double_t xx[100];
  Double_t yy[100];
  
  for (int i=0;i<100;i++){
    
    in->GetPoint(i,x,y);
    xx[i]=x;
    yy[i]=y;

  }
  cout<<"hello"<<endl;
  TGraph * gr = new TGraph(100,xx,yy);
  TCanvas c("c");
  c.cd(1);
  gr->Draw("AL");

  return gr;
}
