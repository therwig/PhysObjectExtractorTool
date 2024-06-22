#include "TFile.h"
#include "TChain.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"
#include "TH1F.h"

int main(){
    TChain *c1 = new TChain("myelectrons/Events");
    c1->Add("/eos/user/t/therwig/jtfi/240621_SingleNeutrino_prod1/output_*.root");
    //c1->Add("/eos/user/t/therwig/jtfi/240621_TT_prod1/output_*.root");
    TTreeReader reader(c1);
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
    return 0;
}
