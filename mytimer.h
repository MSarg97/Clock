#ifndef MYTIMER_H
#define MYTIMER_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class MyTimer;
}

class MyTimer : public QWidget
{
    Q_OBJECT

public:
    explicit MyTimer(QWidget *parent = nullptr);
    ~MyTimer();

private slots:
    void printTime();
    void startButtonClicked();
    void resumeButtonClicked();
    void resetButtonClicked();
    void stopButtonClicked();

private:
    Ui::MyTimer *ui;
    QTime time;
    QTimer *timer;

    QLabel *timeLabel;

    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;

    QPushButton *startButton;
    QPushButton *resumeButton;
    QPushButton *resetButton;
    QPushButton *stopButton;
};

#endif // MYTIMER_H
