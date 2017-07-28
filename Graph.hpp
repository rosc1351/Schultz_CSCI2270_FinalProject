#include <iostream>
#include <vector>
#include <fstream>

#include "LLstring.cpp"

using namespace std;

template<class T>
struct vertex;

template<class T>
struct adjVertex{
    vertex<T> *v;
    int weight;
};

template<class T>
struct vertex{
    T name;
    vector<adjVertex<T> > adj;
};


///Use class == string for reccomender system
template<class T>
class Graph
{
public:
    ///Data
    vector<vertex<T> > vertices;
    
    ///Constructor/destructor
    Graph(string filename);
    ~Graph();
    
    ///Functions
    void addEdge(T v1, T v2, int weight);
    void removeEdge(T v1, T v2);
    void addVertex(T name);
    void displayEdges();
    vertex<T> *find(T name);
    
private:
};

