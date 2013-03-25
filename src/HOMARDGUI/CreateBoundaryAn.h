/********************************************************************************
** Form generated from reading UI file 'CreateBoundaryAn.ui'
**
** Created: Thu Mar 21 17:06:19 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATEBOUNDARYAN_H
#define CREATEBOUNDARYAN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CreateBoundaryAn
{
public:
    QGridLayout *gridLayout_4;
    QLabel *Name;
    QLineEdit *LEBoundaryName;
    QGroupBox *TypeBoundary;
    QGridLayout *gridLayout;
    QRadioButton *RBCylindre;
    QRadioButton *RBSphere;
    QRadioButton *RBCone;
    QGroupBox *gBCylindre;
    QGridLayout *gridLayout1;
    QDoubleSpinBox *SpinBox_Xcent;
    QLabel *TLXcent;
    QDoubleSpinBox *SpinBox_Radius;
    QDoubleSpinBox *SpinBox_Zcent;
    QLabel *TLradius;
    QLabel *TLZcent;
    QLabel *TLYcent;
    QDoubleSpinBox *SpinBox_Ycent;
    QLabel *TLXaxis;
    QLabel *TLYaxis;
    QLabel *TLZaxis;
    QDoubleSpinBox *SpinBox_Zaxis;
    QDoubleSpinBox *SpinBox_Yaxis;
    QDoubleSpinBox *SpinBox_Xaxis;
    QGroupBox *gBSphere;
    QGridLayout *gridLayout2;
    QDoubleSpinBox *SpinBox_Rayon;
    QDoubleSpinBox *SpinBox_Zcentre;
    QLabel *TLRayon;
    QLabel *TLZcentre;
    QLabel *TLYcentre;
    QDoubleSpinBox *SpinBox_Ycentre;
    QDoubleSpinBox *SpinBox_Xcentre;
    QLabel *TLXcentre;
    QGroupBox *gBCone;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *RB_Def_radius;
    QRadioButton *RB_Def_angle;
    QLabel *TLCone_X1;
    QDoubleSpinBox *SpinBox_Cone_X1;
    QLabel *TLCone_X2;
    QDoubleSpinBox *SpinBox_Cone_X2;
    QLabel *TLCone_Y1;
    QDoubleSpinBox *SpinBox_Cone_Y1;
    QLabel *TLCone_Y2;
    QDoubleSpinBox *SpinBox_Cone_Y2;
    QLabel *TLCone_Z1;
    QDoubleSpinBox *SpinBox_Cone_Z1;
    QLabel *TLCone_Z2;
    QDoubleSpinBox *SpinBox_Cone_Z2;
    QLabel *TLCone_V1;
    QDoubleSpinBox *SpinBox_Cone_V1;
    QLabel *TLCone_V2;
    QDoubleSpinBox *SpinBox_Cone_V2;
    QGroupBox *GBButtons;
    QGridLayout *gridLayout3;
    QPushButton *buttonHelp;
    QPushButton *buttonCancel;
    QPushButton *buttonApply;
    QPushButton *buttonOk;

    void setupUi(QDialog *CreateBoundaryAn)
    {
        if (CreateBoundaryAn->objectName().isEmpty())
            CreateBoundaryAn->setObjectName(QString::fromUtf8("CreateBoundaryAn"));
        CreateBoundaryAn->resize(527, 701);
        CreateBoundaryAn->setAutoFillBackground(true);
        CreateBoundaryAn->setSizeGripEnabled(true);
        gridLayout_4 = new QGridLayout(CreateBoundaryAn);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        Name = new QLabel(CreateBoundaryAn);
        Name->setObjectName(QString::fromUtf8("Name"));

        gridLayout_4->addWidget(Name, 0, 0, 1, 1);

        LEBoundaryName = new QLineEdit(CreateBoundaryAn);
        LEBoundaryName->setObjectName(QString::fromUtf8("LEBoundaryName"));
        LEBoundaryName->setMaxLength(32);

        gridLayout_4->addWidget(LEBoundaryName, 0, 1, 1, 1);

        TypeBoundary = new QGroupBox(CreateBoundaryAn);
        TypeBoundary->setObjectName(QString::fromUtf8("TypeBoundary"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TypeBoundary->sizePolicy().hasHeightForWidth());
        TypeBoundary->setSizePolicy(sizePolicy);
        TypeBoundary->setMinimumSize(QSize(340, 0));
        gridLayout = new QGridLayout(TypeBoundary);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RBCylindre = new QRadioButton(TypeBoundary);
        RBCylindre->setObjectName(QString::fromUtf8("RBCylindre"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../resources/cylinderpointvector.png"), QSize(), QIcon::Normal, QIcon::Off);
        RBCylindre->setIcon(icon);
        RBCylindre->setCheckable(true);
        RBCylindre->setChecked(true);

        gridLayout->addWidget(RBCylindre, 0, 0, 1, 1);

        RBSphere = new QRadioButton(TypeBoundary);
        RBSphere->setObjectName(QString::fromUtf8("RBSphere"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../resources/zone_spherepoint.png"), QSize(), QIcon::Normal, QIcon::Off);
        RBSphere->setIcon(icon1);

        gridLayout->addWidget(RBSphere, 0, 1, 1, 1);

        RBCone = new QRadioButton(TypeBoundary);
        RBCone->setObjectName(QString::fromUtf8("RBCone"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../resources/cone.png"), QSize(), QIcon::Normal, QIcon::Off);
        RBCone->setIcon(icon2);

        gridLayout->addWidget(RBCone, 0, 2, 1, 1);


        gridLayout_4->addWidget(TypeBoundary, 1, 0, 1, 2);

        gBCylindre = new QGroupBox(CreateBoundaryAn);
        gBCylindre->setObjectName(QString::fromUtf8("gBCylindre"));
        sizePolicy.setHeightForWidth(gBCylindre->sizePolicy().hasHeightForWidth());
        gBCylindre->setSizePolicy(sizePolicy);
        gridLayout1 = new QGridLayout(gBCylindre);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        SpinBox_Xcent = new QDoubleSpinBox(gBCylindre);
        SpinBox_Xcent->setObjectName(QString::fromUtf8("SpinBox_Xcent"));
        SpinBox_Xcent->setDecimals(5);
        SpinBox_Xcent->setMinimum(-1e+09);
        SpinBox_Xcent->setMaximum(1e+09);
        SpinBox_Xcent->setValue(0);

        gridLayout1->addWidget(SpinBox_Xcent, 0, 1, 1, 1);

        TLXcent = new QLabel(gBCylindre);
        TLXcent->setObjectName(QString::fromUtf8("TLXcent"));
        sizePolicy.setHeightForWidth(TLXcent->sizePolicy().hasHeightForWidth());
        TLXcent->setSizePolicy(sizePolicy);
        TLXcent->setWordWrap(false);

        gridLayout1->addWidget(TLXcent, 0, 0, 1, 1);

        SpinBox_Radius = new QDoubleSpinBox(gBCylindre);
        SpinBox_Radius->setObjectName(QString::fromUtf8("SpinBox_Radius"));
        SpinBox_Radius->setDecimals(5);
        SpinBox_Radius->setMaximum(1e+09);

        gridLayout1->addWidget(SpinBox_Radius, 3, 1, 1, 2);

        SpinBox_Zcent = new QDoubleSpinBox(gBCylindre);
        SpinBox_Zcent->setObjectName(QString::fromUtf8("SpinBox_Zcent"));
        SpinBox_Zcent->setDecimals(5);
        SpinBox_Zcent->setMinimum(-1e+09);
        SpinBox_Zcent->setMaximum(1e+09);
        SpinBox_Zcent->setValue(0);

        gridLayout1->addWidget(SpinBox_Zcent, 2, 1, 1, 1);

        TLradius = new QLabel(gBCylindre);
        TLradius->setObjectName(QString::fromUtf8("TLradius"));
        sizePolicy.setHeightForWidth(TLradius->sizePolicy().hasHeightForWidth());
        TLradius->setSizePolicy(sizePolicy);
        TLradius->setWordWrap(false);

        gridLayout1->addWidget(TLradius, 3, 0, 1, 1);

        TLZcent = new QLabel(gBCylindre);
        TLZcent->setObjectName(QString::fromUtf8("TLZcent"));
        sizePolicy.setHeightForWidth(TLZcent->sizePolicy().hasHeightForWidth());
        TLZcent->setSizePolicy(sizePolicy);
        TLZcent->setWordWrap(false);

        gridLayout1->addWidget(TLZcent, 2, 0, 1, 1);

        TLYcent = new QLabel(gBCylindre);
        TLYcent->setObjectName(QString::fromUtf8("TLYcent"));
        sizePolicy.setHeightForWidth(TLYcent->sizePolicy().hasHeightForWidth());
        TLYcent->setSizePolicy(sizePolicy);
        TLYcent->setWordWrap(false);

        gridLayout1->addWidget(TLYcent, 1, 0, 1, 1);

        SpinBox_Ycent = new QDoubleSpinBox(gBCylindre);
        SpinBox_Ycent->setObjectName(QString::fromUtf8("SpinBox_Ycent"));
        SpinBox_Ycent->setDecimals(5);
        SpinBox_Ycent->setMinimum(-1e+09);
        SpinBox_Ycent->setMaximum(1e+09);
        SpinBox_Ycent->setValue(0);

        gridLayout1->addWidget(SpinBox_Ycent, 1, 1, 1, 1);

        TLXaxis = new QLabel(gBCylindre);
        TLXaxis->setObjectName(QString::fromUtf8("TLXaxis"));
        sizePolicy.setHeightForWidth(TLXaxis->sizePolicy().hasHeightForWidth());
        TLXaxis->setSizePolicy(sizePolicy);
        TLXaxis->setWordWrap(false);

        gridLayout1->addWidget(TLXaxis, 0, 2, 1, 1);

        TLYaxis = new QLabel(gBCylindre);
        TLYaxis->setObjectName(QString::fromUtf8("TLYaxis"));
        sizePolicy.setHeightForWidth(TLYaxis->sizePolicy().hasHeightForWidth());
        TLYaxis->setSizePolicy(sizePolicy);
        TLYaxis->setWordWrap(false);

        gridLayout1->addWidget(TLYaxis, 1, 2, 1, 1);

        TLZaxis = new QLabel(gBCylindre);
        TLZaxis->setObjectName(QString::fromUtf8("TLZaxis"));
        sizePolicy.setHeightForWidth(TLZaxis->sizePolicy().hasHeightForWidth());
        TLZaxis->setSizePolicy(sizePolicy);
        TLZaxis->setWordWrap(false);

        gridLayout1->addWidget(TLZaxis, 2, 2, 1, 1);

        SpinBox_Zaxis = new QDoubleSpinBox(gBCylindre);
        SpinBox_Zaxis->setObjectName(QString::fromUtf8("SpinBox_Zaxis"));
        SpinBox_Zaxis->setDecimals(5);
        SpinBox_Zaxis->setMinimum(-1e+09);
        SpinBox_Zaxis->setMaximum(1e+09);
        SpinBox_Zaxis->setValue(0);

        gridLayout1->addWidget(SpinBox_Zaxis, 2, 3, 1, 1);

        SpinBox_Yaxis = new QDoubleSpinBox(gBCylindre);
        SpinBox_Yaxis->setObjectName(QString::fromUtf8("SpinBox_Yaxis"));
        SpinBox_Yaxis->setDecimals(5);
        SpinBox_Yaxis->setMinimum(-1e+09);
        SpinBox_Yaxis->setMaximum(1e+09);
        SpinBox_Yaxis->setValue(0);

        gridLayout1->addWidget(SpinBox_Yaxis, 1, 3, 1, 1);

        SpinBox_Xaxis = new QDoubleSpinBox(gBCylindre);
        SpinBox_Xaxis->setObjectName(QString::fromUtf8("SpinBox_Xaxis"));
        SpinBox_Xaxis->setDecimals(5);
        SpinBox_Xaxis->setMinimum(-1e+09);
        SpinBox_Xaxis->setMaximum(1e+09);
        SpinBox_Xaxis->setValue(0);

        gridLayout1->addWidget(SpinBox_Xaxis, 0, 3, 1, 1);


        gridLayout_4->addWidget(gBCylindre, 2, 0, 1, 2);

        gBSphere = new QGroupBox(CreateBoundaryAn);
        gBSphere->setObjectName(QString::fromUtf8("gBSphere"));
        sizePolicy.setHeightForWidth(gBSphere->sizePolicy().hasHeightForWidth());
        gBSphere->setSizePolicy(sizePolicy);
        gridLayout2 = new QGridLayout(gBSphere);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        SpinBox_Rayon = new QDoubleSpinBox(gBSphere);
        SpinBox_Rayon->setObjectName(QString::fromUtf8("SpinBox_Rayon"));
        SpinBox_Rayon->setDecimals(5);
        SpinBox_Rayon->setMinimum(0);
        SpinBox_Rayon->setMaximum(1e+09);
        SpinBox_Rayon->setValue(0);

        gridLayout2->addWidget(SpinBox_Rayon, 1, 3, 1, 1);

        SpinBox_Zcentre = new QDoubleSpinBox(gBSphere);
        SpinBox_Zcentre->setObjectName(QString::fromUtf8("SpinBox_Zcentre"));
        SpinBox_Zcentre->setDecimals(5);
        SpinBox_Zcentre->setMinimum(-1e+09);
        SpinBox_Zcentre->setMaximum(1e+09);
        SpinBox_Zcentre->setValue(0);

        gridLayout2->addWidget(SpinBox_Zcentre, 2, 1, 1, 1);

        TLRayon = new QLabel(gBSphere);
        TLRayon->setObjectName(QString::fromUtf8("TLRayon"));
        sizePolicy.setHeightForWidth(TLRayon->sizePolicy().hasHeightForWidth());
        TLRayon->setSizePolicy(sizePolicy);
        TLRayon->setWordWrap(false);

        gridLayout2->addWidget(TLRayon, 1, 2, 1, 1);

        TLZcentre = new QLabel(gBSphere);
        TLZcentre->setObjectName(QString::fromUtf8("TLZcentre"));
        sizePolicy.setHeightForWidth(TLZcentre->sizePolicy().hasHeightForWidth());
        TLZcentre->setSizePolicy(sizePolicy);
        TLZcentre->setWordWrap(false);

        gridLayout2->addWidget(TLZcentre, 2, 0, 1, 1);

        TLYcentre = new QLabel(gBSphere);
        TLYcentre->setObjectName(QString::fromUtf8("TLYcentre"));
        sizePolicy.setHeightForWidth(TLYcentre->sizePolicy().hasHeightForWidth());
        TLYcentre->setSizePolicy(sizePolicy);
        TLYcentre->setWordWrap(false);

        gridLayout2->addWidget(TLYcentre, 1, 0, 1, 1);

        SpinBox_Ycentre = new QDoubleSpinBox(gBSphere);
        SpinBox_Ycentre->setObjectName(QString::fromUtf8("SpinBox_Ycentre"));
        SpinBox_Ycentre->setDecimals(5);
        SpinBox_Ycentre->setMinimum(-1e+09);
        SpinBox_Ycentre->setMaximum(1e+09);
        SpinBox_Ycentre->setValue(0);

        gridLayout2->addWidget(SpinBox_Ycentre, 1, 1, 1, 1);

        SpinBox_Xcentre = new QDoubleSpinBox(gBSphere);
        SpinBox_Xcentre->setObjectName(QString::fromUtf8("SpinBox_Xcentre"));
        SpinBox_Xcentre->setDecimals(5);
        SpinBox_Xcentre->setMinimum(-1e+09);
        SpinBox_Xcentre->setMaximum(1e+09);
        SpinBox_Xcentre->setValue(0);

        gridLayout2->addWidget(SpinBox_Xcentre, 0, 1, 1, 1);

        TLXcentre = new QLabel(gBSphere);
        TLXcentre->setObjectName(QString::fromUtf8("TLXcentre"));
        sizePolicy.setHeightForWidth(TLXcentre->sizePolicy().hasHeightForWidth());
        TLXcentre->setSizePolicy(sizePolicy);
        TLXcentre->setWordWrap(false);

        gridLayout2->addWidget(TLXcentre, 0, 0, 1, 1);


        gridLayout_4->addWidget(gBSphere, 3, 0, 1, 2);

        gBCone = new QGroupBox(CreateBoundaryAn);
        gBCone->setObjectName(QString::fromUtf8("gBCone"));
        sizePolicy.setHeightForWidth(gBCone->sizePolicy().hasHeightForWidth());
        gBCone->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(gBCone);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(gBCone);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        RB_Def_radius = new QRadioButton(groupBox);
        RB_Def_radius->setObjectName(QString::fromUtf8("RB_Def_radius"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../resources/conedxyz.png"), QSize(), QIcon::Normal, QIcon::Off);
        RB_Def_radius->setIcon(icon3);
        RB_Def_radius->setChecked(true);

        gridLayout_2->addWidget(RB_Def_radius, 0, 0, 1, 1);

        RB_Def_angle = new QRadioButton(groupBox);
        RB_Def_angle->setObjectName(QString::fromUtf8("RB_Def_angle"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../resources/conepointvector.png"), QSize(), QIcon::Normal, QIcon::Off);
        RB_Def_angle->setIcon(icon4);

        gridLayout_2->addWidget(RB_Def_angle, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 2);

        TLCone_X1 = new QLabel(gBCone);
        TLCone_X1->setObjectName(QString::fromUtf8("TLCone_X1"));
        sizePolicy.setHeightForWidth(TLCone_X1->sizePolicy().hasHeightForWidth());
        TLCone_X1->setSizePolicy(sizePolicy);
        TLCone_X1->setWordWrap(false);

        gridLayout_3->addWidget(TLCone_X1, 1, 0, 1, 1);

        SpinBox_Cone_X1 = new QDoubleSpinBox(gBCone);
        SpinBox_Cone_X1->setObjectName(QString::fromUtf8("SpinBox_Cone_X1"));
        SpinBox_Cone_X1->setDecimals(5);
        SpinBox_Cone_X1->setMinimum(-1e+09);
        SpinBox_Cone_X1->setMaximum(1e+09);
        SpinBox_Cone_X1->setValue(0);

        gridLayout_3->addWidget(SpinBox_Cone_X1, 1, 1, 1, 1);

        TLCone_X2 = new QLabel(gBCone);
        TLCone_X2->setObjectName(QString::fromUtf8("TLCone_X2"));
        sizePolicy.setHeightForWidth(TLCone_X2->sizePolicy().hasHeightForWidth());
        TLCone_X2->setSizePolicy(sizePolicy);
        TLCone_X2->setWordWrap(false);

        gridLayout_3->addWidget(TLCone_X2, 1, 2, 1, 1);

        SpinBox_Cone_X2 = new QDoubleSpinBox(gBCone);
        SpinBox_Cone_X2->setObjectName(QString::fromUtf8("SpinBox_Cone_X2"));
        SpinBox_Cone_X2->setDecimals(5);
        SpinBox_Cone_X2->setMinimum(-1e+09);
        SpinBox_Cone_X2->setMaximum(1e+09);
        SpinBox_Cone_X2->setValue(0);

        gridLayout_3->addWidget(SpinBox_Cone_X2, 1, 3, 1, 1);

        TLCone_Y1 = new QLabel(gBCone);
        TLCone_Y1->setObjectName(QString::fromUtf8("TLCone_Y1"));
        sizePolicy.setHeightForWidth(TLCone_Y1->sizePolicy().hasHeightForWidth());
        TLCone_Y1->setSizePolicy(sizePolicy);
        TLCone_Y1->setWordWrap(false);

        gridLayout_3->addWidget(TLCone_Y1, 2, 0, 1, 1);

        SpinBox_Cone_Y1 = new QDoubleSpinBox(gBCone);
        SpinBox_Cone_Y1->setObjectName(QString::fromUtf8("SpinBox_Cone_Y1"));
        SpinBox_Cone_Y1->setDecimals(5);
        SpinBox_Cone_Y1->setMinimum(-1e+09);
        SpinBox_Cone_Y1->setMaximum(1e+09);
        SpinBox_Cone_Y1->setValue(0);

        gridLayout_3->addWidget(SpinBox_Cone_Y1, 2, 1, 1, 1);

        TLCone_Y2 = new QLabel(gBCone);
        TLCone_Y2->setObjectName(QString::fromUtf8("TLCone_Y2"));
        sizePolicy.setHeightForWidth(TLCone_Y2->sizePolicy().hasHeightForWidth());
        TLCone_Y2->setSizePolicy(sizePolicy);
        TLCone_Y2->setWordWrap(false);

        gridLayout_3->addWidget(TLCone_Y2, 2, 2, 1, 1);

        SpinBox_Cone_Y2 = new QDoubleSpinBox(gBCone);
        SpinBox_Cone_Y2->setObjectName(QString::fromUtf8("SpinBox_Cone_Y2"));
        SpinBox_Cone_Y2->setDecimals(5);
        SpinBox_Cone_Y2->setMinimum(-1e+09);
        SpinBox_Cone_Y2->setMaximum(1e+09);
        SpinBox_Cone_Y2->setValue(0);

        gridLayout_3->addWidget(SpinBox_Cone_Y2, 2, 3, 1, 1);

        TLCone_Z1 = new QLabel(gBCone);
        TLCone_Z1->setObjectName(QString::fromUtf8("TLCone_Z1"));
        sizePolicy.setHeightForWidth(TLCone_Z1->sizePolicy().hasHeightForWidth());
        TLCone_Z1->setSizePolicy(sizePolicy);
        TLCone_Z1->setWordWrap(false);

        gridLayout_3->addWidget(TLCone_Z1, 3, 0, 1, 1);

        SpinBox_Cone_Z1 = new QDoubleSpinBox(gBCone);
        SpinBox_Cone_Z1->setObjectName(QString::fromUtf8("SpinBox_Cone_Z1"));
        SpinBox_Cone_Z1->setDecimals(5);
        SpinBox_Cone_Z1->setMinimum(-1e+09);
        SpinBox_Cone_Z1->setMaximum(1e+09);
        SpinBox_Cone_Z1->setValue(0);

        gridLayout_3->addWidget(SpinBox_Cone_Z1, 3, 1, 1, 1);

        TLCone_Z2 = new QLabel(gBCone);
        TLCone_Z2->setObjectName(QString::fromUtf8("TLCone_Z2"));
        sizePolicy.setHeightForWidth(TLCone_Z2->sizePolicy().hasHeightForWidth());
        TLCone_Z2->setSizePolicy(sizePolicy);
        TLCone_Z2->setWordWrap(false);

        gridLayout_3->addWidget(TLCone_Z2, 3, 2, 1, 1);

        SpinBox_Cone_Z2 = new QDoubleSpinBox(gBCone);
        SpinBox_Cone_Z2->setObjectName(QString::fromUtf8("SpinBox_Cone_Z2"));
        SpinBox_Cone_Z2->setDecimals(5);
        SpinBox_Cone_Z2->setMinimum(-1e+09);
        SpinBox_Cone_Z2->setMaximum(1e+09);
        SpinBox_Cone_Z2->setValue(0);

        gridLayout_3->addWidget(SpinBox_Cone_Z2, 3, 3, 1, 1);

        TLCone_V1 = new QLabel(gBCone);
        TLCone_V1->setObjectName(QString::fromUtf8("TLCone_V1"));
        sizePolicy.setHeightForWidth(TLCone_V1->sizePolicy().hasHeightForWidth());
        TLCone_V1->setSizePolicy(sizePolicy);
        TLCone_V1->setWordWrap(false);

        gridLayout_3->addWidget(TLCone_V1, 4, 0, 1, 1);

        SpinBox_Cone_V1 = new QDoubleSpinBox(gBCone);
        SpinBox_Cone_V1->setObjectName(QString::fromUtf8("SpinBox_Cone_V1"));
        SpinBox_Cone_V1->setDecimals(14);
        SpinBox_Cone_V1->setMaximum(1e+09);

        gridLayout_3->addWidget(SpinBox_Cone_V1, 4, 1, 1, 1);

        TLCone_V2 = new QLabel(gBCone);
        TLCone_V2->setObjectName(QString::fromUtf8("TLCone_V2"));
        sizePolicy.setHeightForWidth(TLCone_V2->sizePolicy().hasHeightForWidth());
        TLCone_V2->setSizePolicy(sizePolicy);
        TLCone_V2->setWordWrap(false);

        gridLayout_3->addWidget(TLCone_V2, 4, 2, 1, 1);

        SpinBox_Cone_V2 = new QDoubleSpinBox(gBCone);
        SpinBox_Cone_V2->setObjectName(QString::fromUtf8("SpinBox_Cone_V2"));
        SpinBox_Cone_V2->setDecimals(14);
        SpinBox_Cone_V2->setMaximum(1e+09);

        gridLayout_3->addWidget(SpinBox_Cone_V2, 4, 3, 1, 1);


        gridLayout_4->addWidget(gBCone, 4, 0, 1, 2);

        GBButtons = new QGroupBox(CreateBoundaryAn);
        GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
        sizePolicy.setHeightForWidth(GBButtons->sizePolicy().hasHeightForWidth());
        GBButtons->setSizePolicy(sizePolicy);
        gridLayout3 = new QGridLayout(GBButtons);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout3->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        buttonHelp = new QPushButton(GBButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

        gridLayout3->addWidget(buttonHelp, 0, 3, 1, 1);

        buttonCancel = new QPushButton(GBButtons);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        gridLayout3->addWidget(buttonCancel, 0, 2, 1, 1);

        buttonApply = new QPushButton(GBButtons);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

        gridLayout3->addWidget(buttonApply, 0, 1, 1, 1);

        buttonOk = new QPushButton(GBButtons);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

        gridLayout3->addWidget(buttonOk, 0, 0, 1, 1);


        gridLayout_4->addWidget(GBButtons, 5, 0, 1, 2);


        retranslateUi(CreateBoundaryAn);

        QMetaObject::connectSlotsByName(CreateBoundaryAn);
    } // setupUi

    void retranslateUi(QDialog *CreateBoundaryAn)
    {
        CreateBoundaryAn->setWindowTitle(QApplication::translate("CreateBoundaryAn", "Create an analytical boundary", 0, QApplication::UnicodeUTF8));
        Name->setText(QApplication::translate("CreateBoundaryAn", "Name", 0, QApplication::UnicodeUTF8));
        TypeBoundary->setTitle(QApplication::translate("CreateBoundaryAn", "Type of boundary", 0, QApplication::UnicodeUTF8));
        RBCylindre->setText(QApplication::translate("CreateBoundaryAn", "Cylinder", 0, QApplication::UnicodeUTF8));
        RBSphere->setText(QApplication::translate("CreateBoundaryAn", "Sphere", 0, QApplication::UnicodeUTF8));
        RBCone->setText(QApplication::translate("CreateBoundaryAn", "Cone", 0, QApplication::UnicodeUTF8));
        gBCylindre->setTitle(QApplication::translate("CreateBoundaryAn", "Coordinates", 0, QApplication::UnicodeUTF8));
        TLXcent->setText(QApplication::translate("CreateBoundaryAn", "X centre", 0, QApplication::UnicodeUTF8));
        TLradius->setText(QApplication::translate("CreateBoundaryAn", "Radius", 0, QApplication::UnicodeUTF8));
        TLZcent->setText(QApplication::translate("CreateBoundaryAn", "Z centre", 0, QApplication::UnicodeUTF8));
        TLYcent->setText(QApplication::translate("CreateBoundaryAn", "Y centre", 0, QApplication::UnicodeUTF8));
        TLXaxis->setText(QApplication::translate("CreateBoundaryAn", "X axis", 0, QApplication::UnicodeUTF8));
        TLYaxis->setText(QApplication::translate("CreateBoundaryAn", "Y axis", 0, QApplication::UnicodeUTF8));
        TLZaxis->setText(QApplication::translate("CreateBoundaryAn", "Z axis", 0, QApplication::UnicodeUTF8));
        gBSphere->setTitle(QApplication::translate("CreateBoundaryAn", "Coordinates", 0, QApplication::UnicodeUTF8));
        TLRayon->setText(QApplication::translate("CreateBoundaryAn", "Radius", 0, QApplication::UnicodeUTF8));
        TLZcentre->setText(QApplication::translate("CreateBoundaryAn", "Z centre", 0, QApplication::UnicodeUTF8));
        TLYcentre->setText(QApplication::translate("CreateBoundaryAn", "Y centre", 0, QApplication::UnicodeUTF8));
        TLXcentre->setText(QApplication::translate("CreateBoundaryAn", "X centre", 0, QApplication::UnicodeUTF8));
        gBCone->setTitle(QApplication::translate("CreateBoundaryAn", "Coordinates", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CreateBoundaryAn", "Definition", 0, QApplication::UnicodeUTF8));
        RB_Def_radius->setText(QApplication::translate("CreateBoundaryAn", "Radius", 0, QApplication::UnicodeUTF8));
        RB_Def_angle->setText(QApplication::translate("CreateBoundaryAn", "Angle", 0, QApplication::UnicodeUTF8));
        TLCone_X1->setText(QApplication::translate("CreateBoundaryAn", "X 1", 0, QApplication::UnicodeUTF8));
        TLCone_X2->setText(QApplication::translate("CreateBoundaryAn", "X 2", 0, QApplication::UnicodeUTF8));
        TLCone_Y1->setText(QApplication::translate("CreateBoundaryAn", "Y 1", 0, QApplication::UnicodeUTF8));
        TLCone_Y2->setText(QApplication::translate("CreateBoundaryAn", "Y 2", 0, QApplication::UnicodeUTF8));
        TLCone_Z1->setText(QApplication::translate("CreateBoundaryAn", "Z 1", 0, QApplication::UnicodeUTF8));
        TLCone_Z2->setText(QApplication::translate("CreateBoundaryAn", "Z 2", 0, QApplication::UnicodeUTF8));
        TLCone_V1->setText(QApplication::translate("CreateBoundaryAn", "V 1", 0, QApplication::UnicodeUTF8));
        TLCone_V2->setText(QApplication::translate("CreateBoundaryAn", "V 2", 0, QApplication::UnicodeUTF8));
        GBButtons->setTitle(QString());
        buttonHelp->setText(QApplication::translate("CreateBoundaryAn", "Help", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CreateBoundaryAn", "Cancel", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("CreateBoundaryAn", "Apply", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("CreateBoundaryAn", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateBoundaryAn: public Ui_CreateBoundaryAn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEBOUNDARYAN_H
