#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50

typedef struct LNode *List;
struct LNode{
    int data[MAXSIZE];
    int last;
};

List MakeEmpty(){
    List PtrL;
    PtrL = (List )malloc(sizeof(struct LNode));
    PtrL->last = -1;
    return  PtrL;
}

int Find(int x, List PtrL){
    int i = 0;
    int last = PtrL->last;
    while(i <= last && PtrL->data[i] != x)
        i++;
    if(i <= last){
        return i;
    }
    return -1;
}

int Insert(int data, int n, List PtrL){

    for(int i = PtrL->last; i >= n; i--){
        PtrL->data[i+1] = PtrL->data[i];
    }
    PtrL->data[n] = data;
    PtrL->last++;
    return data;
}

int Delete(int n, List PtrL){
    for(int i = n; i < PtrL->last; i++){
        PtrL->data[i] = PtrL->data[i+1];
    }
    PtrL->last--;
    return 0;
}

int show(List PtrL){
    for(int i = 0; i <= PtrL->last; i++){
        printf("%d\n", PtrL->data[i]);
    }
    return PtrL->last+1;
}

int main(){
    List p = MakeEmpty();
    for(int i = 0; i < 10; i++){
        p->data[i] = i+2;
    }
    p->last = 9;
    // Delete(3, p);
    Insert(9, 3, p);

    show(p);
    return 0;
}