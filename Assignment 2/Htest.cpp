// Test our height function
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main( )
{
    BinarySearchTree <int> t;
    //int NUMS = 400000;
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    cout << "Start of BSTtest" << endl;
    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    }

    if( NUMS < 40 ){
        cout << "Keys:" << endl ;
        t.printTree();
        cout << "Tree:" << endl ;
        t.displayTree();
        cout << "Height: " << 
        t.height() << endl;
    }


    // Creating a tree
    for (int i = 0; i < 12; i++)
    {
        t.insert(i);
    }
    cout << "Keys:" << endl ;
    t.printTree();
    cout << "Tree:" << endl ;
    t.displayTree();
    cout << "Height: " <<
    t.height() << endl;


    // removing all the elements from the tree to test if isempty() and height is 0
    for (int i = 0; i < 19; i++)
    {
        t.remove(i);
    }
    // test if empty tree will give us 0 for height
    cout << "Keys:" << endl ;
    t.printTree();
    cout << "Tree:" << endl ;
    t.displayTree();
    cout << "Height: " <<
    t.height() << endl;

    cout << "\nEnd of BSTtest" << endl;

    return 0;
}
