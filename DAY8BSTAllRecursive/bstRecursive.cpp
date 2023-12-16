#include <iostream>

class Hprefferences
{
    int a = 0;
    int b = 0;
};

class Node
{
    Hprefferences pref;
    int prefId;
    Node *left;
    Node *right;

    Node(int prefId, Hprefferences pref)
    {
        this->prefId = prefId;
        this->pref = pref;
    }
};

class BinarySearchTree
{
    Node* root = NULL;


};

int main()
{

    return 0;
}