#define _CRT_SECURE_NO_WARNINGS 1
#define DATE	FILE* P = fopen("log.txt", "w"); \
                fprintf(P, "���һ���޸���:\ndate:%s\ntime:%s\n",\
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
//bool Insertlist(Lnode* p, int i,int e) {//��p�еĵ�i��λ�ò���e
//    if (i < 1) {
//        return false;
//    }
//    Lnode* q = p;//q��ͷָ��p��ʼɨ��,qָ������ɨ�赽�Ľ��
//    int j = 0;//��ǰqָ����ǵڼ������
//    while (j < i - 1 && q != NULL) {//q�ҵ���i-1�����
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
//    Lnode L;//����һ����ͷ
//    Initlist(&L);
//    if (Emptylist(&L)) {
//        printf("�ձ�\n");
//    }
//    else {
//        printf("��Ϊ��\n");
//    }
//    Insertlist(&L, 1, 1);
//    if (Emptylist(&L)) {
//        printf("�ձ�\n");
//    }
//    else {
//        printf("��Ϊ��\n");
//    }
//    return 0;
//}


//��ͷ���ĵ�����
typedef struct Lnode {
    int data;
    struct Lnode* next;
}Lnode;
//bool Initlist(Lnode* p) {//β�巨��ʼ��������
//    p->next = NULL;
//    Lnode* r = p;//βָ��
//    printf("��Ҫ��ʼ�����ٸ���:>");
//    int in = 0;
//    scanf("%d", &in);
//
//    int num = 1;
//    while (in--) {
//        
//        Lnode* n = (Lnode*)malloc(sizeof(Lnode));
//        printf("��%d��ֵΪ:>",num);
//        scanf("%d", &n->data);
//        n->next = NULL;
//        r->next = n;
//        r = n;
//        num++;
//    }
//    printf("¼��ɹ�!\n");
//    return true;
//}

bool Initlist(Lnode* p) {//ͷ�巨��ʼ��������
    p->next = NULL;
    printf("��Ҫ��ʼ�����ٸ���:>");
    int in = 0;
    scanf("%d", &in);

    int num = 1;
    while (in--) {
        Lnode* n = (Lnode*)malloc(sizeof(Lnode));
        printf("��%d��ֵΪ:>", num);
        scanf("%d", &n->data);
        n->next = p->next;
        p->next = n;
        num++;
    }
    printf("¼��ɹ�!\n");
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
    Lnode* q = p;//q��ͷָ��p��ʼɨ��,qָ������ɨ�赽�Ľ��
    int j = 0;//��ǰqָ����ǵڼ������
    while (j < i - 1 && q != NULL) {//q�ҵ���i-1�����
        q = q->next;
        j++;
    }
    return q;
}
bool Insertlist(Lnode* p, int i,int e) {//��p�еĵ�i��λ�ò���e
    //if (i < 1) {
    //    return false;
    //}
    //Lnode* q = p;//q��ͷָ��p��ʼɨ��,qָ������ɨ�赽�Ľ��
    //int j = 0;//��ǰqָ����ǵڼ������
    //while (j < i - 1 && q != NULL) {//q�ҵ���i-1�����
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
    //Lnode* q = p;//q��ͷָ��p��ʼɨ��,qָ������ɨ�赽�Ľ��
    //int j = 0;//��ǰqָ����ǵڼ������
    //while (j < i - 1 && q != NULL) {//q�ҵ���i-1�����
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
Lnode* Getelsm(Lnode* p, int i) {//��λ����
    Lnode* q = Findlast(p, i);//�ҵ���i-1�����
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
    //    printf("�ձ�\n");
    //}
    //else {
    //    printf("��Ϊ��\n");

    Insertlist(head, 3, 9);
    printf("����%d�ɹ�\n", 9);

    Showlist(head);

    Lnode* n = (Lnode*)malloc(sizeof(Lnode));
    Reverse(head, n);
    Showlist(n);

    printf("����Ϊ:%d\n", Length(head));

    int e = 0;
    Dellist(head,1,&e);
    printf("ɾ����%d\n", e);

    Showlist(head);

    Lnode* o = Getelsm(head, 3);
    if (o != NULL)
    printf("%d\n", o->data);
    else {
        printf("û���ҵ�\n");
    }

    printf("����Ϊ:%d\n", Length(head));

    n = (Lnode*)malloc(sizeof(Lnode));
    Reverse(head,n);
    Showlist(n);
}

////��ʮ���Ƴ�������
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

//�ݹ�õ�������
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