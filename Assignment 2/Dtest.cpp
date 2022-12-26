// Test our depth function
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

// Test program
int main( )
{
    BinarySearchTree<int> t;
    //  int NUMS = 400000;
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    cout << "Start of Dtest" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    }

    if( NUMS < 40 ){
        cout << "Keys:" << endl ;
        t.printTree( );
        cout << "Tree:" << endl ;
        t.displayTree(); 
        cout << "Depth of 17 is: " << t.depth(17) << endl;
        cout << "Depth of 2 is: " << t.depth(2) << endl;
        cout << "Depth of 12 is: " << t.depth(12) << endl;
        cout << "Depth of 18 is: " << t.depth(18) << endl;
        cout << "Depth of 20 is: " << t.depth(20) << endl;
    }

    // Creating a new tree
    for (int i = 0; i < 10; i++)
    {
        t.insert(i);
    }
    cout << "Keys:" << endl ;
    t.printTree();
    cout << "Tree:" << endl ;
    t.displayTree();
    cout << "Depth of 2 is: " << t.depth(2) << endl;


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
    cout << "Depth: " <<
    t.depth(12) << endl;

/*
    for( i = 1; i < NUMS; i+= 2 )
        t.remove( i );

    if( NUMS < 40 ) t.printTree( );

    BinarySearchTree<int> t2;
    t2 = t;
*/
    cout << "\nEnd of test" << endl;

    return 0;
}
