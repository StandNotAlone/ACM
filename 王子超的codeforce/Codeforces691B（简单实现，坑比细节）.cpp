×¢ÒâbºÍdÊÇ¶Ô³ÆµÄ
È»ºó¾ÍÊÇi,m,n¶¼ÊÇ²»¶Ô³ÆµÄ£¬ÒòÎª×óÉÏ½Ç¶¼»áÓÐ¸ö¡°Ð¡¹´¡±£¨½áºÏÒ»ÏÂ±ê×¢µÄÓ¢ÎÄÊéÐ´Ï°¹ß£©

#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

char pd[2][26]=
{
    '!','d','!','b','!','!','!','!','!','!','!','!','!','!','o','q','p','!','!','!','!','v','w','x','!','!',
    'A','!','!','!','!','!','!','H','I','!','!','!','M','!','O','!','!','!','!','T','U','V','W','X','Y','!'
};  //pd[0][i]±íÊ¾µÚi+1¸öÐ¡Ð´×ÖÄ¸¶ÔÓ¦µÄ¶Ô³Æ×ÖÄ¸£¬pd[1][i]±íÊ¾µÚi+1¸ö´óÐ´×ÖÄ¸¶ÔÓ¦µÄ¶Ô³Æ×ÖÄ¸
//Èç¹û¶ÔÓ¦µÄ¶Ô³Æ×ÖÄ¸²»´æÔÚ¾ÍÓÃ'!'×Ö·û£¬Ó¢ÎÄ×ÖÄ¸ÖÐ±Ø¶¨²»´æÔÚ×ÖÄ¸ÓëËüÏàÍ¬£¬Òò´Ë¿ÉÒÔÓÃËü±íÊ¾²»´æÔÚ

int main()
{
    IOS;
    string s;
    cin>>s;
    bool flag=1;
    ll len=s.size();
    for(ll i=0;i<len/2+1;i++)   //×¢ÒâÕâÀïµÄÑ­»·ÏÞÖÆÊÇlen/2+1¶ø²»ÊÇlen/2£¬ÒòÎª»¹ÐèÒªÅÐ¶ÏÖÐ¼äµÄÄÇ¸ö×ÖÄ¸ÊÇ²»ÊÇ×óÓÒ¶Ô³ÆµÄ¡£
    {
        if(s[i]>='a'&&s[i]<='z')//ÅÐ¶ÏÊÇ´óÐ´»¹ÊÇÐ¡Ð´×ÖÄ¸
        {
            if(s[len-i-1]!=pd[0][s[i]-'a']) flag=0;
        }
        else if(s[len-i-1]!=pd[1][s[i]-'A']) flag=0;
    }
    if(flag) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;
}

