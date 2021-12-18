import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
 
public class Main {
    public static Queue<Integer> queue;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        int count = Integer.parseInt(br.readLine());
        
        queue = new LinkedList<Integer>();
        StringBuilder sb = new StringBuilder();
        int back = -1;
        
        while(count-- > 0) {
            st = new StringTokenizer(br.readLine());
            
            String order = st.nextToken();
            
            if("push".equals(order)) {
                back = Integer.parseInt(st.nextToken());
                queue.offer(back);
            }else if("size".equalsIgnoreCase(order)) {
                sb.append(queue.size() + "\n");
            }else if("empty".equals(order)) {
                if(queue.size() == 0) sb.append("1 \n");
                else sb.append("0 \n");
            }else if("pop".equals(order)) {
                if(queue.size() == 0) sb.append("-1 \n");
                else sb.append(queue.poll() + "\n");
                
                if(queue.size() == 0) back = -1;
            }else if("front".equals(order)) {
                if(queue.size() == 0) sb.append("-1 \n");
                else sb.append(queue.peek() + "\n");
            }else if("back".equals(order)) {
                sb.append(back + "\n");
            }
        }
        System.out.println(sb.toString());
    }
}
