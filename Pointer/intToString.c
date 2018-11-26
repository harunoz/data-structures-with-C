//
//  intToString.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>
void myFunc(int n){
    char *ptr;
    char myString[250];
    ptr= malloc(200*sizeof(char));
    if(ptr == NULL){
        printf("Not available.");
    }
    *ptr='\0';
    for(int k=0; k<n; k++){
        sprintf(myString,"%d",k);
        
        strcat(ptr,myString);
        
    }
    printf("%s\n n",ptr);
    
}
