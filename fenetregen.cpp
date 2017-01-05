#include "fenetregen.h"

FenetreGen::FenetreGen(QString code)
{
    m_codeBlock = new QTextEdit();
    m_codeBlock->setPlainText("hey");
    m_codeBlock->setReadOnly(true);
    m_codeBlock->setFont(QFont("Courrier"));
    m_codeBlock->setLineWrapMode(QTextEdit::NoWrap);
}
