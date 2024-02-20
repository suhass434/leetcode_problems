typedef struct {
    int *arr;
    int ms;
    int top;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack *stack=malloc(sizeof(CustomStack));
    stack->arr=(int*)malloc(sizeof(int)*maxSize);
    stack->ms=maxSize;
    stack->top=-1;
    return stack;
    
}

void customStackPush(CustomStack* obj, int x) {
    if(obj->top==obj->ms-1)
        return;
    obj->arr[++(obj->top)]=x;
}

int customStackPop(CustomStack* obj) {
    if(obj->top==-1)
        return -1;
    return obj->arr[(obj->top)--];
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    if(k>=obj->ms)
        k=obj->ms;
    for(int i=0;i<k;i++)
        obj->arr[i]+=val; 
}

void customStackFree(CustomStack* obj) {

}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/
