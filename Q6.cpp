#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int i, j;
    cin >> i >> j;
    if ((i == 1 && j == 2) || (i == 2 && j == 1))
    {
        cout << 1;
    }
    else if (i == 1 || j == 1)
    {
        cout << -1;
    }
    else if ((i + j) % 2 == 0)
    {
        int k = min(i, j) - 2;
        long long result = (k + 1) * 2 + (max(i, j) - k - 2) * 2;
        cout << result;
    }
    else
    {
        int k = min(i, j) - 2;
        long long result = (k + 1) * 2 + (max(i, j) - k - 3) * 2 + 1;
        cout << result;
    }
    return 0;
}
