#include "resultwindow.h"

ResultWindow::ResultWindow(const QString &result, QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel(result, this);
    
    layout->addWidget(label);
    
    setLayout(layout);
}
