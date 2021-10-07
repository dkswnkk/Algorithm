import java.util.Scanner;
import java.util.Stack;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack st = new Stack();
		String temp;

		int T = sc.nextInt();

		for (int i = 0; i < T; i++) {
			boolean b = false;

			temp = sc.next();

			for (int j = 0; j < temp.length(); j++) {
				if (temp.charAt(j) == '(') {
					st.push(temp.charAt(j));
				} else {
					if (st.isEmpty()) {
						b = true;
						break;
					} else {
						st.pop();
					}
				}
			}

			if (b == false && st.isEmpty()) {
				System.out.println("YES");
				st.clear();
			} else if (b == true || !st.isEmpty()) {
				System.out.println("NO");
				st.clear();
			}

		}

	}
}
