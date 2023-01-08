//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E
#include<bits/stdc++.h>
int main()
{
    int n,k;
    std::cin>>n>>k;
    std::vector<int> v(n,0);
    for(int i=0;i<n;i++)
        std::cin>>v[i];
    std::unordered_map<int,int> mp;
    int start=0,end=0;
    long long int count=0;
    while(end<n)
    {
        mp[v[end]]++;
        while(mp.size()>k && start<=end)
        {
            mp[v[start]]--;
            if(mp[v[start]]==0)
                mp.erase(v[start]);
            start++;
        }
        if(mp.size()<=k)
            count += (end-start+1);
        end++;
    }
    std::cout<<count;
}