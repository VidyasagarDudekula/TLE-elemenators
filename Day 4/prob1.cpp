//https://codeforces.com/problemset/problem/1251/C
#include<bits/stdc++.h>
int main()
{
    int t;
    std::cin>>t;
    std::cin.ignore();
    while(t--)
    {
        std::string s;
        std::getline(std::cin,s);
        std::vector<char> odd,even;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]-'0')%2==0)
                even.push_back(s[i]);
            else odd.push_back(s[i]);
        }
        int i=0,j=0;
        while(i<even.size() && j<odd.size())
        {
            if(odd[j]<even[i]){
                s[i+j] = odd[j];
                j++;
            }
            else{
                s[i+j] = even[i];
                i+=1;
            }
        }
        while(i<even.size()){
            s[i+j] = even[i];
            i++;
        }
        while(j<odd.size()){
            s[i+j] = odd[j];
            j++;
        }
        std::cout<<s<<"\n";
    }
}
