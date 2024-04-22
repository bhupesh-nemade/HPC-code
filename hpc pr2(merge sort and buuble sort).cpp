#include<iostream>
#include<omp.h>
using namespace std;
void parallelbubble(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        #pragma omp parallel for
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void pmergesort(int arr[],int i,int j)
{
    if(i<j)
    {
        int mid=(i+j)/2;
        #pragma omp parallel section
        {
            #pragma omp parallel section
            pmergesort(arr,i,mid);
            #pragma omp parallel section
            pmergesort(arr,mid+1,j);
            
        }
        int temp[100],k=0,left=i,right=mid+1;
        while(left<=mid && right<=j)
        {
            if(arr[left]<arr[right])
            {
                temp[k++]=arr[left++];
            }
            else
            {
                temp[k++]=arr[right++];
            }
        }
        while(left<=mid)
        {
            temp[k++]=arr[left++];
        }
        while(right<=j)
        {
            temp[k++]=arr[right++];
        }
        for(int idx=i,h=0;idx<=j;idx++,h++)
        {
            arr[idx]=temp[h];
        }
    }
}
int main()
{
    int n;
    cout<<"Enter no";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    parallelbubble(arr,n);
     pmergesort(arr,0,n-1);
    cout<<"sorted";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
   
    cout<<"sorted";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}
