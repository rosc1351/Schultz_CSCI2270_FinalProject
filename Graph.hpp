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


template<class T>
class Graph
{
    public:
        Graph(string filename);
        ~Graph();
        void addEdge(T v1, T v2, int weight);
        void addVertex(T name);
        void displayEdges();
        vertex<T> *find(T name);
    
        vector<vertex<T> > vertices;
    
    protected:
    private:
    

};

template<class T>
Graph<T>::Graph(string filename){
    ifstream file(filename);
    if(!file.is_open()){
        cout << "Error opening file" << endl;
    }else{
        string line;
        getline(file, line);
        LLstring data;
        data.split(line);
        node *tmp = data.head;
        while(tmp != nullptr){
            addVertex(tmp->key);
            tmp = tmp->next;
        }
        while(file.good()){
            getline(file, line);
            if(line != ""){
                data.split(line);
                string user = data.head->key;
                tmp = data.head->next;
                while(tmp != nullptr){
                    addEdge(user, tmp->key, 1);
                    tmp = tmp->next;
                }
            }
        }
    }
}
