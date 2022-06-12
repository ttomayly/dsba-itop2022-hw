#include "dialogdelete.h"
#include "ui_dialogdelete.h"

DialogDelete::DialogDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDelete)
{
    ui->setupUi(this);
}

DialogDelete::~DialogDelete()
{
    delete ui;
}

void DialogDelete::on_butDelete_clicked()
{
    _pairTitleAuthor.first = ui->editTitleDel->text();
    _pairTitleAuthor.second = ui->editAuthorDel->text();

    accept();
}
