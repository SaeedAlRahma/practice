class Solution {
    // This class represents a directed graph using adjacency list
    // representation
    class Graph
    {
        private int V;   // No. of vertices

        // Array  of lists for Adjacency List Representation
        private LinkedList<Integer> adj[];

        // Constructor
        Graph(int v)
        {
            V = v;
            adj = new LinkedList[v];
            for (int i=0; i<v; ++i)
                adj[i] = new LinkedList();
        }

        //Function to add an edge into the graph
        void addEdge(int v, int w)
        {
            adj[v].add(w);  // Add w to v's list.
            adj[w].add(v);
        }

        //Function to remove an edge from the graph
        void removeEdge(int v, int w)
        {
            adj[v].removeFirstOccurrence(w);  // Add w to v's list.
            adj[w].removeFirstOccurrence(v);
        }

        // A function used by DFS
        boolean DFSUtil(int v, int target, boolean visited[])
        {
            if (v == target)
                return true;
            
            // Mark the current node as visited and print it
            visited[v] = true;
            //System.out.print(v+" ");

            // Recur for all the vertices adjacent to this vertex
            Iterator<Integer> i = adj[v].listIterator();
            while (i.hasNext())
            {
                int n = i.next();
                if (!visited[n])
                    if (DFSUtil(n, target, visited))
                        return true;
            }
            
            return false; // no connection found
        }

        // The function to do DFS traversal. It uses recursive DFSUtil()
        boolean DFS(int v, int target)
        {
            // Mark all the vertices as not visited(set as
            // false by default in java)
            boolean visited[] = new boolean[V];

            // Call the recursive helper function to print DFS traversal
            return DFSUtil(v, target, visited);
        }
    }
    // This code is contributed by Aakash Hasija
    
    public int[] findRedundantConnection(int[][] edges) {
        Graph g = new Graph(edges.length+1);

        // add edges
        for (int i=0; i<edges.length; i++) {
            g.addEdge(edges[i][0], edges[i][1]);
            //g.addEdge(edges[i][1], edges[i][0]);
        }

        for (int i=edges.length-1; i>=0; i--) {
            //System.out.println("Removed edge " + i);
            g.removeEdge(edges[i][0], edges[i][1]);
            if(g.DFS(edges[i][0], edges[i][1]))
                return edges[i];
            g.addEdge(edges[i][0], edges[i][1]);
            //System.out.println();
        }
        
        return edges[0];
    }
}
