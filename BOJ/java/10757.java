import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		BigInteger A = sc.nextBigInteger();
		BigInteger B = sc.nextBigInteger();

		System.out.println(A.add(B));
		sc.close();
	}
}
