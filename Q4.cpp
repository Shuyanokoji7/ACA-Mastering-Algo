#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rupees;

int max_oreo(vector<int> &cost, vector<int> &num, int index, int price, int size, int oreo_num)
{
    if (index == size)
    {
        return oreo_num;
    }
    int k1 = 0, k2 = 0;
    if (price + cost[index] <= rupees)
    {
        k1 = max_oreo(cost, num, index + 1, price + cost[index], size, oreo_num + num[index]);
    }
    k2 = max_oreo(cost, num, index + 1, price, size, oreo_num);
    return max(k2, k1);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int size;
        cin >> size >> rupees;
        vector<int> cost(size), num(size);

        for (int i = 0; i < size; ++i)
        {
            cin >> cost[i] >> num[i];
        }

        int result = max_oreo(cost, num, 0, 0, size, 0);
        cout << result << endl;
    }

    return 0;
}
