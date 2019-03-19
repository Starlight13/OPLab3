#include "Header.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <ctype.h>
using namespace std;

void push(queue &q, const char value){
    if(q.size >= q.max_size){
        cout << "Queue overload\n";
        exit(1);
    }
    q.data[q.back] = value;
    q.back = (q.back+q.max_size-1)%q.max_size;
    q.size++;
}

bool pop(queue &q, char &out){
    if(!q.size)
        return false;
    q.front = (q.front+q.max_size-1)%q.max_size;
    out = q.data[q.front];
    q.size--;
    return true;
}

void print(queue &q){
    cout << "=== QUEUE ===\n";
    int i = q.back;
    for(int k = 0; k<q.size; k++){
        i = (i+1)%q.max_size;
        cout << setw(4) << q.data[i];
    }
    cout << "\n=== END ===\n";
}

bool isOperator(char token){
    if(39<token && token<44)
        return true;
    else if (token == 45 || token == 47)
        return true;
    else
        return false;
}

void postfix(char *array, int len, queue &q, stack &op){
    map<char, int> precedence;
    precedence['+'] = 10;
    precedence['-'] = 10;
    precedence['*'] = 20;
    precedence['/'] = 20;
    precedence['^'] = 30;
    precedence['('] = 40;
    precedence[')'] = 40;
    for(int i = 0; i < len; i++){
        char token = array[i];
        if(isdigit(token)){
            push(q, token);
        }
        else if(isOperator(token)){
            if(token == ')'){
                while (op.top() != ')') {
                    push(q, op.pop());
                }
                if(op.top() == '('){
                    op.pop();
                }
            }
            while (precedence[op.top()]>=precedence[token] && token != '(' ) {
                push(q,op.pop());
            }
            op.push(token);
        }
    }
    while (!op.isEmpty()) {
        push(q, op.pop());
    }
    print(q);
}

