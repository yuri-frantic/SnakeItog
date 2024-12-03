#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>
#include <QVector>
#include <QPixmap>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

class SnakeGame : public QWidget {
    Q_OBJECT

public:
    SnakeGame(QWidget *parent = nullptr);
    ~SnakeGame();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;


private slots:
    void openInputDialog();
    void addInput();
    void showResult();
    void onSubmit(const QString &text);


private:
    void loadImages();
    void initGame();
    void locateApple();
    void move();
    void checkCollision();
    QVector<QPoint> snake;
    QPoint apple;
    int score;
    int dir = 270;
    bool gameOver;
    bool paint = false;
    QTimer *timer;
    int iterat = 1;
    int iter_move = 0;
    int angle;
    int apple_ = 10;
    QPixmap appleImage;
    QPixmap dotImage;
    QPixmap headImage;




    QLabel *label;
    QVBoxLayout *layout;
    QWidget *centralWidget;
    QPushButton *addButton;
    QTextEdit *resultDisplay;
    QList<QComboBox*> comboBoxes;
    QList<QLineEdit*> lineEdits;
};

#endif // SNAKE_H
