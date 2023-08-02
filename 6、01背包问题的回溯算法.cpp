#include<bits/stdc++.h>
using namespace std;
int n,c,bestp;
int p[10000],w[10000],x[10000],bestx[10000];
void solve(int i,int cp,int cw){
    int j;
    if(i>n){
        if(cp>bestp){
            bestp=cp;
            for(i=0;i<=n;i++) bestx[i]=x[i];
        }
    }
    else 
        for(j=0;j<=1;j++){
            x[i]=j;
            if(cw+x[i]*w[i]<=c){
                cw+=w[i]*x[i];
                cp+=p[i]*x[i];
                solve(i+1,cp,cw);
                cw-=w[i]*x[i];
                cp-=p[i]*x[i];
            }
        }
}

int main(){
    int i;
    bestp=0; 
    scanf("%d",&n);
    scanf("%d",&c);
    for(i=1;i<=n;i++) 
        scanf("%d",&w[i]);
    for(i=1;i<=n;i++) 
        scanf("%d",&p[i]);
    solve(1,0,0);
    printf("%d",bestp);
    return 0;
}