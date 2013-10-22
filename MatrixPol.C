



void MatrixPol(){

  TMatrixD A(4,4);//declare 4 by 4 matrix

  Double_t x[4];
  x[0]=50;
  x[1]=51;
  x[2]=52;
  x[3]=53;

  Double_t y1=998.5;
  Double_t y2=355.5;
  Double_t y3=-603;
  Double_t y4=-1221;


  for (int row=0;row<4;row++){
    for (int col=0;col<4;col++){
      A[row][col]= pow(x[row],3-col);
    }
  }

  A.Print();

  TMatrixD invertA = A.Invert();
  
  invertA.Print();

  TMatrixD Y(4,1);
  Y[0][0]=y1;
  Y[1][0]=y2;
  Y[2][0]=y3;
  Y[3][0]=y4;

  cout<<"Y I S"<<endl;
  Y.Print();

  TMatrixD res(4,1);

  res = invertA*Y;
  res.Print();

  stringstream s;

  s<<res[0][0]<<"+"<<res[1][0]<<"*x"<<"+"<<
    res[2][0]<<"*x^2"<<"+"<<res[3][0]<<"*x^3";
  cout<<s.str()<<endl;

  stringstream s2;
  s2<<res[3][0]<<"+"<<res[2][0]<<"*x"<<"+"<<
    res[1][0]<<"*x^2"<<"+"<<res[0][0]<<"*x^3";

  cout<<s2.str()<<endl;
  TF1 * f1 = new TF1("f1",s2.str().c_str(),-100,100);
  f1->Draw();

  cout<<f1(50)<<endl;




}
