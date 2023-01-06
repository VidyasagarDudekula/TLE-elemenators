//given an array find the length of the longest subarray with not more than the k distict elements
//time complexity :- O(n)
#include<bits/stdc++.h>
int main()
{
    std::map<int,int> mp;
    int start = 0,end = 0;
    std::vector<int> v{5,6,2,1,4,1,2,3,6,5,9,8,7,2,0,5,4,1,2,6,8,5,1,3};
    int k = 4;
    int ans = 0;
    while(end<v.size())
    {
        mp[v[end]]++;
        while(mp.size()>k && start<=end)
        {
            mp[v[start]]-=1;
            if(mp[v[start]]==0)
                mp.erase(v[start]);
            start++;    
        }
        ans = std::max(ans,end-start+1);
        end++;
    }
    std::cout<<ans<<"\n";
}