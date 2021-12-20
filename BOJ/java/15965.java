import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int K = sc.nextInt();
		boolean check[] = new boolean[10000001];
		int count = 0;

			check[0] = check[1] = true;
			for (int i = 2; i < check.length; i++) {
				if (check[i] == true) {
					continue;
				}
				for (int j = i + i; j < check.length; j += i) {
					check[j] = true;
				}
			}
			for (int i = 0; i < check.length; i++) {
				if (check[i] == false) {
					count++;
				}
				if (K == count) {
					System.out.println(i);
					System.exit(0);
				}
			}

	}
}

