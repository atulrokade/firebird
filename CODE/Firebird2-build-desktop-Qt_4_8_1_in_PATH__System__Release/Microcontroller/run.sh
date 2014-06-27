rm -f mk
rm -f main
g++ makeInputFile.cpp -o mk
./mk
g++ FireBird.h FireBird.cpp main.cpp -o main
./main
