import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static long gcd(long n1,long n2) {
		if(n2==0) return n1;
		else return gcd(n2,n1%n2);
	}

	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n=Integer.parseInt(br.readLine());
		while(n-->0) {
		StringTokenizer st = new StringTokenizer(br.readLine());
		long A=Long.parseLong(st.nextToken());
		long B=Long.parseLong(st.nextToken());
		System.out.println(A*B/gcd(A,B));
	}
}
}
