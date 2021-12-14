#include <iostream>
#include "binaria.hpp"
using namespace std;

void insert(binary** t,data d){

	if ((*t) == NULL){

		*t = (binary*) malloc (sizeof(binary));
		(*t)->RChild = NULL;
		(*t)->LChild = NULL;		
		(*t)->info = d;
	}
			
	else if (d.value < (*t)->info.value){			
		insert(&(*t)->LChild,d);	
	}
	else if (d.value > (*t)->info.value){
		insert(&(*t)->RChild,d);
	}		
	return;
}

binary* search(binary** t,data d){
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

void printBinary(binary *t){
  if(!(t == NULL)){   
    printBinary(t->LChild); 
    cout<<"["<<t->info.value<<"] ";
    printBinary(t->RChild); 

  }
}
