# MALLOC - C

This little malloc writed in c
It work with an array as the memory

# Explanation

It start with the MEMORY definition
an array of 1024
```
char MEMORY[1024]
```
We gonna use that array like the virtual memory
```
typedef struct Block {
    size_t size;
    int free;
    struct Block* next;
} Block;
```