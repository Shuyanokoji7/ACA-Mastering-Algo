#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    priority_queue<int> maxheap;   
    priority_queue<int, vector<int>, greater<int>> minheap;
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        minheap.push(x);
        maxheap.push(x);
        sum+=x;
    }
    for(int i=0;i<m;i++)
    {
        int op;
        long long int sum2=sum;
        cin>>op;
        priority_queue<int, vector<int>, greater<int>> minheapdummy=minheap;
        priority_queue<int> maxheapdummy=maxheap;
        for(int i=0;i<op;i++){
            int min = minheapdummy.top();
            int max = maxheapdummy.top();
            minheapdummy.pop();
            maxheapdummy.pop();
            minheapdummy.push(max-min);
            maxheap.push(max-min);
            sum2-=2*min;
        }
        cout<<sum2<<" ";
    }
    return 0;
}