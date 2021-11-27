import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		HashMap<Integer, Integer> hash = new HashMap<>();

		for (int i = 0; i < N; i++) {
			int temp = Integer.parseInt(st.nextToken());
			if (hash.containsKey(temp)) {
				hash.replace(temp, hash.get(temp) + 1);
			} else {
				hash.put(temp, 1);
			}
		}

		int M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < M; i++) {
			int temp = Integer.parseInt(st.nextToken());
			if (hash.containsKey(temp)) {
				sb.append(hash.get(temp) + " ");
			} else {
				sb.append("0" + " ");
			}

		}

		System.out.print(sb);
	}
}
