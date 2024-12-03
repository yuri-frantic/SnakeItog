#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

class ResultWindow : public QDialog {
    Q_OBJECT

public:
    ResultWindow(const QString &result, QWidget *parent = nullptr);
};

#endif // RESULTWINDOW_H
