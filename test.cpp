#include "Tree.h"

void main()
{
	
 Tree<int>t;
 t.insert( 1);
 cout<< t.exists(1) << t.size() <<t<<endl;
 
 Tree<double>d;
 d.insert(1);
 cout<< d.exists(1) << d.size() << d <<endl;


}