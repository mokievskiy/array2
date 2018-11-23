#include "block.hpp" 
#include "test.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;

typedef void (*fun) ();

int main (int argc, char* argv[]) {
    
    try {
        fun F[] = {test1, test2, test3, test4, test4
                   , test5, test6, test7, test8};
        
        if (argc != 2) 
            throw 4;
        int T = atoi(argv[1]);
        F[T]();
    }
    catch (const int xpt) {
            switch (xpt)
            {
                case 1:
                    cout << "Out of range\n";
                    break;
                case 2:
                    cout << "Memory allocation error\n";
                    break;
                case 3:
                    cout << "Wrong input\n";
                    break;
            }
            system("pause");
            return -1;
        }

    return 0;
}
