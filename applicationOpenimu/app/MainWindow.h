#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widgets/ApplicationMenubar.h"
#include <QVBoxLayout>
#include "string.h"
#include "CustomQmlScene.h"
#include "core/Caneva.h"
#include <QSplitter>
#include "widgets/MyTreeWidget.h"
#include "widgets/MyListWidget.h"
#include <QWidget>
#include "dialogs/AboutDialog.h"
#include "dialogs/HelpDialog.h"
#include <QStatusBar>
#include<QListWidget>
#include "core/components/blockType/DbBlock.h"
#include"dialogs/RecordsDialog.h"
#include<QNetworkReply>
#include<QNetworkAccessManager>
#include"../../acquisition/CJsonSerializer.h"
#include"../../acquisition/WimuRecord.h"

class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
       MainWindow(QWidget *parent = 0);
       ~MainWindow();
       std::string getFileName(std::string s);
       void retranslateUi();
       bool getRecordsFromDB();

    signals:

    public slots:

    void openFile();
    void openRecordDialog();
    void displayRawAccData();
    void computeSteps();
    void closeWindow();
    void onTreeItemClicked(QTreeWidgetItem* item, int /*column*/);
    void computeActivityTime();
    void closeTab(int);
    void replaceTab(QWidget * replacement, std::string label);
    void openAbout();
    void openHelp();
    void dateClicked(QListWidgetItem *item);
    void setApplicationInEnglish();
    void setApplicationInFrench();
    void reponseRecue(QNetworkReply* reply);
    void onListItemClicked(QListWidgetItem* item);

    QListWidget* populateDaysFromDataBase();

    private:
       QString folderName;
       QSplitter * splitter;
       Caneva *caneva;
       QWidget *mainWidget;
       ApplicationMenuBar* menu ;
       CustomQmlScene* scene;
       MyListWidget  * listWidget;
       QTabWidget *tabWidget;
       QString fileSelectedName;
       QWidget *dataView;
       AboutDialog *aboutDialog;
       HelpDialog *helpDialog;
       QStatusBar * statusBar;
       DbBlock * databaseAccess = new DbBlock;
       RecordsDialog * rDialog;
       WimuRecord record;
    };

#endif // MAINWINDOW_H
