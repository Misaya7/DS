#define _CRT_SECURE_NO_WARNINGS 1
#define DATE	FILE* P = fopen("log.txt", "w"); \
                fprintf(P, "���һ���޸���:\ndate:%s\ntime:%s\n",\
					__DATE__, __TIME__); \
                fclose(P); P=NULL

//������ݺ��·ݣ�������һ��������ж����졣
//����������
//�������룬һ���������������ֱ��ʾ��ݺ��·ݣ��ÿո�ָ���
//���������
//���ÿ�����룬���Ϊһ�У�һ����������ʾ��һ��������ж����졣
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
//KiKiʵ��һ���򵥼�������ʵ���������ġ��Ӽ��˳������㣬�û��Ӽ���������ʽ
//��������1�����������2�������㲢������ʽ��ֵ����������������Ų�������
//�� + �� - �� * �� / ����Χ�ڣ������Invalid operation!�����������Ϊ��������
//������ / ��ʱ�����������2����0.0���������Wrong!Division by zero!��
//����������
//����һ���ַ�����������1 + ����� + ������2 �����кϷ�������������� + �� - �� * �� / ����
//���������
//���Ϊһ�С�
//
//�����������������ž��Ϸ��������һ�����ʽ��������1�����������2 = ��������
//����С����������4λ�����ͷ���֮��û�пո�
//
//��������������Ų������ڣ� + �� - �� * �� / ����Χ�ڣ������Invalid operation!����
//�������Ϊ�������㣬���� / ��ʱ��
//
//���������2����0.0���������Wrong!Division by zero!����
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

//����������
//�������룬һ��������1~20������ʾ�����εĳ��ȣ�Ҳ��ʾ���������
//
//���������
//���ÿ�����룬����á� * ����ɵĶ�Ӧ�߳��������Σ�ÿ���� * ��������һ���ո�
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

//����������
//�������룬һ��������2~20������ʾֱ��������ֱ�Ǳߵĳ��ȣ����� * ����������Ҳ��ʾ���������
//���������
//���ÿ�����룬����á� * ����ɵĶ�Ӧ���ȵ�ֱ�������Σ�ÿ���� * ��������һ���ո�
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