#include<iostream>
using namespace std;

class Fleet {
public:
    int fleet[5];
    int count;

    Fleet() {
        for (int i = 0; i < 5; i++) {
            fleet[i] = -1; 
        }
        int count = 0; //keeps track of number of aircrafts in the fleet
    }

    bool empty_check() {
        for (int i = 0; i < 5; i++) {
            if (fleet[i] == -1) { //to find empty space
                return true;
                break;
            }
        }
        return false;
    }

    int empty_index() {
        if (empty_check()) {
            for (int i = 0; i < 5; i++) {
                if (fleet[i] == -1) { //to find the empty index
                    return i;
                }
            }
        }
        return -1;
    }
};


class PriorityQueue {
private:
static const int MAX = 10; 
public:
struct Entry {
        string item;
        int priority;
    } queue[MAX];
    int size;

    PriorityQueue() {
        size = 0;
    }

    
    bool enqueue(const string& item, int priority) { //Priority list -> Fighter Jet: 1 ; Passenger: 2 ; Cargo: 3 
        if(size == MAX) {
            return false; //checks if PQ is full
        }

        int i = size - 1;
        while (i >= 0 && queue[i].priority > priority) {
            queue[i + 1] = queue[i];
            i--;
        }
        queue[i + 1].item = item;
        queue[i + 1].priority = priority;
        size++;
    }

   
    string dequeue() {
        if(size == 0) {
            return "0"; //to indicate it is empty, can be utilised later in other functions
        }
        string frontItem = queue[0].item;
        for (int i = 0; i < size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        size--;
        return frontItem;
    }

    int getSize() {
        return size;
    }
};

class Aircraft:public Fleet{


public:
 char type; 
 int pri;
 int takeoff();
 int landing(char type, int priority);
};

int Aircraft::takeoff()
{

}

int Aircraft::landing(char type, int pri)
{
if(empty_check()==true){
    count++;

}

}


int main(int argc, char const *argv[])
{     
    int x;
    int temp;
    string type;
    int pri;
    char action;

    while (true) {
        cout << "Enter the Flight Scheme:\n1. Landing\n2. Takeoff\nPress 0 to Exit. " << endl;
        cin >> x;
        
        if (x == 1) {
            cout<<"Enter Aircraft Type: \n1.Fighter Jet\n2.Passenger\n3.Cargo"<<endl;
            if (temp == 1) {
                type = "FGHTRJT";
            } else if (temp == 2) {
                type = "PSNGR";
             } else if (temp == 3) {
                type = "CRGO";
            } else {
        cout << "Invalid input. Please enter a valid option." << endl;
        
        return 1; 
    }
        } else if (x == 2) {
            cout << '2';
            break;  // Exit the loop after printing '2'.
        } else if (x == 0) {
            cout << '0';
            break;  // Exit the loop after printing '0'.
        }
    }

    return 0;
}