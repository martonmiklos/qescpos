#include "qibm852codec.h"
#include <QDebug>
QIBM852Codec::QIBM852Codec() :
    QTextCodec()
{
    IBM850Codec = QTextCodec::codecForName("IBM850");
}

QStringList QIBM852Codec::aliases()
{
    QStringList ret;
    ret << "ibm-852_P100-1995"
        << "ibm-852"
        << "IBM852"
        << "cp852"
        << "852"
        << "csPCp852"
        << "windows-852";
    return ret;
}

QString QIBM852Codec::convertToUnicode(const char *in, int length, ConverterState *state) const
{
    if (IBM850Codec == NULL) {
        return "";
    } else {
        return IBM850Codec->toUnicode(in, length, state);
    }
}

QByteArray QIBM852Codec::convertFromUnicode(const QChar *in, int length, ConverterState *state) const
{
    Q_UNUSED(state)
    if (IBM850Codec == NULL) {
        return "";
    } else {
        QByteArray ret;
        for (int i = 0; i<length; i++) {
            switch (in[i].unicode()) {
            case 369: // ű
                ret.append(150);
                break;
            case 337: // ő
                ret.append(147);
                break;
            case 193: // Á
                ret.append(143);
                break;
            case 205: // Í
                ret.append(141);
                break;
            case 368: // Ű
                ret.append(85);
                break;
            case 336: // Ő
                ret.append(153);
                break;
            case 218: // Ú
                ret.append(85);
                break;
            case 211: // Ó
                ret.append(79);
                break;
            default:
                ret.append(IBM850Codec->fromUnicode(&in[i], 1));
                break;
            }
        }
        return ret;
    }

}


QIBM852Codec::~QIBM852Codec()
{

}
