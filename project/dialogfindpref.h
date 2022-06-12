#ifndef DIALOGFINDPREF_H
#define DIALOGFINDPREF_H

#include <QDialog>

namespace Ui {
class DialogFindPref;
}

class DialogFindPref : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFindPref(QWidget *parent = nullptr);
    ~DialogFindPref();

public:
    QList<QString> getSearchedParamets() const {return _searchedParamters;}


private slots:
    void on_butFindPref_clicked();

private:
    Ui::DialogFindPref *ui;
    QList<QString> _searchedParamters;
};

#endif // DIALOGFINDPREF_H
