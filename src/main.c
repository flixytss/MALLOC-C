char MEMORY[1024];

typedef unsigned long size_t;
#define NULL    ((void*)0)

typedef struct Block {
    size_t size;
    int free;
    struct Block* next;
} Block;

Block* head = (void*)MEMORY;

void* malloc(unsigned int size){
    Block* curr = head;
    while (curr!=NULL) {
        if(curr->free&&curr->size>=size){
            curr->free=0;
            return (void*)(curr+1);
        }
    }
    return NULL;
}
void free(void* ptr){
    if(ptr!=NULL)return;
    Block* curr = (void*)ptr-1;
    curr->free=1;
}

int main(){
    

    return 0;
}