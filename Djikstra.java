import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Djikstra {
    static class Edge {
        int to, weight;
        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }
    int V; 
    List<List<Edge>> adjList;
    Djikstra(int V){
        this.V=V;
        adjList=new ArrayList<>();
        for(int i=0;i<V;i++){
            adjList.add(new ArrayList<>());
        }
    }
    void addEdge(int from,int to,int weight){
        adjList.get(from).add(new Edge(to, weight));
    }
    public void dijkstra(int src) {
        int[] dist = new int[V];          // Distance from src to each vertex
        boolean[] visited = new boolean[V]; // Visited array

        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        for (int i = 0; i < V - 1; i++) {
            // Find the unvisited vertex with the smallest distance
            int u = minDistance(dist, visited);
            visited[u] = true;

            // Update distances of neighbors
            for (Edge edge : adjList.get(u)) {
                int v = edge.to;
                int weight = edge.weight;

                if (!visited[v] && dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Print results
        System.out.println("Vertex\tDistance from Source " + src);
        for (int i = 0; i < V; i++) {
            System.out.println(i + "\t\t" + dist[i]);
        }
    }
    private int minDistance(int[] dist, boolean[] visited) {
        int min = Integer.MAX_VALUE;
        int minIndex = -1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] < min) {
                min = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
    }
    public static void main(String[] args) {
        Djikstra graph= new Djikstra(6);
        graph.addEdge(0, 1, 2);
        graph.addEdge(0, 3, -4);
        graph.addEdge(1, 2, -3);
        graph.addEdge(2, 3, 5);
        graph.addEdge(3, 4, 6);
        graph.addEdge(4, 5, 3);
        graph.dijkstra(0);
    }
}
