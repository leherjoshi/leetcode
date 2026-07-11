class Solution {
public:
    vector<int>parent;
    void init(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

    }
    int find(int u){
        if(parent[u]==u)return u;
        else return parent[u]=find(parent[u]);
    }
   void merge(int u,int v){
    int parA=find(u);
    int parB=find(v);

    if(parA!=parB)
        parent[parB]=parA;
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        init(n);
        for(int i=0;i<edges.size();i++){
            merge(edges[i][0],edges[i][1]);
        }

        unordered_map<int,int> nodes;

            for (int i = 0; i < n; i++) {
                nodes[find(i)]++;
            }
        unordered_map<int,int> edjcount;

            for (int i = 0; i < edges.size(); i++) {
                edjcount[find(edges[i][0])]++;
            }
            int cnt=0;
            for(auto n:nodes){
                int leader=n.first;
                int vertex=n.second;
                int edj=edjcount[leader];

                cnt+=edj==vertex*(vertex-1)/2?1:0;
            }
        return cnt;
    }
};