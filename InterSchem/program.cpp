#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
struct nod {
    int start, station, end;
}V[100];
int pi[100], visitedNeighbors[100], fr[100], m[100][100];
int main()
{
    int x, y, z, N = 0;
    while(fin >> x)
    {
        fin >> y >> z;
        pi[N] = -1;
        fr[N] = 0;
        visitedNeighbors[N] = 0;
        V[N].start = x;
        V[N].station = y;
        V[N].end = z;
        N++;
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i != j && V[i].station == V[j].station && ((V[i].start <= V[j].start && V[i].end >= V[j].end) || 
                                                          (V[i].start <= V[j].start && V[i].end <= V[j].end && V[i].end >= V[j].start) ||
                                                          (V[i].start >= V[j].start && V[i].end >= V[j].end && V[i].start <= V[j].end) ||
                                                          (V[i].start >= V[j].start && V[i].end <= V[j].end)))
                m[i][j] = m[j][i] = 1;
        }
    }
    for(int i = N; i > 0; i--)
    {
        int maxx = -1, i_max = -1;
        for(int j = 0; j < N; j++)
        {
            if(visitedNeighbors[j] > maxx && !fr[j])
            {
                maxx = visitedNeighbors[j];
                i_max = j;
            }
        }
        pi[i_max] = i;
        fr[i_max] = 1;
        for(int j = 0; j < N; j++)
        {
            if(m[i_max][j] == 1 && fr[j] == 0)
                if(pi[j] == -1)
                    visitedNeighbors[j]++;
        }
    }
    for(int i = 0; i < N; i++)
        fout << visitedNeighbors[i] << " ";
    fin.close();
    fout.close();
    return 0;
}