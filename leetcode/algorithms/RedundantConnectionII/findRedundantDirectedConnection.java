class Solution {
    // This class represents a directed graph using adjacency list
    // representation
    class Graph
    {
        private int V;   // No. of vertices
        private LinkedList<Integer> adj[]; //Adjacency Lists
        private int[] numConnections; // num of connections pointing to node

        // Constructor
        Graph(int v)
        {
            V = v;
            adj = new LinkedList[v];
            for (int i=0; i<v; ++i)
                adj[i] = new LinkedList();
            numConnections = new int[v];
        }

        // Function to add an edge into the graph
        void addEdge(int v,int w)
        {
            adj[v].add(w);
            numConnections[w]++;
        }
        
        // Function to remove an edge into the graph
        void removeEdge(int v,int w)
        {
            adj[v].removeFirstOccurrence(w);
            numConnections[w]--;
        }
        
        // Funciton to return number of connections directed towards node
        int getNumConnections(int v) {
            return numConnections[v];
        }

        // prints BFS traversal from a given source s
        boolean BFS(int s)
        {
            // Mark all the vertices as not visited(By default
            // set as false)
            boolean visited[] = new boolean[V];

            // Create a queue for BFS
            LinkedList<Integer> queue = new LinkedList<Integer>();

            // Mark the current node as visited and enqueue it
            visited[s]=true;
            queue.add(s);

            while (queue.size() != 0)
            {
                // Dequeue a vertex from queue and print it
                s = queue.poll();
                //System.out.print(s+" ");

                // Get all adjacent vertices of the dequeued vertex s
                // If a adjacent has not been visited, then mark it
                // visited and enqueue it
                Iterator<Integer> i = adj[s].listIterator();
                while (i.hasNext())
                {
                    int n = i.next();
                    if (!visited[n])
                    {
                        visited[n] = true;
                        queue.add(n);
                    }
                }
            }
            
            for (int i=1; i<V; i++) {
                if (!visited[i]) {// missing node(s)
                    //System.out.println("Missing node " + i);
                    return false;
                }
            }
            
            return true; // all nodes visited (connected tree)
        }
    }
    // This code is contributed by Aakash Hasija
    
    public int[] findRedundantDirectedConnection(int[][] edges) {       
        Graph g = new Graph(edges.length+1);

        // add edges
        for (int i=0; i<edges.length; i++) {
            g.addEdge(edges[i][0], edges[i][1]);
        }

        for (int i=edges.length-1; i>=0; i--) {
            //System.out.println("Removed edge " + i);
            if(g.getNumConnections(edges[i][0]) == 0 && g.getNumConnections(edges[i][1]) == 1) 
                continue; // skip nodes with only one connection
            g.removeEdge(edges[i][0], edges[i][1]);
            for (int j=1; j<edges.length+1; j++) {
                //System.out.println("BFS on " + j);
                if(g.getNumConnections(j) > 0)
                    continue; // Skip if not root
                if(g.BFS(j))
                    return edges[i];
            }
            g.addEdge(edges[i][0], edges[i][1]);
            //System.out.println();
        }
        
        return edges[0];
    }
}
