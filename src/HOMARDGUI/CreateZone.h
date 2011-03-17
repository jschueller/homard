/********************************************************************************
** Form generated from reading ui file 'CreateZone.ui'
**
** Created: Mon Sep 27 14:45:47 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef CREATEZONE_H
#define CREATEZONE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CreateZone
{
public:
    QGridLayout *gridLayout_3;
    QLabel *Name;
    QLineEdit *LEZoneName;
    QGroupBox *TypeZone;
    QHBoxLayout *horizontalLayout;
    QRadioButton *RBBox;
    QRadioButton *RBSphere;
    QGroupBox *gBBox;
    QGridLayout *gridLayout;
    QLabel *TLXmini;
    QDoubleSpinBox *SpinBox_Xmini;
    QLabel *TLYmini;
    QDoubleSpinBox *SpinBox_Ymini;
    QLabel *TLZmini;
    QDoubleSpinBox *SpinBox_Zmini;
    QLabel *TLXmaxi;
    QLabel *TLZmaxi;
    QDoubleSpinBox *SpinBox_Zmaxi;
    QLabel *TLYmaxi;
    QDoubleSpinBox *SpinBox_Xmaxi;
    QDoubleSpinBox *SpinBox_Ymaxi;
    QGroupBox *gBSphere;
    QGridLayout *gridLayout_2;
    QLabel *TLXcentre;
    QDoubleSpinBox *SpinBox_Xcentre;
    QLabel *TLYcentre;
    QDoubleSpinBox *SpinBox_Ycentre;
    QLabel *TLRayon;
    QDoubleSpinBox *SpinBox_Rayon;
    QLabel *TLZcentre;
    QDoubleSpinBox *SpinBox_Zcentre;
    QGroupBox *GBButtons;
    QHBoxLayout *hboxLayout;
    QPushButton *buttonOk;
    QPushButton *buttonApply;
    QPushButton *buttonCancel;
    QPushButton *buttonHelp;

    void setupUi(QDialog *CreateZone)
    {
        if (CreateZone->objectName().isEmpty())
            CreateZone->setObjectName(QString::fromUtf8("CreateZone"));
        CreateZone->resize(415, 472);
        CreateZone->setAutoFillBackground(false);
        CreateZone->setSizeGripEnabled(true);
        gridLayout_3 = new QGridLayout(CreateZone);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        Name = new QLabel(CreateZone);
        Name->setObjectName(QString::fromUtf8("Name"));

        gridLayout_3->addWidget(Name, 0, 0, 1, 1);

        LEZoneName = new QLineEdit(CreateZone);
        LEZoneName->setObjectName(QString::fromUtf8("LEZoneName"));
        LEZoneName->setMaxLength(32);

        gridLayout_3->addWidget(LEZoneName, 0, 1, 1, 1);

        TypeZone = new QGroupBox(CreateZone);
        TypeZone->setObjectName(QString::fromUtf8("TypeZone"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TypeZone->sizePolicy().hasHeightForWidth());
        TypeZone->setSizePolicy(sizePolicy);
        TypeZone->setMinimumSize(QSize(340, 0));
        horizontalLayout = new QHBoxLayout(TypeZone);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        RBBox = new QRadioButton(TypeZone);
        RBBox->setObjectName(QString::fromUtf8("RBBox"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../resources/zone_boxdxyz.png"), QSize(), QIcon::Normal, QIcon::Off);
        RBBox->setIcon(icon);
        RBBox->setCheckable(true);
        RBBox->setChecked(true);

        horizontalLayout->addWidget(RBBox);

        RBSphere = new QRadioButton(TypeZone);
        RBSphere->setObjectName(QString::fromUtf8("RBSphere"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../resources/zone_spherepoint.png"), QSize(), QIcon::Normal, QIcon::Off);
        RBSphere->setIcon(icon1);

        horizontalLayout->addWidget(RBSphere);


        gridLayout_3->addWidget(TypeZone, 1, 0, 1, 2);

        gBBox = new QGroupBox(CreateZone);
        gBBox->setObjectName(QString::fromUtf8("gBBox"));
        sizePolicy.setHeightForWidth(gBBox->sizePolicy().hasHeightForWidth());
        gBBox->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(gBBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TLXmini = new QLabel(gBBox);
        TLXmini->setObjectName(QString::fromUtf8("TLXmini"));
        sizePolicy.setHeightForWidth(TLXmini->sizePolicy().hasHeightForWidth());
        TLXmini->setSizePolicy(sizePolicy);
        TLXmini->setWordWrap(false);

        gridLayout->addWidget(TLXmini, 0, 0, 1, 1);

        SpinBox_Xmini = new QDoubleSpinBox(gBBox);
        SpinBox_Xmini->setObjectName(QString::fromUtf8("SpinBox_Xmini"));
        SpinBox_Xmini->setDecimals(5);
        SpinBox_Xmini->setMinimum(-1e+09);
        SpinBox_Xmini->setMaximum(1e+09);
        SpinBox_Xmini->setValue(0);

        gridLayout->addWidget(SpinBox_Xmini, 0, 1, 1, 1);

        TLYmini = new QLabel(gBBox);
        TLYmini->setObjectName(QString::fromUtf8("TLYmini"));
        sizePolicy.setHeightForWidth(TLYmini->sizePolicy().hasHeightForWidth());
        TLYmini->setSizePolicy(sizePolicy);
        TLYmini->setWordWrap(false);

        gridLayout->addWidget(TLYmini, 1, 0, 1, 1);

        SpinBox_Ymini = new QDoubleSpinBox(gBBox);
        SpinBox_Ymini->setObjectName(QString::fromUtf8("SpinBox_Ymini"));
        SpinBox_Ymini->setDecimals(5);
        SpinBox_Ymini->setMinimum(-1e+09);
        SpinBox_Ymini->setMaximum(1e+09);
        SpinBox_Ymini->setValue(0);

        gridLayout->addWidget(SpinBox_Ymini, 1, 1, 1, 1);

        TLZmini = new QLabel(gBBox);
        TLZmini->setObjectName(QString::fromUtf8("TLZmini"));
        sizePolicy.setHeightForWidth(TLZmini->sizePolicy().hasHeightForWidth());
        TLZmini->setSizePolicy(sizePolicy);
        TLZmini->setWordWrap(false);

        gridLayout->addWidget(TLZmini, 2, 0, 1, 1);

        SpinBox_Zmini = new QDoubleSpinBox(gBBox);
        SpinBox_Zmini->setObjectName(QString::fromUtf8("SpinBox_Zmini"));
        SpinBox_Zmini->setDecimals(5);
        SpinBox_Zmini->setMinimum(-1e+09);
        SpinBox_Zmini->setMaximum(1e+09);
        SpinBox_Zmini->setValue(0);

        gridLayout->addWidget(SpinBox_Zmini, 2, 1, 1, 1);

        TLXmaxi = new QLabel(gBBox);
        TLXmaxi->setObjectName(QString::fromUtf8("TLXmaxi"));
        sizePolicy.setHeightForWidth(TLXmaxi->sizePolicy().hasHeightForWidth());
        TLXmaxi->setSizePolicy(sizePolicy);
        TLXmaxi->setWordWrap(false);

        gridLayout->addWidget(TLXmaxi, 0, 2, 1, 1);

        TLZmaxi = new QLabel(gBBox);
        TLZmaxi->setObjectName(QString::fromUtf8("TLZmaxi"));
        sizePolicy.setHeightForWidth(TLZmaxi->sizePolicy().hasHeightForWidth());
        TLZmaxi->setSizePolicy(sizePolicy);
        TLZmaxi->setWordWrap(false);

        gridLayout->addWidget(TLZmaxi, 2, 2, 1, 1);

        SpinBox_Zmaxi = new QDoubleSpinBox(gBBox);
        SpinBox_Zmaxi->setObjectName(QString::fromUtf8("SpinBox_Zmaxi"));
        SpinBox_Zmaxi->setDecimals(5);
        SpinBox_Zmaxi->setMinimum(-1e+09);
        SpinBox_Zmaxi->setMaximum(1e+09);
        SpinBox_Zmaxi->setValue(0);

        gridLayout->addWidget(SpinBox_Zmaxi, 2, 3, 1, 1);

        TLYmaxi = new QLabel(gBBox);
        TLYmaxi->setObjectName(QString::fromUtf8("TLYmaxi"));
        sizePolicy.setHeightForWidth(TLYmaxi->sizePolicy().hasHeightForWidth());
        TLYmaxi->setSizePolicy(sizePolicy);
        TLYmaxi->setWordWrap(false);

        gridLayout->addWidget(TLYmaxi, 1, 2, 1, 1);

        SpinBox_Xmaxi = new QDoubleSpinBox(gBBox);
        SpinBox_Xmaxi->setObjectName(QString::fromUtf8("SpinBox_Xmaxi"));
        SpinBox_Xmaxi->setDecimals(5);
        SpinBox_Xmaxi->setMinimum(-1e+09);
        SpinBox_Xmaxi->setMaximum(1e+09);
        SpinBox_Xmaxi->setValue(0);

        gridLayout->addWidget(SpinBox_Xmaxi, 0, 3, 1, 1);

        SpinBox_Ymaxi = new QDoubleSpinBox(gBBox);
        SpinBox_Ymaxi->setObjectName(QString::fromUtf8("SpinBox_Ymaxi"));
        SpinBox_Ymaxi->setDecimals(5);
        SpinBox_Ymaxi->setMinimum(-1e+09);
        SpinBox_Ymaxi->setMaximum(1e+09);
        SpinBox_Ymaxi->setValue(0);

        gridLayout->addWidget(SpinBox_Ymaxi, 1, 3, 1, 1);


        gridLayout_3->addWidget(gBBox, 2, 0, 1, 2);

        gBSphere = new QGroupBox(CreateZone);
        gBSphere->setObjectName(QString::fromUtf8("gBSphere"));
        sizePolicy.setHeightForWidth(gBSphere->sizePolicy().hasHeightForWidth());
        gBSphere->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(gBSphere);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        TLXcentre = new QLabel(gBSphere);
        TLXcentre->setObjectName(QString::fromUtf8("TLXcentre"));
        sizePolicy.setHeightForWidth(TLXcentre->sizePolicy().hasHeightForWidth());
        TLXcentre->setSizePolicy(sizePolicy);
        TLXcentre->setWordWrap(false);

        gridLayout_2->addWidget(TLXcentre, 0, 0, 1, 1);

        SpinBox_Xcentre = new QDoubleSpinBox(gBSphere);
        SpinBox_Xcentre->setObjectName(QString::fromUtf8("SpinBox_Xcentre"));
        SpinBox_Xcentre->setDecimals(5);
        SpinBox_Xcentre->setMinimum(-1e+09);
        SpinBox_Xcentre->setMaximum(1e+09);
        SpinBox_Xcentre->setValue(0);

        gridLayout_2->addWidget(SpinBox_Xcentre, 0, 1, 1, 1);

        TLYcentre = new QLabel(gBSphere);
        TLYcentre->setObjectName(QString::fromUtf8("TLYcentre"));
        sizePolicy.setHeightForWidth(TLYcentre->sizePolicy().hasHeightForWidth());
        TLYcentre->setSizePolicy(sizePolicy);
        TLYcentre->setWordWrap(false);

        gridLayout_2->addWidget(TLYcentre, 1, 0, 1, 1);

        SpinBox_Ycentre = new QDoubleSpinBox(gBSphere);
        SpinBox_Ycentre->setObjectName(QString::fromUtf8("SpinBox_Ycentre"));
        SpinBox_Ycentre->setDecimals(5);
        SpinBox_Ycentre->setMinimum(-1e+09);
        SpinBox_Ycentre->setMaximum(1e+09);
        SpinBox_Ycentre->setValue(0);

        gridLayout_2->addWidget(SpinBox_Ycentre, 1, 1, 1, 1);

        TLRayon = new QLabel(gBSphere);
        TLRayon->setObjectName(QString::fromUtf8("TLRayon"));
        sizePolicy.setHeightForWidth(TLRayon->sizePolicy().hasHeightForWidth());
        TLRayon->setSizePolicy(sizePolicy);
        TLRayon->setWordWrap(false);

        gridLayout_2->addWidget(TLRayon, 1, 2, 1, 1);

        SpinBox_Rayon = new QDoubleSpinBox(gBSphere);
        SpinBox_Rayon->setObjectName(QString::fromUtf8("SpinBox_Rayon"));
        SpinBox_Rayon->setDecimals(5);
        SpinBox_Rayon->setMinimum(-1e+09);
        SpinBox_Rayon->setMaximum(1e+09);
        SpinBox_Rayon->setValue(0);

        gridLayout_2->addWidget(SpinBox_Rayon, 1, 3, 1, 1);

        TLZcentre = new QLabel(gBSphere);
        TLZcentre->setObjectName(QString::fromUtf8("TLZcentre"));
        sizePolicy.setHeightForWidth(TLZcentre->sizePolicy().hasHeightForWidth());
        TLZcentre->setSizePolicy(sizePolicy);
        TLZcentre->setWordWrap(false);

        gridLayout_2->addWidget(TLZcentre, 2, 0, 1, 1);

        SpinBox_Zcentre = new QDoubleSpinBox(gBSphere);
        SpinBox_Zcentre->setObjectName(QString::fromUtf8("SpinBox_Zcentre"));
        SpinBox_Zcentre->setDecimals(5);
        SpinBox_Zcentre->setMinimum(-1e+09);
        SpinBox_Zcentre->setMaximum(1e+09);
        SpinBox_Zcentre->setValue(0);

        gridLayout_2->addWidget(SpinBox_Zcentre, 2, 1, 1, 1);


        gridLayout_3->addWidget(gBSphere, 3, 0, 1, 2);

        GBButtons = new QGroupBox(CreateZone);
        GBButtons->setObjectName(QString::fromUtf8("GBButtons"));
        sizePolicy.setHeightForWidth(GBButtons->sizePolicy().hasHeightForWidth());
        GBButtons->setSizePolicy(sizePolicy);
        hboxLayout = new QHBoxLayout(GBButtons);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setMargin(9);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        buttonOk = new QPushButton(GBButtons);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

        hboxLayout->addWidget(buttonOk);

        buttonApply = new QPushButton(GBButtons);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

        hboxLayout->addWidget(buttonApply);

        buttonCancel = new QPushButton(GBButtons);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        hboxLayout->addWidget(buttonCancel);

        buttonHelp = new QPushButton(GBButtons);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));

        hboxLayout->addWidget(buttonHelp);


        gridLayout_3->addWidget(GBButtons, 4, 0, 1, 2);


        retranslateUi(CreateZone);

        QMetaObject::connectSlotsByName(CreateZone);
    } // setupUi

    void retranslateUi(QDialog *CreateZone)
    {
        CreateZone->setWindowTitle(QApplication::translate("CreateZone", "Create Zone", 0, QApplication::UnicodeUTF8));
        Name->setText(QApplication::translate("CreateZone", "Name", 0, QApplication::UnicodeUTF8));
        TypeZone->setTitle(QApplication::translate("CreateZone", "Type of zone", 0, QApplication::UnicodeUTF8));
        RBBox->setText(QString());
        RBSphere->setText(QString());
        gBBox->setTitle(QApplication::translate("CreateZone", "Coordinates", 0, QApplication::UnicodeUTF8));
        TLXmini->setText(QApplication::translate("CreateZone", "X mini", 0, QApplication::UnicodeUTF8));
        TLYmini->setText(QApplication::translate("CreateZone", "Y mini", 0, QApplication::UnicodeUTF8));
        TLZmini->setText(QApplication::translate("CreateZone", "Z mini", 0, QApplication::UnicodeUTF8));
        TLXmaxi->setText(QApplication::translate("CreateZone", "X maxi", 0, QApplication::UnicodeUTF8));
        TLZmaxi->setText(QApplication::translate("CreateZone", "Z maxi", 0, QApplication::UnicodeUTF8));
        TLYmaxi->setText(QApplication::translate("CreateZone", "Y maxi", 0, QApplication::UnicodeUTF8));
        gBSphere->setTitle(QApplication::translate("CreateZone", "Coordinates", 0, QApplication::UnicodeUTF8));
        TLXcentre->setText(QApplication::translate("CreateZone", "X centre", 0, QApplication::UnicodeUTF8));
        TLYcentre->setText(QApplication::translate("CreateZone", "Y centre", 0, QApplication::UnicodeUTF8));
        TLRayon->setText(QApplication::translate("CreateZone", "Radius", 0, QApplication::UnicodeUTF8));
        TLZcentre->setText(QApplication::translate("CreateZone", "Z centre", 0, QApplication::UnicodeUTF8));
        GBButtons->setTitle(QString());
        buttonOk->setText(QApplication::translate("CreateZone", "&Ok", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("CreateZone", "&Apply", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("CreateZone", "&Cancel", 0, QApplication::UnicodeUTF8));
        buttonHelp->setText(QApplication::translate("CreateZone", "&Help", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(CreateZone);
    } // retranslateUi

};

namespace Ui {
    class CreateZone: public Ui_CreateZone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATEZONE_H
