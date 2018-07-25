#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
  int val;
  struct node* next;
}; //this struct node is used to store numbers or results of airthmatics
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
  char store[1000];
  int b[100];
  // getchar();
  char c=getchar();
  int i=0,size,j;
  while(c!='\n'){
    store[i]=c;
    i++;
    c=getchar();
  }
  store[i]='\0';


  size=i;
  printf("size=%d ",size);
  int x=1,y=2;
  scanf("%d %d",&x,&y);
  printf("  x=%d y=%d  ",x,y);

  i=0;j=0;
  int k=0;
  printf("%s\n",store);
  for(i=0;i<size;){
    j=i; //printf("hello motto\n");
    while(store[j]!=' ' && store[j]!='\0'){
      printf("hi");
      if(store[j]=='x' && store[j+1]!='y'){
        char tmp[20];
        strncpy(tmp,store+i,j-i);
        tmp[j-i]='\0';
            printf("   %s   ",tmp);
        b[k]=atoi(tmp);
        b[k]=b[k]*x;
            printf("  %d  ",b[k]);
        k++;
      }
      if(store[j]=='y' && store[j+1]!='x'){
        char tmp[20];
        strncpy(tmp,store+i,j-i);
        tmp[j-i]='\0';
        b[k]=atoi(tmp);
        b[k]=b[k]*y;
        // printf(" %d ",b[k]);
        k++;
      }
      if((store[j]=='x' && store[j+1]=='y')||(store[j]=='y' && store[j+1]=='x')){
        char tmp[20];
        strncpy(tmp,store+i,j-i);
        tmp[j-i]='\0';
        b[k]=atoi(tmp);
        b[k]=b[k]*y*x;
        k++;
      }
      if(store[j]=='+'){
        b[k]=-1;
        // printf(" %d ",b[k]);
        k++;
      }
      if(store[j]=='-'){
        b[k]=-2;
        k++;
      }
      if(store[j]=='*'){
        b[k]=-3;
        k++;
      }
      if(store[j]=='/'){
        b[k]=-4;
        k++;
      }
      j++;
    }
    i=j+1;
  }

// printf("\n");
//   for(i=0;i<size;i++){
//     printf("%c",store[i]);
//   }
//   printf("\n");
//   for(i=0;i<k;i++){
//     printf(" %d ",b[i]);
//   }
  struct node* stack=NULL;
// printf("hi");
  for(i=0;i<k;i++){
    if(b[i]==-1);//if + don't do anythin
    else if(b[i]==-2){
      push(&stack,-1*b[i++]);
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
    sum=sum+stack->val;
  }
  // printf("\nsum=%d",sum);

  }
