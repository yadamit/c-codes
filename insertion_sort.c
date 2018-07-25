#include<stdio.h>

void insertion_sort(int a[],int size){
	if(size==1){
		printf("%d",a[0]);
		return;
	}
	int i=0;
	//int b[]=a;
	for(i=0;i<size;i++){
		int j=i-1;
		while(j>=-1){
			if((a[j]>=a[i])&&(j!=-1)){
				j--;
				
				
			}
			

			else{
				int z,x=a[i];
				for(z=i;z>j+1;z--){
					a[z]=a[z-1];
				}
				a[j+1]=x;
				break;
			}
			
		}
	}
	for(i=0;i<size;i++){
		printf("%d  ",a[i]);
	}	


}

int main(){
	int size;
	scanf("%d",&size);
	int a[size],i;
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	
	insertion_sort(a,size);
	
	return 0;
}



/*
3,1,2,4,6,5
3,1,2,4,6,5
1,3,2,4,6,5
1,2,3,4,6,5
*/
