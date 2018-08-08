#include<iostream>
using namespace std;

int max(int a, int b){
  return (a>b)? a:b;
}

int max_value(int W, int wt[], int val[], int n){
  if(n < 0){
    return 0;
  }
  if(wt[n] > W){
    return max_value(W, wt, val, n-1);
  }

  return max(max_value(W, wt, val, n-1), max_value(W-wt[n], wt, val, n-1) + val[n]);
}


int main(){
  int n,i;
  cin>>n;
  int W;
  cin>>W;
  int wt[n],val[n];

  for(i=0;i<n;i++){
    cin>>wt[i]>>val[i];
  }

  cout<<endl<<max_value(W,wt,val,n-1);
}
