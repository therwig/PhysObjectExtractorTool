import ROOT, sys
if len(sys.argv)<3: exit('usage: python reformat.py inFile.root outFile.root')
inFileName = sys.argv[1]
outFileName = sys.argv[2]

toSave = {
    'myelectrons': [ 'electron_e', 'electron_pt', 'electron_eta', 'electron_phi', ],
    'mymuons': [ 'muon_e', 'muon_pt', 'muon_eta', 'muon_phi', ],
    'myjets': [ 'jet_e', 'jet_pt', 'jet_eta', 'jet_phi', 'jet_corrpt', 'jet_btag', ],
    'myelectrons': [ 'electron_pt', 'electron_eta', 'electron_phi', ],
    'mymets': [ 'met_pt', 'met_e', 'met_phi', ],
    'mypvertex': [ 'PV_npvs', ],
}

infile = ROOT.TFile(inFileName)
trees = [ infile.Get(k+'/Events') for k in toSave.keys()]

for t in trees[1:]:
    trees[0].AddFriend(t)

columnsToSave = []
for k in toSave: columnsToSave += toSave[k]

df = ROOT.RDataFrame( trees[0] )
opts = ROOT.RDF.RSnapshotOptions()
opts.fCompressionAlgorithm = ROOT.RCompressionSetting.EAlgorithm.kLZMA
opts.fCompressionLevel = 9
opts.fOverwriteIfExists = True
df.Snapshot('Events', outFileName, columnsToSave, opts)
