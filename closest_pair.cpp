// closest pair of points
// Moodle lecture 1 by Prof. S. Baswana
// input: #points, (x1,y1), (x2,y2),....,(xn,yn)

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int inf = 99999;
typedef struct node{
  float x;
  float y;
}Node;

typedef struct info{
  float x1,y1;
  float x2,y2;
  float dist;
}info;

Node* createNode(float x, float y){
  Node* tmp = (Node*)calloc(1,sizeof(Node));
  tmp->x = x;
  tmp->y = y;
  return tmp;
}

float distance(float x1, float y1, float x2, float y2){
  return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

void mergeSort(vector<Node*> *pts, int left, int right, string axis){
  int n = right - left + 1;
  cout<<"left="<<left<<" right="<<right<<" n = "<<n<<endl;
  vector<Node*> tmp(n,NULL);
  if(left >= right){
    // tmp[0] = *pts[left];
    return ;
  }

  int mid = (left + right)/2;
  mergeSort(pts, left, mid, axis);
  mergeSort(pts, mid+1, right, axis);
  int i,j,k;
  for(i=left,j=mid+1,k=0; i<=mid && j<=right; ){
    cout<<"i,j ="<<i<<" "<<j<<endl;
    if(axis=="X"){
      if( ((*pts)[i]->x < (*pts)[j]->x) ){
        tmp[k] = (*pts)[i];
        i++; k++;
      }
      else{
        tmp[k] = (*pts)[j];
        j++; k++;
      }
    }
    else if(axis=="Y"){
      if( ((*pts)[i]->y < (*pts)[j]->y) ){
        tmp[k] = (*pts)[i];
        i++; k++;
      }
      else{
        tmp[k] = (*pts)[j];
        j++; k++;
      }
    }
    else{
      cout<<"Invalid axis"<<endl;
      return;
    }
  }
  while(i<=mid){
    tmp[k] = (*pts)[i];
    i++; k++;
  }
  while(j<=right){
    tmp[k] = (*pts)[j];
    j++; k++;
  }

  cout<<"copying"<<endl;
  for(i=left,k=0; i<=right; i++,k++){
    (*pts)[i] = tmp[k];
    cout<<tmp[k]->x<<endl;
    // free(tmp[k]);
  }
}

vector<Node*> searchPoints(vector<Node*> *pts, int left, int right, string axis){
  //return a vector contianing points b/w left and right x-co-ordinates
  vector<Node*>tmp;
  int l = 0;
  int r = (*ptr).size()-1;
  int i = (l+r)/2;
  while((r-l)>1){
    if(left > (*pts)[i]->x){
      l = i;
      i = (l+r)/2;
    }
    else{
      r = i;
      i = (l+r)/2;
    }
  }
  int left_index = r;
  while((*ptr)[left_index]->x <= right){
    tmp.push_back( (*ptr)[left_index] )

  }
}

info* min_dist(vector<Node*> *pts, int left, int right){
  int mid = (left+right)/2;
  info* tmp = (info*)calloc(1,sizeof(info));
  if(left >= right){
    tmp->x1 = (*pts)[left]->x ;
    tmp->x2 = (*pts)[right]->x;
    tmp->y1 = (*pts)[left]->y ;
    tmp->y2 = (*pts)[right]->y ;
    tmp->dist = inf;
    return tmp;
  }
  if((right-left)<=1){
    tmp->x1 = (*pts)[left]->x ;
    tmp->y1 = (*pts)[left]->y ;
    tmp->x2 = (*pts)[right]->x;
    tmp->y2 = (*pts)[right]->y ;
    tmp->dist = distance(tmp->x1,tmp->y1 ,tmp->x2, tmp->y2);
  }
  info* tmp1 = min_dist(pts, left, mid); //dist = a
  info* tmp2 = min_dist(pts, mid+1, right); //dist = b
  float b = (tmp1->dist > tmp2->dist)? tmp2->dist : tmp1->dist;
  int mid_x = (*pts)[mid]->x;
  int left_x = mid_x - b;
  int right_x = mid_x + b;
  vector<Node*> left_strip = searchPoints(pts, left_x, mid_x);
  vector<Node*> right_strip = searchPoints(pts, mid_x, right_x);
  mergeSort(&left_strip, 0, (*left_strip).size()-1, "Y"); //sort along y-axis
  mergeSort(&right_strip, 0, (*right_strip).size()-1, "Y"); //sort along y-axis

}

int main(){
  int n;
  cin>>n;
  int i;
  float x,y;
  vector<Node*>pts(n,NULL);
  for(i=0;i<n;i++){
    cin>>x>>y;
    pts[i] = createNode(x,y);
  }

  mergeSort(&pts, 0, n-1, "X");//sort along X-axis

  // cout<<endl;
  // for(i=0;i<n;i++){
  //   cout<<pts[i]->x<<" "<<pts[i]->y<<endl;
  // }













  return 0;
}
