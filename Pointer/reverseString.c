//
//  reverseString.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>


void reverse_string(char *s1){
    if(s1 == 0){
        return; //Skip empty
    }
    if(*s1 ==0){
        return; //Skip empty
    }
    //getrange
    char *start = s1;
    char *end= start + strlen(s1) - 1 ;
    char temp;
    
    while(end > start){
        temp= *start;
        *start=*end;
        *end=temp;
        
        ++start;
        --end;
        
    }
}
