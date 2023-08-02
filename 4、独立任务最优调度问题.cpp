#include <bits/stdc++.h>
using namespace std;
int n;
int*a,*b;
int solve(){
	int i,j,k;
	bool*** p;
	int sum_a=0,sum_b=0;
	for(i=0;i<n;i++) {
		sum_a += a[i];
		sum_b += b[i];
	}
	int ret;
	p=new bool** [sum_a + 1];
	for(i=0;i<=sum_a;i++)
		p[i]=new bool* [sum_b + 1];
	for(i=0;i<=sum_a;i++)
		for(j=0;j<=sum_b;j++)
			p[i][j]=new bool[n + 1];
	for(i=0;i<=sum_a;i++) {
		for(j=0;j<=sum_b;j++) {
			p[i][j][0]=true;
			for(k=1;k<=n;k++)
				p[i][j][k]=false;
		}
	}
	for(k=1;k<=n;k++) {
		for(i=0;i<=sum_a;i++) {
			for(j=0;j<=sum_b;j++) {
				if(i-a[k-1] >= 0)
					p[i][j][k]=p[i-a[k-1]][j][k-1];
				if(j-b[k-1] >= 0)
					p[i][j][k]=p[i][j][k] || p[i][j-b[k-1]][k-1];
			}
		}
	}
	for(i=0,ret=2147483000;i<=sum_a;i++) {
		for(j=0;j<=sum_b;j++) {
			if(p[i][j][n]) {
				int tmp=(i > j) ? i : j;
				if(tmp<ret)
					ret=tmp;
			}
		}
	}
	return ret;
}
int main()
{
	cin>>n;
	a=new int[n];
	b=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	cout<<solve()<< endl;
	return 0;
}