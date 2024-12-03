#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class InputDialog : public QDialog {
    Q_OBJECT

public:
    InputDialog(QWidget *parent = nullptr);

signals:
    void inputSubmitted(const QString &text);

private slots:
    void submitInput();

private:
    QLineEdit *lineEdit;
};

#endif // INPUTDIALOG_H
