//
//  changeString.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>


void changeString(char *string, char *search, char *replace){
    char buffer[100];
    char*ptr = string;
    while((ptr=strstr(ptr, search))){
        strncpy(buffer, string, ptr-string);
        buffer[ptr-string] = '\0';
        strcat(buffer, replace);
        strcat(buffer, ptr+strlen(search));
        strcpy(string, buffer);
        ptr++;
    }
    printf("%s\n",string);
}
