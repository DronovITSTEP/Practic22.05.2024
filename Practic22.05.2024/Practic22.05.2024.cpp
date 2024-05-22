#include <iostream>
#include "List.h"


using namespace std;

int main()
{
    int id;
    string name;
    List list;
    List::node* ptr, *temp;

    ptr = list.initNode("node1", 1);
    list.addNode(ptr);
    ptr = list.initNode("node2", 2);
    list.addNode(ptr);
    ptr = list.initNode("node3", 3);
    list.addNode(ptr);
    ptr = list.initNode("node4", 4);
    list.addNode(ptr);
    temp = ptr;
    ptr = list.initNode("node5", 5);
    list.addNode(ptr);
    ptr = list.initNode("node6", 6);
    list.addNode(ptr);

    /*list.displayList();
    cout << endl;
    list.displayList(temp);
    cout << endl;
    list.displayNode(temp);*/

    /*name = "node3";
    ptr = list.searchName(name);
    if (ptr != nullptr) {
        list.displayNode(ptr);
        list.deleteNode(ptr);
        list.displayList();
    }*/

    /*list.reverse();
    list.displayList();*/

    /*ptr = new List::node{ 31, "node31" };
    list.insertNode(ptr, 3);
        list.displayList();*/

    /*ptr = list.searchId(4);
    list.deleteListBegin(ptr);
    list.displayList();*/

}
