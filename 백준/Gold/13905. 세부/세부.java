import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int S, E;
    static int[] parent;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stk = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stk.nextToken());
        M = Integer.parseInt(stk.nextToken());

        parent = new int[N + 1];
        for (int i = 1; i < N + 1; i++) {
            parent[i] = i;
        }

        stk = new StringTokenizer(br.readLine());
        S = Integer.parseInt(stk.nextToken());
        E = Integer.parseInt(stk.nextToken());

        List<Edge> edges = new ArrayList<>();
        int h1, h2, k;
        for (int i = 0; i < M; i++) {
            stk = new StringTokenizer(br.readLine());
            h1 = Integer.parseInt(stk.nextToken());
            h2 = Integer.parseInt(stk.nextToken());
            k = Integer.parseInt(stk.nextToken());
            edges.add(new Edge(h1, h2, k));
        }
        
        Collections.sort(edges);

        for (Edge e : edges) {
            int ph1 = findParent(e.h1);
            int ph2 = findParent(e.h2);

            if (ph1 == ph2) {
                continue;
            }
            if (ph1 < ph2) {
                parent[ph2] = ph1;
            } else {
                parent[ph1] = ph2;
            }
            if (findParent(S) == findParent(E)) {
                System.out.println(e.k);
                return;
            }
        }
        
        System.out.println(0);
    }

    static int findParent(int target) {
        if (parent[target] == target) {
            return target;
        } else {
            return parent[target] = findParent(parent[target]);
        }
    }

    static class Edge implements Comparable<Edge> {

        int h1;
        int h2;
        int k;

        Edge() {
        }

        Edge(int h1, int h2, int k) {
            this.h1 = h1;
            this.h2 = h2;
            this.k = k;
        }

        @Override
        public int compareTo(Edge e) {
            return e.k - this.k;
        }
    }
}