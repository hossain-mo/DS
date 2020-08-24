#pragma once
class subset
{
public:
    int parent;
    int rank;
    int find(subset subsets[], int i);
    void Union(subset subsets[], int x, int y);
};

