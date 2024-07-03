// usage: root "sorter.C(\"comb.root\",\"combo_sorted.root\")" 
void sorter(TString inF, TString outF){
  TFile *f = new TFile(inF);
  TTree *t_raw = (TTree*) f->Get("Events");
  t_raw->LoadBaskets();

  // Create index on tunix branch (time)                                                                                                     
  Int_t nb_idx = t_raw->BuildIndex("PV_npvs");
  TTreeIndex* att_index = (TTreeIndex*) t_raw->GetTreeIndex();

  TFile *fo = new TFile(outF,"recreate","",209);
  TTree* t = (TTree*) t_raw->CloneTree(0);
  t->SetName("Events");

  // Loop on t_raw entries and fill t                                                                                                        
  for( Long64_t i = 0; i < att_index->GetN(); i++ ) {
    t_raw->GetEntry( att_index->GetIndex()[att_index->GetN()-i] );
    t->Fill();
  }
  t->Write();
  fo->Close();
  gSystem->Exit(0);
}
