/********************************************************************************
** Form generated from reading UI file 'CreateBoundaryDi.ui'
**
** Created: Tue Sep 17 14:08:59 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATEBOUNDARYDI_H
#define CREATEBOUNDARYDI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateBoundaryDi
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonHelp;
    QPushButton *buttonCancel;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QCheckBox *CBGroupe;
    QLineEdit *LEFileName;
    QPushButton *PushFichier;
    QLabel *Mesh;
    QLineEdit *LEName;
    QLabel *Name;

    void setupUi(QDialog *CreateBoundaryDi)
    {
        if (CreateBoundaryDi->objectName().isEmpty())
            CreateBoundaryDi->setObjectName(QString::fromUtf8("CreateBoundaryDi"));
        CreateBoundaryDi->resize(566, 169);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateBoundaryDi->sizePolicy().hasHeightForWidth());
        CreateBoundaryDi->setSizePolicy(sizePolicy);
        CreateBoundaryDi->setAutoFillBackground(true);
        CreateBoundaryDi->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(CreateBoundaryDi);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GBButtons = new QGroupBox(CreateBoundaryDi);
        GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
        gridLayout1 = new QGridLayout(GBButtons);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        buttonHelp = new QPushButton(GBButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

        gridLayout1->addWidget(buttonHelp, 0, 3, 1, 1);

        buttonCancel = new QPushButton(GBButtons);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        gridLayout1->addWidget(buttonCancel, 0, 2, 1, 1);

        buttonApply = new QPushButton(GBButtons);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

        gridLayout1->addWidget(buttonApply, 0, 1, 1, 1);

        buttonOk = new QPushButton(GBButtons);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

        gridLayout1->addWidget(buttonOk, 0, 0, 1, 1);


        gridLayout->addWidget(GBButtons, 3, 0, 1, 3);

        CBGroupe = new QCheckBox(CreateBoundaryDi);
        CBGroupe->setObjectName(QString::fromUtf8("CBGroupe"));

        gridLayout->addWidget(CBGroupe, 2, 0, 1, 3);

        LEFileName = new QLineEdit(CreateBoundaryDi);
        LEFileName->setObjectName(QString::fromUtf8("LEFileName"));
        LEFileName->setMinimumSize(QSize(370, 21));

        gridLayout->addWidget(LEFileName, 1, 2, 1, 1);

        PushFichier = new QPushButton(CreateBoundaryDi);
        PushFichier->setObjectName(QString::fromUtf8("PushFichier"));

        gridLayout->addWidget(PushFichier, 1, 1, 1, 1);

        Mesh = new QLabel(CreateBoundaryDi);
        Mesh->setObjectName(QString::fromUtf8("Mesh"));

        gridLayout->addWidget(Mesh, 1, 0, 1, 1);

        LEName = new QLineEdit(CreateBoundaryDi);
        LEName->setObjectName(QString::fromUtf8("LEName"));
        LEName->setMinimumSize(QSize(382, 21));
        LEName->setMaxLength(32);

        gridLayout->addWidget(LEName, 0, 1, 1, 2);

        Name = new QLabel(CreateBoundaryDi);
        Name->setObjectName(QString::fromUtf8("Name"));

        gridLayout->addWidget(Name, 0, 0, 1, 1);


        retranslateUi(CreateBoundaryDi);

        QMetaObject::connectSlotsByName(CreateBoundaryDi);
    } // setupUi

    void retranslateUi(QDialog *CreateBoundaryDi)
    {
        CreateBoundaryDi->setWindowTitle(QApplication::translate("CreateBoundaryDi", "Create a discrete boundary", 0, QApplication::UnicodeUTF8));
        GBButtons->setTitle(QString());
        buttonHelp->setText(QApplication::translate("CreateBoundaryDi", "Help", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CreateBoundaryDi", "Cancel", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("CreateBoundaryDi", "Apply", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("CreateBoundaryDi", "OK", 0, QApplication::UnicodeUTF8));
        CBGroupe->setText(QApplication::translate("CreateBoundaryDi", "Filtering with groups", 0, QApplication::UnicodeUTF8));
        PushFichier->setText(QString());
        Mesh->setText(QApplication::translate("CreateBoundaryDi", "Mesh", 0, QApplication::UnicodeUTF8));
        Name->setText(QApplication::translate("CreateBoundaryDi", "Name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateBoundaryDi: public Ui_CreateBoundaryDi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEBOUNDARYDI_H
