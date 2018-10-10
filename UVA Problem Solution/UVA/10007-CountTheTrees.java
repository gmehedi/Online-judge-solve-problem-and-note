package pkg10007.count.the.trees;

import java.math.BigInteger;
import java.util.*;
public class CountTheTrees
{
    public static BigInteger fac[]=new BigInteger[350];
     
    public static void Fac()
    {
        fac[0]=BigInteger.ONE;
        for(int i=1; i<=301; i++)
        {
            fac[i]=fac[i-1].multiply(BigInteger.valueOf(i));
        }
    }
    
    public static BigInteger Bionomial(int n, int k)
    {
        if( (n-k)<k)k=n-k;
        BigInteger res=BigInteger.ONE;
        
        for(int i=1; i<=k; i++)
        {
            res=res.multiply(BigInteger.valueOf(n-k+i));
            res=res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    
    public static BigInteger Catalan(int n)
    {
        return Bionomial(2*n,n).divide(BigInteger.valueOf(n+1));
    }
    
    public static void main(String[] args) 
    {
      int n;
      Fac();
      Scanner input= new Scanner(System.in);
      
      while(true)
      {
          n= input.nextInt();
          if(n==0)break;
          BigInteger res=Catalan(n);
          System.out.println(res.multiply(fac[n]));
          
      }
    }
    
}
