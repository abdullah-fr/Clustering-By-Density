Clustering By Density - CS221 Project
📋 Project Overview
This project implements a density-based clustering algorithm for analyzing network graphs, with applications in protein-protein interaction networks and other relational datasets. The algorithm identifies cohesive subgroups (clusters) within a graph based on edge density and node connectivity patterns.

🎯 Key Features
Density-Based Clustering: Finds subgraphs with density ≥ threshold value

Protein Interaction Network Analysis: Designed for biological network analysis

Weighted Edge Calculation: Edge weights based on common neighbors

Priority-Based Expansion: Clusters grow based on node connectivity metrics

Configurable Thresholds: Adjustable density and cluster property parameters

📊 Algorithm Details
The algorithm works by:

Starting with the highest-weight node as initial cluster

Expanding clusters by adding neighbor nodes

Maintaining density and cluster property constraints

Iteratively processing remaining nodes

Key Metrics:
Edge Weight: Number of common neighbors between nodes

Node Weight: Sum of weights of connected edges

Cluster Density: Ratio of actual edges to maximum possible edges

Cluster Property (cp): Measures node's connectivity within cluster

🏗️ Implementation
Language: C++

Data Structures: Graph representation using adjacency lists

Classes: Node, Graph

File Input: Reads from mydataset.txt (node1, node2, weight format)

📁 File Structure
text
├── main.cpp              # Main implementation
├── mydataset.txt         # Input data file
├── README.md            # This documentation
└── Project_Description.pdf # Original project specifications
🚀 Usage
Prepare input file in format: node1 node2 weight

Compile: g++ -o clustering main.cpp

Run: ./clustering

Adjust density and cp thresholds in clustering() function call

📈 Sample Output
The program displays:

Original graph structure

Identified clusters with their member nodes

Edge weights and connectivity information

🎓 Academic Context
Course: CS221 - Data Structures and Design
Institution: GIK Institute
Submission Deadline: 22-12-2023
Project Type: Semester Project

🔬 Applications
Biological network analysis (protein-protein interactions)

Social network community detection

Recommendation systems

Data mining and pattern recognition

⚙️ Parameters
thdensity: Minimum cluster density threshold (0-1)

cp: Cluster property threshold for node inclusion (0-1)

📝 Notes
The algorithm prioritizes nodes with strong intra-cluster connections

Edge weights are calculated as common neighbors count (M² for u ≠ v)

Clusters are removed from consideration once identified

Implementation handles undirected simple graphs

🛠️ Future Enhancements
Potential improvements could include:

Parallel processing for large graphs

Additional clustering quality metrics

Visualization components

Support for directed graphs

Optimized data structures for scalability

📚 References
Based on density-based clustering principles and network analysis techniques commonly used in bioinformatics and data mining research.
