#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n,m,i;
  cin>>n,m;
  vector<int>color(n,0);

  for(i=0;i<m;i++){
    int l,m,n,x;
    vector<int>d(0,3);
    cin>>v[1],v[2],v[3];

    if(color[v[1]]!=0) x=1;
    else if(color[v[2]]!=0) x=2;
    else if(color[v[3]]!=0) x=3;

    switch (color[v[x]]) {
      case 0: color[l]=1;
              color[m]=2;
              color[n]=3;
              break;
      case 1: if(x!=l) color[l]=2;
              color[n]=3;
              break;
      case 2: color[m]=1;
              color[n]=2;

    }

  }
}
