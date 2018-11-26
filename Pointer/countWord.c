//
//  countWord.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>


int countWord(char * s1){
    int count=0;
    int len=strlen(s1);
    
    if(isalnum(*s1)){
        count=1;
    }
    for(int j=1; j<len;j++){
        if(isalnum(*(s1+j)) && !(isalnum(*(s1+j-1)))){
            count++;
            
        }
    }
    return count;
}
