#include "mafenetre.h"
#include "newwindow.h"

void MaFenetre::generateClass()
{
    if(!m_className->text().isEmpty())
    {
        QString code;

        //adding the comment section
        if (m_commentBox->isChecked())
        {
            code += tr("/*\nAuthor : ") + m_classAuthor->text() + "\n";
            code += tr("Creation Date : ") + m_creationDate->date().toString() + "\n\n";
            code += tr("Role :\n") + m_classRole->toPlainText() + "\n*/\n\n\n";
        }

        //adding the header
        if (m_multipleInclusions->isChecked())
        {
            code += "#ifndef HEADER_NAME \n";
            code += "#define HEADER_NAME \n\n";
        }

        //Adding the base class code
        code += "class " + m_className->text();

        //Adding the parent class
        if (!m_parentClassName->text().isEmpty())
        {
            code += " : public " + m_parentClassName->text() + "\n";
            code += "{\n";
        }

        //Adding the default constructor
        if (m_defaultConstructor->isChecked())
        {
            code += "public:\n";
            code += "    ";
            code += m_className->text() + ";\n";
        }

        //Adding a destructor
        if (m_destructor->isChecked())
        {
            code += "    ~" + m_className->text() + ";\n\n";
        }

        //Adding private and protected keywords
        code += "\nprivate:\n\n";
        code += "protected:\n\n";
        code += "};";

        NewWindow *codeWindow = new NewWindow(code, this);
        codeWindow->setWindowTitle("Class Generator");
        codeWindow->exec();
    }else{
        QMessageBox::critical(this,tr("No class name"), tr("Please add a name to your class"));
    }
}

MaFenetre::MaFenetre() : QWidget()
{
    m_all = new QVBoxLayout(this);

//Class Definition
    m_classDefinitionForm = new QFormLayout();//form containing 2 elements
    m_classDefinitionBox = new QGroupBox(tr("Class Definition"), this);//box containing the form

    m_className = new QLineEdit();
    m_parentClassName = new QLineEdit();

    m_classDefinitionForm->addRow(tr("Class Name"), m_className);
    m_classDefinitionForm->addRow(tr("Parent Class"), m_parentClassName);

    m_classDefinitionBox->setLayout(m_classDefinitionForm);

    m_all->addWidget(m_classDefinitionBox);

//Options
    m_optionsBox = new QGroupBox(tr("Options"), this);
    m_VOptionsBox = new QVBoxLayout();

    m_multipleInclusions = new QCheckBox(tr("Protect the class against multiple inclusions"));
    m_defaultConstructor = new QCheckBox(tr("Add a default constructor"));
    m_destructor = new QCheckBox(tr("Add a destructor"));

    m_VOptionsBox->addWidget(m_multipleInclusions);
    m_VOptionsBox->addWidget(m_defaultConstructor);
    m_VOptionsBox->addWidget(m_destructor);

    m_optionsBox->setLayout(m_VOptionsBox);

    m_all->addWidget(m_optionsBox);

//Comments
    m_commentBox = new QGroupBox(tr("Add comments"), this);
    m_commentBox->setCheckable(true);
    m_classCommentsForm = new QFormLayout();
    m_classAuthor = new QLineEdit();
    m_creationDate = new QDateEdit();
    m_classRole = new QTextEdit();

    m_classCommentsForm->addRow(tr("Author:"), m_classAuthor);
    m_classCommentsForm->addRow(tr("Creation Date"), m_creationDate);
    m_classCommentsForm->addRow(tr("Class Role"), m_classRole);

    m_commentBox->setLayout(m_classCommentsForm);
    m_all->addWidget(m_commentBox);

//Buttons
    m_generate = new QPushButton(tr("Generate"));
    m_quit = new QPushButton(tr("Quit"));
    m_buttonsLayout = new QHBoxLayout();

    QObject::connect(m_quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_generate, SIGNAL(clicked()), this, SLOT(generateClass()));

    m_buttonsLayout->addWidget(m_generate);
    m_buttonsLayout->addWidget(m_quit);

    m_all->addLayout(m_buttonsLayout);
}
