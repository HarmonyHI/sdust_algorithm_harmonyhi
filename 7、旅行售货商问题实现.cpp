#include<bits/stdc++.h>
using namespace std;
const int scope=23;
int n,ans=1<<30,tot;
int vis[scope],minn[scope];
struct node{
    int order;
    int v;
}pos[scope][scope];
bool rule(const node &s1,const node &s2){
    return s1.v<s2.v;
}
void dfs(int x,int num){
    if(num==n){
        if(tot+minn[x]<ans) ans=tot+minn[x];
        return;
    }
    for(int i=2;i<=n;i++){
        if(!vis[pos[x][i].order]){
            if(tot+pos[x][i].v>=ans) return;
            if(tot+(n-num)+1>=ans) return;
            vis[pos[x][i].order]=1;
            tot+=pos[x][i].v;
            dfs(pos[x][i].order,num+1);
            vis[pos[x][i].order]=0;
            tot-=pos[x][i].v;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&pos[i][j].v);
            pos[i][j].order=j;
        }
        minn[i]=pos[i][1].v;
        sort(pos[i]+1,pos[i]+n+1,rule);
    }
    vis[1]=1;         
    dfs(1,1);
    printf("%d",ans);
    return 0;
}