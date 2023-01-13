//given an array of positive integers, select 3 elements from it suchh that they can form a triangle and perimeter of the triangle is maximized (1<=N<= 10^5)
//https://www.geeksforgeeks.org/maximum-perimeter-triangle-from-array/
#include<bits/stdc++.h>
int maxPerimeter(int arr[], int n){
    std::sort(arr,arr+n);
    int ans = -1;
    for(int i = 0;i<n-2;i++)
    {
        if(arr[i]+arr[i+1]>arr[i+2])
            ans = std::max(ans,arr[i]+arr[i+1]+arr[i+2]);
    }
    return ans;
}
int main()
{
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        std::cin>>arr[i];
    std::cout<<maxPerimeter(arr,n);
}