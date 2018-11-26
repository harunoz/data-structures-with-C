//
//  changeString.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>


void changeString(char *line, char* char1,char*char2){
    char *ptr;
    ptr= strstr(line,char1);
    while( ptr != '\0'){
        ptr = strstr(ptr + strlen(char1),char1);
            *line=*char2;
            line++;
        
        
    }
    printf("%s",line);
}
