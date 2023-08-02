#include<bits/stdc++.h>
using namespace std;
int n,m,d;
int c[100][100];
int w[100][100];
int tc=0;
int tw=0;
int minw=1000000;
int final[100];
int test[100];
void solve(int t){
    if(t>=n){
        if(tw<minw){
            minw=tw;
            for(int i=0;i<n;i++)
                final[i]=test[i];
        }
        return;
    }
   for(int i=0;i<m;i++){
       tc+=c[t][i];
       tw+=w[t][i];
       test[t]=i;
      if(tc<=d && tw <=minw){
        solve(t+1);
      }
      tc-=c[t][i];
      tw-=w[t][i];
   }
}
int main(){
    cin >> n >> m >> d;
    memset(final,0,sizeof(final));
    memset(test,0,sizeof(test));
    memset(c,0,sizeof(c));
    memset(w,0,sizeof(w));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c[i][j];
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> w[i][j];
        }
    }
    solve(0);
    cout << minw << endl;
    for(int i=0;i<n;i++){
       cout << final[i]+1 << " ";
    }
    return 0;
}