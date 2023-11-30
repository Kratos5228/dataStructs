/*
#include <iostream>
using namespace std;

const int NODES = 11;

// Node structure to hold the adjacency list
struct Node {
    char data;
    Node* next;
};

// Graph class
class Graph {
private:
    Node* List[NODES];

public:
    Graph() {
        for (int i = 0; i < NODES; i++) {
            List[i] = NULL;
        }
    }

    // Adds an edge to the graph
    void addEdge(char src, char dest) {
        Node* newNode = new Node;
        newNode->data = dest;
        newNode->next = List[src - 'A'];
        List[src - 'A'] = newNode;
    }

    // Depth-first search function
    bool dfs(char src, char dest, bool visited[]) {
        if (src == dest) {
            return true;
        }

        visited[src - 'A'] = true;

        for (Node* ptr = List[src - 'A']; ptr != NULL; ptr = ptr->next) {
            if (!visited[ptr->data - 'A']) {
                if (dfs(ptr->data, dest, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Graph g;

    // Add edges to the graph
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'E');
    g.addEdge('B', 'A');
    g.addEdge('C', 'D');
    g.addEdge('C', 'E');
    g.addEdge('D', 'B');
    g.addEdge('D', 'F');
    g.addEdge('D', 'H');
    g.addEdge('E', 'G');
    g.addEdge('E', 'I');
    g.addEdge('F', 'B');
    g.addEdge('F', 'H');
    g.addEdge('G', 'H');
    g.addEdge('G', 'I');
    g.addEdge('H', 'G');
    g.addEdge('H', 'K');
    g.addEdge('J', 'K');
    g.addEdge('J', 'F');
    g.addEdge('K', 'J');

    char src, dest;
    bool visited[NODES] = { false };

    // Prompt user for source and destination nodes
    cout << "Enter source node: ";
    cin >> src;
    cout << "Enter destination node: ";
    cin >> dest;

    // Call depth-first search function and print result
    if (g.dfs(src, dest, visited)) {
        cout << "Path exists between " << src << " and " << dest << endl;
    }
    else {
        cout << "No path exists between " << src << " and " << dest << endl;
    }

    return 0;
}
*/

/*
#include <iostream>

using namespace std;

const int MAX_NODES = 11;

// Node data structure
struct Node {
    char id;
    Node* next;
};

// Graph data structure
class Graph {
private:
    Node* head[MAX_NODES];
    int num_nodes;

public:
    Graph(int num_nodes) {
        this->num_nodes = num_nodes;
        for (int i = 0; i < num_nodes; i++) {
            head[i] = NULL;
        }
    }

    void add_edge(int u, int v) {
        Node* new_node = new Node;
        new_node->id = v;
        new_node->next = head[u];
        head[u] = new_node;
    }

    void dfs(int u, int v, bool* visited, bool& found) {
        if (u == v) {
            found = true;
            return;
        }
        visited[u] = true;
        for (Node* cur = head[u]; cur != NULL; cur = cur->next) {
            if (!visited[cur->id]) {
                dfs(cur->id, v, visited, found);
                if (found) {
                    return;
                }
            }
        }
    }
};

int main() {
    // Construct the graph
    Graph g(MAX_NODES);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 4);
    g.add_edge(1, 0);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 1);
    g.add_edge(3, 5);
    g.add_edge(3, 7);
    g.add_edge(4, 6);
    g.add_edge(4, 8);
    g.add_edge(5, 1);
    g.add_edge(5, 7);
    g.add_edge(6, 7);
    g.add_edge(6, 8);
    g.add_edge(7, 6);
    g.add_edge(7, 10);
    g.add_edge(9, 10);
    g.add_edge(9, 5);
    g.add_edge(10, 9);

    // Prompt user for source and destination nodes
    char source, dest;
    cout << "Enter source node: ";
    cin >> source;
    cout << "Enter destination node: ";
    cin >> dest;

    // Convert node names to node IDs
    int source_id = source - 'A';
    int dest_id = dest - 'A';

    // Perform depth-first search
    bool visited[MAX_NODES] = {false};
    bool found = false;
    
    g.dfs(source_id, dest_id, visited, found);

    // Print result
    if (found) {
        cout << "Path found from " << source << " to " << dest << endl;
    } else {
        cout << "No path found from " << source << " to " << dest << endl;
    }

    return 0;
}
*/

 #include <iostream>
 #include <vector>
 #include <stack>
 using namespace std;

 class Graph {
     int num_vertices;
     vector<vector<char>> adj_list;

 public:
     Graph(int V) {
         num_vertices = V;
         adj_list.resize(num_vertices);
     }

     void addEdge(char u, char v) {
         adj_list[u].push_back(v);
     }

     bool dfs(int start, int end, vector<bool>& visited) {
         visited[start] = true;

         if (start == end)
             return true;

         for (int i = 0; i < adj_list[start].size(); i++) {
             int neighbor = adj_list[start][i];
             if (!visited[neighbor]) {
                 if (dfs(neighbor, end, visited))
                     return true;
             }
         }

         return false;
     }

     bool hasPathDFS(int start, int end) {
         vector<bool> visited(num_vertices, false);
         return dfs(start, end, visited);
     }
 };

 int main() {
     char choice;
     // Create the graph
     Graph g(11);
     g.addEdge('A', 'B');
     g.addEdge('A', 'C');
     g.addEdge('A', 'E');
     g.addEdge('B', 'A');
     g.addEdge('C', 'D');
     g.addEdge('C', 'E');
     g.addEdge('D', 'B');
     g.addEdge('D', 'F');
     g.addEdge('D', 'H');
     g.addEdge('E', 'G');
     g.addEdge('E', 'I');
     g.addEdge('F', 'B');
     g.addEdge('F', 'H');
     g.addEdge('G', 'H');
     g.addEdge('G', 'I');
     g.addEdge('H', 'G');
     g.addEdge('H', 'K');
     g.addEdge('J', 'K');
     g.addEdge('J', 'F');
     g.addEdge('K', 'J');

     do{
         // Prompt the user for input
         char start, end;
         cout << "Enter the starting node (0-10): ";
         cin >> start;
         cout << "Enter the ending node (0-10): ";
         cin >> end;
         
         // Check if a path exists
         if (g.hasPathDFS(start, end)) {
             cout << "A path exists from node " << start << " to node " << end << endl;
         }
         else {
             cout << "No path exists from node " << start << " to node " << end << endl;
         }
         
         cin >> choice;
         
     }while(choice == 'y' || choice == 'Y');
     return 0;
 }
 
