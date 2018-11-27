//
//  lengthOfString.c
//  Pointer
//
//  Created by Harun Öz on 11/27/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>

void lengthOfString(char* chr1){
    int count=0;
    while(*chr1 != '\0'){
        count++;
        chr1++;
        
    }
    printf("Length is %d\n",count);
}
