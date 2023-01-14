//https://cses.fi/problemset/task/1643/
#include<bits/stdc++.h>
int main()
{
    int n;
    std::cin>>n;
    std::vector<long long int> v(n,0);
    for(int i=0;i<n;i++)
        std::cin>>v[i];
    long long int sum = 0,ans = INT_MIN;
    int start=0, end=0;
    while(end<n)
    {
        sum+=v[end];
        ans = std::max(sum,ans);
        if(sum<0)
            sum=0;
        end++;
    }
    std::cout<<ans;
}