#ifndef DIALOGPRINTTEMPLATE_H
#define DIALOGPRINTTEMPLATE_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>

#include "escposconverter.h"

namespace Ui {
class DialogPrintTemplate;
}

class DialogPrintTemplate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPrintTemplate(QWidget *parent = 0);
    ~DialogPrintTemplate();

private slots:
    void on_pushButtonPrint_clicked();

private:
    Ui::DialogPrintTemplate *ui;
    QSerialPort *m_port;
    ESCPOSDirectConverter m_converter;
};

#endif // DIALOGPRINTTEMPLATE_H
