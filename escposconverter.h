#ifndef ESCPOSCONVERTER_H
#define ESCPOSCONVERTER_H

#include <QObject>
#include <QTextDocument>
#include <QTextDocumentFragment>
#include <QTextBlock>
#include <QDebug>

#include "qibm852codec.h"


class ESCPOSConverter : public QObject
{
    Q_OBJECT
public:
    ESCPOSConverter(QObject *parent = 0);
    virtual QByteArray convert(QTextDocument *doc) = 0;

protected:
    QByteArray setAlignment(Qt::Alignment);
    QByteArray setFormat(QTextFragment fragment);
    QIBM852Codec *codec;
};

class ESCPOSDirectConverter : public ESCPOSConverter
{
    Q_OBJECT
public:
    ESCPOSDirectConverter(QObject *parent = 0);
    QByteArray convert(QTextDocument *doc);
};


#endif // ESCPOSCONVERTER_H
