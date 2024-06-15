#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
bool possible(vector<ll> &books, ll cost, ll mid)
{
    ll price = 0;
    for (ll height : books)
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
            // cout<<price<<"\n";
            return false;
        }
    }
    // cout<<price<<"\n";
        return true;
}
ll result(vector<ll> &books, ll cost)
{
    ll low = 0, high = *max_element(books.begin(), books.end());
    while (low < high)
    {
        ll mid = (low + high) / 2;
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
        vector<ll> books(size);
        for (int i = 0; i < size; i++)
        {
            ll height;
            cin >> height;
            books.push_back(height);
        }
        ll maxheight = result(books, cost);
        cout << maxheight << endl;
    }
    return 0;
}
