#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearPaddle(int paddleX) {
    gotoxy(paddleX, 20);
    cout << "      "; // Assuming paddle size is 6 as in drawBoard
}

void clearBall(int ballX, int ballY) {
    gotoxy(ballX, ballY);
    cout << " "; // Overwrite the ball's previous position with a space
}

void drawBoard(int paddleX, int ballX, int ballY, int score, int lives) {
    // Draw paddle
    gotoxy(paddleX, 20);
    cout << "======";
    
    // Draw ball
    gotoxy(ballX, ballY);
    cout << "O";
    
    // Display score and lives
    gotoxy(45, 5);
    cout << "Score: " << score << "   "; // Extra spaces to overwrite previous text
    gotoxy(45, 7);
    cout << "Lives: " << lives << "   "; // Extra spaces to overwrite previous text
}

void drawWalls() {
    for (int i = 0; i < 42; i++) {
        gotoxy(i, 0);
        cout << "#";
        gotoxy(i, 24);
        cout << "#";
    }
    for (int i = 0; i < 25; i++) {
        gotoxy(0, i);
        cout << "#";
        gotoxy(41, i);
        cout << "#";
    }
}

int main() {
    system("mode con: lines=30 cols=60");

    int paddleX = 20;
    int ballX = 32;
    int ballY = 19;
    int ballDirX = 1;
    int ballDirY = -1;
    int score = 0;
    int lives = 3;

    cout << "Instructions: " << endl;
    cout << "*************" << endl;
    cout << "1.Press right and left arrow keys for move paddle." << endl;
    cout << "2.Press Esc key for quit game." << endl;

    system("pause");
    system("cls"); // Clear initial instructions screen
    drawWalls(); // Draw walls once as they don't change

    while (lives > 0) {
        if (_kbhit()) {
            char key = _getch();

            clearPaddle(paddleX); // Clear the paddle's previous position

            if (key == 75 && paddleX > 1) {
                paddleX--;
            } else if (key == 77 && paddleX < 34) {
                paddleX++;
            } else if (key == 27) {
                break;
            }
        }

        clearBall(ballX, ballY); // Clear the ball's previous position

        ballX += ballDirX;
        ballY += ballDirY;

        // Game logic...
        if (ballY == 20 && ballX >= paddleX && ballX <= paddleX + 5) {
            ballDirY = -ballDirY;
            score++;
        }
        if (ballX == 1 || ballX == 40) ballDirX = -ballDirX;
        if (ballY == 1) ballDirY = -ballDirY;
        if (ballY == 23) {
            lives--;
            ballX = 20;
            ballY = 19;
            ballDirY = -ballDirY;
        }

        drawBoard(paddleX, ballX, ballY, score, lives);
        Sleep(100);
    }

    system("cls");

    gotoxy(15, 8);
    cout << "Game Over!" << endl;
    gotoxy(15, 9);
    cout << "Final Score: " << score << endl;
    gotoxy(15, 10);
    cout << "Press any key to exit..." << endl;
    _getch();

    return 0;
}
