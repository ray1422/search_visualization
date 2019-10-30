#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;
class Console {

public:
    static void gotoXY( int column, int line) {
      COORD coord;
      coord.X = column;
      coord.Y = line;
      SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
    }
};
