#include "dialogfindpref.h"
#include "ui_dialogfindpref.h"

DialogFindPref::DialogFindPref(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFindPref)
{

    ui->setupUi(this);
}

DialogFindPref::~DialogFindPref()
{
    delete ui;
}

void DialogFindPref::on_butFindPref_clicked()
{
    _searchedParamters.push_back(ui->editTitle->text());
    _searchedParamters.push_back(ui->editAuthor->text());
    _searchedParamters.push_back(ui->editGenre->text());
    _searchedParamters.push_back(ui->editRating->text());
    _searchedParamters.push_back(ui->editYear->text());
    _searchedParamters.push_back(ui->editPages->text());
    _searchedParamters.push_back(ui->editLang->text());
    _searchedParamters.push_back(ui->editDesc->text());

    accept();
}
