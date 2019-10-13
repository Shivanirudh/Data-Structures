#ifndef StackStatic1_h
#define	StackStatic1_h
#include"ADTArray2.h"
#include<stdio.h>
#include<stdlib.h>
typedef Array Stack;
Stack* stackinput(Stack *s);
int    stackdisplay(Stack *s);
Stack* push(Stack *s,any datatobepushed);
Stack* pop(Stack *s);
any    peep(Stack *s);
int    isfull(Stack *s);
int    isempty(Stack *s);
#endif
