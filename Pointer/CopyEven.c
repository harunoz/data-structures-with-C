//
//  CopyEven.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>


int copyEven(int *a1,int n1,int *a2){
    int n2=0;
    int j;
    for (j=0; j<n1; j++){
        if(*a1 % 2 ==0){
            *a2=*a1;
            a2++;
            n2++;
        }
        a1++;
    }
    return n2;
}
