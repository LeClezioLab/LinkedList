#include <stdio.h> 
#include <stdlib.h> 
 
struct Cell { 
  struct Cell *next; 
  int value; 
} ; 
 
struct Cell* head; 
 
struct Cell* new_Cell(int val); 
void append(struct Cell* c, int val); 
void free_all(struct Cell* c);; 
 
void fatal_error(){ 
  printf("fatal error");  
  free_all(head); 
 } 
 
 struct Cell* new_Cell(int val) 
  { 
   struct Cell* c; 
   c = (struct Cell*)malloc(sizeof(struct Cell)); 
   if(c == NULL) 
   { 
     fatal_error(); 
        } 
 
 c->value = val; 
 return c; 
 } 
 
void append(struct Cell* c, int val) 
 { 
  
 while(c->next != NULL){ 
  c = c->next; 
  } 
  c->next = new_Cell(val); 
  c->next ->next = NULL; 
 
} 
 
void free_all(struct Cell* c){ 
if(c->next == NULL){ 
 return; 
}
else { 
 free_all(c->next); 
 free(c); 
 } 
} 
 
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

int main()  
{  
head = (struct Cell*)malloc(sizeof(struct Cell)); 
head->next = NULL; 
head->value = 3; 
append(head,5); 
print_all(head);
free_all(head); 
return 0;  
} 
