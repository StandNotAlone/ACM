#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

template<class T>
struct Deque//支持O(1)翻转操作的deque
{
    T data[maxn*2];
    int head=maxn,tail=maxn-1;
    bool f=0;//翻转次数奇偶性标记
    bool empty(){return tail<head;}
    int size(){return tail-head+1;}
    T front(){return f?data[tail]:data[head];}
    T back(){return f?data[head]:data[tail];}
    void push_front(T x){f?data[++tail]=x:data[--head]=x;}
    void push_back(T x){f?data[--head]=x:data[++tail]=x;}
    void pop_back(){f?head++:tail--;}
    void pop_front(){f?tail--:head++;}
    void reverse(){f^=1;}//翻转
};

int n;
int num[maxn];
int k=-1;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    for(int i=n;i>0;i--)
        if(num[i]!=i){k=i-num[i]+1;break;}
    if(k==-1) printf("yes\n1\n");
    else
    {
        Deque<int>Q;
        for(int i=1;i<k;i++) Q.push_back(num[i]);
        bool flag=1;
        for(int i=1;i+k<n;i++)
        {
            Q.push_back(num[i+k-1]);
            if(Q.front()!=i)
            {
                if(Q.back()==i) Q.reverse();
                else {flag=0;break;}
            }
            Q.pop_front();
        }
        if(flag) printf("yes\n%d\n",k);
        else printf("no\n");
    }
}
