import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		char[] arr1;
		char[] arr2;
		boolean check = false;

		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			String s1 = sc.next();
			String s2 = sc.next();

			arr1 = s1.toCharArray();
			arr2 = s2.toCharArray();

			Arrays.sort(arr1);
			Arrays.sort(arr2);

			if (Arrays.equals(arr1, arr2)) {
				System.out.println(s1 + " & " + s2 + " are anagrams.");
			} else {
				System.out.println(s1 + " & " + s2 + " are NOT anagrams.");
			}

		}
	}

}
