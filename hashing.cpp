#include <iostream>
using namespace std;

int size;
int* array1;
int* array2;

void initializeArrays() {
    array1 = new int[size];
    array2 = new int[size];
    for (int i = 0; i < size; i++) {
        array1[i] = -1;
        array2[i] = -1;
    }
}

void display_LinearProbing() 
{
    cout << "Linear Probing Table: ";
    for (int i = 0; i < size; i++) {
        if (array1[i] == -1)
            cout << "_ ";
        else
            cout << array1[i] << " ";
    }
    cout << endl;
}

void display_QuadraticProbing() {
    cout << "Quadratic Probing Table: ";
    for (int i = 0; i < size; i++) {
        if (array2[i] == -1)
            cout << "_ ";
        else
            cout << array2[i] << " ";
    }
    cout << endl;
}

// Insert using Linear Probing
void insert_LinearProbing(int data) {
    int i = 0, count = 1;
    int index = (data + i) % size;

    while (array1[index] != -1 && i < size) {
        i++;
        index = (data + i) % size;
        count++;
    }

    if (i < size) {
        array1[index] = data;
        cout << "Inserted (Linear Probing): " << data << endl;
        display_LinearProbing();
        cout << "Comparisons (Linear): " << count << endl;
    } else {
        cout << "Hash table full (Linear Probing)" << endl;
    }
}

// Insert using Quadratic Probing
void insert_QuadraticProbing(int data) {
    int i = 0, count = 1;
    int index = (data + i * i) % size;

    while (array2[index] != -1 && i < size) {
        i++;
        index = (data + i * i) % size;
        count++;
    }

    if (i < size) {
        array2[index] = data;
        cout << "Inserted (Quadratic Probing): " << data << endl;
        display_QuadraticProbing();
        cout << "Comparisons (Quadratic): " << count << endl;
    } else {
        cout << "Hash table full (Quadratic Probing)" << endl;
    }
}

// Search using Linear Probing
void search_Linear(int data) {
    int i = 0, count = 1;
    int index;

    while (i < size) {
        index = (data + i) % size;

        if (array1[index] == data) {
            cout << "Found (Linear): " << data << " at index " << index << endl;
            cout << "Comparisons (Linear): " << count << endl;
            return;
        } else if (array1[index] == -1) {
            break;
        }

        i++;
        count++;
    }

    cout << "Not Found (Linear): " << data << endl;
    cout << "Comparisons (Linear): " << count << endl;
}

// Search using Quadratic Probing
void search_Quadratic(int data) {
    int i = 0, count = 1;
    int index;

    while (i < size) {
        index = (data + i * i) % size;

        if (array2[index] == data) {
            cout << "Found (Quadratic): " << data << " at index " << index << endl;
            cout << "Comparisons (Quadratic): " << count << endl;
            return;
        } else if (array2[index] == -1) {
            break;
        }

        i++;
        count++;
    }

    cout << "Not Found (Quadratic): " << data << endl;
    cout << "Comparisons (Quadratic): " << count << endl;
}

int main() {
    cout << "Enter size of hash table: ";
    cin >> size;

    initializeArrays();

    while (true) {
        int choice;
        cout << "\n1. Insert\n2. Search\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int data;
            cout << "Enter telephone number to insert: ";
            cin >> data;
            insert_LinearProbing(data);
            insert_QuadraticProbing(data);
        } else if (choice == 2) {
            int data;
            cout << "Enter telephone number to search: ";
            cin >> data;
            search_Linear(data);
            search_Quadratic(data);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    delete[] array1;
    delete[] array2;
    return 0;
}
