import java.util.Scanner;
import java.util.StringTokenizer;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String S = sc.nextLine();
		StringTokenizer st = new StringTokenizer(S, "-");
		int cnt = st.countTokens();

		String arr[] = new String[cnt];

		for (int i = 0; i < arr.length; i++) {
			arr[i] = st.nextToken();
		}
		for (int i = 0; i < arr.length; i++) {
			for (char j = 'A' - 0; j <= 'Z'; j++) {
				if (arr[i].indexOf(j) != -1) {
					System.out.print(j);
				}
			}
		}

	}
}
