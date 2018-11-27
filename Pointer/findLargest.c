//
//  findLargest.c
//  Pointer
//
//  Created by Harun Öz on 11/27/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>


void findLargest(int n){
    float *element;
    element= (float*)calloc(n,sizeof(float));
    if(element==NULL){
        printf("Not enough space! \n");
    }
    else{
        for(int i=0; i<n ; i++){
            printf("Enter e element. \n");
            scanf("%f",element+i);
            
        }
        for (int i=1; i<n;++i){
            if(*element < *(element+i)){
                *element=*(element+i);
            }
        }
        printf("Largest eleemnt is %f ",*element);
    }
}
