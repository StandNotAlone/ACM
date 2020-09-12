#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e4+7;

int num[maxn];
int n;

int32_t main()
{
    IOS;
    cin>>n;
    int tar=1;//tar指示当前扫过部分的最大值的下标，for循环时该位置的值是不确定的
    for(int i=2;i<=n;i++)
    {
        int x,y;
        cout<<"? "<<tar<<' '<<i<<endl;cout.flush();
        cin>>x;
        cout<<"? "<<i<<' '<<tar<<endl;cout.flush();
        cin>>y;
        if(x>y)//代表x是num[tar]和num[i]中较小的那个，并且x=num[tar]
        {
            num[tar]=x;//确定下标tar的值为x
            tar=i;//更新不确定的最大值位置下标为i
        }
        else num[i]=y;//num[tar]>num[i]时，不需要更新tar，直接确定下标i的值为y
    }
    num[tar]=n;//for结束后还剩下最后一个tar位置'不确定'，但是他是这n排列中最大的，自然只能是n了
    cout<<"! ";
    for(int i=1;i<=n;i++)
    {
        if(i>1) cout<<' ';
        cout<<num[i];
    }
    cout<<endl;
}
