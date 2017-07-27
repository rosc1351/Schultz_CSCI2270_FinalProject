#include "Rec.cpp"

using namespace std;

void menu2(Rec Rec){
    int res = 0;
    while(res != 5){
        cout << "===Menu=== *" << Rec.user->name << endl;
        cout << "1. Add friend" << endl;
        cout << "2. Suggest friends" << endl;
        cout << "3. Display friends" << endl;
        cout << "4. Count Friends" << endl;
        cout << "5. Log out" << endl;
        
        cin >> res;
        
        if(res == 1){
            Rec.addfriend();
        }else if(res == 2){
            Rec.suggestfriends();
        }else if(res == 3){
            Rec.displayfriends();
        }else if(res == 4){
            cout << "You have " << Rec.countfriends() << " friends" << endl;
        }else if(res == 5){
            Rec.logout();
        }
    }
}

int main(int argc, const char * argv[]){
    ///Get filename from command line or user if not provided
    string filename;
    if(argc > 2){
        cout << "Input format: ./[exec] [filename (optional)]" << endl;
    }else if(argc == 2){
        filename = argv[1];
    }else{
        cout << "Filename: " << endl;
        cin >> filename;
    }
    
    ///Initialize graph from file
    Rec Rec(filename);
    
    
    int res = 0;
    
    while(res != 2){
        cout << "===Menu===" << endl;
        cout << "1. Log in" << endl;
        cout << "2. Quit" << endl;
        
        cin >> res;
        
        if(res == 1){
            Rec.login();
            menu2(Rec);
        }else if(res == 2){
            Rec.quit();
        }else if(res == 3){
            //debugging
            Rec.friends->displayEdges();
        }
    }
}
