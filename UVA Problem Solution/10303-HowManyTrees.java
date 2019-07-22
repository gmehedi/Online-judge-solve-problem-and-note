
package pkg10303.how.many.trees;

import java.util.*;
import java.math.BigInteger;

public class HowManyTrees // for uva submit...class Main{.......}
{
    public static BigInteger dp[][]=new BigInteger [2010][1020];
    
    public static BigInteger Bionomial(int n, int k)
    {
        if(n==k || k==0) return BigInteger.valueOf(1);
        if( dp[n][k] != BigInteger.valueOf(-1) ) return dp[n][k];
        
        BigInteger t1=Bionomial(n-1,k-1);
        BigInteger t2=Bionomial(n-1,k);
        return dp[n][k]=t1.add(t2);
    }
    
    public static BigInteger Catalan(int n)
    {
        BigInteger temp=BigInteger.valueOf(n+1);
        BigInteger temp1=Bionomial(2*n,n);
        return temp1.divide(temp);
    }
   
    public static void main(String[] args)
    {
       int n;
       
       for(int i=0; i<2001; i++)
       {
           for(int j=0; j<1001; j++) dp[i][j]=BigInteger.valueOf(-1);
       }
   //    System.out.println(Bionomial(14,9));
       Scanner input = new Scanner(System.in);
       
       while( input.hasNextInt() )
       {
           n=input.nextInt();
           BigInteger res=Catalan(n);
           System.out.println(res);
       }
      
    }
    
    
}
