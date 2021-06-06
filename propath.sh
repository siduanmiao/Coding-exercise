#!/bin/bash
function help () {
if [[ $2 == "--help" || $2 == "-h" ]]
then
cat README.txt | sed -n "/$1:/p"
exit -1
fi

}

if [[ $1 == "-d" ]]
then
help $1 $2
make -f Dijkstra.txt
./Dijkstra $2 $3
elif [[ $1 == "-f" ]]
then
help $1 $2
make -f Floyd-Warshall.txt
./Floyd-Warshall 
elif [[ $1 == "-o" ]]
then
help $1 $2
make -f older_Dijkstra.txt
./older_Dijkstra $2 $3
elif [[ $1 == "-b" ]]
then
help $1 $2
make -f Bellman_Ford.txt
./Bellman_Ford $2 $3
elif [[ $1 == "-t" ]]
then
help $1 $2
make -f Dijkstra.txt
make -f older_Dijkstra.txt
make -f Bellman_Ford.txt
echo "optimlized Dijkstra time:"
time ./Dijkstra $2 $3
echo "Dijkstra time:"
time ./older_Dijkstra $2 $3
echo "Bellman_Ford time:"
time ./Bellman_Ford $2 $3
elif [[ $1 == "--option" ]]
then 
cat README.txt | sed -n 49,61p
else
echo "Your option is not correct ,please input again  !!!"	
fi

