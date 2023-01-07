//problem link :- https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
#include<bits/stdc++.h>
int main()
{
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    long long int a[n],b[m];
    for(long long int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(long long int i=0;i<m;i++)
        scanf("%lld",&b[i]);
    long long int count = 0,c_a=0, c_b=0;
    long long int i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
            long long int temp_i=i;
            while(temp_i<n && a[temp_i]==a[i])
                temp_i+=1;
            c_a = temp_i - i;
            i=temp_i;
            long long int temp_j = j;
            while(temp_j<m && b[temp_j]==b[j])
                temp_j+=1;
            c_b = temp_j - j;
            j=temp_j;
            count += (c_a*c_b); 
        }
        else if(a[i]<b[j])
            i++;
        else j++;
    }
    printf("%lld",count);
}

//Accepted.