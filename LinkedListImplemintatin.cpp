/// stack with linked list implementation

#include <iostream>

using namespace std;

#define stackelement int
struct element
{
    stackelement item ;
    element *next ;
};
struct stack
{
    element* topelement ;
    int stacksize ;
};
void creatstack (stack* st )
{
    st->topelement = NULL ;
    st->stacksize = 0 ;
}
void push(stack *st, stackelement value)
{
    element* newelement = new element ;
    newelement->item = value ;
    newelement->next = st->topelement ;
    st->topelement = newelement ;
    st->stacksize++ ;
}
stackelement top(stack *st)
{
    return st->topelement->item ;
}
stackelement pop(stack *st)
{
    stackelement poped_value = top(st) ;
    element* pn = st->topelement;
    st->topelement= st->topelement->next;
    delete pn ;
    st->stacksize-- ;
    return poped_value ;
}

bool empty(stack *st)
{
    return (st->topelement == NULL) ;
}
void clear(stack *st)
{
    element* tempelement = st->topelement;
    while(tempelement)
    {
        tempelement = tempelement->next ;
        delete st->topelement ;
        st->topelement = tempelement ;
    }
    st->stacksize = 0 ;
}
int size(stack *st)
{
    return st->stacksize ;
}
void traversestack (stack *st, void(*go)(stackelement))
{
    element* tempelement = st->topelement;
    while(tempelement)
    {
        (*go)(tempelement->item) ;
        tempelement=tempelement->next ;
    }
}
bool full (stack *st)
{
    return 0 ;
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
