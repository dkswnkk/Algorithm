import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int n = sc.nextInt();
			if(n==0) {
				break;
			}
			int sum = 0;
			boolean check[] = new boolean[2 * n + 1];

			check[0] = check[1] = true;

			for (int i = 2; i <= 2 * n; i++) {
				if (check[i] == true) {
					continue;
				}

				for (int j = i + i; j <= 2 * n; j = j + i) {
					check[j] = true;
				}
			}
			for (int i = n + 1; i <= 2 * n; i++) {
				if (check[i] == false) {
					sum++;
				}
			}
			System.out.println(sum);
			sum=0;
		}
	}


}
