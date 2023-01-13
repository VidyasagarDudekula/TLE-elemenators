//given a array, find the minimum difference between the any two elements.
#include<bits/stdc++.h>
int main()
{
    int n;
    std::cin>>n;
    std::vector<int> v(n,0);
    for(int i=0;i<n;i++)
        std::cin>>v[i];
    //sort
    std::sort(v.begin(),v.end());
    int ans = INT_MAX;
    int i=0;
    while(i<v.size()-1)
    {
        int diff = v[i+1]-v[i];
        ans = std::min(ans,diff);
    }
    std::cout<<ans<<"\n";
}