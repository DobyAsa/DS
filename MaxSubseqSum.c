#include <stdio.h>

int MaxSubseqSum1(int A[], int N);
int MaxSubseqSum2(int A[], int N);
int MaxSubseqSum3(int A[], int N);

int main(){
    int A[8] = {-1, 3, -2, 4, -6, 1, 6, -1};
    printf("%d\n", MaxSubseqSum3(A, 8));
    return 0;
}

int MaxSubseqSum1(int A[], int N){
    int ThisSum,MaxSum = 0;
    for (int i = 0; i < N; i++){    //i is the begin of subseq.
        for (int j = i; j < N; j++){    //j is the end of subseq.
            ThisSum = 0;
            for (int k = i; k <= j; k++){   //sum
                ThisSum += A[k];
            }
            if (MaxSum < ThisSum){
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}
int MaxSubseqSum2(int A[], int N){
    int ThisSum,MaxSum = 0;
    for (int i = 0; i < N; i++){    //i is the begin of subseq.
        ThisSum = 0;
        for (int j = i; j < N; j++){    //j is the end of subseq.
            ThisSum += A[j];
            if (MaxSum < ThisSum){
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}
int MaxSubseqSum3(int A[], int N){
    int ThisSum = 0,MaxSum = 0;
    for (int i = 0; i < N; i++){
        ThisSum += A[i];
        if (ThisSum > MaxSum){
            MaxSum = ThisSum;
        }else if (ThisSum < 0){
            ThisSum = 0;
        }
    }
    return MaxSum;
}