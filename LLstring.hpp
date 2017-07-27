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
    
    ///Functions
    int size();
    void append(string k);
    void countappend(string k);
    void prepend(string k);
    void empty();
    node *find(string s);
    node *split(string line, char delimiter);
    node *split(string line);
    node *head;
    node *tail;
    void sortbycount();
    
};
