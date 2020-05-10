#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long

#define local
#ifdef local
#endif

#define maxn

using namespace std;

//�����Ҫ�������ƶ������ǽ�����һ�����ֺ���Էֳ�������ȵĲ��֣���ô���ǰ��գ�0��n)��1��n-1)(2,n-2)...��˳���ԭ���зֳ��������֣��Ƚ��������ֵĲ�ֵ���Ӵ�������Ҳ�ֵһ������Ƿ���ھͿ�����

ll n,len=0;//len��¼arr1������˼�����

struct Cell
{
    ll num,min,max;
};

struct Mynum
{
    ll num;
    ll dis;
};

vector<Cell>arr1;       //��¼����������arr�г�������Щ����min��¼��С�±�max��¼����±�
vector<Mynum>arr;       //arr�洢��ʼ����ֵ��.dis�洢ԭ�����±�λ��
vector<ll>sum;          //ǰ׺�����飬sum[i]��¼ǰi�����ĺ�

bool cmp(Mynum x,Mynum y)
{
    return x.num<y.num;
}

bool judge1(ll x,ll target)
{
    ll l=1,r=len,mid;
    while(l<r-1)
    {
        if(arr1[r].num==target) //�����Ҳ༴�ɣ��·����ж�����õ���<target����l���l�����Ǳ߽�
        {
            if(arr1[r].max>x) return 1;
            else return 0;
        }
        mid=l+(r-l)/2;
        if(arr1[mid].num<target) l=mid;
        else r=mid;
    }
    if(arr1[l].num==target&&arr1[l].max>x) return 1;//����ѭ���Ļ�Ҫ������������
    if(arr1[r].num==target&&arr1[r].max>x) return 1;//�����кʹ��ʱ��Ҫ���ҵ����Ǹ���������±�Ҫ�ȵ�ǰ�ָ���±�Ҫ��
    return 0;
}

bool judge2(ll x,ll target)
{
    ll l=1,r=len,mid;
    while(l<r-1)
    {
        if(arr1[r].num==target)
        {
            if(arr1[r].min<=x) return 1;
            else return 0;
        }
        mid=l+(r-l)/2;
        if(arr1[mid].num<target) l=mid;
        else r=mid;
    }
    if(arr1[l].num==target&&arr1[l].min<=x) return 1;//ǰ���к�С��ʱ���ҵ����Ǹ�������С�±�Ҫ������
    if(arr1[r].num==target&&arr1[r].min<=x) return 1;
    return 0;
}

int main()
{
    scanf("%lld",&n);
    arr.resize(n+1);
    sum.resize(n+1);
    arr1.resize(n+1);
    sum[0]=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i].num);
        sum[i]=sum[i-1]+arr[i].num;
        arr[i].dis=i;
    }
    sort(&arr[1],&arr[n+1],cmp);//��arr�����С�������������ڶ��ֲ���
    arr1[0].num=-1;
    for(ll i=1;i<=n;i++)//��arr1�����ʼ��
    {
        arr1[i].min=llINF;
        arr1[i].max=0;
    }
    for(ll i=1;i<=n;i++)        //��������arr�������ݴ�������arr1��
    {
        if(arr[i].num==arr1[len].num)
        {
            if(arr[i].dis>arr1[len].max) arr1[len].max=arr[i].dis;
            if(arr[i].dis<arr1[len].min) arr1[len].min=arr[i].dis;
        }
        else
        {
            len++;
            arr1[len].num=arr[i].num;
            arr1[len].max=arr[i].dis;
            arr1[len].min=arr[i].dis;
        }
    }
    if(sum[n]%2||n==1) printf("NO\n");//�����ܺ�����������ֻ��һ���������
    else
    {
        bool flag=0;
        for(ll i=0;i<n;i++)     //ע��iҪ��0��ʼȡ
        {
            ll target=sum[n]/2-sum[i];      //�ܺ͵�һ���ȥ��ǰ���е��ܺͼ�Ϊ�������к�-ǰ���кͣ�/2
            if(target==0)                   //������ֱ���ж���ȷ
            {
                flag=1;
                break;
            }
            else if(target>0)               //�������Ĵ���judge1
            {
                if(judge1(i,target))
                {
                    flag=1;
                    break;
                }
            }
            else if(judge2(i,-target))      //ǰ��Ĵ���judge2
            {
                flag=1;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}


