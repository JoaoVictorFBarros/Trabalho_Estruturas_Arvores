#ifndef _binary__HPP
#define _binary__HPP
#include "AVL.hpp"

struct binary{
	data info;
	binary* LChild;
	binary* RChild;
};

void insert(binary** t,data d);
binary* search(binary** t,data d);
void printBinary(binary* t);


#endif
