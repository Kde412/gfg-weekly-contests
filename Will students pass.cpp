class Solution {
  public:
    int minimumCost(int n, int m, int x, vector<int> &p, vector<vector<int>> &a) {
        int lim=pow(2,n);
        int ans=INT_MAX;
        for(int i=0;i<lim;i++)
        {
            int amt=0;
            //int ans=1e8;
            vector<int>temp(m,0);
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    amt+=p[j];
                    for(int k=0;k<m;k++)
                    {
                        temp[k]+=a[j][k];
                    }
                }
            }
            bool ok=1;
            for(int j=0;j<m;j++)
            {
                if(temp[j]<x)
                {
                ok=0;
                break;
                }
            }
            if(ok)
            ans=min(ans,amt);
        }
        if(ans==INT_MAX){
        return -1;}
        return ans;
    }
};
