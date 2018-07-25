// closest pair of points
// Moodle lecture 1 by Prof. S. Baswana
// input: #points, (x1,y1), (x2,y2),....,(xn,yn)

#include<iostream>
#include<vector>
using namespace std;

typedef struct node{
  int x;
  int y;
}Node;

Node* createNode(int x, int y){
  Node* tmp = (Node*)calloc(1,sizeof(Node));
  tmp->x = x;
  tmp->y = y;
  return tmp;
}

void mergeSort(vector<Node*> *pts, int left, int right){
  int n = right - left + 1;
  vector<Node*> tmp(n,NULL);
  if(left >= right){
    return;
  }

  int mid = (left + right)/2;
  mergeSort(pts, left, mid);
  mergeSort(pts, mid+1, right);
  int i,j,k;
  for(i=left,j=mid+1,k=0; i<=mid && j<=right; ){
    if(*pts[i] < *pts[j]){
      tmp[k] = *pts[i];
      i++; k++;
    }
    else{
      tmp[k] = *pts[j];
      j++; k++;
    }
  }
  while(i!=mid){
    
  }

}

int main(){
  int n;
  cin>>n;
  int i,x,y;
  vector<Node*>pts(n,NULL);
  for(i=0;i<n;i++){
    cin>>x>>y;
    pts[i] = createNode(x,y);
  }
  cout<<endl;
  // for(i=0;i<n;i++){
  //   cout<<pts[i]->x<<" "<<pts[i]->y<<endl;
  // }












  return 0;
}
