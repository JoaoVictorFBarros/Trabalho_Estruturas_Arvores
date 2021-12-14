#ifndef _RN__HPP
#define _RN__HPP
#include "AVL.hpp"

struct RN{
	data info;
	RN* LChild;
	RN* RChild;
	RN* parent;
	char color;
};
RN* rotateRight(RN* t);
RN* rotateLeft(RN* t);
void rebalance (RN* t);
void insert (RN** t,RN* parent,data d);
RN* search(RN** t,data d);
void printRN(RN *t);

#endif
