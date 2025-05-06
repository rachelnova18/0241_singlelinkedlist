#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};

class linkedlist
{
    Node *START;

public:
    linkedlist()
    {
        START = NULL;
    }

    