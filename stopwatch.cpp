#include "stopwatch.h"
#include "ui_stopwatch.h"

Stopwatch::Stopwatch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stopwatch)
{
    ui->setupUi(this);
    setWindowTitle("Stopwatch");

    time = QTime(0, 0, 0);

    timeLabel = new QLabel();

    startButton = new QPushButton();
    resumeButton = new QPushButton();
    resetButton = new QPushButton();
    stopButton = new QPushButton();

    verticalLayout = new QVBoxLayout();
    horizontalLayout = new QHBoxLayout();

    startButton->setStyleSheet("font: 12pt \"MS Shell Dlg 2\"");
    resumeButton->setStyleSheet("font: 12pt \"MS Shell Dlg 2\"");
    resetButton->setStyleSheet("font: 12pt \"MS Shell Dlg 2\"");
    stopButton->setStyleSheet("font: 12pt \"MS Shell Dlg 2\"");

    startButton->setText("Start");
    resumeButton->setText("Resume");
    resetButton->setText("Reset");
    stopButton->setText("Stop");

    horizontalLayout->addWidget(startButton);
    horizontalLayout->addWidget(resumeButton);
    horizontalLayout->addWidget(resetButton);
    horizontalLayout->addWidget(stopButton);

    verticalLayout->addWidget(timeLabel);
    verticalLayout->addLayout(horizontalLayout);
    setLayout(verticalLayout);

    resumeButton->setEnabled(false);
    resetButton->setEnabled(false);
    stopButton->setEnabled(false);

    printTime();

    connect(startButton, SIGNAL(pressed()), this, SLOT(startButtonClicked()));
    connect(resumeButton, SIGNAL(pressed()), this, SLOT(resumeButtonClicked()));
    connect(resetButton, SIGNAL(pressed()), this, SLOT(resetButtonClicked()));
    connect(stopButton, SIGNAL(pressed()), this, SLOT(stopButtonClicked()));
}

void Stopwatch::startButtonClicked()
{
    startButton->setEnabled(false);
    resumeButton->setEnabled(false);
    resetButton->setEnabled(false);
    stopButton->setEnabled(true);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(printTime()));
    timer->start(1000);
}

void Stopwatch::resumeButtonClicked()
{
    startButton->setEnabled(false);
    resumeButton->setEnabled(false);
    resetButton->setEnabled(false);
    stopButton->setEnabled(true);
    timer->start();
}

void Stopwatch::resetButtonClicked()
{
    startButton->setEnabled(true);
    resumeButton->setEnabled(false);
    resetButton->setEnabled(false);
    stopButton->setEnabled(false);
    time = QTime(0, 0, 0);
    printTime();
}

void Stopwatch::stopButtonClicked()
{
    startButton->setEnabled(false);
    resumeButton->setEnabled(true);
    resetButton->setEnabled(true);
    stopButton->setEnabled(false);
    timer->stop();
}

void Stopwatch::printTime()
{
    QString timeText = time.toString("hh : mm : ss");
    timeLabel->setText(timeText);
    timeLabel->setAlignment(Qt::AlignCenter);
    timeLabel->setStyleSheet("font: 24pt \"MS Shell Dlg 2\"");
    time = time.addSecs(1);
}


Stopwatch::~Stopwatch()
{
    delete ui;
}
