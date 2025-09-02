# MALLOC - C

This little malloc writed in c
It work with an array as the memory

# Explanation

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
and for each lego is a block that save information
And the legos are that Struct Block