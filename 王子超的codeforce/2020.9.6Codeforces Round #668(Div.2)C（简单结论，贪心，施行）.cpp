#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=3e5+7;

char firt[maxn];//firt[x]记录字符串s的下标i中，所有满足i%k=x的i，对应的字符是否相同，初始为'?'
//上述条件的所有字符相同，是字符串s的所有长度为k的子串中，0和1出现次数相同的充要条件
//这个条件是题目限定的所有长度为k子串中，0出现的次数均等于1出现的次数这个条件的弱化版本，为前置条件
int n,k;
string s;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>s;
        for(int i=0;i<k;i++) firt[i]='?';
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            if(firt[i%k]=='?') firt[i%k]=s[i];//如果当前firt[i]仍然为'?"代表没有出现固定的0或者1
            else if(s[i]!='?'&&firt[i%k]!=s[i]) flag=0;
            //如果firt[i%k]已经是0或者1了，而s[i]不为'?'且不与firt[i%k]相同的话则出现冲突，直接flag置零
        }
        int sum0=0,sum1=0;
        for(int i=0;i<k;i++)//再检测，每段长度为k的子串中，目前已经确定必须有的0和1各自有多少个
        {
            if(firt[i]=='0') sum0++;
            if(firt[i]=='1') sum1++;
        }
        if(sum0>k/2||sum1>k/2) flag=0;//如果0或者1出现的个数超过了长度k的一半，同样是不满足条件的
        //此处与firt数组实现的条件一同，构成了题目要求的条件
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
