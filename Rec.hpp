#include "Graph.cpp"

class Rec{
public:
    ///Data Members
    vertex<string> *user;
    Graph<string> *friends;
    
    ///Constructor
    Rec(string filename);
    void quit();
    
    ///Functions
    void login();
    void logout();
    void displayfriends();
    int countfriends();
    void addfriend();
    void suggestfriends();
    void listusers();
    bool is_friend(string name);
    
};
