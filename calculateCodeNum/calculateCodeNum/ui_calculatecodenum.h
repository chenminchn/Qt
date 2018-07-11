/********************************************************************************
** Form generated from reading UI file 'calculatecodenum.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATECODENUM_H
#define UI_CALCULATECODENUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_calculateCodeNumClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *calculateCodeNumClass)
    {
        if (calculateCodeNumClass->objectName().isEmpty())
            calculateCodeNumClass->setObjectName(QStringLiteral("calculateCodeNumClass"));
        calculateCodeNumClass->resize(875, 711);
        QFont font;
        font.setPointSize(10);
        calculateCodeNumClass->setFont(font);
        verticalLayout = new QVBoxLayout(calculateCodeNumClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(calculateCodeNumClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(calculateCodeNumClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(calculateCodeNumClass);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(calculateCodeNumClass);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        label_3 = new QLabel(calculateCodeNumClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(40, 20));

        horizontalLayout_2->addWidget(label_3);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(calculateCodeNumClass);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        label_4 = new QLabel(calculateCodeNumClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(40, 20));

        horizontalLayout_3->addWidget(label_4);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(calculateCodeNumClass);

        QMetaObject::connectSlotsByName(calculateCodeNumClass);
    } // setupUi

    void retranslateUi(QDialog *calculateCodeNumClass)
    {
        calculateCodeNumClass->setWindowTitle(QApplication::translate("calculateCodeNumClass", "calculateCodeNum", Q_NULLPTR));
        pushButton->setText(QApplication::translate("calculateCodeNumClass", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("calculateCodeNumClass", "\346\270\205\347\220\206", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("calculateCodeNumClass", "\346\227\240\346\225\210\350\241\214\346\225\260", Q_NULLPTR));
        ___qtreewidgetitem->setText(2, QApplication::translate("calculateCodeNumClass", "\346\234\211\346\225\210\350\241\214\346\225\260", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("calculateCodeNumClass", "\346\200\273\350\241\214\346\225\260", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("calculateCodeNumClass", "\346\226\207\344\273\266\345\220\215", Q_NULLPTR));
        label->setText(QApplication::translate("calculateCodeNumClass", "\346\200\273\350\241\214\346\225\260\357\274\232", Q_NULLPTR));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("calculateCodeNumClass", "\346\200\273\346\234\211\346\225\210\350\241\214\346\225\260\357\274\232", Q_NULLPTR));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class calculateCodeNumClass: public Ui_calculateCodeNumClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATECODENUM_H
