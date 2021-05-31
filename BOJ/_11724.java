package baekjoon;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class _11724 {
	static int N;
	static int M;  
	static int check[][]; 
	static boolean checked[]; 
	static int cnt;
	
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		
		check=new int[N+1][N+1];
		checked=new boolean[N+1];
		
		for(int i=0; i<M; i++) {
			int A=sc.nextInt();
			int B=sc.nextInt();
			check[A][B]=check[B][A]=1;
		}

		for(int i=1; i<=N; i++) {
			if(checked[i]==false) {
				bfs(i);
				cnt++;
			}
		}
		System.out.print(cnt);
	}
	public static void bfs(int n) {
		Queue<Integer> q= new LinkedList<Integer>();
		q.offer(n);
		checked[n]=true;
		
		while(!q.isEmpty()) {
			int temp=q.poll();
		for(int i=1; i<=N;i++) {
			if(check[temp][i]==1&&checked[i]==false) {
				q.offer(i);
				checked[i]=true;
			}
		}
		
		}
		}
	
}
