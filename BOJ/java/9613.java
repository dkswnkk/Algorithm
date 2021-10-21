import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static int GCD(int a,int b) {
		if (b==0) return a;
		else return GCD(b,a%b);
	}
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n= Integer.parseInt(br.readLine());
		
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int t=Integer.parseInt(st.nextToken());
			int arr[]= new int [t];
			for(int i=0; i<t; i++) {
				arr[i]=Integer.parseInt(st.nextToken());			
			}
			long sum=0;
			for(int i=0; i<arr.length; i++) {
				for(int j=0; j<i; j++)
				sum+=GCD(arr[i],arr[j]);				
			}
			System.out.println(sum);
		}
		
 }
}
