/********************************************************************************
** Form generated from reading UI file 'IterInfo.ui'
**
** Created: Wed Feb 20 17:10:38 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ITERINFO_H
#define ITERINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_IterInfo
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *GBOptions;
    QGridLayout *gridLayout;
    QCheckBox *CBQuality;
    QCheckBox *CBConnection;
    QCheckBox *CBDiametre;
    QCheckBox *CBBlockSize;
    QCheckBox *CBEntanglement;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonHelp;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;

    void setupUi(QDialog *IterInfo)
    {
        if (IterInfo->objectName().isEmpty())
            IterInfo->setObjectName(QString::fromUtf8("IterInfo"));
        IterInfo->resize(420, 220);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IterInfo->sizePolicy().hasHeightForWidth());
        IterInfo->setSizePolicy(sizePolicy);
        IterInfo->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(IterInfo);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        GBOptions = new QGroupBox(IterInfo);
        GBOptions->setObjectName(QString::fromUtf8("GBOptions"));
        gridLayout = new QGridLayout(GBOptions);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CBQuality = new QCheckBox(GBOptions);
        CBQuality->setObjectName(QString::fromUtf8("CBQuality"));

        gridLayout->addWidget(CBQuality, 0, 0, 1, 1);

        CBConnection = new QCheckBox(GBOptions);
        CBConnection->setObjectName(QString::fromUtf8("CBConnection"));

        gridLayout->addWidget(CBConnection, 0, 1, 1, 1);

        CBDiametre = new QCheckBox(GBOptions);
        CBDiametre->setObjectName(QString::fromUtf8("CBDiametre"));

        gridLayout->addWidget(CBDiametre, 1, 0, 1, 1);

        CBBlockSize = new QCheckBox(GBOptions);
        CBBlockSize->setObjectName(QString::fromUtf8("CBBlockSize"));

        gridLayout->addWidget(CBBlockSize, 1, 1, 1, 1);

        CBEntanglement = new QCheckBox(GBOptions);
        CBEntanglement->setObjectName(QString::fromUtf8("CBEntanglement"));

        gridLayout->addWidget(CBEntanglement, 2, 0, 1, 2);


        gridLayout_2->addWidget(GBOptions, 0, 0, 2, 2);

        GroupButtons = new QGroupBox(IterInfo);
        GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
        gridLayout1 = new QGridLayout(GroupButtons);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        buttonHelp = new QPushButton(GroupButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
        buttonHelp->setAutoDefault(false);

        gridLayout1->addWidget(buttonHelp, 0, 4, 1, 1);

        buttonApply = new QPushButton(GroupButtons);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));
        buttonApply->setAutoDefault(false);

        gridLayout1->addWidget(buttonApply, 0, 1, 1, 1);

        buttonOk = new QPushButton(GroupButtons);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(false);

        gridLayout1->addWidget(buttonOk, 0, 0, 1, 1);

        buttonCancel = new QPushButton(GroupButtons);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setAutoDefault(false);

        gridLayout1->addWidget(buttonCancel, 0, 2, 1, 1);


        gridLayout_2->addWidget(GroupButtons, 2, 0, 1, 2);


        retranslateUi(IterInfo);

        QMetaObject::connectSlotsByName(IterInfo);
    } // setupUi

    void retranslateUi(QDialog *IterInfo)
    {
        IterInfo->setWindowTitle(QApplication::translate("IterInfo", "Information on a mesh", 0));
        GBOptions->setTitle(QApplication::translate("IterInfo", "Options", 0));
        CBQuality->setText(QApplication::translate("IterInfo", "Quality", 0));
        CBConnection->setText(QApplication::translate("IterInfo", "Connection", 0));
        CBDiametre->setText(QApplication::translate("IterInfo", "Diametre", 0));
        CBBlockSize->setText(QApplication::translate("IterInfo", "Group size", 0));
        CBEntanglement->setText(QApplication::translate("IterInfo", "Entanglement", 0));
        GroupButtons->setTitle(QString());
        buttonHelp->setText(QApplication::translate("IterInfo", "Help", 0));
        buttonApply->setText(QApplication::translate("IterInfo", "Apply", 0));
        buttonOk->setText(QApplication::translate("IterInfo", "OK", 0));
        buttonCancel->setText(QApplication::translate("IterInfo", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class IterInfo: public Ui_IterInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ITERINFO_H
