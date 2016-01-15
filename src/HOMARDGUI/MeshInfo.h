/********************************************************************************
** Form generated from reading UI file 'MeshInfo.ui'
**
** Created: Tue Feb 19 10:05:35 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MESHINFO_H
#define MESHINFO_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_MeshInfo
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *hboxLayout;
    QLabel *Name;
    QLineEdit *LECaseName;
    QHBoxLayout *hboxLayout1;
    QLabel *Directory;
    QPushButton *PushDir;
    QLineEdit *LEDirName;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout2;
    QLabel *Mesh_2;
    QPushButton *PushFichier;
    QLineEdit *LEFileName;
    QSpacerItem *spacerItem1;
    QGroupBox *GBOptions;
    QGridLayout *gridLayout;
    QCheckBox *CBQuality;
    QCheckBox *CBConnection;
    QCheckBox *CBDiametre;
    QCheckBox *CBBlockSize;
    QCheckBox *CBEntanglement;
    QSpacerItem *verticalSpacer;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonHelp;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QSpacerItem *spacer_2;

    void setupUi(QDialog *MeshInfo)
    {
        if (MeshInfo->objectName().isEmpty())
            MeshInfo->setObjectName(QString::fromUtf8("MeshInfo"));
        MeshInfo->resize(536, 372);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MeshInfo->sizePolicy().hasHeightForWidth());
        MeshInfo->setSizePolicy(sizePolicy);
        MeshInfo->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(MeshInfo);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Name = new QLabel(MeshInfo);
        Name->setObjectName(QString::fromUtf8("Name"));

        hboxLayout->addWidget(Name);

        LECaseName = new QLineEdit(MeshInfo);
        LECaseName->setObjectName(QString::fromUtf8("LECaseName"));
        LECaseName->setMinimumSize(QSize(382, 21));

        hboxLayout->addWidget(LECaseName);


        gridLayout_2->addLayout(hboxLayout, 0, 0, 1, 2);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        Directory = new QLabel(MeshInfo);
        Directory->setObjectName(QString::fromUtf8("Directory"));

        hboxLayout1->addWidget(Directory);

        PushDir = new QPushButton(MeshInfo);
        PushDir->setObjectName(QString::fromUtf8("PushDir"));
        PushDir->setAutoDefault(false);

        hboxLayout1->addWidget(PushDir);

        LEDirName = new QLineEdit(MeshInfo);
        LEDirName->setObjectName(QString::fromUtf8("LEDirName"));
        LEDirName->setMinimumSize(QSize(382, 21));

        hboxLayout1->addWidget(LEDirName);


        gridLayout_2->addLayout(hboxLayout1, 1, 0, 1, 2);

        spacerItem = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacerItem, 2, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        Mesh_2 = new QLabel(MeshInfo);
        Mesh_2->setObjectName(QString::fromUtf8("Mesh_2"));

        hboxLayout2->addWidget(Mesh_2);

        PushFichier = new QPushButton(MeshInfo);
        PushFichier->setObjectName(QString::fromUtf8("PushFichier"));
        PushFichier->setAutoDefault(false);

        hboxLayout2->addWidget(PushFichier);

        LEFileName = new QLineEdit(MeshInfo);
        LEFileName->setObjectName(QString::fromUtf8("LEFileName"));
        LEFileName->setMinimumSize(QSize(382, 21));

        hboxLayout2->addWidget(LEFileName);


        gridLayout_2->addLayout(hboxLayout2, 3, 0, 1, 2);

        spacerItem1 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(spacerItem1, 4, 0, 1, 1);

        GBOptions = new QGroupBox(MeshInfo);
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


        gridLayout_2->addWidget(GBOptions, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 0, 1, 1);

        GroupButtons = new QGroupBox(MeshInfo);
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


        gridLayout_2->addWidget(GroupButtons, 7, 0, 1, 1);

        spacer_2 = new QSpacerItem(128, 25, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(spacer_2, 7, 1, 1, 1);


        retranslateUi(MeshInfo);

        QMetaObject::connectSlotsByName(MeshInfo);
    } // setupUi

    void retranslateUi(QDialog *MeshInfo)
    {
        MeshInfo->setWindowTitle(QApplication::translate("MeshInfo", "Information on a mesh", 0));
        Name->setText(QApplication::translate("MeshInfo", "Name", 0));
        Directory->setText(QApplication::translate("MeshInfo", "Directory", 0));
        PushDir->setText(QString());
        Mesh_2->setText(QApplication::translate("MeshInfo", "Mesh", 0));
        PushFichier->setText(QString());
        GBOptions->setTitle(QApplication::translate("MeshInfo", "Options", 0));
        CBQuality->setText(QApplication::translate("MeshInfo", "Quality", 0));
        CBConnection->setText(QApplication::translate("MeshInfo", "Connection", 0));
        CBDiametre->setText(QApplication::translate("MeshInfo", "Diametre", 0));
        CBBlockSize->setText(QApplication::translate("MeshInfo", "Group size", 0));
        CBEntanglement->setText(QApplication::translate("MeshInfo", "Entanglement", 0));
        GroupButtons->setTitle(QString());
        buttonHelp->setText(QApplication::translate("MeshInfo", "Help", 0));
        buttonApply->setText(QApplication::translate("MeshInfo", "Apply", 0));
        buttonOk->setText(QApplication::translate("MeshInfo", "OK", 0));
        buttonCancel->setText(QApplication::translate("MeshInfo", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class MeshInfo: public Ui_MeshInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MESHINFO_H
