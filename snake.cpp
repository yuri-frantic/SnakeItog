#include "snake.h"
#include "inputdialog.h"
#include <QTimerEvent>
#include <QMessageBox>
#include <windows.h>
#include <QDialog>
#include <QFormLayout>
#include <cmath>

SnakeGame::SnakeGame(QWidget *parent) : QWidget(parent), score(0), dir(0), gameOver(false) {
    setFixedSize(400, 400);

    loadImages();

    initGame();
}
void SnakeGame::openInputDialog() {
    InputDialog dialog(this);
    connect(&dialog, &InputDialog::inputSubmitted, this, &SnakeGame::onSubmit);
    dialog.exec();

}
void SnakeGame::onSubmit(const QString &text) {
        angle = text.toInt();
        //showResult();
    }

void SnakeGame::addInput() {
    openInputDialog(); 

}

void SnakeGame::showResult() {
    QMessageBox::information(this, "Результат ввода", QString::number(angle));
}


SnakeGame::~SnakeGame() {}

void SnakeGame::loadImages() {
    appleImage.load("apple.png");
    dotImage.load("dot.png");
    headImage.load("head.png");
}

void SnakeGame::initGame() {
    snake.clear();
    for (int i = 40;i>20;i--)
    {
        snake.append(QPoint(50,i));
    }
    //snake.append(QPoint(5, 50));
    //snake.append(QPoint(5, 40));
    //snake.append(QPoint(5, 30));
    //snake.append(QPoint(5, 20));
    
    locateApple();

    dir = 0;
    score = 0;
    gameOver = false;

    startTimer(100); // Запуск таймера с интервалом 10 мс
}

void SnakeGame::locateApple() {
    apple.setX((rand() % (width()-10))+5);
    apple.setY((rand() % (height()-10))+5);
}

void SnakeGame::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Отрисовка сегментов змеи
    for (int i = 0; i < snake.size(); i=i+5) {
        if (i == 0) {
            painter.drawPixmap(snake[i].x(), snake[i].y(), headImage);
        } else {

            painter.drawPixmap(snake[i].x(), snake[i].y(), dotImage);
        }
    }

    // Отрисовка яблока
    painter.drawPixmap(apple.x(), apple.y(), appleImage);

    // Отображение счета
    painter.drawText(10, 10, QString("Очки: %1").arg(score));

    // Если игра окончена
    if (gameOver == true) {
        painter.drawText(rect(), Qt::AlignCenter, "Игра окончена!");
        QMessageBox::information(this, "Игра окончена ", "Набранные очки: " + QString::number(score));
        initGame(); // Перезапуск игры после окончания
    }
}

void SnakeGame::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
            dir = (dir - angle + 360) % 360; // поворот влево
    } else if (event->key() == Qt::Key_Right) {
            dir = (dir + angle) % 360; // поворот вправо
    }
}

void SnakeGame::move() {
    if (gameOver) return;

    // Сохранение позиции головы змеи
    QPoint prevSegment = snake.first();

    double radian = dir * M_PI / 180.0;
    prevSegment.setX(prevSegment.x() + std::cos(radian)*2);
    prevSegment.setY(prevSegment.y() + std::sin(radian)*2);
    
    if (apple_<5)
    {
        snake.append(prevSegment); // Увеличиваем длину змеи
        apple_++;
    }

    // Проверка на столкновение с яблоком
    if (prevSegment.x() >= apple.x()-5 && prevSegment.x() <= apple.x()+5 && prevSegment.y() >= apple.y()-5 && prevSegment.y() <= apple.y()+5)
    {
        score += 10;
        locateApple();
        apple_=0;
             
     }
    else
    {        
        // Перемещение тела змеи
        for (int i = snake.size() - 1; i > 0; --i)
        {
            snake[i] = snake[i - 1];
        }
        snake[0] = prevSegment; // Обновляем позицию головы
        // Проверка на столкновение с стенами и телом змеи
        checkCollision();
       
    }
    update(); // Перерисовка виджета
    if (paint == false)
    {
        addInput();
        paint = true;
    }
}
void SnakeGame::checkCollision() {
   
    // Проверка на столкновение со стенами
    if (snake[0].x() < 0 || snake[0].x() >= width() ||
        snake[0].y() < 0 || snake[0].y() >= height()) {
        gameOver = true;
    }

    // Проверка на столкновение с самим собой
    for (int i = 1; i < snake.size(); ++i) {
        if (snake[i] == snake[0]) {
            gameOver = true;
             break;
        }
    }
}

void SnakeGame::timerEvent(QTimerEvent *event) {
    move(); // Движение змеи в каждом тике таймера
}

