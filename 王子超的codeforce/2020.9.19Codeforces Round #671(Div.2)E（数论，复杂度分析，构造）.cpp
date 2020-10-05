#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=31630;

vector<ll>prime;//线性筛筛出sqrt(1e9)内的所有素数
bool v[maxn];

void primes()
{
    for(ll i=2;i<maxn;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            prime.push_back(i);
        }
        for(ll j=0;prime[j]<maxn/i;j++)
        {
            v[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}


int32_t main()
{
    IOS;
    primes();
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>primes_now;//保存当前的n分解质因数后有几个不同的质因子
        ll temp=n;
        for(ll i=0;i<prime.size()&&prime[i]<=temp/prime[i];i++)
        {
            if(temp%prime[i]==0)
            {
                primes_now.push_back(prime[i]);
                while(temp%prime[i]==0) temp/=prime[i];
            }
        }
        if(temp>1) primes_now.push_back(temp);

        unordered_map<ll,bool>M;//保存n除了1外的因子有哪些，记录它是否被使用过
        for(ll i=2;i<=n/i;i++)
        {
            if(n%i==0)
            {
                M[i]=0;
                M[n/i]=0;
            }
        }
        M[n]=0;


        if(primes_now.size()==2&&primes_now[0]*primes_now[1]==n) cout<<primes_now[0]<<' '<<primes_now[1]<<' '<<n<<endl<<1<<endl;
        //如果n刚好能拆分成两个质因子相乘，就是唯一一种特殊的情况，我们无法构造出0对相邻互质而只能构成1对相邻互质的特殊情况，直接输出三个数字和对数1。
        else
        {
            vector<ll>mid(primes_now.size());//mid[i]当前n分解的质因子，第i个和第i+1个中间插入的数是哪一个
            for(ll i=0;i<primes_now.size();i++)//直接暴力for一遍，质因子数量是很少的
            {
                for(auto &x:M)//去n的所有因数里面找既能整除第i个质因子又能整除第i+1个质因子的数
                {
                    if(!x.second&&x.first%primes_now[i]==0&&x.first&&x.first%primes_now[(i+1)%primes_now.size()]==0)
                    {
                        mid[i]=x.first;
                        x.second=1;
                        break;
                    }
                }
                M[primes_now[i]]=1;
            }

            for(ll i=0;i<primes_now.size();i++)//然后把剩下没使用过的数字继续暴力放到第i个质因子和mid[i]中间，只需要满足整除第i个质因子即可
            {
                cout<<primes_now[i]<<' ';
                for(auto &x:M)
                {
                    if(!x.second&&x.first%primes_now[i]==0)
                    {
                        cout<<x.first<<' ';
                        x.second=1;
                    }
                }
                cout<<mid[i]<<' ';
            }
            cout<<endl<<0<<endl;
        }
    }
}
