#ifndef MAINGAME_H
#define MAINGAME_H

#include <QMainWindow>
#include "2048demo.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainGame;
}
QT_END_NAMESPACE

class MainGame : public QMainWindow
{
    Q_OBJECT

public:
    MainGame(QWidget *parent = nullptr);
    ~MainGame();
    void UpdateUI(); 
protected:
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void on_pushButton_clicked();

private:
    Demo2048 Game;
    Ui::MainGame *ui;
    void UIRestart(); //重置UI
};
#endif // MAINGAME_H
