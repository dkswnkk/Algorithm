import java.util.Scanner;
public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int D = sc.nextInt();

		String D1, i1;
		int cnt = 0;

		boolean check[] = new boolean[B + 1];

		check[0] = check[1] = true;

		for (int i = 2; i <= B; i++) {
			if (check[i] == true) {
				continue;
			}
			for (int j = i + i; j <= B; j += i) {
				check[j] = true;
			}
		}

		for (int i = A; i <= B; i++) {
			if (check[i] == false) {
				D1 = String.valueOf(D);
				for (int j = 0; j < D1.length(); j++) {
					i1 = String.valueOf(i);
					if (i1.indexOf(D1) != -1) {
						cnt++;
					}

				}
			}
		}
		System.out.println(cnt);
	}
}
