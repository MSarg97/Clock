#include "dateandtime.h"
#include "ui_dateandtime.h"

DateAndTime::DateAndTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateAndTime)
{
    ui->setupUi(this);
    setWindowTitle("Date and Time");

    dateLabel = new QLabel();
    timeLabel = new QLabel();

    currentDate = new QLabel();
    currentTime = new QLabel();

    dateLayout = new QHBoxLayout();
    timeLayout = new QHBoxLayout();
    verticalLayout = new QVBoxLayout();

    dateLabel->setStyleSheet("font: 12pt \"MS Shell Dlg 2\"");
    timeLabel->setStyleSheet("font: 12pt \"MS Shell Dlg 2\"");
    currentDate->setStyleSheet("font: 12pt \"MS Shell Dlg 2\"");
    currentTime->setStyleSheet("font: 12pt \"MS Shell Dlg 2\"");

    dateLabel->setText("Current Date:");
    timeLabel->setText("Current Time:");

    setDate();
    setTime();

    dateLayout->addWidget(dateLabel);
    dateLayout->addWidget(currentDate);

    timeLayout->addWidget(timeLabel);
    timeLayout->addWidget(currentTime);

    verticalLayout->addLayout(dateLayout);
    verticalLayout->addLayout(timeLayout);
    setLayout(verticalLayout);
}

void DateAndTime::setCurrentTime()
{
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh : mm : ss  ap");
    currentTime->setText(timeText);
}

void DateAndTime::setTime()
{
    setCurrentTime();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(setCurrentTime()));
    timer->start();
}


void DateAndTime::setDate()
{
    QDate date = QDate::currentDate();
    QString dateText = date.toString("dddd   dd / MMMM / yyyy");
    currentDate->setText(dateText);
}

DateAndTime::~DateAndTime()
{
    delete ui;
}
