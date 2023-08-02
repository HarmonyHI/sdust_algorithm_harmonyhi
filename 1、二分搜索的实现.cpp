#include <bits/stdc++.h>
using namespace std;
int RBinarySearch(int* arr,int key,int left,int right){	//递归实现二分查找
    if(key<arr[left]||key>arr[right])//未查找到时的终止条件
        return -1;
    int middle=(left&right)+((left^right)>>1);//设定middle时防止溢出
    if(key<arr[middle])
        return RBinarySearch(arr,key,left,middle-1);//搜索左半部分数组
    else if(key>arr[middle])
        return RBinarySearch(arr,key,middle+1,right);//搜索右半部分数组
    else 
        return middle;//成功查找，返回目标值下标
}

int CBinarySearch(int* arr,int key,int n)   //迭代实现二分查找
{
    int left=0;
    int right=n-1;
    if(key<arr[left]||key>arr[right])//未查找到时的终止条件
        return -1;
    while(left<=right){
            int middle =(left&right)+((left^right)>>1);//设定middle时防止溢出
            if(key<arr[middle])
                right = middle-1;//搜索左半部分数组
            else if(key>arr[middle])
                left = middle+1;//搜索右半部分数组
            else
                return middle;//成功查找，返回目标值下标
    }
    return -1;//未查找到时的终止条件
}

int main() {
    cout<<"input object nums"<<endl;
    int n;
    cin>>n;
    int arr[80];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    cout<<"After sort:";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;


    while(true){
        cout<<"input key:";
        int key,position;
        cin>>key;
        //递归搜索
        position = RBinarySearch(arr,key,0,n-1);
        if(position==-1)
            cout<<"search "<<key<<" is not found"<<endl;
        else
            cout<<"search "<<key<<" (R)\n"<<"position is "<<position<<endl;
        //迭代搜索
        position = CBinarySearch(arr,key,n);
        if(position==-1)
            cout<<"search "<<key<<" is not found"<<endl;
        else
            cout<<"search "<<key<<" (C)\n"<<"position is "<<position<<endl;
    }
}



