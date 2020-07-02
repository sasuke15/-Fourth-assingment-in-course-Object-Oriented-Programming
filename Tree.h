#pragma once
#include "Node.h"

template<typename T>
class Tree
{

template<typename T>
friend ostream& operator<<(ostream& Out,  Tree<T> & C); 

public:

	Tree():root(nullptr),Size(0){};

	~Tree();

	void insert( const T & item );
    
	bool exists( const T & item );
	
	int size();

 private:

 node<T> * root;
 int Size;

 void create( node<T> * & curr , const T & item );
 void move( node<T> * & curr , node<T> * & temp , const T & item , int & condtion );
 bool chek( node<T> * & curr , node<T> * & temp );
 void print( ostream & Out , node<T> * & curr );
 void distruct( node<T> * & curr );

};	

template<typename T>
Tree<T>::~Tree()
{

 distruct(root);

}
template<typename T>
void Tree<T>::distruct(  node<T> * & curr )
{

 if( curr != nullptr )
 {
 
  distruct( curr -> left );
  distruct( curr -> right );

  delete [] curr; 
 
 }

}

template<typename T>
void Tree<T>::insert( const T & item )
{

 if( root == nullptr )
 create( root , item );

 else
 {
 
   node<T> * curr = root;
   int condition = 1;

   while( condition == 1 )
   {
    if( curr -> data < item )
	move( curr , curr -> left , item , condition );
  
	else
    move( curr , curr -> right , item , condition );
   
   }
 
 }

}
template<typename T>
void Tree<T>::create( node<T> * & curr , const T & item )
{

  curr = new node<T>( item );

  Size++;

}
template<typename T>
void Tree<T>::move( node<T> * & curr , node<T> * & temp , const T & item , int & condition )
{
	 if( temp == nullptr )
	 {
	  create( temp , item );
	  condition = 0;
	 }
     
	 else
     curr = temp;
	}


template<typename T>
bool Tree<T>::exists( const T & item )
{

  if( root == nullptr )
  return false;

  node<T> * curr = root;
  
  while ( 1 )
  {
  
   if( curr -> data == item )
   return true;

   if( curr -> data < item )
   {
	if( chek( curr , curr -> left ) == false )
    return false;
   }
   
   else
   {
	if( chek( curr , curr -> right ) == false )
    return false;
   }
  
  }

}
template<typename T>
bool Tree<T>::chek( node<T> * & curr , node<T> * & temp )
{
	if( temp == nullptr )
    return false;
   
    else
    curr = temp;

	return true;
  
}

template<typename T>
int Tree<T>::size()
{

 return Size;

}

template<typename T>
ostream& operator<<(ostream& Out,  Tree<T> & C)
{

  C.print( Out , C.root );
	
  return Out;

}

template<typename T>
void Tree<T>::print( ostream & Out , node<T> * & curr )
{

 if( curr != nullptr )
 {  
 
  print( Out , curr -> right );
  Out << curr -> data <<" ";
  print( Out , curr -> left );
 
 }

}