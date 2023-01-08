//https://codeforces.com/problemset/problem/702/C
//this solution is not a purly two pointers solution.
#include<bits/stdc++.h>
bool check(std::vector<long long int> &a,std::vector<long long int> &b,long long int r)
{
    for(long long int i=0;i<a.size();i++)
    {
        bool flag = true;
        long long int start = 0, end=b.size()-1;
        while(start<=end)
        {
            long long int mid = start + (end-start)/2;
            if(a[i]>=b[mid]-r && a[i]<=b[mid]+r)
            {
                flag = false;
                break;
            }
            if(a[i]<b[mid])
                end = mid-1;
            else if(a[i]>b[mid])
                start = mid+1;
        }
        if(flag)
            return false;
    }
    return true;
}
int main()
{
    long long int n,m;
    std::cin>>n>>m;
    std::vector<long long int> a(n,0);
    std::vector<long long int> b(m,0);
    long long int Ma=INT_MIN, Mi=INT_MAX;
    for(long long int i=0;i<n;i++){
        std::cin>>a[i];
        Mi=std::min(Mi,a[i]);
        Ma=std::max(Ma,a[i]);
    }
    for(long long int i=0;i<m;i++){
        std::cin>>b[i];
        Mi=std::min(Mi,b[i]);
        Ma=std::max(Ma,b[i]);
    }
    long long int start=0, end=std::max(std::abs(Ma-Mi),Ma),ans = 0;
    while(start<=end)
    {
        long long int mid = start+(end-start)/2;
        if(check(a,b,mid))
        {
            ans= mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    std::cout<<ans;
}