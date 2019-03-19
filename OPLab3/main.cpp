#include <iostream>
#include "Header.h"

int main(){
    int len = 7;
    queue q;
    stack op;
    char *array = new char[len];
    array[0] = '1';
    array[1] = '+';
    array[2] = '2';
    array[3] = '*';
    array[4] = '4';
    array[5] = '+';
    array[6] = '1';
    postfix(array, len, q, op);
}
