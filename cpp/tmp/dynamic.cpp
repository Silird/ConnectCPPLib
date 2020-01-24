#include <iostream>
using namespace std;

// #include <dynamic.h>

extern "C" int hello() {
    cout << "Hello world!" << endl;
    return 0;
}