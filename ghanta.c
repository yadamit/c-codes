#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
  int val;
  struct node* next;
};
int isEmpty(struct node* head){
  if(head==NULL)
  return 1;
  return 0;
}
int pop(struct node** head){
  struct node *tmp=*head;
  *head=(*head)->next;
  return tmp->val;
}
void push(struct node** head,int val){
  struct node* tmp=calloc(1,sizeof(struct node));
  tmp->val=val;
  tmp->next=(*head);
  *head=tmp;
}




int main(){
  int t,l;
  scanf("%d",&t);
  for(l=0;l<t;l++){
        char store[1000];
        int b[100];
        getchar();
        char c=getchar();
        int i=0,size,j;
        while(c!='\n'){
          store[i]=c;
          i++;
          c=getchar();
        }
        store[i]='\0';


        size=i;
        // printf("size=%d \n",size);
        int x=1,y=2;
        scanf("%d %d",&x,&y);
        // printf("  x=%d y=%d  \n",x,y);
        i=0;j=0;
        int k=0;
        // printf("%s\n",store);
        for(i=0;i<size;){
          j=i; //printf("hello motto\n");
          while(store[j]!=' ' && store[j]!='\0'){
            if(store[j]=='x' && store[j+1]!='y'){
              char tmp[20];
              strncpy(tmp,store+i,j-i);
              tmp[j-i]='\0';
                  // printf("   %s   ",tmp);

              b[k]=(atoi(tmp)==0)? 1:atoi(tmp);
              b[k]=b[k]*x;
                  // printf("  %d  ",b[k]);
              k++;
            }
            else if(store[j]=='y' && store[j+1]!='x'){
              char tmp[20];
              strncpy(tmp,store+i,j-i);
              tmp[j-i]='\0';
              b[k]=(atoi(tmp)==0)? 1:atoi(tmp);
              b[k]=b[k]*y;
              // printf(" %d ",b[k]);
              k++;
            }
            else if((store[j]=='x' && store[j+1]=='y')||(store[j]=='y' && store[j+1]=='x')){
              char tmp[20];
              strncpy(tmp,store+i,j-i);
              tmp[j-i]='\0';
              b[k]=(atoi(tmp)==0)? 1:atoi(tmp);
              b[k]=b[k]*y*x;
              // printf(" %d ",b[k]);
              k++;j++;
            }
            else if(store[j]=='+'){
              b[k]=-1;
              // printf(" %d ",b[k]);
              k++;
            }
            else if(store[j]=='-'){
              b[k]=-2;
              k++;
            }
            else if(store[j]=='*'){
              b[k]=-3;
              k++;
            }
            else if(store[j]=='/'){
              b[k]=-4;
              k++;
            }
            else if(store[j+1]==' ' || store[j+1]=='\0'){
              // printf("hi j=%d\n",j);
              char tmp[20];
              strncpy(tmp,store+i,j-i+1);
              tmp[j-i+1]='\0';
              b[k]=atoi(tmp);
              k++;
            }
            j++;
          }
          i=j+1;
        }
          struct node* stack=NULL;
          for(i=0;i<k;i++){
            if(b[i]==-1);//if + don't do anythin
            else if(b[i]==-2){
              push(&stack,-1*b[++i]);
            }
            else if(b[i]==-3){
              push(&stack,pop(&stack)*b[++i]);
            }
            else if(b[i]==-4){
              push(&stack,pop(&stack)/b[++i]);
            }
            else{
              push(&stack,b[i]);
            }
          }
          int sum=0;
          while(!isEmpty(stack)){
            // printf(" %d ",stack->val);
            sum=sum+pop(&stack);
          }
          printf("%d\n",sum);
        // for(i=0;i<k;i++){
        //   printf(" %d ",b[i]);
        // }
  }
}
