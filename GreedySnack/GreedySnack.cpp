#include "GreedySnack.h"
#include<QPixmap>
#include<QBrush>
#include<QPainter>
#include "GameController.h"

GreedySnack::GreedySnack(QWidget *parent)
	: QMainWindow(parent),\
	theScene(new QGraphicsScene{this}),\
	theView(new QGraphicsView{theScene,this})
{
	this->setCentralWidget(theView);
	this->resize(800, 600);
	this->init();
}

void GreedySnack::init()
{
	this->initGraph();//初始化view,scene
	game = new GameController{ theScene,this };//必须先初始化scene才能初始化
}

void GreedySnack::initGraph()
{
	//背景网格
	const int w{ 20 }, h{ 20 };
	QPixmap pixmap(w, h);
	QPainter painter{ &pixmap };
	painter.setBrush(QBrush{ Qt::gray });
	painter.drawRect(0, 0, w, h);
	//theScene->setBackgroundBrush(QBrush{ pixmap });
	theView->setBackgroundBrush(QBrush{ pixmap });//设置的是view的scene
}
