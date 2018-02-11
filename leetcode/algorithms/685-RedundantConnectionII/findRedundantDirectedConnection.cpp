class Solution {
public:
    /**
     * Time O(n)
     * Space O(n)
     */
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // Build graph
        Graph g;
        g.buildGraph(edges.size(), edges);
        
        // Case 1: One vertex has two parents
        // Implementation: graph traversal
        // O(N), where N is the number of nodes
        if(g.candidatesSize() > 0)
            return g.redundantCandidate();
        
        // Case 2: Every vertex has one parent (cycle)
        // Implementation: loop over edges
        // O(N), where N is the number of edges
        return g.lastCycleEdge(edges);
    }
    
    
private:
    struct Node {
        int val;
        unordered_set<int> adj; // used unordered_set for quick insert/remove element
        vector<int> parentEdge; // track the parent node
        
        Node(int v=0):val(v),adj(){}
    };
    
    class Graph {
        vector<Node> nodes;
        unordered_set<int> visited;
        vector<vector<int>> candidates;
        
    public:
        void buildGraph(int size, vector<vector<int>> edges) {
        
            for(int i=0; i<=size; i++) {
                Node n;
                n.val = i;
                nodes.push_back(n);
            }
            
            for(int i=0; i<size; i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                if (nodes[v].parentEdge.size() == 0) { // first parent
                    nodes[v].parentEdge = edges[i];
                    addEdge(u, v); // only add first edge, test second edge
                }
                else { // EITHER one node only with two parents OR no node with two parents
                    candidates.push_back(nodes[v].parentEdge); // last edge
                    candidates.push_back(edges[i]); // current edge
                }
            }
                
        }
 
        void addEdge(int u, int v) {
            nodes[u].adj.insert(v);
        }

        void removeEdge(int u, int v) {
            nodes[u].adj.erase(v);
        }
        
        int candidatesSize() {
            return candidates.size();
        }
        
        vector<int> lastCycleEdge(vector<vector<int>>& edges) {
            visited.clear();
            vector<int> cycleEdge;
            
            // find last cycle
            for(int i=0; i<edges.size(); i++) {
                // Check cycle
                if(visited.count(edges[i][1])>0) {
                    // found cycle
                    cycleEdge = edges[i];
                }
                
                // Mark vertices visited
                visited.insert(edges[i][0]);
                visited.insert(edges[i][1]);
            }
            
            // Return last cycle eedge
            return cycleEdge;
        }
        
        vector<int> redundantCandidate() {
            // Find root
            int root;
            for (root=1; root<nodes.size(); root++) {
                if (nodes[root].parentEdge.size() == 0) {
                    break;
                }
            }
            
            // Test graph connectivity (with one candidate edge removed)
            if (dfsTraversal(nodes[root].val))
                    return candidates[1]; // visited all nodes
            
            // The redundant edge must be the other candidate
            return candidates[0];
        }
        
        bool dfsTraversal(int u) {
            // Mark node visited
            visited.insert(u); 
            
            // Base case: found all nodes in graph
            if (visited.size() == nodes.size()-1) // Ignore 0th element in nodes
                return true;
            
            // Recursive depth first search
            for(auto it=nodes[u].adj.begin(); it!=nodes[u].adj.end(); it++) {
                // Check if visited
                if(visited.count(*it)>0)
                    continue; // skip
                
                // Recursive search
                if (dfsTraversal(*it))
                    return true;
            }
            
            // not all nodes visited
            return false;   
        }
    }; 
};