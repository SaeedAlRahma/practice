class Solution { 
public:
    /**
     * Time: O(n^2)
     * Space O(n)
     */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Graph g;
 
        // Build graph
        g.buildGraph(edges.size(), edges);
        
        // Find redundant connection
        // Implementation: DFS for every edge
        // O(N^2), where n is the number of nodes (= number of edges)
        for(int i=edges.size()-1; i>=0; i--) {
            g.removeEdge(edges[i][0], edges[i][1]); // remove the connection
            if(g.isConnected(edges[i][0], edges[i][1])) // check for another connection between the two nodes
                return edges[i]; // redundant connection
            g.addEdge(edges[i][0], edges[i][1]); // re-add the connection
        }
         
        return edges[0];
    }
    
private:
    struct Node {
        int val;
        unordered_set<int> adj; // used unordered_set for quick insert/remove element
        
        Node(int v=0):val(v),adj(){}
    };
    
    class Graph {
        vector<Node> nodes;
        unordered_set<int> visited;
        
    public:
        void buildGraph(int size, vector<vector<int>> edges) {
        
            for(int i=0; i<=size; i++) {
                Node n;
                n.val = i;
                nodes.push_back(n);
            }
            
            for(int i=0; i<size; i++)
                addEdge(edges[i][0], edges[i][1]);
        }
        
        // add undirected edge
        void addEdge(int u, int v) {
            nodes[u].adj.insert(v);
            nodes[v].adj.insert(u);
        }

        // remove undirected edge
        void removeEdge(int u, int v) {
            nodes[u].adj.erase(v);
            nodes[v].adj.erase(u);
        }
        
        // find connection between two vertices
        bool isConnected(int u, int v) {
            visited.clear();
            return dfs(u, v);
        }
        
        bool dfs(int u, int v) {
            // Base case: found route from u --> v
            if(u == v)
                return true;
            
            // Mark node visited
            visited.insert(u);
            
            // Recursive depth first search
            for(auto it=nodes[u].adj.begin(); it!=nodes[u].adj.end(); it++) {
                // Check if visited
                if(visited.count(*it)>0)
                    continue;
                
                // Check if connection exists
                if (dfs(*it, v))
                    return true;
            }
            
            // no connection found
            return false;
        }
    };    
};