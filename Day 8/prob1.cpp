#include<bits/stdc++.h>
bool check(std::string &s1,std::string &s2)
{
    std::cout<<s1<<" "<<s2<<"\n";
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i])
            return false;
    }
    return true;
}
void rec(int index,std::string &s,std::set<std::string> &v,int k)
{
    if(index==-1)
    {
        std::string s1=s;
        v.insert(s1);
        return;
    }
    for(int i=index;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            std::swap(s[i],s[j]);
            rec(index-1,s,v,k);
            std::swap(s[i],s[j]);
        }
        if(i==0)
            rec(index-1,s,v,k);
    }
}
std::string getPermutation(int n, int k) {
    std::string s="";
    std::map<int,int> mp;
    mp[0]=1; mp[1]=1; mp[2]=2; mp[3]=6; mp[4]=24; mp[5]=120; mp[6]=720; mp[7]=5040; mp[8]=40320; mp[9]=362880;
    long long int sum=0;
    int count = n;
    std::vector<bool> v(n,true);
    int i=0;
    while(count>0)
    {
        if(v[i]){
            if(sum+mp[count-1]>=k)
            {
                s+=std::to_string(i+1);
                v[i]=false;
                i=-1;
                count-=1;
            }
            else sum+=mp[count-1];
        }
        i++;
    }
    return s;
}
int main()
{
    int n=4;
    int k=9;
    std::cout<<getPermutation(n,k);
}