#include<iostream>
using namespace std;

class Fleet {
public:
    int count;

    Fleet(){
        count = 0;
    }// Initialize count to 0

    bool empty_check() {
        if(count<5){
            return true;
        }
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

    PriorityQueue() : size(0) {}

    bool enqueue(const string& item, int priority) {
        if(size == MAX) {
            return false;
        }

        int i = size - 1;
        while (i >= 0 && queue[i].priority > priority) {
            queue[i + 1] = queue[i];
            i--;
        }
        queue[i + 1].item = item;
        queue[i + 1].priority = priority;
        size++;
        return true;
    }

    string dequeue() {
        if(size == 0) {
            return "0";
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

class Aircraft : public Fleet, public PriorityQueue {
public:
    char type; 
    int pri;
    int takeoff();
    int landing();
};

int Aircraft::takeoff() {
    if(size == 0) {
        cout << "No aircraft in queue for takeoff!" << endl;
        return -1;
    }

    string result = dequeue();
    string aircraft;

    if(result[0] == 'F') {
        aircraft = "Fighter Jet";
    } else if(result[0] == 'P') {
        aircraft = "Passenger";
    } else if(result[0] == 'C') {
        aircraft = "Cargo";
    }

    count--;  // Decrement the count in Fleet
    cout << aircraft << " Successfully Took Off!" << endl << endl;
    return 0;
}

int Aircraft::landing() {
    if(empty_check()) {
        count++;
        string result = dequeue();
        string aircraft;

        if(result[0] == 'F') {
            aircraft = "Fighter Jet";
        } else if(result[0] == 'P') {
            aircraft = "Passenger";
        } else if(result[0] == 'C') {
            aircraft = "Cargo";
        } else if(result[0] == '0') {
            cout << "No aircraft in queue!" << endl;
            return -1;
        }
        cout << aircraft << " Successfully Landed!" << endl<<endl;
        return 0;
    }
    else{
        cout<<"No Space in Fleet, Permission Denied.";
    }
}

int main(int argc, char const *argv[]) {     
    int x;
    int temp;
    char type;
    int pri;
    char action;

    char landingarr[5];
    int landingIndex = 0;

    int takeoffIndex = 0; 
    char takeoffarr[5];  

    char continueChoice;
    
    PriorityQueue pq;
    Aircraft atc;

    while (true) {
        cout << "Enter the Flight Scheme:\n1. Landing\n2. Takeoff\nPress 0 to Exit. " << endl;
        cin >> x;

        if (x == 1) {
            landingIndex = 0;  // Reset the landingIndex

            do {
                if (landingIndex == 5) {
                    cout << "Landing Permission is denied." << endl;
                    break;
                }
                cout << "Enter Aircraft Type: \n1. Fighter Jet\n2. Passenger\n3. Cargo" << endl;
                cin >> temp;

                if (temp == 1) {
                    type = 'F';
                } else if (temp == 2) {
                    type = 'P';
                } else if (temp == 3) {
                    type = 'C';
                } else {
                    cout << "Invalid input. Please enter a valid option." << endl;
                    continue;
                }
                landingarr[landingIndex] = type;
                landingIndex++;

                cout << "Do you want to add another flight? (y/n): ";
                cin >> continueChoice;
            } while (continueChoice == 'y' || continueChoice == 'Y');

            for(int i = 0; i < landingIndex; i++) {
                int priority = 0;
                char var = landingarr[i];
                if(var == 'F') {
                    priority = 1;
                } else if(var == 'P') {
                    priority = 2;
                } else if(var == 'C') {
                    priority = 3;
                }
                atc.enqueue(string(1, var), priority);
            }

            for(int i = 0; i < landingIndex; i++) {
                atc.landing();
            }   
        } 
        else if (x == 2) {
             
    do {
        if (takeoffIndex == atc.Fleet::count) {  
            cout << "No more aircrafts in the Fleet to take off." << endl;
            break;
        }
        cout << "Enter Aircraft Type for takeoff: \n1. Fighter Jet\n2. Passenger\n3. Cargo" << endl;
        cin >> temp;

        if (temp == 1) {
            type = 'F';
        } else if (temp == 2) {
            type = 'P';
        } else if (temp == 3) {
            type = 'C';
        } else {
            cout << "Invalid input. Please enter a valid option." << endl;
            continue;
        }
        takeoffarr[takeoffIndex] = type;
        takeoffIndex++;

        cout << "Do you want to schedule another flight for takeoff? (y/n): ";
        cin >> continueChoice;
    } while (continueChoice == 'y' || continueChoice == 'Y');

    for(int i = 0; i < takeoffIndex; i++) {
        int priority = 0;
        char var = takeoffarr[i];
        if(var == 'F') {
            priority = 1;
        } else if(var == 'P') {
            priority = 2;
        } else if(var == 'C') {
            priority = 3;
        }
        atc.enqueue(string(1, var), priority);
    }

    for(int i = 0; i < takeoffIndex; i++) {
        atc.takeoff();
    }   
        } else if (x == 0) {
            cout << 'Thank you!';
            break;
        }
    }

    return 0;
}