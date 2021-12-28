import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N;
    static int M;
    static int[] subjects;
    static int[] ans;
    static ArrayList<Integer>[] preceding;
    static Queue<Vertex> queue;
    public static void main(String[] args) throws IOException {
        set();
        solve();

        bw.flush();
        bw.close();
        br.close();
    }

    static void set() throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        subjects = new int[N+1];
        ans = new int[N+1];
        preceding = new ArrayList[N+1];
        queue = new LinkedList<>();
        for(int i=1; i<N+1; i++){
            preceding[i] = new ArrayList<>();
        }
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            preceding[a].add(b);
            subjects[b]++;
        }
    }
    static void solve() throws IOException {
        for(int i=1; i<N+1; i++){
            if(subjects[i] == 0){
                queue.add(new Vertex(i,0));
            }
        }

        while(!queue.isEmpty()){
            Vertex vertex = queue.poll();
            for(int i=0; i<preceding[vertex.x].size(); i++){
                int nv = preceding[vertex.x].get(i);
                subjects[nv]--;

                if(subjects[nv] == 0){
                    ans[nv] = vertex.level+1;
                    queue.add(new Vertex(nv,vertex.level+1));
                }
            }
        }

        for(int i=1; i<N+1; i++){
            bw.write((ans[i]+1) +" ");
        }
    }
}
class Vertex{
    int x, level;

    public Vertex(int x, int level) {
        this.x = x;
        this.level = level;
    }
}
