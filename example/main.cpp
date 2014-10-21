#include "dialogprinttemplate.h"
#include "qibm852codec.h"

#include <QTranslator>
#include <QApplication>

int main(int argc, char *argv[])
{
    QIBM852Codec *codec = new QIBM852Codec();
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("MM");
    QCoreApplication::setApplicationName("QESCPOS test app");
    QCoreApplication::setApplicationVersion("1.0");

    DialogPrintTemplate w;
    w.show();
    return a.exec();
}
