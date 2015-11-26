/********************************************************************************
** Form generated from reading UI file 'EditFile.ui'
**
** Created: Thu Feb 28 13:53:13 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef EDITFILE_H
#define EDITFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditFile
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonPrint;
    QPushButton *buttonQuit;
    QSpacerItem *spacerItem1;
    QTextBrowser *QTBEditFile;

    void setupUi(QWidget *EditFile)
    {
        if (EditFile->objectName().isEmpty())
            EditFile->setObjectName(QString::fromUtf8("EditFile"));
        EditFile->resize(675, 901);
        gridLayout = new QGridLayout(EditFile);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spacerItem = new QSpacerItem(331, 49, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 2, 1, 1, 1);

        GroupButtons = new QGroupBox(EditFile);
        GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
        gridLayout1 = new QGridLayout(GroupButtons);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        buttonPrint = new QPushButton(GroupButtons);
        buttonPrint->setObjectName(QString::fromUtf8("buttonPrint"));
        buttonPrint->setAutoDefault(false);
        buttonPrint->setDefault(false);
        buttonPrint->setFlat(false);

        gridLayout1->addWidget(buttonPrint, 0, 1, 1, 1);

        buttonQuit = new QPushButton(GroupButtons);
        buttonQuit->setObjectName(QString::fromUtf8("buttonQuit"));
        buttonQuit->setAutoDefault(false);
        buttonQuit->setDefault(true);
        buttonQuit->setFlat(false);

        gridLayout1->addWidget(buttonQuit, 0, 0, 1, 1);


        gridLayout->addWidget(GroupButtons, 2, 0, 1, 1);

        spacerItem1 = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem1, 1, 0, 1, 2);

        QTBEditFile = new QTextBrowser(EditFile);
        QTBEditFile->setObjectName(QString::fromUtf8("QTBEditFile"));
        QTBEditFile->setMinimumSize(QSize(530, 800));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        QTBEditFile->setFont(font);

        gridLayout->addWidget(QTBEditFile, 0, 0, 1, 2);


        retranslateUi(EditFile);

        QMetaObject::connectSlotsByName(EditFile);
    } // setupUi

    void retranslateUi(QWidget *EditFile)
    {
        EditFile->setWindowTitle(QApplication::translate("EditFile", "Edit a file", 0));
        GroupButtons->setTitle(QString());
        buttonPrint->setText(QApplication::translate("EditFile", "Print", 0));
        buttonQuit->setText(QApplication::translate("EditFile", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class EditFile: public Ui_EditFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDITFILE_H
