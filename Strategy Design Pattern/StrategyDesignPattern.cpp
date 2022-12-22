/**
 * @file StrategyDesignPattern.cpp
 * @author Ngo Van Trung (trung2601.it@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
using namespace std;

class IPromoteStrategy{ // Interface Promote Strategy
public:
    virtual double DoDiscount(double) = 0;
};

class NoDiscountStrategy : public IPromoteStrategy{
    double DoDiscount(double price){
        return price;
    }
};

class QuarterDiscountStrategy : public IPromoteStrategy{
    double DoDiscount(double price){
        return price * 0.75;
    }
};


class HalfDiscountStrategy : public IPromoteStrategy{
    double DoDiscount(double price){
        return price * 0.5;
    }
};

class Ticket{
private:
    double _price;
    string _name;
    IPromoteStrategy *_promoteStrategy;
public:

    Ticket(){
        //Do nothing
    }

    Ticket(IPromoteStrategy *promoteStrategy){
        _promoteStrategy = promoteStrategy;
    }

    double getPrice(){
        return _price;
    }

    void setPrice( double value ){
        _price = value;
    }

    string getName(){
        return _name;
    }

    void setName(string value){
        _name = value;
    }

    IPromoteStrategy *getPromoteStrategy(){
        return _promoteStrategy;
    }
    void setPromoteStrategy(IPromoteStrategy *value){
        _promoteStrategy = value;
    }

    double getPromotePrice(){
        return _promoteStrategy->DoDiscount(_price);
    }
};

int main(){
    Ticket ticket;
    ticket.setName("MayBay");
    ticket.setPrice(100);
    ticket.setPromoteStrategy(new QuarterDiscountStrategy());
    cout << ticket.getName() << " " << ticket.getPrice() << "->" << ticket.getPromotePrice() << "\n";
    ticket.setPromoteStrategy(new NoDiscountStrategy());
    cout << ticket.getName() << " " << ticket.getPrice() << "->" << ticket.getPromotePrice() << "\n";
    return 0;
}
