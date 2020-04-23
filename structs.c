//
//  main.c
//  cs363_hw2_Oz_Harun.c
//
//  Created by Harun Öz on 12/8/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define    NULLCHAR    '\0'
#define    LINESIZE    1000
#define    MAXTOKENS    10
#define    TOKENSIZE    100

// Typedefs:
typedef  struct
{ // description of a student
    int studentId;        // student id
    char name[LINESIZE];        // name
    int birthdate;        // birth date in YYYYMMDD format
    char gender[2];        // gender
    char departmentCode[5];        // department code
    int class;        // class (1..4)
} student_t;

typedef struct node_s
{
    student_t  student;
    struct node_s *next;
} node_t;

typedef  node_t*  nodeptr;

// Function prototypes:
int readStudents(nodeptr *headp, char fname[]);
int getStudent(student_t *stup, char line[]);
nodeptr getnode();
void add_sorted(nodeptr *headp, student_t stu);
void add_end_node(nodeptr *headp, nodeptr newptr);
void print_LL (nodeptr head, char heading[]);
void print_LL_dept (nodeptr head, char dept[]);
void incr_class (nodeptr head);
int del_class (nodeptr *headp, nodeptr *head2p);
int dateStrInt(char str[]);
void splitDate(int ymd, int *dp, int *mp, int *yp);
int split (char str[], char separator[], char tokens[][TOKENSIZE]);
void rtrim (char str[]);

//======================================
// MAIN
int main(void)
{
    nodeptr head = NULL;        // head of LL, initialized.
    nodeptr headGrad = NULL;    // head of 2nd LL, initialized.
    
    
    // Input file name:
    char fileName[20];
    printf("Enter a file name \n");
    scanf("%s",fileName);
    readStudents(&head,fileName);
    char heading[20]="Students";
    print_LL(head,heading);
    
    printf("Enter a department name: \n");
    char headDepth[20];
    scanf("%s",headDepth);
    print_LL_dept(head,headDepth);
    
    incr_class(head);
    del_class(&head,&headGrad);
    int z9;
    scanf("%d",&z9);

    
} // end main

//======================================
// readStudents: From a text file read all data, store in students LL.
int readStudents(nodeptr *headp, char fname[])
{
    printf("readed\n");
    FILE *fptr;
    char line[LINESIZE];
    
    student_t student;
    
    
    fptr = fopen(fname,"r");
    if(fptr ==NULL){
        printf("Can not open a file %s \n", fname );
        system("PAUSE");
        exit(EXIT_FAILURE);
        
    }
    //read from a file
    
    fgets(line,LINESIZE,fptr);
    
    
    while( !feof(fptr)){
        getStudent(&student,line);
        add_sorted(headp,student);
        fgets(line,LINESIZE,fptr);
        
    }
    fclose(fptr);
    return 0;
    
}


//======================================
// Get student struct pointer and a line, split line, store data in student struct.
// Returns 1 if successful, 0 if not successful.
int getStudent(student_t *stup, char line[]){
    student_t student;
    
    char tokens[MAXTOKENS][TOKENSIZE];
    int tok;
    
    rtrim (line);
    tok = split (line, ";", tokens);
    // Assign tokens to data items
    stup->studentId = atoi(tokens[0]);
    strcpy (stup->name, tokens[1]);
    int ymd=dateStrInt(tokens[2]);
    stup->birthdate = ymd;
    strcpy (stup->gender, tokens[3]);
    strcpy (stup->departmentCode, tokens[4]);
    stup->class = atoi (tokens[5]);
    return 1;
    
} // end getStudent

//======================================
// getnode: allocate memory for a node and return its address.
nodeptr getnode()
{
    return ( (nodeptr) malloc (sizeof(node_t)) );
} // end getnode

//==========================================================
void add_sorted(nodeptr *headp, student_t stu)
{
    
    nodeptr newptr, ptr, prevptr;
    newptr = getnode();       // Create node.
    newptr->student = stu;
    

    
    if (*headp == NULL)       // If LL is empty,
    {
        newptr->next = NULL;    // Set next link of new node
        *headp = newptr;        // then, new node is first node.
    }
    else          // LL is not empty.
    {
        ptr = *headp;       // ptr points to first node.


        while (ptr != NULL && stu.birthdate >= ptr -> student.birthdate)    //
        {
            prevptr = ptr;        // save node address to prevptr
            ptr = ptr->next;      // ptr points next node.
        }
        if (ptr == *headp)
        {
            newptr->next = *headp;    //
            *headp = newptr;
        }
        else if (ptr == NULL)
        {
            newptr->next = NULL;  // can also be ptr because ptr == NULL
            prevptr->next = newptr;
        }
        else
        {
            newptr->next = ptr;   //
            prevptr->next = newptr;
        }
    }
    

    
} // end add_sorted

//==========================================================
// add_end_node: append a node to end of LL.
// In this version, new node already exists, and its pointer is passed.
void add_end_node(nodeptr *headp, nodeptr newptr)
{
    nodeptr ptr;
    
    newptr->next = NULL;        // Set next link of new node
    
    if (*headp == NULL)        // If LL is empty,
    {
        *headp = newptr;        // then, new node is first node.
    }
    else
    {
        ptr = *headp;
        while (ptr->next != NULL)
        {  ptr = ptr->next;  }
        ptr->next = newptr;
    }
} // end add_end

//======================================
// print_LL: Print all data in LL.
void print_LL (nodeptr head, char heading[]){
    int no=1;
    nodeptr ptr;
    printf("%s: \n",heading);
    printf ("No.  Id        Name                       G  Birthdate  Dept   Class   \n");
    printf ("==== ========= =======================    =  ========== =====  =====  \n");

    ptr=head;
    while(ptr != NULL){
        int day;
        int month;
        int year;
        int birthdate=ptr->student.birthdate;
        splitDate(birthdate, &day, &month, &year);
        char datestring[10];

        printf("%3d. %10d  %-24s %-2s %02d/%02d/%04d  %-5s %-5d\n",no, ptr->student.studentId, ptr->student.name,ptr->student.gender,day,month,year, ptr->student.departmentCode,ptr->student.class);
        
        no++;
        
        ptr = ptr->next;
    }
    
} // end print_LL

//======================================
// Print students that are in a given dept.
void print_LL_dept (nodeptr head, char dept[])
{
    int no=1;
    nodeptr ptr;
    printf("Students in %s: \n",dept);
    printf ("No.  Id        Name                       G  Birthdate  Dept   Class   \n");
    printf ("==== ========= =======================    =  ========== =====  =====  \n");

    ptr=head;
    
    while(ptr != NULL){
        if(strcmp(ptr->student.departmentCode,dept)==0){
        int day;
        int month;
        int year;
        int birthdate=ptr->student.birthdate;
        splitDate(birthdate, &day, &month, &year);
        char birthyear[25];
        sscanf(birthyear, "%d/%d/%d", &day, &month, &year);


        printf("%3d. %10d  %-24s %-2s %02d/%02d/%04d  %-5s %-5d\n",no, ptr->student.studentId, ptr->student.name,ptr->student.gender,day,month,year, ptr->student.departmentCode,ptr->student.class);
        
        no++;
            
        }
        
        ptr = ptr->next;
    }
    //????
} // end print_LL_dept

//======================================
// incr_class: Increment class by one for all students.
void incr_class (nodeptr head)
{
    printf("Students class is incremented. \n");
    nodeptr ptr;
    
    ptr = head;
    while (ptr != NULL)
    {
        ptr->student.class+=1;
        
        ptr = ptr->next;
    }
  
} // end incr_class

//======================================
// del_class: Move nodes with students whose class > 4 to 2nd LL.
// Returns number of moved nodes
int del_class (nodeptr *headp, nodeptr *head2p)
{
    int count=0;
    nodeptr ptr2;
    nodeptr prev;
    nodeptr ptr;
    ptr=*headp;
    ptr2=*head2p;
    while(ptr != '\0'){
        if(ptr->student.class >4){

            student_t student1;
            student1=  ptr -> student;
            add_sorted(head2p,student1);


            if(ptr->next->student.class ==5){
                prev->next=ptr->next->next;

            }
            else{
                prev->next=ptr->next;

            }

        


            count++;

        }

        prev=ptr;

        ptr=ptr->next;
    }
    printf("%d students are removed because they are graduated\n",count );
    print_LL(*headp,"Students");
    print_LL(*head2p,"Graduated Students");

    
    return count;
} // end del_class


//======================================
// dateStrInt: Converts "DD/MM/YYYY" to YYYYMMDD int value and returns it.
int dateStrInt(char str[])
{
    int d, m, y;
    sscanf(str, "%d/%d/%d", &d, &m, &y);
    return (y * 10000 + m * 100 + d);
} // end dateStrInt

//======================================
// splitDate: separates day, month and year from YYYYMMDD int date.
void splitDate(int ymd, int *dp, int *mp, int *yp)
{
    *yp = ymd / 10000;
    *dp = ymd % 100;
    *mp = (ymd / 100) % 100;
} // end splitDate

//======================================
// split: Separate tokens separated by a separator in a string,
// and places the tokens in a string array that is passed as 3rd parameter.
int split (char str[], char separator[], char tokens[][TOKENSIZE])
{
    int n = 0;  // Number of tokens
    char *ptr, *ptrstart;
    
    if(strlen(str) == 0)        // If string is empty...
    {  return (0);  }
    
    ptrstart = str;        // Set first token start addr.
    ptr = strstr(str, separator);    // Find address of 1st occurence of separator
    while (ptr != NULL)        // While separator is found...
    {
        strncpy(tokens[n], ptrstart, ptr - ptrstart);    // Copy token
        tokens[n][ptr - ptrstart] = NULLCHAR;    // Terminate token
        n++;                // Increment token counter
        ptrstart = ptr + strlen(separator);    // Set next token start addr.
        ptr = strstr(ptrstart, separator);    // Find address of next occur. of sep.
    }
    strcpy(tokens[n], ptrstart);        // Copy last token
    n++;                    // Increment token counter
    return (n);        // Return number of tokens
} // end split

//======================================
// Removes whitespaces at the end of the given string
void rtrim (char str[])
{
    int j = strlen(str) - 1;
    while (j >= 0 && isspace(str[j]) )
    {
        str[j] = NULLCHAR;
        j--;
    }
} // end rtrim