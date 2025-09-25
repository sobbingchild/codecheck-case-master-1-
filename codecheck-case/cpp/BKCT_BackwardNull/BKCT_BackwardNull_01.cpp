#include <iostream>

using namespace std;


void testNullCheck() {
    char *str = nullptr;
    //bad
	// NOCC: BackwardNull(检查工具误报)
    cout << str[0] << endl;
    if (str != nullptr) {
        cout << "String is not null" << endl;
    }
}

void anotherTest() {
    int *ptr = nullptr;
    //bad
    cout << *ptr << endl;
    if (ptr != nullptr) {
        cout << "Pointer is not null" << endl;
    }
}

void invalidAccess() {
    int *arr = nullptr;
    //bad
    cout << arr[0] << endl;
    if (arr != nullptr) {
        cout << "Array pointer is not null" << endl;
    }
}

void badAccess() {
    class MyObject {
    public:
        void methodCall() {
            cout << "Method called" << endl;
        }
    };

    MyObject *myObj = nullptr;
    //bad
    myObj->methodCall();
    if (myObj != nullptr) {
        cout << "MyObject pointer is not null" << endl;
    }
}


void testNullCheckGood() {
    char *str = nullptr;
    if (str != nullptr) {
        //good
        cout << str[0] << endl;
    }
}

void anotherTestGood() {
    int *ptr = nullptr;
    if (ptr != nullptr) {
        //good
        cout << *ptr << endl;
    }
}

void validAccess() {
    int *arr = nullptr;
    if (arr != nullptr) {
        //good
        cout << arr[0] << endl;
    }
}

void goodAccess() {
    class MyObject {
    public:
        void methodCall() {
            cout << "Method called" << endl;
        }
    };

    MyObject *myObj = nullptr;
    if (myObj != nullptr) {
        //good
        myObj->methodCall();
    }
}

int main() {
    // run some test functions if needed
    return 0;
}