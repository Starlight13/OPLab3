//
//  Header.h
//  OPLab3
//
//  Created by dsadas asdasd on 3/19/19.
//  Copyright © 2019 dsadas asdasd. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <stdio.h>
class stack {
    int length = 0;
    int maxLength;
    char * array;
public:
    stack(int maxLen = 0) {
        maxLength = maxLen;
        array = new char[maxLength];
    }
    void push(char value){
        array[length++] = value;
    }
    char pop() {
        char out;
        if (length > 0)
            out = array[length-1];
            array[--length] = NULL;
        return out;
    }
    
    char top() {
        return array[length - 1];
    }
    
    int size() {
        return length;
    }
    bool isEmpty() {
        if(length > 0)
            return false;
        else
            return true;
    }
    void clear() {
        length = 0;
        delete array;
    }
};

struct queue {
    char *data;
    int max_size, size;
    int back, front;
    queue(int N=100): max_size(N), size(0) {
        data = new char[max_size];
        for(int i = 0; i < max_size; i++)
            data[i]=0;
        back = front = max_size-1;
    }
};
void postfix(char *array, int len, queue &q, stack &op);

#include <string>
#include <iostream>
using namespace std;

char *parseStr(int len, char **str);
int length(char *array);

#endif /* Header_h */
