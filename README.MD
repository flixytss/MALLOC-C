# MALLOC - C

This little malloc writed in c
It work with an array as the memory

## Explanation

It start with the MEMORY definition
an array of 1024
```c
char MEMORY[1024]
```
We gonna use that array as the virtual memory
```c
typedef struct Block {
    size_t size;
    int free;
    struct Block* next;
} Block;
```
Now, To imagine the teory
A good way to learn it is imagine a big lego box
and for each lego is a block that save information,
In this case the legos are that Struct Block
```c
Block* head = (void*)MEMORY;
```
There we define the Lego box (The **head**) to save all the Legos (**Blocks**),
There we make transform the **MEMORY** to a usable Lego box (**Blocks**)
```c
void* malloc(unsigned int size){
    Block* curr = head;
    while (curr!=NULL) {
        if(curr->free&&curr->size>=size){
            curr->free=0;
            return (void*)(curr+1);
        }
        curr=curr->next;
    }
    return NULL;
}
```
There is the principal **Void* Function** that returns the closest Lego (**Block**) Pointer
```c
Block* curr = head;
```
Here we define a pointer of the Lego Box (**Head**)