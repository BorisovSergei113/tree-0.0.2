#include <iostream>
#include "tree.hpp"


int main()
{
    tree_t <int> tree {1 ,2 ,3 , 4, 5};
    tree_t <int> tree2;
    tree2.insert(1);
    tree2.insert(2);
    tree2.insert(3);
    tree2.insert(4);
    tree2.insert(5);
    if (tree2 == tree ) {
        cout<<"yes"<<endl;
    }
    //int number;
    //cin >> number;
    //tree.insert(number);
    tree.print(cout);
    cout<<endl;
    tree2.print(cout);
    //tree.remove(number);
    //tree.print(cout);
    return 0;
}
