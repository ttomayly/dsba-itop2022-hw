#ifndef WINDOWABOUT_H
#define WINDOWABOUT_H

#include <QDialog>

namespace Ui {
class windowAbout;
}

class WindowAbout : public QDialog
{
    Q_OBJECT

public:
    explicit WindowAbout(QWidget *parent = nullptr);
    ~WindowAbout();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::windowAbout *ui;
};

#endif // WINDOWABOUT_H
