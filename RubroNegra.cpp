#include <iostream>
#include "RubroNegra.hpp"
using namespace std;

RN* rotateRight(RN* t){

	RN *aux1 = t->LChild;
    RN *aux2 = aux1->RChild;  
	  
    aux1->RChild = t;
    t->LChild = aux2;    
    aux1->color = t->color;
    t->color = 'r';
    aux1->parent = t->parent;
    t->parent = aux1;
    
	return t;
}

RN* rotateLeft(RN* t){
	
	RN *aux1 = t->RChild;
    RN *aux2 = aux1->LChild;   
	 
    aux1->LChild = t;
    t->RChild = aux2;    
    aux1->color = t->color;
    t->color = 'r';
    aux1->parent = t->parent;
    t->parent = aux1;
		
	return t;
}

RN* findUncle(RN* t){

	RN* uncle = NULL;
	if (t->parent != NULL and t->parent->parent != NULL and t->parent->parent->LChild){	
			
		uncle = t->parent->parent->LChild;
					
		if (uncle == t->parent ){
			uncle = t->parent->parent->RChild;
		}	
	}	
	
	return uncle;
}

void rebalance (RN* t){
	
	while (t->parent != NULL){
		RN* uncle = findUncle(t);
		if (uncle != NULL and t->parent != NULL){
			if (uncle->color == 'b' and t->parent->color == 'r' and t->color == 'r' and t->parent->RChild == t){
					
				t = rotateLeft(t->parent);
				uncle = findUncle (t);
	
				if (uncle->color == 'b' and t->color == 'r' and t->parent->color == 'r' and t->parent->LChild == t){
					t->parent->color = 'b';
					t->parent->parent->color = 'r';
					rotateRight(t->parent);				
				}			
			}
			else if (uncle->color == 'b' and t->parent->color == 'r' and t->color == 'r' and t->parent->LChild == t){
					
				t = rotateRight(t->parent);
				uncle = findUncle (t);
	
				if (uncle->color == 'b' and t->color == 'r' and t->parent->color == 'r' and t->parent->RChild == t){
					t->parent->color = 'b';
					t->parent->parent->color = 'r';
					rotateLeft(t->parent);				
				}
			}
		}
		t = t->parent;
	}
	t->color = 'b';
}

void insert (RN** t,RN* parent,data d){
		
	if ((*t) == NULL){
		*t = (RN*) malloc (sizeof(RN));
		(*t)->RChild = NULL;		
		(*t)->LChild = NULL;		
		(*t)->info = d;
		(*t)->color = 'r';
		(*t)->parent = parent;
		
		RN* aux;
		aux = (*t);
		
		if ((*t)->parent != NULL and (*t)->parent->parent != NULL){
			
			if ((*t)->parent->parent->LChild != NULL){
				(*t)->parent->parent->LChild->color = 'b';
			}
			if ((*t)->parent->parent->RChild != NULL){
				(*t)->parent->parent->RChild->color = 'b';
			}

			(*t)->parent->parent->color = 'r';				
		}
		if ((*t)->parent != NULL){
			(*t)->parent->color = 'b';
			 
			if ((*t)->parent->parent != NULL){
				aux =(*t)->parent;
				
				if ((*t)->parent->parent->parent != NULL){
					aux = (*t)->parent->parent;
				}
			}
			
		}		
		rebalance (aux);		
	}			
	else if (d.value < (*t)->info.value){
			
		insert(&(*t)->LChild,*t,d);			
	}
	else if (d.value > (*t)->info.value){
		insert(&(*t)->RChild,*t,d);
	}	

	return;
}

RN* search(RN** t,data d){
	if (*t == NULL){
		return NULL;
	}
	else if ((*t)->info.value == d.value){
		return (*t);
	}	
	else if (d.value < (*t)->info.value){
		search(&(*t)->LChild,d);
	}
	else if (d.value > (*t)->info.value){
		search(&(*t)->RChild,d);
	}
}

void printRN(RN *t){
	if(!(t == NULL)){   
	    printRN(t->LChild); 
	    cout<<"["<<t->info.value<<"] ";
	    printRN(t->RChild); 
  }
}
