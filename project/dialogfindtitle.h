#ifndef DIALOGFINDTITLE_H
#define DIALOGFINDTITLE_H

#include <QDialog>

namespace Ui {
class DialogFindTitle;
}

class DialogFindTitle : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFindTitle(QWidget *parent = nullptr);
    ~DialogFindTitle();

private slots:
    void on_butFindByTtitle_clicked();

public:
    QString getSearchedTitle() const {return _searchedTitle;}

private:
    Ui::DialogFindTitle *ui;
    QString _searchedTitle;
};

#endif
