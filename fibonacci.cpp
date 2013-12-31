/*This file implements printing the nth fibonacci number*/

#include<iostream>
#include<map>
#include <ctime>
using namespace std;

int slowfib(int n)
{
    if(n==0)    return 0;
    else    if(n==1)    return 1;
    return slowfib(n-1)+slowfib(n-2);
}
int fastfib(int n)
{
    static map<unsigned int, unsigned int> mapfib;
    if(mapfib.count(n)>0)   return mapfib[n];
    if(n==0) return 0 ; else if(n == 1) return 1;
    int ret = fastfib(n-1)+fastfib(n-2);
    mapfib[n]=ret;
    return ret;
}
int main()
{
    cout<<"Please input the index of the fibonacci number you want ?";
    int n;
    cin>>n;
    clock_t begin = clock();
    cout<<"The "<<n<<"th fibonacci number  through slow fn is "<< slowfib(n)<<"\n";
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"Time elapsed for slow function "<<elapsed_secs<<"\n";
    begin = clock();
    cout<<"The "<<n<<"th fibonacci number through fast fn is "<< fastfib(n)<<"\n";
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"Time elapsed for fast function"<<elapsed_secs<<"\n";
    return 0;
}
