class Solution {
public:
    bool poss(string &s1,string &s2){
        if(s1.size()!=s2.size()+1) return false;
        int a=0;
        int b=0;
        while(a<s1.size()){
            if(b<s2.size() && s1[a]==s2[b]){
                a++;
                b++;
            }
            else a++;
        }
        return b==s2.size();
    }
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(poss(words[i],words[prev])&&dp[i]<dp[prev]+1){
                    dp[i]=1+dp[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};