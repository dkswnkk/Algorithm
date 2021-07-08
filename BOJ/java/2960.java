import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int K = sc.nextInt();
		boolean arr[]=new boolean[N+1];
		
		int count=0;
		
		for(int i=2; i<=N; i++) {
			for(int j=i; j<=N; j+=i) {
				if(arr[j]==false) {
					count++;
					arr[j]=true;
				}
				if(count==K) {
					System.out.println(j);
					System.exit(0);
				}
			}
		}

	}
	
		}



