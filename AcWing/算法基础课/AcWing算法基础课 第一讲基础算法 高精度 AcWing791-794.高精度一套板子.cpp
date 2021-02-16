#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void read_big(vector<int>&A)//-123在vector中储存是1321
{
    A.clear();
    char s[100000];
    scanf("%s",s);
    if(s[0]=='-') A.push_back(1);//A[0]=0表示A是正数，A[0]=1表示A是负数
    else A.push_back(0);
    for(int i=(int)strlen(s)-1;i>0;i--) A.push_back(s[i]-'0');
    if(A[0]==0) A.push_back(s[0]-'0');
    if(A.size()==2&&A[1]==0) A[0]=0;//-0变成+0
}

void out_big(vector<int>&A)//输出函数
{
    if(A[0]) printf("-");
    for(int i=(int)A.size()-1;i>0;i--) printf("%d",A[i]);
    printf("\n");
}

vector<int> add_big(vector<int>&A,vector<int> &B)
{
    vector<int>C;
    if(A[0]==B[0])//加法
    {
        C.push_back(A[0]);
        int rest=0;
        for(int i=1;i<A.size()||i<B.size();i++)
        {
            if(i<A.size()) rest+=A[i];
            if(i<B.size()) rest+=B[i];
            C.push_back(rest%10);
            rest/=10;
        }
        if(rest) C.push_back(1);
    }
    else//减法，如果只需要进行非负整数间的加法就不要写这个部分
    {
        int f;
        if(A.size()>B.size()) f=1;
        else if(A.size()<B.size()) f=-1;
        else
        {
            f=0;
            for(int i=(int)A.size()-1;i>0;i--)
            {
                if(A[i]>B[i]) {f=1;break;}
                else if(A[i]<B[i]) {f=-1;break;}
            }
        }
        if(f==0) C.push_back(0),C.push_back(0);
        else
        {
            vector<int>D;
            if(f==1) C=A,D=B;
            else C=B,D=A;
            for(int i=1;i<C.size();i++)
            {
                if(i<D.size()) C[i]-=D[i];
                if(C[i]<0) C[i]+=10,C[i+1]--;
            }
            while(C.size()>2&&C[(int)C.size()-1]==0) C.pop_back();
        }
    }
    if(C.size()==2&&C[1]==0) C[0]=0;
    return C;
}

vector<int> sub_big(vector<int>&A,vector<int>&B)//减法本质写在了加法函数里
{
    B[0]=!B[0];
    return add_big(A,B);
}

vector<int> mul_big(vector<int>&A,vector<int>&B)
{
    vector<int>C;
    C.resize((int)A.size()+(int)B.size()-1,0);
    if(A[0]!=B[0]) C[0]=1;
    for(int i=1;i<A.size();i++)
    {
        int rest=0;
        for(int j=1;j<B.size();j++)
        {
            C[i+j-1]+=A[i]*B[j]+rest;
            rest=C[i+j-1]/10;
            C[i+j-1]%=10;
        }
        C[i+(int)B.size()-1]=rest;
    }
    while(C.size()>2&&C[(int)C.size()-1]==0) C.pop_back();
    if(C.size()==2&&C[1]==0) C[0]=0;
    return C;
}

void div_big(vector<int>&A,ll &B,vector<int>&C,ll &D)//计算A%B=C余D
{
    if(!B) exit(-1);
    C.clear();
    C.resize(A.size(),0);
    D=0;
    if(A[0]&&B>0||A[0]==0&&B<0) C[0]=1;
    B=abs(B);
    for(int i=(int)A.size()-1;i>0;i--)
    {
        C[i]=(D*10+A[i])/B;
        D=(D*10+A[i])%B;
    }
    while(C.size()>2&&C[(int)C.size()-1]==0) C.pop_back();
    if(C.size()==2&&C[1]==0) C[0]=0;
    if(A[0]==1) D=-D;
}

int32_t main()
{
    IOS;
    vector<int>A;
    ll B;
    read_big(A);
    scanf("%lld",&B);
    vector<int>C;
    ll D;
    div_big(A,B,C,D);
    out_big(C);
    printf("%lld\n",D);
}
