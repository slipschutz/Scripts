



void MatrixPol(){

  TMatrixD A(4,4);//declare 4 by 4 matrix

  Double_t x[4];
  x[0]=1;
  x[1]=2;
  x[2]=3;
  x[3]=4;

  Double_t y1=1;
  Double_t y1=5;
  Double_t y1=-1;
  Double_t y1=2;


  for (int row=0;row<4;row++){
    for (int col=0;col<4;col++){
      A[row][col]= pow(x[row],3-col);
    }
  }

  A.Print();

  TMatrixD invertA = A.Invert();
  
  invertA.Print();

  TMatrixD Y(4,1);
  Y[0][0]=1;
  Y[1][0]=5;
  Y[2][0]=-1;
  Y[3][0]=2;

  cout<<"Y I S"<<endl;
  Y.Print();

  TMatrixD res(4,1);

  res = invertA*Y;
  res.Print();





}
