/********************************************************************************
** Form generated from reading UI file 'PursueIteration.ui'
**
** Created: Wed Jan 15 08:41:44 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PURSUEITERATION_H
#define PURSUEITERATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PursueIteration
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *hboxLayout;
    QLabel *Name;
    QLineEdit *LECaseName;
    QHBoxLayout *_2;
    QLabel *Directory;
    QPushButton *PushDir;
    QLineEdit *LEDirName;
    QRadioButton *RBIteration;
    QRadioButton *RBCase;
    QHBoxLayout *hboxLayout1;
    QLabel *DirectoryStart;
    QPushButton *PushDirStart;
    QLineEdit *LEDirNameStart;
    QGroupBox *GBIterationintoCase;
    QGridLayout *gridLayout;
    QRadioButton *RBCaseLastIteration;
    QRadioButton *RBCaseNIteration;
    QSpinBox *SpinBoxNumber;
    QGroupBox *GroupButtons;
    QGridLayout *gridLayout1;
    QPushButton *buttonHelp;
    QPushButton *buttonApply;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QSpacerItem *spacer_2;

    void setupUi(QDialog *PursueIteration)
    {
        if (PursueIteration->objectName().isEmpty())
            PursueIteration->setObjectName(QString::fromUtf8("PursueIteration"));
        PursueIteration->resize(601, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PursueIteration->sizePolicy().hasHeightForWidth());
        PursueIteration->setSizePolicy(sizePolicy);
        PursueIteration->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(PursueIteration);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Name = new QLabel(PursueIteration);
        Name->setObjectName(QString::fromUtf8("Name"));

        hboxLayout->addWidget(Name);

        LECaseName = new QLineEdit(PursueIteration);
        LECaseName->setObjectName(QString::fromUtf8("LECaseName"));
        LECaseName->setMinimumSize(QSize(382, 21));

        hboxLayout->addWidget(LECaseName);


        gridLayout_2->addLayout(hboxLayout, 0, 0, 1, 2);

        _2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _2->setSpacing(6);
#endif
        _2->setContentsMargins(0, 0, 0, 0);
        _2->setObjectName(QString::fromUtf8("_2"));
        Directory = new QLabel(PursueIteration);
        Directory->setObjectName(QString::fromUtf8("Directory"));

        _2->addWidget(Directory);

        PushDir = new QPushButton(PursueIteration);
        PushDir->setObjectName(QString::fromUtf8("PushDir"));
        PushDir->setAutoDefault(false);

        _2->addWidget(PushDir);

        LEDirName = new QLineEdit(PursueIteration);
        LEDirName->setObjectName(QString::fromUtf8("LEDirName"));
        LEDirName->setMinimumSize(QSize(382, 21));

        _2->addWidget(LEDirName);


        gridLayout_2->addLayout(_2, 1, 0, 1, 3);

        RBIteration = new QRadioButton(PursueIteration);
        RBIteration->setObjectName(QString::fromUtf8("RBIteration"));
        RBIteration->setChecked(true);

        gridLayout_2->addWidget(RBIteration, 2, 0, 1, 1);

        RBCase = new QRadioButton(PursueIteration);
        RBCase->setObjectName(QString::fromUtf8("RBCase"));

        gridLayout_2->addWidget(RBCase, 2, 1, 1, 1);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        DirectoryStart = new QLabel(PursueIteration);
        DirectoryStart->setObjectName(QString::fromUtf8("DirectoryStart"));

        hboxLayout1->addWidget(DirectoryStart);

        PushDirStart = new QPushButton(PursueIteration);
        PushDirStart->setObjectName(QString::fromUtf8("PushDirStart"));
        PushDirStart->setAutoDefault(false);

        hboxLayout1->addWidget(PushDirStart);

        LEDirNameStart = new QLineEdit(PursueIteration);
        LEDirNameStart->setObjectName(QString::fromUtf8("LEDirNameStart"));
        LEDirNameStart->setMinimumSize(QSize(382, 21));

        hboxLayout1->addWidget(LEDirNameStart);


        gridLayout_2->addLayout(hboxLayout1, 3, 0, 1, 3);

        GBIterationintoCase = new QGroupBox(PursueIteration);
        GBIterationintoCase->setObjectName(QString::fromUtf8("GBIterationintoCase"));
        gridLayout = new QGridLayout(GBIterationintoCase);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RBCaseLastIteration = new QRadioButton(GBIterationintoCase);
        RBCaseLastIteration->setObjectName(QString::fromUtf8("RBCaseLastIteration"));
        RBCaseLastIteration->setChecked(true);

        gridLayout->addWidget(RBCaseLastIteration, 0, 0, 1, 1);

        RBCaseNIteration = new QRadioButton(GBIterationintoCase);
        RBCaseNIteration->setObjectName(QString::fromUtf8("RBCaseNIteration"));

        gridLayout->addWidget(RBCaseNIteration, 1, 0, 1, 1);

        SpinBoxNumber = new QSpinBox(GBIterationintoCase);
        SpinBoxNumber->setObjectName(QString::fromUtf8("SpinBoxNumber"));
        SpinBoxNumber->setMaximum(1789);

        gridLayout->addWidget(SpinBoxNumber, 1, 1, 1, 1);


        gridLayout_2->addWidget(GBIterationintoCase, 4, 0, 1, 2);

        GroupButtons = new QGroupBox(PursueIteration);
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


        gridLayout_2->addWidget(GroupButtons, 5, 0, 1, 2);

        spacer_2 = new QSpacerItem(128, 25, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(spacer_2, 5, 2, 1, 1);


        retranslateUi(PursueIteration);

        QMetaObject::connectSlotsByName(PursueIteration);
    } // setupUi

    void retranslateUi(QDialog *PursueIteration)
    {
        PursueIteration->setWindowTitle(QApplication::translate("PursueIteration", "Pursue an iteration", 0));
        Name->setText(QApplication::translate("PursueIteration", "Name", 0));
        Directory->setText(QApplication::translate("PursueIteration", "Directory", 0));
        PushDir->setText(QString());
        RBIteration->setText(QApplication::translate("PursueIteration", "From an iteration", 0));
        RBCase->setText(QApplication::translate("PursueIteration", "From a case", 0));
        DirectoryStart->setText(QApplication::translate("PursueIteration", "Directory", 0));
        PushDirStart->setText(QString());
        GBIterationintoCase->setTitle(QApplication::translate("PursueIteration", "Iteration into the case"));
        RBCaseLastIteration->setText(QApplication::translate("PursueIteration", "Last iteration", 0));
        RBCaseNIteration->setText(QApplication::translate("PursueIteration", "Iteration number", 0));
        GroupButtons->setTitle(QString());
        buttonHelp->setText(QApplication::translate("PursueIteration", "Help", 0));
        buttonApply->setText(QApplication::translate("PursueIteration", "Apply", 0));
        buttonOk->setText(QApplication::translate("PursueIteration", "OK", 0));
        buttonCancel->setText(QApplication::translate("PursueIteration", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class PursueIteration: public Ui_PursueIteration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PURSUEITERATION_H
