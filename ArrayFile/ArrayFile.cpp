#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// ---------- SERVICE FUNCTIONS ----------

void inputArray(int* A, int n)
{
    for (int i = 0; i < n; i++)
        cin >> A[i];
}

void printArray(int* A, int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void writeTextFile(int* A, int n, string filename)
{
    ofstream file(filename);

    for (int i = 0; i < n; i++)
        file << A[i] << " ";

    file.close();
}

void writeBinaryFile(int* A, int n, string filename)
{
    ofstream file(filename, ios::binary);

    file.write((char*)A, sizeof(int) * n);

    file.close();
}

void randomArray(int* A, int n)
{
    for (int i = 0; i < n; i++)
        A[i] = rand() % 100;
}

// ---------- TASK 1 ----------

void task1()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int* A = new int[n];
    int* B = new int[n];

    cout << "Enter array A:\n";
    inputArray(A, n);

    cout << "Enter array B:\n";
    inputArray(B, n);

    for (int i = 0; i < n; i++)
        if (A[i] > 0)
            A[i] = B[i];

    cout << "Result array:\n";
    printArray(A, n);

    delete[] A;
    delete[] B;
}

// ---------- TASK 2 ----------

void task2()
{
    int n, T1, T2;

    cout << "Enter n: ";
    cin >> n;

    int* A = new int[n];

    cout << "Enter array:\n";
    inputArray(A, n);

    cout << "Enter T1: ";
    cin >> T1;

    cout << "Enter T2: ";
    cin >> T2;

    int pos = -1;

    for (int i = 0; i < n; i++)
        if (A[i] == T2)
        {
            pos = i;
            break;
        }

    if (pos == -1)
    {
        cout << "T2 not found\n";
        delete[] A;
        return;
    }

    int min = 1000000;
    int index = -1;

    for (int i = pos + 1; i < n; i++)
        if (A[i] > T1 && A[i] < min)
        {
            min = A[i];
            index = i;
        }

    if (index != -1)
        cout << "Element index: " << index << endl;
    else
        cout << "Element not found\n";

    delete[] A;
}

// ---------- TASK 3 ----------

void task3()
{
    int n;

    cout << "Enter n (<=400): ";
    cin >> n;

    int* A = new int[n];

    inputArray(A, n);

    int maxUnique = -1000000;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
            if (A[i] == A[j])
                count++;

        if (count == 1 && A[i] > maxUnique)
            maxUnique = A[i];
    }

    cout << "Max unique number: " << maxUnique << endl;

    delete[] A;
}

// ---------- TASK 4 ----------

void task4()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int* A = new int[n];

    inputArray(A, n);

    writeTextFile(A, n, "array.txt");

    cout << "Array written to file array.txt\n";

    delete[] A;
}

// ---------- TASK 5 ----------

void task5()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int* A = new int[n];

    randomArray(A, n);

    cout << "Generated array:\n";
    printArray(A, n);

    writeBinaryFile(A, n, "array.bin");

    cout << "Array written to binary file\n";

    delete[] A;
}

// ---------- TASK 6 ----------

void task6()
{
    ifstream file("input.txt");

    int n;

    file >> n;

    int* A = new int[n];

    for (int i = 0; i < n; i++)
        file >> A[i];

    file.close();

    int max = A[0];

    for (int i = 1; i < n; i++)
        if (A[i] > max)
            max = A[i];

    ofstream out("result.txt");

    out << max;

    out.close();

    cout << "Max value = " << max << endl;

    delete[] A;
}

// ---------- TASK 7 ----------

void task7()
{
    ifstream file("input.txt");

    vector<int> data;

    int x;

    while (file >> x)
        data.push_back(x);

    file.close();

    cout << "Data from container:\n";

    for (int v : data)
        cout << v << " ";

    cout << endl;
}

// ---------- MENU ----------

void menu()
{
    cout << "\n===== MENU =====\n";
    cout << "1 - Task 1\n";
    cout << "2 - Task 2\n";
    cout << "3 - Task 3\n";
    cout << "4 - Task 4\n";
    cout << "5 - Task 5\n";
    cout << "6 - Task 6\n";
    cout << "7 - Task 7\n";
    cout << "0 - Exit\n";
}

int main()
{
    srand(time(0));

    int choice;

    do
    {
        menu();

        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        }

    } while (choice != 0);

    return 0;
}
