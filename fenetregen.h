#ifndef FENETREGEN_H
#define FENETREGEN_H

#include <QTextEdit>
#include <QPushButton>

class FenetreGen
{
public:
    FenetreGen(QString &code, QWidget *parent);

private:
    QTextEdit *m_codeBlock;
    QPushButton *m_quit;
};

#endif // FENETREGEN_H
