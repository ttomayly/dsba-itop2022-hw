#ifndef DIALOGDELETE_H
#define DIALOGDELETE_H

#include <QDialog>

namespace Ui {
class DialogDelete;
}

class DialogDelete : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDelete(QWidget *parent = nullptr);
    ~DialogDelete();
    QPair<QString, QString> getPair() const {return _pairTitleAuthor;}

private slots:
    void on_butDelete_clicked();

private:
    Ui::DialogDelete *ui;
    QPair<QString, QString> _pairTitleAuthor;
};

#endif // DIALOGDELETE_H
