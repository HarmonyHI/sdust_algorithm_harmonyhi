#include<bits/stdc++.h>
using namespace std;
typedef struct Node {
    char name;
    int weight;
    Node *left,*right;
} Node;
struct comparer{
    bool operator()(Node* &x,Node* &y){
        return x->weight>y->weight;
    }
};

Node* BuildHuffmanTree(priority_queue<Node*,vector<Node*>,comparer> treenode) {
    while(true) {
    	if(treenode.size()<=1)
    		break;
        Node *newnode=new Node;           
        Node *x=new Node;
        x=treenode.top();
        treenode.pop();
        Node *y=new Node;
        y=treenode.top();
        treenode.pop();
        newnode->weight=x->weight+y->weight;
        newnode->left=x;
        newnode->right=y;
        treenode.push(newnode);         
    }
    return treenode.top();      
}

void PrintAns(Node *Root,vector<int> ans) {
    if(Root->left==NULL&&Root->right==NULL) {
        cout<<Root->name<<":";
        for(auto i:ans) {
            cout<<i;
        }
        cout<<endl;
        return ;                           
    }
	else {               
        ans.push_back(0);    
        PrintAns(Root->left,ans);
        ans.pop_back();    
        ans.push_back(1);
        PrintAns(Root->right,ans);
        ans.pop_back();
    }
}


int main() {
    priority_queue<Node*,vector<Node*>,comparer> treenode;
    char charater;
    cout<<"Input the character list"<<endl;
    vector<char> box;
    while((charater=getchar())!='\n') {
        if(charater==' ')continue;
        box.push_back(charater);
    }
    cout<<"Input each character's heavy"<<endl;
    for(int i=0; i<box.size(); i++) {
        int weight;
        cin>>weight;
        Node* node=new Node;
        node->name=box[i];
        node->weight=weight;
        node->left=NULL;
        node->right=NULL;
        treenode.push(node);
    }
    Node* Root=BuildHuffmanTree(treenode);
    vector<int> ans;
    cout<<"Each character's huffman code is:"<<endl;
    PrintAns(Root,ans);
}
