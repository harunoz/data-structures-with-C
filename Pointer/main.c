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

void isPalindrome(char *str)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;
    
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            printf("%s is Not Palindrome", str);
            return;
        }
    }
    printf("%s is palindrome", str);
}
int main(int argc, const char * argv[]) {
    char line[SIZE]="abba abba";
    char char1[10]="ru";
    char char2[10]="HO";
    
    int n=0;
    
    isPalindrome(line);
    //insertString(line, char2, n);
   // changeString(line, char1, char2);
}





