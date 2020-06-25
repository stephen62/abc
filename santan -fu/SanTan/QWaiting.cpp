#include "QWaiting.h"
#include "ui_QWaiting.h"
#include <QDesktopWidget>
#include <QPoint>

QWaiting::QWaiting(QWidget *parent)
	: QWidget(parent), ui(new Ui::QWaiting)
{
	ui->setupUi(this);
	move((parent->width() - this->width()) / 2, (parent->height() - this->height()) / 2);
	//setWindowModality(Qt::WindowModal);
	ui->labelText->setStyleSheet("color: #DDD");
}


QWaiting::~QWaiting()
{
	//m_Move->stop();
	delete ui;
}
