#include <stdio.h> 
#include <stdlib.h> 
//print_all(head)と入力すると表示されます。 
 void print_all(struct Cell* c){ 
if(c->next == NULL){ 
 printf("[%d]\n",c->value);
 return; 
}
else { 
 printf("[%d]->",c->value);
 print_all(c->next);  
 } 
}
