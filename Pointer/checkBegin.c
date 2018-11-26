//
//  checkBegin.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>


void checkBegin(char*str1,char*str2){
    if(strstr(str1,str2)==str1){
        printf("First string begin with second");
    }
    else{
        printf("First string  not begin with seconde");
    }
}
