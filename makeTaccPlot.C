{
//20
//27.3296
//37.3452
//51.0314
//69.7333
//95.289
//130.21
//177.93
//243.137
//332.241
//454


  TF1 *e20=new TF1("e20","20/x",1e-4,6);
  TF1 *e27=new TF1("e27","27/x",1e-4,6);
  TF1 *e37=new TF1("e37","37/x",1e-4,6);
  TF1 *e51=new TF1("e51","51/x",1e-4,6);
  TF1 *e70=new TF1("e70","70/x",1e-4,6);
  TF1 *e95=new TF1("e95","95/x",1e-4,6);
  TF1 *e130=new TF1("e130","130/x",1e-4,6);
  TF1 *e178=new TF1("e178","178/x",1e-4,6);
  TF1 *e243=new TF1("e243","243/x",1e-4,6);
  TF1 *e332=new TF1("e332","332/x",1e-4,6);
  TF1 *e454=new TF1("e454","454/x",1e-4,6);

  TColor *c0=new TColor(1100,0,0,0.2);
  TColor *c1=new TColor(1101,0.05,0.1,0.4);
  TColor *c2=new TColor(1102,0.1,0.2,0.6);
  TColor *c3=new TColor(1103,0.15,0.3,0.8);
  TColor *c4=new TColor(1104,0.2,0.4,1);
  TColor *c5=new TColor(1105,0.25,0.5,1);
  TColor *c6=new TColor(1106,0.3,0.6,1);
  TColor *c7=new TColor(1107,0.35,0.7,1);
  TColor *c8=new TColor(1108,0.4,0.8,1);
  TColor *c9=new TColor(1109,0.45,0.9,1);
  TColor *c10=new TColor(1110,0.6,1,1);

  e20->SetLineColor(1100);
  e27->SetLineColor(1101);
  e37->SetLineColor(1102);
  e51->SetLineColor(1103);
  e70->SetLineColor(1104);
  e95->SetLineColor(1105);
  e130->SetLineColor(1106);
  e178->SetLineColor(1107);
  e243->SetLineColor(1108);
  e332->SetLineColor(1109);
  e454->SetLineColor(1110);

  TCanvas *c=new TCanvas();
  c->SetLogx();
  c->SetLogy();

  e454->GetYaxis()->SetRangeUser(100,5e6);
  e454->GetXaxis()->SetLabelFont(132);
  e454->GetYaxis()->SetLabelFont(132);
  e454->GetXaxis()->SetTitleFont(132);
  e454->GetYaxis()->SetTitleFont(132);
  e454->GetXaxis()->CenterTitle();
  e454->GetXaxis()->SetTitleSize(0.05);
  e454->GetXaxis()->SetTitleOffset(0.95);
  e454->GetYaxis()->CenterTitle();
  e454->GetYaxis()->SetTitleSize(0.05);
  e454->GetYaxis()->SetTitleOffset(0.95);
  e454->GetYaxis()->SetTitle("t_{acc} [s]");
  e454->GetXaxis()->SetTitle("B [G]");
  e454->SetTitle("");

  e454->Draw();
  e332->Draw("same");
  e243->Draw("same");
  e178->Draw("same");
  e130->Draw("same");
  e95->Draw("same");
  e70->Draw("same");
  e51->Draw("same");
  e37->Draw("same");
  e27->Draw("same");
  e20->Draw("same");

  double xp[6]={1e-4, 0.3, 0.3, 1.39e-3 ,1e-4, 1e-4};
  double yp[6]={100, 100, 400, 86400, 86400, 100};
  TGraph *periarea=new TGraph(6,xp,yp);
  //periarea->SetFillColorAlpha(c10,0.1);
  periarea->SetFillColor(1106);
  //periarea->SetFillStyle(3344);
  periarea->Draw("F");

  double xa[6]={1e-4, 0.1, 0.1, 5.255e-3, 1e-4, 1e-4};
  double ya[6]={100, 100, 4.54e3, 86400, 86400, 100};
  TGraph *aparea=new TGraph(6,xa,ya);
  //aparea->SetFillColoralpha(c6,0.1);
  aparea->SetFillColor(1110);
  //aparea->SetFillStyle(3444);
  aparea->Draw("F");


  TLine *day=new TLine(1e-4,86400,0.3,86400);
  day->SetLineStyle(3);
  day->SetLineColor(kBlack);
  day->Draw("same");

  TLine *bperi=new TLine(0.3,100,0.3,86400);
  bperi->SetLineStyle(3);
  bperi->SetLineColor(kBlack);
  bperi->Draw("same");

  TLine *bap=new TLine(0.1,100,0.1,86400);
  bap->SetLineStyle(3);
  bap->SetLineColor(kBlack);
  bap->Draw("same");

  TLatex daylabel;
  daylabel.SetTextFont(132);
  daylabel.SetTextSize(0.04);
  //daylabel.SetNDC();
  daylabel.DrawLatex(0.02,1e5,"t_{acc} = 1 day");

  TLatex peri;
  peri.SetTextFont(132);
  peri.SetTextSize(0.04);
  peri.SetTextAngle(-90);
  //peri.SetNDC();
  peri.DrawLatex(0.397,4e4,"B_{periastron}");

  TLatex ap;
  ap.SetTextFont(132);
  ap.SetTextSize(0.04);
  ap.SetTextAngle(-90);
  //ap.SetNDC();
  ap.DrawLatex(0.13,4e4,"B_{apastron}");

  TLegend *l=new TLegend(0.75,0.4,0.89,0.86);
  l->SetTextFont(132);
  l->SetFillColor(0);
  l->SetBorderSize(0);
  l->AddEntry(e20,"#eta=20","l");
  l->AddEntry(e27,"#eta=27","l");
  l->AddEntry(e37,"#eta=37","l");
  l->AddEntry(e51,"#eta=51","l");
  l->AddEntry(e70,"#eta=70","l");
  l->AddEntry(e95,"#eta=95","l");
  l->AddEntry(e130,"#eta=130","l");
  l->AddEntry(e178,"#eta=178","l");
  l->AddEntry(e243,"#eta=243","l");
  l->AddEntry(e332,"#eta=332","l");
  l->AddEntry(e454,"#eta=454","l");
  l->Draw("same");

}
