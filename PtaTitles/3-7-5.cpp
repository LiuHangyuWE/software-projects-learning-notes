#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int arrivalTime; // 到达时间
    int serviceTime; // 事务处理时间
    int isVIP;       // 是否为VIP客户
} Customer;
 
typedef struct {
    int customerCount; // 统计该窗口服务过的顾客数目
    int remainingTime; // 该窗口为某位顾客处理事务还需要的时间
} Window;
 
int numCustomers, numWindows, vipWindowIndex;
int currentTime = -1, totalWaitTime = 0, maxWaitTime = 0;
///结构体数组：每个元素是一个结构体类型的元素，每个结构体需要分配内存空间==>每个数组元素需要分配内存
Window* windows[10];
Customer* customers[1000];
 
///信息读入函数
void inputDeal() {
    scanf("%d", &numCustomers);
    for (int i = 0; i < numCustomers; i++) {
        customers[i] = (Customer*)malloc(sizeof(Customer));
        scanf("%d %d %d", &customers[i]->arrivalTime, &customers[i]->serviceTime, &customers[i]->isVIP);
        if (customers[i]->serviceTime > 60) {
            customers[i]->serviceTime = 60;
        }
    }
    scanf("%d %d", &numWindows, &vipWindowIndex);
    for (int i = 0; i < numWindows; i++) {
        windows[i] = (Window*)malloc(sizeof(Window));
        windows[i]->customerCount = 0;
        windows[i]->remainingTime = 0;
    }
}
    
void serveCustomer(int windowIndex, int customerIndex) {
    int waitTime = currentTime - customers[customerIndex]->arrivalTime;
    totalWaitTime += waitTime;
    if (waitTime > maxWaitTime) {
        maxWaitTime = waitTime;
    }
    windows[windowIndex]->customerCount++;
    windows[windowIndex]->remainingTime = customers[customerIndex]->serviceTime;
    customers[customerIndex]->isVIP = -1;
}
 
void outputDeal() {
    printf("%.1f %d %d\n", (double)totalWaitTime / numCustomers, maxWaitTime, currentTime);
    for (int i = 0; i < numWindows - 1; i++) {
        printf("%d ", windows[i]->customerCount);
    }
    printf("%d\n", windows[numWindows - 1]->customerCount);
}
 
int main() {
    inputDeal();///信息读入
    int remainingWork, customerIndex = 0;
    while (1) {
        currentTime++;
        remainingWork = 0;
        for (int i = 0; i < numWindows; i++) {
            if (windows[i]->remainingTime > 0) {
                windows[i]->remainingTime--;
                remainingWork += windows[i]->remainingTime;
            }
        }
        if (remainingWork == 0 && customerIndex == numCustomers) {
            break;
        }
        if (windows[vipWindowIndex]->remainingTime == 0) { // VIP窗口空闲
            for (int i = customerIndex; i < numCustomers && customers[i]->arrivalTime <= currentTime; i++) { // 寻找排队中的VIP顾客
                if (customers[i]->isVIP == 1) {
                    serveCustomer(vipWindowIndex, i);
                    break; // VIP窗口有人，跳出
                }
            }
        }
        for (int i = 0; i < numWindows; i++) {
            while (customerIndex != numCustomers && customers[customerIndex]->isVIP == -1) {
                customerIndex++; // 跳过已处理的顾客
            }
            if (windows[i]->remainingTime == 0 && customerIndex != numCustomers && customers[customerIndex]->arrivalTime <= currentTime) { // 有空窗口，且到达顾客
                serveCustomer(i, customerIndex++);
            }
        }
    }
    outputDeal();
    return 0;
}
