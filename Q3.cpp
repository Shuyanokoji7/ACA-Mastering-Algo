#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if we can achieve the max_height with given cost K
bool canAchieveHeight(const vector<int> &heights, long long max_height, long long K)
{
    long long total_cost = 0;
    for (int height : heights)
    {
        if (height > max_height)
        {
            total_cost += height - max_height;
            if (total_cost > K)
            {
                return false;
            }
        }
    }
    return total_cost <= K;
}

// Function to find the minimum possible maximum height of the bookshelves
int minMaxHeight(int N, long long K, const vector<int> &heights)
{
    int low = 0;
    int high = *max_element(heights.begin(), heights.end());

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (canAchieveHeight(heights, mid, K))
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
    int T;
    cin >> T;
    vector<int> results;

    for (int t = 0; t < T; ++t)
    {
        int N;
        long long K;
        cin >> N >> K;
        vector<int> heights(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> heights[i];
        }
        results.push_back(minMaxHeight(N, K, heights));
    }

    for (int result : results)
    {
        cout << result << endl;
    }

    return 0;
}
