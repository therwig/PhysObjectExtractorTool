echo running the python loop
time python plot.py

echo Running the interpreted c++ macro
time root -b plot.C

echo Running compiled c++ program
g++ plot.cxx $(root-config --cflags --glibs) -o run
time ./run
