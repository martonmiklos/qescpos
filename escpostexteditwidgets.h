#ifndef ESCPOSTEXTEDITWIDGETS_H
#define ESCPOSTEXTEDITWIDGETS_H

#include <QToolButton>
#include <QComboBox>
#include <QTextEdit>


class ESCPOSToolWidget
{
public:
    ESCPOSToolWidget() : m_textEdit(NULL) {}
    void setTextEdit(QTextEdit* textEdit) {m_textEdit = textEdit;}

protected:
    QTextEdit* m_textEdit;
};

class ESCPOSToolButton : public QToolButton, public ESCPOSToolWidget
{
    Q_OBJECT
public:
    ESCPOSToolButton(QWidget *parent = 0);

protected slots:
    virtual void clicked() = 0;
};

class ESCPOSTextEditAlignLeft : public ESCPOSToolButton
{
    Q_OBJECT
public:
    ESCPOSTextEditAlignLeft(QWidget *parent = 0) : ESCPOSToolButton(parent) {}
private slots:
    void clicked();
};

class ESCPOSTextEditAlignRight : public ESCPOSToolButton
{
    Q_OBJECT
public:
    ESCPOSTextEditAlignRight(QWidget *parent = 0) : ESCPOSToolButton(parent) {}
private slots:
    void clicked();
};

class ESCPOSTextEditAlignCenter : public ESCPOSToolButton
{
    Q_OBJECT
public:
    ESCPOSTextEditAlignCenter(QWidget *parent = 0) : ESCPOSToolButton(parent) {}
private slots:
    void clicked();
};

class ESCPOSTextEditBold : public ESCPOSToolButton
{
    Q_OBJECT
public:
    ESCPOSTextEditBold(QWidget *parent = 0) : ESCPOSToolButton(parent) {}
private slots:
    void clicked();
};

class ESCPOSTextEditUnderLine : public ESCPOSToolButton
{
    Q_OBJECT
public:
    ESCPOSTextEditUnderLine(QWidget *parent = 0) : ESCPOSToolButton(parent) {}
private slots:
    void clicked();
};

class ESCPOSFontSizeComboBox : public QComboBox, public ESCPOSToolWidget
{
    Q_OBJECT
public:
    ESCPOSFontSizeComboBox(QWidget *parent = 0);

private slots:
    void activatedSlot(int index);
};

#endif // ESCPOSTEXTEDITWIDGETS_H
