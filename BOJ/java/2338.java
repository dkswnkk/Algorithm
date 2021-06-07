package baekjoon;

import java.math.BigInteger;
import java.util.Scanner;

public class _2338 {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		BigInteger A = sc.nextBigInteger();
		BigInteger B= sc.nextBigInteger();
	
		sb.append(A.add(B)+"\n").append(A.subtract(B)+"\n").append(A.multiply(B));
		System.out.print(sb);
	}
}
