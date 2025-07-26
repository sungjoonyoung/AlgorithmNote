#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
vector<int> s;
vector<int> adj[20'001];
int p[20'001];
bool fix[20'001];
int ind=1;
int DFS(int x){
    p[x]=ind;
    int pnum=ind;
    s.push_back(x);
    ind++;
    for(int i=0;i<adj[x].size();i++){
        if(!p[adj[x][i]])pnum=min(pnum,DFS(adj[x][i]));
        else if(!fix[adj[x][i]])pnum=min(pnum,p[adj[x][i]]);
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
    int N=20'001;
    // setting

    for(int i=1;i<=N;i++)if(!p[i])DFS(i);

    
    
}
