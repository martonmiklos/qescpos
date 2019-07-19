#ifndef ESCPOSTEXTEDITWIDGETS_H
#define ESCPOSTEXTEDITWIDGETS_H

#include <QToolButton>
#include <QComboBox>
#include <QTextEdit>

class ESCPOSToolWidgetCharm;

class ESCPOSToolWidget
{
public:
    ESCPOSToolWidget();
    ~ESCPOSToolWidget();
    void setTextEdit(QTextEdit* textEdit);
    void unsetCurrentTextEdit();

    virtual void setStateFromFormat(const QTextCharFormat & format);

protected:
    QTextEdit* m_textEdit;
    ESCPOSToolWidgetCharm *m_charm;
};

class ESCPOSToolWidgetCharm : public QObject
{
    Q_OBJECT
public:
    ESCPOSToolWidgetCharm(ESCPOSToolWidget *widget);
public slots:
    void setStateFromFormat(const QTextCharFormat & format);

    void setTextEdit(QTextEdit* textEdit);
    void unsetCurrentTextEdit();

private:
    ESCPOSToolWidget *m_widget = nullptr;
    QTextEdit *m_textEdit = nullptr;
};

class ESCPOSToolButton : public QToolButton, public ESCPOSToolWidget
{
    Q_OBJECT
public:
    ESCPOSToolButton(QWidget *parent = nullptr);

protected slots:
    virtual void clicked() = 0;
};

class ESCPOSTextEditAlignLeft : public ESCPOSToolButton
{
    Q_OBJECT
public:
    ESCPOSTextEditAlignLeft(QWidget *parent = nullptr) : ESCPOSToolButton(parent) {}
private slots:
    void clicked() override;
};

class ESCPOSTextEditAlignRight : public ESCPOSToolButton
{
    Q_OBJECT
public:
    ESCPOSTextEditAlignRight(QWidget *parent = nullptr) : ESCPOSToolButton(parent) {}
private slots:
    void clicked() override;
};

class ESCPOSTextEditAlignCenter : public ESCPOSToolButton
{
    Q_OBJECT
public:
    ESCPOSTextEditAlignCenter(QWidget *parent = nullptr) : ESCPOSToolButton(parent) {}
private slots:
    void clicked() override;
};

class ESCPOSTextEditBold : public ESCPOSToolButton
{
    Q_OBJECT
public:
    ESCPOSTextEditBold(QWidget *parent = nullptr) : ESCPOSToolButton(parent) {}
    virtual void setStateFromFormat(const QTextCharFormat & format) override;

private slots:
    void clicked() override;
};

class ESCPOSTextEditUnderLine : public ESCPOSToolButton
{
    Q_OBJECT
public:
    ESCPOSTextEditUnderLine(QWidget *parent = nullptr) : ESCPOSToolButton(parent) {}
    virtual void setStateFromFormat(const QTextCharFormat & format) override;

private slots:
    void clicked() override;
};

class ESCPOSFontSizeComboBox : public QComboBox, public ESCPOSToolWidget
{
    Q_OBJECT
public:
    ESCPOSFontSizeComboBox(QWidget *parent = nullptr);
    void setStateFromFormat(const QTextCharFormat & format) override;
private slots:
    void activatedSlot(int index);
};

#endif // ESCPOSTEXTEDITWIDGETS_H
