# Graph

In order to be able to compare it we had to create class Graph which will have vertices and edges. Data about how many vertices there
is for particular graph and how they are connected are stored in one adjacency list. To be able to manipulate with created graph we had
to implement few methods of which some are in class and some are separately.




•	int num_components(Graph a)

Fist method which was given to create needs to count number of components in graph that is created.
We came up with solution to take each vertex from adjacency list and record its connections. With this idea we created
two functions. First function is taking object of type Graph and according to number of its vertices creates array of Booleans
which are all set to 0 at beginning so we can record which vertices are visited. After that we are starting to loop trough vertices
and if vertex is not visited it will call second method and after its execution counter will increase by 1. Second function is based
on DFS. This function will iterate trough all connections of one vertex recursively and set it as visited.


•	bool is_complement(Graph a, Graph b)

Second method is checking are two graphs complement of each other. Idea which we were guided here is checking does the given
graphs have properties of complement graphs. So in order for function to return 1 graphs cannot have different number of vertices;
number their edges combined needs to be equal to the number of edges in connected graph with same number of vertices(to determine
this we used my_choose method); if number of vertices mod 4 is bigger than one it means that edges of connected graph cannot be
divided in in two equal way so two graphs cannot combine one full connected graph; two same vertices cannot be connected in both
graph.


•	bool is_isomorphic(Graph a, Graph b)

Third method checks if two graphs are isomorphic. To determine this our method will check if two graphs have same number of vertices
and edges and if each vertex from both graphs have same number of degrees. If this is satisfied the function will return true.
