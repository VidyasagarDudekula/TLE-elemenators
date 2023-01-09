//https://codeforces.com/problemset/problem/1251/C
#include<bits/stdc++.h>
int main()
{
    long long int t;
    std::cin>>t;
    std::cin.ignore();
    for(long long int i=0;i<t;i++)
    {
        std::string s;
        std::getline(std::cin,s);
        long long int start=0,end=0,val1 = s.length();
        while(end<val1)
        {
            if((s[start]-'0')%2!=(s[end]-'0')%2)
            {
                long long int i=start, j= end;
                while(s[i]<=s[j] && i<=j)
                    i++;
                bool flag = false;
                while(i<j && j>0)
                {
                    flag = true;
                    std::swap(s[j-1],s[j]);
                    j--;
                }
                start=j;
                if(flag)
                    start++;
            }
            end++;
            // std::cout<<start<<" "<<end<<"\n";
        }
        std::cout<<s<<"\n";
    }
}