//README
In our program, we use three algorithms to finish our work:
	Dijkstra
	Floyd-Warshall
	Bellman_Ford
also,there are two types of  Dijkstra algorithms, one is the trditional Dijkstra algorithm(older_Dijkstra),  another is a program optimized by C++(Dijkstra). 
Thus , if you want to use our source codes, you must have:
	gcc g++
In our package, every  algorithm has these items:(use Floyd-Warshall as example)
	Floyd-Warshall.c
	Floyd-Warshall.o
	Floyd-Warshall.txt
the Floyd-Warshall.c is the source code of Floyd-Warshall algorithm,and the Floyd-Warshall.txt is the makefile to deal the source code.
Because these algorithms have some procedures in common, we make a head file and some common functions to simplify our code,the functions are:
	head file:
		common.h
		Dijkstra.h
	function:
		usage
		num_protein_make
		judge
		array_make
		creat_new
these functions all have their own .o and .c files.
Addition to the files above, there are :
	num_protein.txt
	new.txt
	result.txt
	filename.txt
	1504319.protein.links.v11.0.txt
	propath.sh
the result.txt filename.txt 1504319.protein.links.v11.0.txt are test files, we use them to test our code:
	result.txt is the result after we use Floyd-Warshall algorithm
	the filename.txt is the input file before we use Floyd-Warshall algorithm.
	the 1504319.protein.links.v11.0.txt is the source data we input to all the algorithms.
the num_protein.txt and new.txt are the files in the process for all  algorithms,you needn't know them ,but if you want to check the data,you can scan them
	num_protein.txt:
		we transfer our proteins name  to numbers , this file store the Correspondence
	new.txt:
		using the 	Correspondence we stored in the num_protein.txt to transfer the source data to a pure num file
propath.sh is a bash file ,you can use it to call all the algorithms.



if you want to use propath.sh,then use :
	bash propath.sh -option [option1] [option2]
option:

	-f:using Floyd-Warshall algorithm,you can't add option1 and option2
		
	-d:using Dijkstra algorithm,you must add option1 and option2

	-b:using Bellman_Ford algorithm,you must add option1 and option2

	-o:using older_Dijkstra algorithm,you must add option1 and option2
	
	-t:process Dijkstra Bellman_Ford older_Dijkstra algorithms and output their time
	
	--option:show all the options you can use
	
	if the use "-option --help" or "-option -h",you can call the useful line of the help file
    
option1:protein1
	
option2:protein1

Examples in use:

	./Floyd-Warshall	using the file input and gain the result.txt as result 
	./Dijkstra protein1 protein2	process the protein1 protein2
	./Bellman_Ford protein1 protein2	process the protein1 protein2
	./older_Dijkstra protein1 protein2	process the protein1 protein2
	

