/********************************************************************************
** Form generated from reading ui file 'CreateCase.ui'
**
** Created: Fri Nov 26 13:44:35 2010
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef CREATECASE_H
#define CREATECASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateCase
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Name;
    QLineEdit *LECaseName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Directory;
    QPushButton *PushDir;
    QLineEdit *LEDirName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Mesh_2;
    QPushButton *PushFichier;
    QLineEdit *LEFileName;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *GBTypeConf;
    QHBoxLayout *horizontalLayout;
    QRadioButton *RBConforme;
    QRadioButton *RBNonConforme;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *GBTypeNoConf;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *RB1NpM;
    QRadioButton *RB1NpA;
    QRadioButton *RBQuelconque;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *CBBoundaryD;
    QCheckBox *CBBoundaryA;
    QSpacerItem *verticalSpacer_7;
    QGroupBox *GBBoundaryD;
    QGridLayout *gridLayout_3;
    QComboBox *CBBoundaryDi;
    QSpacerItem *spacer_2;
    QPushButton *PBBoundaryDiEdit;
    QPushButton *PBBoundaryDiNew;
    QGroupBox *GBBoundaryA;
    QTableWidget *TWBoundary;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *PBBoundaryNew;
    QPushButton *PBBoundaryEdit;
    QPushButton *PBBoundaryDelete;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout;
    QPushButton *buttonOk;
    QPushButton *buttonApply;
    QPushButton *buttonCancel;
    QPushButton *buttonHelp;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *CreateCase)
    {
    if (CreateCase->objectName().isEmpty())
        CreateCase->setObjectName(QString::fromUtf8("CreateCase"));
    CreateCase->resize(589, 675);
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(CreateCase->sizePolicy().hasHeightForWidth());
    CreateCase->setSizePolicy(sizePolicy);
    CreateCase->setAutoFillBackground(false);
    gridLayout_2 = new QGridLayout(CreateCase);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    horizontalLayout_5 = new QHBoxLayout();
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    Name = new QLabel(CreateCase);
    Name->setObjectName(QString::fromUtf8("Name"));

    horizontalLayout_5->addWidget(Name);

    LECaseName = new QLineEdit(CreateCase);
    LECaseName->setObjectName(QString::fromUtf8("LECaseName"));
    LECaseName->setMinimumSize(QSize(382, 21));

    horizontalLayout_5->addWidget(LECaseName);


    gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 2);

    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    Directory = new QLabel(CreateCase);
    Directory->setObjectName(QString::fromUtf8("Directory"));

    horizontalLayout_4->addWidget(Directory);

    PushDir = new QPushButton(CreateCase);
    PushDir->setObjectName(QString::fromUtf8("PushDir"));
    PushDir->setAutoDefault(false);

    horizontalLayout_4->addWidget(PushDir);

    LEDirName = new QLineEdit(CreateCase);
    LEDirName->setObjectName(QString::fromUtf8("LEDirName"));
    LEDirName->setMinimumSize(QSize(382, 21));

    horizontalLayout_4->addWidget(LEDirName);


    gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    Mesh_2 = new QLabel(CreateCase);
    Mesh_2->setObjectName(QString::fromUtf8("Mesh_2"));

    horizontalLayout_3->addWidget(Mesh_2);

    PushFichier = new QPushButton(CreateCase);
    PushFichier->setObjectName(QString::fromUtf8("PushFichier"));
    PushFichier->setAutoDefault(false);

    horizontalLayout_3->addWidget(PushFichier);

    LEFileName = new QLineEdit(CreateCase);
    LEFileName->setObjectName(QString::fromUtf8("LEFileName"));
    LEFileName->setMinimumSize(QSize(382, 21));

    horizontalLayout_3->addWidget(LEFileName);


    gridLayout_2->addLayout(horizontalLayout_3, 3, 0, 1, 2);

    verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_2, 4, 0, 1, 1);

    GBTypeConf = new QGroupBox(CreateCase);
    GBTypeConf->setObjectName(QString::fromUtf8("GBTypeConf"));
    horizontalLayout = new QHBoxLayout(GBTypeConf);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    RBConforme = new QRadioButton(GBTypeConf);
    RBConforme->setObjectName(QString::fromUtf8("RBConforme"));
    RBConforme->setChecked(true);

    horizontalLayout->addWidget(RBConforme);

    RBNonConforme = new QRadioButton(GBTypeConf);
    RBNonConforme->setObjectName(QString::fromUtf8("RBNonConforme"));

    horizontalLayout->addWidget(RBNonConforme);

    RBNonConforme->raise();
    RBConforme->raise();

    gridLayout_2->addWidget(GBTypeConf, 5, 0, 1, 2);

    verticalSpacer_3 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_3, 6, 0, 1, 1);

    GBTypeNoConf = new QGroupBox(CreateCase);
    GBTypeNoConf->setObjectName(QString::fromUtf8("GBTypeNoConf"));
    horizontalLayout_2 = new QHBoxLayout(GBTypeNoConf);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    RB1NpM = new QRadioButton(GBTypeNoConf);
    RB1NpM->setObjectName(QString::fromUtf8("RB1NpM"));

    horizontalLayout_2->addWidget(RB1NpM);

    RB1NpA = new QRadioButton(GBTypeNoConf);
    RB1NpA->setObjectName(QString::fromUtf8("RB1NpA"));

    horizontalLayout_2->addWidget(RB1NpA);

    RBQuelconque = new QRadioButton(GBTypeNoConf);
    RBQuelconque->setObjectName(QString::fromUtf8("RBQuelconque"));

    horizontalLayout_2->addWidget(RBQuelconque);


    gridLayout_2->addWidget(GBTypeNoConf, 7, 0, 1, 2);

    verticalSpacer_4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_4, 8, 0, 1, 1);

    horizontalLayout_6 = new QHBoxLayout();
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    CBBoundaryD = new QCheckBox(CreateCase);
    CBBoundaryD->setObjectName(QString::fromUtf8("CBBoundaryD"));

    horizontalLayout_6->addWidget(CBBoundaryD);

    CBBoundaryA = new QCheckBox(CreateCase);
    CBBoundaryA->setObjectName(QString::fromUtf8("CBBoundaryA"));

    horizontalLayout_6->addWidget(CBBoundaryA);


    gridLayout_2->addLayout(horizontalLayout_6, 9, 0, 1, 1);

    verticalSpacer_7 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_7, 10, 0, 1, 1);

    GBBoundaryD = new QGroupBox(CreateCase);
    GBBoundaryD->setObjectName(QString::fromUtf8("GBBoundaryD"));
    sizePolicy.setHeightForWidth(GBBoundaryD->sizePolicy().hasHeightForWidth());
    GBBoundaryD->setSizePolicy(sizePolicy);
    gridLayout_3 = new QGridLayout(GBBoundaryD);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    CBBoundaryDi = new QComboBox(GBBoundaryD);
    CBBoundaryDi->setObjectName(QString::fromUtf8("CBBoundaryDi"));
    CBBoundaryDi->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    gridLayout_3->addWidget(CBBoundaryDi, 0, 0, 1, 1);

    spacer_2 = new QSpacerItem(40, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

    gridLayout_3->addItem(spacer_2, 0, 1, 1, 1);

    PBBoundaryDiEdit = new QPushButton(GBBoundaryD);
    PBBoundaryDiEdit->setObjectName(QString::fromUtf8("PBBoundaryDiEdit"));
    PBBoundaryDiEdit->setAutoDefault(false);

    gridLayout_3->addWidget(PBBoundaryDiEdit, 0, 2, 1, 1);

    PBBoundaryDiNew = new QPushButton(GBBoundaryD);
    PBBoundaryDiNew->setObjectName(QString::fromUtf8("PBBoundaryDiNew"));
    PBBoundaryDiNew->setAutoDefault(false);

    gridLayout_3->addWidget(PBBoundaryDiNew, 0, 3, 1, 1);


    gridLayout_2->addWidget(GBBoundaryD, 11, 0, 1, 1);

    GBBoundaryA = new QGroupBox(CreateCase);
    GBBoundaryA->setObjectName(QString::fromUtf8("GBBoundaryA"));
    GBBoundaryA->setMinimumSize(QSize(548, 150));
    TWBoundary = new QTableWidget(GBBoundaryA);
    if (TWBoundary->columnCount() < 2)
        TWBoundary->setColumnCount(2);
    QTableWidgetItem *__colItem = new QTableWidgetItem();
    TWBoundary->setHorizontalHeaderItem(0, __colItem);
    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    TWBoundary->setHorizontalHeaderItem(1, __colItem1);
    TWBoundary->setObjectName(QString::fromUtf8("TWBoundary"));
    TWBoundary->setGeometry(QRect(4, 20, 371, 121));
    TWBoundary->setAutoScrollMargin(16);
    TWBoundary->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
    TWBoundary->setShowGrid(true);
    TWBoundary->setRowCount(0);
    TWBoundary->setColumnCount(2);
    layoutWidget = new QWidget(GBBoundaryA);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(410, 20, 120, 110));
    verticalLayout_4 = new QVBoxLayout(layoutWidget);
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    verticalLayout_4->setContentsMargins(0, 0, 0, 0);
    PBBoundaryNew = new QPushButton(layoutWidget);
    PBBoundaryNew->setObjectName(QString::fromUtf8("PBBoundaryNew"));
    PBBoundaryNew->setAutoDefault(false);

    verticalLayout_4->addWidget(PBBoundaryNew);

    PBBoundaryEdit = new QPushButton(layoutWidget);
    PBBoundaryEdit->setObjectName(QString::fromUtf8("PBBoundaryEdit"));
    PBBoundaryEdit->setAutoDefault(false);

    verticalLayout_4->addWidget(PBBoundaryEdit);

    PBBoundaryDelete = new QPushButton(layoutWidget);
    PBBoundaryDelete->setObjectName(QString::fromUtf8("PBBoundaryDelete"));
    PBBoundaryDelete->setAutoDefault(false);

    verticalLayout_4->addWidget(PBBoundaryDelete);


    gridLayout_2->addWidget(GBBoundaryA, 12, 0, 1, 2);

    GroupButtons = new QGroupBox(CreateCase);
    GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
    gridLayout = new QGridLayout(GroupButtons);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    buttonOk = new QPushButton(GroupButtons);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
    buttonOk->setAutoDefault(false);

    gridLayout->addWidget(buttonOk, 0, 0, 1, 1);

    buttonApply = new QPushButton(GroupButtons);
    buttonApply->setObjectName(QString::fromUtf8("buttonApply"));
    buttonApply->setAutoDefault(false);

    gridLayout->addWidget(buttonApply, 0, 1, 1, 1);

    buttonCancel = new QPushButton(GroupButtons);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
    buttonCancel->setAutoDefault(false);

    gridLayout->addWidget(buttonCancel, 0, 2, 1, 1);

    buttonHelp = new QPushButton(GroupButtons);
    buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
    buttonHelp->setAutoDefault(false);

    gridLayout->addWidget(buttonHelp, 0, 3, 1, 1);


    gridLayout_2->addWidget(GroupButtons, 13, 0, 1, 2);

    verticalSpacer_5 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_5, 2, 1, 1, 1);


    retranslateUi(CreateCase);

    CBBoundaryDi->setCurrentIndex(-1);


    QMetaObject::connectSlotsByName(CreateCase);
    } // setupUi

    void retranslateUi(QDialog *CreateCase)
    {
    CreateCase->setWindowTitle(QApplication::translate("CreateCase", "Create Case", 0, QApplication::UnicodeUTF8));
    Name->setText(QApplication::translate("CreateCase", "Name", 0, QApplication::UnicodeUTF8));
    Directory->setText(QApplication::translate("CreateCase", "Directory", 0, QApplication::UnicodeUTF8));
    PushDir->setText(QString());
    Mesh_2->setText(QApplication::translate("CreateCase", "Mesh", 0, QApplication::UnicodeUTF8));
    PushFichier->setText(QString());
    GBTypeConf->setTitle(QApplication::translate("CreateCase", "Conformity Type", 0, QApplication::UnicodeUTF8));
    RBConforme->setText(QApplication::translate("CreateCase", "Conformal", 0, QApplication::UnicodeUTF8));
    RBNonConforme->setText(QApplication::translate("CreateCase", "Non conformal", 0, QApplication::UnicodeUTF8));
    GBTypeNoConf->setTitle(QApplication::translate("CreateCase", "Non Conformal option", 0, QApplication::UnicodeUTF8));
    RB1NpM->setText(QApplication::translate("CreateCase", "1 hanging node per mesh", 0, QApplication::UnicodeUTF8));
    RB1NpA->setText(QApplication::translate("CreateCase", "1 node per edge", 0, QApplication::UnicodeUTF8));
    RBQuelconque->setText(QApplication::translate("CreateCase", "free", 0, QApplication::UnicodeUTF8));
    CBBoundaryD->setText(QApplication::translate("CreateCase", "Discrete Boundary ", 0, QApplication::UnicodeUTF8));
    CBBoundaryA->setText(QApplication::translate("CreateCase", "Analytic Boundary ", 0, QApplication::UnicodeUTF8));
    GBBoundaryD->setTitle(QApplication::translate("CreateCase", "Discrete Boundary", 0, QApplication::UnicodeUTF8));
    PBBoundaryDiEdit->setText(QApplication::translate("CreateCase", "Edit", 0, QApplication::UnicodeUTF8));
    PBBoundaryDiNew->setText(QApplication::translate("CreateCase", "New", 0, QApplication::UnicodeUTF8));
    GBBoundaryA->setTitle(QApplication::translate("CreateCase", "Analytic Boundary", 0, QApplication::UnicodeUTF8));
    TWBoundary->horizontalHeaderItem(0)->setText(QApplication::translate("CreateCase", "Group", 0, QApplication::UnicodeUTF8));
    TWBoundary->horizontalHeaderItem(1)->setText(QApplication::translate("CreateCase", "Boundary", 0, QApplication::UnicodeUTF8));
    PBBoundaryNew->setText(QApplication::translate("CreateCase", "New", 0, QApplication::UnicodeUTF8));
    PBBoundaryEdit->setText(QApplication::translate("CreateCase", "Edit", 0, QApplication::UnicodeUTF8));
    PBBoundaryDelete->setText(QString());
    GroupButtons->setTitle(QString());
    buttonOk->setText(QApplication::translate("CreateCase", "&Ok", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateCase", "&Apply", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateCase", "&Cancel", 0, QApplication::UnicodeUTF8));
    buttonHelp->setText(QApplication::translate("CreateCase", "&Help", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CreateCase);
    } // retranslateUi

};

namespace Ui {
    class CreateCase: public Ui_CreateCase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATECASE_H
