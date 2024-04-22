#include<iostream>
#include<climits>
#include<omp.h>
using namespace std;
void minreduction(int arr[],int n)
{
    #pragma omp for parallel reduction(min:min_value)
    int min_value=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min_value)
        {
            min_value=arr[i];
        }
    }
    cout<<"\nmin_value"<<min_value;
}
void maxreduction(int arr[],int n)
{
    #pragma omp for parallel reduction(max:max_value)
    int max_value=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max_value)
        {
            max_value=arr[i];
        }
    }
    cout<<"\nmax_value"<<max_value;
}
void sumreduction(int arr[],int n)
{
    #pragma omp for parallel reduction(+:sum)
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    cout<<"\nsum"<<sum;
}
void averagereduction(int arr[],int n)
{
    #pragma omp for parallel reduction(+:sum)
    int sum=0;
    for(int i=0;i<n;i++)
    {
       sum+=arr[i];
    }
    cout<<"\naverage"<<sum/n;
}
int main()
{
    int n;
    cout<<"Enter the total numbers:-";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    minreduction(arr,n);
    maxreduction(arr,n);
    sumreduction(arr,n);
    averagereduction(arr,n);
}
