#include<iostream>
using namespace std;

<<<<<<< Updated upstream
int main()
{
    /* code */
    cout<<"Hello World";
=======
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

int main(int argc, char const *argv[])
{
    
>>>>>>> Stashed changes
    return 0;
}