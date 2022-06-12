#include "dialogadd.h"
#include "ui_dialogadd.h"

DialogAdd::DialogAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
}

DialogAdd::~DialogAdd()
{
    delete ui;
}

void DialogAdd::on_butAdd_clicked()
{
    _newRow.push_back(ui->editTitle->text());
    _newRow.push_back(ui->editAuthor->text());
    _newRow.push_back(ui->editGenre->text());
    _newRow.push_back(ui->editRating->text());
    _newRow.push_back(ui->editYear->text());
    _newRow.push_back(ui->editPages->text());
    _newRow.push_back(ui->editLang->text());
    _newRow.push_back(ui->editDescr->text());

    accept();
}
