import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String arr[] = new String[100];
		int point = 0;
		int count = 0;

		for (int i = 0; i < N; i++) {
			arr[i] = sc.next();
			for (int j = 0; j < arr[i].length(); j++) {
				if (arr[i].charAt(j) == 'O') {
					count++;
					point += count;
				} else
					count = 0;

			}
			System.out.println(point);
			point = 0;
			count = 0;
		}
		sc.close();
	}
}
