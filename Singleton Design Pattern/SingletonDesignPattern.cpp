#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <vector>

using namespace std;

// class singleton with method constructor private
class TrungSingleton{
private:
    int _index;
    static TrungSingleton *_uniqueInstance;

    TrungSingleton(){
        _index = 0;
    }

    TrungSingleton(int value){
        _index = value;
    }
    
public: // get instance static
    static TrungSingleton* getInstance() {
        if (_uniqueInstance == NULL) {
            srand(time(NULL));
            int ranNum = rand() % 15;
            _uniqueInstance = new TrungSingleton(ranNum);
        }
        return _uniqueInstance; 
    }
public: // Order method
    void sayHello(){
        cout << "Hello, i am Trung number " << _index << endl;
    }

    void setIndex(int index){
        _index = index;
    };

    int getIndex(){
        return _index;
    }
};

// create variable Singleton = NULL
TrungSingleton *TrungSingleton::_uniqueInstance = NULL;

// test code
int main(){
    TrungSingleton *singleton = TrungSingleton::getInstance();
    singleton->sayHello();
    TrungSingleton *singleton1 = TrungSingleton::getInstance();
    singleton1->sayHello();
    return 0;
};
