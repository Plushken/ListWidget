#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sortleft_clicked();

    void on_movetoright_clicked();

    void on_movetoleft_clicked();

    void on_sortright_clicked();

    void on_lc_itemClicked();

    void on_rc_itemClicked();

private:
    Ui::MainWindow *ui;

    bool check_column(QListWidget* l);

    void select(QListWidget* l);

};
#endif // MAINWINDOW_H
