#include<bits/stdc++.h>
bool check(int mid,int k,std::vector<int> &v)
{
    int start=0,end=0,sum=0;
    while(end<v.size())
    {
        if(end-start+1==mid)
        {
            if(sum<=k)
                return true;
            sum-=v[start];
            start+=1;
        }
        sum+=v[end];
        end++;
    }
    return false;
}
int largest_subarray(int k,std::vector<int> &v)
{
    int ans = 0;
    int start=1,end=v.size();
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(check(mid,k,v))
        {
            ans = std::max(mid,ans);
            start = mid+1;
        }
        else end = mid-1;
    }
    return ans;
}
int main()
{
    std::vector<int> v{1,6,4,2,0,5,4,6,8,1,2,3,4,11,5,3,4,12,6};
    int k=16;
    std::cout<<largest_subarray(k,v);
}