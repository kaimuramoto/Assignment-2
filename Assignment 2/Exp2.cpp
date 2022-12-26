#include <iostream>
#include "AvlTree.h"
#include "BinarySearchTree.h"
#include <time.h>
using namespace std;

double elapsed_time( clock_t start, clock_t finish)
{ // returns elapsed time in milliseconds 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
}

int main( )
{
    clock_t start, finish ;

    // FIRST TREE BST: Tall skinny tree (T1) 
    BinarySearchTree <int> T1;
    start = clock();

    for (int i = 0; i < 15000; i++)
    {
        T1.insert(i);
    }

    finish = clock(); // stops the clock
    double T1insertion_time_taken = elapsed_time(start,finish);


    start = clock(); // starts the clock
    // Performs 15000 memebership checks on the tree 
    for (int i = 0; i < 15000; i++)
    {
        T1.contains(i);
    }

    finish = clock(); // stops the clock
    double T2time_taken = elapsed_time(start,finish);



    // SECOND TREE AVL: Tall skinny tree (T2) 
    AvlTree <int> T2;
    start = clock();
    // inserts nodes into 
    for (int i = 0; i < 15000; i++)
    {
        T2.insert(i);
    }

    finish = clock ();
    double T2insertion_time_taken = elapsed_time(start,finish);

    
    start = clock(); // starts the clock
    // Performs 15000 memebership checks on the tree 
    for (int i = 0; i < 15000; i++)
    {
        T2.contains(i);
    }

    finish = clock(); // stops the clock

    double T4time_taken = elapsed_time(start,finish);

    // Average time for insertion calculations
    double T1insertion_avg_time = (T1insertion_time_taken)/14999;
    double T2insertion_avg_time = (T2insertion_time_taken)/14999;

    // average depth calculation
    int x = T1.depth(180);
    int y = T2.depth(180);

    //cout << "depth of 180 in T1: " << T1.depth(180) << endl;

    //cout << "depth of 180 in T2: " << T2.depth(180) << endl;

    double avg_depth = (x + y)/2;

   
    cout << "Total insertion time on BST: " << T1insertion_time_taken << "ms" << endl;
    cout << "Total insertion time on AVL tree: " << T2insertion_time_taken << "ms" << endl;
    cout << "Average insertion time for BST: " << T1insertion_avg_time << "ms" << endl;
    cout << "Average insertion time for an AVL tree: " << T2insertion_avg_time << "ms" << endl;
    cout << "The total time of contains() on a BST took: " << T2time_taken << "ms" << endl;
    cout << "The total time of contains() function on an AVL tree took: " << T4time_taken << "ms" << endl;
    cout << "Height of BST: " << T1.height() << endl;
    cout << "Height of AVL tree: " << T2.height() << endl;
    cout << "Average depth of 300 in BST (T1) and AVL tree (T2) is: " << avg_depth << endl;



    return 0;
}