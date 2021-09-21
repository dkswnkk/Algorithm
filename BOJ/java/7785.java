import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		Map<String, String> hs = new HashMap();
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String A = st.nextToken();
			String B = st.nextToken();
			if (B.equals("leave")) {
				hs.remove(A);
			} else {
				hs.put(A, B);
			}

		}
		TreeMap<String, String> tm = new TreeMap<String, String>(Collections.reverseOrder());
		tm.putAll(hs);
		Iterator<String> it = tm.keySet().iterator();

		while (it.hasNext()) {
			String key = it.next();
			System.out.println(key);
		}

	}

}
