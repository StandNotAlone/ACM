#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>
#include<unordered_set>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e3+7;

bool flag[maxn][maxn];//flag[i][j]�����ַ���c�ĳ���ƥ�䵽iʱ��ƥ���ַ���a�ĳ���Ϊjʱ�Ƿ���У���ʱ��Ӧ��ƥ���ַ���b�ĳ���Ϊi-j

int32_t main()
{
    IOS;
    string a,b,c;
    while(cin>>a>>b>>c)
    {
        memset(flag,0,sizeof(flag));
        flag[0][0]=1;//���Ⱦ�Ϊ0��ʱ�������ǵĳ�ʼ�������Ϊ1
        int lena=(int)a.size();
        int lenb=(int)b.size();
        int lenc=(int)c.size();
        for(int i=1;i<=lenc;i++)//iΪ�ַ���c��ƥ�䳤��
        {
            for(int j=0;j<=i;j++)//jΪ�ַ���a��ƥ�䳤��
            {
                int k=i-j;//kΪ�ַ���c��ƥ�䳤��
                //����Ϊ���ַ���c��ƥ�䳤��Ϊi-1ʱ״̬ת������ǰ�ĳ���Ϊiʱ
                if(j<=lena&&a[j-1]==c[i-1]&&flag[i-1][j-1]) flag[i][j]=1;//�ַ���c�ĵ�i���ַ����±��Ӧi-1�����ַ���aƥ������
                if(k<=lenb&&b[k-1]==c[i-1]&&flag[i-1][j]) flag[i][j]=1;//�ַ���c�ĵ�i���ַ����±��Ӧi-1�����ַ���bƥ������
            }
        }
        bool f=0;
        for(int i=0;i<=lenc;i++)
            if(flag[lenc][i]) f=1;
        if(f&&lenc==lena+lenb) cout<<"Yes"<<endl;//�ǵ�������c�ĳ���Ҫ����a+b����Ȼa+b����c�������Ҳ�ǿ���ƥ��ɹ���
        else cout<<"No"<<endl;
    }
}
