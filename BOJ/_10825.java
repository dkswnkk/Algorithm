package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class _10825 {
	public static void main(String[]args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String [][]arr = new String [N][4];

		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			arr[i][0]=st.nextToken();
			arr[i][1]=st.nextToken();
			arr[i][2]=st.nextToken();
			arr[i][3]=st.nextToken();
		}
		Arrays.sort(arr,new Comparator<String[]>(){
			public int compare(String[]o1,String[]o2) {
				int A=Integer.compare(Integer.parseInt(o1[1]), Integer.parseInt(o2[1]));
				if(A>0) return -1;
				else if(A==0) {
					int B=Integer.compare(Integer.parseInt(o1[2]), Integer.parseInt(o2[2]));
					if(B<0) return -1;
				else if(B==0) {
					int C=Integer.compare(Integer.parseInt(o1[3]), Integer.parseInt(o2[3]));
					if(C>0) return -1;
				else if(C==0) return o1[0].compareTo(o2[0]);
				}
				}
				return 1;
			}
	});

		for(int i=0; i<N; i++) {
			System.out.println(arr[i][0]);
		}
		
}
}
