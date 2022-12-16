#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <vector>

using namespace std;

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
    
public:
    static TrungSingleton* getInstance() {
        if (_uniqueInstance == NULL) {
            srand(time(NULL));
            int ranNum = rand() % 15;
            _uniqueInstance = new TrungSingleton(ranNum);
        }
        return _uniqueInstance; 
    }

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

TrungSingleton *TrungSingleton::_uniqueInstance = NULL;

void run(){
    TrungSingleton::getInstance()->sayHello();
    // cout << "Hello" << endl;
}

int main(){
    
    // TrungSingleton::getInstance()->sayHello();
    thread thread1(run);
    thread thread2(run);
    thread1.join(); // wait finish thread 1
    thread2.join(); // wait thread 1 finish 

    // vector<thread> threads;
    // threads.push_back(thread1);
    // threads.push_back(thread2); 
    // for (int i = 0; i < threads.size(); i++) {
    //     threads[i].join();
    // }
    
    return 0;
};
