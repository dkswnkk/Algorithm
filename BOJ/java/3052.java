import java.util.HashSet;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		HashSet s = new HashSet();

		int arr[] = new int[10];

		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt() % 42;

		}
		for (int i = 0; i < arr.length; i++) {
			s.add(arr[i]);
		}
		System.out.println(s.size());
	}
}
