//
//  countSubst.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>

void countSubst(char * str1, char * str2){
    char *ptr;
    int count=0;
    
    ptr=strstr(str1,str2);
    while(ptr != '\0'){
        count++;
        ptr=strstr(ptr + strlen(str2),str2);
    }
    printf("Count is %d\n",count);
}
