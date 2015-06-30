{
  TF1 *ex1=new TF1("ex1","(x<56975)*[0]*exp(-abs(x-56948.3)/[1]) + (x>56975)*[0]*exp(-abs(x-56948.3)/[2])",56946,56954);
  TF1 *ex2=new TF1("ex2","(x<56975)*[0]*exp(-abs(x-56975)/[1]) + (x>56975)*[0]*exp(-abs(x-56975)/[2])",56972,56981);

  TNtuple *o1=new TNtuple("o1","o1","mjd:f:df");
  o1->ReadFile("orbit1_noul.txt");
  o1->Draw("mjd:f:df");
  TGraphErrors *g1=new TGraphErrors(11,o1->GetV1(),o1->GetV2(),0,o1->GetV3());
  g1->SetMarkerStyle(20);
  //g1->Draw("AP");
  ex1->SetParameters(o1->GetV2()[2],0.5,0.5);
  ex1->SetParLimits(0,o1->GetV2()[2]-o1->GetV3()[2],o1->GetV2()[2]+o1->GetV3()[2]);


  TNtuple *o2=new TNtuple("o2","o2","mjd:f:df");
  o2->ReadFile("orbit2_noul.txt");
  o2->Draw("mjd:f:df");
  TGraphErrors *g2=new TGraphErrors(12,o2->GetV1(),o2->GetV2(),0,o2->GetV3());
  g2->SetMarkerStyle(20);
  //g2->Draw("AP");
  ex2->SetParameters(o2->GetV2()[2],0.5,0.5);
  ex2->SetParLimits(0,o2->GetV2()[2]-o2->GetV3()[2],o2->GetV2()[2]+o2->GetV3()[2]);

  cout<<"\033[22;32m\nPiecewise defined exponential rise/decay\033[0m"<<endl; 
  cout<<"\n\033[22;34mFit to orbit1:\033[0m\n"<<endl;
  g1->Fit("ex1","ME","",56946,56952);
  cout<<"\n\033[22;34mFit to orbit2:\033[0m\n"<<endl;
  g2->Fit("ex2","ME","",56972,56981);

  cout<<"\n\033[22;34mFlux doubling time is ln(2)*par1 (rise) or ln(2)*par2 (fall)\033[0m"<<endl;

  cout<<"\033[22;32m\nEquation 7 from Abdo et al., 2010, ApJ, 722, 520\033[0m"<<endl;

  TF1 *f71=new TF1("f71","[0] + [1]/( exp((56948.3-x)/[2]) + exp((x-56948.3)/[3]) )");
  f71->SetParameters(-1e-12,7e-11,0.5,0.5);
  cout<<"\n\033[22;34mFit to orbit1:\033[0m\n"<<endl;
  g1->Fit("f71","ME");

  TF1 *f72=new TF1("f72","[0] + [1]/( exp((56975-x)/[2]) + exp((x-56975.3)/[3]) )");
  f72->SetParameters(1e-12,3e-11,1,1);
  g2->Fit("f72","ME");

//  cout<<"\033[22;32m\nGaussian on baseline\033[0m"<<endl;
//
//  TF1 *fg1=new TF1("fg1","[0]+[1]*TMath::Gaus(x,[2],[3])");
//  fg1->SetParameters(1e-12,3e-11,56948.3,1);
//  fg1->FixParameter(2,56948.3);
//  cout<<"\n\033[22;34mFit to orbit1:\033[0m\n"<<endl;
//  g1->Fit("fg1","ME");
//
//  TF1 *fg2=new TF1("fg2","[0]+[1]*TMath::Gaus(x,[2],[3])");
//  fg2->SetParameters(1e-12,2e-11,56975,1);
//  cout<<"\n\033[22;34mFit to orbit2:\033[0m\n"<<endl;
//  g2->Fit("fg2","ME");

}
