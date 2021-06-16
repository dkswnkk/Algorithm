import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			int a = sc.nextInt();
			String S = sc.next();

			for (int j = 0; j < S.length(); j++) { // 3
				for (int k = 0; k < a; k++) {
					System.out.print(S.charAt(j));
				}
			}
			System.out.println();
		}

	}
}
