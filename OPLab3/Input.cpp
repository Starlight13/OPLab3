//
//  FIle.cpp
//  OPLab3
//
//  Created by dsadas asdasd on 3/19/19.
//  Copyright © 2019 dsadas asdasd. All rights reserved.
//
#include "Header.h"
using namespace std;

char *parseStr(int len, char **str) {
    char *m = new char[len];
    int count = 0;
    
    for (int i = 1; i < len; i++) {
        if (str[i][0] >= '0' && str[i][0] <= '9') {
            m[count++] = str[i][0];
        } else if (str[i][0] == '+' || str[i][0] == '-' || str[i][0] == '(' || str[i][0] == ')' || str[i][0] == '*' || str[i][0] == '/' || str[i][0] == '^') {
            m[count++] = str[i][0];
        } else m[count++] = str[i][0];
    }
    
    
    return m;
}

int length(char *array) {
    int length = 0;
    while (array[length])
        length++;
    
    return length;
}
