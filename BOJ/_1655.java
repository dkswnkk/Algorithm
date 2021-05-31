package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class _1655 {
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N= Integer.parseInt(br.readLine());
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		
//		while(N-->0) {
//			pq.add(Integer.parseInt(br.readLine()));
//			System.out.println(pq.get(N));
//		}

		for(int i=0; i<N; i++) {
			pq.add(Integer.parseInt(br.readLine()));
			System.out.println(pq.peek());
		}
		
	}
}
