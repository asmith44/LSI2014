{
  TNtuple *o1=new TNtuple("o1","o1","mjd:phi:f:dfh:dfl");
  o1->ReadFile("./orbit1_300.txt");
  TNtuple *o2=new TNtuple("o2","o2","mjd:phi:f:dfh:dfl");
  o2->ReadFile("./orbit2_300.txt");
  TNtuple *o3=new TNtuple("o3","o3","mjd:phi:f:dfh:dfl");
  o3->ReadFile("./orbit3_300.txt");
  TNtuple *o1ul=new TNtuple("o1ul","o1ul","mjd:phi:dx:f:dfh:dfl");
  o1ul->ReadFile("./orbit1_300_ULs.txt");
  TNtuple *o2ul=new TNtuple("o2ul","o2ul","mjd:phi:dx:f:dfh:dfl");
  o2ul->ReadFile("./orbit2_300_ULs.txt");
  TNtuple *o3ul=new TNtuple("o3ul","o3ul","mjd:phi:dx:f:dfh:dfl");
  o3ul->ReadFile("./orbit3_300_ULs.txt");
  
  o1->Draw("phi:f:dfh:dfl");
  o2->Draw("phi:f:dfh:dfl");
  o3->Draw("phi:f:dfh:dfl");
  o1ul->Draw("phi:f:dx:dfl");
  o2ul->Draw("phi:f:dx:dfl");
  o3ul->Draw("phi:f:dx:dfl");

  int N=o1->GetEntries();
  TGraphAsymmErrors *g1=new TGraphAsymmErrors(N,o1->GetV1(),o1->GetV2(),0,0,o1->GetV4(),o1->GetV3());
  int N=o2->GetEntries();
  TGraphAsymmErrors *g2=new TGraphAsymmErrors(N,o2->GetV1(),o2->GetV2(),0,0,o2->GetV4(),o2->GetV3());
  int N=o3->GetEntries();
  TGraphAsymmErrors *g3=new TGraphAsymmErrors(N,o3->GetV1(),o3->GetV2(),0,0,o3->GetV4(),o3->GetV3());
  int N=o1ul->GetEntries();
  TGraphAsymmErrors *g1ul=new TGraphAsymmErrors(N,o1ul->GetV1(),o1ul->GetV2(),0,0,o1ul->GetV4(),0);
  TGraphErrors *g1ulline=new TGraphErrors(N,o1ul->GetV1(),o1ul->GetV2(),o1ul->GetV3(),0);
  int N=o2ul->GetEntries();
  TGraphAsymmErrors *g2ul=new TGraphAsymmErrors(N,o2ul->GetV1(),o2ul->GetV2(),0,0,o2ul->GetV4(),0);
  TGraphErrors *g2ulline=new TGraphErrors(N,o2ul->GetV1(),o2ul->GetV2(),o2ul->GetV3(),0);
  int N=o3ul->GetEntries();
  TGraphAsymmErrors *g3ul=new TGraphAsymmErrors(N,o3ul->GetV1(),o3ul->GetV2(),0,0,o3ul->GetV4(),0);
  TGraphErrors *g3ulline=new TGraphErrors(N,o3ul->GetV1(),o3ul->GetV2(),o3ul->GetV3(),0);

  g1->SetMarkerStyle(20);
  g2->SetMarkerStyle(33);
  g2->SetMarkerSize(1.6);
  g3->SetMarkerStyle(21);
  g1ul->SetMarkerStyle(0);
  g2ul->SetMarkerStyle(0);
  g3ul->SetMarkerStyle(0);
  g1ulline->SetMarkerStyle(0);
  g2ulline->SetMarkerStyle(0);
  g3ulline->SetMarkerStyle(0);

  g1->SetMarkerColor(kOrange+1);
  g1ul->SetMarkerColor(kOrange+1);
  g1ulline->SetMarkerColor(kOrange+1);
  g2->SetMarkerColor(kMagenta-3);
  g2ul->SetMarkerColor(kMagenta-3);
  g2ulline->SetMarkerColor(kMagenta-3);
  g3->SetMarkerColor(kBlue+1);
  g3ul->SetMarkerColor(kBlue+1);
  g3ulline->SetMarkerColor(kBlue+1);

  g1->SetLineColor(kOrange+1);
  g1ul->SetLineColor(kOrange+1);
  g1ulline->SetLineColor(kOrange+1);
  g2->SetLineColor(kMagenta-3);
  g2ul->SetLineColor(kMagenta-3);
  g2ulline->SetLineColor(kMagenta-3);
  g3->SetLineColor(kBlue+1);
  g3ul->SetLineColor(kBlue+1);
  g3ulline->SetLineColor(kBlue+1);

  g1->SetFillColor(kOrange+1);
  g1ul->SetFillColor(kOrange+1);
  g1ulline->SetFillColor(kOrange+1);
  g2->SetFillColor(kMagenta-3);
  g2ul->SetFillColor(kMagenta-3);
  g2ulline->SetFillColor(kMagenta-3);
  g3->SetFillColor(kBlue+1);
  g3ul->SetFillColor(kBlue+1);
  g3ulline->SetFillColor(kBlue+1);

  g1ul->Draw("AP|>");
  g1ulline->Draw("PZ");
  g2ul->Draw("P|>");
  g2ulline->Draw("PZ");
  g3ul->Draw("P|>");
  g3ulline->Draw("PZ");
  g1->Draw("P");
  g2->Draw("P");
  g3->Draw("P");

  g1ul->GetXaxis()->SetRangeUser(0,1);
  g1ul->GetYaxis()->SetRangeUser(1e-13,3.7e-11);
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
  g1ul->GetYaxis()->SetTitle("Flux (E>300 GeV) [ph cm^{-2} s^{-1}]");
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
