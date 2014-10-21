#ifndef QIBM852CODEC_H
#define QIBM852CODEC_H

#include <QTextCodec>
#include <QStringList>

class QIBM852Codec : public QTextCodec
{
public:
    QIBM852Codec();
    ~QIBM852Codec();
    QByteArray name() const {return "IBM852";}
    QStringList aliases();
    int mibEnum() const {return 2010;}
    QString convertToUnicode(const char *in, int length, ConverterState *state) const ;
    QByteArray convertFromUnicode(const QChar *in, int length, ConverterState *state) const ;
private:
    QTextCodec *IBM850Codec;

};

#endif // QIBM852CODEC_H
