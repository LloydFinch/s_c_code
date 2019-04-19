#include <stdio.h> //#include是预处理指令，把stdio.h// h的内容包含在当前程序中(拷贝粘贴)，stdio提供了键盘输入和屏幕输出的支持

int sPrintf(); //函数声明
int computeFei(int f); //函数声明的参数不需要和函数定义相同(但是建议写成相同的)

//======//
int main() {
    printf("Hello, World!\n");

    sPrintf();
    printf("compute fei is : %d\n", computeFei(13));
    computeFei(4);
    return 0;
}

int sPrintf() {
    int num = 1;
    num++;
    printf("I am a simple number %d\n", num);
    return 0;
}

/**
 * 计算斐波那序数
 * @param factor
 * @return
 */
int computeFei(int factor) {
    // 1 1 2 3 5 8 13 21 34 55 89 144 233
    if (factor <= 2) {
        return 1;
    }

    return computeFei(factor - 1) + computeFei(factor - 2);
}