#include<bits/stdc++.h>
using namespace std;
int function1(int *a,int n,int start=0,int end=0){
	int max=0;  
	for(int i=1; i<=n;i++)  
	{  
	    int sum = 0;  
	    for(int j=i;j<=n;j++)  
	    {  
	        sum+=a[j];  
	        if(sum>max)  
	        {  
	           start=i;  
	           end=j;  
	           max=sum;  
	        }  
	    }  
	}
	return max; 
}
int function2(int *a,int left,int right){  
    if(right==left)  
    	return a[left]>0?a[left]:0;  
    int center=(left+right)/2;  
    int leftMaxInterval=function2(a,left,center);    
    int rightMaxInterval=function2(a,center+1,right);  
    int sum=0;  
    int left_max=0;  
    for(int i=center;i>=left;i--){
       sum+=a[i];  
       if(sum>left_max)  
          left_max=sum;  
    }
    sum=0;  
    int right_max=0;  
    for(int i=center+1;i<=right;i++){  
       sum+=a[i];
       if(sum>right_max)  
         right_max=sum;  
    }
    int ret=left_max+right_max;  
    if(ret<leftMaxInterval)  
        ret=leftMaxInterval;  
    if(ret<rightMaxInterval)  
        ret=rightMaxInterval;  
    return ret;  
 }
int function3(int *a,int n,int start=0,int end=0){
	int max = 0;  
	int b[n+1];  
	memset(b,0,n+1);  
	for(int i = 1; i <= n; ++i){  
		if(b[i-1]>0)
			b[i] = b[i-1]+a[i];  
		else  
	    	b[i] = a[i];  
		if(b[i]>max)  
	    	max = b[i];  
	}
	return max;
}
int main(){
	int n;
	cin>>n;
	int data[n+5];
	for(int i=1;i<=n;i++)
		cin>>data[i];
	cout<<function1(data,n)<<endl;
	cout<<function2(data,1,n)<<endl;
	cout<<function3(data,n)<<endl;
}