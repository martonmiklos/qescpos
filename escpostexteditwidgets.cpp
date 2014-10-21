#include "escpostexteditwidgets.h"

ESCPOSToolButton::ESCPOSToolButton(QWidget *parent)
    : QToolButton(parent), ESCPOSToolWidget()
{
    connect(this, SIGNAL(clicked()), this, SLOT(clicked()));
}

void ESCPOSTextEditAlignLeft::clicked()
{
    if (m_textEdit != NULL)
        m_textEdit->setAlignment(Qt::AlignLeft);
}



void ESCPOSTextEditAlignRight::clicked()
{
    if (m_textEdit != NULL)
        m_textEdit->setAlignment(Qt::AlignRight);
}


void ESCPOSTextEditAlignCenter::clicked()
{
    if (m_textEdit != NULL)
        m_textEdit->setAlignment(Qt::AlignCenter);
}


void ESCPOSTextEditBold::clicked()
{
    if (m_textEdit != NULL) {
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


void ESCPOSTextEditUnderLine::clicked()
{
    if (m_textEdit != NULL) {
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

void ESCPOSFontSizeComboBox::activatedSlot(int index)
{
    if (m_textEdit != NULL) {
        QTextCursor cursor = m_textEdit->textCursor();
        if (!cursor.hasSelection())
            cursor.select(QTextCursor::WordUnderCursor);
        QTextCharFormat format = cursor.charFormat();
        format.setFontPointSize(index == 0?9:12);
        m_textEdit->mergeCurrentCharFormat(format);
    }
}
