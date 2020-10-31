class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int k) {
        int ans=0;
        int out=0;
        int n=g.size();
        if(k>=n){
            for(int i=0;i<n;i++){
                ans+=c[i];
            }
            return ans;
        }
        int res=0;
        for(int i=0;i<k;i++){
            if(g[i]==0){
                ans+=c[i];
            }else{
                res+=c[i];
            }
        }
        out=max(out,res);
        int j=k,i=0;
        while(j<n){
            if(g[i]==1){
                res-=c[i];
            }
            if(g[j]==1){
                res+=c[j];
            }else if(g[j]==0){
                ans+=c[j];
            }
            out=max(out,res);
            i++;
            j++;
        }
        return ans+out;
    }
};