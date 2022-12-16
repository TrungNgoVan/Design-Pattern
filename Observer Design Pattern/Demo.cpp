#include <iostream>
#include <vector>
using namespace std;

class Observer // Interface class // aka Server
{ 
public:
    virtual void update(int value) = 0; // virtual function
};

class Subject 
{
private:
    int m_value;
    vector<Observer *> m_views; // List behavior Observer

public:
    void attach(Observer *obs)
    {
        m_views.push_back(obs);
    }

    void set_val(int value)
    {
        m_value = value;
        notify();
    }

    void notify()
    {
        for (int i = 0; i < m_views.size(); ++i)
        {
            m_views[i]->update(m_value);
        }
    }
};

class DivObserver : public Observer
{
private:
    int m_div;

public:
    DivObserver(Subject *model, int value)
    {
        model->attach(this); // add this Observer to list of observers/server
        m_div = value;
    }

    void update(int value)
    {
        cout << value << " div " << m_div << " is " << value / m_div << "\n";
    }
};

class ModObserver : public Observer
{
private:
    int m_mod;

public:
    ModObserver(Subject *model, int value)
    {
        model->attach(this); // add ModObserver to Subject
        m_mod = value;
    }

    void update(int value)
    {
        cout << value << " mod " << m_mod << " is " << value % m_mod << "\n";
    }
};

int main()
{
    Subject subj;
    // Add behavior
    DivObserver div1(&subj, 4); 
    DivObserver div2(&subj, 3);
    ModObserver mod1(&subj, 4);
    // Change data and notify observers
    subj.set_val(15);
    return 0;
}
