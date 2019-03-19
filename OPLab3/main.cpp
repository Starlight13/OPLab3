#include <iostream>
#include "Header.h"
using namespace std;

int main(int argc, char **argv) {
    char *array = parseStr(argc, argv);
    for (int i = 0; i < length(array); i++) {
        cout << array[i] << " ";
    }
    int len = length(array);
    char *postArray = new char[len];
    cstack op;
    istack num;
    postfix(array, len, postArray, op);
    int result = calculate(postArray, len, num);
    cout << "\nResult: " << result << endl;
    return 0;
}
