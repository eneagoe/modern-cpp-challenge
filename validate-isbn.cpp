#include <iostream>

using namespace std;

int main(void)
{
    string isbn;
    int s = 0, i = 10;

    cin >> isbn;

    if(isbn.size() != 10)
        cout << "Invalid" << endl;
    else {
        for(auto &c: isbn) {
            s += (c - '0') * i;
            i--;
        }
        if(s % 11 == 0)
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;

    }

    return 0;
}
