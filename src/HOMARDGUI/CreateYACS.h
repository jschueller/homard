/********************************************************************************
** Form generated from reading UI file 'CreateYACS.ui'
**
** Created: Mon Jan 20 13:23:30 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATEYACS_H
#define CREATEYACS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateYACS
{
public:
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_5;
    QWidget *WName;
    QGridLayout *gridLayout_2;
    QLabel *Name;
    QLineEdit *LEName;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLabel *Case;
    QPushButton *PBCaseName;
    QLineEdit *LECaseName;
    QHBoxLayout *_2;
    QLabel *Script;
    QPushButton *PBScriptFile;
    QLineEdit *LEScriptFile;
    QHBoxLayout *hboxLayout;
    QLabel *DirectoryStart;
    QPushButton *PBDir;
    QLineEdit *LEDirName;
    QHBoxLayout *_3;
    QLabel *MeshFile;
    QPushButton *PBMeshFile;
    QLineEdit *LEMeshFile;
    QGroupBox *GBTypeSchema;
    QHBoxLayout *_4;
    QRadioButton *RBConstant;
    QRadioButton *RBVariable;
    QGroupBox *GBMax;
    QGridLayout *gridLayout_3;
    QLabel *TLMaxIteration;
    QSpinBox *SpinBoxMaxIter;
    QLabel *TLMaxNodes;
    QSpinBox *SpinBoxMaxNode;
    QLabel *TLMaxElem;
    QSpinBox *SpinBoxMaxElem;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *GBConvergence;
    QGridLayout *gridLayout_4;
    QRadioButton *RBNone;
    QRadioButton *RBVMinAbs;
    QRadioButton *RBVMaxAbs;
    QLabel *labelVref;
    QDoubleSpinBox *doubleSpinBoxConvergence;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonHelp;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QSpacerItem *spacer_2;

    void setupUi(QScrollArea *CreateYACS)
    {
        if (CreateYACS->objectName().isEmpty())
            CreateYACS->setObjectName(QString::fromUtf8("CreateYACS"));
        CreateYACS->resize(684, 649);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateYACS->sizePolicy().hasHeightForWidth());
        CreateYACS->setSizePolicy(sizePolicy);
        CreateYACS->setMinimumSize(QSize(600, 500));
        CreateYACS->setSizeIncrement(QSize(1, 1));
        CreateYACS->setBaseSize(QSize(600, 500));
        CreateYACS->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 680, 645));
        scrollAreaWidgetContents->setProperty("sizeGripEnabled", QVariant(true));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        WName = new QWidget(scrollAreaWidgetContents);
        WName->setObjectName(QString::fromUtf8("WName"));
        gridLayout_2 = new QGridLayout(WName);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Name = new QLabel(WName);
        Name->setObjectName(QString::fromUtf8("Name"));

        gridLayout_2->addWidget(Name, 0, 0, 1, 1);

        LEName = new QLineEdit(WName);
        LEName->setObjectName(QString::fromUtf8("LEName"));
        LEName->setMaxLength(32);

        gridLayout_2->addWidget(LEName, 0, 1, 1, 1);


        gridLayout_5->addWidget(WName, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Case = new QLabel(scrollAreaWidgetContents);
        Case->setObjectName(QString::fromUtf8("Case"));

        gridLayout->addWidget(Case, 0, 0, 1, 1);

        PBCaseName = new QPushButton(scrollAreaWidgetContents);
        PBCaseName->setObjectName(QString::fromUtf8("PBCaseName"));
        PBCaseName->setEnabled(true);
        PBCaseName->setMaximumSize(QSize(50, 27));

        gridLayout->addWidget(PBCaseName, 0, 1, 1, 1);

        LECaseName = new QLineEdit(scrollAreaWidgetContents);
        LECaseName->setObjectName(QString::fromUtf8("LECaseName"));
        LECaseName->setMinimumSize(QSize(382, 21));

        gridLayout->addWidget(LECaseName, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout, 1, 0, 1, 2);

        _2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _2->setSpacing(6);
#endif
        _2->setContentsMargins(0, 0, 0, 0);
        _2->setObjectName(QString::fromUtf8("_2"));
        Script = new QLabel(scrollAreaWidgetContents);
        Script->setObjectName(QString::fromUtf8("Script"));

        _2->addWidget(Script);

        PBScriptFile = new QPushButton(scrollAreaWidgetContents);
        PBScriptFile->setObjectName(QString::fromUtf8("PBScriptFile"));
        PBScriptFile->setAutoDefault(false);

        _2->addWidget(PBScriptFile);

        LEScriptFile = new QLineEdit(scrollAreaWidgetContents);
        LEScriptFile->setObjectName(QString::fromUtf8("LEScriptFile"));
        LEScriptFile->setMinimumSize(QSize(382, 21));

        _2->addWidget(LEScriptFile);


        gridLayout_5->addLayout(_2, 2, 0, 1, 2);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        DirectoryStart = new QLabel(scrollAreaWidgetContents);
        DirectoryStart->setObjectName(QString::fromUtf8("DirectoryStart"));

        hboxLayout->addWidget(DirectoryStart);

        PBDir = new QPushButton(scrollAreaWidgetContents);
        PBDir->setObjectName(QString::fromUtf8("PBDir"));
        PBDir->setAutoDefault(false);

        hboxLayout->addWidget(PBDir);

        LEDirName = new QLineEdit(scrollAreaWidgetContents);
        LEDirName->setObjectName(QString::fromUtf8("LEDirName"));
        LEDirName->setMinimumSize(QSize(382, 21));

        hboxLayout->addWidget(LEDirName);


        gridLayout_5->addLayout(hboxLayout, 3, 0, 1, 2);

        _3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _3->setSpacing(6);
#endif
        _3->setContentsMargins(0, 0, 0, 0);
        _3->setObjectName(QString::fromUtf8("_3"));
        MeshFile = new QLabel(scrollAreaWidgetContents);
        MeshFile->setObjectName(QString::fromUtf8("MeshFile"));

        _3->addWidget(MeshFile);

        PBMeshFile = new QPushButton(scrollAreaWidgetContents);
        PBMeshFile->setObjectName(QString::fromUtf8("PBMeshFile"));
        PBMeshFile->setAutoDefault(false);

        _3->addWidget(PBMeshFile);

        LEMeshFile = new QLineEdit(scrollAreaWidgetContents);
        LEMeshFile->setObjectName(QString::fromUtf8("LEMeshFile"));
        LEMeshFile->setMinimumSize(QSize(382, 21));

        _3->addWidget(LEMeshFile);


        gridLayout_5->addLayout(_3, 4, 0, 1, 2);

        GBTypeSchema = new QGroupBox(scrollAreaWidgetContents);
        GBTypeSchema->setObjectName(QString::fromUtf8("GBTypeSchema"));
        _4 = new QHBoxLayout(GBTypeSchema);
#ifndef Q_OS_MAC
        _4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _4->setContentsMargins(9, 9, 9, 9);
#endif
        _4->setObjectName(QString::fromUtf8("_4"));
        RBConstant = new QRadioButton(GBTypeSchema);
        RBConstant->setObjectName(QString::fromUtf8("RBConstant"));
        RBConstant->setChecked(true);

        _4->addWidget(RBConstant);

        RBVariable = new QRadioButton(GBTypeSchema);
        RBVariable->setObjectName(QString::fromUtf8("RBVariable"));

        _4->addWidget(RBVariable);


        gridLayout_5->addWidget(GBTypeSchema, 5, 0, 1, 1);

        GBMax = new QGroupBox(scrollAreaWidgetContents);
        GBMax->setObjectName(QString::fromUtf8("GBMax"));
        gridLayout_3 = new QGridLayout(GBMax);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        TLMaxIteration = new QLabel(GBMax);
        TLMaxIteration->setObjectName(QString::fromUtf8("TLMaxIteration"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TLMaxIteration->sizePolicy().hasHeightForWidth());
        TLMaxIteration->setSizePolicy(sizePolicy1);
        TLMaxIteration->setWordWrap(false);

        gridLayout_3->addWidget(TLMaxIteration, 0, 0, 1, 1);

        SpinBoxMaxIter = new QSpinBox(GBMax);
        SpinBoxMaxIter->setObjectName(QString::fromUtf8("SpinBoxMaxIter"));
        SpinBoxMaxIter->setMinimum(0);
        SpinBoxMaxIter->setMaximum(999999999);
        SpinBoxMaxIter->setValue(0);

        gridLayout_3->addWidget(SpinBoxMaxIter, 0, 1, 1, 1);

        TLMaxNodes = new QLabel(GBMax);
        TLMaxNodes->setObjectName(QString::fromUtf8("TLMaxNodes"));
        sizePolicy1.setHeightForWidth(TLMaxNodes->sizePolicy().hasHeightForWidth());
        TLMaxNodes->setSizePolicy(sizePolicy1);
        TLMaxNodes->setWordWrap(false);

        gridLayout_3->addWidget(TLMaxNodes, 1, 0, 1, 1);

        SpinBoxMaxNode = new QSpinBox(GBMax);
        SpinBoxMaxNode->setObjectName(QString::fromUtf8("SpinBoxMaxNode"));
        SpinBoxMaxNode->setMinimum(0);
        SpinBoxMaxNode->setMaximum(999999999);
        SpinBoxMaxNode->setSingleStep(1000);
        SpinBoxMaxNode->setValue(0);

        gridLayout_3->addWidget(SpinBoxMaxNode, 1, 1, 1, 1);

        TLMaxElem = new QLabel(GBMax);
        TLMaxElem->setObjectName(QString::fromUtf8("TLMaxElem"));
        sizePolicy1.setHeightForWidth(TLMaxElem->sizePolicy().hasHeightForWidth());
        TLMaxElem->setSizePolicy(sizePolicy1);
        TLMaxElem->setWordWrap(false);

        gridLayout_3->addWidget(TLMaxElem, 1, 2, 1, 1);

        SpinBoxMaxElem = new QSpinBox(GBMax);
        SpinBoxMaxElem->setObjectName(QString::fromUtf8("SpinBoxMaxElem"));
        SpinBoxMaxElem->setMinimum(0);
        SpinBoxMaxElem->setMaximum(999999999);
        SpinBoxMaxElem->setSingleStep(1000);
        SpinBoxMaxElem->setValue(0);

        gridLayout_3->addWidget(SpinBoxMaxElem, 1, 3, 1, 1);


        gridLayout_5->addWidget(GBMax, 6, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(269, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 6, 1, 1, 1);

        GBConvergence = new QGroupBox(scrollAreaWidgetContents);
        GBConvergence->setObjectName(QString::fromUtf8("GBConvergence"));
        gridLayout_4 = new QGridLayout(GBConvergence);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        RBNone = new QRadioButton(GBConvergence);
        RBNone->setObjectName(QString::fromUtf8("RBNone"));
        RBNone->setChecked(true);

        gridLayout_4->addWidget(RBNone, 0, 0, 1, 1);

        RBVMinAbs = new QRadioButton(GBConvergence);
        RBVMinAbs->setObjectName(QString::fromUtf8("RBVMinAbs"));

        gridLayout_4->addWidget(RBVMinAbs, 0, 1, 1, 1);

        RBVMaxAbs = new QRadioButton(GBConvergence);
        RBVMaxAbs->setObjectName(QString::fromUtf8("RBVMaxAbs"));

        gridLayout_4->addWidget(RBVMaxAbs, 0, 2, 1, 1);

        labelVref = new QLabel(GBConvergence);
        labelVref->setObjectName(QString::fromUtf8("labelVref"));

        gridLayout_4->addWidget(labelVref, 1, 0, 1, 1);

        doubleSpinBoxConvergence = new QDoubleSpinBox(GBConvergence);
        doubleSpinBoxConvergence->setObjectName(QString::fromUtf8("doubleSpinBoxConvergence"));
        doubleSpinBoxConvergence->setDecimals(4);
        doubleSpinBoxConvergence->setMinimum(-1e+09);
        doubleSpinBoxConvergence->setMaximum(1e+09);

        gridLayout_4->addWidget(doubleSpinBoxConvergence, 1, 1, 1, 1);


        gridLayout_5->addWidget(GBConvergence, 7, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(269, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 7, 1, 1, 1);

        GroupButtons = new QGroupBox(scrollAreaWidgetContents);
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


        gridLayout_5->addWidget(GroupButtons, 8, 0, 1, 1);

        spacer_2 = new QSpacerItem(128, 25, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(spacer_2, 8, 1, 1, 1);

        CreateYACS->setWidget(scrollAreaWidgetContents);

        retranslateUi(CreateYACS);

        QMetaObject::connectSlotsByName(CreateYACS);
    } // setupUi

    void retranslateUi(QScrollArea *CreateYACS)
    {
        CreateYACS->setWindowTitle(QApplication::translate("CreateYACS", "Create YACS", 0, QApplication::UnicodeUTF8));
        Name->setText(QApplication::translate("CreateYACS", "Name", 0, QApplication::UnicodeUTF8));
        Case->setText(QApplication::translate("CreateYACS", "Case", 0, QApplication::UnicodeUTF8));
        PBCaseName->setText(QString());
        Script->setText(QApplication::translate("CreateYACS", "Script", 0, QApplication::UnicodeUTF8));
        PBScriptFile->setText(QString());
        DirectoryStart->setText(QApplication::translate("CreateYACS", "Directory", 0, QApplication::UnicodeUTF8));
        PBDir->setText(QString());
        MeshFile->setText(QApplication::translate("CreateYACS", "Mesh file", 0, QApplication::UnicodeUTF8));
        PBMeshFile->setText(QString());
        GBTypeSchema->setTitle(QApplication::translate("CreateYACS", "Type of schema", 0, QApplication::UnicodeUTF8));
        RBConstant->setText(QApplication::translate("CreateYACS", "Constant", 0, QApplication::UnicodeUTF8));
        RBVariable->setText(QApplication::translate("CreateYACS", "Variable", 0, QApplication::UnicodeUTF8));
        GBMax->setTitle(QApplication::translate("CreateYACS", "Maximum of ...", 0, QApplication::UnicodeUTF8));
        TLMaxIteration->setText(QApplication::translate("CreateYACS", "Iterations", 0, QApplication::UnicodeUTF8));
        TLMaxNodes->setText(QApplication::translate("CreateYACS", "Nodes", 0, QApplication::UnicodeUTF8));
        TLMaxElem->setText(QApplication::translate("CreateYACS", "Elements", 0, QApplication::UnicodeUTF8));
        GBConvergence->setTitle(QApplication::translate("CreateYACS", "Test of convergence", 0, QApplication::UnicodeUTF8));
        RBNone->setText(QApplication::translate("CreateYACS", "None", 0, QApplication::UnicodeUTF8));
        RBVMinAbs->setText(QApplication::translate("CreateYACS", "Vtest > Vref", 0, QApplication::UnicodeUTF8));
        RBVMaxAbs->setText(QApplication::translate("CreateYACS", "Vtest < Vref", 0, QApplication::UnicodeUTF8));
        labelVref->setText(QApplication::translate("CreateYACS", "Vref", 0, QApplication::UnicodeUTF8));
        GroupButtons->setTitle(QString());
        buttonHelp->setText(QApplication::translate("CreateYACS", "Help", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("CreateYACS", "Apply", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("CreateYACS", "OK", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CreateYACS", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateYACS: public Ui_CreateYACS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEYACS_H
