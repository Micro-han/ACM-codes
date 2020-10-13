#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>


using namespace std;

#ifndef MAXNODE
#define MAXNODE 20005
#endif

int flag[MAXNODE] = {0};
int dfn[MAXNODE] = {0};
int low[MAXNODE] = {0};
int tpArr[MAXNODE] = {0};
int tpNum = 0;
int _index = 0;

vector<int> graph[MAXNODE];

stack<int> st;


void tarjan(int n){
    st.push(n);
    flag[n] = 1;
    dfn[n] = ++_index;
    low[n] = _index;
    for (int i = 0; i < graph[n].size(); i++) {
        int cur = graph[n][i];
        if (dfn[cur] == 0) {
            tarjan(cur);
            low[n] = min(low[n], low[cur]);
        }else{
            if (flag[cur] == 1) {
                low[n] = min(low[n], dfn[cur]);
            }
        }
    }
    if (dfn[n] == low[n]) {
        tpNum++;
        do{
            n = st.top();
            st.pop();
            flag[n] = 0;
            tpArr[n] = tpNum;
        }while(dfn[n] != low[n]);
    }
}

void addNode(int n1, int n2){
    if ((n1&1) > 0) {
        graph[n1].push_back(n2+1);
        graph[n2].push_back(n1+1);
    }else{
        graph[n1].push_back(n2-1);
        graph[n2].push_back(n1-1);
    }
}

void transAddNode(int a, int b, int l){
    if (l == 1) {
        addNode(a*2, b*2);
    }else{
        addNode(a*2-1, b*2-1);
    }
}

bool judge(int N){
    for (int i = 1; i <= N; i++) {
        if (tpArr[2*i-1] == tpArr[2*i]) {
            return false;
        }
    }
    return true;
}

int main(){
    int M;
    cin>>M; //测试组数
    while (M--) {
        int N,T;
        cin>>N>>T; //N是开关个数，T是规则个数
        int a,b,c;
        for (int i = 0; i < T; i++) {
            cin>>a>>b>>c; //输入a b c分别代表开关a，开关b，已经开关状态c只有(0/1)，表示开关a,b不能同时处于状态c
            transAddNode(a, b, c);
        }
        for (int i = 1; i <= 2*N; i++) {
            if (dfn[i] == 0) {
                tarjan(i);
            }
        }
        if(judge(N)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        for (int i = 1; i <= 2*N;i++) {
            flag[i] = 0;
            dfn[i] = 0;
            low[i] = 0;
            graph[i].clear();
        }
        _index = 0;
    }
    return 0;
}