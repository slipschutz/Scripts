/*
//run321
Double_t Dt1_C[3];
Dt1_C[0]=-0.612753;
Dt1_C[1]=0.0488126;
Dt1_C[2]=0.574782;

Double_t CDt1_C[3];
CDt1_C[0]=-0.597403;
CDt1_C[1]=0.0377225;
CDt1_C[2]=0.550891;


Double_t Dt2_C[3];
Dt2_C[0]=-0.617589;
Dt2_C[1]=0.0982356;
Dt2_C[2]=0.61729;


Double_t CDt2_C[3];
CDt2_C[0]=-0.607457;
CDt2_C[1]=0.0880865;
CDt2_C[2]=0.677314;
*/

/*
//run323
Double_t Dt1_C[3];
Dt1_C[0]=-0.27968;
Dt1_C[1]=0.0731061;
Dt1_C[2]=-0.965463;


Double_t CDt1_C[3];
CDt1_C[0]=-0.266473;
CDt1_C[1]=0.0474731;
CDt1_C[2]=-0.935292;

Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;
*/
/*
//run324
Double_t Dt1_C[3];
Dt1_C[0]=-0.277475;
Dt1_C[1]=0.0805407;
Dt1_C[2]=-1.03989;


Double_t CDt1_C[3];
CDt1_C[0]=-0.266848;
CDt1_C[1]=0.064693;
CDt1_C[2]=-0.929905;


Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;

*/

//run320
Double_t Dt1_C[3];
Dt1_C[0]=-0.287014;
Dt1_C[1]=0;
Dt1_C[2]=0;


/*
Dt1_C[0]=-0.265159;
Dt1_C[1]=0.165123;
Dt1_C[2]=-1.12028;
*/

Double_t CDt1_C[3];
CDt1_C[0]=-0.266473;
CDt1_C[1]=0.0474731;
CDt1_C[2]=-0.935292;

Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;


//run328
/*
Double_t Dt1_C[3];
Dt1_C[0]=-0.312017;
Dt1_C[1]=0;
Dt1_C[2]=0;


Double_t CDt1_C[3];
CDt1_C[0]=-0.312017;
CDt1_C[1]=0;
CDt1_C[2]=0;





Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;
*/
///
/*
//run333
Double_t Dt1_C[3];
Dt1_C[0]=-0.476493;
Dt1_C[1]=0;
Dt1_C[2]=0;


Double_t CDt1_C[3];
CDt1_C[0]= -0.490274;
CDt1_C[1]= 0;
CDt1_C[2]= 0 ;





Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;
*/


/*
//run325
Double_t Dt1_C[3];
Dt1_C[0]=-0.301421;
Dt1_C[1]=0;
Dt1_C[2]=0;


Double_t CDt1_C[3];
CDt1_C[0]=-0.301843;
CDt1_C[1]= 0;
CDt1_C[2]= 0 ;


Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;
*/

//run 334
/*Double_t Dt1_C[3];
Dt1_C[0]=-0.55243;
Dt1_C[1]=0;
Dt1_C[2]=0;


Double_t CDt1_C[3];
CDt1_C[0]=0;
CDt1_C[1]= 0;
CDt1_C[2]= 0 ;


Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;
*/









/*
Double_t Dt1_C[3];
Dt1_C[0]=-0.588404;
Dt1_C[1]=0;
Dt1_C[2]=0;


Double_t CDt1_C[3];
CDt1_C[0]=-0.588404;
CDt1_C[1]=0;
CDt1_C[2]=0;

Double_t Dt2_C[3];
Dt2_C[0]=0;
Dt2_C[1]=0;
Dt2_C[2]=0;


Double_t CDt2_C[3];
CDt2_C[0]=0;
CDt2_C[1]=0;
CDt2_C[2]=0;



*/






TGraphErrors* Res(){


  //  Double_t startGamma=-65.5;
  // Double_t endGamma=-64.8;




  Double_t startGamma=-1;
  Double_t endGamma=1;

  const Int_t numProjections=100;
 
  Double_t range=2000;
  Double_t startPoint=00;
  Double_t step =(range-startPoint)/numProjections;
  TH1D * projectionsDt1[numProjections];
  TH1D * projectionsDt2[numProjections];
  TH1D * projectionsTimeDiff[numProjections];

  TH1D * CprojectionsDt1[numProjections];
  TH1D * CprojectionsDt2[numProjections];
  TH1D * CprojectionsTimeDiff[numProjections];

  Double_t cutE=0;

  Double_t maxE=range+startPoint;

  LendaEvent * Event = new LendaEvent();
  
  flt->SetBranchAddress("Event",&Event);
  
  Int_t numEntries = flt->GetEntries();
  
  std::stringstream s;
  


    

  
  for (int j=0;j<numProjections;j++){
      cutE = startPoint + j*step;
      s<<"EDt1_"<<cutE;
      projectionsDt1[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma-5,endGamma+5);
      s.str("");
      s<<"EDt2_"<<cutE;
      projectionsDt2[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma-5,endGamma+5);
      s.str("");
      s<<"ETD_"<<cutE;
      projectionsTimeDiff[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma-5,endGamma+5);
      s.str("");

      s<<"ECDt1_"<<cutE;
      CprojectionsDt1[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma-5,endGamma+5);
      s.str("");
      s<<"ECDt2_"<<cutE;
      CprojectionsDt2[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma-5,endGamma+5);
      s.str("");
      s<<"ECTD_"<<cutE;
      CprojectionsTimeDiff[j]=new TH1D(s.str().c_str(),"TOF",1000,startGamma-5,endGamma+5);
      s.str("");
  }

  //  numEntries=200000;
  for (int I=0;I<numEntries;I++){
    if (I% 10000==0)
      cout<<"on "<<I<<endl;

    flt->GetEntry(I);

    if ( Event->NumOfChannelsInEvent==2&& (Event->channels[0]==0 || Event->channels[0]==2)&&TMath::Abs(Event->GOE)<0.6&& Event->softwareCFDs[0]>0 &&Event->softwareCFDs[1]>0&&
	 Event->energies[0]>0&&Event->energies[1]>0 &&Event->energies[0]+Event->energies[1]<15000){
      for (int j=0;j<numProjections;j++){

	cutE = startPoint + j*step;
	
	if (Event->energies[0]>=cutE && Event->energies[1]>=cutE &&
	    Event->energies[0] + Event->energies[1]<maxE*2){

	  if (Event->channels[0]==0){
	    projectionsDt1[j]->Fill((Event->softTimes[0]-Event->softTimes[1])-Dt1_C[0]*Event->GOE -Dt1_C[1]*Event->GOE*Event->GOE- Dt1_C[2]*Event->GOE*Event->GOE*Event->GOE );
	    CprojectionsDt1[j]->Fill((Event->cubicTimes[0]-Event->cubicTimes[1])-CDt1_C[0]*Event->GOE - CDt1_C[1]*Event->GOE*Event->GOE- CDt1_C[2]*Event->GOE*Event->GOE*Event->GOE );

	  } else if(Event->channels[0]==2){
	    projectionsDt2[j]->Fill(Event->Dt -Dt2_C[0]*Event->GOE -Dt2_C[1]*Event->GOE*Event->GOE - Dt2_C[2]*Event->GOE*Event->GOE*Event->GOE);
	    CprojectionsDt2[j]->Fill((Event->cubicTimes[0]-Event->cubicTimes[1]) -CDt2_C[0]*Event->GOE -CDt2_C[1]*Event->GOE*Event->GOE - CDt2_C[2]*Event->GOE*Event->GOE*Event->GOE);
	  }
	} else if (Event->energies[0] + Event->energies[1]>maxE ){
	  //kill the loop over j 
	  j=numProjections+10;
	}
	
      }//end for over j
    } else if (Event->channels[0] ==0 && Event->channels[1]==1&& Event->channels[2]==2&& Event->channels[3]==3 &&
	       Event->energies[0]>0&&Event->energies[1]>0 &&Event->energies[3]>0&&Event->energies[3]>0&& Event->NumOfChannelsInEvent==4 && 
	       Event->softwareCFDs[0]>0 && Event->softwareCFDs[1]>0 && Event->softwareCFDs[2]>0 && Event->softwareCFDs[3]>0){
      //this does not have same conditions as other one righ now
      for (int j=0;j<numProjections;j++){
	
        cutE = startPoint + j*step;
	
        if (Event->energies[0] + Event->energies[1]>=cutE && Event->energies[2] + Event->energies[3]>cutE&&
            Event->energies[0] + Event->energies[1]<maxE && Event->energies[2] + Event->energies[3]<maxE){

	  CprojectionsTimeDiff[j]->Fill(0.5*(Event->cubicTimes[0]+Event->cubicTimes[1]-Event->cubicTimes[2]-Event->cubicTimes[3]));
	  projectionsTimeDiff[j]->Fill(0.5*(Event->times[0]+Event->times[1]-Event->times[2]-Event->times[3]));
	  
        } else if (Event->energies[0] + Event->energies[1]>maxE || Event->energies[2] + Event->energies[3]>maxE){
          //kill the loop over j
          j=numProjections+10;
        }
      }//end for over j
    }
  }//end main loop over tree
    
  


  Double_t x[numProjections];
  Double_t y[numProjections];
  Double_t ex[numProjections];
  Double_t ey[numProjections];

  Double_t x1[numProjections];
  Double_t y1[numProjections];
  Double_t ex1[numProjections];
  Double_t ey1[numProjections];


  Double_t x2[numProjections];
  Double_t y2[numProjections];
  Double_t ex2[numProjections];
  Double_t ey2[numProjections];

  Double_t Cx[numProjections];
  Double_t Cy[numProjections];
  Double_t Cex[numProjections];
  Double_t Cey[numProjections];

  Double_t Cx1[numProjections];
  Double_t Cy1[numProjections];
  Double_t Cex1[numProjections];
  Double_t Cey1[numProjections];


  Double_t Cx2[numProjections];
  Double_t Cy2[numProjections];
  Double_t Cex2[numProjections];
  Double_t Cey2[numProjections];


  for (int i=0;i<numProjections;i++){
    x[i]=startPoint + i*step;
    x1[i]=startPoint + i*step;
    x2[i]=startPoint + i*step;
    ex[i]=0;
    ex1[i]=0;
    ex2[i]=0;
    y[i]=y1[i]=ey[i]=ey1[i]=0;
    y2[i]=ey2[i]=0;
    
    Cx[i]=startPoint + i*step;
    Cx1[i]=startPoint + i*step;
    Cx2[i]=startPoint + i*step;
    Cex[i]=0;
    Cex1[i]=0;
    Cex2[i]=0;
    Cy[i]=Cy1[i]=Cey[i]=Cey1[i]=0;
    Cy2[i]=Cey2[i]=0;
  }

  TF1 *f1 = new TF1("f1","gaus",startGamma,endGamma);
  
  TFitResultPtr result;
  for(int i=0;i<numProjections;i++){
    result = projectionsDt1[i]->Fit("f1","QSNR");
    //x y is from Dt1
    Int_t status=result;
    if (status==0){
      y[i]=result->Value(2)*2.35*10000;
      ey[i]=result->UpperError(2)*2.35*10000;
    } else {
      y[i]=0;
      ey[i]=0;
    }
    
    //x y is for dt
    result = CprojectionsDt1[i]->Fit("f1","QSNR");
    status=result;
    if (status==0){
      Cy[i]=result->Value(2)*2.35*10000;;
      Cey[i]=result->UpperError(2)*2.35*10000;
    } else {
      Cy[i]=0;
      Cey[i]=0;
    }



    //x1 y1 is for dt2
    result = projectionsDt2[i]->Fit("f1","QSNR");
    status=result;
    if (status==0){
      y1[i]=result->Value(2)*2.35*10000;
      ey1[i]=result->UpperError(2)*2.35*10000;
    } else {
      y1[i]=0;
      ey1[i]=0;
    }

    
    //x1 y1 is for dt2
    result = CprojectionsDt2[i]->Fit("f1","QSNR");
    status=result;
    if (status==0){
      Cy1[i]=result->Value(2)*2.35*10000;
      Cey1[i]=result->UpperError(2)*2.35*10000;
    } else {
      Cy1[i]=0;
      Cey1[i]=0;
    }




    //x2 y2 is for time_diff
    result = projectionsTimeDiff[i]->Fit("f1","QSNR");
    status=result;
    if (status==0){
      y2[i]=result->Value(2)*2.35*10000/TMath::Sqrt(2);;
      ey2[i]=result->UpperError(2)*2.35*10000/TMath::Sqrt(2);;
    } else {
      y2[i]=0;
      ey2[i]=0;
    }

    //x2 y2 is for time_diff
    result = CprojectionsTimeDiff[i]->Fit("f1","QSNR");
    status=result;
    if (status==0){
      Cy2[i]=result->Value(2)*2.35*10000/TMath::Sqrt(2);;
      Cey2[i]=result->UpperError(2)*2.35*10000/TMath::Sqrt(2);;
    } else {
      Cy2[i]=0;
      Cey2[i]=0;
    }

  }

  TGraphErrors *grDt1 =new TGraphErrors(numProjections,x,y,ex,ey);
  TGraphErrors *grDt2 =new TGraphErrors(numProjections,x1,y1,ex1,ey1);
  TGraphErrors *grTimeDiff =new TGraphErrors(numProjections,x2,y2,ex2,ey2);

  TGraphErrors *CgrDt1 =new TGraphErrors(numProjections,Cx,Cy,Cex,Cey);
  TGraphErrors *CgrDt2 =new TGraphErrors(numProjections,Cx1,Cy1,Cex1,Cey1);
  TGraphErrors *CgrTimeDiff =new TGraphErrors(numProjections,Cx2,Cy2,Cex2,Cey2);


  grDt2->SetLineColor(6);
  grDt1->SetLineColor(2);
 
  grDt1->SetName("Dt1");
  grDt2->SetName("Dt2");
  grTimeDiff->SetName("TD");

  CgrDt1->SetName("CDt1");
  CgrDt2->SetName("CDt2");
  CgrTimeDiff->SetName("CTD");

  
  TCanvas *c = new TCanvas("c22");


  c->cd(1);
  grDt1->Draw("AL");
  grDt2->Draw("same");
  grTimeDiff->Draw("same");

  stringstream ss;

  ss<<"ResOut"<< gDirectory->GetFile()->GetName(); 
  cout<<"FIle is "<<ss.str()<<endl;

  TFile * f=new TFile(ss.str().c_str(),"recreate");
  for (int i=0;i<numProjections;i++){
    
    projectionsDt1[i]->Write();
    projectionsDt2[i]->Write();
    projectionsTimeDiff[i]->Write();

    CprojectionsDt1[i]->Write();
    CprojectionsDt2[i]->Write();
    CprojectionsTimeDiff[i]->Write();
     

  }

  grDt1->Write();
  grDt2->Write();
  grTimeDiff->Write();

  CgrDt1->Write();
  CgrDt2->Write();
  CgrTimeDiff->Write();

  f->Close();



  return grDt1;
  
}





