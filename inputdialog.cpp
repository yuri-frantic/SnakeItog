#include "inputdialog.h"

InputDialog::InputDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Угол поворота змеи, град");
    
    QPushButton *submitButton = new QPushButton("Принять", this);

    layout->addWidget(lineEdit);
    layout->addWidget(submitButton);

    connect(submitButton, &QPushButton::clicked, this, &InputDialog::submitInput);
}

void InputDialog::submitInput() {
    emit inputSubmitted(lineEdit->text());
    accept(); // Закрыть диалог после отправки
}
