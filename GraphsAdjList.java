import java.util.*;

class GraphsAdjList {
    private int V; 
    private List<Integer>[] adjList; 

    public GraphsAdjList(int V) {
        this.V = V;
        adjList = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            adjList[i] = new ArrayList<>();
        }
    }

    public void addEdge(int src, int dest) {
        adjList[src].add(dest);
        adjList[dest].add(src); 
    }

    public void dfsIterative(int start) { // O(V+E)
        boolean[] visited = new boolean[V];
        Stack<Integer> stack = new Stack<>();
        stack.push(start);

        System.out.print("DFS: ");

        while (!stack.isEmpty()) {
            int v = stack.pop();

            if (!visited[v]) {
                System.out.print(v + " ");
                visited[v] = true;

                List<Integer> neighbors = adjList[v];
                Collections.reverse(neighbors); 
                for (int neighbor : neighbors) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }
        System.out.println();
    }
    public void bfs(int start) {  // O(V+E)
        boolean[] visited = new boolean[V]; 
        Queue<Integer> queue = new LinkedList<>(); 
        visited[start] = true;
        queue.add(start); 

        System.out.print("BFS: ");
        
        while (!queue.isEmpty()) {
            int v = queue.poll(); 

            System.out.print(v + " "); 

            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        GraphsAdjList graph = new GraphsAdjList(4);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        
        graph.dfsIterative(0);
        graph.bfs(0);
    }
}
