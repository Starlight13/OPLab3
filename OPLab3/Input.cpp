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
        for (int o = 0; o < length(str[i]); o++) {
            if (str[i][o] >= '0' && str[i][o] <= '9') {
                m[count++] = str[i][o];
            } else if (str[i][o] == '+' || str[i][o] == '-' || str[i][o] == '(' || str[i][o] == ')' || str[i][o] == '*' || str[i][o] == '/' || str[i][o] == '^' || str[i][o] == 'v') {
                m[count++] = str[i][o];
            } else if (str[i][o] == '!') {
                int facto = m[count - 1] - '0';
                for (int u = 1; u <= facto; u++) {
                    if (u == 1) {
                        m[count - 1] = u + '0';
                        m[count++] = '*';
                    } else if (u == facto)
                        m[count++] = u + '0';
                    else {
                        m[count++] = u + '0';
                        m[count++] = '*';
                    }
                }
            }
        }
    }
    m[count++] = '\0';
    
    
    return m;
}

int length(char *array) {
    int length = 0;
    while (array[length])
        length++;
    
    return length;
}
