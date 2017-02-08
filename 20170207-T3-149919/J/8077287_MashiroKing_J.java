import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int [] a = new int[10];
		int [] b = new int[10];
		while(in.hasNextInt()){
			int k = in.nextInt(); 
			for(int i = 1; i <= k; i++){
				a[i] = in.nextInt();
			}
			a[k + 1] = 0;
			for(int i = k; i >= 1; i--){
				for(int j = a[i + 1] + 1; j <= a[i]; j++){
					b[j] = i;
				}
			}
			/*System.out.println("================");
			for(int i = 1; i <= 7; i++)
				System.out.print(b[i] + " ");
			System.out.println("");
			*/int n = in.nextInt();
			BigInteger ans = BigInteger.ONE;
			for(int i = 1; i <= k; i++)
				for(int j = 1; j <= a[i]; j++){
					ans = ans.multiply(BigInteger.valueOf(n + j - i));
				}
			for(int i = 1; i <= k; i++)
				for(int j = 1; j <= a[i]; j++){
					ans = ans.divide(BigInteger.valueOf((a[i] - j) + (b[j] - i) + 1));
				}
			System.out.println(ans);
		}
	}
}
