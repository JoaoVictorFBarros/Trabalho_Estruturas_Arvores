#include <iostream>
#include "AVL.hpp"
using namespace std;

int getWeight(avl** t){
	if (*t == NULL){
		return -1;
	}
	else{
		return (*t)->weight;
	}
}

int maxWeight(int a,int b){
	if (a>b){
		return a;
	}
	else{
		return b;
	}
}

void rotateRight(avl** t){
		
	avl *aux1 = (*t)->LChild;
    avl *aux2 = aux1->RChild; 
  
    aux1->RChild = (*t);
    (*t)->LChild = aux2;   
    (*t) = aux1;
	(*t)->weight = maxWeight(getWeight(&(*t)->LChild), getWeight(&(*t)->RChild)) + 1;
	aux1->weight = maxWeight(getWeight(&aux1->LChild), getWeight(&aux1->RChild)) + 1;
}

void rotateLeft(avl** t){
	
	avl *aux1 = (*t)->RChild;
    avl *aux2 = aux1->LChild;    
    aux1->LChild = (*t);
    (*t)->RChild = aux2;    
    (*t) = aux1;
	(*t)->weight = maxWeight(getWeight(&(*t)->LChild), getWeight(&(*t)->RChild)) + 1;
	aux1->weight = maxWeight(getWeight(&aux1->LChild), getWeight(&aux1->RChild)) + 1;		
}

void DoubleRotationRight(avl** t){
	rotateLeft(&(*t)->LChild);
	rotateRight(t);
}

void DoubleRotationLeft(avl** t){
	rotateRight(&(*t)->RChild);
	rotateLeft(t);
}

void rebalance(avl** t){

	int balance, left=0,right=0;
	balance = getWeight(&(*t)->LChild) - getWeight(&(*t)->RChild);
	if((*t)->LChild){					
		left = getWeight(&(*t)->LChild->LChild) - getWeight(&(*t)->LChild->RChild);		
	}
		
	if((*t)->RChild){		
		right = getWeight(&(*t)->RChild->LChild) - getWeight(&(*t)->RChild->RChild);	
	}
	
	if(balance == 2 and left >= 0){		
		rotateRight(t);
	}
		
	if(balance == 2 and left < 0){		
		DoubleRotationRight(t);
	}	

	if(balance == -2 and right <= 0){
		rotateLeft(t);					
	}
		
	if(balance == -2 and right > 0){
		DoubleRotationLeft(t);
	}
	
}

void insert(avl** t,data d){

	if ((*t) == NULL){

		*t = (avl*) malloc (sizeof(avl));
		(*t)->RChild = NULL;
		(*t)->LChild = NULL;		
		(*t)->weight = 0;
		(*t)->info = d;
	}
			
	else if (d.value < (*t)->info.value){
			
		insert(&(*t)->LChild,d);
			
	}
	else if (d.value > (*t)->info.value){
		insert(&(*t)->RChild,d);
	}	
	(*t)->weight = maxWeight(getWeight(&(*t)->LChild),getWeight(&(*t)->RChild)) +1;		

	rebalance(t);
	return;
}

avl* search(avl** t,data d){
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

avl* successor(avl* t){
	
	while (t->LChild != NULL){
		t = t->LChild;
	}
	
	return t;
}

void remove(avl** t,avl** parent,char direction,data d){
		
	if (*t == NULL){
		return;
	}	
	else if ((*t)->info.value == d.value){
		avl* aux;		
		aux = *t;
		
		if ((*t)->LChild == NULL and (*t)->RChild == NULL){
			free(aux);
			*t = NULL;
			if (direction == 'L' and (*parent) != NULL){
				(*parent)->LChild = NULL;
			}
			if (direction == 'R' and (*parent) != NULL){				
				(*parent)->RChild = NULL;
			}
		}
		else if ((*t)->RChild != NULL){	
			*t = successor((*t)->RChild);
			free(aux);
		}
		else{
			*t = (*t)->LChild;
			free(aux);
		}
	}	
	else if (d.value < (*t)->info.value){
		remove(&(*t)->LChild,t,'L',d);
		return;
	}
	else if (d.value > (*t)->info.value){
		remove(&(*t)->RChild,t,'R',d);
		return;
	}	
	if ( parent != NULL and (*parent) != NULL){		
		rebalance(parent);	
	}	
}

void printAvl(avl *t){
  if(!(t == NULL)){   
    printAvl(t->LChild); 
    cout<<"["<<t->info.value<<"] ";
    printAvl(t->RChild); 

  }
}
