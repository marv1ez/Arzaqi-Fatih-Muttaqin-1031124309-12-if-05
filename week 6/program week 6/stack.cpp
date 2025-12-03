#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) {
    S.TOP = Nil; // Nil = -1
}

bool IsEmpty(Stack S) {
    return S.TOP == Nil;
}

bool IsFull(Stack S) {
    return S.TOP == MaxEl - 1;
}

void Push(Stack &S, infotype X) {
    if (!IsFull(S)) { 
        if (IsEmpty(S)) {
            S.TOP = 0;
        } else {
            S.TOP++;
        }
        S.info[S.TOP] = X;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype Pop(Stack &S) {
    infotype X = -999;
    if (!IsEmpty(S)) {
        X = S.info[S.TOP];
        S.TOP--;
        if (S.TOP < 0) {
            S.TOP = Nil; 
        }
    } else {
        cout << "Stack kosong" << endl;
    }
    return X;
}

void printInfo(Stack S) {
    if (IsEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.TOP; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!IsEmpty(S)) {
        Stack temp;
        CreateStack(temp);
        while (!IsEmpty(S)) {
            Push(temp, Pop(S));
        }
        S = temp;
    }
}

void pushAscending(Stack &S, infotype X) {
    if (IsFull(S)) {
        cout << "Stack penuh" << endl;
        return;
    }

    Stack temp;
    CreateStack(temp);

    while (!IsEmpty(S) && S.info[S.TOP] < X) {
        Push(temp, Pop(S));
    }

    Push(S, X);

    while (!IsEmpty(temp)) {
        Push(S, Pop(temp));
    }
}

void getInputStream(Stack &S) {
    cout << "Masukkan angka: ";
    string input;
    cin >> input; 

    for (char c : input) {
        if (isdigit(c)) {
            int value = c - '0';
            Push(S, value);
        }
    }
}
