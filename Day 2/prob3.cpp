//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/D
#include<bits/stdc++.h>
int main()
{
    int n;
    std::cin>>n;
    long long int k;
    std::cin>>k;
    std::vector<long long int> v(n,0);
    for(int i=0;i<n;i++)
        std::cin>>v[i];
    int start=0, end=0;
    long long int sum=0;
    long long int count=0;
    while(end<n)
    {
        sum+=v[end];
        while(sum>=k && start<=end)
        {
            count+=(n-end);
            sum-=v[start];
            start++;
        }
        end++;
    }
    std::cout<<count;
}