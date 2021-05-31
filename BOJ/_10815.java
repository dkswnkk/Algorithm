package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class _10815 {

	public static int Search(int arrN[], int N, int search) {
		int indexFirst = 0;
		int indexLast = N - 1;
		int indexMid = 0;

		while (indexFirst <= indexLast) {
			indexMid = (indexFirst + indexLast) / 2; // 중간 인덱스

			if (arrN[indexMid] == search) { // 중간값과 찾으려는 수가 같은 경우
				return 1;
			}
			if (arrN[indexMid] < search) { // 중간값이 찾으려는 수보다 작으면,그 이하의 수는 볼필요x
				indexFirst = indexMid + 1;
			} else {// 중간값이 찾으려는 수보다 크면, 그 이상으로는 볼 필요 x
				indexLast = indexMid - 1;
			}
		}
		return 0;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		int arrN[] = new int[N];

		for (int i = 0; i < N; i++) {
			arrN[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arrN);
		int M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < M; i++) {
			int m = Integer.parseInt(st.nextToken());
			sb.append(Search(arrN, N, m) + " ");
		}

		System.out.println(sb);

	}
}

/*

package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class test1 {


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		int arrN[] = new int[N];

		for (int i = 0; i < N; i++) {
			arrN[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arrN);
		int M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < M; i++) {
			int m = Integer.parseInt(st.nextToken());
			int index=Arrays.binarySearch(arrN, m);
			if(index>=0) 
			sb.append(1+" ");			
			else
			sb.append(0+" ");

	}
		System.out.println(sb);
}
}
*/