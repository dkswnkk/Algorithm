import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int arr[] = new int[1000];
		int total = 0;
		double avg = 0;
		int count = 0;
		double answer;
		
		for (int i = 1; i <= N; i++) {
			int A = sc.nextInt();
			count=0;
			total=0;
			for (int j = 0; j < A; j++) {
				arr[j] = sc.nextInt();
				total += arr[j];
			}
			avg =(double)total / A;

			for (int q = 0; q < A; q++) {
				if (arr[q] >avg) {
					count++;
				}
			}

			answer = ((double)count/(double)A * 100);
			System.out.printf("%.3f",answer);
			System.out.println("%");

		}
sc.close();
	}
}
