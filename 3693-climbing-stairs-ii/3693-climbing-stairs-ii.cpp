class Solution {
public:

int Solve(int index, vector<int>& cost, int n){

    if(index==n)
        return 0;

    if(index>n)
        return INT_MAX;

    int ans=INT_MAX;

    if(index+1<=n)
        ans=min(ans,
        Solve(index+1,cost,n)+cost[index+1]+1);

    if(index+2<=n)
        ans=min(ans,
        Solve(index+2,cost,n)+cost[index+2]+4);

    if(index+3<=n)
        ans=min(ans,
        Solve(index+3,cost,n)+cost[index+3]+9);

    return ans;
}

int climbStairs(int n, vector<int>& costs){

    costs.insert(costs.begin(),0);

    return Solve(0,costs,n);
}
};