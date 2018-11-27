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
int addTwoNumbers(int *n, int *n2);
void changePosition(char* ch1, char* ch2);
void charPermu(char *cht, int stno, int endno);
void findLargest(int n);
void lengthOfString(char* chr1);
void swapElements(char *str1, char *str2);


#include <stdio.h>


int main(int argc, const char * argv[]) {
    char myString[200]="harun";
    char myString1[200]="h";
    
    
    CountSubstring(myString,myString1 );
}





