


int temp()
{

  TCanvas *c = new TCanvas();
  c->Divide(2,2);
  c->cd(1);
  flt->Draw("longGate/shortGate:shortGate","abs(longGate/shortGate)<3 &&shortGate<15000");



  c->cd(2);
  flt->Draw("longGate2/shortGate2:shortGate2","abs(longGate2/shortGate2)<3 &&shortGate2<15000");

  c->cd(3);
  flt->Draw("longGate3/shortGate3:shortGate3","abs(longGate3/shortGate3)<3 &&shortGate3<15000");

  c->cd(4);
  flt->Draw("longGate4/shortGate4:shortGate4","abs(longGate4/shortGate4)<3 &&shortGate4<15000");


}
