//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/C
#include<bits/stdc++.h>
int main()
{
    int n;
    long long int k;
    std::cin>>n>>k;
    std::vector<long long int> v(n,0);
    for(int i=0;i<n;i++)
        std::cin>>v[i];
    int start=0,end=0;
    long long int sum=0,ans=0;
    while(end<n)
    {
        sum+=v[end];
        while(start<=end && sum>k)
        {
            sum-=v[start];
            start++;
        }
        ans+=(end-start+1);
        end++;
    }
    std::cout<<ans;
}