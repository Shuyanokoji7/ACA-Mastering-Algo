#include <iostream>
#include <cmath>
#define MAX 998244353
using namespace std;

int func(int n, int r)
{
    int sum = 0;
    if (n <= r)
    {
        return ((int)(pow(2, n - 1))) % MAX;
    }
    else
    {
        for (int i = 1; i <= r; i++)
        {
            sum += func(n - i, r);
            sum %= MAX;
        }
    }
    return sum;
}

int main()
{
    int num;
    cin >> num;
    while (num--)
    {
        int n, r;
        cin >> n >> r;
        cout << func(n, r) << endl;
    }
    return 0;
}
