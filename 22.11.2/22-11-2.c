#define _CRT_SECURE_NO_WARNINGS 1
#define DATE	FILE* P = fopen("log.txt", "w"); \
                fprintf(P, "最后一次修改于:\ndate:%s\ntime:%s\n",\
					__DATE__, __TIME__); \
                fclose(P); P=NULL

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//typedef struct Lnode {
//    int data;
//    struct Lnode* next;
//}Lnode;
//
//bool Initlist(Lnode* p) {
//    p = (Lnode*)malloc(sizeof(Lnode));
//    if (p == NULL) {
//        return false;
//    }
//    p->next = NULL;
//    return true; 
//}
//bool Emptylist(Lnode* p) {
//    if (p->next == NULL) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//bool Insertlist(Lnode* p, int i,int e) {//在p中的第i个位置插入e
//    if (i < 1) {
//        return false;
//    }
//    Lnode* q = p;//q从头指针p开始扫描,q指向现在扫描到的结点
//    int j = 0;//当前q指向的是第几个结点
//    while (j < i - 1 && q != NULL) {//q找到第i-1个结点
//        q = q->next;
//        j++;
//    }
//    if (q == NULL) {
//        return false;
//    }
//    Lnode* s = (Lnode*)malloc(sizeof(Lnode));
//    s->data = e;
//    s->next = q->next;
//    q->next = s;
//    return true;
//}
//int main() {
//    Lnode L;//定义一个表头
//    Initlist(&L);
//    if (Emptylist(&L)) {
//        printf("空表\n");
//    }
//    else {
//        printf("不为空\n");
//    }
//    Insertlist(&L, 1, 1);
//    if (Emptylist(&L)) {
//        printf("空表\n");
//    }
//    else {
//        printf("不为空\n");
//    }
//    return 0;
//}


//带头结点的单链表
typedef struct Lnode {
    int data;
    struct Lnode* next;
}Lnode;
//bool Initlist(Lnode* p) {//尾插法初始化单链表
//    p->next = NULL;
//    Lnode* r = p;//尾指针
//    printf("你要初始化多少个数:>");
//    int in = 0;
//    scanf("%d", &in);
//
//    int num = 1;
//    while (in--) {
//        
//        Lnode* n = (Lnode*)malloc(sizeof(Lnode));
//        printf("第%d个值为:>",num);
//        scanf("%d", &n->data);
//        n->next = NULL;
//        r->next = n;
//        r = n;
//        num++;
//    }
//    printf("录入成功!\n");
//    return true;
//}

bool Initlist(Lnode* p) {//头插法初始化单链表
    p->next = NULL;
    printf("你要初始化多少个数:>");
    int in = 0;
    scanf("%d", &in);

    int num = 1;
    while (in--) {
        Lnode* n = (Lnode*)malloc(sizeof(Lnode));
        printf("第%d个值为:>", num);
        scanf("%d", &n->data);
        n->next = p->next;
        p->next = n;
        num++;
    }
    printf("录入成功!\n");
    return true;
}
bool Reverse(Lnode* p,Lnode* n) {
        n->next = NULL;
        while (p->next) {
            Lnode* s = (Lnode*)malloc(sizeof(Lnode));
            p = p->next;
            s->data = p->data;
            s->next = n->next;
            n->next = s;
        }
    return true;
}
bool Emptylist(Lnode* p) {
    if (p->next == NULL) {
        return true;
    }
    return false;
}
Lnode* Findlast(Lnode* p, int i) {
    if (i < 1) {
        return 0;
    }
    Lnode* q = p;//q从头指针p开始扫描,q指向现在扫描到的结点
    int j = 0;//当前q指向的是第几个结点
    while (j < i - 1 && q != NULL) {//q找到第i-1个结点
        q = q->next;
        j++;
    }
    return q;
}
bool Insertlist(Lnode* p, int i,int e) {//在p中的第i个位置插入e
    //if (i < 1) {
    //    return false;
    //}
    //Lnode* q = p;//q从头指针p开始扫描,q指向现在扫描到的结点
    //int j = 0;//当前q指向的是第几个结点
    //while (j < i - 1 && q != NULL) {//q找到第i-1个结点
    //    q = q->next;
    //    j++;

//    }
    Lnode* q = Findlast(p, i);
    
    if (q == NULL) {
        return false;
    }

    Lnode* s = (Lnode*)malloc(sizeof(Lnode));
    s->data = e;
    s->next = q->next;
    q->next = s;
    return true;
}
bool Dellist(Lnode* p, int i,int *e) {
    Lnode* q = Findlast(p, i);
    //if (i < 1) {
    //    return false;
    //}
    //Lnode* q = p;//q从头指针p开始扫描,q指向现在扫描到的结点
    //int j = 0;//当前q指向的是第几个结点
    //while (j < i - 1 && q != NULL) {//q找到第i-1个结点
    //    q = q->next;
    //    j++;
    //}
    if (q == NULL) {
        return false;
    }
    if (p->next == NULL) {
        return false;
    }
    Lnode* u = q->next;
    *e = u->data;
    q->next = u->next;
    free(u);
    u = NULL;
    return true;
}
bool Showlist(Lnode* p) {
    if (p->next == NULL) {
        return false;
    }
    
    while (p->next!=NULL) {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
    return true;
}
Lnode* Getelsm(Lnode* p, int i) {//按位查找
    Lnode* q = Findlast(p, i);//找到第i-1个结点
    if (q== NULL)
        return NULL;

    q = q->next;
    if (q != NULL)
        return q;
    else
        return NULL;
}
int Length(Lnode* p) {
    int len = 0;
    Lnode* q = p->next;
    while (q != NULL) {
        q = q->next;
        len++;
    }
    return len;
}
int main() {
    Lnode* head = (Lnode*)malloc(sizeof(Lnode));
    Initlist(head);
    Showlist(head);
    //if (Emptylist(head)) {
    //    printf("空表\n");
    //}
    //else {
    //    printf("不为空\n");

    Insertlist(head, 3, 9);
    printf("插入%d成功\n", 9);

    Showlist(head);

    Lnode* n = (Lnode*)malloc(sizeof(Lnode));
    Reverse(head, n);
    Showlist(n);

    printf("长度为:%d\n", Length(head));

    int e = 0;
    Dellist(head,1,&e);
    printf("删除了%d\n", e);

    Showlist(head);

    Lnode* o = Getelsm(head, 3);
    if (o != NULL)
    printf("%d\n", o->data);
    else {
        printf("没有找到\n");
    }

    printf("长度为:%d\n", Length(head));

    n = (Lnode*)malloc(sizeof(Lnode));
    Reverse(head,n);
    Showlist(n);
}

////给十进制出二进制
//int main() {
//    int input = 0;
//    scanf("%d", &input);
//    int arr[32] = { 0 };
//    int i = 0;
//    while (input != 0) {
//        int shang = input;
//        shang = shang % 2;
//        arr[i] = shang;
//        
//        input = input / 2;
//
//        i++;
//    }
//    i--;
//    for (i; i >=0; i--) {
//        printf("%d", arr[i]);
//    }
//    return 0;
//}

//递归得到二进制
//void er(int input) {
//    if (input) {
//        er(input / 2);
//    }
//    if (input == 0)
//        return;
//    printf("%d", input % 2);
//}
//
//int main() {
//    int input = 0;
//    scanf("%d", &input);
//    er(input);
//
//    return 0;
//}