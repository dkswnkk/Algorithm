import java.util.Scanner;
import java.util.Stack;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int sum = 0;
		int k = sc.nextInt();
		Stack<Integer> stack = new Stack<>();

		for (int i = 0; i < k; i++) {
			int input = sc.nextInt();
			if (input == 0) {
				stack.pop();
			} else {
				stack.push(input);
			}
		}
		for (int i = 0; i < stack.size(); i++) {
			sum += stack.get(i);
		}
		System.out.println(sum);
	}
}
