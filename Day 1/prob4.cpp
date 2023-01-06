//given an array, find the first negative number in every subarray of size k.
#include<bits/stdc++.h>
int main()
{
    std::vector<int> v{1,5,-6,3,0,4,-2,6,-1,8,11,2,0,-3,5,6,-4,2,-7,1,6,-8,1,-9,4,-2,6,1,4,-3};
    int k = 5;
    int start = 0, end = 0;
    std::queue<int> qu;
    while(end<v.size())
    {
        if(v[end]<0)
            qu.push(v[end]);
        if(end-start+1>k)
        {
            if(!qu.empty())
                std::cout<<qu.front()<<"\n";
            if(v[start]<0)
                qu.pop();
            start++;
        }
        end++;
    }
}