#include <iostream>
using namespace std;

class node
{
public:
    node *down;
    string name;
    node *next;
    
    node()
    {
        down = NULL;
        next = NULL;
        name = "";
    }
};

class book
{
public:
    node *root = NULL;

    void insert_book()
    {
        if (root != NULL)
        {
            cout << "Book already exists!\n";
            return;
        }

        root = new node();
        cout << "Enter the Book Name: ";
        cin >> root->name;
    }

    void insert_chapter()
    {
        if (root == NULL)
        {
            cout << "No book found! Insert a book first.\n";
            return;
        }

        node *new_chapter = new node();
        cout << "Enter Chapter Name: ";
        cin >> new_chapter->name;

        if (root->down == NULL)
        {
            root->down = new_chapter;
        }
        else
        {
            node *temp = root->down;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_chapter;
        }
    }

    void insert_section()
    {
        if (root == NULL || root->down == NULL)
        {
            cout << "No chapters found! Insert a chapter first.\n";
            return;
        }

        node *chapter = root->down;
        while (chapter->next != NULL)
        {
            chapter = chapter->next;
        }

        node *new_section = new node();
        cout << "Enter Section Name: ";
        cin >> new_section->name;

        if (chapter->down == NULL)
        {
            chapter->down = new_section;
        }
        else
        {
            node *temp = chapter->down;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_section;
        }
    }

    void insert_subsection()
    {
        if (root == NULL || root->down == NULL)
        {
            cout << "No chapters found! Insert a chapter first.\n";
            return;
        }

        node *chapter = root->down;
        while (chapter->next != NULL)
        {
            chapter = chapter->next;
        }

        if (chapter->down == NULL)
        {
            cout << "No sections found! Insert a section first.\n";
            return;
        }

        node *section = chapter->down;
        while (section->next != NULL)
        {
            section = section->next;
        }

        node *new_subsection = new node();
        cout << "Enter Subsection Name: ";
        cin >> new_subsection->name;

        if (section->down == NULL)
        {
            section->down = new_subsection;
        }
        else
        {
            node *temp = section->down;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_subsection;
        }
    }

    void display()
    {
        if (root == NULL)
        {
            cout << "No book found!\n";
            return;
        }

        cout << "Book: " << root->name << endl;
        node *chapter = root->down;

        while (chapter != NULL)
        {
            cout << "  Chapter: " << chapter->name << endl;
            node *section = chapter->down;

            while (section != NULL)
            {
                cout << "    Section: " << section->name << endl;
                node *subsection = section->down;

                while (subsection != NULL)
                {
                    cout << "      Subsection: " << subsection->name << endl;
                    subsection = subsection->next;
                }
                section = section->next;
            }
            chapter = chapter->next;
        }
    }
};

int main()
{
    book b;
    int choice;

    while (true)
    {
        cout << "\n1. Insert Book\n2. Insert Chapter\n3. Insert Section\n4. Insert Subsection\n5. Display\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b.insert_book();
            break;
        case 2:
            b.insert_chapter();
            break;
        case 3:
            b.insert_section();
            break;
        case 4:
            b.insert_subsection();
            break;
        case 5:
            b.display();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
