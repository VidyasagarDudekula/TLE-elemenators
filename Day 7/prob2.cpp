//https://cses.fi/problemset/task/1662
#include<bits/stdc++.h>
int main()
{
    long long int n,x;
    std::cin>>n;
    std::vector<long long int> v(n,0);
    for(long long int i=0;i<n;i++)
        std::cin>>v[i];
    std::unordered_map<long long int,long long int> mp;
    long long int sum=0,count=0;
    mp[sum]+=1;
    for(long long int i=0;i<n;i++)
    {
        sum+=v[i];
        if(mp[std::abs(sum)%n]>0)
            count+=mp[std::abs(sum)%n];
        mp[std::abs(sum)%n]++;
    }
    std::cout<<count;
}