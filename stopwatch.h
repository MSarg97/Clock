#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class Stopwatch;
}

class Stopwatch : public QWidget
{
    Q_OBJECT

public:
    explicit Stopwatch(QWidget *parent = nullptr);
    ~Stopwatch();

private slots:
    void printTime();
    void startButtonClicked();
    void resumeButtonClicked();
    void resetButtonClicked();
    void stopButtonClicked();


private:
    Ui::Stopwatch *ui;
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

#endif // STOPWATCH_H
