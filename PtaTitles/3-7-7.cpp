//计算前缀表达式的值
//注意：1.数有正负；2.数有小数点；3.数超过1位
//4.ERROR条件提示：除法除到0，或符号匹配不对
//原理：从右往左读

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  
  
typedef struct Node* Stack;  
typedef struct Node* Position;  
  
struct Node{  
    char opr;  
    float num;  
    int type;  //0表示操作符 1表示数字  
    struct Node* Next;  
};  

//这里用到了函数重载，只能用C++编译
void Push(char c, Stack S)  
{  
    Position P;  
    Position Temp;  
    Temp = (Position)malloc(sizeof(struct Node));  
    Temp->opr = c;  
    Temp->type = 0;  
    Temp->Next = NULL;  
    Temp->Next = S->Next;  
    S->Next = Temp;  
}  

int IsEmpty(Stack S)  
{  
    return S->Next == NULL;  
}  
  
float PopNum(Stack S)  
{  
    Position Temp;  
    float num;  
  
    Temp = S->Next;  
    num = Temp->num;  
    S->Next = Temp->Next;  
    free(Temp);  
    return num;  
}  
  
char PopOpr(Stack S)  
{  
    Position Temp;  
    char opr;  
  
    Temp = S->Next;  
    opr = Temp->opr;  
    if (Temp->Next != NULL)  
        S->Next = Temp->Next;  
    else  
        S->Next = NULL;  
    free(Temp);  
    return opr;  
}  
  
void Push(float n, Stack S)  
{  
    Position P;  
    Position Temp;  
    Temp = (Position)malloc(sizeof(struct Node));  
    Temp->num = n;  
    Temp->type = 1;  
    Temp->Next = NULL;  
    if (S->Next == NULL) //如果此前一个是操作符或栈空，那么直接压入
    {  
        Temp->Next = S->Next;  
        S->Next = Temp;  
    }  
    else if (S->Next->type == 0)  
    {
        Temp->Next = S->Next;  
        S->Next = Temp;  
    }
    else{ //如果此前一个是数字
        float m = PopNum(S); 
        char c = PopOpr(S);
  
        if (c == '+')  
            Push(n + m, S);  
        else if (c == '-')  
            Push(m - n, S);  
        else if (c == '*')  
            Push(m * n, S);  
        else{  
            if (n == 0)  
            {  
                printf("ERROR");  
                exit(0);  
            }  
            else  
                Push(m / n, S);  
        }  
  
    }  
}  
  
int IsOpr(char in[])  
{  
    int length = strlen(in);  
    if (length== 1 && (in[0] == '+' || in[0] == '-' || in[0] == '*' || in[0] == '/'))  
        return 1;  
    else  
        return 0;  
}  
  
float StrToNum(char s[])  
{  
    int length = strlen(s);  
    float result = 0;  
    int flag = 1;  
    int right = 0;  
    int j = 0;  
    for (int i = 0; i < length; i++)  
    {  
        if (s[i] == '.'){  
            right = 1;  
            continue;  
        }  
  
        if (i == 0 && s[i] == '+')  
            flag = 1;  
        else if (i == 0 && s[i] == '-')  
            flag = -1;  
        else if (!right) {  
            result = 10 * result + s[i] - '0';  
        }  
        else{  
            j++;  
            result = result + (s[i] - '0') / (pow(10.0, j));  
        }  
    }  
    return result*flag;  
}  

int main()  
{  
    char in[30];  
    char buff;  
    float result = 0;  
    Stack S;  
    S = (Stack)malloc(sizeof(struct Node));  
    S->Next = NULL;  
    scanf("%s", in);  
    buff = getchar();  
    if (!IsOpr(in)) //如果输入的第一项就是数字，直接返回结果
    {  
        float r = StrToNum(in);  
        printf("%.1f", r);  
        return 0;  
    }  
  
    //如果输入的第一项是操作符  
    Push(in[0], S);
    while (buff != '\n')
    {
        scanf("%s", in);
        if (IsOpr(in))  //如果输入的是操作符，就直接入栈
        {  
            Push(in[0], S);    
        }  
        else  //如果输入的数字
        {  
            Push(StrToNum(in), S);  
        }  
        buff = getchar();  
    }
  
    result = S->Next->num;  
    printf("%.1f", result);  
    return 0;
}