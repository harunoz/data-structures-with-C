//
//  main.c
//  Pointer
//
//  Created by Harun Öz on 11/24/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>
#define MAXLEN 50
#define    NULLCHAR    '\0'

int copyEven(int *a1,int n1, int *a2);
void disparr(int ar[], int n);
void copyAlpha(char mySt1[],char mySt2[]);

int main(int argc, const char * argv[]) {
    
//    int A[]={1,2,3,4,5};
  //  int size= sizeof(A) /sizeof(A[0]);
   // int total=sumOfElements(A,size);
    //printf("%d\n", total);
    
    
    int ar1[MAXLEN] = {7, 4, 9, 1, 12, 5, 4, 9, 6, 3, 2, 8, 7, 2};
  int ar2[MAXLEN];
    
    int n=14;
    int n2;
    n2= copyEven(ar1, n, ar2);
    disparr(ar2, n2);
   //char str1[MAXLEN] = "Abc, defgh -*+- (x + Y + z)\tqwERty098";
    //char str2[MAXLEN];
    
  //  printf("%s\n", str1);
    //copyAlpha(str1, str2);
    //printf("%s\n", str2);
    


}
int sumOfElements(int *A, int size){
    int j=0, sum=0;
    for (j=0;j<size;j++){
        sum += *(A+j);
    }
    return sum;
}


void disparr(int ar[], int n){
    int j;
    for(j=0; j<n;j++){
        printf("%d ", ar[j]);
        
    }
    printf("\n");
}

void copyAlpha(char mySt1[],char mySt2[]){
    while(*mySt1!= NULLCHAR){
        if(isalpha(*mySt1)){
            *mySt2 = *mySt1;
            mySt2++;
        }
        mySt1++;
    }
    *mySt2= NULLCHAR;
        
    
}
