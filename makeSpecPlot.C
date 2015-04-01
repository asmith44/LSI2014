{
  //gStyle->SetOptFit(1111);
  TNtuple *d=new TNtuple("d","d","ecen:elow:ehigh:f:df");
  d->ReadFile("AllSpec.txt");
  double e[6], el[6], eh[6], flux[6], dflux[6];
  d->Draw("elow:ecen:ehigh");
  for( int i=0; i<6; i++ ){
    e[i]=d->GetV2()[i];
    el[i]=d->GetV2()[i] - d->GetV1()[i];
    eh[i]=d->GetV3()[i] - d->GetV2()[i];
  }
  d->Draw("f:df");
  for( int i=0; i<6; i++ ){
    flux[i]=d->GetV1()[i]*1e-4;
    dflux[i]=d->GetV2()[i]*1e-4;
  }
  TGraphAsymmErrors *spec=new TGraphAsymmErrors(6,e,flux,el,eh,dflux,dflux);
  spec->SetMarkerStyle(20);
  TCanvas *c1=new TCanvas("c1","c1",500,500);
  c1->SetLogx();
  c1->SetLogy();
  spec->GetXaxis()->SetRangeUser(0.3,20);
  spec->GetYaxis()->SetRangeUser(1e-15,3e-11);
  spec->GetXaxis()->SetLabelFont(132);
  spec->GetYaxis()->SetLabelFont(132);
  spec->GetXaxis()->SetTitleFont(132);
  spec->GetYaxis()->SetTitleFont(132);
  spec->GetXaxis()->CenterTitle();
  spec->GetXaxis()->SetTitleSize(0.05);
  spec->GetXaxis()->SetTitleOffset(1);
  spec->GetYaxis()->CenterTitle();
  spec->GetYaxis()->SetTitleSize(0.05);
  spec->GetYaxis()->SetTitleOffset(1.15);
  spec->GetXaxis()->SetTitle("Energy [TeV]");
  spec->GetYaxis()->SetTitle("dN/dE [cm^{-2} s^{-1} TeV^{-1}]");
  spec->SetTitle("");
  spec->Draw("AP");

  TF1 *specfit=new TF1("specfit","[0]*pow(x,[1])");
  specfit->SetLineColor(kBlack);
  specfit->SetParNames("Norm","Index");
  spec->Fit("specfit");

  TPaveText *pte=new TPaveText(0.11,0.12,0.8,0.23,"NDC");
  pte->SetBorderSize(0);
  pte->SetFillColor(0);
  pte->SetTextFont(132);
  pte->SetTextAlign(12);
  pte->AddText("dN/dE =");
  TString st1;
  st1.Form("(%4.2f #pm %4.2f) #times 10^{-12} (E/1 TeV)^{%4.2f #pm %4.2f} [cm^{-2} s^{-1} TeV^{-1}]", specfit->GetParameter(0)/1e-12, specfit->GetParError(0)/1e-12, specfit->GetParameter(1), specfit->GetParError(1) );
  pte->AddText(st1);
  //pte->AddText("[cm^{-2} s^{-1} TeV^{-1}]");
  TString st2;
  st2.Form("#chi^{2}/NDF = %4.2f/%d", specfit->GetChisquare(), specfit->GetNDF() );
  pte->AddText(st2);
  pte->Draw();
}
