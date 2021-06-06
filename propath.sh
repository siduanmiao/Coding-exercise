#!/bin/bash

if [[ $1 == "-d" ]]
then
make -f Dijkstra.txt
./Dijkstra $2 $3
elif [[ $1 == "-f" ]]
then
make -f Floyd-Warshall.txt
./Floyd-Warshall 
elif [[ $1 == "-o" ]]
then
make -f older_Dijkstra.txt
./older_Dijkstra 
elif [[ $1 == "-b" ]]
then
make -f Bellman_Ford.txt
./Bellman_Ford $2 $3
else
echo "Your option is not correct ,please input again  !!!"	
fi
