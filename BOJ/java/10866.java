import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Deque dq = new LinkedList();

		int cnt = sc.nextInt();

		for (int i = 0; i < cnt; i++) {
			String s = sc.next();
			if (s.equals("push_back")) {
				dq.addLast(sc.nextInt());

			} else if (s.equals("push_front")) {
				dq.addFirst(sc.nextInt());
			} else if (s.equals("pop_front")) {
				if (dq.isEmpty()) {
					System.out.println(-1);
				} else {
					System.out.println(dq.pop());
				}

			} else if (s.equals("pop_back")) {
				if (dq.isEmpty()) {
					System.out.println(-1);
				} else {
					System.out.println(dq.removeLast());
				}

			} else if (s.equals("size")) {
				System.out.println(dq.size());
			} else if (s.equals("empty")) {
				if (dq.isEmpty()) {
					System.out.println(1);
				} else {
					System.out.println(0);
				}

			} else if (s.equals("front")) {
				if (dq.isEmpty()) {
					System.out.println(-1);
				} else {
					System.out.println(dq.peek());
				}
			} else if (s.equals("back")) {
				if (dq.isEmpty()) {
					System.out.println(-1);
				} else {
					System.out.println(dq.peekLast());
				}

			}


		}

	}
}
