#pragma once
#include <iostream>
using namespace std;

template<typename T> class Tree;

template<typename T>
class node
{
public:
 
node( const T & item ):data(item), left( nullptr ) , right( nullptr ) {};

private:

const T data;
node<T> * left;
node<T> * right;

friend class Tree<T>;

};
