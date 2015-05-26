{
  TF1 *acciari=new TF1("acciari","2.89e-12*pow(x,-2.40)",0.3,20);
  TF1 *aleksic=new TF1("aleksic","2.3e-13*pow(x,-2.5)",0.3,20);
  TF1 *avg=new TF1("avg","1.7e-12*pow(x,-2.35)",0.3,20);
  TF1 *f1=new TF1("f1","8.6e-12*pow(x,-2.24)",0.3,20);
  TF1 *f2=new TF1("f2","4.8e-12*pow(x,-2.36)",0.3,20);

  acciari->SetLineColor(kGray+2);
  aleksic->SetLineColor(kGray+2);
  avg->SetLineColor(kBlack);
  avg->SetLineStyle(3);
  f1->SetLineColor(kBlack);
  f1->SetLineStyle(7);
  f2->SetLineColor(kBlack);
  f2->SetLineStyle(6);

  TNtuple *d1=new TNtuple("d1","d1","e:f:df");
  d1->ReadFile("AvgSpec.txt");
  d1->Draw("e:f:df");
  TGraphErrors *g1=new TGraphErrors(6,d1->GetV1(),d1->GetV2(),0,d1->GetV3());
  g1->SetMarkerStyle(24);

  TNtuple *d2=new TNtuple("d2","d2","e:f:df");
  d2->ReadFile("F1Spec.txt");
  d2->Draw("e:f:df");
  TGraphErrors *g2=new TGraphErrors(6,d2->GetV1(),d2->GetV2(),0,d2->GetV3());
  g2->SetMarkerStyle(26);

  TNtuple *d3=new TNtuple("d3","d3","e:f:df");
  d3->ReadFile("F2Spec.txt");
  d3->Draw("e:f:df");
  TGraphErrors *g3=new TGraphErrors(5,d3->GetV1(),d3->GetV2(),0,d3->GetV3());
  g3->SetMarkerStyle(32);

  TCanvas *c1=new TCanvas("c1","c1",500,500);
  c1->SetLogx();
  c1->SetLogy();

  g1->GetXaxis()->SetRangeUser(0.35,25);
  g1->GetYaxis()->SetRangeUser(1e-16,2e-10);
  g1->GetXaxis()->SetLabelFont(132);
  g1->GetYaxis()->SetLabelFont(132);
  g1->GetXaxis()->SetTitleFont(132);
  g1->GetYaxis()->SetTitleFont(132);
  g1->GetXaxis()->CenterTitle();
  g1->GetXaxis()->SetTitleSize(0.05);
  g1->GetXaxis()->SetTitleOffset(1);
  g1->GetYaxis()->CenterTitle();
  g1->GetYaxis()->SetTitleSize(0.05);
  g1->GetYaxis()->SetTitleOffset(1.15);
  g1->GetXaxis()->SetTitle("Energy [TeV]");
  g1->GetYaxis()->SetTitle("dN/dE [cm^{-2} s^{-1} TeV^{-1}]");
  g1->SetTitle("");

  g1->Draw("AP");
  g2->Draw("P");
  g3->Draw("P");
  avg->Draw("same");
  f1->Draw("same");
  f2->Draw("same");
  acciari->Draw("same");
  aleksic->Draw("same");

  TLegend *l=new TLegend(0.55,0.65,0.88,0.88);
  l->SetTextFont(132);
  l->SetFillColor(0);
  l->SetBorderSize(0);
  l->AddEntry(avg,"2014 fit to all data","l");
  l->AddEntry(g1,"2014 all data","p");
  l->AddEntry(f1,"2014 fit to F1","l");
  l->AddEntry(g2,"2014 F1 data","p");
  l->AddEntry(f2,"2014 fit to F2","l");
  l->AddEntry(g3,"2014 F2 data","p");
  l->Draw("same");

}
