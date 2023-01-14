//https://cses.fi/problemset/task/1640
#include<bits/stdc++.h>
int main()
{
    int n;
    long long int target;
    scanf("%d %lld",&n,&target);
    std::vector<long long int> v(n,0);
    for(int i=0;i<n;i++)
        scanf("%lld",&v[i]);
    std::unordered_map<long long int, long long int> mp;
    for(int i=0;i<n;i++)
    {
        long long int rem = target - v[i];
        if(mp[rem]>0){
            std::cout<<mp[rem]<<" "<<i+1;
            return 0;
        }
        mp[v[i]] = i+1;
    }
    std::cout<<"IMPOSSIBLE";
}