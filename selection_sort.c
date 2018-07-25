#include<stdio.h>
int min_index(int a[],int size){
	int i,min=0;
	for(i=0;i<size;i++){
		if(a[i]<a[min]){
			min=i;
		}
	}
	return min;
}
void selection_sort(int a[],int size){
	if(size==1)
	return;
	int x;
	x=min_index(a,size);
	int y=a[x];
	a[x]=a[0];
	a[0]=y;
	selection_sort(a+1,size-1);
}


int main(){
	int i,size;
	scanf("%d",&size);
	int a[size];
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	selection_sort(a,size);
	for(i=0;i<size;i++){
		printf("%d",a[i]);
	}
}

