import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt(); // 낮에 올라가는 길이
		int B = sc.nextInt(); // 밤에 잘때 떨어지는 길이
		int V = sc.nextInt(); // 나무막대 높이

		int day = (V - B) / (A - B);

		if ((V - B) % (A - B) != 0) {
			day++;
		}
		System.out.println(day);

	}
}
