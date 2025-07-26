#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
vector<int> adj[100'001];
vector<int> s;
int p[100'001];
bool fix[100'001];
int ind=1;
int DFS(int x){
    p[x]=ind;
    int pnum=ind;
    s.push_back(x);
    ind++;
    for(int i=0;i<v[x].size();i++){
        if(!p[v[x][i]])pnum=min(pnum,DFS(v[x][i]));
        else if(!fix[v[x][i]])pnum=min(pnum,p[v[x][i]]);
    }
    if(p[x]==pnum){
        while(s.back()!=x){
            fix[s.back()]=1;
            p[s.back()]=x;
            s.pop_back();
        }
        fix[s.back()]=1;
        p[s.back()]=x;
        s.pop_back();
    }
    return pnum;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
}
