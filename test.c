#include<stdio.h>
int main(){
  struct node* stack=NULL;
  int x,y;
  // struct node* st2=mk_node(6);
  int size,i=0,j=0;
  char store[100][10]; //use mallocing space instead
  char c='a';
  for(i=0;c!='\n';){
    c=getchar();

    if(c=='\n'){
      printf("c is new line");
      store[i][j]='\0';
      i++;j=0;
      break;
    }
    if(c==' '){
      printf("increasing i by 1, space");
      store[i][j]='\0';
      i++;continue;
    }
    store[i][j++]=c;

  }
  size=i;
  printf("size=%d\n",size);
  scanf("%d %d",&x,&y);
  printf("x=%d y=%d store[1][0]=%c\n",x,y,store[1][0]);

  for(i=0;i<size;i++){
    printf("%c\n",store[i][0]);
  }
}
// scanf("%s %s",a,b);
// printf("%s\n%s\n",a,b);
// printf("%d",strcmp(a,"hi"));
// for(i=0;i<size;i++){
//   scanf("%s",a);
//   // printf("scanned=%s \n",a);
//   if(strcmp(a,"+")==0){
//     // push(&st1,pop(&st1)+)
//   }
//   else if(strcmp(a,"-")==0){
//     scanf("%s",b);
//     i++;
//     push(&st1,-1*atoi(b));
//   }
//   else if(strcmp(a,"*")==0){
//     scanf("%s",a); i++;
//     push(&st1,pop(&st1)*atoi(a));
//   }
//   else if(strcmp(a,"/")==0){
//     scanf("%s",a); i++;
//     push(&st1,pop(&st1)/atoi(a));
//   }
//   else{
//     push(&st1,atoi(a));
//   }
// }
// int sum=0;
// while(st1!=NULL){
//   printf("%d ",st1->val);
//   sum=sum+st1->val;
//   st1=st1->next;
// }
// printf("%d\n",sum);
