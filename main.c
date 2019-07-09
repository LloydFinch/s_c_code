#include <stdio.h> //#include是预处理指令，把stdio.h// h的内容包含在当前程序中(拷贝粘贴)，stdio提供了键盘输入和屏幕输出的支持
#include <string.h>
#include <limits.h> //定义了整数类型的大小限制相关
#include <float.h> //定义了浮点类型的大小限制相关
#include <stdlib.h>
#include <stdarg.h> //处理可变参数

#define DENSITY 62.4 //人体密度:镑/立方英尺
#define HELLO "hello" //使用预处理指令定义一个常量
typedef char MChar; //使用typedef关键字给char类型起别名MChar
#define ONE 1;//使用#define定义ONE是1
//typedef ONE 1;//error, typedef不能定义边领，只能为类型定义
#define TRUE FALSE; //fuck code!!!

int sPrint(); //函数声明
int cType();

int cHex();

int computeFei(int f); //函数声明的参数不需要和函数定义相同(但是建议写成相同的)

int test();

int testStr();

void fuck();

int max(int, int); //函数声明可以不写形参，只写类型
void testEnum();

void testMemoryAddress();

void testPointer();

void ptrFunction(int *);

int *returnIntPtr();

int max2(int, int);

int funcPtr();

int testCallback(int(*p)(int, int));

int testStruct();

int testBitRange();

/**
 * 共用体
 * 这个共用体占用20byte内存(取最大的)
 * 可以存放int，float和char数组
 * 只能声明不能初始化(因为这是类型)
 */
union Data {
    int i;
    float f;
    char str[20];
};

enum DAY {
    MON = 1, TUE, WED, THU, FRI, SAT, SUN
};

int getUnionSize(union Data);

int ioput();

void writeFile();

void readFile();

void testMemory();

void swap(int *, int *);

void bubble_sort(int arr[], int length);

void testRepeat();

void testArgs(int, ...);

void testPtrCal();

void testAllocMemory();

void testStrApi();

//======//
int main() {

//    sPrint();
//    printf("compute fei is : %d\n", computeFei(13));
//    computeFei(4);

//    cType();

//    test();

//    testStr();

//    fuck();

//    cHex();

//    testEnum();

//    testMemoryAddress();

//    testPointer();

//    funcPtr();


    //测试函数指针，直接将函数传递也是可以的
//    int (*p)(int, int) = max;
//    testCallback(p);
//    testCallback(max);

//    testStruct();

//    testBitRange();

//    union Data data;
//    data.i = 10;
//    data.f = 20.0f;
//    //char数组不能重新指定，只能复制
//    strcpy(data.str, "hello union");
//    getUnionSize(data);

//    ioput();

//    writeFile();

//    readFile();

//    testMemory();

    /**
     * C语言冒泡排序
     */
//    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
//    int length = sizeof(arr) / sizeof(*arr);
//    bubble_sort(arr, length);

//    testRepeat();

//    testArgs(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

//    testPtrCal();

    testAllocMemory();

//    testStrApi();
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

//    float weight;
//    float value;
//    printf("Please input a float number:");
//    scanf("%f", &weight); //&weight表示找到weight变量的地点
//
//    value = 10 * weight;
//    printf("value is : %.2f\n", value); //精确骚小数点后两位

//    printf("%f and %f is %f", value); //遗漏两个参数，但是不会报错，只会匹配第一个，后面没有匹配的完全是随机取数

    int a1; //-32768 ~ 32767
    unsigned int a; //0 ~ 65535 这个符号位现在用来表示数字了，表示的整数范围大了，没有负数范围了

    char cha = 'A';
    printf("%c\n", cha);
    cha = 97;
    printf("%c\n", cha);


    return 0;
}

/**
 * 测试进制类型
 */
int cHex() {
    int a = 16;
    printf("%d 的十进制是 %d，完整写法是%d \n", a, a, a);
    printf("%d 的八进制是 %o，完整写法是%#o \n", a, a, a);
    printf("%d 的十六进制是 %x，完整写法是%#x \n", a, a, a);
}

/**
 * 测试函数
 */
int test() {

    printf("\a hello, the number is %d \n", 10);
    return 0;
}

int pra1() {
    float g, h;
    float tax, rate;
    g = 1e21;
    tax = rate * g;
}

/**
 * C没有String，使用char数组来存储字符串
 * 空字符\0用来标记一个字符结束
 */
int testStr() {
    float weight;
    float volume;
    int size;
    int letters;
    char name[40];
    printf("input name:");
    scanf("%s", name);
    printf("input weight:");
    scanf("%f", &weight);
    size = sizeof(name); //获取占用的字节数(40，因为一个char占一个字节)
    printf("input size is: %d \n", size);
    letters = strlen(name); //这个函数用来获取字符实际长度
    volume = weight / DENSITY;
    printf("size = %d, letters = %d, volume =  %f \n", size, letters, volume);


    float a = 1.456633;
    printf("%1.2f\n", a); //四舍五入取小数点后两位

//    DENSITY = 10; //常量不能赋值
    const int H = 10; //const定义一个常量，是只读的
//    H = 10; //const的常量不能再次赋值

    float n1 = 100.11;
    float n2 = 100.22;
    int n3 = 10;
    int n4 = 11;
    int print = printf("result: %1d, %1d, %1d, %1d \n", n1, n2, n3, n4); //返回实际打印的字符数量
    printf("print is %d", print);
}

/**
 * extern表示只声明不定义，可以在别的文件中定义
 * 添加表示从别的文件中寻找，如果有多个就会报错
 */
extern int d = 4;
static int hello = 10;

extern void sayHello(); //表示是别的文件的方法

//void sayHello() {
//    printf("say hello in main.c file");
//}

void fuck() {

    register int a = 10; //只保存在寄存器中，没有内存位置，不能进行&操作
    auto int b = 10; //所有局部变量的默认存储方式

    printf("hello, fuck the sb C\n");


    sayHello();
}

void testEnum() {
    enum DAY day = WED;
    printf("%d", day);
}

int max(int a, int b) {
    return a > b ? a : b;
}

void testMemoryAddress() {
    int a = 10;
    printf("a的内存地址: %p\n", &a);

    int *ip = &a;
    printf("a的指针的值: %p\n", ip);
    printf("使用指针访问a的值: %d\n", *ip);

    int *ptr = NULL;
    printf("NUll指针: %p\n", ptr);
    if (ptr) {
        printf("this is a NULL pointer");
    }
    if (!ptr) {
        printf("this pointer is: %p\n", ptr);
    }
}

/**
 * 使用指针
 */
void testPointer() {
    //使用指针遍历数组
    int arr[] = {1, 2, 3, 4, 5, 6};
    int *ptr = arr;
    for (int i = 0; i < 6; ++i) {
        printf("address:%p, value:%d\n", ptr, *ptr);
        ptr++;
    }

    //使用指针作为下标访问数组 *&arr[1] = arr[1]
    printf("value2 = %d\n", *&arr[1]);
    printf("value1 = %d\n", *&arr[1]);

    //定义一个指针数组
    int *ptrArr[3]; //存放int类型的指针数组

    //指向指针的指针
    int a = 10;
    int *aPtr = &a; //指向a的指针
    int **aPtrPtr = &aPtr; //指向指针aPtr的指针
    printf("a = %d\n", *aPtr);
    printf("a = %d\n", **aPtrPtr); //需要两次取值

    int b = 20;
    printf("before change, b = %d\n", b);
    ptrFunction(&b);
    printf("after change, b = %d\n", b);

    int *ptr1 = returnIntPtr();
    printf("ptr=%p,value=%d", ptr1, *ptr1);
}

void ptrFunction(int *ptr) {
    *ptr = 100; //这里会直接修改参数值
}

/**
 * 从函数返回指针
 * 该函数返回一个int类型的指针
 */
int *returnIntPtr() {
    int a = 255;
    return &a;
}

/**
 * 函数指针
 * 指向函数的指针，可以直接当成函数使用
 * 因为可以直接当函数使用，就可以作为参数，实现回调函数
 */
int funcPtr() {

    //声明一个指针，一次为:返回类型: 指针名 参数
    int (*p)(int, int) = &max2;//&可以省略
    printf("max2 is :%d\n", p(3, 4));

    return 0;
}

int max2(int x, int y) {

    return x > y ? x : y;
}

/**
 * 回调函数
 * 使用函数指针作为参数，实现回调
 */
int testCallback(int (*pInt)(int, int)) {
    if (pInt) {
        int max = pInt(10, 20);
        printf("callback invoke result is %d\n", max);
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////结构体
///////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * 如果两个结构体互相包含，需要对其中一个结构体进行不完整声明
 * 结构体不可以定义成员函数，可以作为参数，可以有指向结构体的指针
 */

//对User进行不完全声明
struct User;

struct User {
    char id[50];
    char name[20];
    int age;
    struct User *user;//包含一个指向自己的指针
};

//另一种声明方式
typedef struct {

    char id[50];
    char name[20];
    int age;
    float money;
    //结构体可以包含其他结构体
    struct User user;

} User2;

//定义结构体的时候创建变量(顺带初始化)
struct Book {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;

    //自定义函数，不可以!!!
//    char[] toString() {
//        return "title=" + title + ", author=" + author + ", subject=" + subject + ", book_id=" + book_id;
//    };

} book = {"C语言", "卡卡罗特", "编程语言", 10086};


int testStruct() {
    //没有使用typedef声明的结构体，必须使用struct关键字进行变量声明
    struct User user;
    strcpy(user.name, "user-name");
    //使用了typedef声明的结构体，可以不加struct关键字
    User2 user2;
    strcpy(user2.name, "user2-name");
    //直接使用.来访问结构体的成员
    printf("author is: %s\n", book.author);

    //使用指针来访问结构体的成员，需要使用->
    struct Book *bookPtr = &book;
    printf("author is: %s\n", bookPtr->author);

    //使用指针来访问，使用->，不是使用typedef声明的结构体
    //需要加struct关键字
    struct User *userPtr = &user;
    printf("user name is: %s\n", userPtr->name);

    //使用typedef声明的，这里就不需要再加struct了
    User2 *user2Ptr = &user2;
    printf("user2 name is: %s\n", user2Ptr->name);
}


/**
 * 位域
 * 可以用来减少内存消耗，将一个字节拆分为几个片段来表示不同的功能
 *
 * 一个位域存放在同一个字节中，如果一个字节剩余空间不足以存放另一个位域时，
 * 则会从下一个字节开始存放，可以使用空域来调整存放位置
 *
 * 位域不能跨两个字节，所以位域的长度不能超过一个字节的长度，最大8位
 * 位域的值不能超过能表示的最大值
 *
 * 定义方法根结构相似，只是中间用冒号隔开，后面放长度
 */
struct BS {
    //a占8位
    int a:8;

    //b占2位
    int b:2;
    //c占6位
    int c:6;

    int d:4;
    int :4; //空域，占4位，不能使用

    int e:4; //被挤到第三个字节了
};

/**
 * 位域的使用
 */
int testBitRange() {
    struct BS bs;
    struct BS *ptr = &bs;
    ptr->a = 10; //使用指针的方式给位域赋值
    bs.a = 10; //给位域赋值
}

/**
 * 获取共用体的大小
 * @param data
 * @return 共用体大小，单位byte
 */
int getUnionSize(union Data data) {
    int size = sizeof(data);
    printf("size of data is %d\n", size);
    printf("i = %d\n", data.i);
    printf("f = %f\n", data.f);
    printf("str = %s\n", data.str);

    return size;
}

/**
 * 输入输出
 */

int ioput() {

    //从屏幕上读取下一个可用字符并返回为一个整数
//    int aChar = getchar();
//    printf("aChar is %d\n", aChar);
//    //将一个字符输出到屏幕上，并返回相同的字符
//    int bChar = putchar(aChar);
//    printf("bChar is %d\n", bChar);
//
//    char str[100];
//    printf("enter a value:");
//    //从stdin读取一行到str指定的缓冲区
//    gets(str);
//
//    printf("\nyou entered:");
//    //把str和一个尾随换行符写入到stdout
//    puts(str);


    char buffer[200];
    //接收从终端输入的字符串，放在buffer中
    int length = scanf("%s", buffer);
    printf("you scanf: %s, length is: %d,\n", buffer, length);

    return 0;
}

//================文件处理============================
/**
 * 写入文件(路径都要使用绝对路径)
 */
void writeFile() {
    FILE *fp = NULL;

    //打开文件，第一个为绝对路径，第二个为模式
    fp = fopen("/Users/lloydfinch/venn/workspace/c++/by_clion/c_code/test.txt", "w+");

    //写入文件
    fprintf(fp, "this is test of fprintf...\n");

    //写入文件
    //写入成功会返回一个非负值，错误返回EOF
    fputs("this is testing for fputs...\n", fp);

    //关闭流
    fclose(fp);
}

/**
 * 读取文件
 */
void readFile() {
    FILE *fp = NULL;
    char buff[255];

    //打开文件
    fp = fopen("/Users/lloydfinch/venn/workspace/c++/by_clion/c_code/test.txt", "r");

    //读取文件到buff中
    //从头读取，知道遇到空格为止
    fscanf(fp, "%s", buff);
    printf("fscanf: %s\n", buff);

    //读取一个并返回，错误返回EOF
    int c = fgetc(fp);
    printf("fgetc: %d\n", c);

    //读取文件到buff中
    //读取n-1个字符，直到遇见换行符为止，并且换行符也会读取，会在最后追加一个null字符
    fgets(buff, 255, fp);
    printf("fgets: %s\n", buff);

    //读取文件到buff中
    fgets(buff, 255, fp);
    printf("fgets2: %s\n", buff);
    fclose(fp);

}


/**
 * 可变参数
 */
double avarge(int num, ...) {

    double sum = 0.0;
//    va_list vaList;
//    int i;
//
//    //为num个参数初始化vaList
//    va_start(vaList, num);
//    //遍历读取
//    for (i = 0; i < num; i++) {
//        sum += va_arg(vaList, i);
//    }
//    //清理内存
//    va_end(vaList);


    return sum / num;
}


/**
 * 动态分配内存
 */
void testMemory() {
    char name[100];
    char *description;
    //给name赋值
    strcpy(name, "hello cpp");

    //动态分配内存(c++需要强制类型转换)
    description = malloc(200 * sizeof(char));
    //也可以这么写
//    description = calloc(200, sizeof(char));
    if (description == NULL) {
        //将内容输出到stderr流中
        fprintf(stderr, "error, unable to allocate required memory\n");
    } else {
        strcpy(description, "hello cpp has allocate 200 char space\n");
    }
    printf("name = %s\n", name);
    printf("description: %s\n", description);


    //重新调整内存(c++需要强制类型转换)
    description = realloc(description, 300 * sizeof(char));
    if (description == NULL) {
        fprintf(stderr, "realloc memory error\n");
    } else {
        strcat(description, "realloc memory success\n");
    }
    printf("name = %s\n", name);
    printf("description: %s\n", description);

    //释放内存
    free(description);
}


/**
 * C语言排序算法===============================================================================================
 */
/**
 * 冒泡排序
 * @param arr 要排序的数组
 * @param length 数组的长度
 */
void bubble_sort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&(arr[j]), &(arr[j + 1]));
            }
        }
    }

    printf("after sort, arr is\n");
    for (int k = 0; k < length - 1; k++) {
        printf("%d,", arr[k]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void testRepeat() {
    int a = 10;
    int *ip = &a;
    int **ipp = &ip;

    int b = *ip;
    int c = *(*ipp);
    printf("a=%d,ip=%p,ipp=%p,b=%d,c=%d\n", a, ip, ipp, b, c);

    int sizeIP = sizeof(ip);
    int sizeIpp = sizeof(ipp);
    //打印8
    printf("sizeIp=%d,sizeIpp=%d\n", sizeIP, sizeIpp);

    long l = 10;
    int *ipL = &l;
    //打印8，说明指针的大小就是8byte[当前计算机是64位的]，跟指向的数据类型无关
    printf("sizeIpL=%d\n", sizeof(ipL));

    //空指针的值是0x0
    int null = NULL;
//    int *ptrNull = &null;
    int *ptrNull = NULL;
    printf("size of ptrNull = %d, value = %d,\n", sizeof(ptrNull), ptrNull);
}


/*
 * 测试可变参数
 * count: 参数个数
 * ...: 参数列表
 */
void testArgs(int count, ...) {
    //声明变量列表
    va_list vaList;
    //初始化变量列表
    va_start(vaList, count);

    //遍历变量列表
    for (int i = 0; i < count; i++) {
        int num = va_arg(vaList, int);
        printf("arg%d = %d\n", i, num);
    }
    //清理变量列表内存
    va_end(vaList);
}

/**
 * 测试一下指针的运算
 */
void testPtrCal() {
    int a = 10;
    int b = 20;
    long c = 30;
    int *ptr_a = &a;
    int *ptr_b = &b;
    long *ptr_c = &c;

//    printf("ptr_a=%p\n", ptr_a);
//    printf("ptr_a=%p,ptr_b=%p\n", ptr_a, ptr_b);

    //地址a>b>c，证明栈模型
    //a = b + 4(int);
    //b = c + b(long);
    printf("ptr_a=%p,ptr_b=%p,ptr_c=%p\n", ptr_a, ptr_b, ptr_c);
}

/**
 * 动态内存分配
 */
void testAllocMemory() {
    int count = 100;
    //返回分配内存的起始点
    //int 4byte; char 1byte; long 8byte


    printf("long size:%d\n", sizeof(long));

    int charS = count * sizeof(char);
    printf("char size:%d", charS);
    int *charSize = malloc(charS);
    printf("malloc 100*char:%p\n", charSize);

    int *charSize2 = malloc(charS);
    printf("malloc 100*char2:%p\n", charSize2);

    int *intSize = malloc(count * sizeof(int)); //400
    printf("malloc 100*int:%p\n", intSize);

    int *longSize = malloc(count * sizeof(long));
    printf("malloc 100*long:%p\n", longSize);

    //重新调整内存
    longSize = realloc(longSize, (count * 2) * sizeof(longSize));
    printf("malloc 100*long2:%p\n", longSize);

    free(charSize);
    free(charSize2);
    free(intSize);
    free(longSize);
}

/**
 * 字符串的api
 */
void testStrApi() {
    char str[100];

    //使用指针
    char *ptr = &str;
    strcpy(ptr, "hello, cpp");

    //也可以这么写
//    strcpy(str, "hello, cpp");
    //甚至这么写
//    strcpy(&str, "hello, cpp");

    int length = strlen(str);
    printf("[%s] 's length is %d\n", str, length);
}

//定义struct
struct Student {

};

struct Student1 {
    char name[20];
    int age;
} student1 = {"zhangsan", 20};

//定义struct
typedef struct {

} Teacher;








