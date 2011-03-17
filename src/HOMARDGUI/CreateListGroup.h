/********************************************************************************
** Form generated from reading ui file 'CreateListGroup.ui'
**
** Created: Thu Nov 18 16:31:34 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef CREATELISTGROUP_H
#define CREATELISTGROUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateListGroup
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GBOptions;
    QGridLayout *gridLayout_7;
    QTableWidget *TWGroupe;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout_5;
    QPushButton *buttonOk;
    QPushButton *buttonApply;
    QPushButton *buttonCancel;
    QPushButton *buttonHelp;

    void setupUi(QDialog *CreateListGroup)
    {
        if (CreateListGroup->objectName().isEmpty())
            CreateListGroup->setObjectName(QString::fromUtf8("CreateListGroup"));
        CreateListGroup->resize(717, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateListGroup->sizePolicy().hasHeightForWidth());
        CreateListGroup->setSizePolicy(sizePolicy);
        CreateListGroup->setAutoFillBackground(false);
        CreateListGroup->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(CreateListGroup);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GBOptions = new QGroupBox(CreateListGroup);
        GBOptions->setObjectName(QString::fromUtf8("GBOptions"));
        gridLayout_7 = new QGridLayout(GBOptions);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        TWGroupe = new QTableWidget(GBOptions);
        if (TWGroupe->columnCount() < 2)
            TWGroupe->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TWGroupe->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TWGroupe->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        TWGroupe->setObjectName(QString::fromUtf8("TWGroupe"));
        TWGroupe->setShowGrid(true);
        TWGroupe->setRowCount(0);
        TWGroupe->setColumnCount(2);

        gridLayout_7->addWidget(TWGroupe, 0, 0, 1, 1);


        gridLayout->addWidget(GBOptions, 0, 0, 1, 1);

        GBButtons = new QGroupBox(CreateListGroup);
        GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
        gridLayout_5 = new QGridLayout(GBButtons);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        buttonOk = new QPushButton(GBButtons);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

        gridLayout_5->addWidget(buttonOk, 0, 0, 1, 1);

        buttonApply = new QPushButton(GBButtons);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

        gridLayout_5->addWidget(buttonApply, 0, 1, 1, 1);

        buttonCancel = new QPushButton(GBButtons);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        gridLayout_5->addWidget(buttonCancel, 0, 2, 1, 1);

        buttonHelp = new QPushButton(GBButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

        gridLayout_5->addWidget(buttonHelp, 0, 3, 1, 1);


        gridLayout->addWidget(GBButtons, 1, 0, 1, 1);


        retranslateUi(CreateListGroup);

        QMetaObject::connectSlotsByName(CreateListGroup);
    } // setupUi

    void retranslateUi(QDialog *CreateListGroup)
    {
        CreateListGroup->setWindowTitle(QApplication::translate("CreateListGroup", "Create Hypothesis - Group selection", 0, QApplication::UnicodeUTF8));
        GBOptions->setTitle(QApplication::translate("CreateListGroup", "Selected groups", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = TWGroupe->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CreateListGroup", "Selection", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = TWGroupe->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CreateListGroup", "Group", 0, QApplication::UnicodeUTF8));
        GBButtons->setTitle(QString());
        buttonOk->setText(QApplication::translate("CreateListGroup", "&Ok", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("CreateListGroup", "&Apply", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CreateListGroup", "&Cancel", 0, QApplication::UnicodeUTF8));
        buttonHelp->setText(QApplication::translate("CreateListGroup", "&Help", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(CreateListGroup);
    } // retranslateUi

};

namespace Ui {
    class CreateListGroup: public Ui_CreateListGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATELISTGROUP_H
