import java.util.Scanner;
import java.util.Stack;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack st = new Stack();
		String s;
		char c;
		int count = 0;
		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			st.clear();
			s = sc.next();
			for (int j = 0; j < s.length(); j++) {
				c = s.charAt(j);
				if (c == 'A') {
					if (!st.isEmpty() && st.peek().equals('A')) {
						st.pop();
					} else {
						st.push('A');
					}
				}
				else if (c == 'B') {
					if (!st.isEmpty() && st.peek().equals('B')) {
						st.pop();
					} else {
						st.push('B');
					}
				}
			}
			if (st.isEmpty() == true) {
				count++;
			}
		}
		System.out.println(count);
	}
}
