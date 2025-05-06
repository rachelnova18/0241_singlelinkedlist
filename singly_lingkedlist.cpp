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

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi nohs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *previos = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previos = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previos->next = nodeBaru;
    }
    bool listEmpaty()
    {
        return (START == NULL);
    }
    bool search(int nim, Node **previous, Node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }
    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!search(nim, &previous, &current))
        {
            cout << "\nNoMhs tidak ditemukan\n";
            return false;

            if (current == START)
                START = START->next;
            else
                previous->next = current->next;

            delete current;
            return true;
        }
    }

    void traverse()
    {
        if (listEmpaty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData didalan list adalah: \n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

