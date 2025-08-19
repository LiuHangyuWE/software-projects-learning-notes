//STL容器解法
//注意：1.数有正负；2.数有小数点；3.数超过1位
//4.ERROR条件提示：除法除到0，或符号匹配不对
//原理：从右往左读

#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stack <double> st;

    for(int i = s.length() - 1; i >= 0; i--) {
        //外循环遇到空格跳过以分割数字和运算符
        if(s[i] == ' ') {
            continue;
        }
        
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            double a, b, sum;
            a = st.top();
            st.pop();
            if(st.empty()) {
                cout << "ERROR\n";
                return 0;
            }
            b = st.top();
            st.pop();
            if(s[i] == '+') {
                sum = a + b;
            } else if(s[i]=='-') {
                sum = a - b;
            } else if(s[i]=='*') {
                sum = a * b;
            } else if(s[i]=='/') {
                if(b == 0) {
                    cout << "ERROR\n";
                    return 0;
                }
                sum = a / b;
            }
            st.push(sum);
        } else {
            stack <char> temp;
            //内循环保证可以读到小数点和正负号，不会与运算混淆
            //考虑仅有一个元素的情况！读到末尾则终止
            while(s[i] != ' ' && s[i] != '\0') {
                temp.push(s[i]);
                i--;
            }
            char transTemp[10];
            int j = 0;
            while(!temp.empty()) {
                transTemp[j++] = temp.top();
                temp.pop();
            }
            st.push(stod(transTemp));
        }
    }

    if(st.size() != 1) {
        cout << "ERROR\n";
        return 0;
    }
    printf("%.1lf", st.top());
    return 0;
}