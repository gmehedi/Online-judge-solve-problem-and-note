
package pkg10497.uva.sweet.child.makes.trouble;

import java.math.BigInteger;
import java.util.*;

public class UvaSweetChildMakesTrouble 
{
    public static BigInteger dp[][]=new BigInteger[830][830];
    public static BigInteger dpb[][]=new BigInteger[830][830];
     
    public static BigInteger Bionomial(int n, int k)
    {
        if(n == k || k == 0) return BigInteger.valueOf(1);
        int check = dpb[n][k].compareTo(BigInteger.valueOf(-1));
        if(check != 0) return dp[n][k];
        
        return dpb[n][k] = Bionomial(n-1,k-1).add( Bionomial(n-1,k) );
    }
    
    public static BigInteger  Subfactorial(int n, int k)
    {
        if(n == 0 && k == 0) return BigInteger.ONE;
        if(n == 1 && k == 0) return BigInteger.ZERO;
        int check = dp[n][k].compareTo(BigInteger.valueOf(-1));
        if(check != 0) return dp[n][k];
        
        if(n>1 && k == 0)
        {
            return dp[n][k] = BigInteger.valueOf(n-1).multiply( Subfactorial(n-1,k).add( Subfactorial(n-2,k)) );
        }
        
        
        return dp[n][k] = dpb[n][k].multiply( Subfactorial(n-k,k) ); 
    }

    
    public static void main(String[] args) 
    {
      int n;
      Scanner input= new Scanner(System.in);
      
      for(int i=0; i<=810; i++)
      {
          for(int j=0; j<=810; j++)
          {
              dp[i][j]=BigInteger.valueOf(-1);
              dpb[i][j]=BigInteger.valueOf(-1);
          }
      }
      
      Bionomial(801,0);
      
      while( input.hasNextInt() )
      {
          n= input.nextInt();
          if(n == -1) break;
          System.out.println( Subfactorial(n,0));       
      }
      
    }
    
}