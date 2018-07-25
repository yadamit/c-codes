#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
  int val;
  struct node* next;
}; //this struct node is used to store numbers or results of airthmatics

struct node* mk_node(int val){
  struct node* tmp=calloc(1,sizeof(struct node));
  tmp->val=val;
  return tmp;
}
// STRUCT *struct node=NULL;

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

int find_str(char *a,char x){
  int i=0;
  while(a[i]!=x){
    if(a[i]=='\0') return -1;
    i++;
  }
  return i;
}

int min(int a,int b){
  if(a<b) return a;
  return b;
}

int main(){
  struct node* stack=NULL;
  int x,y;
  // struct node* st2=mk_node(6);
  int size,i=0,j=0;
  // char store[100][10]; //use mallocing space instead
  // char c='a';
  // for(i=0;c!='\n';i++){
  //   j=0;
  //   c=getchar();
  //   if(c=='\n'){
  //     store[i][j]='\0';
  //     i++;
  //     break;
  //   }
  //   if(c==' '){
  //     store[i][j]='\0';
  //     i++;continue;
  //   }
  //   store[i][j++]=c;
  //
  // }
  // size=i;
  scanf("%d %d",&x,&y);
  // printf("x=%d y=%d\n",x,y);



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
  // scanf("%s",store[i++]);//storing the equation in an array
  // while(store[i-1][0]!='\0'){
  //   scanf("%s",store[i++]);
  // }
  // int x,y;
  // scanf("%d %d",&x,&y);

char store[][10]={{"60x"},{"-"},{"3y"},{"+"},{"7"},{"*"},{"2"}};
size=7;
j=0;i=0;
for(j=0;j<size;j++){

  printf("%s",*(store+j));
}

i=0;
while(i<size){ //this loop converts any terms with x or y to the result by putting value of variables
  if((find_str(store[i],'x')!=-1)&&(find_str(store[i],'y')==-1)){
    char tmp[10];
    strncpy(tmp,store[i],find_str(store[i],'x'));
    printf("\nonly x  tmp=%s\n",tmp);
    sprintf(store[i],"%d",atoi(tmp)==0? x:atoi(tmp)*x);
  }
  else if((find_str(store[i],'x')==-1)&&(find_str(store[i],'y')!=-1)){
    char tmp[10];
    strncpy(tmp,store[i],find_str(store[i],'y'));
    printf("\nonly y  tmp=%s\n",tmp);
    sprintf(store[i],"%d",atoi(tmp)==0? y:atoi(tmp)*y);
  }
  else if((find_str(store[i],'x')!=-1)&&(find_str(store[i],'y')!=-1)){
    char tmp[10];
    strncpy(tmp,store[i],min(find_str(store[i],'y'),find_str(store[i],'x')));
    printf("both xy  tmp=%s\n",tmp);
    sprintf(store[i],"%d",atoi(tmp)==0? x*y:atoi(tmp)*x*y);
  }
  i++;
}

j=0;
for(j=0;j<size;j++){
printf("%s ",store[j]);
}

i=0;
for(i=0;i<size;){//pushes to stack
  if(strcmp(store[i],"+")==0) i++;
  else if(strcmp(store[i],"-")==0){
    push(&stack,-1*atoi(store[i++]));
  }
  else if(strcmp(store[i],"*")==0){
    push(&stack,pop(&stack)*atoi(store[++i]));
    i++;
  }
  else if(strcmp(store[i],"/")==0){
     printf(" 1 ");
    push(&stack,pop(&stack)/atoi(store[++i]));
    i++;
  }
  else{
    push(&stack,atoi(store[i]));
    printf(" pushed=%d ",atoi(store[i]));
    i++;
  }
}
int sum=0;
while(!isEmpty(stack)){
  printf(" val=%d ",stack->val);
  sum=sum+pop(&stack);
}
printf("\nsum=%d\n",sum);




}
