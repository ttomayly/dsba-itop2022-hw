#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>

namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdd(QWidget *parent = nullptr);
    ~DialogAdd();
    QList<QVariant> getNewRow() const {return _newRow;}

private slots:
    void on_butAdd_clicked();

private:
    Ui::DialogAdd *ui;
    QList<QVariant> _newRow;
};

#endif // DIALOGADD_H
