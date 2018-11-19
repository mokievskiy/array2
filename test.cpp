#include "block.hpp"
#include <iostream>

using namespace std;

int arr[] = {-5, -1, 0, 1};
size_t n = sizeof (arr) / sizeof(int);

void test1() {
    cout << "Test #1: Creating List of Blocks by array \n";

    List <int> S(arr, n);

    int *b;
    b = new int[n];
    for (size_t i = 0; i < n; i++) {
        b[i] = S[i];
    }

    int ch = 0;
    for (size_t i = 0; i < n; i++) {
        if (b[i] != arr[i]) {
            throw -2;
            ch = 1;
            cout << "Not correct\n";
            break;
        }
    }
    if (ch != 1)
        cout <<"Test correct\n";

    delete[] b;
    return;
}

void test2() {
    cout << "Test #2: Creating with cope constructor \n";

    List <int> S(arr, n);
    List <int> R (S);

    int *b;
    b = new int[n];
    for (size_t i = 0; i < n; i++) {
        b[i] = R[i];
    }

    int ch = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] != b[i]) {
            throw -2;
            ch = 1;
            cout << "Not correct\n";
            break;
        }
    }
    if (ch != 1)
        cout <<"Test correct\n";

    delete[] b;
    return;
}

