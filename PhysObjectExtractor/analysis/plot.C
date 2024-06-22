void plot(){
    TFile* f1 = new TFile("TT_10k.root");
    TTreeReader reader("myelectrons/Events", f1);
    TTreeReaderArray<float> ele_pt(reader, "electron_pt");
    
    TFile* fout = new TFile("hist.root","recreate");
    TH1F* h1 = new TH1F("h1",";number of high-pt electrons",6,-0.5,5.5);
    
    while (reader.Next()) {
        unsigned int nEle=0;
        for(unsigned int i=0; i < ele_pt.GetSize(); i++){
            if (ele_pt[i] > 5) nEle++;
        }
        h1->Fill(nEle);
    }
    fout->Write();
    gSystem->Exit(0);
}
