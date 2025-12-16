#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Node
{
public:
    string name;
    vector<pair<Node *, double>> neighbors;
    bool partOfCluster;

    Node(const string &n) : name(n)
    {
        bool partOfCluster = 0;
    }

    void addEdge(Node *n, double weight)
    {
        neighbors.push_back({n, weight});
        
    }

    void displayNode() const
    {
        cout << "\nPARENT: " << name << "\t--->\t";
        for (const auto &neighbor : neighbors)
        {
            cout << neighbor.first->name << "(" << neighbor.second << ")-> ";
        }
        cout << endl;
    }
    size_t getNumberOfEdges()
    {
        return neighbors.size();
    }
};

class Graph
{
public:
    vector<Node *> nodes;
    void addNode(Node * node){
        nodes.push_back(node);
    }
    void addEdge(Node *source, Node *dest, double weight)
    {
        bool isNode = false;
        for (Node *n : nodes)
        {
            if (n->name == source->name)
            {
                n->addEdge(dest, weight);
                isNode = true;
                break;
            }
        }
        if (!isNode)
        {
            source->addEdge(dest, weight);
            nodes.push_back(source);
        }
    }

    void displayGraph() const
    {
        for (const Node *n : nodes)
        {
            n->displayNode();
        }
    }
    float density()
    {
        float sum = 0;
        for (Node *n : nodes)
        {
            sum += n->getNumberOfEdges();
        }
        return ((2 * sum) / (nodes.size() * (nodes.size() - 1)));
    }
    ~Graph()
    {
        for (Node *n : nodes)
        {
            for (auto neighbor : n->neighbors)
            {
                delete neighbor.first; // Delete the neighbor node
            }
            delete n; // Delete the current node
        }
    }
};

float clusterProperty(Graph cluster, Node *node)
{
    
    int commonEdges = 0; // Ec variable
    int cluster_edges = 0;    //Nc variable
    for(int i = 0; i < cluster.nodes.size(); i++){
        for(int j =0 ; j < node->neighbors.size(); j++){
            if(node->neighbors[j].first->partOfCluster && node->neighbors[j].first->name == cluster.nodes[i]->name){
                commonEdges++;
            }
        }
        for(int j = 0; j < cluster.nodes[i]->neighbors.size(); j++){
            if(!cluster.nodes[i]->neighbors[j].first->partOfCluster){
                cluster_edges++;
            }
        }
    }
    return (commonEdges) / (cluster.density() * cluster.nodes.size());
}

bool canAddNode(Graph cluster, Node *node, float thdensity, float cp)
{
    cluster.addNode(node);
    if ((cluster.density() < thdensity && cluster.density() > 0) && (clusterProperty(cluster, node) < cp && clusterProperty(cluster, node) > 0))
    {
        return true;
    }
    else
        return false;
}

vector<Graph> clustering(Graph graph, float thdensity, float cp)
{
    vector<Graph> clusters;
    int cluster_counter = 0;
    Graph cluster;
    cluster.addNode(graph.nodes[0]);
    graph.nodes[0]->partOfCluster = 1;
    clusters.push_back(cluster);
    for (int i = 1; i < graph.nodes.size(); i++)
    {
        if(graph.nodes[i]->partOfCluster){
            continue;
        }
        Graph current_cluster = clusters[cluster_counter];
        for(int j = 0; j < current_cluster.nodes.size(); j++){
            for(int k = 0; k < clusters[cluster_counter].nodes[j]->neighbors.size(); k++){
                if(!clusters[cluster_counter].nodes[j]->neighbors[k].first->partOfCluster){
                    if(canAddNode(clusters[cluster_counter], graph.nodes[i], thdensity, cp)){
                        clusters[cluster_counter].addNode(graph.nodes[i]);
                        graph.nodes[i]->partOfCluster = 1;
                    }
                }
            }

        }
    }
    return clusters;
}

int main()
{
    // Create a graph
    Graph graph;

    // Add edges to the graph based on the given data
    ifstream myfile("mydataset.txt");
    if (!myfile.is_open())
    {
        cerr << "Error opening file for reading" << std::endl;
        return 1;
    }

    string line;
    while (getline(myfile, line))
    {
        istringstream iss(line);
        string node1, node2;
        double weight;

        if (iss >> node1 >> node2 >> weight)
        {
            Node *obj1 = new Node(node1);
            Node *obj2 = new Node(node2);
            graph.addEdge(obj1, obj2, weight);
            graph.addEdge(obj2, obj1, weight);
        }
        else
        {
            cerr << "Error reading line: " << line << endl;
        }
    }

    myfile.close();

    // Display the graph
    cout << "Graph:" << endl;
    graph.displayGraph();

    cout << endl;
    cout << ".....................CLUSTERS....................";
    vector<Graph> clusters = clustering(graph, 0.3, 0.3);
    int i = 1;
    for (const auto &element : clusters)
    {
        cout << "Cluster: " << i << "\n";
        element.displayGraph();
        cout << endl;
    }
    return 0;
}