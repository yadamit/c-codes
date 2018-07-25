#include<iostream>
#include<vector>
using namespace std;
struct node{
  int val;
  int chd;
};
typedef struct node NODE;

vector<int> sort(vector<int>v){

}

void infix(vector<NODE> v,int root){
  int n_child=0,i;
  vector<int> store;
  // cout<<"root="<<root<<endl;
  for(i=0;i<v.size();i++){
    if(v[i].val==root){
      n_child++;
      int j;
      // cout<<"children: "<<v[i].chd<<"store.size="<<store.size()<<endl;
      for(j=0;j<=store.size();j++){
        if(j==store.size()){
          store.push_back(v[i].chd);
          break;
        }
        else if(store[j]>v[i].chd){
          store.insert(store.begin()+j,v[i].chd);
          break;
        }
      }
      // store.push_back(v[i].chd);
      // cout<<"children of root="<<root<<" are "<<n_child<<endl;
    }
  }
  // for(i=0;i<store.size();i++){
  //   cout<<store[i];
  // }
  if(n_child==0){
    cout<<root<<" ";
    return;
  }
  else{
    // store=sort(store);
    for(i=0;i<n_child/2;i++){
      infix(v,store[i]);
    }
    cout<<root<<" ";
    for(i=n_child/2;i<n_child;i++){
      infix(v,store[i]);
    }
  }
  return;

}

int main(){
  int t,l;
  scanf("%d",&t);
  for(l=0;l<t;l++){
      int i, n;
      scanf("%d",&n);
      n=n-1;
      int a,b,root=1;
      NODE node;
      vector <NODE> v;
      for(i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        node.val=a;
        // if(i==0) root=a; //store the vlue of root term
        node.chd=b;
        v.push_back(node);
      }
      // cout<<v.size()<<endl;
      infix(v,root);
      cout<<endl;
    }
}
