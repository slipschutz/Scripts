






#define NUM 40;

void RatioTest(){

  Double_t x[NUM];
  Double_t ex[NUM];
  Double_t y[NUM];
  Double_t ey[NUM];
  
  TH1::AddDirectory(kFALSE);
  TCanvas *c = new TCanvas();

  for (int i=0;i<NUM;i++){
    stringstream ss;
    ss<<"Run381LA"<<i<<".root";
    TFile *f= new TFile(ss.str().c_str());
    
    Long64_t N8 =ChannelsRaw->GetBinContent(9);
    Long64_t N9 =ChannelsRaw->GetBinContent(10);
  
    Double_t ErrorN8 =sqrt(N8);
    Double_t ErrorN9 =sqrt(N9);
  
    Double_t Error = sqrt( (ErrorN8/N8)**2 + (ErrorN9/N9)**2);
  
    cout <<i<< " Error"<<double(N9)/double(N8)<<" Error "<<Error*(double(N9)/double(N8))<<endl;

    x[i]=i;
    ex[i]=0;
    y[i]=double(N9)/double(N8);
    ey[i]=Error*(double(N9)/double(N8));

  }
  c->cd(1);
  TGraphErrors* g = new TGraphErrors(NUM,x,y,ex,ey);
  g->SetLineColor(kRed);

  Double_t x1[NUM];
  Double_t ex1[NUM];
  Double_t y1[NUM];
  Double_t ey1[NUM];
  
  for (int i=0;i<NUM;i++){
    stringstream ss;
    ss<<"Run381LA"<<i<<".root";

    TFile *f= new TFile(ss.str().c_str());
    
    Long64_t N8 =ChannelsN2->GetBinContent(9);
    Long64_t N9 =ChannelsN2->GetBinContent(10);
  
    Double_t ErrorN8 =sqrt(N8);
    Double_t ErrorN9 =sqrt(N9);
  
    Double_t Error = sqrt( (ErrorN8/N8)**2 + (ErrorN9/N9)**2);
  
    cout <<i<< " Error"<<double(N9)/double(N8)<<" Error "<<Error*(double(N9)/double(N8))<<endl;

    x1[i]=i;
    ex1[i]=0;
    y1[i]=double(N9)/double(N8);
    ey1[i]=Error*(double(N9)/double(N8));

  }
  TGraphErrors* g1 = new TGraphErrors(NUM,x1,y1,ex1,ey1);
  

  TMultiGraph * mg = new TMultiGraph();
  mg->Add(g,"l");
  mg->Add(g1,"l");
  mg->Draw("a");

}
