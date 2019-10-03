//
// Created by Nils on 02.10.2019.
//

#include "arrayz.h"
#include <stdio.h>


typedef struct {
    void* next;
    void* value;
} list_entry;

typedef struct {
    list_entry* start;
    int size;
} list;
typedef void (*each_callback)(list_entry*, int);

list* init_list(){
    list lst;
    lst.start = NULL;
    lst.size = 0;
    return &lst;
}

void add_to_list(list* lst, void* value){
    list_entry* curent = lst->start;
    if(curent == NULL) {
        list_entry frst;
        frst.next = NULL;
        frst.value = value;
        lst->start = &frst;
        return;
    }
    while(curent->next != NULL){
        curent = curent->next;
    }
    list_entry* nxt = (list_entry*)(curent->next);
    nxt->value = value;
}

void for_each(list* lst,each_callback code){
    list_entry* curent = lst->start;
    int i = 0;
    while(curent != NULL){
        code((list_entry*)curent,i);
        i++;
        curent = curent->next;
    }
}




void prnt_entry(list_entry* val,int caunt){
    //printf(val);
    printf("Entry : %p \n",val);
}
int main(void){
    list* myList = init_list();
    int val1 = 11,val2 = 12,val3= 14;

    add_to_list(myList,&val1);
    add_to_list(myList,&val2);
    add_to_list(myList,&val3);

    each_callback each_code = &prnt_entry;
    for_each(myList,each_code);
}