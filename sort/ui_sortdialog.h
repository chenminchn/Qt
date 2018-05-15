/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_sortDialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *primaryGroupBox;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QComboBox *primaryColumnCombo;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QComboBox *primaryOrderCombo;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;
    QPushButton *moreButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *primaryGroupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QComboBox *secondaryColumnCombo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_10;
    QComboBox *secondaryOrderCombo;
    QGroupBox *primaryGroupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QComboBox *tertiaryColumnCombo;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_12;
    QComboBox *tertiaryOrderCombo;

    void setupUi(QDialog *sortDialog)
    {
        if (sortDialog->objectName().isEmpty())
            sortDialog->setObjectName(QStringLiteral("sortDialog"));
        sortDialog->resize(295, 328);
        gridLayout_4 = new QGridLayout(sortDialog);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        primaryGroupBox = new QGroupBox(sortDialog);
        primaryGroupBox->setObjectName(QStringLiteral("primaryGroupBox"));
        gridLayout = new QGridLayout(primaryGroupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_7 = new QLabel(primaryGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        primaryColumnCombo = new QComboBox(primaryGroupBox);
        primaryColumnCombo->setObjectName(QStringLiteral("primaryColumnCombo"));

        gridLayout->addWidget(primaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_8 = new QLabel(primaryGroupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        primaryOrderCombo = new QComboBox(primaryGroupBox);
        primaryOrderCombo->setObjectName(QStringLiteral("primaryOrderCombo"));

        gridLayout->addWidget(primaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(primaryGroupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        okButton = new QPushButton(sortDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(sortDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        verticalSpacer = new QSpacerItem(77, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moreButton = new QPushButton(sortDialog);
        moreButton->setObjectName(QStringLiteral("moreButton"));
        moreButton->setCheckable(true);
        moreButton->setChecked(true);

        verticalLayout->addWidget(moreButton);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 47, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        primaryGroupBox_2 = new QGroupBox(sortDialog);
        primaryGroupBox_2->setObjectName(QStringLiteral("primaryGroupBox_2"));
        gridLayout_2 = new QGridLayout(primaryGroupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_9 = new QLabel(primaryGroupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        secondaryColumnCombo = new QComboBox(primaryGroupBox_2);
        secondaryColumnCombo->setObjectName(QStringLiteral("secondaryColumnCombo"));

        gridLayout_2->addWidget(secondaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_10 = new QLabel(primaryGroupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        secondaryOrderCombo = new QComboBox(primaryGroupBox_2);
        secondaryOrderCombo->setObjectName(QStringLiteral("secondaryOrderCombo"));

        gridLayout_2->addWidget(secondaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(primaryGroupBox_2, 2, 0, 1, 1);

        primaryGroupBox_3 = new QGroupBox(sortDialog);
        primaryGroupBox_3->setObjectName(QStringLiteral("primaryGroupBox_3"));
        gridLayout_3 = new QGridLayout(primaryGroupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_11 = new QLabel(primaryGroupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        tertiaryColumnCombo = new QComboBox(primaryGroupBox_3);
        tertiaryColumnCombo->setObjectName(QStringLiteral("tertiaryColumnCombo"));

        gridLayout_3->addWidget(tertiaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        label_12 = new QLabel(primaryGroupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 1, 0, 1, 1);

        tertiaryOrderCombo = new QComboBox(primaryGroupBox_3);
        tertiaryOrderCombo->setObjectName(QStringLiteral("tertiaryOrderCombo"));

        gridLayout_3->addWidget(tertiaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(primaryGroupBox_3, 3, 0, 1, 1);

        QWidget::setTabOrder(primaryColumnCombo, primaryOrderCombo);
        QWidget::setTabOrder(primaryOrderCombo, secondaryColumnCombo);
        QWidget::setTabOrder(secondaryColumnCombo, secondaryOrderCombo);
        QWidget::setTabOrder(secondaryOrderCombo, tertiaryColumnCombo);
        QWidget::setTabOrder(tertiaryColumnCombo, tertiaryOrderCombo);
        QWidget::setTabOrder(tertiaryOrderCombo, okButton);
        QWidget::setTabOrder(okButton, cancelButton);
        QWidget::setTabOrder(cancelButton, moreButton);

        retranslateUi(sortDialog);
        QObject::connect(okButton, SIGNAL(clicked()), sortDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), sortDialog, SLOT(reject()));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), primaryGroupBox_2, SLOT(setVisible(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), primaryGroupBox_3, SLOT(setVisible(bool)));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(sortDialog);
    } // setupUi

    void retranslateUi(QDialog *sortDialog)
    {
        sortDialog->setWindowTitle(QApplication::translate("sortDialog", "Sort Dialog", Q_NULLPTR));
        primaryGroupBox->setTitle(QApplication::translate("sortDialog", "&Primary Key", Q_NULLPTR));
        label_7->setText(QApplication::translate("sortDialog", "Column:", Q_NULLPTR));
        primaryColumnCombo->clear();
        primaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "None", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("sortDialog", "Order:", Q_NULLPTR));
        primaryOrderCombo->clear();
        primaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "Ascending", Q_NULLPTR)
         << QApplication::translate("sortDialog", "Dscending", Q_NULLPTR)
        );
        okButton->setText(QApplication::translate("sortDialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("sortDialog", "Cancel", Q_NULLPTR));
        moreButton->setText(QApplication::translate("sortDialog", "More", Q_NULLPTR));
        primaryGroupBox_2->setTitle(QApplication::translate("sortDialog", "&Secondary Key", Q_NULLPTR));
        label_9->setText(QApplication::translate("sortDialog", "Column:", Q_NULLPTR));
        secondaryColumnCombo->clear();
        secondaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "None", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("sortDialog", "Order:", Q_NULLPTR));
        secondaryOrderCombo->clear();
        secondaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "Ascending", Q_NULLPTR)
         << QApplication::translate("sortDialog", "Dscending", Q_NULLPTR)
        );
        primaryGroupBox_3->setTitle(QApplication::translate("sortDialog", "&Tertiary Key", Q_NULLPTR));
        label_11->setText(QApplication::translate("sortDialog", "Column:", Q_NULLPTR));
        tertiaryColumnCombo->clear();
        tertiaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "None", Q_NULLPTR)
        );
        label_12->setText(QApplication::translate("sortDialog", "Order:", Q_NULLPTR));
        tertiaryOrderCombo->clear();
        tertiaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "Ascending", Q_NULLPTR)
         << QApplication::translate("sortDialog", "Dscending", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class sortDialog: public Ui_sortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
