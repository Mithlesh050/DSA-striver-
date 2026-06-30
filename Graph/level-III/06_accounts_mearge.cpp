#include<bits/stdc++.h>
using namespace std ;

class disjointSet {
    vector<int> parent, size;

public:
    disjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUparent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUparent(parent[node]);
    }
    void unionBysize(int u, int v) {
        int ultiparentU = findUparent(u);
        int ultiparentV = findUparent(v);
        if (ultiparentU == ultiparentV)
            return;
        else if (size[ultiparentU] < size[ultiparentV]) {
            parent[ultiparentU] = ultiparentV;
            size[ultiparentV] += size[ultiparentU];
        } else {
            parent[ultiparentV] = ultiparentU;
            size[ultiparentU] += size[ultiparentV];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjointSet ds(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                } else {
                    ds.unionBysize(i, mp[mail]);
                }
            }
        }
        vector<string> meargeMail[n];
        for (auto it : mp) {
            meargeMail[ds.findUparent(it.second)].push_back(it.first);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (meargeMail[i].size() == 0)
                continue;
            sort(meargeMail[i].begin(), meargeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]) ;
            for (auto it : meargeMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(){
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"John", "johnnybravo@mail.com"}};
    Solution s ;
    vector<vector<string>> ans = s.accountsMerge(accounts);
    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}