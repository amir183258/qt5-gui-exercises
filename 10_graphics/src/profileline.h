#ifndef PROFILE_LINE_H
#define PROFILE_LINE_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPen>

class profileLine: public QGraphicsLineItem {
public:
	profileLine(QGraphicsItem* parent = nullptr);
	void initLine(QGraphicsItem* start, QGraphicsItem* end);
	void updateLine();

	QGraphicsItem* startBox;
	QGraphicsItem* endBox;
};

#endif
