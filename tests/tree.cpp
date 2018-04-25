#include <catch.hpp>
#include <sstream>
#include "tree.hpp"



TEST_CASE(" insert and print ")
{
    tree_t<float> tree;
    tree.insert(2.3);
    tree.insert(5.4);
    tree.insert(6.8);
    string wait {
        "------------6.8\n"
        "--------5.4\n"
        "----2.3\n" };
    ostringstream ostream;
    tree.print(ostream);
    REQUIRE(ostream.str()==wait);
}

TEST_CASE(" find in tree ")
{
    tree_t<int> tree;
    tree.insert(3);
    tree.insert(5);
    tree.insert(4);
    REQUIRE(tree.find(5)==true);
    REQUIRE(tree.find(3)==true);
    REQUIRE(tree.find(15)==false);
}

TEST_CASE(" remove elements in tree ")
{
    tree_t<int> tree;
    tree.insert(3);
    tree.insert(5);
    tree.insert(4);
    tree.insert(43);
    REQUIRE(tree.remove(5)==true);
    REQUIRE(tree.find(2)==false);
}


TEST_CASE(" print ")
{
    tree_t<float> tree;
    tree.insert(2.3);
    tree.insert(5.4);
    tree.insert(6.8);
    string wait {
        "------------6.8\n"
        "--------5.4\n"
        "----2.3\n" };
    ostringstream ostream;
    tree.print(ostream);
    REQUIRE(ostream.str()==wait);
    tree.insert(1.2);
    string wait2 {
        "------------6.8\n"
        "--------5.4\n"
        "----2.3\n"
        "--------1.2\n" };
    ostream.str("");
    tree.print(ostream);
    REQUIRE(ostream.str() == wait2);
}

TEST_CASE(" compare trees ")
{
    tree_t<int> tree1;
    tree1.insert(4);
    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(43);
    tree_t<int> tree2 ;
    tree2.insert(4);
    tree2.insert(5);
    tree2.insert(3);
    tree2.insert(43);
    REQUIRE((tree1==tree2)==true);
    tree1.insert(0);
    REQUIRE((tree1==tree2)==false);
}

TEST_CASE(" initializer_list ")
{
    tree_t<int> tree {0,2,4,6,123} ;
    string srav {
        "--------------------123\n"
        "----------------6\n"
        "------------4\n"
        "--------2\n"
        "----0\n"     };
    ostringstream ostream;
    tree.print(ostream);
    REQUIRE(ostream.str()==srav);
}

TEST_CASE("exceptions")
{
    tree_t<double> tree;
    REQUIRE_THROWS (tree.print(cout));
    tree.insert(4);
    tree.insert(5);
    tree.remove(5);
    tree.remove(4);
    REQUIRE_THROWS (tree.remove(4));
}
