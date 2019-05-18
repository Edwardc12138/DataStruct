#pragma once

typedef int StackDataType;

typedef struct Stack {
    StackDataType *_data;   // 存储数据
    int _top;       // 栈顶元素下标
    int _capacity;  // 容量
    int _size;      // 大小
} Stack;

// 初始化
void InitStack(Stack *stack);

// 销毁
void DestoryStack(Stack *stack);

// 入栈
void PushStack(Stack *stack, StackDataType data);

// 出栈
StackDataType PopStack(Stack *stack);

// 判空
int EmptyStack(Stack *stack);

// 栈中元素个数
int SizeStack(Stack *stack);

// 栈顶元素
StackDataType TopStack(Stack *stack);

// 清空
void ClearStack(Stack *stack);
