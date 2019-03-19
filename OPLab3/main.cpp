#include "Header.h"
using namespace std;

int main(int argc, char **argv) {
    char *array = parseStr(argc, argv);

    for (int i = 0; i < length(array); i++) {
        cout << array[i] << " ";
    }
    
    return 0;
}
