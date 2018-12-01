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
    printf("ptr is %s\n",ptr);
    while((ptr=strstr(ptr, search))){
        printf("ptr2 is %s\n",ptr);
        strncpy(buffer, string, ptr-string);
         printf("buffer is %s\n",buffer);
        buffer[ptr-string] = '\0';

        strcat(buffer, replace);

        strcat(buffer, ptr+strlen(search));
         printf("buffer is %s\n",buffer);
        strcpy(string, buffer);
        ptr++;
    }
    printf("%s\n",string);
}
