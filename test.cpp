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

void test3() {
    cout << "Test #3: Testing pop_back and push_back operators\n";
    
    List<int> S(arr, n);
    List<int> R(arr, n);
    
    int *b, *a;
    b = new int[n - 1];
    a = new int[n + 1];
    
    for (size_t i = 0; i < n - 1; i++) {
        b[i] = S[i];
    }
    S.pop_back();
    
    for (size_t i = 0; i < n; i++) {
        a[i] = S[i];   
    }
    a[n] = 3;
    R.push_back(3);
    
    
    int ch = 0;
    for (size_t i = 0; i < n - 1; i++) {
        if (S[i] != b[i] || S.lenght() != n - 1) {
            throw -2;
            ch = 1;
            cout << "Not correct\n";
            break;
        }
    }
    for (size_t i = 0; i < n + 1; i++) {
        if (R[i] != a[i] || R.lenght() != n + 1) {
            throw -2;
            ch = 1;
            cout << "Not correct\n";
            break;
        }
    }
    if (ch != 1)
        cout <<"Test correct\n";
    
    delete[] a;
    delete[] b;
    return;
}

void test4() {
    cout << "Test #4: Testing 
}
