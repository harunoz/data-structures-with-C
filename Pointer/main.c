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
void countSubst(char * str1, char * str2);
void toLower(char * str);
void copyAlpha(char *s1,char*s2);
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

void changeString(char *string, char *search, char *replace);


#include <stdio.h>


int main(int argc, const char * argv[]) {
    char line[SIZE]="harnozz";
    char char1[10]="harunoz";
    char char2[10]="gu";
    
    checkBegin(line, char1);
    
   // changeString(line, char1, char2);
}





