#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int digitSum(const string& s) {
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

int countresult(vector<string>& strings) {
    unordered_map<int, unordered_map<int, int>> hashTable;
    for (unsigned i = 0; i < strings.size(); ++i) {
        if(strings[i].size()<=50){
            hashTable[strings[i].size()][digitSum(strings[i])]++;
        }
    }
    int result = 0;
    
    for (unsigned int i = 0; i < strings.size(); ++i) {
        int len = strings[i].size();
        int sum = digitSum(strings[i]);
        int len2 = 12 - strings[i].size();
        int sum2 = 50 - digitSum(strings[i]);
        
        if (hashTable.count(len2) && hashTable[len2].count(sum2)) {
            result += hashTable[len2][sum2];
            if (len == len2 && sum == sum2) {
                result--;
            }
        }
    }
    return result;
}
int main() {
    int n;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }
    cout << countresult(strings) << endl;
    
    return 0;
}
