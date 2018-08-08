#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

typedef struct point{
  int x;
  int y;
  int covered;
  int index;
} Point;

Point p1,p2;
int dist(Point p1, point p2){
  return (sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2)));
}

int compare_p1(const void* a, const void* b){
  return (dist(*(Point*)a, p1) - dist(*(Point*)b, p1));
}
int compare_p2(const void* a, const void* b){
  return (dist(*(Point*)a, p2) - dist(*(Point*)b, p2));
}



int main(){
  int n,i,j;
  // Point p1,p2;
  cin>>p1.x>>p1.y;
  cin>>p2.x>>p2.y;
  cin>>n;

  Point v[n];
  Point p1_sort[n];
  Point p2_sort[n];
  for(i=0;i<n;i++){
    cin>>v[i].x>>v[i].y;
    p1_sort[i].x = v[i].x;
    p1_sort[i].y = v[i].y;
    p1_sort[i].index = i;
    // p1_sort.p_x = p1.x;
    // p2_sort.p_y = p1.y;
    p2_sort[i].x = v[i].x;
    p2_sort[i].y = v[i].y;
    p2_sort[i].index = i;
    // p2_sort.p_x = p1.x;
    // p2_sort.p_y = p1.y;
  }
  // cout<<endl;
  // for(i=0;i<n;i++){
  //   cout<<v[i].x<<" "<<v[i].y<<endl;
  // }
  int r1=0,r2=0,min_sqr=999999;
  Point min_p1,min_p2;
  // for(i=0;i<n;i++){
  //   int tmp_r1 = dist(p1,v[i]);
  //   for(j=0;j<n;j++){
  //     int tmp_r2 = dist(p2,v[j]);
  //     if(tmp_r2 < )
  //     if(pow(tmp_r1,2)+pow(tmp_r2,2) < min_sqr){
  //       min_sqr = pow(tmp_r1,2)+pow(tmp_r2,2);
  //       r1 = tmp_r1;
  //       r2 = tmp_r2;
  //       min_p1 = v[i];
  //       min_p2 = v[j];
  //     }
  //   }
  // }
  //
  // cout<<"r1 = "<<r1<<" r2 = "<<r2<<" min_sqr = "<<min_sqr<<endl;
  // cout<<"min_p1 "<<min_p1.x<<" "<<min_p1.y<<endl;
  // cout<<"min_p2 "<<min_p2.x<<" "<<min_p2.y<<endl;

  qsort(p1_sort, n, sizeof(Point), compare_p1);
  for(i=0;i<n;i++){
    cout<<p1_sort[i].x<<" "<<p1_sort[i].y<<endl;
  }
  qsort(p2_sort, n, sizeof(Point), compare_p2);
  for(i=0;i<n;i++){
    cout<<p2_sort[i].x<<" "<<p2_sort[i].y<<endl;
  }

  i=n-1;
  j=n-1;
  // while(i<n && j<n){
  //   if(v[p1_sort[i].index].covered == 1){
  //     i++;
  //     continue;
  //   }
  //   if(v[p2_sort[j].index].covered == 1){
  //     j++;
  //     continue;
  //   }
    // if(dist(p1_sort[i], p1) < dist(p2_sort[j], p2)){
    //   int tmp_r1 = dist(p1_sort[i], p1);
    //   int tmp_r2 = dist(p1_sort[i], p2);
    //   if(pow(tmp_r1,2) + pow(r2,2) < pow(r1,2) + pow(tmp_r2,2)){
    //     r1 = tmp_r1;
    //   }
    //   else{
    //     r2 = tmp_r2;
    //   }
    //   v[p1_sort[i].index].covered = 1;
    //   i++;
    // }
  //
  //   else{
  //     int tmp_r1 = dist(p2_sort[j], p1);
  //     int tmp_r2 = dist(p2_sort[j], p2);
  //     if(pow(tmp_r1,2) + pow(r2,2) < pow(r1,2) + pow(tmp_r2,2)){
  //       r1 = tmp_r1;
  //     }
  //     else{
  //       r2 = tmp_r2;
  //     }
  //     v[p2_sort[j].index].covered = 1;
  //     j++;
  //   }
  // }
  // cout<<endl<<endl;
  // cout<<r1<<" "<<r2<<endl;

  while(i>=0 && j>=0){
    if(dist(p1_sort[i], p1) < r1 || dist(p1_sort[i], p2) < r2){
      i--;
      continue;
    }
    if(dist(p2_sort[j], p1) < r1 || dist(p2_sort[j], p2) < r2){
      j--;
      continue;
    }
    if(dist(p1_sort[i], p1) > dist(p2_sort[j], p2)){
      int tmp_r1 = dist(p1_sort[i], p1);
      int tmp_r2 = dist(p1_sort[i], p2);
      if(pow(tmp_r1,2) + pow(r2,2) < pow(r1,2) + pow(tmp_r2,2)){
        r1 = tmp_r1;
      }
      else{
        r2 = tmp_r2;
      }
      v[p1_sort[i].index].covered = 1;
      i--;
    }

    else{
      int tmp_r1 = dist(p2_sort[j], p1);
      int tmp_r2 = dist(p2_sort[j], p2);
      if(pow(tmp_r1,2) + pow(r2,2) < pow(r1,2) + pow(tmp_r2,2)){
        r1 = tmp_r1;
      }
      else{
        r2 = tmp_r2;
      }
      v[p2_sort[j].index].covered = 1;
      j--;
    }

  }
  cout<<endl<<endl;
  cout<<r1<<" "<<r2<<endl;














}
