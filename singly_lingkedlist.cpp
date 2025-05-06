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

int main()
{
    linkedlist mhs;
    int nim;
    char ch;
    while (1)
    {
        cout << endl
             << "Menu";
        cout << endl
             << "1. Menambahkan data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << endl
             << "Masukan pilihan (1-5): ";
        cin >> ch;
        switch (ch)
        {
            case '1':
            {
                mhs.addNode();
            }
            break;
    
            case '2':
            {
                if (mhs.listEmpaty())
                {
                    cout << endl
                         << "List Kosong" << endl;
                    break;
                }
                cout << endl
                     << "\nMasukan no mahasiswa yang akan di hapus: ";
                cin >> nim;
                if (mhs.delNode(nim) == false)
                    cout << endl
                         << "Data tidak ditemukan" << endl;
                else
                    cout << endl
                         << "Data dengan nomor mahasiswa " << nim << " berhasil dihapus" << endl;
            }
            break;
            case '3':
            {
                mhs.traverse();
            }
            break;
            case '4':
            {
                if (mhs.listEmpaty() == true)
                {
                    cout << "\nList kosong\n";
                    break;
                }
                Node *previous, *current;
                cout << endl
                     << "Masukan no mahasiswa yang dicari : ";
                cin >> nim;
                if (mhs.search(nim, &previous, &current) == false)
                    cout << endl
                         << "Data tidak ditemukan" << endl;
                else
                {
                    cout << endl
                         << "Data ditemukan" << endl;
                    cout << "\nNo Mahasiswa : " << current->noMhs << endl;
                    cout << "\n";
                }
            }
            break;
            case '5':
            {
                exit(0);
            }
            break;
            