#include <stdio.h>
#include "Stack.h"

int main() {
    Stack s;
    InitStack(&s);

    PushStack(&s, 3);
    printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    PushStack(&s, 2);
    printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    PushStack(&s, 1);
    printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    PushStack(&s, 4);

    printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }

    PopStack(&s);
        printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    PopStack(&s);
        printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    PopStack(&s);
        printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    PopStack(&s);
        printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    PopStack(&s);
        printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }

    PushStack(&s, 3);
        printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    PushStack(&s, 2);
        printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    PushStack(&s, 1);
        printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    PushStack(&s, 4);
        printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }

    ClearStack(&s);
        printf("size = %d\n", SizeStack(&s));
    if(!EmptyStack(&s)) {
        printf("top = %d\n", TopStack(&s));
    }
    DestoryStack(&s);
    return 0;
}

