#include<stdio.h>
#include<time.h>

clock_t s,e;

void PrintN(int n);

int main(){
    s = clock();
    PrintN(100000);
    e = clock();

    printf("%f",((double)(e-s))/CLOCKS_PER_SEC);
    return 0;
}

void PrintN(int n){
    for(int i = 1; i <= n; i++){
        // printf("%d\n",i);
    }
}
// void PrintN(int n){
//     if (n > 0){
//         PrintN(n-1);
//         printf("%d\n",n);
//     }
// }