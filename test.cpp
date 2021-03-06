#include "block.hpp"
#include <iostream>

using namespace std;

int arr[] = {5, -1, 0, 1};
double a[] = {5, -1, 0, 1};
double b[] = {2, 3, 1, 0};
int arrs[] = {-1, 0, 1, 5};
size_t n = sizeof (arr) / sizeof(int);
Array A(a, 4);
Array B(b, 4);

Array Arr[] = {A, B};

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
    List <int> R(S);
    
    int *b;
    b = new int[n];
    for (size_t i = 0; i < n; i++) {
        b[i] = R[i];
    }

    int ch = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] != b[i]) {
            throw 2;
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
    cout << "Test #3: Testing += and pop_back operators\n";
    
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
    R += 3;
    
    
    int ch = 0;
    for (size_t i = 0; i < n - 1; i++) {
        if (S[i] != b[i] || S.length() != n - 1) {
            ch = 1;
            cout << "Not correct\n";
            break;
        }
    }
    for (size_t i = 0; i < n + 1; i++) {
        if (R[i] != a[i] || R.length() != n + 1) {
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
    cout << "Test #4: Testing print\n";
    
    List<int> S(arr,n);
    
    cout << S << "\n";
    
    return;
}

void test5() {
    cout << "Test #5: Testing length function\n";
    
    List<int> S(arr, n);
    size_t k;
    k = S.length();
    
    int ch = 0;
    if (k != n) {
        ch = 1;
        cout << "Test incorrect\n";
    }
    if (ch != 1) 
        cout << "Test correct\n";
    
    return;
}

void test6() {
    cout << "Test #6: Testing operator +\n";

    List<int> S(arr, n);
    List<int> R(arr, n);

    R+S;

    int ch = 0;

    for (size_t i = 0; i < n; i++) {
        if (R[i + n] != arr[i]) {
            ch = 1;
            cout << "Not correct\n";
            break;
        }
    }
    if (ch != 1)
        cout <<"Test correct\n";

    return;
}

void test7() {
    cout << "Test #7: Testing [] operator\n";
    
    List<int> S(arr,n);
    
    int ch = 0;
    for (size_t i = 0; i < n; i++) {
        if (S[i] != arr[i]) {
            ch = 1;
            cout << "Not correct\n";
            break;
        }
    }
    if (ch != 1)
        cout <<"Test correct\n";

    return;
}

void test8() {
    cout << "Test #8: Testing sorting\n";
    
    List<int> S(arr, n);
    S.sorti();
    
    int ch = 0;
    for (size_t i = 0; i < n; i++) {
        if (S[i] != arrs[i]) {
            ch = 1;
            cout << "Not correct\n";
            cout << S;
            break;
        }
    }
    if (ch != 1)
        cout <<"Test correct\n";
   
    return;
}

void test9() {
    cout << "Test #9: Testing List of Blocks by Array with previous working class - array of Doubles\n";
    
    List<Array> S(Arr, 2);
    
    int ch = 0;
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 4; j++) {
            if (S[i][j] != Arr[i][j]) {
            ch = 1;
            cout << "Not correct\n";
            break;
        }
        }
    }
    
    if (ch != 1)
        cout << "Test correct\n";
    
    return;
}
