#ifndef CLOCK_H
#define CLOCK_H

#include "dateandtime.h"
#include "mytimer.h"
#include "stopwatch.h"

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

namespace Ui {
class Clock;
}

class Clock : public QWidget
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = nullptr);
    ~Clock();

private slots:
    void timerButtonClicked();
    void dateAndTimeButtonClicked();
    void stopwatchButtonClicked();

private:
    Ui::Clock *ui;
    MyTimer *timerWindow;
    DateAndTime *dateAndTimeWindow;
    Stopwatch *stopwatchWindow;

    QPushButton *timerButton;
    QPushButton *dateAndTimeButton;
    QPushButton *stopwatchButton;

    QHBoxLayout *horizontalLayout;
};

#endif // CLOCK_H
