#include "clock.h"
#include "ui_clock.h"

Clock::Clock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clock)
{
    ui->setupUi(this);

    setWindowTitle("Clock");

    timerWindow = new MyTimer();
    stopwatchWindow = new Stopwatch();
    dateAndTimeWindow = new DateAndTime();

    horizontalLayout = new QHBoxLayout();

    timerButton = new QPushButton();
    stopwatchButton = new QPushButton();
    dateAndTimeButton = new QPushButton();

    timerButton->setStyleSheet("font: 10pt \"MS Shell Dlg 2\"");
    stopwatchButton->setStyleSheet("font: 10pt \"MS Shell Dlg 2\"");
    dateAndTimeButton->setStyleSheet("font: 10pt \"MS Shell Dlg 2\"");

    timerButton->setText("Timer");
    stopwatchButton->setText("Stopwatch");
    dateAndTimeButton->setText("Date and Time");

    horizontalLayout->addWidget(timerButton);
    horizontalLayout->addWidget(stopwatchButton);
    horizontalLayout->addWidget(dateAndTimeButton);

    setLayout(horizontalLayout);

    connect(timerButton, SIGNAL(pressed()), this, SLOT(timerButtonClicked()));
    connect(stopwatchButton, SIGNAL(pressed()), this, SLOT(stopwatchButtonClicked()));
    connect(dateAndTimeButton, SIGNAL(pressed()), this, SLOT(dateAndTimeButtonClicked()));
}

void Clock::timerButtonClicked()
{
    timerWindow->show();
}

void Clock::stopwatchButtonClicked()
{
    stopwatchWindow->show();
}

void Clock::dateAndTimeButtonClicked()
{
    dateAndTimeWindow->show();
}


Clock::~Clock()
{
    delete ui;
}

