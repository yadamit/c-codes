#include<stdio.h>
int min(int a,int b){
	if(a<=b)
		return a;
	else
		return b;
}
 int* merge(int* a,int x,int* b,int y){
	int c[x+y];
	int i=0,j=0,k=0;
	/*for(i=0;i<x+y;i++){
		printf("\n%d",a[i]);
	}*/
	//i=0;
	while(i!=x||j!=y){
		if(i<x&&j<y){
			if(a[i]<=b[j]){
				c[k]=a[i];
				i++;
			}
			else{
				c[k]=b[j];
				j++;
			}

			k++;
		}
		else if(i==x){
			c[k]=b[j];
			k++;j++;
		}
		else if(j==y){
			c[k]=a[i];
			k++;i++;
		}
	}
	a=c;
	for(i=0;i<x+y;i++){
		printf("%d",a[i]);
	}
	printf("\n\n");
	return a;
}
int* merge_sort(int a[],int size){
	if(size==1)
		return a;
	int b[size];
	if(size%2==0){
		int* x=merge_sort(a,size/2);
		int* y=merge_sort(a+size/2,size/2);
		a=merge(x,size/2,y,size/2);
	}
	int i;
	for(i=0;i<size;i++){
		printf("\n%d",a[i]);
	}
	printf("\n\n\n\n");
	return a;
}


int main(){
	int size;
	scanf("%d",&size);
	int i, a[size];
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	int b[]={3,2};
	int* x=a;
	int* y=b;
	int* c=merge_sort(a,size);
	for(i=0;i<size;i++){
		printf("\n%d",c[i]);
	}



}
