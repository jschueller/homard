/********************************************************************************
** Form generated from reading ui file 'EditFile.ui'
**
** Created: Mon Sep 27 14:45:55 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
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
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditFile
{
public:
    QGridLayout *gridLayout_2;
    QTextBrowser *QTBEditFile;
    QSpacerItem *verticalSpacer;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout;
    QPushButton *buttonQuit;
    QPushButton *buttonPrint;
    QPushButton *buttonHelp;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *EditFile)
    {
        if (EditFile->objectName().isEmpty())
            EditFile->setObjectName(QString::fromUtf8("EditFile"));
        EditFile->resize(548, 901);
        gridLayout_2 = new QGridLayout(EditFile);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        QTBEditFile = new QTextBrowser(EditFile);
        QTBEditFile->setObjectName(QString::fromUtf8("QTBEditFile"));
        QTBEditFile->setMinimumSize(QSize(530, 800));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        QTBEditFile->setFont(font);

        gridLayout_2->addWidget(QTBEditFile, 0, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        GroupButtons = new QGroupBox(EditFile);
        GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
        gridLayout = new QGridLayout(GroupButtons);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonQuit = new QPushButton(GroupButtons);
        buttonQuit->setObjectName(QString::fromUtf8("buttonQuit"));
        buttonQuit->setAutoDefault(true);
        buttonQuit->setDefault(true);
        buttonQuit->setFlat(true);

        gridLayout->addWidget(buttonQuit, 0, 0, 1, 1);

        buttonPrint = new QPushButton(GroupButtons);
        buttonPrint->setObjectName(QString::fromUtf8("buttonPrint"));

        gridLayout->addWidget(buttonPrint, 0, 1, 1, 1);

        buttonHelp = new QPushButton(GroupButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

        gridLayout->addWidget(buttonHelp, 0, 2, 1, 1);


        gridLayout_2->addWidget(GroupButtons, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(249, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 1, 1, 1);


        retranslateUi(EditFile);

        QMetaObject::connectSlotsByName(EditFile);
    } // setupUi

    void retranslateUi(QWidget *EditFile)
    {
        EditFile->setWindowTitle(QApplication::translate("EditFile", "Edit File", 0, QApplication::UnicodeUTF8));
        GroupButtons->setTitle(QString());
        buttonQuit->setText(QApplication::translate("EditFile", "&Quit", 0, QApplication::UnicodeUTF8));
        buttonPrint->setText(QApplication::translate("EditFile", "&Print", 0, QApplication::UnicodeUTF8));
        buttonHelp->setText(QApplication::translate("EditFile", "&Help", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(EditFile);
    } // retranslateUi

};

namespace Ui {
    class EditFile: public Ui_EditFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDITFILE_H
