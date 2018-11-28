//
//  swapElements.c
//  Pointer
//
//  Created by Harun Öz on 11/27/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


void swapElements(char *str1, char *str2){
 char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
    
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
    free(temp);
}
