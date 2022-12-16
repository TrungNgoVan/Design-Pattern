#include <iostream>
#include <vector>

using namespace std;

class Observer{
public:
    virtual void notify() = 0; // virtual function 
};

class Subject{
private:
    vector<Observer *> observers;
public:
    // Construct
    Subject(){
        // Do nothing
    }
    // Method & operator
    void addObserver(Observer *){
        
    }

    void deleteObserver(Observer *){

    }

    void notifyObserver(Observer *){

    }
};

class YoutubeNotify{

};

class PhoneNotify{

};

class EmailNotify{
    
};

class Video{
private:
    string _title;
    string _description;
    string _name;
public:
    //Setter / Getter
    void setTitle(string value){
        _title = value;
    }

    string getTitle(){
        return _title;
    }

    void setDescription(string value){
        _description = value;
    }

    string getDescription(){
        return _description;
    }

    void setName(string value){
        _name = value;
    }

    string getName(){
        return _name;
    }


};


int main(){

    return 0;
}
