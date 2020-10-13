/*
* @ author: micro_han
* @ email: yxh.op@qq.com
* @ data: 2020-10-12 14:50
*/

/*
欧拉函数
a ^ b = a ^ ( b % phi(p))           gcd(a,p) = 1
a ^ b = a ^ b % p                   gcd(a,p) != 1  &&  b < phi(p)
a ^ b = a ^ (b % phi(p) + phi(p))   gcd(a,p) != 1 && b>=phi(p)

*/


ll phi(ll n)   //单个欧拉函数值 
{  
    int ans=n,temp=n;  
    for(int i=2;i*i<=temp;i++)   
    {  
        if(temp%i==0)   
        {  
            ans-=ans/i;  
            while(temp%i== 0) temp/=i;  
        }  
    }  
    if(temp>1) ans-=ans/temp;  
    return ans;  
}  


int euler()	//n log n  
{
	for(int i=1;i<=1000000;i++)
	{
		phi[i]=i;
	}
	for(int i=2;i<=1000000;i++)
	{
		if(i==phi[i]) //判断如果i是素数 
		{
			for(int j=i;j<=1000000;j+=i)
			{
			    phi[j]=(phi[j]/i)*(i-1);//i是素数并且是j的一个因子，正好满足欧拉函数。 
			}
		}
	}
}