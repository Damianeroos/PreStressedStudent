#ifndef DIALOGAUTHORSINFO_H
#define DIALOGAUTHORSINFO_H

#include <QDialog>

namespace Ui {
class DialogAuthorsInfo;
}

class DialogAuthorsInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAuthorsInfo(QWidget *parent = nullptr);
    ~DialogAuthorsInfo();

private:
    Ui::DialogAuthorsInfo *ui;
};

#endif // DIALOGAUTHORSINFO_H
