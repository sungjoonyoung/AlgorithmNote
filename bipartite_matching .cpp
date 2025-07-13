//#include<iostream>
//#include<vector>
//#include<set>
//#include<tuple>
//using namespace std;
//set<int> adj_list[1000];
//vector<tuple<int, int, int>> Query;
//int fixed_arr[1000];
//int P[1000];
//int DFS(int x) {
//    // cout<<x<<" ";
//    for (auto nx : adj_list[x]) {
//        if (fixed_arr[nx])continue;
//        fixed_arr[nx] = 1;
//        if (P[nx] == 0) { //find new possible line
//            P[nx] = x;
//            return 1;
//        }
//        if (DFS(P[nx])) {//backtracking
//            P[nx] = x;
//            return 1;
//        }
//    }
//    return 0;
//}
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int N, M, K;
//    cin >> N >> M >> K;
//    for (int i = 1; i <= K; i++) {
//        int n, m, c;
//        cin >> n >> m >> c;
//        Query.push_back({ n,m,c });
//    }
//    for (int i = 0; i < Query.size(); i++) {
//        int a, b, c;
//        tie(a, b, c) = Query[i];
//        if (c == 1)continue;
//        for (int j = 0; j < Query.size(); j++) {
//            int aa, bb, cc;
//            tie(aa, bb, cc) = Query[j];
//            if (c == cc)continue;
//            if (a == aa or b == bb)adj_list[i + 1].insert(j + 1);
//        }
//    }
//
//
//    int answer = 0;
//    for (int i = 1; i < 1000; i++) {
//        // if(adj_list[i].size()==0)continue;
//        fill(fixed_arr, fixed_arr + 1000, 0);
//        answer += DFS(i);
//    }
//    cout << answer;
//}

#include<iostream>
#include<vector>
using namespace std;
vector<int> adj_list[501];
int P[501];
int visited[501];
int BI_DFS(int x) {
    for (auto a : adj_list[x]) {
        if (visited[a])continue;
        visited[a] = 1;
        if (P[a] == 0 or BI_DFS(P[a])) {
            P[a] = x;
            return 1;
        }
    }
    return 0;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    while (Q--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (adj_list[i].empty())continue;
        fill(visited, visited + N + 1, 0);
        answer += BI_DFS(i);
    }
    cout << answer;
}