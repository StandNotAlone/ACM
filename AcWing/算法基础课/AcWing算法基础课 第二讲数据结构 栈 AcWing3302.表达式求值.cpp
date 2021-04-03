#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

stack<int>num;
stack<char>ope;
string s;

void cal(){
    int a=num.top();num.pop();
    int b=num.top();num.pop();
    switch(ope.top()){
        case '+':b+=a;break;
        case '-':b-=a;break;
        case '*':b*=a;break;
        case '/':b/=a;break;
        default:break;
    }
    ope.pop();
    num.push(b);
}

int get_level(char c){
    if(c=='+'||c=='-') return 1;
    else return 2;
}

int main(){
    IOS
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>'0'&&s[i]<='9'){
            int temp=0;
            while(i<s.size()&&s[i]>='0'&&s[i]<='9'){
                temp=temp*10+s[i]-'0';
                i++;
            }
            i--;
            num.push(temp);
        }
        else if(s[i]=='(') ope.push(s[i]);
        else if(s[i]==')'){
            while(ope.top()!='(') cal();
            ope.pop();
        }
        else{
            int now_level=get_level(s[i]);
            while(ope.size()&&ope.top()!='('&&get_level(ope.top())>=now_level) cal();
            ope.push(s[i]);
        }
    }
    while(ope.size()) cal();
    cout<<num.top()<<endl;
}
