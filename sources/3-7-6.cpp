//题目：检查一个C语言文件里面的左右符号是否配对完全
//难点："/**/"这种符号先转换再纳入单符号体系

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';  // 返回空字符表示栈为空
}

int isEmpty() {
    return top == -1;
}

char getTop() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';  // 返回空字符表示栈为空
}

char x[101], y[101] = ""; //x数组存放输入数据，y数组存放符号

int main() {
    
    int flag = 1;

    // 读取输入直到遇到句点.
    while (fgets(x, 101, stdin)) {
        if (strcmp(x, ".\n") == 0)
            break;
        for (int i = 0; x[i] != '\0'; i++) {
            if (x[i] == '[' || x[i] == ']' || x[i] == '{' || x[i] == '}' || x[i] == '(' || x[i] == ')') {
                strncat(y, &x[i], 1);  // 将括号加入符号序列 y
               // 单独处理 /* 和 */，用 < 和 > 表示 
            } else if (x[i] == '/' && x[i + 1] == '*') {
                strcat(y, "<");
                i++;
            } else if (x[i] == '*' && x[i + 1] == '/') {
                strcat(y, ">");
                i++;
            }
        }
    }

    // 循环遍历符号序列 y
    for (int i = 0; y[i] != '\0'; i++) {
        char a = getTop();

        if (y[i] == '[' || y[i] == '{' || y[i] == '(' || y[i] == '<') {  // 左括号符号入栈
            push(y[i]);
            continue;
            // 遇到右括号，有两种不匹配的情况：栈为空（没有可匹配的左括号）或者和栈顶元素不匹配（不符合匹配规则）
        } else if (isEmpty()) {   //缺少左括号
            printf("NO\n");
            if (y[i] == '>')
                printf("?-*/\n"); 
            else
                printf("?-%c\n", y[i]);
            flag = 0;
            break;
        } else if (y[i] - a != 1 && y[i] - a != 2) {  // 匹配规则是左括号和右括号的 ASCII 码差值为 1 或 2
            printf("NO\n");
            if (a == '<')
                printf("/*-?\n");  //有多的左括号，此时栈顶就是没有配对的左括号
            else
                printf("%c-?\n", a);
            pop();
            flag = 0;
            break;
        } else {  // 匹配，出栈
            pop();
        }
    }
    //考虑除了栈顶可能还有未匹配的左括号
    if (flag == 1) {
        if (isEmpty()) {
            printf("YES\n");
        } else {
            char a = getTop();
            printf("NO\n");
            if (a == '<')
                printf("/*-?\n");
            else
                printf("%c-?\n", a);
        }
    }

    return 0;
}