//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
#include<bits/stdc++.h>
int main()
{
    long long int n;
    std::cin>>n;
    long long int k;
    std::cin>>k;
    std::vector<long long int> v(n,0);
    for(long long int i=0;i<n;i++)
        std::cin>>v[i];
    int start=0,end=0;
    std::map<long long int,long long int> mp;
    long long int M=v[0],m=v[0];
    long long int count =0;
    while(end<n)
    {
        mp[v[end]]++;
        M = std::max(M,v[end]);
        m = std::min(m,v[end]);
        while(M-m>k && start<=end)
        {
            mp[v[start]]--;
            if(mp[v[start]]==0)
                mp.erase(v[start]);
            start++;
            std::map<long long int,long long int>::iterator it = mp.begin();
            m = it->first;
            it = mp.end();
            it--;
            M = it->first;
        }
        if(M-m<=k)
        {
            long long int l = end-start+1;
            count +=l;
            // std::cout<<start<<" "<<end<<"\n";
        }
        end++;
    }
    std::cout<<count<<"\n";
}