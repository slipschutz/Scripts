


Double_t FWHM(TH1F * h1 ){

  int bin1 = h1->FindFirstBinAbove(h1->GetMaximum()/2);
  int bin2 = h1->FindLastBinAbove(h1->GetMaximum()/2);
  Double_t fwhm = h1->GetBinCenter(bin2) - h1->GetBinCenter(bin1);

  return fwhm;
}
