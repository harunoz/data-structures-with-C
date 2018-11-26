//
//  toLower.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>

void toLower(char *str){
    for(int i = 0; *(str+i); i++){
        *(str+i) = tolower(*(str+i));
    }
    printf("%s",str);


}


