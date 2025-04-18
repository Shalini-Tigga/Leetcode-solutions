import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BellmanFord {
    static class Edge {
        int from, to, weight;

        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }
    private int V;
    private List<Edge> edgeList;
    BellmanFord(int V) {
        this.V = V;
        edgeList = new ArrayList<>();
    }
    public void addEdge(int from, int to, int weight) {
        edgeList.add(new Edge(from, to, weight));
    }
    public void bellmanFord(int src) {
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        // Relax edges V - 1 times
        for (int i = 1; i <= V - 1; i++) {
            for (Edge edge : edgeList) {
                if (dist[edge.from] != Integer.MAX_VALUE &&
                    dist[edge.from] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                }
            }
        }

        // Detect negative cycles
        for (Edge edge : edgeList) {
            if (dist[edge.from] != Integer.MAX_VALUE &&
                dist[edge.from] + edge.weight < dist[edge.to]) {
                System.out.println("Negative weight cycle detected!");
                return;
            }
        }

        // Print distances
        System.out.println("Vertex\tDistance from Source " + src);
        for (int i = 0; i < V; i++) {
            System.out.println(i + "\t\t" + dist[i]);
        }
    }
    public static void main(String[] args) {
        BellmanFord graph=new BellmanFord(6);
        graph.addEdge(0, 1, 2);
        graph.addEdge(0, 3, -4);
        graph.addEdge(1, 2, -3);
        graph.addEdge(2, 3, 5);
        graph.addEdge(3, 4, 6);
        graph.addEdge(4, 5, 3);
        graph.bellmanFord(0);
    }
}
