//https://cses.fi/problemset/task/1074
#include<bits/stdc++.h>
int main()
{
    int n;
    std::cin>>n;
    std::vector<long long int> v(n);
    long long int sum = 0;
    for(int i=0;i<n;i++)
    {
        std::cin>>v[i];
        sum+=v[i];
    }
    long long int avg = sum/n;
    std::sort(v.begin(),v.end());

    int start=0, end=n-1;
    int mid = start + (end-start)/2;
    long long int val = v[mid];
    sum = 0;
    for(int i=0;i<n;i++)
    sum += std::abs(val-v[i]);

    std::cout<<sum;
}