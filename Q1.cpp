#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
bool possible(vector<int> &books, ll cost, ll mid)
{
    ll price = 0;
    for (int height : books)
    {
        if (height > mid)
        {
            while (height > mid)
            {
                price += height;
                height--;
            }
        }
        if (price > cost)
        {
            return false;
        }
    }
    return true;
}
int result(vector<int> &books, ll cost)
{
    int low = 0, high = *max_element(books.begin(), books.end());
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (possible(books, cost, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int size;
        ll cost;
        cin >> size;
        cin >> cost;
        vector<int> books(size);
        for (int i = 0; i < size; i++)
        {
            cin >> books[i];
        }
        int maxheight = result(books, cost);
        cout << maxheight << endl;
    }
    return 0;
}
