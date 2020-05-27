#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

//������в�������ʹ���Ƕ�ħ��Ӫ�ģ�������ʹ�ض�˵�滰����ħ�ض�˵�ٻ��������������ܴ�һ���ʻ��еõ���ȷ����Ϣ
//ѯ��a:"b�ǲ�����ʹ",����ش���yes����ô��a��bͬΪ��ʹ������a��bͬΪ��ħ�������
//����ش���no����ô��aΪ��ʹbΪ��ħ������aΪ��ħ��bΪ��ʹ�������

//����ֻ��עa��b�Ƿ���ͬһ����Ӫ�Ļ����ᷢ��yes����abͬ��Ӫ��no����ab�ڶ�����Ӫ���ɴ˽������鼯�����Խ������˷�Ϊ��������
//ÿ�������з�Ϊ������Ӫ���������ǲ�֪�����Ƿֱ���������ĸ���Ӫ

//�ɴ��������뱳��dp����������Ӫ����num[i]��˵���͸��ڵ���ͬ��Ӫ����������ʹ�������ڶ�ħ�����൱��01����
//dp[i][j]������ǰi�����ϣ����j����ʹ�м��ַ���
//����͵�ǰ���ϸ��ڵ���ͬ��Ӫ����������ʹ��������ͬ��Ӫ���˵���������ǰ��ʹ�����ϣ�����͵�ǰ���ϸ��ڵ㲻ͬ��Ӫ����������ʹ��Ҳ��Ӧ�Ľ���Щ�����ӵ���ǰ��ʹ������
//��������м��϶���ʹ�ú�dp[][p1]�ķ������Ƿ�Ϊ1������ж��ط������ǲ�ȷ���������ͬ�����no

ll n,p1,p2;

vector<ll>fa;
vector<ll>dis;

void fainit()
{
    for(ll i=0;i<fa.size();i++)
    {
        fa[i]=i;
        dis[i]=0;
    }
}

ll get(ll x)
{
    if(x==fa[x]) return x;
    ll root=get(fa[x]);
    dis[x]^=dis[fa[x]];
    return fa[x]=root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(scanf("%lld%lld%lld",&n,&p1,&p2),n||p1||p2)
    {
        fa.clear();
        dis.clear();
        ll sum=p1+p2;
        fa.resize(sum+1);
        dis.resize(sum+1);
        fainit();
        char s[4];
        ll a,b;
        for(ll i=0;i<n;i++)
        {
            scanf("%lld%lld %s",&a,&b,s);
            ll x=get(a),y=get(b);
            if(x!=y)            //ע����һ��ĺϲ�����...wa�˼����ŷ�������д����
            {
                fa[x]=y;
                dis[x]=dis[a]^dis[b];
                if(s[0]=='n') dis[x]^=1;
            }
        }
        vector<ll>num;
        for(ll i=1;i<=sum;i++)
            if(i==get(i)) num.push_back(i); //ÿһ��num�е�ֵ������һ�����ϵĴ���Ԫ��
        vector<vector<ll> >field(num.size()*2); //�±�+num������ü��ϴ���Ԫ��������Ӫ��ͬ��Ԫ�ظ����������±������ͬ��Ԫ�ظ���
        for(ll i=0;i<num.size();i++)
        {
            for(ll j=1;j<=sum;j++)
            {
                if(get(j)==num[i])
                {
                    if(dis[j]) field[i+num.size()].push_back(j);
                    else field[i].push_back(j);
                }
            }
        }
        vector<vector<ll> >dp(num.size()),root(num.size());     //����dp,root�洢·��
        for(ll i=0;i<num.size();i++)
        {
            dp[i].resize(p1+1,0);
            root[i].resize(p1+1,0);
            for(ll j=0;j<=p1;j++)
            {
                dp[i][j]=0;
                root[i][j]=0;
            }
        }
        if(field[0].size()<=p1)
        {
            dp[0][field[0].size()]+=1;
            root[0][field[0].size()]=1;
        }
        if(field[num.size()].size()<=p1)
        {
            dp[0][field[num.size()].size()]+=1;
            root[0][field[num.size()].size()]=-1;
        }
        for(ll i=1;i<num.size();i++)
        {
            for(ll j=0;j<=p1;j++)
            {
                if(field[i].size()<=j&&dp[i-1][j-(ll)field[i].size()])
                {
                    dp[i][j]+=dp[i-1][j-(ll)field[i].size()];
                    root[i][j]=1;
                }
                if(field[i+num.size()].size()<=j&&dp[i-1][j-(ll)field[i+num.size()].size()])
                {
                    dp[i][j]+=dp[i-1][j-(ll)field[i+num.size()].size()];
                    root[i][j]=-1;
                }
            }
        }
        if(dp[(ll)num.size()-1][p1]!=1) printf("no\n");
        else
        {
            vector<ll>ans;
            ll nowi=(ll)num.size()-1,nowj=p1;
            while(nowi>=0)
            {
                if(root[nowi][nowj]==1)
                {
                    for(ll i=0;i<field[nowi].size();i++) ans.push_back(field[nowi][i]);
                    nowj-=(ll)field[nowi].size();
                }
                else
                {
                    for(ll i=0;i<field[nowi+num.size()].size();i++) ans.push_back(field[nowi+num.size()][i]);
                    nowj-=(ll)field[nowi+num.size()].size();
                }
                nowi--;
            }
            sort(ans.begin(),ans.end());
            for(ll i=0;i<ans.size();i++) printf("%lld\n",ans[i]);
            printf("end\n");
            ans.clear();
        }
        num.clear();
        dp.clear();
        field.clear();
    }
}


