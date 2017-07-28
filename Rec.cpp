#include "Rec.hpp"

Rec::Rec(string filename){
    friends = new Graph<string>(filename);
}

void Rec::quit(){
    delete friends;
    cout << "Goodbye!" << endl;
}


void Rec::login(){
    string login;
    do{
        cout << "User: " << endl;
        getline(cin, login);
        if(login == "stop"){
            break;
        }
        user = friends->find(login);
    }while(user == nullptr);
}

void Rec::logout(){
    user = nullptr;
}

void Rec::displayfriends(){
    if(user != nullptr){
        for(int i = 0; i < user->adj.size(); i++){
            cout << user->adj[i].v->name << endl;
        }
    }else{
        cout << "log in to see friends" << endl;
    }
}

int Rec::countfriends(){
    if(user != nullptr){
        return (int) user->adj.size();
    }else{
        return -1;
    }
}

void Rec::addfriend(){
    if(user != nullptr){
        string name;
        cout << "Enter Name:" << endl;
        cin.ignore(1000,'\n');
        getline(cin,name);
        if(is_friend(name)){
            cout << name << " is already your friend" << endl;
        }else{
            if(friends->find(name) == nullptr){
                cout << "User does not exist" << endl;
            }else{
                friends->addEdge(user->name, name, 1);
                cout << name << " added as friend" << endl;
            }
        }
    }else{
        cout << "Login to add friends" << endl;
    }
}

void Rec::removefriend(){
    if(user != nullptr){
        string name;
        cout << "Enter Name:" << endl;
        cin.ignore(1000,'\n');
        getline(cin,name);
        if(!is_friend(name)){
            cout << name << " is not in your friends list" << endl;
        }else{
            friends->removeEdge(user->name, name);
        }
    }else{
        cout << "Login to add friends" << endl;
    }

}

void Rec::suggestfriends(){
    //suggest friends
    //for vects in adj vects
        //for friend-of-friend in vects.adj vects
            //if not in list
                //add to list
            //else
            //add to count in existing node;
    //display x greatest counts
    LLstring list;
    for(int i = 0; i < user->adj.size(); i++){
        for(int c = 0; c < user->adj[i].v->adj.size(); c++){
            string name = user->adj[i].v->adj[c].v->name;
            if(name!= user->name && !is_friend(name)){
                list.countappend(name);
            }
            
        }
    }
    list.printbycount();
}

void Rec::listusers(){
    for(int i = 0; i < friends->vertices.size(); i++){
        cout << friends->vertices[i].name << endl;
    }
}

bool Rec::is_friend(string name){
    if(user != nullptr){
        for(int i = 0; i < user->adj.size(); i++){
            if(user->adj[i].v->name == name){
                return true;
            }
        }
    }
    return false;
}
