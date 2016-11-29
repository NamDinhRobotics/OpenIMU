#ifndef RESULTSTABWIDGET_H
#define RESULTSTABWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <string>
#include <QLabel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "../algorithm/AlgorithmOutputInfoSerializer.h"
#include "../algorithm/AlgorithmInfoSerializer.h"
#include "../acquisition/RecordInfo.h"
#include "../core/components/blockType/DbBlock.h"
#include "../MainWindow.h"
#include <QPushButton>
#include <QInputDialog>

QT_CHARTS_USE_NAMESPACE

class ResultsTabWidget: public QWidget
{
    Q_OBJECT

    public:
    ResultsTabWidget();
    ResultsTabWidget(QWidget *parent, AlgorithmOutputInfo output);
     ~ResultsTabWidget();

    public slots:
    void exportToPdfSlot();
    void exportToDBSlot();

    private:
    QWidget* m_parent;
    QGridLayout* layout;
    QWidget* container;
    QLabel* imuType;
    QPushButton* exportToPdf;
    QPushButton* saveResultsToDB;
    QChartView *chartView;

    QLabel* algoLabel;
    QLabel* recordLabel;
    QLabel* dateLabel;
    QLabel* startHourLabel;
    QLabel* endHourLabel;
    QLabel* positionLabel;
    QLabel* measureUnitLabel;
    QLabel* computeTimeLabel;

    DbBlock * m_databaseAccess;

    AlgorithmOutputInfo m_algorithmOutputInfo;

    void init(AlgorithmOutputInfo output);
};

#endif
