#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "storage.h"
#include "dialogfindpref.h"
#include "dialogfindtitle.h"
#include "dialogadd.h"
#include "dialogdelete.h"
#include "windowabout.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    Storage* _storage;
    QSortFilterProxyModel* _proxyModelSort; // TODO: put in storage
    ModelSortBooks* _modelSortBooks; // try

private slots:
    void on_butFindByPref_clicked();
    void on_butAddBook_clicked();
    void on_butDelBook_clicked();
    void on_butFindTitle_clicked();
    void on_actionOpen_triggered();

public:
    void findBookTitle(const QString& searchedTitle);

private slots:
    void onFileRead();

private slots:
    void on_butRes_clicked();
    void on_comBoxSort_activated(int index);
    void on_actionSave_triggered();
    void on_actionInfo_about_app_triggered();

private:
    Ui::MainWindow* ui;
    DialogFindPref* dialogFindPref;
    DialogAdd *dialogAdd;
    DialogDelete *dialogDelete;
    DialogFindTitle *dialogFindTitle;
    WindowAbout* windowAbout;
};
#endif // MAINWINDOW_H
