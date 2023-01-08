//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B
#include<bits/stdc++.h>
int main()
{
    int n;
    std::cin>>n;
    long long int k;
    std::cin>>k;
    std::vector<int> v(n,0);
    for(int i=0;i<n;i++)
        std::cin>>v[i];
    int start=0, end=0;
    long long int count=0,sum=0;
    while(end<n)
    {
        sum+=v[end];
        while(sum>k && start<=end)
        {
            sum-=v[start];
            start++;
        }
        if(sum<=k){
            long long int l=end-start+1;
            count+=(l*(l+1))/2;
        }
        end++;
    }
    std::cout<<count;
}