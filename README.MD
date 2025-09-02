# MALLOC - C

This little malloc writed in C
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
There we are in the first Lego (**Block**)
```c
while (curr!=NULL) {/*Existing code...*/}
```
It runs the Lego box (**Head**) until it found one that's free and it size
dosent overflow the **MEMORY** size with the next code
```c
        if(curr->free&&curr->size>=size){
            curr->free=0;
            return (void*)(curr+1);
        }
```
There we use the closest free Lego (**Block**) to use,
And the 
```c
return (void*)(curr+1);
```
Returns the Lego (**Block**) Pointer,
If that dosent true it will point to the next Lego (**Block**)
```c
curr=curr->next;
```
And finally it returns **NULL** if there's no space avaible in the **Virtual Memory**