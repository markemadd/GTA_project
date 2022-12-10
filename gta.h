#ifndef GTA_H
#define GTA_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class gta; }
QT_END_NAMESPACE


class gta : public QMainWindow
{
    Q_OBJECT

public:
    gta(QWidget *parent = nullptr);
    ~gta();

private:
    Ui::gta *ui;
};
#endif // GTA_H
