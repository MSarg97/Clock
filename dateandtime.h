#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QTimer>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class DateAndTime;
}

class DateAndTime : public QWidget
{
    Q_OBJECT

public:
    explicit DateAndTime(QWidget *parent = nullptr);
    void setDate();
    void setTime();
    ~DateAndTime();

private slots:
    void setCurrentTime();

private:
    Ui::DateAndTime *ui;
    QLabel *dateLabel;
    QLabel *timeLabel;
    QLabel *currentDate;
    QLabel *currentTime;

    QTimer *timer;
    QHBoxLayout *dateLayout;
    QHBoxLayout *timeLayout;
    QVBoxLayout *verticalLayout;
};

#endif // DATEANDTIME_H
