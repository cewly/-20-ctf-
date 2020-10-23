#include<iostream>
using namespace std;
int add(int num1,int num2)
{
	int sum1,sum2;
	if (num2==0) return num1;
	sum1=num1^num2;
	sum2=(num1&num2)<<1;
	return add(sum1,sum2);
}
int substract(int num1,int num2)
{
	int comp; 
	comp=add(~num2,1);
	return add(comp,num1);
}
int mulitiply(int num1,int num2)
{
	int bz,sum;
	bz=1;sum=0;
	if (num1<0) 
	{
	   num1=add(~num1,1);
	   bz=bz^1;
    }
	if (num2<0) 
	{
	   num2=add(~num2,1);
	   bz=bz^1;
    }
    while (num1>0)
    {
    	if ((num1 & 0x1)==1) sum=add(sum,num2);
    	num2=num2<<1;
    	num1=num1>>1;
    }
    if (bz==0)  sum=add(~sum,1); 
    return sum;
}
int div(int num1,int num2)
{
	int bz,q,i;
	bz=1;q=0;i=31;
	if (num1<0) 
	{
	   num1=add(~num1,1);
	   bz=bz^1;
    }
	if (num2<0) 
	{
	   num2=add(~num2,1);
	   bz=bz^1;
    }
    for (int i=31;i>=0;i=substract(i,1))
    {
    	if ((num1>>i)>=num2) {
    	q=add(q,1<<i);
    	num1=substract(num1,num2<<i);
    }
    }
    if (bz==0) q=add(~q,1);
    return q;
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<a<<"+"<<b<<"="<<add(a,b)<<endl;
	cout<<a<<"-"<<b<<"="<<substract(a,b)<<endl;
	cout<<a<<"*"<<b<<"="<<mulitiply(a,b)<<endl;
	cout<<a<<"/"<<b<<"="<<div(a,b);
} 
