{
  TNtuple *o1=new TNtuple("o1","o1","mjd:phi:f:dfh:dfl");
  o1->ReadFile("./orbit1.txt");
  TNtuple *o2=new TNtuple("o2","o2","mjd:phi:f:dfh:dfl");
  o2->ReadFile("./orbit2.txt");
  TNtuple *o3=new TNtuple("o3","o3","mjd:phi:f:dfh:dfl");
  o3->ReadFile("./orbit3.txt");
  TNtuple *o1ul=new TNtuple("o1ul","o1ul","mjd:phi:f:dfh:dfl");
  o1ul->ReadFile("./orbit1UL.txt");
  TNtuple *o2ul=new TNtuple("o2ul","o2ul","mjd:phi:f:dfh:dfl");
  o2ul->ReadFile("./orbit2UL.txt");
  TNtuple *o3ul=new TNtuple("o3ul","o3ul","mjd:phi:f:dfh:dfl");
  o3ul->ReadFile("./orbit3UL.txt");
  
  o1->Draw("phi:f:dfh:dfl");
  o2->Draw("phi:f:dfh:dfl");
  o3->Draw("phi:f:dfh:dfl");
  o1ul->Draw("phi:f:dfh:dfl");
  o2ul->Draw("phi:f:dfh:dfl");
  o3ul->Draw("phi:f:dfh:dfl");

  int N=o1->GetEntries();
  TGraphAsymmErrors *g1=new TGraphAsymmErrors(N,o1->GetV1(),o1->GetV2(),0,0,o1->GetV4(),o1->GetV3());
  int N=o2->GetEntries();
  TGraphAsymmErrors *g2=new TGraphAsymmErrors(N,o2->GetV1(),o2->GetV2(),0,0,o2->GetV4(),o2->GetV3());
  int N=o3->GetEntries();
  TGraphAsymmErrors *g3=new TGraphAsymmErrors(N,o3->GetV1(),o3->GetV2(),0,0,o3->GetV4(),o3->GetV3());
  int N=o1ul->GetEntries();
  TGraphAsymmErrors *g1ul=new TGraphAsymmErrors(N,o1ul->GetV1(),o1ul->GetV2(),0,0,o1ul->GetV4(),o1ul->GetV3());
  int N=o2ul->GetEntries();
  TGraphAsymmErrors *g2ul=new TGraphAsymmErrors(N,o2ul->GetV1(),o2ul->GetV2(),0,0,o2ul->GetV4(),o2ul->GetV3());
  int N=o3ul->GetEntries();
  TGraphAsymmErrors *g3ul=new TGraphAsymmErrors(N,o3ul->GetV1(),o3ul->GetV2(),0,0,o3ul->GetV4(),o3ul->GetV3());

  g1->SetMarkerStyle(20);
  g2->SetMarkerStyle(20);
  g3->SetMarkerStyle(20);
  g1ul->SetMarkerStyle(20);
  g2ul->SetMarkerStyle(20);
  g3ul->SetMarkerStyle(20);

  g1->SetMarkerColor(kOrange+7);
  g1ul->SetMarkerColor(kOrange+7);
  g2->SetMarkerColor(kMagenta-2);
  g2ul->SetMarkerColor(kMagenta-2);
  g3->SetMarkerColor(kAzure-3);
  g3ul->SetMarkerColor(kAzure-3);

  g1->SetLineColor(kOrange+7);
  g1ul->SetLineColor(kOrange+7);
  g2->SetLineColor(kMagenta-2);
  g2ul->SetLineColor(kMagenta-2);
  g3->SetLineColor(kAzure-3);
  g3ul->SetLineColor(kAzure-3);

  g1->SetFillColor(kOrange+7);
  g1ul->SetFillColor(kOrange+7);
  g2->SetFillColor(kMagenta-2);
  g2ul->SetFillColor(kMagenta-2);
  g3->SetFillColor(kAzure-3);
  g3ul->SetFillColor(kAzure-3);

  g1ul->Draw("AP|>");
  g2ul->Draw("P|>");
  g3ul->Draw("P|>");
  g1->Draw("P");
  g2->Draw("P");
  g3->Draw("P");

  g1ul->GetXaxis()->SetRangeUser(0,1);
  g1ul->GetYaxis()->SetRangeUser(1e-13,3.5e-11);
  g1ul->GetXaxis()->SetLabelFont(132);
  g1ul->GetYaxis()->SetLabelFont(132);
  g1ul->GetXaxis()->SetTitleFont(132);
  g1ul->GetYaxis()->SetTitleFont(132);
  g1ul->GetXaxis()->CenterTitle();
  g1ul->GetXaxis()->SetTitleSize(0.05);
  g1ul->GetXaxis()->SetTitleOffset(0.95);
  g1ul->GetYaxis()->CenterTitle();
  g1ul->GetYaxis()->SetTitleSize(0.05);
  g1ul->GetYaxis()->SetTitleOffset(0.8);
  g1ul->GetXaxis()->SetTitle("Orbital phase #phi");
  g1ul->GetYaxis()->SetTitle("Flux (E>350 GeV) [ph cm^{-2} s^{-1}]");
  g1ul->SetTitle("");

  TLegend *l=new TLegend(0.15,0.7,0.5,0.85);
  l->SetTextFont(132);
  l->SetFillColor(0);
  l->SetBorderSize(0);
  l->AddEntry(g1,"1st Orbit (Oct 2014)","p");
  l->AddEntry(g2,"2nd Orbit (Nov 2014)","p");
  l->AddEntry(g3,"3rd Orbit (Dec 2014)","p");
  l->Draw("same");

}
