#include <iostream>

#include "./search.cpp"

using namespace std;

int main() {
    int h, w;
    cout << "Please Enter Height: "; cin >> h;
    cout << "Please Enter Width: "; cin >> w;
    bool graph[h * w];
    cout << "Input The Map Below. 0: Blank, 1: Wall: \n";
    for(int i = 0; i < h; i++)for(int j = 0 ; j < w; j++) cin >> graph[i*w + j];
    bool type;
    cout << "DFS (0) or BFS(1) ? ";cin >> type;
    if(type){
        BFS *bfs = new BFS();
        bfs->setGraph(h, w, graph);
        bfs->startAt(0, 0);
        bfs->clearScreen();
        while(bfs->doStep()) {
            bfs->visualize();
            cout << "\npress enter to continue.\n";
            getchar();
        }
    } else {
        DFS *dfs = new DFS();
        dfs->setGraph(h, w, graph);
        dfs->startAt(0, 0);
        dfs->clearScreen();
        while(dfs->doStep()) {
            dfs->visualize();
            cout << "\npress enter to continue.\n";
            getchar();
        }
    }
    cout << "Done!";
}
