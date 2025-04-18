#include "maingame.h"
#include "./ui_maingame.h"
#include <QKeyEvent>

MainGame::MainGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainGame)
{
    ui->setupUi(this);
}

MainGame::~MainGame()
{
    delete ui;
}

//按下开始键
void MainGame::on_pushButton_clicked()
{
    UIRestart();
}

void MainGame::UIRestart(){
    Game.RstGame();
    UpdateUI();
    ui->pushButton->setText("Restart(R)");
    ui->label_Tips->setText("Press W,A,S,D to move!");
}

//更新UI
void MainGame::UpdateUI() {
    const auto& grid = Game.Getgrid();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            QLabel *label = static_cast<QLabel*>(
                ui->gridLayout->itemAtPosition(i, j)->widget()
            );
            int value = grid[i][j];
            label->setText(value > 0 ? QString::number(value) : "");
        }
    }
    ui->ScoreNum->setText(QString::number(Game.GetScore()));
}

void MainGame::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_A: Game.MoveLeft(); break;
        case Qt::Key_D: Game.MoveRight(); break;
        case Qt::Key_W: Game.MoveUp(); break;
        case Qt::Key_S: Game.MoveDown(); break;
        case Qt::Key_R: UIRestart(); break;
        default: QMainWindow::keyPressEvent(event); 
        return;
    }
    UpdateUI();
    if (Game.IsGameOver()) {
        ui->pushButton->setText("Start!");
        ui->label_Tips->setText("Game Over!");
    }
}
