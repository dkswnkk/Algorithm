import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static int mod(int n1,int n2) {
		if(n2==0) return n1;
		else return mod(n2,n1%n2);
	}
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N= Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int A=Integer.parseInt(st.nextToken());
		for(int i=0; i<N-1; i++) {
			int B=Integer.parseInt(st.nextToken());		
			System.out.println(A/mod(A,B)+"/"+B/mod(A,B));
		}
		
	}
}
