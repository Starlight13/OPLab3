#include <iostream>
#include "Header.h"
using namespace std;

int main(int argc, char **argv) {
    char *array = parseStr(argc, argv);

    for (int i = 0; i < length(array); i++) {
        cout << array[i] << " ";
    }
    
    int len = 7;
    queue q;
    stack op;
    postfix(array, len, q, op);
    
    return 0;
}
