import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String[] n = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
		String s = sc.nextLine();

		for (int i = 0; i < n.length; i++) {
			s = s.replaceAll(n[i], "x");
		}
		System.out.println(s.length());
	}
}
