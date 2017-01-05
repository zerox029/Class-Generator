#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QGroupBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QObject>

class MaFenetre : public QWidget
{
Q_OBJECT

public:
    MaFenetre();

public slots:
    void generateClass();

private:
//Layouts
    QFormLayout *m_classDefinitionForm;
    QFormLayout *m_classCommentsForm;
    QVBoxLayout *m_VOptionsBox;
    QHBoxLayout *m_buttonsLayout;
    QVBoxLayout *m_all;

//Line Edits
    QLineEdit *m_className;
    QLineEdit *m_parentClassName;
    QLineEdit *m_classAuthor;

//Check Boxes
    QCheckBox *m_multipleInclusions;
    QCheckBox *m_defaultConstructor;
    QCheckBox *m_destructor;

//Group Boxes
    QGroupBox *m_classDefinitionBox;
    QGroupBox *m_optionsBox;
    QGroupBox *m_commentBox;

//Date Edits
    QDateEdit *m_creationDate;

//Text Edits
    QTextEdit *m_classRole;

//Buttons
    QPushButton *m_generate;
    QPushButton *m_quit;

};

#endif
