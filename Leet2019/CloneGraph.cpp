#include "stdafx.h"

//Given a reference of a node in a connected undirected graph, return a deep copy
//(clone) of the graph. Each node in the graph contains a val (int) and a list
//(List[Node]) of its neighbors.
// 
//      1---2
//      |   |
//      4---3
//
//Example:
//Input:
//{"$id":"1","neighbors":
//	[{"$id":"2","neighbors":
//		[{"$ref":"1"},{"$id":"3","neighbors":
//			[{"$ref":"2"},{"$id":"4","neighbors":
//				[{"$ref":"3"},{"$ref":"1"}],"val":4}],
//		"val":3}],
//	"val":2},{"$ref":"4"}],
//"val":1}
//
//Explanation:
//Node 1's value is 1, and it has two neighbors: Node 2 and 4.
//Node 2's value is 2, and it has two neighbors: Node 1 and 3.
//Node 3's value is 3, and it has two neighbors: Node 2 and 4.
//Node 4's value is 4, and it has two neighbors: Node 1 and 3.
// 
//
//Note:
//The number of nodes will be between 1 and 100.
//The undirected graph is a simple graph, which means no repeated edges and no
//self-loops in the graph.
//Since the graph is undirected, if node p has node q as neighbor, then node q
//must have node p as neighbor too.
//You must return the copy of the given node as a reference to the cloned graph. 

namespace Solution2019
{
	namespace CloneGraph
	{
		class Node {
		public:
			int val;
			vector<Node*> neighbors;

			Node() {}

			Node(int _val, vector<Node*> _neighbors) {
				val = _val;
				neighbors = _neighbors;
			}
		};

		namespace DFS {
			Node* helper(Node* node, unordered_map<Node*, Node*>& map) {
				if (map.find(node) == map.end()) {
					map[node] = new Node(node->val, {});
					for (Node* n : node->neighbors) {
						map[node]->neighbors.push_back(helper(n, map));
					}
				}
				return map[node];
			}

			Node* cloneGraph(Node* node) {
				if (!node) { return nullptr; }
				unordered_map<Node*, Node*> map;
				return helper(node, map);
			}
		}

		namespace BFS {
			Node* cloneGraph(Node* node) {
				if (!node) { return nullptr; }

				unordered_map<Node*, Node*> map;
				queue<Node*> q;
				q.push(node);
				map[node] = new Node(node->val, {});

				while (!q.empty()) {
					Node* cur = q.front();
					q.pop();

					for (Node* n : cur->neighbors) {
						if (map.find(n) == map.end()) {
							map[n] = new Node(n->val, {});
							q.push(n);
						}
						map[cur]->neighbors.push_back(map[n]);
					}
				}
				return map[node];
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

