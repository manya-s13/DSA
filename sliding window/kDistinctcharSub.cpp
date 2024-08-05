#include<iostream>
#include<unordered_map>

using namespace std;

int kDistinctChars(int k, string &str)
{
    int maxlen = 0, l = 0, r = 0;
    unordered_map<char, int> mpp;
    while(r<str.size()){
        mpp[str[r]]++;
        if(mpp.size()>k){
            if(--mpp[str[l]]==0) mpp.erase(str[l]);
            l++;
        }
        if(mpp.size()<=k){
            maxlen = max(maxlen, r-l+1);
           
        }
        r++;
    }
    return maxlen;
}

int main(){
    string str;
    cin>>str;
    int k; cin>>k;

    cout<<kDistinctChars(k, str);

    return 0;
}