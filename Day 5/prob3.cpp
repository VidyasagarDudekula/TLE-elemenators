//https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C
#include<bits/stdc++.h>
long long int get_possible_ways(long long int r,std::vector<long long int> &v,long long int total_ways)
{
    long long int start=0,end=0,count=0;
    while(end<v.size())
    {
        while(v[end] - v[start]>r && start<=end)
        {
            start+=1;
        }
        // std::cout<<start<<" "<<end<<"\n";
        count = end-start +1 ;
        total_ways -= count ;
        end++;
    }
    return total_ways;
}
int main()
{
    long long int n,r;
    std::cin>>n>>r;
    std::vector<long long int> v(n,0);
    for(long long int i=0;i<n;i++)
        std::cin>>v[i];
    long long int total_ways = (n*(n+1))/2;
    std::cout<<get_possible_ways(r,v,total_ways);
}