注意b和d是对称的
然后就是i,m,n都是不对称的，因为左上角都会有个“小勾”（结合一下标注的英文书写习惯）

#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

char pd[2][26]=
{
� � '!','d','!','b','!','!','!','!','!','!','!','!','!','!','o','q','p','!','!','!','!','v','w','x','!','!',
� � 'A','!','!','!','!','!','!','H','I','!','!','!','M','!','O','!','!','!','!','T','U','V','W','X','Y','!'
};� //pd[0][i]表示第i+1个小写字母对应的对称字母，pd[1][i]表示第i+1个大写字母对应的对称字母
//如果对应的对称字母不存在就用'!'字符，英文字母中必定不存在字母与它相同，因此可以用它表示不存在

int main()
{
� � IOS;
� � string s;
� � cin>>s;
� � bool flag=1;
� � ll len=s.size();
� � for(ll i=0;i<len/2+1;i++) � //注意这里的循环限制是len/2+1而不是len/2，因为还需要判断中间的那个字母是不是左右对称的。
� � {
� � � � if(s[i]>='a'&&s[i]<='z')//判断是大写还是小写字母
� � � � {
� � � � � � if(s[len-i-1]!=pd[0][s[i]-'a']) flag=0;
� � � � }
� � � � else if(s[len-i-1]!=pd[1][s[i]-'A']) flag=0;
� � }
� � if(flag) cout<<"TAK"<<endl;
� � else cout<<"NIE"<<endl;
}

