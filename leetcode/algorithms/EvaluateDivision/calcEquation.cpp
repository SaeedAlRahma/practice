struct Node;
struct Edge;

struct Node {
    string var; // node/variable name
    vector<Edge*> edges; // list of directed edges from the node
    Node(string s) : var(s) {}
};

struct Edge {
    Node *to; // pointer to another node/variable
    double weight; // variables multiplicand (from = weight*to), where from and to are variables A and B
};

class Graph
{
public:
    typedef map<string, Node *> NodeMap;
    NodeMap node_map;
    void addNode(const string& var);
    void addEdge(const string& from, const string& to, double weight);
    double getQueryAnswer(const string& num, const string& den);
};

void Graph::addNode(const string &var)
{
    NodeMap::iterator itr = node_map.find(var);
    if (itr == node_map.end())
    {
        Node *n;
        n = new Node(var); // create node
        node_map[var] = n; // add node to list
        return;
    }
    //cout << "\nNode already exists!";
}

void Graph::addEdge(const string& from, const string& to, double weight)
{
    Node *root = (node_map.find(from)->second);
    Node *n = (node_map.find(to)->second);
    Edge *edge = new Edge();
    edge->to = n;
    edge->weight = weight;
    root->edges.push_back(edge);
}

double dfs(Node *n, const string& den, unordered_set<string> visited) {
    // Base case
    if (n->var == den) return 1.0; // found answer
    
    //cout << "\ndfs on " << n->var << " to " << den;
    
    // Recursion
    for(int i=0; i<n->edges.size(); i++) {
        //cout << "\nsearching " << n->edges[i]->to->var;
        unordered_set<string>::const_iterator contain = visited.find(n->edges[i]->to->var);
        if (contain == visited.end()) { // not visted
            //cout << "\nNOT VISITED :)";
            visited.insert (n->edges[i]->to->var); // add to set
            double ans = dfs(n->edges[i]->to, den, visited); // look for answer recursively
            if (ans > 0) return n->edges[i]->weight*ans; // return if found expression
        }
    }
    
    // Dead end
    return -1; // no answer found
}

double Graph::getQueryAnswer(const string& num, const string& den) {
    // Check nodes exist/valid
    NodeMap::iterator itr = node_map.find(den);
    if (itr == node_map.end()) return -1.0; // node does not exist
    itr = node_map.find(num);
    if (itr == node_map.end()) return -1.0; // node does not exist
        
    // convert num(erator) to expression in terms of den(ominator)
    unordered_set<string> visited;
    //return dfs((node_map.find(num)->second), den, visited);
    return dfs(itr->second, den, visited);
}

class Solution {  
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        Graph graph;
        
        for (int i=0; i<equations.size(); i++) {
            // add nodes
            graph.addNode(equations[i].first);
            graph.addNode(equations[i].second);
            // add edges (both ways)
            graph.addEdge(equations[i].first, equations[i].second, values[i]);
            graph.addEdge(equations[i].second, equations[i].first, 1/values[i]);
        }
        
        vector<double> ans;
        
        for (int i=0; i<queries.size(); i++) {
            //ans.push_back(graph.getQueryAnswer("z", "Z"));
            ans.push_back(graph.getQueryAnswer(queries[i].first, queries[i].second));
        }
        
        return ans;
    }
};
