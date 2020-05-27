#include <bits/stdc++.h>
using namespace std;

//Creating graph using adjacency lists
class Graph {

public:
    // Constructor
    int V;
    int nbrE=0;
    list<int>* adlist;

    Graph(int V);
    unsigned long long int my_choose();
    void addEdge(int v, int w);
    void printGraph() ;

};

//setting number of vertices and creating adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adlist = new list<int>[V];
}


//adding edges to list and counting number of edges
void Graph::addEdge(int v, int w){

    adlist[v].push_back(w);
    adlist[w].push_back(v);
    nbrE++;
}

//printing out graph in console
void Graph::printGraph(){

    for (int v = 0; v < V; ++v)
    {
        cout << "-Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adlist[v])
           cout << " -> " << x;
           printf("\n");

    }

}

//calculating combinations in order to find out what is maximum number of edges for graph
//this function is simmilar to one in part one of project
unsigned long long int  Graph::my_choose(){
    int n=V;
        int M[n+1][3];
        for (int i=0;i<=n;i++){
            for(int j=0;j<=min(i,2);j++ ){
                if(j == 0 || j == i){
                    M[i][j] =1;}
                else
                    M[i][j]= M[i-1][j-1] + M[i-1][j];
            }
        }
    return M[n][2];
    }

// iterating trough list to check which vertices are visited and connected
void DFS(int v, bool visited[], Graph a){

    // mark the current node as visited
    visited[v] = true;
    list<int>* adj = a.adlist;

    // recur for all the vertices
    // connected to this vertex
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited,a);
}

// checking how many components are in graph
int num_components(Graph a)
{

    // set all the vertices as not visited and setting
    //counter for number of components
    bool* visited = new bool[a.V];
    int count = 0;
    for (int i = 0; i < a.V; i++)
        visited[i] = false;

    for (int i = 0; i < a.V; i++) {
        //if not visited then check it connections
        if (visited[i] == false) {
            DFS(i, visited, a);
            count += 1;
        }
    }

    return count;
}


// counting how many degree each vertex heve
int countdegree(Graph a, int ver){

    int edges =0;
    for(auto x: a.adlist[ver])
        edges++;

    return edges;

    }

// checking for isomorphism of two graphs
bool is_isomorphic(Graph a, Graph b){

    //if they have different number of edges and vertices they cannot be isomorpihc
    if((a.V != b.V) || (a.nbrE != b.nbrE)){
        return false;
    }

    //if one vertex have different number of edges than one in other graph, graph is not isomorphic
    for (int v = 0; v < a.V; ++v)
    {

        if(countdegree(a,v) != countdegree(b,v) )
            return false;
        }

    return true;
}

//checking if two graphs are complement of each other
bool is_complement(Graph a, Graph b){

    // will not be complement if number of vertices are different
    if((a.V != b.V) ){
        return false;
        }

    //if sum of edges of two graph is not equal to number of edges that graph
    //need to have to be complete graph, then it is not complete
    if(a.my_choose()!=(a.nbrE + b.nbrE)){
        return false;
    }

    //if number of edges in complete graph cannot be divide equally on two graph
    //then it will not be complete graph
    if((a.V%4)>1){
        return false;
    }

    //if edges of both graph are connecting same two vertices then it is not complete graph
    for (int v = 0; v < a.nbrE; ++v){
        for (auto xa : a.adlist[v] )
            for (auto xb : b.adlist[v] )
                if(xa == xb )
                    return false;
        }

    return true;
    }


    //test
int main()
{

    Graph g(5);
   /* g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);*/
/*isomorphic
   // g.addEdge(1, 4);
    g.addEdge(1, 0);
   // g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    //new graph
    g.addEdge(5,4);
    g.addEdge(4,3);
    g.addEdge(3,2);
    g.addEdge(2,1);
    g.addEdge(1,0);
    g.addEdge(0,5);
    g.addEdge(0,4);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(6,2);
    g.addEdge(6,5);*/

    //complement
/*nbr1 correct
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(3,0);*/

    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(3,0);
    g.addEdge(4,2);
    //g.addEdge(2,0);

    Graph h(5);
/*isomorphic

    h.addEdge(1, 0);
   // h.addEdge(0, 2);
    h.addEdge(2, 3);
    h.addEdge(3, 4);*/

    /*h.addEdge(5,3);
    h.addEdge(4,3);
    h.addEdge(3,2);
    h.addEdge(2,1);
    h.addEdge(1,0);
    h.addEdge(0,5);
    h.addEdge(0,4);
    h.addEdge(1,4);
    h.addEdge(2,5);

    //newgraph
    h.addEdge(0,1);
    h.addEdge(1,2);
    h.addEdge(2,0);
    h.addEdge(5,4);
    h.addEdge(4,3);
    h.addEdge(5,3);*/

/*nbr1 correct
    h.addEdge(2,0);
    h.addEdge(2,1);
    h.addEdge(2,3);*/

    h.addEdge(0,3);
    h.addEdge(3,2);
    h.addEdge(2,1);
    h.addEdge(1,4);
    h.addEdge(4,0);

    g.printGraph();

    h.printGraph();

    cout<<"--------------------------"<<endl;
    cout << "Number of components in graph:" << num_components(g)<<endl;
    cout << "Number of components in graph:" <<num_components(h)<<endl;

    cout <<"Are this graphs isomorphic?\n"<< is_isomorphic(g,h)<<endl;

    cout<<"Are this graphs complement?\n"<<is_complement(g,h);

    return 0;
}
