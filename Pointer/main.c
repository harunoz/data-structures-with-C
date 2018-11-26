//
//  main.c
//  Pointer
//
//  Created by Harun Öz on 11/24/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>
#define SIZE 50
#define    NULLCHAR    '\0'


int countWord(char * s1);
int copyEven(int *a1,int n1, int *a2);
void disparr(int ar[], int n);
void copyAlpha(char mySt1[],char mySt2[]);
void CountSubstring(char *str, char *substr);
void toLower(char * str);
void copyAlpha(char *s1,char*s2);
void changeString(char *line, char* char1,char*char2);
void checkBegin(char*str1,char*str2);
void insertString(char*line1,char*char1,int pos);
void myFunc(int n);
void reverse_string(char *s1);




int main(int argc, const char * argv[]) {
    
    
    char s1[] = "Reverse me!";
    char s2[] = "abc";
    char s3[] = "ab";
    char s4[] = "a";
    char s5[] = "";
    
    reverse_string(0);
    
    reverse_string(s1);
    reverse_string(s2);
    reverse_string(s3);
    reverse_string(s4);
    reverse_string(s5);
    
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("%s\n", s4);
    printf("%s\n", s5);



}





