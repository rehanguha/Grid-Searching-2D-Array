#include<iostream>

using namespace std;

#define MAX 4

int f_i,f_j;


int check(int arr[MAX][MAX],int i,int j,int num,int n=MAX)
{
	if(((i>=0) && (i<n))&&((j>=0) && (j<n)) && arr[i][j]==num)
	{
		return 1;
	}
	return 0;
}

int range(int n)
{
    int t;
    if(n%3==1)
    {
        t=((n+2)/3);
    }
    else if(n%3==2)
    {
        t=((n+1)/3);
    }
    else
        t=((n)/3);
    return t*t;
}
int grid_search(int arr[MAX][MAX],int NUM,int n=MAX)
{
    int flag=0;
    int t=range(n);
    cout<<t;
    for(int i=1;i<=t;i=i+3)
    {
        for(int j=1;j<=t;j=j+3)
        {
        	cout<<"\n"<<i<<"-"<<j;
            if(check(arr,i-1,j-1,NUM))
            {
                flag=1;
                f_i=i-1;
                f_j=j-1;
                return 1;
            }
            if(check(arr,i-1,j,NUM))
            {
                flag=1;
                f_i=i-1;
                f_j=j;
                return 1;
            }
            if(check(arr,i,j-1,NUM))
            {
                flag=1;
                f_i=i;
                f_j=j-1;
                return 1;
            }
            if(check(arr,i-1,j+1,NUM))
            {
                flag=1;
                f_i=i-1;
                f_j=j+1;
                return 1;
            }
            if(check(arr,i,j,NUM))
            {
                flag=1;
                f_i=i;
                f_j=j;
                return 1;
            }
            if(check(arr,i,j+1,NUM))
            {
                flag=1;
                f_i=i;
                f_j=j+1;
                return 1;
            }
            if(check(arr,i+1,j-1,NUM))
            {
                flag=1;
                f_i=i+1;
                f_j=j-1;
                return 1;
            }
            if(check(arr,i+1,j,NUM))
            {
                flag=1;
                f_i=i+1;
                f_j=j;
                return 1;
            }
            if(check(arr,i+1,j+1,NUM))
            {
                flag=1;
                f_i=i+1;
                f_j=j+1;
                return 1;
            }
        }
    }
    if(flag == 0)
    {
        return 0;
    }
}

int main()
{
    int arr[MAX][MAX]={{71,2,3,84},{5,66,7,8},{9,180,11,182},{413,3414,515,126}};
    int num;
    cout<<"Enter no.:";
    cin>>num;
    cout<<"\nResult:\n";
    if(grid_search(arr,num))
    {
    	
        cout<<"\n"<<f_i<<"\t"<<f_j;
    }
    else
        cout<<"\nNOT FOUND";
    return 0;    
}
