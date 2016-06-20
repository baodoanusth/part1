#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <QProcess>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QStringList>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
          "",
         QFileDialog::ShowDirsOnly
         | QFileDialog::DontResolveSymlinks);
    ui->DIR->setText(directory);
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->DIR->toPlainText();
    string cmd = "./list_all_videos.sh "+text.toStdString();
    system("chmod +x list_all_videos.sh");
    system(cmd.c_str());

    ifstream fin { "result.txt" };
    string s { istreambuf_iterator<char>(fin), istreambuf_iterator<char>() };
    QString str = s.c_str();
    ui->show_list->setText(str);

}

void MainWindow::on_pushButton_3_clicked()
{
    system("chmod +x sort_name.sh");
    system("./sort_name.sh");

    ifstream fin { "sort_result.txt" };
    string s { istreambuf_iterator<char>(fin), istreambuf_iterator<char>() };
    QString str = s.c_str();
    ui->show_list->setText(str);
}

void MainWindow::on_pushButton_4_clicked()
{
    system("chmod +x sort_size.sh");
    system("./sort_size.sh");

    ifstream fin { "sort_result.txt" };
    string s { istreambuf_iterator<char>(fin), istreambuf_iterator<char>() };
    QString str = s.c_str();
    ui->show_list->setText(str);
}

void MainWindow::on_pushButton_5_clicked()
{
    system("chmod +x sort_date.sh");
    system("./sort_date.sh");

    ifstream fin { "sort_result.txt" };
    string s { istreambuf_iterator<char>(fin), istreambuf_iterator<char>() };
    QString str = s.c_str();
    ui->show_list->setText(str);
}

void MainWindow::on_pushButton_6_clicked()
{
    system("chmod +x check_dub.sh");
    system("./check_dub.sh");

    ifstream fin { "check.txt" };
    string s { istreambuf_iterator<char>(fin), istreambuf_iterator<char>() };
    QString str = s.c_str();
    ui->show_list->setText(str);
}

void MainWindow::on_pushButton_7_clicked()
{
    QString key = ui->key->toPlainText();
    QString text = ui->DIR->toPlainText();
    string cmd = "./search_by_keyword.sh "+text.toStdString()+" "+key.toStdString();
    system("chmod +x search_by_keyword.sh");
    system(cmd.c_str());

    ifstream fin { "search_result.txt" };
    string s;
    QStringList all;
    int n =1;

    while(!fin.eof()){
    getline(fin,s);
    string toString = to_string(n);
    string convert = toString + ", " + s;
    n++;
    QString str = convert.c_str();
    all << str;
    }

    fin.close();
    ui->searchResult->setText(all.join("\n"));
}

void MainWindow::on_searchResult_anchorClicked()
{

}

void MainWindow::on_pushButton_8_clicked()
{
    QString videoNum = ui->videoNumber->toPlainText();
    int convert_to_int = stoi(videoNum.toStdString());

    ifstream fin { "search_result.txt" };
    string s;

    for(int i=0;i<convert_to_int-1;i++)
        getline(fin, s);

    getline(fin, s);
    string cmd = "xdg-open "+s;
    system(cmd.c_str());
}
