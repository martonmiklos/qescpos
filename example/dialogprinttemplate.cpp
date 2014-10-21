#include "dialogprinttemplate.h"
#include "ui_dialogprinttemplate.h"

#include <QMessageBox>
#include <QDebug>
#include <QFile>

DialogPrintTemplate::DialogPrintTemplate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPrintTemplate)
{
    ui->setupUi(this);
    ui->toolButtonAlignLeft->setTextEdit(ui->textEditBody);
    ui->toolButtonAlignRight->setTextEdit(ui->textEditBody);
    ui->toolButtonAlignCenter->setTextEdit(ui->textEditBody);
    ui->toolButtonBold->setTextEdit(ui->textEditBody);
    ui->toolButtonUnderLine->setTextEdit(ui->textEditBody);
    ui->comboBoxFontType->setTextEdit(ui->textEditBody);

    m_port = new QSerialPort(this);
    m_port->setBaudRate(115200);
    m_port->setDataBits(QSerialPort::Data8);
    m_port->setParity(QSerialPort::NoParity);
    m_port->setStopBits(QSerialPort::OneStop);
    m_port->setPortName("/dev/ttyS0");
    if (!m_port->open(QSerialPort::ReadWrite)) {
        QMessageBox::warning(this,
                             tr("Unable to open the port!"),
                             tr("Unable to open the %1 serial port!\nError:%2").arg(m_port->portName()).arg(m_port->errorString())
                             );
    }
}

DialogPrintTemplate::~DialogPrintTemplate()
{
    delete ui;
}


void DialogPrintTemplate::on_pushButtonPrint_clicked()
{
    if (!m_port->isOpen()) {
        if (!m_port->open(QSerialPort::ReadWrite)) {
            QMessageBox::warning(this,
                                 tr("Port is not open!").arg(m_port->portName()),
                                 tr("The serial port is closed")
                                 );
        }
    } else {
        m_port->write(m_converter.convert(ui->textEditBody->document()));
    }
}
