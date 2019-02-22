#include<iostream>

int f_i,f_j;

int linear_search(int arr[3][3],int NUM,int n=3)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j] == NUM)
            {
                flag=1;
                f_i=i;
                f_j=j;
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
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int num;
    std::cin>>num;
    if(linear_search(arr,num))
    {
        std::cout<<"\n"<<f_i<<"\t"<<f_j;
    }
    else
        std::cout<<"\nNOT FOUND";
    return 0;    
}
