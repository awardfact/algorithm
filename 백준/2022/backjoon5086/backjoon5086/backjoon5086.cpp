

#include <iostream>

using namespace std;
int main()
{
    int n, m;

    do {

        cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }
        if (m % n == 0) {
            cout << "factor" << "\n";
        }
        else if (n % m == 0) {
            cout << "multiple" << "\n";
        }
        else {
            cout << "neither" << "\n";
        }



    } while (n != 0 && m != 0);

    return 0;

    
}

