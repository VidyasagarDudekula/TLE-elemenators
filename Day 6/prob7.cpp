//https://cses.fi/problemset/task/1629
#include<bits/stdc++.h>
int main()
{
    int n;
    scanf("%d",&n);
    std::vector<std::pair<long long int,long long int>>v;
    for(int i=0;i<n;i++)
    {
        std::pair<long long int,long long int> p;
        scanf("%lld%lld",&p.second,&p.first);
        v.push_back(p);
    }
    std::sort(v.begin(),v.end());
    std::vector<std::pair<long long int,long long int>> movies;
    long long int k=-1,count=0;
    long long int end = 0;
    while(end<v.size())
    {
        // std::cout<<v[end].second<<" "<<k<<"\n";
        if(v[end].second>=k)
        {
            count++;
            k = v[end].first;
        }
        end++;
    }
    std::cout<<count;
}