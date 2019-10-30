#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include "./console.cpp"

class Search {

protected:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    int h, w;

    bool inRange(int r, int c) {
        return r >= 0 && r < h && c >= 0 && c < w;
    }

public:
    short  vis[3000][3000];
    bool graph[3000][3000];
    Search(){
        memset(vis, 0, sizeof(vis));
        memset(graph, 0, sizeof(graph));
    }


    bool setGraph(int _h, int _w, bool blocked[]) { // if h or w > 3000, return false, operation failed.
        h = _h; w = _w;
        std::memset(vis, 0, sizeof(vis));
        std::memset(vis, 0, sizeof(vis));
        for(int i = 0 ; i < h; i++) {
            for(int j = 0 ; j < w; j++) {
                graph[i][j] = blocked[i * w + j];
            }
        }
    }
    void clearScreen(){
        Console::gotoXY(0, 0);
        for(int i = 0 ; i < h*2 + 10;i++) {
            for(int j = 0; j < 90; j++) cout << " ";
            cout << endl;
        }
        Console::gotoXY(0, 0);
    }
    void visualize(){
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      Console::gotoXY(0, 0);
        for(int i = 0 ; i < h; i++) {
            for(int j = 0 ; j < w; j++) {
                if(graph[i][j]) SetConsoleTextAttribute(hConsole, 12);
                else
                    if (vis[i][j] == 0) SetConsoleTextAttribute(hConsole, 7);
                    else if (vis[i][j] == 1) SetConsoleTextAttribute(hConsole, 14);
                    else if (vis[i][j] == 2) SetConsoleTextAttribute(hConsole, 10);
                cout << " *";
                SetConsoleTextAttribute(hConsole, 7);
            }

            std::cout << "\n";
        }
        cout << "\n";
        SetConsoleTextAttribute(hConsole, 12);cout << "*";SetConsoleTextAttribute(hConsole, 7);cout  << " wall, ";
        SetConsoleTextAttribute(hConsole, 7);cout << "*";SetConsoleTextAttribute(hConsole, 7);cout  << " not visited, ";
        SetConsoleTextAttribute(hConsole, 14);cout << "*";SetConsoleTextAttribute(hConsole, 7);cout  << " visited, ";
        SetConsoleTextAttribute(hConsole, 10);cout << "*";SetConsoleTextAttribute(hConsole, 7);cout  << " finished.\n";


    }
};

class DFS: public Search {
private:
    std::stack<std::pair<int, int> > stk;
public:
    bool startAt(int r, int c) {
        if(!stk.empty() || graph[r][c]) return 0; // already started.
        stk.emplace(r, c);
        return 1;
    };
    bool doStep(){
        if(stk.empty()) return false;
        std::pair<int, int> pt = stk.top();
        stk.pop();
        int r = pt.first, c = pt.second;
        vis[r][c] = 2;
        for(int i = 0 ; i < sizeof(dx)/sizeof(int); i++) {
            int next_r = r+dx[i], next_c = c+dy[i];
            if(inRange(next_r, next_c) && !vis[next_r][next_c] && !graph[next_r][next_c]) {
                stk.emplace(next_r, next_c);
                vis[next_r][next_c] = 1;
            }
        }
        return 1;
    }
};


class BFS: public Search {
private:
    std::queue<std::pair<int, int>> que;
public:
    bool startAt(int r, int c) {
        if(!que.empty() || graph[r][c]) return 0; // already started.
        que.emplace(r, c);
        return 1;
    };
    bool doStep(){
        if(que.empty()) return false;
        std::pair<int, int> pt = que.front();
        que.pop();
        int r = pt.first, c = pt.second;
        vis[r][c] = 2;
        for(int i = 0 ; i < sizeof(dx)/sizeof(int); i++) {
            int next_r = r+dx[i], next_c = c+dy[i];
            if(inRange(next_r, next_c) && !vis[next_r][next_c] && !graph[next_r][next_c]) {
                que.emplace(next_r, next_c);
                vis[next_r][next_c] = 1;
            }
        }
        return 1;
    }
};


