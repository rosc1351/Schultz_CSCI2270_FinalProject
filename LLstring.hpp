#include <string>
#include <sstream>

using namespace std;

struct node{
    string key;
    node* next = nullptr;
    int count = 1;
};

class LLstring{
public:
    ///Constructor and Destructor
    LLstring();
    ~LLstring();
    
    ///Data
    node *head;
    node *tail;
    
    ///Functions
    int size();
    void append(string k);
    void countappend(string k); ///Use append() if not counting for the sake of efficency
    void prepend(string k);
    void empty(); ///Erases list
    node *find(string s);
    node *split(string line, char delimiter);
    node *split(string line);
    void printbycount();
    
};
