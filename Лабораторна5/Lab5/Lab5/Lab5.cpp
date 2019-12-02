#include <iostream>
#include <stdio.h>
using namespace std;
#define inf INT_MAX
#define nodes 30

void dijkstra(double Graph[nodes][nodes], int n, int startNode) {
	double cost[nodes][nodes], dist[nodes], pred[nodes], minDist, visited[nodes];
	int  counter, nextNode, i, j;
	for ( i = 0; i < n; i++) {
		for ( j = 0; j < n; j++) {
			if (Graph[i][j] == 0) {
				cost[i][j] = inf;
			}
			else {
				cost[i][j] = Graph[i][j];
			}
		}
	}
	for ( i = 0; i < n; i++) {
		dist[i] = cost[startNode][i];
		pred[i] = startNode;
		visited[i] = 0;
	}
	dist[startNode] = 0;
	visited[startNode] = 1;
	counter = 1;

	while (counter < n-1)
	{
		minDist = inf;
		for (i = 0; i < n; i++) {
			if (dist[i] < minDist && !visited[i]) {
				minDist = dist[i];
				nextNode = i;
			}
		}
		visited[nextNode] = 1;
		for ( i = 0; i < n; i++) {
			if (!visited[i]) {
				if (minDist + cost[nextNode][i] < dist[i]) {
					dist[i] = minDist + cost[nextNode][i];
					pred[i] = nextNode;
				}
			}
		}		
		counter++;
	}
	for (i = 0; i < n; i++) {
		if (i != startNode) {
			cout << "\nDistance of node" << i + 1 << "=" << dist[i];
			cout << "\nPath=" << i + 1;
			j = i;
			do {
				j = pred[j];
				cout << "<-" << j + 1;
			} while (j != startNode);
		}
	}
}

int main()
{
	double G[nodes][nodes];
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			G[i][j] = 0;
		}
	}
	
	int i = 0, j = 1;
	do {
		cout << "Enter weight from " << i + 1 << " to " << j + 1 << endl;
		cin >> G[i][j];
		i++;
		j++;
	} while (j < nodes);
	i = nodes - 1;
	j = i - 6;

	do {
		cout << "Enter weight from " << i + 1 << " to " << j + 1 << endl;
		cin >> G[j][i];
		i--;
		j = i -6;
	} while (j >= 0);

	for (i = 0; i < nodes; i++) {
		for (j = 0; j < nodes; j++) {
			G[j][i] = G[i][j];
			G[j][i] = G[i][j];
		}
	}
	

	int n = 30;
	int u = 0;
	dijkstra(G, n, u);
}
