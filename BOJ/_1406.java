package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class _1406 {

	static String tmp1;
	static String tmp2;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb= new StringBuilder();
		Stack lStack = new Stack();
		Stack rStack = new Stack();
		String s = br.readLine();
		for (int i = 0; i < s.length(); i++) {
			lStack.push(s.charAt(i));
		}
		int m = Integer.parseInt(br.readLine());
		for (int i = 0; i < m; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			if (st.countTokens() == 2) {
				tmp1 = st.nextToken();
				tmp2 = st.nextToken();
			} else {
				tmp1 = st.nextToken();
			}
			if (tmp1.equals("L")) {
				if (!lStack.isEmpty())
					rStack.push(lStack.pop());
			}   
			if (tmp1.equals("D")) {
				if (!rStack.isEmpty())
					lStack.push(rStack.pop());
			}

			if (tmp1.equals("B")) {
				if (!lStack.isEmpty())
					lStack.pop();

			}
			if (tmp1.equals("P")) {
				lStack.push(tmp2);
			}
		}
		while (!lStack.empty()) {
			rStack.push(lStack.pop());
		}

		while (!rStack.isEmpty()) {
			sb.append(rStack.pop());
		}
		System.out.print(sb);
	}
}
