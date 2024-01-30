#include <iostream> 
#include <conio.h> 
#include <time.h>
#include <windows.h>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include<fstream>

#define dinoPos 2
#define hurdlePos 74

using namespace std;

stack<int> scoreStack;
int score = 0;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int dinoY;

int speed = 40;
int gameover = 0;

class DinoGame {
public:

    void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void setcursor(bool visible, DWORD size) {
        if (size == 0) {
            size = 20; // default cursor size Changing to numbers from 1 to 20, decreases cursor width
        }
        CONSOLE_CURSOR_INFO lpCursor;
        lpCursor.bVisible = visible;
        lpCursor.dwSize = size;
        SetConsoleCursorInfo(console, &lpCursor);
    }

    void displayScore(stack<int> scoreStack, int score)
    {
        ofstream file("Score.txt");
        gotoxy(3, 3); cout << "Score: ";
        gotoxy(10, 3); cout << score;
        // Iterate through the stack 
        while (!scoreStack.empty()) {
            scoreStack.pop();
        }
        file << "Score is : " << score << endl;
        file.close();
    }

    void init() {
        system("cls");
        gameover = 0;

        displayScore(scoreStack, score);

        for (int i = 0; i < 72; i++) {
            gotoxy(1 + i, 0); cout << "_";
            gotoxy(1 + i, 1); cout << "ß";
            gotoxy(1 + i, 25); cout << "ß";
            gotoxy(20, 26); cout << "THE DINOSAUR RUNNING SIMULATOR";
            gotoxy(1 + i, 28); cout << "ß";

        }

    }

    void moveDino(int jump = 0) {
        static int foot = 0;

        if (jump == 0)
            dinoY = 0;
        else if (jump == 2)
            dinoY--;
        else dinoY++;

        gotoxy(dinoPos, 15 - dinoY); cout << "                 ";
        gotoxy(dinoPos, 16 - dinoY); cout << "         /\\/\\/\\/";
        gotoxy(dinoPos, 17 - dinoY); cout << "        /\\ @ @/\\";
        gotoxy(dinoPos, 18 - dinoY); cout << "         \\_/\\/\\/";
        gotoxy(dinoPos, 19 - dinoY); cout << " /\\     /\\/\\/\\/ ";
        gotoxy(dinoPos, 20 - dinoY); cout << " /\\/\\  /\\/\\/\\\\/\\ ";
        gotoxy(dinoPos, 21 - dinoY); cout << " \\/\\/\\/\\/\\_/\\/\\ ";
        gotoxy(dinoPos, 22 - dinoY); cout << "   \\/\\/\\/\\_/     ";
        gotoxy(dinoPos, 23 - dinoY);

        if (jump == 1 || jump == 2) {
            cout << "    /\\'' /\\       ";
            gotoxy(2, 24 - dinoY);
            cout << "    /\\   /\\      ";

        }
        else if (foot == 0) {
            cout << "    \\/\\  \\/\\/\\    ";
            gotoxy(2, 24 - dinoY);
            cout << "      /\\         ";
            foot = !foot;
        }
        else if (foot == 1) {
            cout << "     \\/\\/ \\/\\      ";
            gotoxy(2, 24 - dinoY);
            cout << "          /\\     ";
            foot = !foot;
        }

        gotoxy(2, 25 - dinoY);
        if (jump == 0) {
            cout << "ßßßßßßßßßßßßßßßßß";
        }
        else {
            cout << "                ";
        }
        Sleep(speed);
    }

    void drawHurdle() {
        static int plantX = 0;

        if (plantX == 56 && dinoY < 4) {
            speed = 40;
            gotoxy(36, 8); cout << "Game Over";
            _getch();
            gameover = 1;
        }
       
        gotoxy(hurdlePos - plantX, 20); cout << "| | ";
        gotoxy(hurdlePos - plantX, 21); cout << "| | ";
        gotoxy(hurdlePos - plantX, 22); cout << "|_| ";
        gotoxy(hurdlePos - plantX, 23); cout << " |  ";
        gotoxy(hurdlePos - plantX, 24); cout << " |  ";

        plantX++;

        if (plantX == 73) {
            plantX = 0;

            scoreStack.push(score++);
            displayScore(scoreStack, score);
        }
        if (speed > 20)
            speed--;
    }
    void play() {
        system("cls");
        system("Color E4");
        char ch;
        int i;
        score = 0;
        init();
        while (true) {
            while (!_kbhit()) {
                if (gameover == 1) {
                    return;
                }
                moveDino();
                drawHurdle();
            }
            ch = _getch();
            if (ch == 32) {
                i = 0;
                while (i < 12) {
                    moveDino(1);
                    drawHurdle();
                    i++;
                }
                while (i > 0) {
                    moveDino(2);
                    drawHurdle();
                    i--;
                }
            }
            else if (ch == 'p' || ch == 'P')
                _getch();
            else if (ch == 27)
                break;
        }
    }
  
    void instructions() {
        system("cls");
        cout << "Instructions";
        cout << "\n----------------";
        cout << "\n1. Avoid hurdles by jumping";
        cout << "\n2. Press 'Spacebar' to jump ";
        cout << "\n3. Press 'p' to pause game ";
        cout << "\n4. Press 'Escape' to exit from game";
        cout << "\n\nPress any key to go back to menu";
        _getch();
    }

    void LoadingBar() {
        cout << "\n\n\n\t\t\t\tPlease wait while loading\n\n";
        char a = 177, b =219 ;
        cout << "\t\t\t\t";
        for (int i = 0; i <= 15; i++)
            cout << a;
        cout << "\r";
        cout << "\t\t\t\t";
        for (int i = 0; i <= 15; i++)
        {
            cout << b;
            for (int j = 0; j <= 1e8; j++); //You can also use sleep function instead of for loop
        }
    }
};

int main() {
    DinoGame DG;
    DG.setcursor(0, 0);

    do {
        system("cls");
        system("Color 0b");
        DG.gotoxy(10, 5); cout << " -------------------------- ";
        DG.gotoxy(10, 6); cout << " |        DINO RUN        | ";
        DG.gotoxy(10, 7); cout << " -------------------------- ";
        DG.gotoxy(10, 9); cout << " 1. Start Game";
        DG.gotoxy(10, 11); cout << "2. Instructions";
        DG.gotoxy(10, 12); cout << "3. Quit ";
        DG.gotoxy(10, 14); cout << "Select option: ";
        char op = _getche();

        if (op == '1') {
            system("color 0b");
            DG.LoadingBar();
            DG.play();

        }
        else if (op == '2') DG.instructions();
        else if (op == '3') return 0;

    } while (1);

    return 0;
}
