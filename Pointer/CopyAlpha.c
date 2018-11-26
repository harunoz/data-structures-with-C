//
//  CopyAlpha.c
//  Pointer
//
//  Created by Harun Öz on 11/26/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//
#define NULLCHAR '\0'

#include <stdio.h>


void copyAlpha(char *s1, char *s2)
{
    while(*s1 != NULLCHAR)
    {
        if(isalpha(*s1))
        {
            *s2 = *s1;
            s2++;
        }
        s1++;
    }
    *s2 = NULLCHAR;

}
