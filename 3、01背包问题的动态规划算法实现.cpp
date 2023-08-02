#include<bits/stdc++.h>
using namespace std;
int valuedp[20][300];
int weight[20],value[20];
int main(){
	int n,baglmt;
	cin>>n>>baglmt;
	for(int i=1;i<=n;i++){
		cin>>weight[i]>>value[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=baglmt;j++){
			if(weight[i]<=j){
				valuedp[i][j]=max(valuedp[i-1][j],valuedp[i-1][j-weight[i]]+value[i]);
			}
			else{
				valuedp[i][j]=valuedp[i-1][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=baglmt;j++){
			cout<<valuedp[i][j]<<" ";
		}
		cout<<endl;
	}
}