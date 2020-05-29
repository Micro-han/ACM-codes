import java.math.*;
import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(System.in);
		BigInteger []m=new BigInteger[200];
		m[0]=BigInteger.valueOf(4);
		m[1]=BigInteger.valueOf(14);
		for(int i=2;i<180;i++)
			m[i]=m[i-1].multiply(BigInteger.valueOf(4)).subtract(m[i-2]);
		//a.add(),a.subtract(),a.multiply(),a.divide()zhengchu,a.remainder()quyu,a.pow()mi,a.compareTo()bijiao
		int t;
		t=input.nextInt();
		for(int i=0;i<t;i++) {
			BigInteger N;
			N=input.nextBigInteger();
			for(int j=0;j<180;j++) {
				if(m[j].compareTo(N)>=0) {
					System.out.println(m[j]);
					break;
				}
			}
				
		}

	}

}