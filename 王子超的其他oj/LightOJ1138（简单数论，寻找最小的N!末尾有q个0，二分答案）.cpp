#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int cal(int x)
{
    int ret=0;
    while(x)//����x!�ֽ����������ж��ٸ�5
    {
        ret+=x/5;
        x/=5;
    }
    return ret;
}

int main()
{
    IOS;//ʹ��֮��Ҫ����cin��scanf printf
    int t;cin>>t;
    for(int CASE=1;CASE<=t;CASE++)
    {
        int m;cin>>m;
        int l=5,r=5e8;//�ұ߽翪һ���㹻��ľ����ˣ�ֱ��5��������m�ķ�Χ�ع�������Ҫ�ٶ������
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(cal(mid)<m) l=mid+1;
            else r=mid;
        }
        cout<<"Case "<<CASE<<": ";
        if(cal(l)==m) cout<<l<<endl;
        else cout<<"impossible"<<endl;
    }
}

