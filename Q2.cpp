// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits.h>
using namespace std;
int shortestSubarray(vector<int>& nums, int k) {
    int n=nums.size();
    deque<pair<int,int>> dq;
    long long sum = 0;
    long long mini = INT_MAX;
    
    for(long long i=0;i<n;++i){
        sum += nums[i];
        if(sum>=k)  mini = min(mini,i+1);
        pair<long long,long long> curr = {INT_MIN,INT_MIN};
        while(!dq.empty() and (sum-dq.front().second >= k)){
            curr = dq.front();
            dq.pop_front();
        }
        if(curr.second!=INT_MIN){
            mini = min(mini,(i-curr.first));
        }
        while(!dq.empty() and sum<=dq.back().second)
            dq.pop_back();
        dq.push_back({i,sum});
    }
    return mini==INT_MAX?-1:mini;
}
int main() {
    int n, K;
    cin >> n;
    cin >> K;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    int result = shortestSubarray(A, K);
    cout << result;
    return 0;
}