/********************************************************************************
** Form generated from reading UI file 'QWaiting.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWAITING_H
#define UI_QWAITING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWaiting
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *labelText;
    QHBoxLayout *hLayoutPic;
    QSpacerItem *hSpacerH1;
    QProgressBar *progressBar;
    QSpacerItem *hSpacerH2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *QWaiting)
    {
        if (QWaiting->objectName().isEmpty())
            QWaiting->setObjectName(QString::fromUtf8("QWaiting"));
        QWaiting->resize(879, 364);
        widget = new QWidget(QWaiting);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 10, 861, 341));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelText = new QLabel(widget);
        labelText->setObjectName(QString::fromUtf8("labelText"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        labelText->setFont(font);
        labelText->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelText);

        hLayoutPic = new QHBoxLayout();
        hLayoutPic->setObjectName(QString::fromUtf8("hLayoutPic"));
        hSpacerH1 = new QSpacerItem(37, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutPic->addItem(hSpacerH1);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setMinimumSize(QSize(300, 10));
        progressBar->setMaximumSize(QSize(300, 10));
        progressBar->setMinimum(0);
        progressBar->setMaximum(0);
        progressBar->setValue(-1);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        hLayoutPic->addWidget(progressBar);

        hSpacerH2 = new QSpacerItem(37, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutPic->addItem(hSpacerH2);


        verticalLayout->addLayout(hLayoutPic);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        retranslateUi(QWaiting);

        QMetaObject::connectSlotsByName(QWaiting);
    } // setupUi

    void retranslateUi(QWidget *QWaiting)
    {
        QWaiting->setWindowTitle(QCoreApplication::translate("QWaiting", "Form", nullptr));
        labelText->setText(QCoreApplication::translate("QWaiting", "\350\257\267\347\250\215\347\255\211...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWaiting: public Ui_QWaiting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWAITING_H
