#include <iostream>
#include <cstring>
using namespace std;
class Vector {
private:
    int size, length;
    int *data;
public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new int[size];
    }
    ~Vector() {
        delete[] data;
    }
    bool insert(int loc, int value) {
        if (loc < 0 || loc > length) {
            return false;
        }
        if (length >= size) {
            return false;
        }
        for (int i = length; i > loc; --i) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
    int search(int value) {
        for(int i=0; i<length; i++){
            if(data[i]==value){
                return i;
            }
        }
        return -1;

    }
};
int main() {
    Vector a(2);
    cout << a.insert(1, 0) << endl;
    cout << a.insert(0, 1) << endl;
    cout << a.insert(2, 1) << endl;
    cout << a.insert(1, 2) << endl;
    cout << a.insert(0, 3) << endl;
    cout << a.search(1) << endl;
    cout << a.search(4) << endl;
    return 0;
}
