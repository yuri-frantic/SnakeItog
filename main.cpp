#include <QApplication>
#include "snake.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    SnakeGame game;
    // устанавливаем цвет фона и шрифта
    game.setStyleSheet("background-color:black; color: white");
    game.show();
    return a.exec();
}
