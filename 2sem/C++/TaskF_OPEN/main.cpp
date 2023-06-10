#include <iostream>
using namespace std;

int main()
{
    int t, count = 0;
    unsigned long long n, buf, temp;

    cin >> t;

    while (t != 0)
    {
        cin >> n;

        for (int i = 0; i <= n; ++i)
        {
            temp = i;
            buf = temp % 10;
            temp /= 10;

            if (buf == 0 || buf == 1 || buf == 2 || buf == 3 || buf == 5 || buf == 8)
            {
                ++count;
            }

            cout << n - counte;
        }
    }
}
