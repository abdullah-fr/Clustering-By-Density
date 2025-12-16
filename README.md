Clustering By Density - CS221 Project

📋 Overview

This project implements a density-based clustering algorithm for analyzing network graphs, with applications in protein-protein interaction networks and other relational datasets. It identifies cohesive subgroups (clusters) within a graph based on edge density and node connectivity patterns.

🧭 Table of Contents

Key Features

Algorithm Details

Implementation

File Structure

Usage

Sample Output

Parameters

Applications

Notes

Future Enhancements

References

🎯 Key Features

Density-Based Clustering: Detects subgraphs with density ≥ threshold

Protein Interaction Network Analysis: Designed for biological networks

Weighted Edge Calculation: Based on common neighbors

Priority-Based Expansion: Clusters grow via connectivity metrics

Configurable Thresholds: Adjustable density and cluster property parameters

📊 Algorithm Details

Start with the highest-weight node as the initial cluster.

Expand clusters by adding neighbor nodes.

Maintain density and cluster property (cp) constraints.

Iteratively process remaining nodes.

Key Metrics:

Edge Weight: Number of common neighbors between nodes

Node Weight: Sum of weights of connected edges

Cluster Density: Actual edges ÷ maximum possible edges

Cluster Property (cp): Node connectivity within the cluster

🏗️ Implementation

Language: C++

Data Structures: Graph represented using adjacency lists

Classes: Node, Graph

Input File: mydataset.txt (format: node1 node2 weight)



🚀 Usage

Prepare the input file in format:

node1 node2 weight


Compile the program:

g++ -o clustering main.cpp


Run the executable:

./clustering


Adjust density and cluster property thresholds in the clustering() function call.

📈 Sample Output

Original graph structure

Identified clusters with member nodes

Edge weights and connectivity information

⚙️ Parameters
Parameter	Description	Range
thdensity	Minimum cluster density threshold	0–1
cp	Cluster property threshold for node inclusion	0–1
🔬 Applications

Biological network analysis (protein-protein interactions)

Social network community detection

Recommendation systems

Data mining and pattern recognition

📝 Notes

Prioritizes nodes with strong intra-cluster connections

Edge weights calculated as common neighbors count (M² for u ≠ v)

Clusters removed from consideration once identified

Supports undirected simple graphs

🛠️ Future Enhancements

Parallel processing for large graphs

Additional clustering quality metrics

Visualization components

Support for directed graphs

Optimized data structures for scalability

📚 References

Based on density-based clustering principles and network analysis techniques commonly used in bioinformatics and data mining research.
