#ifndef PROFILE_BOX_H
#define PROFILE_BOX_H

#include <QGraphicsItemGroup>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "./mainwindow.h"

class MainWindow;

class profileBox: public QGraphicsItemGroup {
public:
	explicit profileBox(QGraphicsItem* parent = nullptr);

	void init(QString name, MainWindow *window,
			QGraphicsScene* scene);

	QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;

private:
	MainWindow* mainWindow;
	QGraphicsTextItem* nameTag;
};

#endif
