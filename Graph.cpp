#include "Graph.hpp"

template<class T>
Graph<T>::~Graph()
{
}

template<class T>
void Graph<T>::addEdge(T v1, T v2, int weight){

    for(int i = 0; i < vertices
.size(); i++){
        if(vertices[i].name == v1){
            bool found = false;
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    found = true;
                    adjVertex<T> av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}

template<class T>
void Graph<T>::addVertex(T n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex<T> v;
        v.name = n;
        vertices.push_back(v);

    }
}

template<class T>
void Graph<T>::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }

}

template<class T>
vertex<T> *Graph<T>::find(T name){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == name){
            cout<<vertices[i].name<<" found."<<endl;
            return &vertices[i];
        }
    }
    return nullptr;
}
