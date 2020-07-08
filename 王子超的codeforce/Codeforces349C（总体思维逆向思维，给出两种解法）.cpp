µÚÒ»ÖÖ½â·¨£¨µÚ¶þÖÖ¸üÖ±½ÓÒ»µã£¬²»Ïë¿´µÚÒ»ÖÖ¾ÍÈ¥¿´µÚ¶þÖÖ£©
ÎÒÃÇ¿ÉÒÔÕâÑùÏë£¬Èç¹ûÎÒÃÇ×Ü¹²½øÐÐÁËxÂÖÓÎÏ·£¬Èç¹ûÒ»¸öÈËÔÚÆäÖÐµÄkÂÖ±»Ñ¡ÎªÉÏµÛ£¬ÄÇÃ´Êµ¼ÊÉÏËû×÷ÎªÍæ¼ÒµÄÂÖÊýÎªx-k£¬Ò²¾ÍÊÇËµËûÆÚÍûÓÎÍæµÄÂÖÊýnumÒªÂú×ãnum<=x-k£¬Ò²¾ÍÊÇnum+k<=x¡£
×¢Òâ¹Û²ìµ½ÕâÀïµÄkÊµ¼ÊÉÏÒ»¸öÐèÒª²Î¼ÓÓÎÏ·ÂÖÊýµÄÔö¼ÓÖµ£¨²»¹ÜÊÇµ±ÉÏµÛ»¹ÊÇÍæ¼Ò£©£¬×Ü¹²½øÐÐxÂÖÓÎÏ·Ò²¾ÍÓÐxÈË´Îµ±ÁËÉÏµÛ£¬Ò²¾ÍÊÇËµ×Ü¹²ÒªÔö¼ÓxÂÖÊýµ½ËûÃÇµÄÆÚÍûÖµÉÏ£¬ÎÒÃÇËùÇóµÄ´ð°¸ÊÇÔö¼Ó×Ü¹²xÂÖÊýµ½ËûÃÇÔ­±¾µÄÆÚÍûÂÖÊýºó£¬ËùÓÐÂÖÊýÖÐ×î´óÖµµÄ×îÐ¡Öµ¡££¨ÕâÃ´Ã÷ÏÔµÄÒ»¸ö¶þ·Ö´ð°¸ÌØµã£©
ÓÉ´ËÕâ¸öÎÊÌâ¿ÉÒÔ×ª»¯ÎªÒ»ÖÖ¶þ·Ö´ð°¸µÄË¼Â·¡£µ«ÊÇÕâÀïµÄµÚÒ»ÖÖ½â·¨²ÉÈ¡µÄÊÇ½áÂÛ½â·¨¡£

ÎÒÃÇ°Ñ³õÊ¼ÆÚÍûÂÖÊýÖÐµÄ×î´óÖµ¶¨Î»Max£¬ÎÒÃÇ¸ù¾Ý×îÖÕ´ð°¸ÂÖÊýans=Max£¨ÂÖÊý²»¿ÉÄÜ±ÈÆÚÍûÂÖÊý×î´óÖµMax»¹Ð¡µÄ£¬Ô­Òò×Ô¼ºÏë£©»¹ÊÇans>Max·ÖÎªÁ½ÖÖÇé¿öÌÖÂÛ¡£

ÎÒÃÇ¼ÆËãÃ¿Ò»¸öÈËµÄÆÚÍûÂÖÊýÓë×î´óÖµMaxµÄ²îÖµ£¬ÀÛ¼Óµ½tempÉÏ£¬Ò²¾ÍÊÇans=MaxÇé¿öÏÂÍæ¼Ò¿ÉÒÔ×÷ÎªÉÏµÛ×î¶à´ÎÊý£¬Êµ¼ÊÉÏÒ²¾ÍÊÇÓÎÏ·½øÐÐµÄ×î¶àÂÖÊý¡£Èç¹ûtemp´óÓÚµÈÓÚMaxÂÖ£¬¾Í´ú±íÊÇ¿ÉÒÔÂú×ã½øÐÐMaxÂÖµÄÐèÇóµÄ£¬ans¾ÍÊÇMax¡£
µ«ÊÇÈç¹ûMax>tempµÄ»°£¬´ú±í»¹´æÔÚMax-tempÂÖÊýµÄÉÏµÛÃ»ÈË·ÖÅä×ß£¬ÄÇÃ´ÕâÐ©´ÎÊý»¹Òª¼ÌÐø·ÖÅä¸øËùÓÐÈË£¬ÎÒÃÇÏ£Íû×îºóµÄ×î´óÂÖÊý¾¡¿ÉÄÜÐ¡µÄ»°£¬ÄÇ¾Í²ÉÈ¡¾¡¿ÏÄÜÆ½¾ù·ÖÅäµÄ·½·¨¡£
ÆäÖÐn¸öÈËµ±ÖÐµÄÒ»¸ö±»Ñ¡×öÁË×î´óÂÖÊý£¬ÄÇÃ´Êµ¼ÊÉÏÎÒÃÇMax-tempÆ½¾ù·ÖÅäµ½ÁËn-1¸öÈËµ±ÖÐ£¬´ð°¸ans=Max+[(Max-temp)/n-1]£¨ÕâÀïÒªÏòÉÏÈ¡Õû£©
#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll num[maxn];

int main()
{
    IOS;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++) cin>>num[i];
    sort(num,num+n);
    ll temp=0;
    for(ll i=0;i<n;i++) temp+=num[n-1]-num[i];
    if(temp>=num[n-1]) cout<<num[n-1]<<endl;
    else
    {
        temp=num[n-1]-temp;
        ll ans=num[n-1]+temp/(n-1);
        if(temp%(n-1)) ans++;
        cout<<ans<<endl;
    }
}



µÚ¶þÖÖ½â·¨
ÎÒÃÇÃ¿´Î½øÐÐÓÎÏ·£¬¿ÉÒÔÁîn-1¸öÈË»¹ÐèÒª½øÐÐµÄÂÖÊý-1,Ò²¾ÍÊÇËùÓÐÈËµÄ×ÜÐèÒªÂÖÊý-(n-1)¡£
ÄÇÃ´ÎÒÃÇÍ³¼ÆËùÓÐÈËµÄ×ÜÐèÒªÂÖÊýsum£¬ÔÚ×îÓÅ²ßÂÔÏÂ£¨Ã¿´Î¶¼Ñ¡È¡µ±Ç°ÐèÒªÂÖÊý×îÐ¡µÄÄÇ¸öÈËµ±ÉÏµÛ£©ÐèÒª½øÐÐµÄÂÖÊýÎª[sum/(n-1)]£¨ÏòÉÏÈ¡Õû£©£¬Êµ¼ÊÉÏÕâÖÖÇé¿ö¾ÍÆõºÏÁËµÚÒ»ÖÖ½â·¨ÖÐÌÖÂÛµÄans>Max£¨MaxÎª³õÊ¼ÆÚÍûÂÖÊýÖÐµÄ×î´óÖµ£©µÄÇé¿ö¡£
Èç¹û[sum/(n-1)]<MaxµÄ»°£¬ÓÉÓÚans²»¿ÉÄÜÐ¡ÓÚMax£¨Õâ¸ö×Ô¼ºÏë£©£¬´ð°¸Ö»ÄÜÎªMax¡££¨ÆõºÏÁËµÚÒ»ÖÖ½â·¨ÖÐans=MaxµÄÇé¿ö£©

#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS;
    ll n;
    cin>>n;
    ll sum=0,Max=-1;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        sum+=x;
        Max=max(Max,x);
    }
    cout<<max(Max,sum/(n-1)+(sum%(n-1)?1:0))<<endl;
}
