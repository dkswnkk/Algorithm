package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class _2751 {
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N=Integer.parseInt(br.readLine());
		ArrayList<Integer> arr = new ArrayList<>();
		StringBuilder sb = new StringBuilder();
		while(N-->0) {
			arr.add(Integer.parseInt(br.readLine()));
		}
		Collections.sort(arr);
		for(int i:arr) {
			sb.append(i).append("\n");
		}
		System.out.println(sb);
	}
}
