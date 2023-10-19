#include<iostream>
using namespace std;

class Fleet {
public:
    int fleet[24];
    int count;

    Fleet() {
        for (int i = 0; i < 24; i++) {
            fleet[i] = -1; 
        }
        int count = 0; //keeps track of number of aircrafts in the fleet
    }

    bool empty_check() {
        for (int i = 0; i < 24; i++) {
            if (fleet[i] == -1) { //to find empty space
                return true;
                break;
            }
        }
        return false;
    }

    int empty_index() {
        if (empty_check()) {
            for (int i = 0; i < 24; i++) {
                if (fleet[i] == -1) { //to find the empty index
                    return i;
                }
            }
        }
        return -1;
    }
};

class Aircraft:public Fleet
{

public:
 int Aircraft_Id; 
 int priority;
 char action;
 int takeoff();
 int Landing();
};

int Aircraft::takeoff()
{
    
}

int Aircraft:: Landing()
{
}

int main(int argc, char const *argv[])
{
    
    return 0;
}