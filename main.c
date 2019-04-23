#include <stdio.h> //#include是预处理指令，把stdio.h// h的内容包含在当前程序中(拷贝粘贴)，stdio提供了键盘输入和屏幕输出的支持

int sPrint(); //函数声明
int cType();

int computeFei(int f); //函数声明的参数不需要和函数定义相同(但是建议写成相同的)

//======//
int main() {
    printf("Hello, World!\n");

//    sPrint();
//    printf("compute fei is : %d\n", computeFei(13));
//    computeFei(4);

    cType();
    return 0;
}

int sPrint() {
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

/**
 * 数据类型
 * @return
 */
int cType() {
    //int, short, long, unsigned, char, float,double,_Bool, _Complex(复数), _Imaginary(虚数)
    //sizeof
    //scanf()

    float weight;
    float value;
    printf("Please input a float number:");
    scanf("%f", &weight); //&weight表示找到weight变量的地点

    value = 10 * weight;
    printf("value is : %.2f\n", value); //精确骚小数点后两位

    printf("%f and %f is %f", value); //遗漏两个参数，但是不会报错，只会匹配第一个，后面没有匹配的完全是随机取数


    return 0;
}