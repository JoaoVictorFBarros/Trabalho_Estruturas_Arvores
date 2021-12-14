#ifndef _AVL__HPP
#define _AVL__HPP


struct data{
	double value;
};

struct avl{	
	avl *LChild;
	avl *RChild;
	data info;
	int weight=0;
};

int maxWeight(int a,int b);
void rotateRight(avl** t);
void rotateLeft(avl** t);
void DoubleRotationRight(avl** t);
void DoubleRotationLeft(avl** t);
void rebalance(avl** t);
void insert(avl** t,data d);
avl* search(avl** t,data d);
avl* successor(avl* t);
void remove(avl** t,avl** parent,char direction,data d);
void printAvl(avl *t);

#endif
