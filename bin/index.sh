# THIS IS bash script for executing the game
#!bin/bash
cd ..
cd src
gcc Main.c

#copy a.out file to bin folder
cp a.out ../bin

# navigate to bin folder
cd ..
cd bin

#execute the app
./a.out