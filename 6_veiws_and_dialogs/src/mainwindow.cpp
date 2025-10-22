#include <QDebug>
#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>

#include <QMessageBox>

#include <QFileDialog>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // list
    ui->listWidget->addItem("My Test Item");

    QListWidgetItem* listItem = new QListWidgetItem;
    listItem->setText("My Second Item");
    listItem->setData(100, 1000);
    ui->listWidget->addItem(listItem);

    qDebug() << listItem->data(100);

    // tree
    QTreeWidgetItem* treeItem = new QTreeWidgetItem;
    treeItem->setText(0, "My Test Item");
    ui->treeWidget->addTopLevelItem(treeItem);

    QTreeWidgetItem* treeItem2 = new QTreeWidgetItem;
    treeItem2->setText(0, "My Test Subitem");
    treeItem->addChild(treeItem2);
    
    // table
    QTableWidgetItem* tableItem = new QTableWidgetItem;
    tableItem->setText("Testing1");
    ui->tableWidget->setItem(0, 0, tableItem);

    QTableWidgetItem* tableItem2 = new QTableWidgetItem;
    tableItem2->setText("Testing2");
    ui->tableWidget->setItem(1, 2, tableItem2);

    // dialogs
    
    /*
    QMessageBox::information(this, "Alert", "Just to let you know, something happened!");
    QMessageBox::warning(this, "Alert", "Just to let you know, something happened!");
    QMessageBox::question(this, "Alert", "Just to let you know, something happened!");
    QMessageBox::critical(this, "Alert", "Just to let you know, something happened!");
    QMessageBox::about(this, "Alert", "Just to let you know, something happened!");
    */

    //QMessageBox::question(this, "Alert", "Just to let you know, something happened!", QMessageBox::Ignore, QMessageBox::Yes);
    
    /*
    QMessageBox msgBox;
    msgBox.setWindowTitle("Alert");
    msgBox.setText("Just to let you know, something happened!");
    msgBox.exec();
    */

    /*
    QMessageBox msgBox;
    msgBox.setWindowTitle("Serious Question");
    msgBox.setText("Am I an awesome guy?");
    msgBox.addButton("Seriously Yes!", QMessageBox::YesRole);
    msgBox.addButton("Well no thanks", QMessageBox::NoRole);
    msgBox.setIcon(QMessageBox::Question);
    msgBox.exec();
    */

    /*
    QMessageBox msgBox;
    msgBox.setWindowTitle("Serious Question");
    msgBox.setText("Am I an awsome guy?");
    msgBox.addButton("Seriously Yes!", QMessageBox::YesRole);
    msgBox.addButton("Well no thanks", QMessageBox::NoRole);
    QPixmap myIcon {":/img/icon.png"};
    msgBox.setIconPixmap(myIcon);
    msgBox.exec();
    */

    /*
    if (QMessageBox::question(this, "Question", "Some random question. Yes or no?") == QMessageBox::Yes)
	    QMessageBox::warning(this, "Yes", "You have pressed Yes!");
    else
	    QMessageBox::warning(this, "No", "You have pressed No!");
    */

    // file dialog

    /*
    QString fileName = QFileDialog::getOpenFileName(this);
    qDebug() << fileName;
    */

    QString fileName = QFileDialog::getOpenFileName(this, "Your title",
		    QDir::currentPath(), "All files (*.*) ;; Document files (*.doc *.rtf) ;; PNG files (*.png)");
    qDebug() << fileName;

    




}

MainWindow::~MainWindow()
{
    delete ui;
}

