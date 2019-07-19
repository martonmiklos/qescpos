#include "escpostexteditwidgets.h"

#include <QDebug>

ESCPOSToolButton::ESCPOSToolButton(QWidget *parent)
    : QToolButton(parent), ESCPOSToolWidget()
{
    setCheckable(true);
    connect(this, &QToolButton::clicked, this, &ESCPOSToolButton::clicked);
}

void ESCPOSTextEditAlignLeft::clicked()
{
    if (m_textEdit != nullptr)
        m_textEdit->setAlignment(Qt::AlignLeft);
}

void ESCPOSTextEditAlignRight::clicked()
{
    if (m_textEdit != nullptr)
        m_textEdit->setAlignment(Qt::AlignRight);
}



void ESCPOSTextEditAlignCenter::clicked()
{
    if (m_textEdit != nullptr)
        m_textEdit->setAlignment(Qt::AlignCenter);
}


void ESCPOSTextEditBold::setStateFromFormat(const QTextCharFormat &format)
{
    setChecked(format.fontWeight() == QFont::Bold);
}

void ESCPOSTextEditBold::clicked()
{
    if (m_textEdit != nullptr) {
        QTextCursor cursor = m_textEdit->textCursor();
        if (!cursor.hasSelection())
            cursor.select(QTextCursor::WordUnderCursor);
        QTextCharFormat format = cursor.charFormat();
        if (format.fontWeight() == QFont::Bold)
            format.setFontWeight(QFont::Normal);
        else
            format.setFontWeight(QFont::Bold);
        m_textEdit->mergeCurrentCharFormat(format);
    }
}

void ESCPOSTextEditUnderLine::setStateFromFormat(const QTextCharFormat &format)
{
    setChecked(format.underlineStyle() == QTextCharFormat::SingleUnderline);
}

void ESCPOSTextEditUnderLine::clicked()
{
    if (m_textEdit != nullptr) {
        QTextCursor cursor = m_textEdit->textCursor();
        if (!cursor.hasSelection())
            cursor.select(QTextCursor::WordUnderCursor);
        QTextCharFormat format = cursor.charFormat();
        if (format.underlineStyle() == QTextCharFormat::NoUnderline)
            format.setUnderlineStyle(QTextCharFormat::SingleUnderline);
        else
            format.setUnderlineStyle(QTextCharFormat::NoUnderline);
        m_textEdit->mergeCurrentCharFormat(format);
    }
}


ESCPOSFontSizeComboBox::ESCPOSFontSizeComboBox(QWidget *parent) :
    QComboBox(parent), ESCPOSToolWidget()
{
    addItem(tr("Font B (~ 9pt)"));
    addItem(tr("Font A (~ 12pt)"));
    connect(this, SIGNAL(activated(int)), this, SLOT(activatedSlot(int)));
}

void ESCPOSFontSizeComboBox::setStateFromFormat(const QTextCharFormat &format)
{
    setCurrentIndex(qFuzzyCompare(format.fontPointSize(), 9.0) ? 0 : 1);
}

void ESCPOSFontSizeComboBox::activatedSlot(int index)
{
    if (m_textEdit != nullptr) {
        QTextCursor cursor = m_textEdit->textCursor();
        if (!cursor.hasSelection())
            cursor.select(QTextCursor::WordUnderCursor);
        QTextCharFormat format = cursor.charFormat();
        format.setFontPointSize(index == 0?9:12);
        m_textEdit->mergeCurrentCharFormat(format);
    }
}

ESCPOSToolWidget::ESCPOSToolWidget() :
    m_textEdit(nullptr)
{
    m_charm = new ESCPOSToolWidgetCharm(this);
}

ESCPOSToolWidget::~ESCPOSToolWidget()
{
    delete m_charm;
}

void ESCPOSToolWidget::setTextEdit(QTextEdit *textEdit)
{
    m_textEdit = textEdit;
    m_charm->setTextEdit(textEdit);
}

void ESCPOSToolWidget::unsetCurrentTextEdit()
{
    m_charm->unsetCurrentTextEdit();
    m_textEdit = nullptr;
}

void ESCPOSToolWidget::setStateFromFormat(const QTextCharFormat &format)
{
    Q_UNUSED(format);
}

ESCPOSToolWidgetCharm::ESCPOSToolWidgetCharm(ESCPOSToolWidget *widget) :
    QObject (nullptr),
    m_widget(widget)
{

}

void ESCPOSToolWidgetCharm::setStateFromFormat(const QTextCharFormat &format)
{
    m_widget->setStateFromFormat(format);
}

void ESCPOSToolWidgetCharm::setTextEdit(QTextEdit *textEdit)
{
    m_textEdit = textEdit;
    connect(m_textEdit, &QTextEdit::currentCharFormatChanged, this, &ESCPOSToolWidgetCharm::setStateFromFormat);
}

void ESCPOSToolWidgetCharm::unsetCurrentTextEdit()
{
    if (m_textEdit)
        disconnect(m_textEdit, &QTextEdit::currentCharFormatChanged, this, &ESCPOSToolWidgetCharm::setStateFromFormat);
    m_textEdit = nullptr;
}
