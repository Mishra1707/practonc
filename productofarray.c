#include<stdio.h>
#include<stdlib.h>
void productArray(int arr[],int n)
 {
    //base case 
    if(n==1){
    printf("0");
    return;  
     }

//allocate memory for temp
int* left= (int*)malloc(sizeof(int)*n);
int* right= (int*)malloc(sizeof(int)*n);
//allocate memmory for product array
int* prod= (int*)malloc(sizeof(int)*n);
int i,j;
//left most element
left[0]=1;
//right most
right[n-1]=1;
//constructing left arr
for(i=1;i<n;i++)
   left[i]=arr[i-1]*left[i-1];
   //right arr
for(j=n-2;j>=0;j--)
 right[j]=arr[j+1]*right[j+1];
//const product arr
for(i=0;i<n;i++)
  prod[i]=left[i]*right[i];
//printing
for(i=0;i<n;i++)
   printf("%d",prod[i]);
return;
}
int main()
{
    int arr[]={8,3,5,10,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("the product array is :\n");
    productArray(arr, n);
    getchar();
    
}   
