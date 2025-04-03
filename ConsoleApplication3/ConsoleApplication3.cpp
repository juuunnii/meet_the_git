#include <iostream>
#include <windows.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Установка цвета текста (красный) и фона (белый)
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_WHITE);
    std::cout << "Hello, World!" << std::endl;

    // Перемещение курсора
    COORD pos = { 10, 5 };
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << "Cursor moved!" << std::endl;

    // Возврат к стандартным настройкам
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}