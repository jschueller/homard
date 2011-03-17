/********************************************************************************
** Form generated from reading ui file 'CreateIteration.ui'
**
** Created: Thu Nov 18 15:59:09 2010
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef CREATEITERATION_H
#define CREATEITERATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateIteration
{
public:
    QGridLayout *gridLayout_2;
    QLabel *Iteration_Name;
    QLineEdit *LEIterationName;
    QLabel *Iter_Parent;
    QSpacerItem *verticalSpacer;
    QPushButton *PBIterParent;
    QLineEdit *LEIterationParentName;
    QLabel *Mesh_n;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *LEMeshName_n;
    QSpacerItem *verticalSpacer_1;
    QLabel *Mesh_np1;
    QLineEdit *LEMeshName_np1;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *GBField;
    QGridLayout *gridLayout;
    QLabel *FieldFile;
    QPushButton *PushFieldFile;
    QLineEdit *LEFieldFile;
    QSpacerItem *verticalSpacer_7;
    QRadioButton *RBNo;
    QRadioButton *RBLast;
    QRadioButton *RBChosen;
    QSpacerItem *verticalSpacer_4;
    QLabel *TimeStep;
    QSpinBox *SpinBox_TimeStep;
    QSpacerItem *spacer;
    QLabel *Rank;
    QSpinBox *SpinBox_Rank;
    QSpacerItem *spacer_3;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *Hypothese;
    QGridLayout *gridLayout_3;
    QComboBox *CBHypothese;
    QSpacerItem *spacer_2;
    QPushButton *PBHypoEdit;
    QPushButton *PBHypoNew;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout_4;
    QPushButton *buttonOk;
    QPushButton *buttonApply;
    QPushButton *buttonCancel;
    QPushButton *buttonHelp;

    void setupUi(QWidget *CreateIteration)
    {
    if (CreateIteration->objectName().isEmpty())
        CreateIteration->setObjectName(QString::fromUtf8("CreateIteration"));
    CreateIteration->resize(587, 598);
    gridLayout_2 = new QGridLayout(CreateIteration);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    Iteration_Name = new QLabel(CreateIteration);
    Iteration_Name->setObjectName(QString::fromUtf8("Iteration_Name"));

    gridLayout_2->addWidget(Iteration_Name, 0, 0, 1, 2);

    LEIterationName = new QLineEdit(CreateIteration);
    LEIterationName->setObjectName(QString::fromUtf8("LEIterationName"));
    LEIterationName->setMinimumSize(QSize(290, 21));
    LEIterationName->setMaxLength(200);

    gridLayout_2->addWidget(LEIterationName, 0, 2, 1, 2);

    Iter_Parent = new QLabel(CreateIteration);
    Iter_Parent->setObjectName(QString::fromUtf8("Iter_Parent"));

    gridLayout_2->addWidget(Iter_Parent, 1, 0, 1, 1);

    verticalSpacer = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 1);

    PBIterParent = new QPushButton(CreateIteration);
    PBIterParent->setObjectName(QString::fromUtf8("PBIterParent"));
    PBIterParent->setEnabled(true);
    PBIterParent->setMaximumSize(QSize(50, 27));

    gridLayout_2->addWidget(PBIterParent, 1, 2, 1, 1);

    LEIterationParentName = new QLineEdit(CreateIteration);
    LEIterationParentName->setObjectName(QString::fromUtf8("LEIterationParentName"));
    LEIterationParentName->setMinimumSize(QSize(0, 21));
    LEIterationParentName->setMaxLength(200);
    LEIterationParentName->setReadOnly(true);

    gridLayout_2->addWidget(LEIterationParentName, 1, 3, 1, 1);

    Mesh_n = new QLabel(CreateIteration);
    Mesh_n->setObjectName(QString::fromUtf8("Mesh_n"));

    gridLayout_2->addWidget(Mesh_n, 2, 0, 1, 1);

    verticalSpacer_6 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_6, 2, 1, 1, 1);

    LEMeshName_n = new QLineEdit(CreateIteration);
    LEMeshName_n->setObjectName(QString::fromUtf8("LEMeshName_n"));
    LEMeshName_n->setMinimumSize(QSize(290, 21));
    LEMeshName_n->setMaxLength(32);
    LEMeshName_n->setReadOnly(true);

    gridLayout_2->addWidget(LEMeshName_n, 2, 2, 1, 2);

    verticalSpacer_1 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_1, 3, 1, 1, 1);

    Mesh_np1 = new QLabel(CreateIteration);
    Mesh_np1->setObjectName(QString::fromUtf8("Mesh_np1"));

    gridLayout_2->addWidget(Mesh_np1, 4, 0, 1, 2);

    LEMeshName_np1 = new QLineEdit(CreateIteration);
    LEMeshName_np1->setObjectName(QString::fromUtf8("LEMeshName_np1"));
    LEMeshName_np1->setMinimumSize(QSize(290, 21));
    LEMeshName_np1->setMaxLength(32);

    gridLayout_2->addWidget(LEMeshName_np1, 4, 2, 1, 2);

    verticalSpacer_3 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_3, 5, 1, 1, 1);

    GBField = new QGroupBox(CreateIteration);
    GBField->setObjectName(QString::fromUtf8("GBField"));
    gridLayout = new QGridLayout(GBField);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    FieldFile = new QLabel(GBField);
    FieldFile->setObjectName(QString::fromUtf8("FieldFile"));

    gridLayout->addWidget(FieldFile, 0, 0, 1, 1);

    PushFieldFile = new QPushButton(GBField);
    PushFieldFile->setObjectName(QString::fromUtf8("PushFieldFile"));

    gridLayout->addWidget(PushFieldFile, 0, 1, 1, 1);

    LEFieldFile = new QLineEdit(GBField);
    LEFieldFile->setObjectName(QString::fromUtf8("LEFieldFile"));
    LEFieldFile->setMinimumSize(QSize(282, 21));

    gridLayout->addWidget(LEFieldFile, 0, 2, 1, 6);

    verticalSpacer_7 = new QSpacerItem(138, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_7, 1, 3, 1, 4);

    RBNo = new QRadioButton(GBField);
    RBNo->setObjectName(QString::fromUtf8("RBNo"));
    RBNo->setCheckable(true);
    RBNo->setChecked(true);

    gridLayout->addWidget(RBNo, 2, 0, 1, 3);

    RBLast = new QRadioButton(GBField);
    RBLast->setObjectName(QString::fromUtf8("RBLast"));

    gridLayout->addWidget(RBLast, 2, 3, 1, 3);

    RBChosen = new QRadioButton(GBField);
    RBChosen->setObjectName(QString::fromUtf8("RBChosen"));

    gridLayout->addWidget(RBChosen, 2, 7, 1, 1);

    verticalSpacer_4 = new QSpacerItem(138, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_4, 3, 0, 1, 4);

    TimeStep = new QLabel(GBField);
    TimeStep->setObjectName(QString::fromUtf8("TimeStep"));

    gridLayout->addWidget(TimeStep, 4, 0, 1, 1);

    SpinBox_TimeStep = new QSpinBox(GBField);
    SpinBox_TimeStep->setObjectName(QString::fromUtf8("SpinBox_TimeStep"));
    SpinBox_TimeStep->setMinimum(-2);
    SpinBox_TimeStep->setMaximum(100000);
    SpinBox_TimeStep->setValue(-1);

    gridLayout->addWidget(SpinBox_TimeStep, 4, 1, 1, 1);

    spacer = new QSpacerItem(40, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

    gridLayout->addItem(spacer, 4, 2, 1, 2);

    Rank = new QLabel(GBField);
    Rank->setObjectName(QString::fromUtf8("Rank"));

    gridLayout->addWidget(Rank, 4, 4, 1, 1);

    SpinBox_Rank = new QSpinBox(GBField);
    SpinBox_Rank->setObjectName(QString::fromUtf8("SpinBox_Rank"));
    SpinBox_Rank->setMinimum(-1);
    SpinBox_Rank->setMaximum(1010000);
    SpinBox_Rank->setValue(1);

    gridLayout->addWidget(SpinBox_Rank, 4, 5, 1, 1);

    spacer_3 = new QSpacerItem(255, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(spacer_3, 4, 6, 1, 2);


    gridLayout_2->addWidget(GBField, 6, 0, 1, 4);

    verticalSpacer_2 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_2, 7, 1, 1, 1);

    Hypothese = new QGroupBox(CreateIteration);
    Hypothese->setObjectName(QString::fromUtf8("Hypothese"));
    gridLayout_3 = new QGridLayout(Hypothese);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    CBHypothese = new QComboBox(Hypothese);
    CBHypothese->setObjectName(QString::fromUtf8("CBHypothese"));
    CBHypothese->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    gridLayout_3->addWidget(CBHypothese, 0, 0, 1, 1);

    spacer_2 = new QSpacerItem(40, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

    gridLayout_3->addItem(spacer_2, 0, 1, 1, 1);

    PBHypoEdit = new QPushButton(Hypothese);
    PBHypoEdit->setObjectName(QString::fromUtf8("PBHypoEdit"));

    gridLayout_3->addWidget(PBHypoEdit, 0, 2, 1, 1);

    PBHypoNew = new QPushButton(Hypothese);
    PBHypoNew->setObjectName(QString::fromUtf8("PBHypoNew"));

    gridLayout_3->addWidget(PBHypoNew, 0, 3, 1, 1);


    gridLayout_2->addWidget(Hypothese, 8, 0, 1, 4);

    verticalSpacer_5 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout_2->addItem(verticalSpacer_5, 9, 0, 1, 2);

    GroupButtons = new QGroupBox(CreateIteration);
    GroupButtons->setObjectName(QString::fromUtf8("GroupButtons"));
    gridLayout_4 = new QGridLayout(GroupButtons);
    gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
    buttonOk = new QPushButton(GroupButtons);
    buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
    buttonOk->setAutoDefault(false);
    buttonOk->setDefault(false);

    gridLayout_4->addWidget(buttonOk, 0, 0, 1, 1);

    buttonApply = new QPushButton(GroupButtons);
    buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

    gridLayout_4->addWidget(buttonApply, 0, 1, 1, 1);

    buttonCancel = new QPushButton(GroupButtons);
    buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

    gridLayout_4->addWidget(buttonCancel, 0, 2, 1, 1);

    buttonHelp = new QPushButton(GroupButtons);
    buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

    gridLayout_4->addWidget(buttonHelp, 0, 3, 1, 1);


    gridLayout_2->addWidget(GroupButtons, 10, 0, 1, 4);


    retranslateUi(CreateIteration);

    CBHypothese->setCurrentIndex(-1);


    QMetaObject::connectSlotsByName(CreateIteration);
    } // setupUi

    void retranslateUi(QWidget *CreateIteration)
    {
    CreateIteration->setWindowTitle(QApplication::translate("CreateIteration", "Create_Iteration", 0, QApplication::UnicodeUTF8));
    Iteration_Name->setText(QApplication::translate("CreateIteration", "Iteration Name", 0, QApplication::UnicodeUTF8));
    Iter_Parent->setText(QApplication::translate("CreateIteration", "Previous iteration", 0, QApplication::UnicodeUTF8));
    PBIterParent->setText(QString());
    Mesh_n->setText(QApplication::translate("CreateIteration", "Mesh n", 0, QApplication::UnicodeUTF8));
    Mesh_np1->setText(QApplication::translate("CreateIteration", "Mesh n+1", 0, QApplication::UnicodeUTF8));
    GBField->setTitle(QApplication::translate("CreateIteration", "Field information", 0, QApplication::UnicodeUTF8));
    FieldFile->setText(QApplication::translate("CreateIteration", "Field File", 0, QApplication::UnicodeUTF8));
    PushFieldFile->setText(QString());
    RBNo->setText(QApplication::translate("CreateIteration", "No Time Step", 0, QApplication::UnicodeUTF8));
    RBLast->setText(QApplication::translate("CreateIteration", "Last Time Step", 0, QApplication::UnicodeUTF8));
    RBChosen->setText(QApplication::translate("CreateIteration", "Chosen time step", 0, QApplication::UnicodeUTF8));
    TimeStep->setText(QApplication::translate("CreateIteration", "Time Step", 0, QApplication::UnicodeUTF8));
    Rank->setText(QApplication::translate("CreateIteration", "Rank", 0, QApplication::UnicodeUTF8));
    Hypothese->setTitle(QApplication::translate("CreateIteration", "Hypothesis", 0, QApplication::UnicodeUTF8));
    PBHypoEdit->setText(QApplication::translate("CreateIteration", "Edit", 0, QApplication::UnicodeUTF8));
    PBHypoNew->setText(QApplication::translate("CreateIteration", "New", 0, QApplication::UnicodeUTF8));
    GroupButtons->setTitle(QString());
    buttonOk->setText(QApplication::translate("CreateIteration", "&Ok", 0, QApplication::UnicodeUTF8));
    buttonApply->setText(QApplication::translate("CreateIteration", "&Apply", 0, QApplication::UnicodeUTF8));
    buttonCancel->setText(QApplication::translate("CreateIteration", "&Cancel", 0, QApplication::UnicodeUTF8));
    buttonHelp->setText(QApplication::translate("CreateIteration", "&Help", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CreateIteration);
    } // retranslateUi

};

namespace Ui {
    class CreateIteration: public Ui_CreateIteration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEITERATION_H
