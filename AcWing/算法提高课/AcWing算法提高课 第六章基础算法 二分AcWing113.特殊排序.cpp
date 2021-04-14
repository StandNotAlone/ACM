// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

// [[0, 1, 0], [0, 0, 0], [1, 1, 0]]
// 指的是对于3个数的每组compare
// compare（1，1）=0
// compare（1，2）=1
// compare（1，3）=0
// compare（2，1）=0
// compare（2，2）=0
// compare（2，3）=0
// compare（3，1）=1
// compare（3，2）=1
// compare（3，3）=0

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int>ret;
        for(int i=1;i<=N;++i) ret.push_back(i);
        stable_sort(ret.begin(),ret.end(),compare);
        return ret;
    }
};