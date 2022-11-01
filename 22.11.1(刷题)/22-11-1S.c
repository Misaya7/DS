#define _CRT_SECURE_NO_WARNINGS 1
#define DATE	FILE* P = fopen("log.txt", "w"); \
                fprintf(P, "最后一次修改于:\ndate:%s\ntime:%s\n",\
					__DATE__, __TIME__); \
                fclose(P); P=NULL

//输入年份和月份，计算这一年这个月有多少天。
//输入描述：
//多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
//输出描述：
//针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。
//#include <stdio.h>
//
//int main() {
//    int a = 0;
//    int month = 0;
//    while (scanf("%d%d", &a, &month) != EOF) {
//        //int q1, q3, q5, q7, q8, q10, q12 = 31;
//        //int q4, q6, q9, q11 = 30;
//        int q2 = 28;
//        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0 && a % 400 == 0)) {
//            q2 = 29;
//        }
//        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
//            printf("%d\n", 31);
//        }
//        else if (month == 4 || month == 6 || month == 9 || month == 11) {
//            printf("%d\n", 30);
//        }
//        else {
//            printf("%d\n", q2);
//        }
//    }
//    return 0;
//}

//
//KiKi实现一个简单计算器，实现两个数的“加减乘除”运算，用户从键盘输入算式
//“操作数1运算符操作数2”，计算并输出表达式的值，如果输入的运算符号不包括在
//（ + 、 - 、 * 、 / ）范围内，输出“Invalid operation!”。当运算符为除法运算
//，即“ / ”时。如果操作数2等于0.0，则输出“Wrong!Division by zero!”
//输入描述：
//输入一行字符串，操作数1 + 运算符 + 操作数2 （其中合法的运算符包括： + 、 - 、 * 、 / ）。
//输出描述：
//输出为一行。
//
//如果操作数和运算符号均合法，则输出一个表达式，操作数1运算符操作数2 = 运算结果，
//各数小数点后均保留4位，数和符号之间没有空格。
//
//如果输入的运算符号不包括在（ + 、 - 、 * 、 / ）范围内，输出“Invalid operation!”。
//当运算符为除法运算，即“ / ”时。
//
//如果操作数2等于0.0，则输出“Wrong!Division by zero!”。
//#include <stdio.h>
//
//int main() {
//    double a = 0.0;
//    double c = 0.0;
//    char b = '0';
//    scanf("%lf%c%lf", &a, &b, &c);
//    if (b != '+' && b != '-' && b != '/' && b != '*') {
//        printf("Invalid operation!");
//        return 0;
//    }
//    else if (b == '/' && c == 0.0) {
//        printf("Wrong!Division by zero!");
//        return 0;
//    }
//   
//    if (b == '+') {
//        printf("%.4lf+%.4lf=%.4lf\n", a, c, a + c);
//    }
//    else if (b == '-') {
//        printf("%.4lf-%.4lf=%.4lf\n", a, c, a - c);
//    }
//    else if (b == '*') {
//        printf("%.4lf*%.4lf=%.4lf\n", a, c, a * c);
//    }
//    else if(b == '/') {
//        printf("%.4lf/%.4lf=%.4lf\n", a, c, a / c);
//    }
//    return 0;
//}

//输入描述：
//多组输入，一个整数（1~20），表示正方形的长度，也表示输出行数。
//
//输出描述：
//针对每行输入，输出用“ * ”组成的对应边长的正方形，每个“ * ”后面有一个空格。
//#include <stdio.h>
//
//int main() {
//    int a = 0;
//    while (scanf("%d", &a) != EOF) {
//        int i = 0;
//        for (i = 0; i < a; i++) {
//            int j = 0;
//            for (j = 0; j < a; j++) {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//输入描述：
//多组输入，一个整数（2~20），表示直角三角形直角边的长度，即“ * ”的数量，也表示输出行数。
//输出描述：
//针对每行输入，输出用“ * ”组成的对应长度的直角三角形，每个“ * ”后面有一个空格。
//#include <stdio.h>
//
//int main() {
//    int a;
//    while (scanf("%d", &a) != EOF) {
//        int i = 0;
//        for (i = 0; i < a; i++) {
//            int j = 0;
//            for (j = 0; j <= i; j++) {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

#include <stdio.h>
#include<stdlib.h>
int main() {
    
    int a = 0;
    scanf("%d", &a);
    int b = a;
    int* p = (int*)malloc(a * sizeof(int));
    int i = 0;
    
    for (i = 0; i < a; i++) {
        int q = 0;
        scanf("%d", &q);
        p[i] = q;
    }

    int left = 0;
    int right = a - 1;

    int* pp = (int*)malloc(a * sizeof(int));
    while (b > 0) {
        if (left >= right) {
            left = 0;
            right = a - 1;
        }

        pp[right] = p[left];

        left++;
        b--;
    }
    for (i = 0; i < a; i++) {

        printf("%d ", pp[i]);
    }
    return 0;
}

//
//#include <stdio.h>
//#include <malloc.h>
//int  main()
//{
//    int  n;
//    int  i, left, rigt;
//    int* ai = NULL;
//    int* temp_ai = NULL;
//    char move_sign = 1;
//    scanf("%d", &n);
//    if (NULL == (ai = (int*)malloc(n * sizeof(int))) || NULL == (temp_ai = (int*)malloc(n * sizeof(int))))
//        return 0;
//    for (i = n - 1; i > -1; i--)
//        scanf("%d", ai + i);
//    for (left = 0, rigt = n - 1, i = 0; i < n; i++)
//    {
//        if (1 == move_sign)
//        {
//            temp_ai[left++] = ai[i];
//            move_sign = 0;
//        }
//        else
//        {
//            temp_ai[rigt--] = ai[i];
//            move_sign = 1;
//        }
//    }
//    for (i = 0; i < n; i++)
//        printf("%d ", temp_ai[i]);
//    free(ai);
//    free(temp_ai);
//    return 0;
//}