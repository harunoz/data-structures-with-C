//
//  main.c
//  DynamicMemory
//
//  Created by Harun Öz on 11/25/18.
//  Copyright © 2018 Harun Öz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



typedef struct  node_s{
    int item;
    struct node_s* next;
}node_t;

typedef node_t* nodeptr;


nodeptr getnode(void);
void add_end(nodeptr  *headp, int item);
void displayList(nodeptr head);
void add_begin(nodeptr *headp, int item);
void addnth(nodeptr *headp, int item, int pos);
void deletenth(nodeptr *headp, int pos);




int main(int argc, const char * argv[]) {
    nodeptr head = NULL;
    int num;
    
    printf("Enter a number: ");
    scanf("%d" , &num);
    while(num != 0){
        add_end(&head, num);
        //add_begin(&head, num);
        printf("Enter a number: ");
        scanf("%d", &num);
    }
    addnth(&head, 88, 3);
    
    deletenth(&head, 2);
    
    displayList(head);
}

nodeptr getnode(void){
    nodeptr ptr;
    ptr = (nodeptr) malloc(sizeof(node_t));
    return ptr;
    
}

void addnth(nodeptr *headp, int item, int pos){
    nodeptr newptr,ptr;
    newptr = getnode();
    newptr -> item =item;
    newptr -> next = NULL;
    
    if(pos==1){
        newptr -> next = *headp;
        *headp=newptr;
    }
    
    ptr = *headp;
    for(int j=0; j<pos-2; j++){
        ptr = ptr -> next;
    }
    newptr->next=ptr ->next;
    ptr->next=newptr;
}

void deletenth(nodeptr *headp, int pos){
    nodeptr ptr;
    
    ptr=*headp;
    
    for (int j=0; j<pos-1; j++){
        ptr = ptr ->next;
    }
    ptr ->next=NULL;
    ptr ->next = ptr+1;
    
}

void add_begin(nodeptr *headp, int item){
    nodeptr newptr;
    newptr = getnode();
    newptr -> item = item;
    newptr -> next = *headp;
    *headp=newptr;
    
}


void add_end(nodeptr  *headp, int item){
    nodeptr newptr,ptr;
    newptr=getnode();
    
    newptr -> item = item;
    newptr -> next = NULL;
    
    
    if(*headp == NULL){
        *headp = newptr;
    }
    else{
        ptr =*headp;
        while(ptr -> next != NULL) ptr = ptr -> next;
        
        ptr -> next = newptr;
    }
}

void displayList(nodeptr head){
    nodeptr ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d\n",ptr -> item);
        ptr = ptr -> next;
    }
}