# Physics Objects Extractor Tool (POET) - 2015MiniAOD

## Description

This POET repository contains packages that verse instructions and examples on how to extract physics (objects) information from Run 2 (MiniAOD format) CMS open/legacy data and methods or tools needed for processing them. These objects can be: electrons, muons, photons, jets, tracks, etc.

Please check out the `README` of a specific package (e.g., [PhysObjectExtractor](/PhysObjectExtractor) and the [tutorials](https://cms-opendata-workshop.github.io/2022-08-01-cms-open-data-workshop/) of the CMS open data workshop for further instructions on how to use the code.

## References

[A list of mostly internal references](https://github.com/cms-opendata-analyses/PhysObjectExtractorTool/issues/64#issuecomment-1121600157)

# My instruction

```
Some instructions here
https://github.com/cms-opendata-analyses/PhysObjectExtractorTool/tree/2015MiniAOD/PhysObjectExtractor

# setup standard CMS software
source /cvmfs/cms.cern.ch/cmsset_default.sh
# setup a software release, same as the one used to collect the data
cmsrel CMSSW_7_6_7
cd CMSSW_7_6_7/src/
git clone -b 2015MiniAOD https://github.com/cms-opendata-analyses/PhysObjectExtractorTool.git
cmsenv
cd PhysObjectExtractorTool/PhysObjectExtractor/
scram b # you can do "scram b -j 4" to compile on 4 threads at once

# Open the python cfg file in your favorite editor, and change the database paths from
# /cvmfs/cms-opendata-conddb.cern.ch/76X_dataRun2_16Dec2015_v0.db
# /cvmfs/cms-opendata-conddb.cern.ch/76X_mcRun2_asymptotic_RunIIFall15DR76_v1.db
# to 
# /atlas/data18a/herwig/database/76X_mcRun2_asymptotic_RunIIFall15DR76_v1.db
# /atlas/data18a/herwig/database/76X_dataRun2_16Dec2015_v0.db
 
nano python/poet_cfg.py

# now you can run the code!
cmsRun python/poet_cfg.py maxEvents=10
# and you see that an output file was generated called "output_numEvent10.root"
# you can look inside it with the root program if you want

root output_numEvent10.root
# and then you can, e.g., open a graphical interface with "TBrowser m"
```

