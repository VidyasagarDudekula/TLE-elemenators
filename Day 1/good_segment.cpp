#include<bits/stdc++.h>
//this approach is using the two pointers approach
int largest_subarray(int k,std::vector<int> &v)
{
    int start=0,end=0,ans = 0,sum = 0;
    while(end<v.size())
    {
        sum += v[end];
        while(start<=end && sum>k)
        {
            sum-=v[start];
            start++;
        }
        if(sum<=k)
            ans = std::max(ans,end-start+1);
        end++;
    }
    return ans;
}
int main()
{
    std::vector<int> v{1,6,4,2,0,5,4,6,8,1,2,3,4,11,5,3,4,12,6};
    int k=16;
    std::cout<<largest_subarray(k,v);
}