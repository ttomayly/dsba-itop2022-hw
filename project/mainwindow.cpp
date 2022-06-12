#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include  <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _storage = new Storage(this);
    _proxyModelSort = new QSortFilterProxyModel(this);
    windowAbout = new WindowAbout(this);

    QWidget::connect(_storage, &Storage::onFileRead, this, &MainWindow::onFileRead);

    ui->comBoxSort->addItem("By default");
    ui->comBoxSort->addItem("By title(asc)");
    ui->comBoxSort->addItem("By title(desc)");
    ui->comBoxSort->addItem("By author(asc)");
    ui->comBoxSort->addItem("By author(desc)");
    ui->comBoxSort->addItem("By rating(asc)");
    ui->comBoxSort->addItem("By rating(desc)");
    ui->comBoxSort->addItem("By year(asc)");
    ui->comBoxSort->addItem("By year(desc)");
    ui->comBoxSort->addItem("By pages(asc)");
    ui->comBoxSort->addItem("By pages(desc)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_butFindByPref_clicked()
{
    dialogFindPref = new DialogFindPref(this);
    if (dialogFindPref->exec() == QDialog::Accepted)
    {
        QList<QString> searchedParamters = dialogFindPref->getSearchedParamets();
        _modelSortBooks = new ModelSortBooks(searchedParamters, this);
        _modelSortBooks->setSourceModel(_storage->getBookModel());
        ui->viewBookDescr->setModel(_modelSortBooks);
        ui->viewBookDescr->sortByColumn(3, Qt::DescendingOrder); // sorting by rating
    }
}


void MainWindow::on_butAddBook_clicked()
{
    dialogAdd = new DialogAdd(this);
    if (dialogAdd->exec() == QDialog::Accepted)
        _storage->getBookModel()->appendRow(dialogAdd->getNewRow());
}


void MainWindow::on_butDelBook_clicked()
{
    dialogDelete = new DialogDelete(this);
    if (dialogDelete->exec() == QDialog::Accepted)
        _storage->getBookModel()->removeSetRow(dialogDelete->getPair());
}

void MainWindow::findBookTitle(const QString& searchedTitle)
{
    _proxyModelSort->setSourceModel(_storage->getBookModel());
    ui->viewBookDescr->setModel(_proxyModelSort);
    _proxyModelSort->setFilterFixedString(searchedTitle);
    ui->viewBookDescr->setSortingEnabled(true);
}

void MainWindow::on_butFindTitle_clicked()
{
    dialogFindTitle = new DialogFindTitle(this);

    if (dialogFindTitle->exec() == QDialog::Accepted)
         findBookTitle(dialogFindTitle->getSearchedTitle());
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Data Storage File"), "",
                                     tr("Comma Separated Values (*.csv)"));
    if (fileName.isNull())
        return;

    _storage->loadFile(fileName);
    ui->viewBookDescr->setModel(_storage->getBookModel());
}

void MainWindow::onFileRead()
{
    ui->butAddBook->setEnabled(true);
    ui->butFindByPref->setEnabled(true);
    ui->butFindTitle->setEnabled(true);
    ui->butDelBook->setEnabled(true);
    ui->butRes->setEnabled(true);
    ui->comBoxSort->setEnabled(true);
}

void MainWindow::on_butRes_clicked()
{
    ui->viewBookDescr->setModel(_storage->getBookModel());
}

void MainWindow::on_comBoxSort_activated(int index)
{
    _proxyModelSort = new QSortFilterProxyModel(this);
    _proxyModelSort->setSourceModel(_storage->getBookModel());
    ui->viewBookDescr->setModel(_proxyModelSort);
    ui->viewBookDescr->setSortingEnabled(true);

    if (index == 0)
         ui->viewBookDescr->sortByColumn(-1, Qt::AscendingOrder);

    if (index == 1)
        ui->viewBookDescr->sortByColumn(0, Qt::AscendingOrder);

    if (index == 2)
         ui->viewBookDescr->sortByColumn(0, Qt::DescendingOrder);

    if (index == 3)
        ui->viewBookDescr->sortByColumn(1, Qt::AscendingOrder);

    if (index == 4)
         ui->viewBookDescr->sortByColumn(1, Qt::DescendingOrder);

    if (index == 5)
        ui->viewBookDescr->sortByColumn(3, Qt::AscendingOrder);

    if (index == 6)
         ui->viewBookDescr->sortByColumn(3, Qt::DescendingOrder);

    if (index == 7)
        ui->viewBookDescr->sortByColumn(4, Qt::AscendingOrder);

    if (index == 8)
         ui->viewBookDescr->sortByColumn(4, Qt::DescendingOrder);

    if (index == 9)
        ui->viewBookDescr->sortByColumn(5, Qt::AscendingOrder);

    if (index == 10)
         ui->viewBookDescr->sortByColumn(5, Qt::DescendingOrder);
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Open File",
                                                    "../",
                                                    "Data (*.csv)");
    _storage->getBookModel()->saveDataFile(fileName);
}


void MainWindow::on_actionInfo_about_app_triggered()
{
    windowAbout->show();
}
