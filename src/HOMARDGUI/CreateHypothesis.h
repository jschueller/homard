/********************************************************************************
** Form generated from reading UI file 'CreateHypothesis.ui'
**
** Created: Fri Jun 13 09:26:59 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATEHYPOTHESIS_H
#define CREATEHYPOTHESIS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
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
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateHypothesis
{
public:
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_5;
    QWidget *WName;
    QGridLayout *gridLayout;
    QLabel *Name;
    QLineEdit *LEName;
    QSpacerItem *horizontalSpacer_9;
    QGroupBox *GBTypeAdaptation;
    QHBoxLayout *hboxLayout;
    QRadioButton *RBUniforme;
    QRadioButton *RBChamp;
    QRadioButton *RBZone;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *CBGroupe;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *GBUniform;
    QGridLayout *gridLayout1;
    QRadioButton *RBUniDera;
    QRadioButton *RBUniRaff;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *GBFieldFile;
    QGridLayout *gridLayout2;
    QLabel *FieldFile;
    QLineEdit *LEFieldFile;
    QGroupBox *GBFieldManagement;
    QGridLayout *gridLayout3;
    QHBoxLayout *hboxLayout1;
    QLabel *FieldName;
    QComboBox *CBFieldName;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout2;
    QTableWidget *TWCMP;
    QSpacerItem *spacerItem1;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout3;
    QRadioButton *RBL2;
    QRadioButton *RBInf;
    QCheckBox *CBJump;
    QHBoxLayout *hboxLayout4;
    QGroupBox *GBRefinementThresholds;
    QGridLayout *gridLayout4;
    QRadioButton *RBRPE;
    QDoubleSpinBox *SpinBox_RPE;
    QRadioButton *RBRRel;
    QDoubleSpinBox *SpinBox_RRel;
    QRadioButton *RBRAbs;
    QDoubleSpinBox *SpinBox_RAbs;
    QRadioButton *RBRMuSigma;
    QDoubleSpinBox *SpinBox_RMuSigma;
    QRadioButton *RBRNo;
    QGroupBox *GBCoarseningThresholds;
    QGridLayout *gridLayout5;
    QRadioButton *RBCPE;
    QDoubleSpinBox *SpinBox_CPE;
    QRadioButton *RBCRel;
    QDoubleSpinBox *SpinBox_CRel;
    QRadioButton *RBCAbs;
    QDoubleSpinBox *SpinBox_CAbs;
    QRadioButton *RBCMuSigma;
    QDoubleSpinBox *SpinBox_CMuSigma;
    QRadioButton *RBCNo;
    QGroupBox *GBAreaManagement;
    QGridLayout *gridLayout_4;
    QTableWidget *TWZone;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *vboxLayout1;
    QVBoxLayout *vboxLayout2;
    QPushButton *PBZoneNew;
    QPushButton *PBZoneEdit;
    QPushButton *PBZoneDelete;
    QSpacerItem *spacerItem2;
    QGroupBox *GBField;
    QGridLayout *gridLayout6;
    QGridLayout *gridLayout7;
    QRadioButton *RBFieldNo;
    QRadioButton *RBFieldAll;
    QRadioButton *RBFieldChosen;
    QTableWidget *TWField;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *CBAdvanced;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *GBAdvancedOptions;
    QGridLayout *gridLayout_3;
    QLabel *TLMinimalDiameter;
    QDoubleSpinBox *doubleSpinBoxDiamMin;
    QLabel *TLMaximalLevel;
    QSpinBox *SpinBoxNivMax;
    QGroupBox *GBAdapInit;
    QGridLayout *gridLayout_2;
    QRadioButton *RBAIN;
    QRadioButton *RBAIR;
    QRadioButton *RBAID;
    QCheckBox *CBOutputLevel;
    QCheckBox *CBOutputQuality;
    QCheckBox *CBOutputDiameter;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout8;
    QPushButton *buttonOk;
    QPushButton *buttonApply;
    QPushButton *buttonCancel;
    QPushButton *buttonHelp;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QScrollArea *CreateHypothesis)
    {
        if (CreateHypothesis->objectName().isEmpty())
            CreateHypothesis->setObjectName(QString::fromUtf8("CreateHypothesis"));
        CreateHypothesis->resize(848, 1600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateHypothesis->sizePolicy().hasHeightForWidth());
        CreateHypothesis->setSizePolicy(sizePolicy);
        CreateHypothesis->setMinimumSize(QSize(800, 600));
        CreateHypothesis->setSizeIncrement(QSize(1, 1));
        CreateHypothesis->setBaseSize(QSize(800, 1200));
        CreateHypothesis->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 844, 1596));
        scrollAreaWidgetContents->setProperty("sizeGripEnabled", QVariant(true));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        WName = new QWidget(scrollAreaWidgetContents);
        WName->setObjectName(QString::fromUtf8("WName"));
        gridLayout = new QGridLayout(WName);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Name = new QLabel(WName);
        Name->setObjectName(QString::fromUtf8("Name"));

        gridLayout->addWidget(Name, 0, 0, 1, 1);

        LEName = new QLineEdit(WName);
        LEName->setObjectName(QString::fromUtf8("LEName"));
        LEName->setMinimumSize(QSize(282, 31));

        gridLayout->addWidget(LEName, 0, 1, 1, 1);


        gridLayout_5->addWidget(WName, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(224, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 0, 1, 1, 2);

        GBTypeAdaptation = new QGroupBox(scrollAreaWidgetContents);
        GBTypeAdaptation->setObjectName(QString::fromUtf8("GBTypeAdaptation"));
        hboxLayout = new QHBoxLayout(GBTypeAdaptation);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        RBUniforme = new QRadioButton(GBTypeAdaptation);
        RBUniforme->setObjectName(QString::fromUtf8("RBUniforme"));
        RBUniforme->setCheckable(true);

        hboxLayout->addWidget(RBUniforme);

        RBChamp = new QRadioButton(GBTypeAdaptation);
        RBChamp->setObjectName(QString::fromUtf8("RBChamp"));

        hboxLayout->addWidget(RBChamp);

        RBZone = new QRadioButton(GBTypeAdaptation);
        RBZone->setObjectName(QString::fromUtf8("RBZone"));

        hboxLayout->addWidget(RBZone);


        gridLayout_5->addWidget(GBTypeAdaptation, 1, 0, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 1, 3, 1, 1);

        CBGroupe = new QCheckBox(scrollAreaWidgetContents);
        CBGroupe->setObjectName(QString::fromUtf8("CBGroupe"));

        gridLayout_5->addWidget(CBGroupe, 2, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 2, 3, 1, 1);

        GBUniform = new QGroupBox(scrollAreaWidgetContents);
        GBUniform->setObjectName(QString::fromUtf8("GBUniform"));
        gridLayout1 = new QGridLayout(GBUniform);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        RBUniDera = new QRadioButton(GBUniform);
        RBUniDera->setObjectName(QString::fromUtf8("RBUniDera"));

        gridLayout1->addWidget(RBUniDera, 0, 1, 1, 1);

        RBUniRaff = new QRadioButton(GBUniform);
        RBUniRaff->setObjectName(QString::fromUtf8("RBUniRaff"));
        RBUniRaff->setChecked(true);

        gridLayout1->addWidget(RBUniRaff, 0, 0, 1, 1);


        gridLayout_5->addWidget(GBUniform, 3, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 3, 3, 1, 1);

        GBFieldFile = new QGroupBox(scrollAreaWidgetContents);
        GBFieldFile->setObjectName(QString::fromUtf8("GBFieldFile"));
        gridLayout2 = new QGridLayout(GBFieldFile);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        FieldFile = new QLabel(GBFieldFile);
        FieldFile->setObjectName(QString::fromUtf8("FieldFile"));

        gridLayout2->addWidget(FieldFile, 0, 0, 1, 1);

        LEFieldFile = new QLineEdit(GBFieldFile);
        LEFieldFile->setObjectName(QString::fromUtf8("LEFieldFile"));
        LEFieldFile->setMinimumSize(QSize(282, 31));

        gridLayout2->addWidget(LEFieldFile, 0, 1, 1, 1);


        gridLayout_5->addWidget(GBFieldFile, 4, 0, 1, 2);

        GBFieldManagement = new QGroupBox(scrollAreaWidgetContents);
        GBFieldManagement->setObjectName(QString::fromUtf8("GBFieldManagement"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(GBFieldManagement->sizePolicy().hasHeightForWidth());
        GBFieldManagement->setSizePolicy(sizePolicy1);
        gridLayout3 = new QGridLayout(GBFieldManagement);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        FieldName = new QLabel(GBFieldManagement);
        FieldName->setObjectName(QString::fromUtf8("FieldName"));

        hboxLayout1->addWidget(FieldName);

        CBFieldName = new QComboBox(GBFieldManagement);
        CBFieldName->setObjectName(QString::fromUtf8("CBFieldName"));
        sizePolicy1.setHeightForWidth(CBFieldName->sizePolicy().hasHeightForWidth());
        CBFieldName->setSizePolicy(sizePolicy1);
        CBFieldName->setEditable(false);
        CBFieldName->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        hboxLayout1->addWidget(CBFieldName);

        spacerItem = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);


        gridLayout3->addLayout(hboxLayout1, 0, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        TWCMP = new QTableWidget(GBFieldManagement);
        if (TWCMP->columnCount() < 2)
            TWCMP->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TWCMP->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TWCMP->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        TWCMP->setObjectName(QString::fromUtf8("TWCMP"));
        TWCMP->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        TWCMP->setShowGrid(true);
        TWCMP->setRowCount(0);
        TWCMP->setColumnCount(2);

        hboxLayout2->addWidget(TWCMP);

        spacerItem1 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem1);

        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        RBL2 = new QRadioButton(GBFieldManagement);
        RBL2->setObjectName(QString::fromUtf8("RBL2"));
        RBL2->setChecked(true);

        hboxLayout3->addWidget(RBL2);

        RBInf = new QRadioButton(GBFieldManagement);
        RBInf->setObjectName(QString::fromUtf8("RBInf"));
        RBInf->setChecked(false);

        hboxLayout3->addWidget(RBInf);


        vboxLayout->addLayout(hboxLayout3);

        CBJump = new QCheckBox(GBFieldManagement);
        CBJump->setObjectName(QString::fromUtf8("CBJump"));

        vboxLayout->addWidget(CBJump);


        hboxLayout2->addLayout(vboxLayout);


        gridLayout3->addLayout(hboxLayout2, 1, 0, 1, 1);

        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        GBRefinementThresholds = new QGroupBox(GBFieldManagement);
        GBRefinementThresholds->setObjectName(QString::fromUtf8("GBRefinementThresholds"));
        sizePolicy1.setHeightForWidth(GBRefinementThresholds->sizePolicy().hasHeightForWidth());
        GBRefinementThresholds->setSizePolicy(sizePolicy1);
        gridLayout4 = new QGridLayout(GBRefinementThresholds);
#ifndef Q_OS_MAC
        gridLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout4->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        RBRPE = new QRadioButton(GBRefinementThresholds);
        RBRPE->setObjectName(QString::fromUtf8("RBRPE"));
        RBRPE->setCheckable(true);
        RBRPE->setChecked(true);

        gridLayout4->addWidget(RBRPE, 0, 0, 1, 1);

        SpinBox_RPE = new QDoubleSpinBox(GBRefinementThresholds);
        SpinBox_RPE->setObjectName(QString::fromUtf8("SpinBox_RPE"));
        SpinBox_RPE->setDecimals(3);
        SpinBox_RPE->setMaximum(100);
        SpinBox_RPE->setSingleStep(0.1);
        SpinBox_RPE->setValue(2);

        gridLayout4->addWidget(SpinBox_RPE, 0, 1, 1, 1);

        RBRRel = new QRadioButton(GBRefinementThresholds);
        RBRRel->setObjectName(QString::fromUtf8("RBRRel"));

        gridLayout4->addWidget(RBRRel, 1, 0, 1, 1);

        SpinBox_RRel = new QDoubleSpinBox(GBRefinementThresholds);
        SpinBox_RRel->setObjectName(QString::fromUtf8("SpinBox_RRel"));
        SpinBox_RRel->setEnabled(false);
        SpinBox_RRel->setDecimals(3);
        SpinBox_RRel->setMaximum(100);
        SpinBox_RRel->setSingleStep(0.1);

        gridLayout4->addWidget(SpinBox_RRel, 1, 1, 1, 1);

        RBRAbs = new QRadioButton(GBRefinementThresholds);
        RBRAbs->setObjectName(QString::fromUtf8("RBRAbs"));

        gridLayout4->addWidget(RBRAbs, 2, 0, 1, 1);

        SpinBox_RAbs = new QDoubleSpinBox(GBRefinementThresholds);
        SpinBox_RAbs->setObjectName(QString::fromUtf8("SpinBox_RAbs"));
        SpinBox_RAbs->setEnabled(false);
        SpinBox_RAbs->setDecimals(8);
        SpinBox_RAbs->setMinimum(-1e+12);
        SpinBox_RAbs->setMaximum(1e+12);
        SpinBox_RAbs->setSingleStep(0.1);

        gridLayout4->addWidget(SpinBox_RAbs, 2, 1, 1, 1);

        RBRMuSigma = new QRadioButton(GBRefinementThresholds);
        RBRMuSigma->setObjectName(QString::fromUtf8("RBRMuSigma"));

        gridLayout4->addWidget(RBRMuSigma, 3, 0, 1, 1);

        SpinBox_RMuSigma = new QDoubleSpinBox(GBRefinementThresholds);
        SpinBox_RMuSigma->setObjectName(QString::fromUtf8("SpinBox_RMuSigma"));
        SpinBox_RMuSigma->setEnabled(false);
        SpinBox_RMuSigma->setDecimals(8);
        SpinBox_RMuSigma->setMinimum(-1e+12);
        SpinBox_RMuSigma->setMaximum(1e+12);
        SpinBox_RMuSigma->setSingleStep(0.1);
        SpinBox_RMuSigma->setValue(3);

        gridLayout4->addWidget(SpinBox_RMuSigma, 3, 1, 1, 1);

        RBRNo = new QRadioButton(GBRefinementThresholds);
        RBRNo->setObjectName(QString::fromUtf8("RBRNo"));

        gridLayout4->addWidget(RBRNo, 4, 0, 1, 1);


        hboxLayout4->addWidget(GBRefinementThresholds);

        GBCoarseningThresholds = new QGroupBox(GBFieldManagement);
        GBCoarseningThresholds->setObjectName(QString::fromUtf8("GBCoarseningThresholds"));
        gridLayout5 = new QGridLayout(GBCoarseningThresholds);
#ifndef Q_OS_MAC
        gridLayout5->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout5->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        RBCPE = new QRadioButton(GBCoarseningThresholds);
        RBCPE->setObjectName(QString::fromUtf8("RBCPE"));
        RBCPE->setCheckable(true);
        RBCPE->setChecked(false);

        gridLayout5->addWidget(RBCPE, 0, 0, 1, 1);

        SpinBox_CPE = new QDoubleSpinBox(GBCoarseningThresholds);
        SpinBox_CPE->setObjectName(QString::fromUtf8("SpinBox_CPE"));
        SpinBox_CPE->setEnabled(false);
        SpinBox_CPE->setDecimals(3);
        SpinBox_CPE->setMaximum(100);
        SpinBox_CPE->setSingleStep(0.1);

        gridLayout5->addWidget(SpinBox_CPE, 0, 1, 1, 1);

        RBCRel = new QRadioButton(GBCoarseningThresholds);
        RBCRel->setObjectName(QString::fromUtf8("RBCRel"));

        gridLayout5->addWidget(RBCRel, 1, 0, 1, 1);

        SpinBox_CRel = new QDoubleSpinBox(GBCoarseningThresholds);
        SpinBox_CRel->setObjectName(QString::fromUtf8("SpinBox_CRel"));
        SpinBox_CRel->setEnabled(false);
        SpinBox_CRel->setDecimals(3);
        SpinBox_CRel->setMaximum(100);
        SpinBox_CRel->setSingleStep(0.1);

        gridLayout5->addWidget(SpinBox_CRel, 1, 1, 1, 1);

        RBCAbs = new QRadioButton(GBCoarseningThresholds);
        RBCAbs->setObjectName(QString::fromUtf8("RBCAbs"));

        gridLayout5->addWidget(RBCAbs, 2, 0, 1, 1);

        SpinBox_CAbs = new QDoubleSpinBox(GBCoarseningThresholds);
        SpinBox_CAbs->setObjectName(QString::fromUtf8("SpinBox_CAbs"));
        SpinBox_CAbs->setEnabled(false);
        SpinBox_CAbs->setDecimals(8);
        SpinBox_CAbs->setMinimum(-1e+12);
        SpinBox_CAbs->setMaximum(1e+12);
        SpinBox_CAbs->setSingleStep(0.1);

        gridLayout5->addWidget(SpinBox_CAbs, 2, 1, 1, 1);

        RBCMuSigma = new QRadioButton(GBCoarseningThresholds);
        RBCMuSigma->setObjectName(QString::fromUtf8("RBCMuSigma"));

        gridLayout5->addWidget(RBCMuSigma, 3, 0, 1, 1);

        SpinBox_CMuSigma = new QDoubleSpinBox(GBCoarseningThresholds);
        SpinBox_CMuSigma->setObjectName(QString::fromUtf8("SpinBox_CMuSigma"));
        SpinBox_CMuSigma->setEnabled(false);
        SpinBox_CMuSigma->setDecimals(8);
        SpinBox_CMuSigma->setMinimum(-1e+12);
        SpinBox_CMuSigma->setMaximum(1e+12);
        SpinBox_CMuSigma->setSingleStep(0.1);
        SpinBox_CMuSigma->setValue(4);

        gridLayout5->addWidget(SpinBox_CMuSigma, 3, 1, 1, 1);

        RBCNo = new QRadioButton(GBCoarseningThresholds);
        RBCNo->setObjectName(QString::fromUtf8("RBCNo"));
        RBCNo->setChecked(true);

        gridLayout5->addWidget(RBCNo, 4, 0, 1, 1);


        hboxLayout4->addWidget(GBCoarseningThresholds);


        gridLayout3->addLayout(hboxLayout4, 2, 0, 1, 1);


        gridLayout_5->addWidget(GBFieldManagement, 5, 0, 1, 4);

        GBAreaManagement = new QGroupBox(scrollAreaWidgetContents);
        GBAreaManagement->setObjectName(QString::fromUtf8("GBAreaManagement"));
        sizePolicy1.setHeightForWidth(GBAreaManagement->sizePolicy().hasHeightForWidth());
        GBAreaManagement->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(GBAreaManagement);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        TWZone = new QTableWidget(GBAreaManagement);
        if (TWZone->columnCount() < 3)
            TWZone->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TWZone->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TWZone->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TWZone->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        TWZone->setObjectName(QString::fromUtf8("TWZone"));
        TWZone->setMinimumSize(QSize(400, 0));
        TWZone->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        TWZone->setShowGrid(true);
        TWZone->setRowCount(0);
        TWZone->setColumnCount(3);

        gridLayout_4->addWidget(TWZone, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 1, 1, 1);

        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        PBZoneNew = new QPushButton(GBAreaManagement);
        PBZoneNew->setObjectName(QString::fromUtf8("PBZoneNew"));

        vboxLayout2->addWidget(PBZoneNew);

        PBZoneEdit = new QPushButton(GBAreaManagement);
        PBZoneEdit->setObjectName(QString::fromUtf8("PBZoneEdit"));

        vboxLayout2->addWidget(PBZoneEdit);

        PBZoneDelete = new QPushButton(GBAreaManagement);
        PBZoneDelete->setObjectName(QString::fromUtf8("PBZoneDelete"));

        vboxLayout2->addWidget(PBZoneDelete);


        vboxLayout1->addLayout(vboxLayout2);

        spacerItem2 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem2);


        gridLayout_4->addLayout(vboxLayout1, 0, 2, 1, 1);


        gridLayout_5->addWidget(GBAreaManagement, 6, 0, 1, 3);

        GBField = new QGroupBox(scrollAreaWidgetContents);
        GBField->setObjectName(QString::fromUtf8("GBField"));
        gridLayout6 = new QGridLayout(GBField);
#ifndef Q_OS_MAC
        gridLayout6->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout6->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
        gridLayout7 = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout7->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout7->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
        RBFieldNo = new QRadioButton(GBField);
        RBFieldNo->setObjectName(QString::fromUtf8("RBFieldNo"));
        RBFieldNo->setChecked(true);

        gridLayout7->addWidget(RBFieldNo, 0, 0, 1, 1);

        RBFieldAll = new QRadioButton(GBField);
        RBFieldAll->setObjectName(QString::fromUtf8("RBFieldAll"));
        RBFieldAll->setChecked(false);

        gridLayout7->addWidget(RBFieldAll, 0, 1, 1, 1);

        RBFieldChosen = new QRadioButton(GBField);
        RBFieldChosen->setObjectName(QString::fromUtf8("RBFieldChosen"));
        RBFieldChosen->setChecked(false);

        gridLayout7->addWidget(RBFieldChosen, 0, 2, 1, 1);


        gridLayout6->addLayout(gridLayout7, 0, 0, 1, 1);

        TWField = new QTableWidget(GBField);
        if (TWField->columnCount() < 2)
            TWField->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TWField->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        TWField->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        TWField->setObjectName(QString::fromUtf8("TWField"));

        gridLayout6->addWidget(TWField, 1, 0, 1, 1);


        gridLayout_5->addWidget(GBField, 7, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 7, 3, 1, 1);

        CBAdvanced = new QCheckBox(scrollAreaWidgetContents);
        CBAdvanced->setObjectName(QString::fromUtf8("CBAdvanced"));

        gridLayout_5->addWidget(CBAdvanced, 8, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 8, 3, 1, 1);

        GBAdvancedOptions = new QGroupBox(scrollAreaWidgetContents);
        GBAdvancedOptions->setObjectName(QString::fromUtf8("GBAdvancedOptions"));
        gridLayout_3 = new QGridLayout(GBAdvancedOptions);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        TLMinimalDiameter = new QLabel(GBAdvancedOptions);
        TLMinimalDiameter->setObjectName(QString::fromUtf8("TLMinimalDiameter"));
        sizePolicy1.setHeightForWidth(TLMinimalDiameter->sizePolicy().hasHeightForWidth());
        TLMinimalDiameter->setSizePolicy(sizePolicy1);
        TLMinimalDiameter->setWordWrap(false);

        gridLayout_3->addWidget(TLMinimalDiameter, 0, 0, 1, 1);

        doubleSpinBoxDiamMin = new QDoubleSpinBox(GBAdvancedOptions);
        doubleSpinBoxDiamMin->setObjectName(QString::fromUtf8("doubleSpinBoxDiamMin"));
        doubleSpinBoxDiamMin->setDecimals(7);

        gridLayout_3->addWidget(doubleSpinBoxDiamMin, 0, 1, 1, 1);

        TLMaximalLevel = new QLabel(GBAdvancedOptions);
        TLMaximalLevel->setObjectName(QString::fromUtf8("TLMaximalLevel"));
        sizePolicy1.setHeightForWidth(TLMaximalLevel->sizePolicy().hasHeightForWidth());
        TLMaximalLevel->setSizePolicy(sizePolicy1);
        TLMaximalLevel->setWordWrap(false);

        gridLayout_3->addWidget(TLMaximalLevel, 1, 0, 1, 1);

        SpinBoxNivMax = new QSpinBox(GBAdvancedOptions);
        SpinBoxNivMax->setObjectName(QString::fromUtf8("SpinBoxNivMax"));
        SpinBoxNivMax->setValue(99);

        gridLayout_3->addWidget(SpinBoxNivMax, 1, 1, 1, 1);

        GBAdapInit = new QGroupBox(GBAdvancedOptions);
        GBAdapInit->setObjectName(QString::fromUtf8("GBAdapInit"));
        gridLayout_2 = new QGridLayout(GBAdapInit);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        RBAIN = new QRadioButton(GBAdapInit);
        RBAIN->setObjectName(QString::fromUtf8("RBAIN"));
        RBAIN->setChecked(true);

        gridLayout_2->addWidget(RBAIN, 0, 0, 1, 1);

        RBAIR = new QRadioButton(GBAdapInit);
        RBAIR->setObjectName(QString::fromUtf8("RBAIR"));

        gridLayout_2->addWidget(RBAIR, 0, 1, 1, 1);

        RBAID = new QRadioButton(GBAdapInit);
        RBAID->setObjectName(QString::fromUtf8("RBAID"));

        gridLayout_2->addWidget(RBAID, 0, 2, 1, 1);


        gridLayout_3->addWidget(GBAdapInit, 2, 0, 1, 2);

        CBOutputLevel = new QCheckBox(GBAdvancedOptions);
        CBOutputLevel->setObjectName(QString::fromUtf8("CBOutputLevel"));

        gridLayout_3->addWidget(CBOutputLevel, 3, 0, 1, 1);

        CBOutputQuality = new QCheckBox(GBAdvancedOptions);
        CBOutputQuality->setObjectName(QString::fromUtf8("CBOutputQuality"));

        gridLayout_3->addWidget(CBOutputQuality, 4, 0, 1, 1);

        CBOutputDiameter = new QCheckBox(GBAdvancedOptions);
        CBOutputDiameter->setObjectName(QString::fromUtf8("CBOutputDiameter"));

        gridLayout_3->addWidget(CBOutputDiameter, 5, 0, 1, 1);


        gridLayout_5->addWidget(GBAdvancedOptions, 9, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 9, 3, 1, 1);

        GBButtons = new QGroupBox(scrollAreaWidgetContents);
        GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
        gridLayout8 = new QGridLayout(GBButtons);
#ifndef Q_OS_MAC
        gridLayout8->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout8->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
        buttonOk = new QPushButton(GBButtons);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

        gridLayout8->addWidget(buttonOk, 0, 0, 1, 1);

        buttonApply = new QPushButton(GBButtons);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

        gridLayout8->addWidget(buttonApply, 0, 1, 1, 1);

        buttonCancel = new QPushButton(GBButtons);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        gridLayout8->addWidget(buttonCancel, 0, 2, 1, 1);

        buttonHelp = new QPushButton(GBButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

        gridLayout8->addWidget(buttonHelp, 0, 3, 1, 1);


        gridLayout_5->addWidget(GBButtons, 10, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 10, 2, 1, 1);

        CreateHypothesis->setWidget(scrollAreaWidgetContents);

        retranslateUi(CreateHypothesis);

        QMetaObject::connectSlotsByName(CreateHypothesis);
    } // setupUi

    void retranslateUi(QScrollArea *CreateHypothesis)
    {
        CreateHypothesis->setWindowTitle(QApplication::translate("CreateHypothesis", "Create an hypothesis", 0));
        Name->setText(QApplication::translate("CreateHypothesis", "Name", 0));
        GBTypeAdaptation->setTitle(QApplication::translate("CreateHypothesis", "Type of adaptation", 0));
        RBUniforme->setText(QApplication::translate("CreateHypothesis", "Uniform", 0));
        RBChamp->setText(QApplication::translate("CreateHypothesis", "Driven by a field", 0));
        RBZone->setText(QApplication::translate("CreateHypothesis", "With geometrical zones", 0));
        CBGroupe->setText(QApplication::translate("CreateHypothesis", "Filtering with groups", 0));
        GBUniform->setTitle(QApplication::translate("CreateHypothesis", "Uniform adaptation", 0));
        RBUniDera->setText(QApplication::translate("CreateHypothesis", "Coarsening", 0));
        RBUniRaff->setText(QApplication::translate("CreateHypothesis", "Refinement", 0));
        GBFieldFile->setTitle(QString());
        FieldFile->setText(QApplication::translate("CreateHypothesis", "File of the fields", 0));
        GBFieldManagement->setTitle(QApplication::translate("CreateHypothesis", "Governing field for the adaptation", 0));
        FieldName->setText(QApplication::translate("CreateHypothesis", "Field name", 0));
        QTableWidgetItem *___qtablewidgetitem = TWCMP->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CreateHypothesis", "Selection", 0));
        QTableWidgetItem *___qtablewidgetitem1 = TWCMP->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CreateHypothesis", "Component", 0));
        RBL2->setText(QApplication::translate("CreateHypothesis", "L2 norm", 0));
        RBInf->setText(QApplication::translate("CreateHypothesis", "Infinite norm", 0));
        CBJump->setText(QApplication::translate("CreateHypothesis", "Jump between elements", 0));
        GBRefinementThresholds->setTitle(QApplication::translate("CreateHypothesis", "Refinement threshold", 0));
        RBRPE->setText(QApplication::translate("CreateHypothesis", "Percentage of meshes", 0));
        SpinBox_RPE->setSuffix(QApplication::translate("CreateHypothesis", " %", 0));
        RBRRel->setText(QApplication::translate("CreateHypothesis", "Relative", 0));
        SpinBox_RRel->setSuffix(QApplication::translate("CreateHypothesis", " %", 0));
        RBRAbs->setText(QApplication::translate("CreateHypothesis", "Absolute", 0));
        RBRMuSigma->setText(QApplication::translate("CreateHypothesis", "Mean + n*(std deviation)", 0));
        RBRNo->setText(QApplication::translate("CreateHypothesis", "No refinement", 0));
        GBCoarseningThresholds->setTitle(QApplication::translate("CreateHypothesis", "Coarsening threshold", 0));
        RBCPE->setText(QApplication::translate("CreateHypothesis", "Percentage of meshes", 0));
        SpinBox_CPE->setSuffix(QApplication::translate("CreateHypothesis", " %", 0));
        RBCRel->setText(QApplication::translate("CreateHypothesis", "Relative", 0));
        SpinBox_CRel->setSuffix(QApplication::translate("CreateHypothesis", " %", 0));
        RBCAbs->setText(QApplication::translate("CreateHypothesis", "Absolute", 0));
        RBCMuSigma->setText(QApplication::translate("CreateHypothesis", "Mean - n*(std deviation)", 0));
        RBCNo->setText(QApplication::translate("CreateHypothesis", "No coarsening", 0));
        GBAreaManagement->setTitle(QApplication::translate("CreateHypothesis", "Zone management", 0));
        QTableWidgetItem *___qtablewidgetitem2 = TWZone->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("CreateHypothesis", "Refinement", 0));
        QTableWidgetItem *___qtablewidgetitem3 = TWZone->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("CreateHypothesis", "Coarsening", 0));
        QTableWidgetItem *___qtablewidgetitem4 = TWZone->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("CreateHypothesis", "Zone name", 0));
        PBZoneNew->setText(QApplication::translate("CreateHypothesis", "New", 0));
        PBZoneEdit->setText(QApplication::translate("CreateHypothesis", "Edit", 0));
        PBZoneDelete->setText(QString());
        GBField->setTitle(QApplication::translate("CreateHypothesis", "Field Interpolation", 0));
        RBFieldNo->setText(QApplication::translate("CreateHypothesis", "None", 0));
        RBFieldAll->setText(QApplication::translate("CreateHypothesis", "All", 0));
        RBFieldChosen->setText(QApplication::translate("CreateHypothesis", "Chosen", 0));
        QTableWidgetItem *___qtablewidgetitem5 = TWField->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("CreateHypothesis", "Selection", 0));
        QTableWidgetItem *___qtablewidgetitem6 = TWField->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("CreateHypothesis", "Field Name", 0));
        CBAdvanced->setText(QApplication::translate("CreateHypothesis", "Advanced options", 0));
        GBAdvancedOptions->setTitle(QApplication::translate("CreateHypothesis", "Advanced options", 0));
        TLMinimalDiameter->setText(QApplication::translate("CreateHypothesis", "Minimal diameter", 0));
        TLMaximalLevel->setText(QApplication::translate("CreateHypothesis", "Maximal level", 0));
        GBAdapInit->setTitle(QApplication::translate("CreateHypothesis", "Initialization of adaptation", 0));
        RBAIN->setText(QApplication::translate("CreateHypothesis", "Nothing", 0));
        RBAIR->setText(QApplication::translate("CreateHypothesis", "Refinement", 0));
        RBAID->setText(QApplication::translate("CreateHypothesis", "Coarsening", 0));
        CBOutputLevel->setText(QApplication::translate("CreateHypothesis", "Output of the level of refinement", 0));
        CBOutputQuality->setText(QApplication::translate("CreateHypothesis", "Output of the qualities", 0));
        CBOutputDiameter->setText(QApplication::translate("CreateHypothesis", "Output of the diameters", 0));
        GBButtons->setTitle(QString());
        buttonOk->setText(QApplication::translate("CreateHypothesis", "OK", 0));
        buttonApply->setText(QApplication::translate("CreateHypothesis", "Apply", 0));
        buttonCancel->setText(QApplication::translate("CreateHypothesis", "Cancel", 0));
        buttonHelp->setText(QApplication::translate("CreateHypothesis", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateHypothesis: public Ui_CreateHypothesis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEHYPOTHESIS_H
