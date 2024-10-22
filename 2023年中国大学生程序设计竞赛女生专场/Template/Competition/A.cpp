#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

stack<int> block[13];
stack<int> pq;
int x[3];

void solve()
{
    while (!pq.empty()){
        pq.pop();
    }
    for (int i = 0;i<13;i++){
        while(!block[i].empty()){
            block[i].pop();
        }
    }
    x[0] = 2,x[1] = 3,x[2] = 4;
    block[2].push(0),block[3].push(1),block[4].push(2);
    for (int i = 1;i<13;i++){
        int a,b;
        cin >> a >> b;
        if (a==1){
            while (block[x[0]].top()!=0){
                pq.push(block[x[0]].top());
                block[x[0]].pop();
            }
            pq.push(block[x[0]].top());
            block[x[0]].pop();
            x[0]+=b;
            while (!pq.empty()){
                block[x[0]].push(pq.top());
                x[pq.top()] = x[0];
                pq.pop();
            }
        }else if (a==2){
            while (block[x[1]].top()!=1){
                pq.push(block[x[1]].top());
                block[x[1]].pop();
            }
            pq.push(block[x[1]].top());
            block[x[1]].pop();
            x[1]+=b;
            while (!pq.empty()){
                block[x[1]].push(pq.top());
                x[pq.top()] = x[1];
                pq.pop();
            }
        }else{
            while (block[x[2]].top()!=2){
                pq.push(block[x[2]].top());
                block[x[2]].pop();
            }
            pq.push(block[x[2]].top());
            block[x[2]].pop();
            x[2]+=b;
            while (!pq.empty()){
                block[x[2]].push(pq.top());
                x[pq.top()] = x[2];
                pq.pop();
            }
        }
    }
    if (block[9].size()==3){
        cout<<"Y"<<endl;
    }else{
        cout<<"N"<<endl;
    }
    return;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}