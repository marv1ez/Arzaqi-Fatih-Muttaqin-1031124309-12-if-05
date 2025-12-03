#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    // Operasi stack
    Push(S, 5);
    Push(S, 6);
    Push(S, 10);
    Pop(S);
    Push(S, 4);
    Push(S, 5);
    Pop(S);
    Push(S, 11);

    cout << "Stack sebelum dibalik:" << endl;
    printInfo(S);

    balikStack(S);

    cout << "Stack sesudah dibalik:" << endl;
    printInfo(S);

    return 0;
}
