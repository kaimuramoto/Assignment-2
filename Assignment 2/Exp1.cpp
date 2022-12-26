// Experiment 1
#include <iostream>
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

    // Tall skinny tree (T1)
    BinarySearchTree <int> T1;
    for (int i = 0; i < 15000; i++)
    {
        T1.insert(i);
    }

    cout << "Start of T1test" << endl;

    // cout << "Keys: range from 0 14999" << endl ;
    // T1.printTree( );

    // cout << "Tree: elements range from 0 to 14999" << endl ;
    // T1.displayTree(); 
    
    start = clock(); // starts the clock
    // Performs 15000 memebership checks on the tree 
    for (int i = 0; i < 15000; i++)
    {
        T1.contains(i);
    }

    finish = clock(); // stops the clock

    double T1time_taken = elapsed_time(start,finish);
    cout << "The total time of contains() function took: " << T1time_taken << "ms" << endl;

    cout << "End of T1test" << endl;


    // Balanced tree (T2)
    BinarySearchTree<int> T2;

    //creates balanced tree
    int NUMS = 15000;
    const int GAP  = 8;
    const int CAP  = 15000;
    int i;
    int key;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        T2.insert( key );
    }

    
    cout << "Start of T2test \n"; 

    start = clock(); // starts the clock
    // Performs 15000 memebership checks on the tree 
    for (int i = 0; i < 15000; i++)
    {
        T2.contains(i);
    }

    finish = clock(); // stops the clock

    double T2time_taken = elapsed_time(start,finish);
    cout << "The total time of contains() function took: " << T2time_taken << "ms" << endl;

    double T1avg_time = (T1time_taken)/i;
    double T2avg_time = (T2time_taken)/i;

    cout << "End of T2test" << endl;

    cout << "The average time taken for T1 is: " << T1avg_time << "ms" << endl;
    cout << "The average time taken for T2 is: " << T2avg_time << "ms" << endl;

    int x = T1.depth(300);
    int z = T2.depth(300);

    cout << "depth of 300 in T1: " << T1.depth(300) << endl;

    cout << "depth of 300 in T2: " << T2.depth(300) << endl;

    double avg_depth = (x + z)/2;
    cout << "Average depth of 300 in T1 + T2 is: " << avg_depth << endl;

}