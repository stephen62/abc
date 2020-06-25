#ifndef QWAITING_H
#define QWAITING_H
#include <QWidget>
#include <qmovie.h>

namespace Ui {
	class QWaiting;
}

class QWaiting :
	public QWidget
{
	Q_OBJECT

private:
	Ui::QWaiting *ui;

public:
	explicit QWaiting(QWidget *parent = 0);
	~QWaiting();

};

#endif //QWAITING_H