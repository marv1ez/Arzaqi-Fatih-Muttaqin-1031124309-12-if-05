#ifndef STACK_H
#define STACK_H

#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl]; 
    int TOP;
};

// Prototipe fungsi dasar
void CreateStack(Stack &A);
bool IsEmpty(Stack A);
bool IsFull(Stack A);
void Push(Stack &A, infotype B);
infotype Pop(Stack &A);
void printInfo(Stack A);

// Fungsi tambahan
void balikStack(Stack &A);           
void pushAscending(Stack &A, infotype B);
void getInputStream(Stack &A);

#endif
