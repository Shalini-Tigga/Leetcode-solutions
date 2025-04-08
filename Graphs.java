import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Graphs {
    int [][] adjacencyMatrix;
    int numVertices;
    boolean[] visited;
    
    Graphs(int numVertices){
        this.numVertices = numVertices;
        adjacencyMatrix = new int[numVertices][numVertices];
        visited = new boolean[numVertices];
        
        for (int i = 0; i < numVertices; i++) {
            adjacencyMatrix[i][i] = 1;
        }
    }

    void addEdge(int src, int dest) {
        if ((src >= 0 && src < numVertices) && (dest >= 0 && dest < numVertices)) {
            adjacencyMatrix[src][dest] = 1;
            adjacencyMatrix[dest][src] = 1;
        }
    }

    void removeEdge(int src, int dest) {
        if ((src >= 0 && src < numVertices) && (dest >= 0 && dest < numVertices)) {
            adjacencyMatrix[src][dest] = 0;
            adjacencyMatrix[dest][src] = 0;
        }
    }

    void printGraph() {
        for (int[] row : adjacencyMatrix) {
            System.out.println(Arrays.toString(row));
        }
    }

    void dfs(int vertex) { // O(V^2)
        visited[vertex] = true;
        System.out.print(vertex + " ");
        for (int i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
                dfs(i);
            }
        }
    }

    void dfsIterative(int startVertex) {
        boolean[] visitedIterative = new boolean[numVertices]; 
        Stack<Integer> stack = new Stack<>();
        stack.push(startVertex);
        
        while (!stack.isEmpty()) {
            int vertex = stack.pop();
            if (!visitedIterative[vertex]) {
                visitedIterative[vertex] = true;
                System.out.print(vertex + " ");
            }
            for (int i = numVertices - 1; i >= 0; i--) {
                if (adjacencyMatrix[vertex][i] == 1 && !visitedIterative[i]) {
                    stack.push(i);
                }
            }
        }
    }

    void bfs(int start) {
        boolean[] visitedBFS = new boolean[numVertices]; 
        Queue<Integer> queue = new LinkedList<>();
        visitedBFS[start] = true;
        queue.add(start);
        
        System.out.print("BFS: ");
        
        while (!queue.isEmpty()) {
            int v = queue.poll();
            System.out.print(v + " ");
            for (int i = 0; i < numVertices; i++) {
                if (adjacencyMatrix[v][i] == 1 && !visitedBFS[i]) {
                    visitedBFS[i] = true;
                    queue.add(i);
                }
            }
        }
        System.out.println();
    }

    public static void main(String args[]) {
        Graphs graph = new Graphs(4);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        
        graph.printGraph();
        
        // Performing DFS
        graph.dfs(0);
        System.out.println();
        
        // Performing Iterative DFS
        graph.dfsIterative(0);
        System.out.println();
        
        // Performing BFS
        graph.bfs(0);
    }
}
