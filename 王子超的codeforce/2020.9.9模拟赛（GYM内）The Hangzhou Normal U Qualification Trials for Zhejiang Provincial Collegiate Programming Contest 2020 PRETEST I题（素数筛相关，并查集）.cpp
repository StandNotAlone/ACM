#include<cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>
#define ll long long
using namespace std;
int const INF = 0x3f3f3f3f;
int const maxn = 1e5 + 10;
int const maxm = 3e5 + 10;
int const mod = 1e5 + 3;
int n, m;
int pre[maxn];
int vis[maxn];
int find(int x) {
    if (pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}
int primes[maxn], cnt;     
bool st[maxn];  

int p;
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) { 
            primes[cnt++] = i; 
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
int main() {
    int a, b;
    cin >> a >> b >> p;
    get_primes(b);
    for (int i = a; i <= b; i++) {
        pre[i] = i;
    }
    for (int i = 0; i < cnt && primes[i] <= b; i++) {
        if (primes[i] < p) continue;
        int val = primes[i];
        int flag = 0;
        int tmp;
        for (int j = 1; j <= b / val; j++) {
            if (j*val < a) continue;
            if (!flag) {
                tmp = j*val;
                flag = 1;
            }
            else {
                if (find(j*val) != find(tmp)) {
                    pre[find(j*val)] = find(tmp);
                }
            }
        }
    }
    unordered_map<int, int> mp;
    for (int i = a; i <= b; i++) {
        mp[find(i)]++;
    }
    printf("%d\n", mp.size());
    return 0;
}