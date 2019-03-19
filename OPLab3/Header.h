//
//  Header.h
//  OPLab3
//
//  Created by dsadas asdasd on 3/19/19.
//  Copyright © 2019 dsadas asdasd. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class cstack {
    int length = 0;
    int maxLength;
    char * array;
public:
    cstack(int maxLen = 0) {
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

class istack {
    int length = 0;
    int maxLength;
    int * array;
public:
    istack(int maxLen = 0) {
        maxLength = maxLen;
        array = new int[maxLength];
    }
    void push(int value){
        array[length++] = value;
    }
    int pop() {
        int out;
        if (length > 0)
            out = array[length-1];
        array[--length] = NULL;
        return out;
    }
    
    int top() {
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
bool isOperator(char token);
void postfix(char *array, int len, char* postArray, cstack &op);
int calculate(char *postArray, int len, istack &num);
char *parseStr(int len, char **str);
int length(char *array);

#endif /* Header_h */
