/********************************************************************************
** Form generated from reading UI file 'gotocelldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOCELLDIALOG_H
#define UI_GOTOCELLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_goToCellDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *goToCellDialog)
    {
        if (goToCellDialog->objectName().isEmpty())
            goToCellDialog->setObjectName(QStringLiteral("goToCellDialog"));
        goToCellDialog->resize(287, 80);
        QFont font;
        font.setPointSize(11);
        goToCellDialog->setFont(font);
        verticalLayout = new QVBoxLayout(goToCellDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(goToCellDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(goToCellDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okButton = new QPushButton(goToCellDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setEnabled(false);

        horizontalLayout_2->addWidget(okButton);

        cancelButton = new QPushButton(goToCellDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEdit, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(goToCellDialog);

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(goToCellDialog);
    } // setupUi

    void retranslateUi(QDialog *goToCellDialog)
    {
        goToCellDialog->setWindowTitle(QApplication::translate("goToCellDialog", "Go To Cell", Q_NULLPTR));
        label->setText(QApplication::translate("goToCellDialog", "&Cell Location:", Q_NULLPTR));
        okButton->setText(QApplication::translate("goToCellDialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("goToCellDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class goToCellDialog: public Ui_goToCellDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOCELLDIALOG_H
