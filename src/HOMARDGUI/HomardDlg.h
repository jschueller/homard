/********************************************************************************
** Form generated from reading ui file 'HomardDlg.ui'
**
** Created: Fri Jan 16 19:12:09 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef HOMARDDLG_H
#define HOMARDDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomardDlg
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *ListeMeshName;
    QPushButton *PushFichier;
    QLineEdit *NomFichier;
    QGroupBox *groupBox_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QCheckBox *NbEntites;
    QSpacerItem *verticalSpacer;
    QCheckBox *Volumes;
    QSpacerItem *horizontalSpacer;
    QCheckBox *Inter;
    QCheckBox *Qualite;
    QCheckBox *Connexite;
    QGroupBox *groupBox_2;
    QCheckBox *Histo;
    QCheckBox *Bilan;
    QGroupBox *groupBox_4;
    QPushButton *lancement;
    QPushButton *terminer;

    void setupUi(QWidget *HomardDlg)
    {
    if (HomardDlg->objectName().isEmpty())
        HomardDlg->setObjectName(QString::fromUtf8("HomardDlg"));
    HomardDlg->resize(632, 372);
    groupBox = new QGroupBox(HomardDlg);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 0, 614, 131));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(20, 20, 57, 17));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(20, 90, 57, 17));
    ListeMeshName = new QComboBox(groupBox);
    ListeMeshName->setObjectName(QString::fromUtf8("ListeMeshName"));
    ListeMeshName->setGeometry(QRect(100, 70, 501, 41));
    PushFichier = new QPushButton(groupBox);
    PushFichier->setObjectName(QString::fromUtf8("PushFichier"));
    PushFichier->setGeometry(QRect(100, 20, 51, 31));
    NomFichier = new QLineEdit(groupBox);
    NomFichier->setObjectName(QString::fromUtf8("NomFichier"));
    NomFichier->setGeometry(QRect(170, 10, 431, 51));
    groupBox_3 = new QGroupBox(HomardDlg);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 140, 614, 78));
    widget = new QWidget(groupBox_3);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(21, 10, 445, 92));
    gridLayout = new QGridLayout(widget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    NbEntites = new QCheckBox(widget);
    NbEntites->setObjectName(QString::fromUtf8("NbEntites"));
    NbEntites->setChecked(true);

    gridLayout->addWidget(NbEntites, 0, 0, 3, 2);

    verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer, 0, 2, 4, 1);

    Volumes = new QCheckBox(widget);
    Volumes->setObjectName(QString::fromUtf8("Volumes"));
    Volumes->setChecked(true);

    gridLayout->addWidget(Volumes, 0, 3, 2, 1);

    horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer, 1, 1, 2, 1);

    Inter = new QCheckBox(widget);
    Inter->setObjectName(QString::fromUtf8("Inter"));
    Inter->setChecked(false);

    gridLayout->addWidget(Inter, 2, 3, 2, 1);

    Qualite = new QCheckBox(widget);
    Qualite->setObjectName(QString::fromUtf8("Qualite"));
    Qualite->setChecked(true);

    gridLayout->addWidget(Qualite, 3, 0, 1, 2);

    Connexite = new QCheckBox(widget);
    Connexite->setObjectName(QString::fromUtf8("Connexite"));
    Connexite->setChecked(true);

    gridLayout->addWidget(Connexite, 4, 0, 1, 2);

    groupBox_2 = new QGroupBox(HomardDlg);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(10, 220, 614, 78));
    Histo = new QCheckBox(groupBox_2);
    Histo->setObjectName(QString::fromUtf8("Histo"));
    Histo->setGeometry(QRect(330, 30, 171, 22));
    Histo->setChecked(true);
    Bilan = new QCheckBox(groupBox_2);
    Bilan->setObjectName(QString::fromUtf8("Bilan"));
    Bilan->setGeometry(QRect(10, 30, 171, 22));
    Bilan->setChecked(true);
    groupBox_4 = new QGroupBox(HomardDlg);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(10, 310, 614, 51));
    lancement = new QPushButton(groupBox_4);
    lancement->setObjectName(QString::fromUtf8("lancement"));
    lancement->setGeometry(QRect(430, 10, 83, 31));
    terminer = new QPushButton(groupBox_4);
    terminer->setObjectName(QString::fromUtf8("terminer"));
    terminer->setGeometry(QRect(520, 10, 83, 31));

    retranslateUi(HomardDlg);

    QMetaObject::connectSlotsByName(HomardDlg);
    } // setupUi

    void retranslateUi(QWidget *HomardDlg)
    {
    HomardDlg->setWindowTitle(QApplication::translate("HomardDlg", "Homard : Analyse de maillage", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QString());
    label->setText(QApplication::translate("HomardDlg", "MED File", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("HomardDlg", "Mesh", 0, QApplication::UnicodeUTF8));
    PushFichier->setText(QApplication::translate("HomardDlg", "Icon", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("HomardDlg", "Options", 0, QApplication::UnicodeUTF8));
    NbEntites->setText(QApplication::translate("HomardDlg", "Nombre d'entit\303\251s", 0, QApplication::UnicodeUTF8));
    Volumes->setText(QApplication::translate("HomardDlg", "Volumes/Surfaces/Longueurs", 0, QApplication::UnicodeUTF8));
    Inter->setText(QApplication::translate("HomardDlg", "Interp\303\251n\303\251tration", 0, QApplication::UnicodeUTF8));
    Qualite->setText(QApplication::translate("HomardDlg", "Qualit\303\251", 0, QApplication::UnicodeUTF8));
    Connexite->setText(QApplication::translate("HomardDlg", "Connexit\303\251", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("HomardDlg", "Conservation des r\303\251sultats", 0, QApplication::UnicodeUTF8));
    Histo->setText(QApplication::translate("HomardDlg", "Histogramme Qualit\303\251", 0, QApplication::UnicodeUTF8));
    Bilan->setText(QApplication::translate("HomardDlg", "Bilan", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QString());
    lancement->setText(QApplication::translate("HomardDlg", "Ok", 0, QApplication::UnicodeUTF8));
    terminer->setText(QApplication::translate("HomardDlg", "Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(HomardDlg);
    } // retranslateUi

};

namespace Ui {
    class HomardDlg: public Ui_HomardDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // HOMARDDLG_H
