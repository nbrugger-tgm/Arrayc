# Arrayz
A C Array and List lib

A C Lib for generic sized lists
### Example

```c
//method definition which will later on be used to print each entry
void prnt_entry(list_entry* val,int i){
    int* some = ((*val).value);
    printf("Entry : %d \n",*some);
}


int main(void){
    //define a list (pointer)
    list* myList = init_list();
    
    //some values we like to add
    int val1 = 11,val2 = 12,val3= 14;
    
    //Add the pointers to the list
    add_to_list(myList,&val1);
    add_to_list(myList,&val2);
    add_to_list(myList,&val3);
    add_to_list(myList,&val3);

    //create a function pointer
    each_callback each_code = &prnt_entry;
    
    
    //call the function pointer for each element in the list
    for_each(myList,each_code);
}
```
