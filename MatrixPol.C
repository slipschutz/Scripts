



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








}
