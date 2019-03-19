#include "Header.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <ctype.h>
#include <cmath>
using namespace std;

bool isOperator(char token){
    if(39<token && token<44)
        return true;
    else if (token == 45 || token == 47)
        return true;
    else
        return false;
}

void postfix(char *array, int len, char* postArray, cstack &op){
    map<char, int> precedence;
    precedence['+'] = 10;
    precedence['-'] = 10;
    precedence['*'] = 20;
    precedence['/'] = 20;
    int j = 0;
    for(int i = 0; i < len; i++){
        char token = array[i];
        if(isdigit(token)){
            postArray[j] = token;
            j++;
        }
        else if(isOperator(token)){
            while (precedence[op.top()]>=precedence[token]) {
                postArray[j] = op.pop();
                j++;
            }
            op.push(token);
        }
    }
    while (!op.isEmpty()) {
        postArray[j] = op.pop();
        j++;
    }
}

int calculate(char *postArray, int len, istack &num){
    int a, b, c;
    for(int i = 0; i < len; i++){
        char token = postArray[i];
        if(isdigit(token)){
            num.push((int)token-48);
        }
        else{
            b = num.pop();
            a = num.pop();
            switch (token) {
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = a - b;
                    break;
                case '/':
                    c = a / b;
                    break;
                case '*':
                    c = a * b;
                    break;
                case '^':
                    c = pow(a,b);
                    break;
                default:
                    break;
            }
            num.push(c);
        }
    }
    return c;
}

