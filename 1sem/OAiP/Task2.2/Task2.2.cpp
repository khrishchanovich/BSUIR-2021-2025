#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int a[4][4];
    int i, j, S = 0;
    for (i = 0; i <= 4; i++)
    {
        for (j = 0; j <= 4; j++)
        {
            cin >> a[i][j];
            if (i % 2 != 0) { S = S + a[i][j]; }
        }
    }

    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            cout << a[i][j] << " ";
        } cout << endl;
    }
    cout << S << endl;
    return 0;
}