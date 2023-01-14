//https://cses.fi/problemset/task/1091/
#include<bits/stdc++.h>
long long int get_possible_ticket(long long int budget,std::vector<long long int> &prices, std::unordered_map<long long int,long long int> &mp)
{
    int start=0 ,end = prices.size() - 1;
    long long int ans =-1;
    // std::cout<<"indices:- "<<start<<" "<<end<<"\n";
    while(start<=end)
    {
        long long int mid = start + (end-start)/2;
        if(prices[mid]<=budget)
        {
            ans = mid;
            start = mid+1;
        }
        else end= mid-1;
    }
    return ans;
}
int main()
{
    long long int n,m;
    std::cin>>n>>m;
    std::vector<long long int> prices(n,0);
    std::vector<long long int> persons(m,0);
    for(long long int i=0;i<n;i++)
        std::cin>>prices[i];
    for(long long int j=0;j<m;j++)
        std::cin>>persons[j];

    std::sort(prices.begin(),prices.end());
    std::unordered_map<long long int,long long int> mp;
    std::vector<long long int> v;
    for(long long int i=0;i<n;i++){
        mp[prices[i]]++;
        if(mp[prices[i]]==1)
            v.push_back(prices[i]);
    }
    for(long long int i=0;i<m;i++)
    {
        long long int index = get_possible_ticket(persons[i],v,mp);
        if(index>-1)
        {
            std::cout<<v[index]<<"\n";
            mp[v[index]]--;
            long long int val = v[index];
            if(mp[v[index]]==0)
                v.erase(v.begin()+index);
        }
        else std::cout<<-1<<"\n";
    }
}
//TLE