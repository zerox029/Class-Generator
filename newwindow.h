#ifndef HEADER_FENCODEGENERE
#define HEADER_FENCODEGENERE

#include <QtWidgets>

class NewWindow : public QDialog
{
    public:
    NewWindow(QString &code, QWidget *parent);

    private:
    QTextEdit *codeGenere;
    QPushButton *fermer;
};

#endif
