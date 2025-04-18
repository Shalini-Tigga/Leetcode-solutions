
import java.util.ArrayList;
import java.util.List;

public class WeightedAdjList {
    static class Edge{
        int to;
        int weight;
        Edge(int to,int weight){
            this.to=to;
            this.weight=weight;
        }
    }
    int V;
    List<List<Edge>> adjList;

    public WeightedAdjList(int V) {
        this.V=V;
        adjList=new ArrayList<>();
        for(int i=0;i<V;i++){
            adjList.add(new ArrayList<>());
        }
    }
    void addEdge(int from,int to,int weight){
        adjList.get(from).add(new Edge(to, weight));
    }
    void printGraph() {
        for (int i = 0; i < V; i++) {
            System.out.print("Vertex " + i + ":");
            for (Edge edge : adjList.get(i)) {
                System.out.print(" -> " + edge.to + "(w:" + edge.weight + ")");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        WeightedAdjList graph=new WeightedAdjList(6);
        graph.addEdge(0, 1, 2);
        graph.addEdge(0, 3, -4);
        graph.addEdge(1, 2, -3);
        graph.addEdge(2, 3, 5);
        graph.addEdge(3, 4, 6);
        graph.addEdge(4, 5, 3);
        graph.printGraph();
    }
}
