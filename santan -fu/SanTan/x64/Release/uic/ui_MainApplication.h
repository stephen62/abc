/********************************************************************************
** Form generated from reading UI file 'MainApplication.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINAPPLICATION_H
#define UI_MAINAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainApplication
{
public:
    QAction *actionJHK;
    QAction *actiondd;
    QAction *action;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QPushButton *m_change_btn;
    QPushButton *init_btn;
    QPushButton *m_compare_btn;
    QPushButton *m_output_btn;
    QCheckBox *m_ddr_box;
    QCheckBox *m_xray_box;
    QLabel *label_9;
    QLineEdit *opacity_text;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_6;
    QVTKWidget *qvtkWidget;
    QVTKWidget *qvtkWidget_2;
    QFrame *frame_4;
    QGridLayout *gridLayout;
    QFrame *frame_11;
    QGridLayout *gridLayout_2;
    QFrame *frame_12;
    QGridLayout *gridLayout_8;
    QLabel *label_12;
    QLineEdit *xt_label;
    QLineEdit *yt_label;
    QLineEdit *zt_label;
    QLabel *label_20;
    QLineEdit *dx_label;
    QLineEdit *dy_label;
    QLabel *label_22;
    QLineEdit *sx_label;
    QLineEdit *sy_label;
    QLineEdit *sz_label;
    QLabel *label_17;
    QLineEdit *sid_label;
    QLabel *label_24;
    QLineEdit *threshold_label;
    QFrame *frame_5;
    QGridLayout *gridLayout_5;
    QLabel *m_scale_label;
    QFrame *frame_10;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QFrame *frame_7;
    QGridLayout *gridLayout_6;
    QLabel *label_8;
    QLabel *label_5;
    QLineEdit *xr_label;
    QLabel *label_6;
    QLineEdit *yr_label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QLineEdit *zr_label;
    QFrame *frame_2;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_32;
    QLineEdit *lineEdit_31;
    QLineEdit *lineEdit_33;
    QLineEdit *lineEdit_30;
    QLineEdit *lineEdit_03;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_02;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_23;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_22;
    QLineEdit *lineEdit_01;
    QLineEdit *lineEdit_00;
    QFrame *frame_6;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *xp_label;
    QLabel *label_3;
    QLineEdit *yp_label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLineEdit *zp_label;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;

    void setupUi(QMainWindow *MainApplication)
    {
        if (MainApplication->objectName().isEmpty())
            MainApplication->setObjectName(QString::fromUtf8("MainApplication"));
        MainApplication->resize(1500, 830);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainApplication->sizePolicy().hasHeightForWidth());
        MainApplication->setSizePolicy(sizePolicy);
        MainApplication->setMinimumSize(QSize(0, 800));
        MainApplication->setFocusPolicy(Qt::ClickFocus);
        actionJHK = new QAction(MainApplication);
        actionJHK->setObjectName(QString::fromUtf8("actionJHK"));
        actiondd = new QAction(MainApplication);
        actiondd->setObjectName(QString::fromUtf8("actiondd"));
        action = new QAction(MainApplication);
        action->setObjectName(QString::fromUtf8("action"));
        centralWidget = new QWidget(MainApplication);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(1021, 50));
        frame->setMaximumSize(QSize(16777215, 50));
        frame->setFocusPolicy(Qt::ClickFocus);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        m_change_btn = new QPushButton(frame);
        m_change_btn->setObjectName(QString::fromUtf8("m_change_btn"));
        m_change_btn->setGeometry(QRect(150, 10, 75, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_change_btn->sizePolicy().hasHeightForWidth());
        m_change_btn->setSizePolicy(sizePolicy1);
        m_change_btn->setMinimumSize(QSize(75, 30));
        m_change_btn->setMaximumSize(QSize(80, 16777215));
        init_btn = new QPushButton(frame);
        init_btn->setObjectName(QString::fromUtf8("init_btn"));
        init_btn->setGeometry(QRect(240, 10, 75, 30));
        init_btn->setMinimumSize(QSize(75, 30));
        m_compare_btn = new QPushButton(frame);
        m_compare_btn->setObjectName(QString::fromUtf8("m_compare_btn"));
        m_compare_btn->setGeometry(QRect(330, 10, 75, 30));
        m_compare_btn->setMinimumSize(QSize(75, 30));
        m_output_btn = new QPushButton(frame);
        m_output_btn->setObjectName(QString::fromUtf8("m_output_btn"));
        m_output_btn->setGeometry(QRect(420, 10, 75, 30));
        m_output_btn->setMinimumSize(QSize(75, 30));
        m_ddr_box = new QCheckBox(frame);
        m_ddr_box->setObjectName(QString::fromUtf8("m_ddr_box"));
        m_ddr_box->setGeometry(QRect(510, 15, 77, 19));
        sizePolicy1.setHeightForWidth(m_ddr_box->sizePolicy().hasHeightForWidth());
        m_ddr_box->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(11);
        m_ddr_box->setFont(font);
        m_ddr_box->setChecked(true);
        m_ddr_box->setTristate(false);
        m_xray_box = new QCheckBox(frame);
        m_xray_box->setObjectName(QString::fromUtf8("m_xray_box"));
        m_xray_box->setGeometry(QRect(600, 15, 91, 19));
        m_xray_box->setFont(font);
        m_xray_box->setChecked(true);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(700, 10, 99, 30));
        label_9->setMinimumSize(QSize(0, 30));
        label_9->setFont(font);
        opacity_text = new QLineEdit(frame);
        opacity_text->setObjectName(QString::fromUtf8("opacity_text"));
        opacity_text->setGeometry(QRect(810, 15, 40, 25));
        opacity_text->setMinimumSize(QSize(0, 25));
        opacity_text->setMaximumSize(QSize(40, 25));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(855, 20, 15, 17));
        label_11->setMaximumSize(QSize(15, 16777215));
        QFont font1;
        font1.setPointSize(13);
        label_11->setFont(font1);

        verticalLayout_2->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(571, 591));
        frame_3->setLayoutDirection(Qt::LeftToRight);
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        qvtkWidget = new QVTKWidget(frame_3);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setMinimumSize(QSize(571, 591));
        qvtkWidget->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(qvtkWidget);

        qvtkWidget_2 = new QVTKWidget(frame_3);
        qvtkWidget_2->setObjectName(QString::fromUtf8("qvtkWidget_2"));
        qvtkWidget_2->setMinimumSize(QSize(571, 591));
        qvtkWidget_2->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(qvtkWidget_2);

        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(330, 300));
        frame_4->setMaximumSize(QSize(330, 16777215));
        frame_4->setFocusPolicy(Qt::NoFocus);
        frame_4->setContextMenuPolicy(Qt::DefaultContextMenu);
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(0);
        gridLayout = new QGridLayout(frame_4);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_11 = new QFrame(frame_4);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setMinimumSize(QSize(310, 0));
        frame_11->setMaximumSize(QSize(310, 16777215));
        frame_11->setFrameShape(QFrame::NoFrame);
        frame_11->setFrameShadow(QFrame::Raised);
        frame_11->setLineWidth(0);
        gridLayout_2 = new QGridLayout(frame_11);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_12 = new QFrame(frame_11);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setMinimumSize(QSize(310, 250));
        frame_12->setMaximumSize(QSize(310, 16777215));
        frame_12->setFrameShape(QFrame::Box);
        frame_12->setFrameShadow(QFrame::Raised);
        frame_12->setLineWidth(2);
        gridLayout_8 = new QGridLayout(frame_12);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_12 = new QLabel(frame_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label_12->setFont(font2);

        gridLayout_8->addWidget(label_12, 0, 0, 1, 1);

        xt_label = new QLineEdit(frame_12);
        xt_label->setObjectName(QString::fromUtf8("xt_label"));
        xt_label->setEnabled(false);
        xt_label->setMinimumSize(QSize(0, 22));
        xt_label->setMaximumSize(QSize(60, 16777215));
        xt_label->setFocusPolicy(Qt::NoFocus);

        gridLayout_8->addWidget(xt_label, 0, 1, 1, 1);

        yt_label = new QLineEdit(frame_12);
        yt_label->setObjectName(QString::fromUtf8("yt_label"));
        yt_label->setEnabled(false);
        yt_label->setMinimumSize(QSize(0, 22));
        yt_label->setMaximumSize(QSize(60, 16777215));
        yt_label->setFocusPolicy(Qt::NoFocus);

        gridLayout_8->addWidget(yt_label, 0, 2, 1, 1);

        zt_label = new QLineEdit(frame_12);
        zt_label->setObjectName(QString::fromUtf8("zt_label"));
        zt_label->setEnabled(false);
        zt_label->setMinimumSize(QSize(0, 22));
        zt_label->setMaximumSize(QSize(60, 16777215));
        zt_label->setFocusPolicy(Qt::NoFocus);

        gridLayout_8->addWidget(zt_label, 0, 3, 1, 1);

        label_20 = new QLabel(frame_12);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font2);

        gridLayout_8->addWidget(label_20, 1, 0, 1, 1);

        dx_label = new QLineEdit(frame_12);
        dx_label->setObjectName(QString::fromUtf8("dx_label"));
        dx_label->setMaximumSize(QSize(70, 16777215));
        dx_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(dx_label, 1, 1, 1, 1);

        dy_label = new QLineEdit(frame_12);
        dy_label->setObjectName(QString::fromUtf8("dy_label"));
        dy_label->setMaximumSize(QSize(70, 16777215));
        dy_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(dy_label, 1, 2, 1, 2);

        label_22 = new QLabel(frame_12);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);

        gridLayout_8->addWidget(label_22, 2, 0, 1, 1);

        sx_label = new QLineEdit(frame_12);
        sx_label->setObjectName(QString::fromUtf8("sx_label"));
        sx_label->setEnabled(true);
        sx_label->setFocusPolicy(Qt::StrongFocus);
        sx_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(sx_label, 2, 1, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        sy_label = new QLineEdit(frame_12);
        sy_label->setObjectName(QString::fromUtf8("sy_label"));
        sy_label->setEnabled(true);
        sy_label->setFocusPolicy(Qt::StrongFocus);
        sy_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(sy_label, 2, 2, 1, 1);

        sz_label = new QLineEdit(frame_12);
        sz_label->setObjectName(QString::fromUtf8("sz_label"));
        sz_label->setEnabled(true);
        sz_label->setFocusPolicy(Qt::StrongFocus);
        sz_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(sz_label, 2, 3, 1, 1);

        label_17 = new QLabel(frame_12);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font2);

        gridLayout_8->addWidget(label_17, 3, 0, 1, 1);

        sid_label = new QLineEdit(frame_12);
        sid_label->setObjectName(QString::fromUtf8("sid_label"));

        gridLayout_8->addWidget(sid_label, 3, 1, 1, 1);

        label_24 = new QLabel(frame_12);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font2);

        gridLayout_8->addWidget(label_24, 3, 2, 1, 1);

        threshold_label = new QLineEdit(frame_12);
        threshold_label->setObjectName(QString::fromUtf8("threshold_label"));

        gridLayout_8->addWidget(threshold_label, 3, 3, 1, 1);


        gridLayout_2->addWidget(frame_12, 3, 0, 1, 2);

        frame_5 = new QFrame(frame_11);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMinimumSize(QSize(310, 150));
        frame_5->setMaximumSize(QSize(310, 16777215));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(2);
        gridLayout_5 = new QGridLayout(frame_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        m_scale_label = new QLabel(frame_5);
        m_scale_label->setObjectName(QString::fromUtf8("m_scale_label"));
        m_scale_label->setMinimumSize(QSize(0, 0));
        m_scale_label->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setWeight(50);
        m_scale_label->setFont(font3);
        m_scale_label->setTextFormat(Qt::AutoText);
        m_scale_label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(m_scale_label, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_5, 4, 0, 1, 2);

        frame_10 = new QFrame(frame_11);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setMinimumSize(QSize(0, 290));
        frame_10->setMaximumSize(QSize(16777215, 16777215));
        frame_10->setFrameShape(QFrame::Box);
        frame_10->setFrameShadow(QFrame::Raised);
        frame_10->setLineWidth(2);
        gridLayout_4 = new QGridLayout(frame_10);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_10 = new QLabel(frame_10);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 0));
        label_10->setMaximumSize(QSize(300, 30));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        label_10->setFont(font4);

        gridLayout_4->addWidget(label_10, 1, 0, 1, 2);

        frame_7 = new QFrame(frame_10);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        sizePolicy.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy);
        frame_7->setMinimumSize(QSize(155, 0));
        frame_7->setMaximumSize(QSize(150, 115));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_7);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_8 = new QLabel(frame_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(false);
        font5.setWeight(50);
        label_8->setFont(font5);

        gridLayout_6->addWidget(label_8, 0, 0, 1, 3);

        label_5 = new QLabel(frame_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_6->addWidget(label_5, 1, 0, 1, 1);

        xr_label = new QLineEdit(frame_7);
        xr_label->setObjectName(QString::fromUtf8("xr_label"));
        sizePolicy.setHeightForWidth(xr_label->sizePolicy().hasHeightForWidth());
        xr_label->setSizePolicy(sizePolicy);
        xr_label->setMaximumSize(QSize(60, 16777215));

        gridLayout_6->addWidget(xr_label, 1, 1, 1, 1);

        label_6 = new QLabel(frame_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 2, 0, 1, 1);

        yr_label = new QLineEdit(frame_7);
        yr_label->setObjectName(QString::fromUtf8("yr_label"));
        yr_label->setMaximumSize(QSize(60, 16777215));

        gridLayout_6->addWidget(yr_label, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(42, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 2, 2, 1, 1);

        label_7 = new QLabel(frame_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_6->addWidget(label_7, 3, 0, 1, 1);

        zr_label = new QLineEdit(frame_7);
        zr_label->setObjectName(QString::fromUtf8("zr_label"));
        zr_label->setMaximumSize(QSize(60, 16777215));

        gridLayout_6->addWidget(zr_label, 3, 1, 1, 1);


        gridLayout_4->addWidget(frame_7, 0, 1, 1, 1);

        frame_2 = new QFrame(frame_10);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        lineEdit_13 = new QLineEdit(frame_2);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setEnabled(false);
        lineEdit_13->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_13, 1, 3, 1, 1);

        lineEdit_32 = new QLineEdit(frame_2);
        lineEdit_32->setObjectName(QString::fromUtf8("lineEdit_32"));
        lineEdit_32->setEnabled(false);
        lineEdit_32->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_32, 3, 2, 1, 1);

        lineEdit_31 = new QLineEdit(frame_2);
        lineEdit_31->setObjectName(QString::fromUtf8("lineEdit_31"));
        lineEdit_31->setEnabled(false);
        lineEdit_31->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_31, 3, 1, 1, 1);

        lineEdit_33 = new QLineEdit(frame_2);
        lineEdit_33->setObjectName(QString::fromUtf8("lineEdit_33"));
        lineEdit_33->setEnabled(false);
        lineEdit_33->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_33, 3, 3, 1, 1);

        lineEdit_30 = new QLineEdit(frame_2);
        lineEdit_30->setObjectName(QString::fromUtf8("lineEdit_30"));
        lineEdit_30->setEnabled(false);
        lineEdit_30->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_30, 3, 0, 1, 1);

        lineEdit_03 = new QLineEdit(frame_2);
        lineEdit_03->setObjectName(QString::fromUtf8("lineEdit_03"));
        lineEdit_03->setEnabled(false);
        lineEdit_03->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_03, 0, 3, 1, 1);

        lineEdit_20 = new QLineEdit(frame_2);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setEnabled(false);
        lineEdit_20->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_20, 2, 0, 1, 1);

        lineEdit_02 = new QLineEdit(frame_2);
        lineEdit_02->setObjectName(QString::fromUtf8("lineEdit_02"));
        lineEdit_02->setEnabled(false);
        lineEdit_02->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_02, 0, 2, 1, 1);

        lineEdit_21 = new QLineEdit(frame_2);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));
        lineEdit_21->setEnabled(false);
        lineEdit_21->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_21, 2, 1, 1, 1);

        lineEdit_23 = new QLineEdit(frame_2);
        lineEdit_23->setObjectName(QString::fromUtf8("lineEdit_23"));
        lineEdit_23->setEnabled(false);
        lineEdit_23->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_23, 2, 3, 1, 1);

        lineEdit_12 = new QLineEdit(frame_2);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setEnabled(false);
        lineEdit_12->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_12, 1, 2, 1, 1);

        lineEdit_10 = new QLineEdit(frame_2);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setEnabled(false);
        lineEdit_10->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_10, 1, 0, 1, 1);

        lineEdit_11 = new QLineEdit(frame_2);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setEnabled(false);
        lineEdit_11->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_11, 1, 1, 1, 1);

        lineEdit_22 = new QLineEdit(frame_2);
        lineEdit_22->setObjectName(QString::fromUtf8("lineEdit_22"));
        lineEdit_22->setEnabled(false);
        lineEdit_22->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_22, 2, 2, 1, 1);

        lineEdit_01 = new QLineEdit(frame_2);
        lineEdit_01->setObjectName(QString::fromUtf8("lineEdit_01"));
        lineEdit_01->setEnabled(false);
        lineEdit_01->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_01, 0, 1, 1, 1);

        lineEdit_00 = new QLineEdit(frame_2);
        lineEdit_00->setObjectName(QString::fromUtf8("lineEdit_00"));
        lineEdit_00->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_00->sizePolicy().hasHeightForWidth());
        lineEdit_00->setSizePolicy(sizePolicy2);
        lineEdit_00->setFocusPolicy(Qt::NoFocus);

        gridLayout_7->addWidget(lineEdit_00, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame_2, 2, 0, 1, 2);

        frame_6 = new QFrame(frame_10);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMinimumSize(QSize(0, 105));
        frame_6->setMaximumSize(QSize(140, 110));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_6);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(39, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 0, 2, 2);

        label = new QLabel(frame_6);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 0));
        label->setFont(font5);

        gridLayout_3->addWidget(label, 0, 2, 1, 2);

        label_2 = new QLabel(frame_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(40, 0));
        label_2->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(label_2, 1, 1, 1, 1);

        xp_label = new QLineEdit(frame_6);
        xp_label->setObjectName(QString::fromUtf8("xp_label"));
        sizePolicy1.setHeightForWidth(xp_label->sizePolicy().hasHeightForWidth());
        xp_label->setSizePolicy(sizePolicy1);
        xp_label->setMinimumSize(QSize(45, 0));
        xp_label->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(xp_label, 1, 2, 1, 2);

        label_3 = new QLabel(frame_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(40, 0));
        label_3->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(label_3, 2, 1, 1, 1);

        yp_label = new QLineEdit(frame_6);
        yp_label->setObjectName(QString::fromUtf8("yp_label"));
        yp_label->setMinimumSize(QSize(45, 0));
        yp_label->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(yp_label, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        label_4 = new QLabel(frame_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(label_4, 3, 1, 1, 1);

        zp_label = new QLineEdit(frame_6);
        zp_label->setObjectName(QString::fromUtf8("zp_label"));
        zp_label->setMinimumSize(QSize(45, 0));
        zp_label->setMaximumSize(QSize(45, 16777215));

        gridLayout_3->addWidget(zp_label, 3, 2, 1, 2);


        gridLayout_4->addWidget(frame_6, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_10, 2, 0, 1, 2);


        gridLayout->addWidget(frame_11, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(frame_4);


        horizontalLayout->addWidget(frame_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        MainApplication->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainApplication);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1500, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuEdit->setFont(font);
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainApplication->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuFile->addAction(actionJHK);
        menuFile->addAction(actiondd);

        retranslateUi(MainApplication);

        QMetaObject::connectSlotsByName(MainApplication);
    } // setupUi

    void retranslateUi(QMainWindow *MainApplication)
    {
        MainApplication->setWindowTitle(QCoreApplication::translate("MainApplication", "SanTan", nullptr));
        actionJHK->setText(QCoreApplication::translate("MainApplication", "CT\345\275\261\345\203\217", nullptr));
        actiondd->setText(QCoreApplication::translate("MainApplication", "X \345\275\261\345\203\217", nullptr));
        action->setText(QCoreApplication::translate("MainApplication", "\346\257\224\350\276\203\345\214\272\345\237\237", nullptr));
        m_change_btn->setText(QCoreApplication::translate("MainApplication", "\345\210\207\346\215\242\346\230\276\347\244\272", nullptr));
        init_btn->setText(QCoreApplication::translate("MainApplication", "\350\277\230\345\216\237\345\217\202\346\225\260", nullptr));
        m_compare_btn->setText(QCoreApplication::translate("MainApplication", "\346\257\224\350\276\203\345\214\272\345\237\237", nullptr));
        m_output_btn->setText(QCoreApplication::translate("MainApplication", "\345\257\274\345\207\272\345\214\272\345\237\237", nullptr));
        m_ddr_box->setText(QCoreApplication::translate("MainApplication", "\346\230\276\347\244\272DRR", nullptr));
        m_xray_box->setText(QCoreApplication::translate("MainApplication", "\346\230\276\347\244\272X\345\275\261\345\203\217", nullptr));
        label_9->setText(QCoreApplication::translate("MainApplication", "DRR\345\233\276\351\200\217\346\230\216\345\215\240\346\257\224", nullptr));
        opacity_text->setText(QCoreApplication::translate("MainApplication", "50", nullptr));
        label_11->setText(QCoreApplication::translate("MainApplication", "%", nullptr));
        label_12->setText(QCoreApplication::translate("MainApplication", "\345\205\211\346\272\220\344\275\215\347\275\256", nullptr));
        xt_label->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        yt_label->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        zt_label->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        label_20->setText(QCoreApplication::translate("MainApplication", "\346\210\220\345\203\217\345\244\247\345\260\217", nullptr));
        dx_label->setText(QCoreApplication::translate("MainApplication", "1024", nullptr));
        dy_label->setText(QCoreApplication::translate("MainApplication", "1024", nullptr));
        label_22->setText(QCoreApplication::translate("MainApplication", "CT\346\225\260\346\215\256\351\227\264\350\267\235", nullptr));
        sx_label->setText(QCoreApplication::translate("MainApplication", " 0.3125", nullptr));
        sy_label->setText(QCoreApplication::translate("MainApplication", " 0.3125", nullptr));
        sz_label->setText(QCoreApplication::translate("MainApplication", "  1", nullptr));
        label_17->setText(QCoreApplication::translate("MainApplication", "\345\203\217\350\267\235\344\275\215\347\275\256", nullptr));
        sid_label->setText(QCoreApplication::translate("MainApplication", "400", nullptr));
        label_24->setText(QCoreApplication::translate("MainApplication", "\346\210\220\345\203\217\351\230\210\345\200\274", nullptr));
        threshold_label->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        m_scale_label->setText(QCoreApplication::translate("MainApplication", "<html><head/><body><p align=\"center\">          \346\234\252\350\277\233\350\241\214\351\205\215\345\207\206</p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainApplication", "         \345\257\271\345\272\224\347\232\204\345\217\230\345\214\226\347\237\251\351\230\265", nullptr));
        label_8->setText(QCoreApplication::translate("MainApplication", "  \346\227\213\350\275\254\345\272\246(\350\247\222\345\272\246)", nullptr));
        label_5->setText(QCoreApplication::translate("MainApplication", "X\350\275\264", nullptr));
        xr_label->setText(QCoreApplication::translate("MainApplication", "90", nullptr));
        label_6->setText(QCoreApplication::translate("MainApplication", "Y\350\275\264", nullptr));
        yr_label->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainApplication", "Z\350\275\264", nullptr));
        zr_label->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_32->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_31->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_33->setText(QCoreApplication::translate("MainApplication", "1", nullptr));
        lineEdit_30->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_03->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_20->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_02->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_21->setText(QCoreApplication::translate("MainApplication", "1", nullptr));
        lineEdit_23->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainApplication", "-1", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_22->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_01->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        lineEdit_00->setText(QCoreApplication::translate("MainApplication", "1", nullptr));
        label->setText(QCoreApplication::translate("MainApplication", "\345\203\217\347\264\240\345\271\263\347\247\273", nullptr));
        label_2->setText(QCoreApplication::translate("MainApplication", "X\345\203\217\347\264\240", nullptr));
        xp_label->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainApplication", "Y\345\203\217\347\264\240", nullptr));
        yp_label->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainApplication", "Z\345\203\217\347\264\240", nullptr));
        zp_label->setText(QCoreApplication::translate("MainApplication", "0", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainApplication", "    File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainApplication", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainApplication", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainApplication: public Ui_MainApplication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINAPPLICATION_H
