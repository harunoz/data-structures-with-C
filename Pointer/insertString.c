//
//  insertString.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


void insertString(char*line1,char*char1,int pos){
    int len1;
    char temp[20];
    
    len1=strlen(line1);
    
    if(pos <=0 || pos > len1){
        printf("Position is out of bound");
    }
    else{
        strcpy(temp,(line1+pos));
        printf("temp--> %s\n",temp);
        strcpy(line1+pos,char1);
        printf("line1 --> %s\n",line1);
        strcat(line1,temp);
        
    }
    printf("%s",line1);
}
