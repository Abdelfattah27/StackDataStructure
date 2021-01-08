///stack with array based implementation

#include <iostream>

using namespace std;
#define stackelement int
#define STACKSIZE 1000
struct stack{
    stackelement elements[STACKSIZE] ;
    int stacksize ;
};
void creatstack (stack* st )
{
    st->stacksize = 0 ;
}
void push(stack *st , stackelement item){
        st->elements[st->stacksize++] = item;
}
stackelement top(stack *st){
        return st->elements[st->stacksize  -1];
}
stackelement pop(stack *st){
       stackelement popedvalue = top(st) ;
        st->stacksize-- ;
        return popedvalue ;
}

bool empty(stack *st){
        return (st->stacksize == 0) ;
}
void clear(stack *st){
        st->stacksize = 0 ;
}
int size(stack *st){
        return st->stacksize ;
}
void traversestack (stack *st , void(*go)(stackelement)){
    int temppointer = st->stacksize ;
        while(temppointer){
            (*go)(st->elements[--temppointer]) ;
        }
}
bool full (stack *st){
    return (st->stacksize == STACKSIZE) ;
}
void log(stackelement value){
cout<<value<<endl;
}
int main()
{
    stack stack1 ;
    creatstack(&stack1) ;
    push(&stack1, 1) ;
    push(&stack1, 2) ;
    push(&stack1, 3) ;
    push(&stack1, 4) ;
    push(&stack1, 5) ;
    push(&stack1, 6) ;
    push(&stack1, 7) ;
    cout<<pop(&stack1) << endl;
    cout<<top(&stack1) << endl ;
    cout<<size(&stack1) << endl;
    traversestack(&stack1 , &log) ;

}
