#define _CRT_SECURE_NO_WARNINGS 1
#define DATE	FILE* P = fopen("log.txt", "w"); \
                fprintf(P, "���һ���޸���:\ndate:%s\ntime:%s\n",\
					__DATE__, __TIME__); \
                fclose(P); P=NULL

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

//��̬˳���ĳ�ʼ�������ӣ�ɾ��
//#define MAXSIZE 10
//typedef struct list {
//    int data[MAXSIZE];
//    int length;       //��ǰ����
//}sqlist;
//
//void Initlist(sqlist* p) {
//    memset(p->data,0,MAXSIZE*sizeof(int));
//    p->length = 0;
//}
//bool Insertlist(sqlist* p, int i, int e) { //��i������e
//    if (i<1 || i>p->length + 1 || i > MAXSIZE)
//        return false;
//    int j = p->length;
//    for (j; j > i - 1; j--) {
//        p->data[j] = p->data[j - 1];
//    }
//    p->data[i - 1] = e;
//    p->length++;
//    return true;
//}
//bool Dellist(sqlist* p, int i, int* e) {//ɾ����i�����֣�����e
//    if (i<1 || i>p->length + 1 || i > MAXSIZE)
//        return false;
//    *e = p->data[i - 1];
//    //int j = i - 1;
//    for (i; i < p->length; i++)
//        p->data[i - 1] = p->data[i];
//    p->length--;
//    return true;
//}
// int Get(sqlist* p, int i) {//��λ����
//if (i<1 || i > p->length) {
//    return -1;
//}
//return p->data[i - 1];
//}
//int Searchlist(sqlist* p, int x) {//����x���ɹ�����λ��
//    int i = 0;
//    for (i = 0; i < p->length; i++) {
//        if (p->data[i] == x) {
//            return i + 1;
//        }
//    }
//        return 0;
//}
//int main() {
//    sqlist q;
//    Initlist(&q);
//    Insertlist(&q, 1, 3);
//    Insertlist(&q, 2, 4);
//    Insertlist(&q, 3, 5);
//    Insertlist(&q, 4, 6);
//    Insertlist(&q, 5, 7);
//    if (Searchlist(&q, 5)) {
//        printf("λ��Ϊ%d\n", Searchlist(&q, 5));
//    }
//    else {
//        printf("û���ҵ�\n");
//    }
//        //if (Insertlist(&q, 1, 1)) {
//        //    printf("��")
//        //}
//    int e = 1; 
//    if (Dellist(&q, 3, &e)) {
//        printf("ɾ��%d�ɹ�\n", e);
//    }
//    else {
//        printf("ɾ��ʧ��\n");
//    }
//
//
//    if (Searchlist(&q, 5)) {
//        printf("λ��Ϊ%d\n", Searchlist(&q, 5));
//    }
//    else {
//        printf("û���ҵ�\n");
//    }
//    return 0;
//}


//��̬˳���ĳ�ʼ�������ӣ�ɾ��
#define Initsize 10
typedef struct list {
    int* data;
    int length;       //��ǰ����
}sqlist;

void Initlist(sqlist* p) {
    p->data = (int*)calloc(Initsize , sizeof(int));
//    memset(p->data, 0, Initsize * sizeof(int));
    p->length = 0;
}
void Increaselist(sqlist* p,int x) {
//    int i = (x + Initsize) * sizeof(int);
    int* pp = (int*)realloc(p->data, (x + p->length) * sizeof(int));
    p->data = pp;
    pp = NULL; 
}
bool Insertlist(sqlist* p, int i, int e) { //��i������e
    if (i<1 || i>p->length + 1)
        return false;
    int j = p->length;
    for (j; j > i - 1; j--) {
        p->data[j] = p->data[j - 1];
    }
    p->data[i - 1] = e;
    p->length++;
    return true;
}
bool Dellist(sqlist* p, int i, int* e) {//ɾ����i�����֣�����e
    if (i<1 || i>p->length + 1)
        return false;
    *e = p->data[i - 1];
    //int j = i - 1;
    for (i; i < p->length; i++)
        p->data[i - 1] = p->data[i];
    p->length--;
    return true;
}
int Searchlist(sqlist* p, int x) {//����x���ɹ�����λ��
    int i = 0;
    for (i = 0; i < p->length; i++) {
        if (p->data[i] == x) {
            return i + 1;
        }
    }
    return 0;
}
int Get(sqlist* p, int i) {//��λ����
    if (i<1 || i > p->length) {
        return -1;
    }
    return p->data[i - 1];
}
void Destorylist(sqlist* p) {
    free(p->data);
    p->data = NULL;
}
int main() {
    sqlist q;
    Initlist(&q);
    Insertlist(&q, 1, 3);
    Insertlist(&q, 2, 4);
    Insertlist(&q, 3, 5);
    Insertlist(&q, 4, 6);
    Insertlist(&q, 5, 7);
    Increaselist(&q, 3);

    int get=Get(&q, 3);
    printf("%d\n", get);

    if (Searchlist(&q, 5)) {
        printf("λ��Ϊ%d\n", Searchlist(&q, 5));
    }
    else {
        printf("û���ҵ�\n");
    }

    if (Searchlist(&q, 7)) {
        printf("λ��Ϊ%d\n", Searchlist(&q, 7));
    }
    else {
        printf("û���ҵ�\n");
    }
    //if (Insertlist(&q, 1, 1)) {
    //    printf("��")
    //}
    int e = 1;
    if (Dellist(&q, 3, &e)) {
        printf("ɾ��%d�ɹ�\n", e);
    }
    else {
        printf("ɾ��ʧ��\n");
    }


    if (Searchlist(&q, 5)) {
        printf("λ��Ϊ%d\n", Searchlist(&q, 5));
    }
    else {
        printf("û���ҵ�\n");
    }
    
    get = Get(&q, 3);
    printf("%d\n", get);

    Destorylist(&q);
    return 0;
}