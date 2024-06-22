import ROOT
f1 = ROOT.TFile('TT_10k.root')
t1 = f1.Get('myelectrons/Events')

fout = ROOT.TFile('hist.root','recreate')
h1 = ROOT.TH1F('h1',';number of high-pt electrons',6,-0.5,5.5)

for event in t1:
    nEle=0
    for ele_pt in event.electron_pt:
        if ele_pt > 5: nEle += 1
    h1.Fill(nEle)

fout.Write()
exit(0)

# c = ROOT.TCanvas()
# c.SetLogy()
# h1.SetLineColor(ROOT.kBlack)
# h1.Draw()
# c.SaveAs('example.pdf')
