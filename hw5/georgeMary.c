#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_george() {
    while (1) {
        printf("George\n");
        sleep(1);
    }
}

void print_mary() {
    while (1) {
        printf("Mary\n");
        sleep(2);
    }
}

int main() {
    pid_t pid1, pid2;

    pid1 = fork(); // 創建第一個子進程
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid1 == 0) {
        print_george(); // 第一個子進程執行 print_george 函數
        exit(0);
    }

    pid2 = fork(); // 創建第二個子進程
    if (pid2 < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid2 == 0) {
        print_mary(); // 第二個子進程執行 print_mary 函數
        exit(0);
    }

    while (1) { // 主進程每隔一秒鐘印出分隔行
        printf("----------------\n");
        sleep(1);
    }

    return 0;
}
