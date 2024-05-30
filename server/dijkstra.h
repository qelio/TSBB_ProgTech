#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <climits>

const int NUM_VERTICES = 5;
const int INF = INT_MAX;

int dijkstra(int s, int t, std::vector<std::vector<int>>& graph);

#endif // DIJKSTRA_H
