#include <string>
#include <sstream>

#include "LLstring.hpp"

using namespace std;

LLstring::LLstring(){
    head = nullptr;
    tail = nullptr;
}

LLstring::~LLstring(){
    node *tmp = head;
    while(tmp != nullptr){
        node *del = tmp;
        tmp = tmp->next;
        head = tmp;
        delete del;
    }
}

int LLstring::size(){
    if(head == nullptr){
        return 0;
    }else{
        node *tmp = head;
        int c = 0;
        while(tmp != nullptr){
            c++;
            tmp = tmp->next;
        }
        return c;
    }
}

void LLstring::append(string k){
    if(k != ""){
        if(head == nullptr){
            head = new node;
            head->key = k;
            tail = head;
        }else{
            tail->next = new node;
            tail->next->key = k;
            tail = tail->next;
            tail->next = nullptr;
        }
    }
}

void LLstring::countappend(string k){
    if(k != ""){
        if(head == nullptr){
            head = new node;
            head->key = k;
            tail = head;
            tail->next = nullptr;
        }else{
            node *tmp = head;
            bool add = false;
            while(tmp != nullptr){
                if(tmp->key == k){
                    tmp->count = tmp->count + 1;
                    add = true;
                }
                tmp = tmp->next;
            }
            if(!add){
                tail->next = new node;
                tail->next->key = k;
                tail = tail->next;
                tail->next = nullptr;
            }
            
        }
    }
}

void LLstring::prepend(string k){
    if(head == nullptr){
        head = new node;
        head->key = k;
        tail = head;
    }else{
        node *tmp = new node;
        tmp->key = k;
        tmp->next = head;
        head = tmp;
    }
}

void LLstring::empty(){
    if(size() != 0){
        node *tmp = head;
        while(tmp != nullptr){
            node *del = tmp;
            tmp = tmp->next;
            delete del;
        }
        head = nullptr;
        tail = nullptr;
    }
}

node *LLstring::find(string s){
    node *tmp = head;
    while(tmp != nullptr){
        if(tmp->key == s){
            return tmp;
        }else{
            tmp = tmp->next;
        }
    }
    return nullptr;
}

node *LLstring::split(string line, char delimiter){
    empty();
    stringstream sline;
    sline << line;
    while(sline.good()){
        string data;
        getline(sline, data, delimiter);
        append(data);
    }
    return head;
}

node *LLstring::split(string line){
    return split(line, ',');
}

void LLstring::sortbycount(){
    int max = 0;
    node *tmp = head;
    while(tmp != nullptr){
        if(tmp->count > max){
            max = tmp->count;
        }
        tmp = tmp->next;
    }
    int count = 1;
    for(int i = max; i > 0; i--){
        tmp = head;
        while(tmp != nullptr){
            if(count % 5 == 0){
                cout << "====See more==== yes:1 no:0" << endl;
                cin >> count;
                if(count == 0){
                    return;
                }
            }
            if(tmp->count == i){
                cout << tmp->key << " ~~Count: " << tmp->count << endl;
                count++;
            }
            tmp = tmp->next;
        }
    }
}
