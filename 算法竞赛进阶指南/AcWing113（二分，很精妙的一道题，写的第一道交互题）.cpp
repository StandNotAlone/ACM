// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution
{
public:
    vector<int> specialSort(int N)
    {
        vector<int>ans;
        ans.push_back(1);
        for(int i=2;i<=N;i++)
        {
            int l=0,r=(int)ans.size()-1;
            while(l<=r)             //目标是确定当前需要插入的位置的左边一个身位的下标
            {
                int mid=(l+r)>>1;
                if(compare(ans[mid],i)) l=mid+1;    //可以假设l+1=r和l=r的情况来考虑这里l和r如和变化
                else r=mid-1;
            }
            ans.push_back(i);
            for(int j=(int)ans.size()-2;j>r;j--) swap(ans[j],ans[j+1]);
        }
        return ans;
    }
};