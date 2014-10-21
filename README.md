qescpos
=======

Some classes for Qt to interact with ESC/POS printers:

 - ESCPOSDirectConverter: a converter class which takes a QTextDocument and produces a QByteArray which can be sent to the printer.
 - ESCPOSTextEdit - toolbuttons (escpostexteditwidgets.h):
These toolbuttons can be added to your GUI where your QTextEdit lives and if you point to the editor with the setTextEdit method these controls will allow you to format your document with the limited formatting options what the  printer supports. 
 - QIBM852Codec: a code which is a wrapped around the IBM850 codec to translate the hungarian accented characters to fit best similar character from the printer's available characters. **Warning** : this codec is designed only for this purpose, not all the codepage mapped/verified. 
 - example:
A basic example dialog which showcases the functionality of the classes above. It uses QSerialPort for sending data to the printer.

TODO: 

 - QIBM852Codec cleanup 
 - Figure out a better method for the text editing,
   because the QTextEdit has a lot of limitations which can be a trivial
   use case. For e.g.: two textblocks in one row one aligned to left
   another aligned to right is not supported. Some webkit based approach
   would eliminate this problem. 
 - Image support [possibly usable code snipplet here](http://madsdyd.wordpress.com/2010/10/19/printing-a-bitmap-with-the-pos-104-prp-085iiit-receipt-printer/#comments)
