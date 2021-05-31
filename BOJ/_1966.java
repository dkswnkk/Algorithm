package baekjoon;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

 class Document{
	int index;
	int priority;
	
	public Document(int index,int priority) {
		this.index=index;
		this.priority=priority;
	}
}

public class _1966 {
	
	
	
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		Queue q= new LinkedList();
		LinkedList <Integer> L= new LinkedList<Integer>();
		
		int testCase = sc.nextInt();
		
		for(int i=0; i<testCase; i++) {
			
			int N=sc.nextInt(); 
			int M=sc.nextInt(); 
				for(int j=1; j<=N; j++) {
					L.add(sc.nextInt());
					q.add(i);						
				}
				for(int k=0; k<N; k++) {
					if(L.get(k)>L.get(k+1)){
							q.add(q.poll());
					}
				}
				
			
			
		}
		
		
	}
}
