import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static final int max = 5000;
	static final int max2 = 4000;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		int R = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());

		int sum = R + B;

		for (int i = 1; i <= max; i++) {
			for (int j = 1; j <= max2; j++) {

				if (sum == i * j) {
					if (i * 2 + (j - 2) * 2 == R && (i - 2) * (j - 2) == B) {
						bw.write(j + " " + i);
						bw.flush();
						System.exit(0);
					}

				}
			}
		}

	}
}
