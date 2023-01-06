//given an array of positive integers find the length of smallest subarray with sum of element >= k
#include<bits/stdc++.h>
int smallest_subarray(int k,std::vector<int> &v)
{
    int start=0, end=0, ans=v.size(), sum=0;
    while(end<v.size())
    {
        sum+=v[end];
        while(sum>=k && start<=end)
        {
            ans = std::min(ans,end-start+1);
            sum-=v[start];
            start++;
        }
        end++;
    }
    if(ans==v.size() && sum>=k)
        return 0;
    return ans;
}
int main()
{
    std::vector<int> v{1,6,4,2,0,5,4,6,8,1,2,3,4,11,5,3,4,12,6};
    int k=16;
    std::cout<<smallest_subarray(k,v);
}