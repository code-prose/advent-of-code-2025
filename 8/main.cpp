#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using ReadVec = std::vector<std::tuple<int, int, int> >;
using DistancePair = std::pair<long long, std::pair<size_t, size_t> >;
using MinHeap = std::priority_queue<DistancePair, std::vector<DistancePair>,
                                    std::greater<DistancePair> >;
std::vector<std::string> splitStringStream(const std::string &s,
                                           char delimiter);
size_t findParent(size_t node, std::vector<size_t> &parent);
void mergeTree(size_t node_1, size_t node_2, std::vector<size_t> &parent,
               std::vector<size_t> &size);
std::vector<size_t> getCircuitSizes(const std::vector<size_t> &parent,
                                    const std::vector<size_t> &size);

void pt1(const ReadVec &InputVector);

int main() {
  ReadVec InputVector;
  std::ifstream inputFile("./input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
    std::vector<std::string> res = splitStringStream(line, ',');
    std::tuple<int, int, int> tup = std::make_tuple<int, int, int>(
        stoi(res[0]), stoi(res[1]), stoi(res[2]));
    InputVector.push_back(tup);
  }
  pt1(InputVector);
}

void pt1(const ReadVec &InputVector) {
  MinHeap pq;
  for (size_t i = 0; i < InputVector.size(); i++) {
    for (size_t j = i + 1; j < InputVector.size(); j++) {
      if (i == j)
        continue;
      long long a = std::get<0>(InputVector[i]) - std::get<0>(InputVector[j]);
      long long b = std::get<1>(InputVector[i]) - std::get<1>(InputVector[j]);
      long long c = std::get<2>(InputVector[i]) - std::get<2>(InputVector[j]);
      a = a * a;
      b = b * b;
      c = c * c;
      long long distSq = a + b + c;
      DistancePair dp = {distSq, {i, j}};
      pq.push(dp);
    }
  }

  std::vector<size_t> parent;
  std::vector<size_t> size;
  parent.resize(InputVector.size());
  size.resize(InputVector.size());
  for (size_t i = 0; i < InputVector.size(); i++) {
    parent[i] = i;
    size[i] = 1;
  }
  int connections = 0;
  while (!pq.empty() && connections < 1000) {
    DistancePair item = pq.top();
    pq.pop();
    std::pair<size_t, size_t> indices = item.second;
    size_t parent_n1 = findParent(indices.first, parent);
    size_t parent_n2 = findParent(indices.second, parent);
    if (parent_n1 != parent_n2) {
      mergeTree(indices.first, indices.second, parent, size);
    }
    connections++;
  }


  std::vector<size_t> treeSizes = getCircuitSizes(parent, size);

  size_t n = treeSizes.size();

  size_t result = treeSizes[n-1] * treeSizes[n-2] * treeSizes[n-3];
  std::cout << "Part 1: " << result << std::endl;
}

void pt2(ReadVec InputVector);

std::vector<std::string> splitStringStream(const std::string &s,
                                           char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::stringstream ss(s);
  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

size_t findParent(size_t node, std::vector<size_t> &parent) {
  if (parent[node] != node) {
    parent[node] = findParent(parent[node], parent);
  }
  return parent[node];
}

void mergeTree(size_t node_1, size_t node_2, std::vector<size_t> &parent,
               std::vector<size_t> &size) {
  size_t parent_n1 = findParent(node_1, parent);
  size_t parent_n2 = findParent(node_2, parent);

  if (parent_n1 == parent_n2)
    return;
  else if (size[parent_n1] >= size[parent_n2]) {
    parent[parent_n2] = parent_n1;
    size[parent_n1] += size[parent_n2];
  } else {
    parent[parent_n1] = parent_n2;
    size[parent_n2] += size[parent_n1];
  }
}

std::vector<size_t> getCircuitSizes(const std::vector<size_t> &parent,
                                    const std::vector<size_t> &size) {
  std::vector<size_t> circuit_sizes;
  for (size_t i = 0; i < parent.size(); i++) {
    if (parent[i] == i) {
      circuit_sizes.push_back(size[i]);
    }
  }
  std::sort(circuit_sizes.begin(), circuit_sizes.end());
  return circuit_sizes;
}
