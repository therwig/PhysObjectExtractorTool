void plot(){
    TChain *c1 = new TChain("myelectrons/Events");
    TChain *c2 = new TChain("mypvertex/Events");
    c1->Add("/eos/user/t/therwig/jtfi/240621_SingleNeutrino_prod1/output_*.root");
    c2->Add("/eos/user/t/therwig/jtfi/240621_SingleNeutrino_prod1/output_*.root");
    TTreeReader reader1(c1);
    TTreeReaderArray<float> ele_pt(reader1, "electron_pt");
    TTreeReader reader2(c2);
    TTreeReaderValue<int> npv(reader2, "PV_npvs");
    
    TFile* fout = new TFile("hist.root","recreate");
    TH1F* h1 = new TH1F("nEle",";number of high-pt electrons",6,-0.5,5.5);
    TH1F* h2 = new TH1F("nPV",";number of primary vertices",30,-0.5,29.5);
    TH2F* h3 = new TH2F("nEle_vs_nPV",";number of primary vertices;number of high-pt electrons",30,-0.5,29.5,6,-0.5,5.5);

    int nEvents=0;
    while (reader1.Next() && reader2.Next()) {
        unsigned int nEle=0;
        for(unsigned int i=0; i < ele_pt.GetSize(); i++){
            if (ele_pt[i] > 5) nEle++;
        }
        h1->Fill(nEle);
        h2->Fill(*npv);
        h3->Fill(*npv,nEle);
        nEvents++;
        //if (nEvents>1e7) break;
    }
    fout->Write();
    gSystem->Exit(0);
}
