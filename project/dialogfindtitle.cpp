#include "dialogfindtitle.h"
#include "ui_dialogfindtitle.h"

DialogFindTitle::DialogFindTitle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFindTitle)
{
    ui->setupUi(this);
}

DialogFindTitle::~DialogFindTitle()
{
    delete ui;
}

void DialogFindTitle::on_butFindByTtitle_clicked()
{
     _searchedTitle = ui->editTtitleFind->text();

     accept();
}
