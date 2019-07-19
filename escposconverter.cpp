#include "escposconverter.h"


ESCPOSConverter::ESCPOSConverter(QObject *parent) :
    QObject(parent)
{
    codec = new QIBM852Codec();
}

ESCPOSDirectConverter::ESCPOSDirectConverter(QObject *parent) :
    ESCPOSConverter(parent)
{
}


QByteArray ESCPOSDirectConverter::convert(QTextDocument* doc)
{
    QByteArray ret;
    for (QTextBlock block = doc->begin(); block != doc->end(); block = block.next()) {
        ret.append(setAlignment(block.blockFormat().alignment()));
        QTextBlock::iterator it = block.begin();
        for(;!(it.atEnd()); ++it) {
            ret.append(setFormat(it.fragment()));
            //ret.append(codec->fromUnicode(it.fragment().text()));
            ret.append(codec->convertFromUnicode(it.fragment().text().data(), it.fragment().length(), nullptr));
        }
        ret.append(0x1B);
        ret.append(0x64);
        ret.append(0x01);
    }
    return ret;
}

QByteArray ESCPOSConverter::setAlignment(Qt::Alignment align)
{
    QByteArray ret;
    ret.append(0x1B);
    ret.append(0x61);
    if (align & Qt::AlignHCenter)
        ret.append(49);
    else if (align & Qt::AlignRight)
        ret.append(50);
    else
        ret.append(48); // left by default

    return ret;
}

QByteArray ESCPOSConverter::setFormat(QTextFragment fragment)
{
    QByteArray ret;
    ret.append(0x1B);
    ret.append(0x21);
    quint8 formatByte = 0;

    if (fragment.charFormat().fontPointSize() == 9) {
        formatByte |= 1;
        //qWarning() << "font: 9pt ";
    }

    if (fragment.charFormat().fontWeight() > 50) {
        formatByte |= 8;
        //qWarning() << "font: bold " << fragment.charFormat().fontWeight();
    }

    if (fragment.charFormat().underlineStyle() !=  QTextCharFormat::NoUnderline) {
        formatByte |= 128;
        //qWarning() << "font: underline ";
    }

    ret.append(formatByte);
    return ret;
}
