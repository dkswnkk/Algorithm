import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
		
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String data;
		StringBuilder sb = new StringBuilder();
		// TreeMap 은 key값으로 자동으로 오름차순 정렬된다.
		int T = Integer.parseInt(br.readLine());

		while (T-- > 0) {
			TreeMap<Long, Long> map = new TreeMap<>();
			int K = Integer.parseInt(br.readLine());
			for (int i = 0; i < K; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				data = st.nextToken();
				long temp = Long.parseLong(st.nextToken());
				if (data.equals("I")) {
					if (map.containsKey(temp))
						map.put(temp, map.get(temp) + 1);
					else
						map.put(temp, 1L);
				}
				else if (data.equals("D") && temp == 1) { // 최댓값 삭제
					if (map.isEmpty())
						continue;
					else {
						long maxKey = map.lastKey();
						long next = map.get(maxKey) - 1;
						if (next == 0) {
							map.remove(maxKey);
						} else
							map.put(maxKey, next);
					}
				} else if (data.equals("D") && temp == -1) { // 최솟값 삭제
					if (map.isEmpty())
						continue;
					else {
						long minKey = map.firstKey();
						long next = map.get(minKey) - 1;
						if (next == 0)
							map.remove(minKey);
						else
							map.put(minKey, next);
					}
				}
			}
			if (map.isEmpty())
				sb.append("EMPTY"+"\n");
			else
				sb.append(map.lastKey() +" "+ map.firstKey()+"\n");

		}
		System.out.print(sb);

	}
}
