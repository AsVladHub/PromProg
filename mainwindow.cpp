#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <math.h>
#include <QDebug>

#include <QPalette>

#include <QWidget>
#include <QKeyEvent>
#include <QPixmap>




double scale = 1;
int X1 = 0,X2 = 0;
int Y1 = 0,Y2 = 0;
 int FrCount = 0; //кадровка движений левакова
int RockCount = 0;//событие ракета
 int verh = 0;
 int vpravo = 0;
 bool najato = 0;
 double pi = 3.1415926;


 bool RockTime = 0; //начало обстрел ракетами
 bool RockGo = 0; //ракеты летят
 int RockGoX = 0;
 int RockGoY = 0;//вектора изменения координаты ракеты в полете
 int RockGoCount = 0; //кадровка ракеты

 int health = 100;
 int health_regen = 0;
 int levakov_health = 150;
 int mana_count = 0;
 int mana = 100;
 bool life = 1;

 bool body_dmg = 0;
 bool rocket_dmg = 0;
 bool fireboom = 0;
 int boomcount = 0;
 int boomX = 0;
 int boomY = 0;
 int immune = 0;


 bool vistrelGo = 0;
 int bullgox = 0;
 int bullgoy = 0;
 int bullgocount = 0;
 bool bull_dmg = 0;
 bool pricel_vis = 0;

 bool rock2 = 0;
 bool Rock2go = 0;
 int Rock2GoCount = 0;
 int Rock2GoX = 0;
 int Rock2GoY = 0;
 int boomX2 = 0;
 int boomY2 = 0;
 bool fireboom2 = 0;
 int boomcount2 = 0;
 bool rocket2_dmg = 0;

 bool fring = 0;
 bool fringgo = 0;
 int fringcount = 0;
 bool fringdmg = 0;
 bool levakstay = 0;
 bool fringfire = 0;
 int fringfirecount = 0;

 int achv = 0;
 bool achvgo = 0;
 int achvcount = 0;

 int achPrigogin = 0;
 int achKennedy = 0;
 int achOshib = 0;
 int achPromah = 0;
 int achFire = 0;
 int achVampire = 0;

 bool escbutton = 0;
 bool escbutton_off = 0;
 bool pausa = 1;

 bool vampire = 1;

 bool menu1on = 1;
 bool menu2on = 0;
 bool menu3on = 0;
 bool menu4on = 0;
 bool menu5on = 0;

 int iconnom = 1;
 int ability = 1;

 float tr1 = 1;
 float tr2 = 1;
 float tr3 = 0.1;
 float tr4 = 1;
 float tr5 = 1;
 float tr6 = 1;

 int fraze = 0;
 bool statsview = 0;

 int men1count = 300;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);


    ui->setupUi(this);



    m_player1 = new QMediaPlayer(this);
    audiooutput1 = new QAudioOutput(m_player1);
    m_player1->setAudioOutput(audiooutput1);

    m_player2 = new QMediaPlayer(this);
    audiooutput2 = new QAudioOutput(m_player2);
    m_player2->setAudioOutput(audiooutput2);

    m_player3 = new QMediaPlayer(this);
    audiooutput3 = new QAudioOutput(m_player3);
    m_player3->setAudioOutput(audiooutput3);

    m_player4 = new QMediaPlayer(this);
    audiooutput4 = new QAudioOutput(m_player4);
    m_player4->setAudioOutput(audiooutput4);

    m_player5 = new QMediaPlayer(this);
    audiooutput5 = new QAudioOutput(m_player5);
    m_player5->setAudioOutput(audiooutput5);

    audiooutput5->setVolume(tr5);


    m_player6 = new QMediaPlayer(this);
    audiooutput6 = new QAudioOutput(m_player6);
    m_player6->setAudioOutput(audiooutput6);
    m_player6->setSource(QUrl("qrc:/snd/menuOST.mp3"));
    audiooutput6->setVolume(tr6*0.1);


    m_player1->setSource(QUrl("qrc:/snd/menuSound.mp3"));
    audiooutput1->setVolume(tr1*0.5);





    setGeometry(0,0,4000,1000);
    MainWindow::showFullScreen();


    scale = (double)(width()) / 1400;
    ui->Fire1->setVisible(0);
    ui->Fire2->setVisible(0);
    ui->Fire3->setVisible(0);
    ui->Fire4->setVisible(0);
    ui->Fire5->setVisible(0);
    ui->Fire6->setVisible(0);
    ui->bullet->setVisible(0);
    ui->Rocket2->setVisible(0);
    ui->ring->setVisible(0);
    ui->pause_fon->setVisible(0);
    ui->menu2fone->setVisible(0);
    ui->menu2button->setVisible(0);
    ui->version->setVisible(0);


    ui->hp_levakov->setGeometry(width() - ui->hp_levakov->width(), 5, ui->hp_levakov->width(), ui->hp_levakov->height());
    ui->gray2->setGeometry(width() - ui->gray2->width(), 5, ui->gray2->width(), ui->gray2->height());
    ui->heart2->setGeometry(width() - ui->gray2->width() - ui->heart2->width() - 5, 3, ui->heart2->width(),ui->heart2->height());
    ui->rocket_timer->setGeometry(width() - ui->rocket_timer->width(),ui->rocket_timer->y(), ui->rocket_timer->width(), ui->rocket_timer->height());
    ui->ring->setGeometry(1,1, ui->Levakov->width() * 4, ui->Levakov->height() * 4);
    ui->menu1fone->setGeometry(0,0,width(), height());
    ui->menu1text->setGeometry(width()/2 - ui->menu1text->width()/2, height()/2 - ui->menu1text->height()/2, ui->menu1text->width(), ui->menu1text->height());
    ui->wintext->setGeometry(width()/2 - ui->wintext->width()/2, height()/2 - ui->wintext->height()/2, ui->wintext->width(), ui->wintext->height());
    ui->loosetext->setGeometry(width()/2 - ui->loosetext->width()/2, height()/2 - ui->loosetext->height()/2, ui->loosetext->width(), ui->loosetext->height() );

    ui->pricel->setGeometry(0,0,width(),height());
    ui->mainfon->setGeometry(0,0, width(), height());
    ui->pricel->setVisible(0);

    ui->achfone->setVisible(0);
    ui->achfoto->setVisible(0);
    ui->achtext->setVisible(0);
    ui->achtext2->setVisible(0);

    ui->continuebutton->setVisible(0);

    ui->menubutton->setVisible(0);
    ui->continuebutton->setEnabled(0);

    ui->menubutton->setEnabled(0);
    ui->pausetext->setVisible(0);
    ui->apenko->setVisible(0);
    ui->testers->setVisible(0);
    ui->apenkofone->setVisible(0);
    ui->apenkicon->setVisible(0);
    ui->paraxicon->setVisible(0);
    ui->iconfon1->setVisible(0);
    ui->iconfon2->setVisible(0);
    ui->vadimicon->setVisible(0);
    ui->iconfon3->setVisible(0);
    ui->booster->setVisible(0);
    ui->danikicon->setVisible(0);
    ui->authoricon->setVisible(0);
    ui->iconfon4->setVisible(0);
    ui->exitbutton->setVisible(0);
    ui->bossicon->setVisible(0);
    ui->playericon->setVisible(0);
    ui->speedicon->setVisible(0);
    ui->healthicon->setVisible(0);
    ui->manaicon->setVisible(0);
    ui->vampireicon->setVisible(0);
    ui->gamego->setVisible(0);
    ui->menu3fone->setVisible(0);
    ui->ukaz->setVisible(0);
    ui->ukaz2->setVisible(0);
    ui->playericonfone->setVisible(0);
    ui->vers->setVisible(0);
    ui->buff->setVisible(0);
    ui->buff2->setVisible(0);
    ui->leftarrow->setVisible(0);
    ui->rightarrow->setVisible(0);
    ui->nameg1->setVisible(0);
    ui->nameg2->setVisible(0);
    ui->nameg3->setVisible(0);
    ui->statsfone->setVisible(0);
    ui->staticon->setVisible(0);
    ui->stattext->setVisible(0);
    ui->stattext2->setVisible(0);
    ui->stattext3->setVisible(0);
    ui->stattext4->setVisible(0);
    ui->stattext5->setVisible(0);
    ui->loosetext->setVisible(0);
    ui->wintext->setVisible(0);

    ui->me->setPixmap(QPixmap(":/fts/ic1.png"));
    ui->achfone->setPixmap(QPixmap(":/fts/ach.png"));
    ui->bullet->setPixmap(QPixmap(":/fts/bullet.png"));
    ui->Fire1->setPixmap(QPixmap(":/fts/Fire1.png"));
    ui->Fire2->setPixmap(QPixmap(":/fts/Fire2.png"));
    ui->Fire3->setPixmap(QPixmap(":/fts/Fire3.png"));
    ui->Fire4->setPixmap(QPixmap(":/fts/Fire4.png"));
    ui->Fire5->setPixmap(QPixmap(":/fts/Fire1.png"));
    ui->Fire6->setPixmap(QPixmap(":/fts/Fire2.png"));
    ui->gray->setPixmap(QPixmap(":/fts/grey.png"));
    ui->gray2->setPixmap(QPixmap(":/fts/grey.png"));
    ui->heart->setPixmap(QPixmap(":/fts/heart.png"));
    ui->heart2->setPixmap(QPixmap(":/fts/heart2.png"));
    ui->hp->setPixmap(QPixmap(":/fts/red.png"));
    ui->hp_levakov->setPixmap(QPixmap(":/fts/purple.png"));
    ui->levakovfone->setPixmap(QPixmap(":/fts/pink.png"));
    ui->Mana->setPixmap(QPixmap(":/fts/blue.png"));
    ui->mefone->setPixmap(QPixmap(":/fts/green.png"));
    ui->pricel->setPixmap(QPixmap(":/fts/scop.png"));
    ui->ring->setPixmap(QPixmap(":/fts/Firering.png"));
    ui->rocket_timer->setPixmap(QPixmap(":/fts/Orange.png"));
    ui->ufo->setPixmap(QPixmap(":/fts/ufo.png"));
    ui->scope->setPixmap(QPixmap(":/fts/krug.png"));
    ui->mainfon->setPixmap(QPixmap(":/fts/gamefon.png"));
    ui->pause_fon->setPixmap(QPixmap(":/fts/pausefon.png"));
    ui->menu2fone->setPixmap(QPixmap(":/fts/menu2.png"));
    ui->apenkicon->setPixmap(QPixmap(":/fts/apenkoicon.png"));
    ui->paraxicon->setPixmap(QPixmap(":/fts/paraxialicon.png"));
    ui->authoricon->setPixmap(QPixmap(":/fts/firefox.png"));
    ui->iconfon1->setPixmap(QPixmap(":/fts/green.png"));
    ui->iconfon2->setPixmap(QPixmap(":/fts/green.png"));
    ui->iconfon3->setPixmap(QPixmap(":/fts/green.png"));
    ui->vadimicon->setPixmap(QPixmap(":/fts/vadimicon.png"));
    ui->danikicon->setPixmap(QPixmap(":/fts/danik.png"));
    ui->iconfon4->setPixmap(QPixmap(":/fts/green.png"));
    ui->bossicon->setPixmap(QPixmap(":/fts/bossfoto.png"));
    ui->playericon->setPixmap(QPixmap(":/fts/ic1.png"));
    ui->speedicon->setPixmap(QPixmap(":/fts/sprint.png"));
    ui->healthicon->setPixmap(QPixmap(":/fts/healing.png"));
    ui->manaicon->setPixmap(QPixmap(":/fts/energy.png"));
    ui->vampireicon->setPixmap(QPixmap(":/fts/vampirskill.png"));
    ui->ukaz->setPixmap(QPixmap(":/fts/blacktriangle1.png"));
    ui->ukaz2->setPixmap(QPixmap(":/fts/blacktriangle1.png"));
    ui->menu3fone->setPixmap(QPixmap(":/fts/menu3.png"));
    ui->playericonfone->setPixmap(QPixmap(":/fts/green.png"));
    ui->vers->setPixmap(QPixmap(":/fts/versus.png"));
    ui->leftarrow->setPixmap(QPixmap(":/fts/blacktriangle3.png"));
    ui->rightarrow->setPixmap(QPixmap(":/fts/blacktriangle2.png"));
    ui->playerability->setPixmap(QPixmap(":/fts/sprint.png"));
    ui->levakability->setPixmap(QPixmap(":/fts/vampirskill.png"));
    ui->statsfone->setPixmap(QPixmap(":/fts/stats.png"));
    ui->menu1fone->setPixmap(QPixmap(":/fts/black.png"));



    ui->continuebutton->setIcon(QIcon(QPixmap(":/fts/Continue.png")));
    ui->menubutton->setIcon(QIcon(QPixmap(":/fts/pausemenu.png")));
    ui->exitbutton->setIcon((QIcon(QPixmap(":/fts/cross.png"))));
    ui->gamego->setIcon(QIcon(QPixmap(":/fts/greentriang.png")));
    ui->menu2button->setIcon(QIcon(QPixmap(":/fts/greentriang.png")));

     menu4on = 1; //убрать
}

MainWindow::~MainWindow()
{
    delete ui;
}

//обработка нажатий клавиш
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {

    }
    if(!pausa)
    {
    if(event->key() == Qt::Key_W)
    {
        ++verh; najato = 1;
    }

    if(event->key() == Qt::Key_A)
    {
        --vpravo; najato = 1;
    }

    if(event->key() == Qt::Key_S)
    {
        --verh; najato = 1;
    }

    if(event->key() == Qt::Key_D)
    {
        ++vpravo; najato = 1;
    }


    }
    if(event->key() == Qt::Key_Escape && !escbutton &&!pausa && menu4on)
    {
        escbutton = 1; pausa = 1; verh = 0; vpravo=0;
    }
    else
    {


    if(event->key() == Qt::Key_Escape && !escbutton && pausa && menu4on)
    {
        escbutton_off = 1; pausa = 0;

    }
    }
}

//обработка отжатий клавилш
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(!pausa)
    {

    if(event->key() == Qt::Key_W)
    {
        --verh; if(verh<-1) verh = -1;
    }
    if(event->key() == Qt::Key_A)
    {
        ++vpravo; if(vpravo>1) vpravo = 1;
    }
    if(event->key() == Qt::Key_S)
    {
        ++verh; if(verh>1) verh = 1;
    }
    if(event->key() == Qt::Key_D)
    {
        --vpravo; if(vpravo<-1) vpravo = -1;
    }
    }
}



//прицеливание и выстрел
void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if(!pausa)
    {

    if(event->button() == Qt::RightButton && !fireboom && !fireboom2)
    {
        if(!pricel_vis){ui->pricel->setVisible(1); pricel_vis = 1;}
        else {ui->pricel->setVisible(0); pricel_vis = 0;}
    }


    if(event->button() == Qt::LeftButton && mana == 100 && !fireboom&&!fireboom2 &&!vistrelGo && pricel_vis)
    {
        ui->bullet->setVisible(1);
        ui->pricel->setVisible(0);
        pricel_vis = 0;

        mana = 0;
        ui->bullet->setGeometry(ui->me->x(), ui->me->y(), ui->bullet->width(), ui->bullet->height());


        X1 = ui->scope->x();
        Y1 = ui->scope->y();
        X2 = ui->bullet->x();
        Y2 = ui->bullet->y();


        double mx = (double)X1;
        double my = (double)Y1;
        double lx = (double)X2;
        double ly = (double)Y2;

        double dx = sqrt((lx-mx)*(lx-mx)) / sqrt((lx-mx)*(lx-mx) + (ly-my)*(ly-my)) * 15 ;

        double dy = sqrt((ly-my)*(ly-my)) / sqrt((lx-mx)*(lx-mx) + (ly-my)*(ly-my)) * 15 ;





        if(lx - mx<=1 && lx-mx>=-1 && ly-my<=1 && ly - my >=-1) { dx = 0; dy = 0;}

        if(lx>=mx) dx*=-1;
        if(ly>=my) dy*=-1;

        bullgox = (int) dx;
        bullgoy = (int) dy;
        vistrelGo = 1;

        m_player2->setSource(QUrl("qrc:/snd/sfxShot.mp3"));
        audiooutput2->setVolume(tr2*0.2);
        m_player2->play();

    }
    if(event->button() == Qt::LeftButton && mana<100 &&!fireboom &&!fireboom2&&!achPrigogin && pricel_vis)
    {
        achPrigogin = 1; ++achv;
        ui->pricel->setVisible(0);
        pricel_vis = 0;
    }

    }

    if(menu2on && statsview)
    {
        statsview = 0;

        ui->statsfone->setVisible(0);
        ui->staticon->setVisible(0);
        ui->apenko->setVisible(0);
        ui->apenkofone->setVisible(0);
        ui->stattext->setVisible(0);
        ui->stattext2->setVisible(0);
        ui->stattext3->setVisible(0);
        ui->stattext4->setVisible(0);
        ui->stattext5->setVisible(0);


    }

    if(menu2on)
    {
        QPoint Wpos = QCursor::pos(); //позиция курсора
        QPoint Wpos2 = this->pos(); //позиция окна
        int curs_x =  Wpos.x() - Wpos2.x();
        int curs_y = Wpos.y() - Wpos2.y();

        if(ui->authoricon->x()<=curs_x && (ui->authoricon->x() + ui->authoricon->width()) >=curs_x  &&  ui->authoricon->y()<=curs_y && (ui->authoricon->y() + ui->authoricon->height()) >=curs_y && !statsview)
        {
            statsview = 1;
            ui->statsfone->setVisible(1);
            ui->staticon->setVisible(1);
            ui->apenko->setVisible(1);
            ui->apenkofone->setVisible(1);
            ui->stattext->setVisible(1);

            ui->staticon->setPixmap(QPixmap(":/fts/firefox.png"));
            ui->apenko->setText(QString("FOX"));
            ui->apenkofone->setText(QString("FOX"));

            ui->statsfone->setGeometry(width()*15/100, height()*9/100, width() * 70/100, height() *80/100);
            ui->staticon->setGeometry(ui->statsfone->width()*7/100 + ui->statsfone->x(), ui->statsfone->y() + ui->statsfone->width()*4/100, ui->statsfone->width()*26/100, ui->statsfone->width()*26/100);

            ui->apenko->setGeometry(ui->staticon->x() + ui->staticon->width() * 6/5, ui->staticon->y() + ui->staticon->height()*1/10, ui->apenko->width(), ui->apenko->height());

            ui->apenkofone->setGeometry(ui->apenko->x()-5, ui->apenko->y()+5, ui->apenkofone->width(), ui->apenkofone->height());

            ui->stattext->setGeometry(ui->staticon->x() + ui->staticon->width() * 6/5, ui->staticon->y() + ui->staticon->width()*4/10 , ui->stattext->width(), ui->stattext->height());


            m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
            audiooutput3->setVolume(tr3);
            m_player3->play();
        }

        if(ui->paraxicon->x()<=curs_x && (ui->paraxicon->x() + ui->paraxicon->width()) >=curs_x  &&  ui->paraxicon->y()<=curs_y && (ui->paraxicon->y() + ui->paraxicon->height()) >=curs_y && !statsview)
        {
            statsview = 1;
            ui->statsfone->setVisible(1);
            ui->staticon->setVisible(1);
            ui->apenko->setVisible(1);
            ui->apenkofone->setVisible(1);
            ui->stattext2->setVisible(1);

            ui->staticon->setPixmap(QPixmap(":/fts/paraxialicon.png"));
            ui->apenko->setText(QString("PARAXIAL"));
            ui->apenkofone->setText(QString("PARAXIAL"));

            ui->statsfone->setGeometry(width()*15/100, height()*6/100, width() * 70/100, height() *80/100);
            ui->staticon->setGeometry(ui->statsfone->width()*7/100 + ui->statsfone->x(), ui->statsfone->y() + ui->statsfone->width()*4/100, ui->statsfone->width()*26/100, ui->statsfone->width()*26/100);

            ui->apenko->setGeometry(ui->staticon->x() + ui->staticon->width() * 6/5, ui->staticon->y() + ui->staticon->height()*1/10, ui->apenko->width(), ui->apenko->height());

            ui->apenkofone->setGeometry(ui->apenko->x()-5, ui->apenko->y()+5, ui->apenkofone->width(), ui->apenkofone->height());

            ui->stattext2->setGeometry(ui->staticon->x() + ui->staticon->width() * 6/5, ui->staticon->y() + ui->staticon->width() /4 , ui->stattext2->width(), ui->stattext2->height());


            m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
            audiooutput3->setVolume(tr3);
            m_player3->play();
        }

        if(ui->apenkicon->x()<=curs_x && (ui->apenkicon->x() + ui->apenkicon->width()) >=curs_x  &&  ui->apenkicon->y()<=curs_y && (ui->apenkicon->y() + ui->apenkicon->height()) >=curs_y && !statsview)
        {
            statsview = 1;
            ui->statsfone->setVisible(1);
            ui->staticon->setVisible(1);
            ui->apenko->setVisible(1);
            ui->apenkofone->setVisible(1);
            ui->stattext3->setVisible(1);

            ui->staticon->setPixmap(QPixmap(":/fts/apenkoicon.png"));
            ui->apenko->setText(QString("Fresh_Time"));
            ui->apenkofone->setText(QString("Fresh_Time"));

            ui->statsfone->setGeometry(width()*15/100, height()*6/100, width() * 70/100, height() *80/100);
            ui->staticon->setGeometry(ui->statsfone->width()*7/100 + ui->statsfone->x(), ui->statsfone->y() + ui->statsfone->width()*4/100, ui->statsfone->width()*26/100, ui->statsfone->width()*26/100);

            ui->apenko->setGeometry(ui->staticon->x() + ui->staticon->width() * 6/5, ui->staticon->y() + ui->staticon->height()*1/10, ui->apenko->width(), ui->apenko->height());

            ui->apenkofone->setGeometry(ui->apenko->x()-5, ui->apenko->y()+5, ui->apenkofone->width(), ui->apenkofone->height());

            ui->stattext3->setGeometry(ui->staticon->x() + ui->staticon->width() * 6/5, ui->staticon->y() + ui->staticon->width() /4 , ui->stattext3->width(), ui->stattext3->height());


            m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
            audiooutput3->setVolume(tr3);
            m_player3->play();
        }

        if(ui->vadimicon->x()<=curs_x && (ui->vadimicon->x() + ui->vadimicon->width()) >=curs_x  &&  ui->vadimicon->y()<=curs_y && (ui->vadimicon->y() + ui->vadimicon->height()) >=curs_y && !statsview)
        {
            statsview = 1;
            ui->statsfone->setVisible(1);
            ui->staticon->setVisible(1);
            ui->apenko->setVisible(1);
            ui->apenkofone->setVisible(1);
            ui->stattext4->setVisible(1);

            ui->staticon->setPixmap(QPixmap(":/fts/vadimicon.png"));
            ui->apenko->setText(QString("Censtro"));
            ui->apenkofone->setText(QString("Censtro"));

            ui->statsfone->setGeometry(width()*15/100, height()*6/100, width() * 70/100, height() *80/100);
            ui->staticon->setGeometry(ui->statsfone->width()*7/100 + ui->statsfone->x(), ui->statsfone->y() + ui->statsfone->width()*4/100, ui->statsfone->width()*26/100, ui->statsfone->width()*26/100);

            ui->apenko->setGeometry(ui->staticon->x() + ui->staticon->width() * 6/5, ui->staticon->y() + ui->staticon->height()*1/10, ui->apenko->width(), ui->apenko->height());

            ui->apenkofone->setGeometry(ui->apenko->x()-5, ui->apenko->y()+5, ui->apenkofone->width(), ui->apenkofone->height());

            ui->stattext4->setGeometry(ui->staticon->x() + ui->staticon->width() * 6/5, ui->staticon->y() + ui->staticon->width() /4 , ui->stattext4->width(), ui->stattext4->height());


            m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
            audiooutput3->setVolume(tr3);
            m_player3->play();
        }

        if(ui->danikicon->x()<=curs_x && (ui->danikicon->x() + ui->danikicon->width()) >=curs_x  &&  ui->danikicon->y()<=curs_y && (ui->danikicon->y() + ui->danikicon->height()) >=curs_y && !statsview)
        {
            statsview = 1;
            ui->statsfone->setVisible(1);
            ui->staticon->setVisible(1);
            ui->apenko->setVisible(1);
            ui->apenkofone->setVisible(1);
            ui->stattext5->setVisible(1);

            ui->staticon->setPixmap(QPixmap(":/fts/danik.png"));
            ui->apenko->setText(QString("MaLLoY"));
            ui->apenkofone->setText(QString("MaLLoY"));

            ui->statsfone->setGeometry(width()*15/100, height()*6/100, width() * 70/100, height() *80/100);
            ui->staticon->setGeometry(ui->statsfone->width()*7/100 + ui->statsfone->x(), ui->statsfone->y() + ui->statsfone->width()*4/100, ui->statsfone->width()*26/100, ui->statsfone->width()*26/100);

            ui->apenko->setGeometry(ui->staticon->x() + ui->staticon->width() * 6/5, ui->staticon->y() + ui->staticon->height()*1/10, ui->apenko->width(), ui->apenko->height());

            ui->apenkofone->setGeometry(ui->apenko->x()-5, ui->apenko->y()+5, ui->apenkofone->width(), ui->apenkofone->height());

            ui->stattext5->setGeometry(ui->staticon->x() + ui->staticon->width() * 6/5, ui->staticon->y() + ui->staticon->width() /4 , ui->stattext5->width(), ui->stattext5->height());


            m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
            audiooutput3->setVolume(tr3);
            m_player3->play();
        }


    }

    if(menu3on)
    {
        QPoint Wpos = QCursor::pos(); //позиция курсора
        QPoint Wpos2 = this->pos(); //позиция окна
        int curs_x =  Wpos.x() - Wpos2.x();
        int curs_y = Wpos.y() - Wpos2.y();

        if(ui->speedicon->x()<=curs_x && (ui->speedicon->x() + ui->speedicon->width()) >=curs_x  &&  ui->speedicon->y()<=curs_y && (ui->speedicon->y() + ui->speedicon->height()) >=curs_y)
        {
            ui->ukaz->setGeometry(ui->speedicon->x(), ui->ukaz->y(), ui->ukaz->width(), ui->ukaz->height());
            ui->buff->setText(QString("Увеличение скорости бега"));
            ability = 1;
            ui->playerability->setPixmap(QPixmap(":/fts/sprint.png"));

            m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
            audiooutput3->setVolume(tr3);
            m_player3->play();
        }

        if(ui->healthicon->x()<=curs_x && (ui->healthicon->x() + ui->healthicon->width()) >=curs_x  &&  ui->healthicon->y()<=curs_y && (ui->healthicon->y() + ui->healthicon->height()) >=curs_y)
        {
            ui->ukaz->setGeometry(ui->healthicon->x(), ui->ukaz->y(), ui->ukaz->width(), ui->ukaz->height());
            ui->buff->setText(QString("Увеличение восстановления здоровья"));
            ability = 2;
            ui->playerability->setPixmap(QPixmap(":/fts/healing.png"));

            m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
            audiooutput3->setVolume(tr3);
            m_player3->play();
        }

        if(ui->manaicon->x()<=curs_x && (ui->manaicon->x() + ui->manaicon->width()) >=curs_x  &&  ui->manaicon->y()<=curs_y && (ui->manaicon->y() + ui->manaicon->height()) >=curs_y)
        {
            ui->ukaz->setGeometry(ui->manaicon->x(), ui->ukaz->y(), ui->ukaz->width(), ui->ukaz->height());
            ui->buff->setText(QString("Увеличение восстановления энергии"));
            ability = 3;
            ui->playerability->setPixmap(QPixmap(":/fts/energy.png"));

            m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
            audiooutput3->setVolume(tr3);
            m_player3->play();
        }

        if(ui->leftarrow->x()<=curs_x && (ui->leftarrow->x() + ui->leftarrow->width()) >=curs_x  &&  ui->leftarrow->y()<=curs_y && (ui->leftarrow->y() + ui->leftarrow->height()) >=curs_y)
        {
            --iconnom; if(iconnom <=0) {iconnom = 20;}

            if(iconnom == 1) {ui->playericon->setPixmap(QPixmap(":/fts/ic1.png"));}
            if(iconnom == 2) {ui->playericon->setPixmap(QPixmap(":/fts/ic2.png"));}
            if(iconnom == 3) {ui->playericon->setPixmap(QPixmap(":/fts/ic3.png"));}
            if(iconnom == 4) {ui->playericon->setPixmap(QPixmap(":/fts/ic4.png"));}
            if(iconnom == 5) {ui->playericon->setPixmap(QPixmap(":/fts/ic5.png"));}
            if(iconnom == 6) {ui->playericon->setPixmap(QPixmap(":/fts/ic6.png"));}
            if(iconnom == 7) {ui->playericon->setPixmap(QPixmap(":/fts/ic7.png"));}
            if(iconnom == 8) {ui->playericon->setPixmap(QPixmap(":/fts/ic8.png"));}
            if(iconnom == 9) {ui->playericon->setPixmap(QPixmap(":/fts/ic9.png"));}
            if(iconnom == 10) {ui->playericon->setPixmap(QPixmap(":/fts/ic10.png"));}
            if(iconnom == 11) {ui->playericon->setPixmap(QPixmap(":/fts/ic11.png"));}
            if(iconnom == 12) {ui->playericon->setPixmap(QPixmap(":/fts/ic12.png"));}
            if(iconnom == 13) {ui->playericon->setPixmap(QPixmap(":/fts/ic13.png"));}
            if(iconnom == 14) {ui->playericon->setPixmap(QPixmap(":/fts/ic14.png"));}
            if(iconnom == 15) {ui->playericon->setPixmap(QPixmap(":/fts/ic15.png"));}
            if(iconnom == 16) {ui->playericon->setPixmap(QPixmap(":/fts/ic16.png"));}
            if(iconnom == 17) {ui->playericon->setPixmap(QPixmap(":/fts/ic17.png"));}
            if(iconnom == 18) {ui->playericon->setPixmap(QPixmap(":/fts/ic18.png"));}
            if(iconnom == 19) {ui->playericon->setPixmap(QPixmap(":/fts/ic19.png"));}
            if(iconnom == 20) {ui->playericon->setPixmap(QPixmap(":/fts/ic20.png"));}


            m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
            audiooutput3->setVolume(tr3);
            m_player3->play();


        }

        if(ui->rightarrow->x()<=curs_x && (ui->rightarrow->x() + ui->rightarrow->width()) >=curs_x  &&  ui->rightarrow->y()<=curs_y && (ui->rightarrow->y() + ui->rightarrow->height()) >=curs_y)
        {
            ++iconnom; if(iconnom >=21) {iconnom = 1;}

            if(iconnom == 1) {ui->playericon->setPixmap(QPixmap(":/fts/ic1.png"));}
            if(iconnom == 2) {ui->playericon->setPixmap(QPixmap(":/fts/ic2.png"));}
            if(iconnom == 3) {ui->playericon->setPixmap(QPixmap(":/fts/ic3.png"));}
            if(iconnom == 4) {ui->playericon->setPixmap(QPixmap(":/fts/ic4.png"));}
            if(iconnom == 5) {ui->playericon->setPixmap(QPixmap(":/fts/ic5.png"));}
            if(iconnom == 6) {ui->playericon->setPixmap(QPixmap(":/fts/ic6.png"));}
            if(iconnom == 7) {ui->playericon->setPixmap(QPixmap(":/fts/ic7.png"));}
            if(iconnom == 8) {ui->playericon->setPixmap(QPixmap(":/fts/ic8.png"));}
            if(iconnom == 9) {ui->playericon->setPixmap(QPixmap(":/fts/ic9.png"));}
            if(iconnom == 10) {ui->playericon->setPixmap(QPixmap(":/fts/ic10.png"));}
            if(iconnom == 11) {ui->playericon->setPixmap(QPixmap(":/fts/ic11.png"));}
            if(iconnom == 12) {ui->playericon->setPixmap(QPixmap(":/fts/ic12.png"));}
            if(iconnom == 13) {ui->playericon->setPixmap(QPixmap(":/fts/ic13.png"));}
            if(iconnom == 14) {ui->playericon->setPixmap(QPixmap(":/fts/ic14.png"));}
            if(iconnom == 15) {ui->playericon->setPixmap(QPixmap(":/fts/ic15.png"));}
            if(iconnom == 16) {ui->playericon->setPixmap(QPixmap(":/fts/ic16.png"));}
            if(iconnom == 17) {ui->playericon->setPixmap(QPixmap(":/fts/ic17.png"));}
            if(iconnom == 18) {ui->playericon->setPixmap(QPixmap(":/fts/ic18.png"));}
            if(iconnom == 19) {ui->playericon->setPixmap(QPixmap(":/fts/ic19.png"));}
            if(iconnom == 20) {ui->playericon->setPixmap(QPixmap(":/fts/ic20.png"));}

            m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
            audiooutput3->setVolume(tr3);
            m_player3->play();

        }
    }

    if(menu5on)
    {
        menu5on = 0;
        menu2on = 1;
        pausa = 1;
        ui->menu1fone->setVisible(0);
        ui->wintext->setVisible(0);
        ui->loosetext->setVisible(0);

        ui->menu2fone->setVisible(1);
        ui->version->setVisible(1);
        ui->menu2button->setVisible(1);
        ui->nameg1->setVisible(1);
        ui->nameg2->setVisible(1);
        ui->nameg3->setVisible(1);
        ui->testers->setVisible(1);
        ui->apenkicon->setVisible(1);
        ui->paraxicon->setVisible(1);
        ui->authoricon->setVisible(1);
        ui->iconfon1->setVisible(1);
        ui->iconfon2->setVisible(1);
        ui->vadimicon->setVisible(1);
        ui->iconfon3->setVisible(1);
        ui->booster->setVisible(1);
        ui->danikicon->setVisible(1);
        ui->iconfon4->setVisible(1);
        ui->exitbutton->setVisible(1);



    }
}













//основной скрипт
void MainWindow::paintEvent(QPaintEvent *)
{


    //меню 1 - заставка fox
    if(menu1on)
    {
        --men1count;

        if(men1count%10 == 0)
        {
            int kadr = rand()%10 + 1;

            if(kadr ==1) {ui->menu1text->setFont(QFont("Comic Sans MS",300,300,0));}
            if(kadr ==2) {ui->menu1text->setFont(QFont("Rubik",300,300,0));}
            if(kadr ==3) {ui->menu1text->setFont(QFont("Impact",300,300,0));}
            if(kadr ==4) {ui->menu1text->setFont(QFont("Courier",300,300,0));}
            if(kadr ==5) {ui->menu1text->setFont(QFont("Segoe Script",300,300,0));}
            if(kadr ==6) {ui->menu1text->setFont(QFont("Liberation Serif",300,300,0));}
            if(kadr ==7) {ui->menu1text->setFont(QFont("MV Boli",300,300,0));}
            if(kadr ==8) {ui->menu1text->setFont(QFont("NSimSun",300,300,0));}
            if(kadr ==9) {ui->menu1text->setFont(QFont("Ink Free",300,300,0));}
            if(kadr ==10) {ui->menu1text->setFont(QFont("Amiri",300,300,0));}
        }

        if (men1count == 0)
        {
            menu1on = 0;
            ui->menu1fone->setVisible(0);
            ui->menu1text->setVisible(0);
            menu2on = 1;
            menu3on = 0;
            menu4on = 0;

            ui->menu2fone->setGeometry(0,0,width(), height());
            ui->menu2fone->setVisible(1);

            ui->version->setGeometry(width() * 99/100 - ui->version->width(), height() * 99/100 - ui->version->height(), ui->version->width(), ui->version->height());
            ui->version->setVisible(1);


            ui->menu2button->setVisible(1);
            ui->menu2button->setGeometry(width() *45/100, height()*60/100, width() * 10/100, width() * 10/100 );


            ui->nameg1->setVisible(1);
            ui->nameg2->setVisible(1);
            ui->nameg3->setVisible(1);

            ui->nameg1->setGeometry(width()/2 - ui->nameg1->width()/2, height() * 5/100, ui->nameg1->width(), ui->nameg1->height());
            ui->nameg2->setGeometry(width()/2 - ui->nameg2->width()/2, ui->nameg1->y() + ui->nameg1->height()*12/10, ui->nameg2->width(), ui->nameg2->height());
            ui->nameg3->setGeometry(width()/2 - ui->nameg3->width()/2, ui->nameg2->y() + ui->nameg1->height()*9/10, ui->nameg3->width(), ui->nameg3->height());






            ui->testers->setVisible(1);
            ui->testers->setGeometry(width()*1/100,height()*55/100 , ui->testers->width(), ui->testers->height());

            ui->apenkicon->setVisible(1);
            ui->paraxicon->setVisible(1);
            ui->authoricon->setVisible(1);
            ui->iconfon1->setVisible(1);
            ui->iconfon2->setVisible(1);

            ui->paraxicon->setGeometry(width()*3/100, height()*65/100, height()/10, height()/10);
            ui->iconfon1->setGeometry(ui->paraxicon->x() - 10, ui->paraxicon->y() - 10, ui->paraxicon->width()+20, ui->paraxicon->height() + 20);

            ui->apenkicon->setGeometry(ui->paraxicon->x() + height()/20 + height()/10, ui->paraxicon->y(), ui->paraxicon->width(), ui->paraxicon->height());
            ui->iconfon2->setGeometry(ui->apenkicon->x()-10, ui->apenkicon->y() - 10, ui->iconfon1->width(), ui->iconfon1->height());


            ui->booster->setGeometry(width() *3/100, height() *3/100, ui->booster->width(), ui->booster->height());
            ui->authoricon->setGeometry(width()*3/100 , height()*13/100, height()*3/10, height()*3/10);


            ui->vadimicon->setVisible(1);
            ui->iconfon3->setVisible(1);



            ui->vadimicon->setGeometry(ui->paraxicon->x(), height()  * 80/100, ui->paraxicon->width(), ui->paraxicon->height());
            ui->iconfon3->setGeometry(ui->vadimicon->x() - 10, ui->vadimicon->y() - 10, ui->vadimicon->width() + 20, ui->vadimicon->height() + 20);

            ui->booster->setVisible(1);
            ui->danikicon->setVisible(1);
            ui->iconfon4->setVisible(1);


            ui->danikicon->setGeometry(ui->apenkicon->x(), ui->vadimicon->y(), ui->vadimicon->width(), ui->vadimicon->height());
            ui->iconfon4->setGeometry(ui->danikicon->x()-10, ui->danikicon->y()-10, ui->danikicon->width()+20, ui->danikicon->height()+20);

            ui->exitbutton->setVisible(1);
            ui->exitbutton->setGeometry(width()*99/100-ui->exitbutton->width(), width() /100, ui->exitbutton->width(), ui->exitbutton->height());

            ui->menu2button->setIconSize(QSize(ui->menu2button->width(), ui->menu2button->width()));

        }

    }

    if(m_player4->isPlaying())
    {
        audiooutput5->setVolume(0.2);
    }
    else
    {
        audiooutput5->setVolume(tr5);
    }

    if((health<=0 || levakov_health<=0)&&menu4on)
    {
        pausa = 1;
        menu4on = 0;
        menu5on =1;
        ui->menu1fone->setVisible(1);
        if(health<=0)
        {
            ui->loosetext->setVisible(1);
        }
        else
        {
            ui->wintext->setVisible(1);
        }

        m_player4->stop();

        m_player5->setSource(QUrl("qrc:/snd/levMeetUAtExam.mp3"));
        audiooutput5->setVolume(tr5);
        m_player5->play();
    }

    //запуск звука в главном меню
    if(m_player1->isPlaying()==0 && menu4on==0  && (menu2on||menu3on))
    {
        m_player1->setSource(QUrl("qrc:/snd/menuSound.mp3"));
        audiooutput1->setVolume(tr1);
        m_player1->play();
    }

    if(m_player1->isPlaying() && menu4on)
    {
        m_player1->stop();
    }


    //запуск звука в игре
    if((m_player6->isPlaying()==0) && menu4on==1 && menu3on==0 && menu2on ==0 && menu1on==0 )
    {

       m_player6->play();
    }

    if( (menu5on == 1||menu2on ==1))
    {
        m_player6->stop();
    }


    //запуск звуков-фраз Левакова
    if(menu4on&&!pausa && m_player5->isPlaying() ==0)
    {
        ++fraze;
        if(fraze>=400 )
        {
            fraze = 0;
            int nomp = rand()% 25 + 1;
            if(nomp==1){ m_player5->setSource(QUrl("qrc:/snd/levDontLearn.mp3"));}
            if(nomp==2){m_player5->setSource(QUrl("qrc:/snd/levDontLearn2.mp3"));}
            if(nomp==3){m_player5->setSource(QUrl("qrc:/snd/levOooooo.mp3"));}
            if(nomp==4){m_player5->setSource(QUrl("qrc:/snd/levStudyMore.mp3"));}
            if(nomp==5){m_player5->setSource(QUrl("qrc:/snd/levIAteDesk.mp3"));}
            if(nomp==6){m_player5->setSource(QUrl("qrc:/snd/levItsAnalysis.mp3"));}
            if(nomp==7){m_player5->setSource(QUrl("qrc:/snd/levItsAnalysis2.mp3"));}
            if(nomp==8){m_player5->setSource(QUrl("qrc:/snd/levItsNeedless.mp3"));}
            if(nomp==9){m_player5->setSource(QUrl("qrc:/snd/levIWillShow.mp3"));}
            if(nomp==10){m_player5->setSource(QUrl("qrc:/snd/levLook.mp3"));}
            if(nomp==11){m_player5->setSource(QUrl("qrc:/snd/levMistake.mp3"));}
            if(nomp==12){m_player5->setSource(QUrl("qrc:/snd/levMistake2.mp3"));}
            if(nomp==13){m_player5->setSource(QUrl("qrc:/snd/levMistake3.mp3"));}
            if(nomp==14){m_player5->setSource(QUrl("qrc:/snd/levMistake4.mp3"));}
            if(nomp==15){m_player5->setSource(QUrl("qrc:/snd/levNextParagraph.mp3"));}
            if(nomp==16){m_player5->setSource(QUrl("qrc:/snd/levNobodyListen.mp3"));}
            if(nomp==17){m_player5->setSource(QUrl("qrc:/snd/levNoOneRemember.mp3"));}
            if(nomp==18){m_player5->setSource(QUrl("qrc:/snd/levOral.mp3"));}
            if(nomp==19){m_player5->setSource(QUrl("qrc:/snd/levProblems.mp3"));}
            if(nomp==20){m_player5->setSource(QUrl("qrc:/snd/levSitDown.mp3"));}
            if(nomp==21){m_player5->setSource(QUrl("qrc:/snd/levTooLate.mp3"));}
            if(nomp==22){m_player5->setSource(QUrl("qrc:/snd/levUDontUnderstand.mp3"));}
            if(nomp==23){m_player5->setSource(QUrl("qrc:/snd/levUDontUnderstand2.mp3"));}
            if(nomp==24){m_player5->setSource(QUrl("qrc:/snd/levUWillNotLearn.mp3"));}
            if(nomp==25){m_player5->setSource(QUrl("qrc:/snd/levUWillNotLearn2.mp3"));}

            m_player5->play();

        }
    }

    if(!pausa)
    {    //обработка всевозможных событий
    if(!RockGo) ui->Rocket1->setVisible(false);
    if(body_dmg && !immune) {health = health - 5; body_dmg = 0; immune = 50;}
    if(rocket_dmg && !immune) {health = health - 15; mana /=2; rocket_dmg = 0; immune = 100;}
    if(rocket2_dmg && !immune) {health = health - 15; mana /=2; rocket2_dmg = 0; immune = 100;}
    if(bull_dmg)
    {
        levakov_health-=10; bull_dmg = 0;
        X1 = ui->Levakov->x() + ui->Levakov->width() / 2 - ui->me->x() - ui->me->width()/2;
        Y1 = ui->Levakov->y() + ui->Levakov->height() / 2 - ui->me->y() - ui->me->height()/2;
        if(X1<0) X1*=-1;
        if(Y1<0) Y1*=-1;
        if(X1*X1 + Y1*Y1 <= ui->ring->width() * ui->ring->width()) {fring = 1;}
        else {rock2 = 1;}
    }

    if(fringdmg && !immune) {health = health - 30; fringdmg = 0; immune = 100; if(achFire == 0){achFire = 1; ++achv;} }
    if(immune>0) --immune;
    ++health_regen;

    if(ability!=2)
    {
    if(health_regen>=400 ) {if(health<100){++health;} health_regen = 0; }
    }
    else
    {
        if(health_regen>=320 ) {if(health<100){++health;} health_regen = 0; }
    }

    //обработка события вампир
    if(levakov_health<=50 && vampire)
    {
        levakov_health =levakov_health + health;
        ++health; health/=2;
        vampire = 0;
        achVampire = 1;
        ++achv;
    }
    }

    //пауза
    if(escbutton)
    {
         ui->pause_fon->setVisible(1);
        ui->pause_fon->setGeometry(width()/5, height()/5, width() *3 /5, height() *3/5);

        ui->menubutton->setGeometry(ui->pause_fon->x() + ui->pause_fon->width() * 33/100, ui->pause_fon->y() + ui->pause_fon->height() * 5 / 10, ui->pause_fon->width() * 35 / 100, ui->pause_fon->height() / 4);
       // ui->Exitbutton->setGeometry(ui->pause_fon->x() + ui->pause_fon->width() * 58/100, ui->pause_fon->y() + ui->pause_fon->height() * 5 / 10, ui->pause_fon->width() * 35 / 100, ui->pause_fon->height() / 4);
        ui->continuebutton->setGeometry(ui->pause_fon->x() + ui->pause_fon->width() * 42 / 100, ui->pause_fon->y() + ui->pause_fon->height() * 20 / 100, ui->pause_fon-> width() * 16 /100, ui->pause_fon->width()*16/100);
        ui->pausetext->setGeometry(ui->pause_fon->x() + ui->pause_fon->width()/2 - ui->pausetext->width() /2, ui->pause_fon->y()+ui->pause_fon->height()*10/100, ui->pausetext->width(), ui->pausetext->height());
        ui->continuebutton->setIconSize(QSize(ui->continuebutton->width(),ui->continuebutton->height()));
        ui->menubutton->setIconSize(QSize(ui->menubutton->width() ,ui->menubutton->height()));

        escbutton = 0;

        ui->continuebutton->setVisible(1);
       // ui->Exitbutton->setVisible(1);
        ui->menubutton->setVisible(1);
        ui->continuebutton->setEnabled(1);
       // ui->Exitbutton->setEnabled(1);
        ui->menubutton->setEnabled(1);


        ui->pausetext->setVisible(1);

    }

    if(escbutton_off)
    {
        escbutton_off = 0;
        ui->pause_fon->setVisible(0);
        pausa = 0;

        ui->continuebutton->setVisible(0);
        //ui->Exitbutton->setVisible(0);
        ui->menubutton->setVisible(0);
        ui->continuebutton->setEnabled(0);
        //ui->Exitbutton->setEnabled(0);
        ui->menubutton->setEnabled(0);
       //MainWindow::showFullScreen();
        ui->pausetext->setVisible(0);
    }


    if(!pausa)
    {
   //описание полоски здоровья и маны и ракет Левакова
    if(health<=100)
    {
        int nov_w = health*ui->gray->width()/100;
        ui->hp->setGeometry(ui->hp->x(), ui->hp->y(),nov_w, ui->hp->height());
    }

    if(mana<=100)
    {
        int nov_wm = mana*ui->gray->width()/100;
        ui->Mana->setGeometry(ui->Mana->x(), ui->Mana->y(),nov_wm, ui->Mana->height());
    }

    if(levakov_health<=150)
    {
        int nov_w = levakov_health*ui->gray2->width()/150;
        ui->hp_levakov->setGeometry(ui->hp_levakov->x(), ui->hp_levakov->y(),nov_w, ui->hp_levakov->height());
    }


    {
        int nov_wr = ui->gray2->width()*RockCount/2000;
         ui->rocket_timer->setGeometry(ui->rocket_timer->x(), ui->rocket_timer->y(), nov_wr, ui->rocket_timer->height());
    }

    ++mana_count;

    if(ability!=3)
    {
    if(mana_count == 10 && mana<100) {++mana; mana_count = 0;} //10 маны/сек
    if(mana_count == 10) mana_count = 0;
    }
    else
    {
        if(mana_count == 8 && mana<100) {++mana; mana_count = 0;} //10 маны/сек
        if(mana_count == 8) mana_count = 0;
    }


    }


    //описание анимации взрыва ракеты
    if(!pausa)
    {
    if(fireboom)
    {
        ++boomcount;
        if(boomcount == 10)
        {ui->Fire1->setVisible(true); ui->Fire1->setGeometry(boomX, boomY-15, ui->Fire1->width(), ui->Fire1->height());}

        if(boomcount == 40)
        {ui->Fire2->setVisible(true); ui->Fire2->setGeometry(boomX-15, boomY, ui->Fire2->width(), ui->Fire2->height());}

        if(boomcount == 70)
        {ui->Fire3->setVisible(true); ui->Fire3->setGeometry(boomX+15, boomY, ui->Fire3->width(), ui->Fire3->height());}

        if(boomcount == 200)
        {
            ui->Fire1->setVisible(0); ui->Fire2->setVisible(0);  ui->Fire3->setVisible(0); fireboom = 0; boomcount = 0;
        }


    }
    }


    if(!pausa)
    {

    if(fireboom2)
    {
        ++boomcount2;
        if(boomcount2 == 10)
        {ui->Fire4->setVisible(true); ui->Fire4->setGeometry(boomX2, boomY2+15, ui->Fire4->width(), ui->Fire4->height());}

        if(boomcount2 == 40)
        {ui->Fire5->setVisible(true); ui->Fire5->setGeometry(boomX2-15, boomY2 -5, ui->Fire5->width(), ui->Fire5->height());}

        if(boomcount2 == 70)
        {ui->Fire6->setVisible(true); ui->Fire6->setGeometry(boomX2+15, boomY2 -5, ui->Fire6->width(), ui->Fire6->height());}

        if(boomcount2 == 200)
        {
            ui->Fire4->setVisible(0); ui->Fire5->setVisible(0);  ui->Fire6->setVisible(0); fireboom2 = 0; boomcount2 = 0;
        }


    }

    }


    //описание движений игрока


         int novX = 0;
         int novY = 0;

         if(ability!=1)
         {
         novX = ui->me->x() + vpravo*10;
         novY = ui->me->y() + verh*(-10);
         }
         else
         {
             novX = ui->me->x() + vpravo*12;
             novY = ui->me->y() + verh*(-12);
         }

        if(novX<=0) novX = 0; if(novX>=width()) novX = width();
        if(novY<=0) novY =0;  if(novY>=height()) novY = height();

        if(!pausa)
        {

        if(najato && !fireboom &&!fireboom2){ui->me->setGeometry(novX,novY, ui->me->width(),ui->me->height() );}
        najato = 0;

        if(ui->me->x() <= 0) {ui->me->setGeometry(1,ui->me->y(), ui->me->width(), ui->me->height());}
        if(ui->me->x() >= width() - ui->me->width()) {ui->me->setGeometry(width() - ui->me->width(),ui->me->y(), ui->me->width(), ui->me->height());}

        if(ui->me->y() <= 0) {ui->me->setGeometry(ui->me->x(),1, ui->me->width(), ui->me->height());}
        if(ui->me->y() >= height() - ui->me->height()) {ui->me->setGeometry(ui->me->x(), height() - ui->me->height(), ui->me->width(), ui->me->height());}

        }



        if(!pausa)
        {
    //ПРИЦЕЛ И ЕГО ГРАФИКА
     ui->pricel->setGeometry(ui->pricel->x(), ui->pricel->y(), height(), height());


     //размещение хп и других обьектов на окне
     ui->hp_levakov->setGeometry(width() - ui->hp_levakov->width(), 5, ui->hp_levakov->width(), ui->hp_levakov->height());
     ui->gray2->setGeometry(width() - ui->gray2->width(), 7, ui->gray2->width(), ui->gray2->height());

     ui->heart2->setGeometry(width() - ui->gray2->width() - ui->heart2->width() - 5, 3, ui->heart2->width(),ui->heart2->height());
     ui->rocket_timer->setGeometry(width() - ui->rocket_timer->width(),ui->rocket_timer->y(), ui->rocket_timer->width(), ui->rocket_timer->height());
     ui->mefone->setGeometry(0,0, ui->heart->x() + ui->heart->width() + 5, ui->heart->height()+5);
     ui->levakovfone->setGeometry(ui->heart2->x() - 5, 0 , width() - ui->heart2->x() + 5, ui->heart2->height() + 5);

     ui->achfone->setGeometry(ui->mefone->width() + 15, 0, ui->levakovfone->x() - 15 - ui->achfone->x(), ui->achfone->height());
     ui->achfoto->setGeometry(ui->achfone->x() + ui->achfone->width()*90/100 - ui->achfoto->width() , 0, ui->achfoto->width(), ui->achfoto->height());
     ui->achtext->setGeometry(ui->achfone->x() + ui->achfone->width()*5/100 ,  ui->achfone->y() + ui->achfone->height()*5/100, ui->achtext->width(), ui->achtext->height());
     ui->achtext2->setGeometry(ui->achtext->x() + ui->achtext->width()*2/10, ui->achtext->y() + ui->achtext->height(), ui->achtext->width(), ui->achtext->height());

     ui->ufo->setGeometry(ui->Levakov->x() - 20, ui->Levakov->y()+100, ui->ufo->width(), ui->ufo->height());
      ui->mainfon->setGeometry(0,0, width(), height());
     ui->playerability->setGeometry(width() /100, ui->mefone->y() + ui->mefone->height() + height()/100, width()*3/100, width()*3/100);
      ui->levakability->setGeometry(width()*96/100, ui->levakovfone->y() + ui->levakovfone->height() + height()/100, width() * 3/100, width()*3/100);
        }


    //описание движения Левакова
    ++ FrCount;
    X1 = ui->me->x();
    Y1 = ui->me->y();
    X2 = ui->Levakov->x();
    Y2 = ui->Levakov->y();

    int DX, DY;
    double dx, dy;
    double mx,my,lx,ly;
    mx = (double)X1;
    my = (double)Y1;
    lx = (double)X2;
    ly = (double)Y2;

    dx = sqrt((lx-mx)*(lx-mx)) / sqrt((lx-mx)*(lx-mx) + (ly-my)*(ly-my)) * 5 ;

    dy = sqrt((ly-my)*(ly-my)) / sqrt((lx-mx)*(lx-mx) + (ly-my)*(ly-my)) * 5 ;





    if(lx - mx<=1 && lx-mx>=-1 && ly-my<=1 && ly - my >=-1) { dx = 0; dy = 0;}

    if(lx>=mx) dx*=-1;
    if(ly>=my) dy*=-1;

    DX = (int) dx;
    DY = (int) dy;


    if(!pausa)
    {
    if(FrCount%5 == 0)
    {if(!levakstay) {ui->Levakov->setGeometry(ui->Levakov->x() + DX, ui->Levakov->y() + DY, ui->Levakov->width(), ui->Levakov->height());}

      int  bod_x = ui->Levakov->x() + ui->Levakov->width()/2 - ui->me->x() - ui->me->width()/2;
       int bod_y = ui->Levakov->y() + ui->Levakov->height()/2 - ui->me->y() - ui->me->height()/2;

      int storona = 50;

      if(bod_x>=-storona&&bod_x<=storona && bod_y>=-storona && bod_y<=storona) {body_dmg = 1; ui->me->setGeometry(ui->me->x() + 20*DX, ui->me->y() + 20*DY, ui->me->width(), ui->me->height());}

        //Изменение рисунка Левакова
        if(ui->Levakov->x()<=ui->me->x()){ui->Levakov->setPixmap(QPixmap(":/fts/sticker2.png"));}
        if(ui->Levakov->x()>ui->me->x()){ui->Levakov->setPixmap(QPixmap(":/fts/sticker1.png"));}


        //прицел
        QPoint Wpos = QCursor::pos(); //позиция курсора
        QPoint Wpos2 = this->pos(); //позиция окна
        int curs_x =  Wpos.x() - Wpos2.x();
        int curs_y = Wpos.y() - Wpos2.y();
        ui->scope->setGeometry(curs_x - ui->scope->width()*30/100, curs_y - ui->scope->height()/2 , ui->scope->width(), ui->scope->height());

        ui->pricel->setGeometry(ui->scope->x() - ui->pricel->width()/2 + ui->scope->width()/2 + 1, ui->scope->y() - ui->pricel->height()/2 + ui->scope->height() -14, ui->pricel->width(), ui->pricel->height() );


    FrCount = 0;
    }
    }



    //таймер события RockTime раз в 20 секунд
    if(!pausa)
    {

    if(!RockGo) ++RockCount;
    if(RockCount == 2000)
    {
        RockTime = 1; RockCount = 0;
        m_player2->setSource(QUrl("qrc:/snd/sfxRocketFly.mp3"));
        audiooutput2->setVolume(tr2);
        m_player2->play();

    }
    }



    //событие - начало полета ракеты (подготовка)
    if(!pausa)
    {
    if(RockTime)
    {
        ui->Rocket1->setGeometry(ui->Levakov->x(), ui->Levakov->y(), ui->Rocket1->width(), ui->Rocket1->height());
        ui->Rocket1->setVisible(true);



        //изменение рисунка ракеты

        int chetv = 0;
        int nom = 0;

        if(ui->me->x()>=ui->Rocket1->x() && ui->me->y()<= ui->Rocket1->y() && chetv == 0) chetv = 1;
        if(ui->me->x()<=ui->Rocket1->x() && ui->me->y()<= ui->Rocket1->y() && chetv == 0) chetv = 2;
        if(ui->me->x()<=ui->Rocket1->x() && ui->me->y()>= ui->Rocket1->y() && chetv == 0) chetv = 3;
        if(ui->me->x()>=ui->Rocket1->x() && ui->me->y()>= ui->Rocket1->y() && chetv == 0) chetv = 4;

        if(chetv==1)
        {
            double Xc = (double)(ui->me->x() - ui->Rocket1->x());
            double Yc = (double)(ui->Rocket1->y() - ui->me->y());
            if (Xc == 0) Xc = 1;
            if(Yc == 0) Yc = 1;
            double Dc = Yc / Xc;
            if(Dc < 0.414213) nom = 3;
            if(Dc>=0.414213 && Dc< 2.414213) nom = 2;
            if(Dc>=2.414213) nom = 1;
        }

        if(chetv==2)
        {
            double Xc = (double)(ui->me->x() - ui->Rocket1->x());
            double Yc = (double)(ui->Rocket1->y() - ui->me->y());
            if (Xc == 0) Xc = -1;
            if(Yc == 0) Yc = 1;
            double Dc = Yc / Xc;
            if(Dc > -0.414213) nom = 7;
            if(Dc<= - 0.414213 && Dc> - 2.414213) nom = 8;
            if(Dc<=-2.414213) nom = 1;
        }

        if(chetv==3)
        {
            double Xc = (double)(ui->me->x() - ui->Rocket1->x());
            double Yc = (double)(ui->Rocket1->y() - ui->me->y());
            if (Xc == 0) Xc = -1;
            if(Yc == 0) Yc = -1;
            double Dc = Yc / Xc;
            if(Dc < 0.414213) nom = 7;
            if(Dc>=0.414213 && Dc< 2.414213) nom = 6;
            if(Dc>=2.414213) nom = 5;
        }

        if(chetv==4)
        {
            double Xc = (double)(ui->me->x() - ui->Rocket1->x());
            double Yc = (double)(ui->Rocket1->y() - ui->me->y());
            if (Xc == 0) Xc = 1;
            if(Yc == 0) Yc = -1;
            double Dc = Yc / Xc;
            if(Dc > -0.414213) nom = 3;
            if(Dc<= - 0.414213 && Dc> - 2.414213) nom = 4;
            if(Dc<=-2.414213) nom = 5;
        }

        if(nom == 1){ui->Rocket1->setPixmap(QPixmap(":/fts/Rocket1.png"));}
        if(nom == 2){ui->Rocket1->setPixmap(QPixmap(":/fts/Rocket2.png"));}
        if(nom == 3){ui->Rocket1->setPixmap(QPixmap(":/fts/Rocket3.png"));}
        if(nom == 4){ui->Rocket1->setPixmap(QPixmap(":/fts/Rocket4.png"));}
        if(nom == 5){ui->Rocket1->setPixmap(QPixmap(":/fts/Rocket5.png"));}
        if(nom == 6){ui->Rocket1->setPixmap(QPixmap(":/fts/Rocket6.png"));}
        if(nom == 7){ui->Rocket1->setPixmap(QPixmap(":/fts/Rocket7.png"));}
        if(nom == 8){ui->Rocket1->setPixmap(QPixmap(":/fts/Rocket8.png"));}




        X1 = ui->me->x();
        Y1 = ui->me->y();
        X2 = ui->Rocket1->x();
        Y2 = ui->Rocket1->y();


        mx = (double)X1;
        my = (double)Y1;
        lx = (double)X2;
        ly = (double)Y2;

        dx = sqrt((lx-mx)*(lx-mx)) / sqrt((lx-mx)*(lx-mx) + (ly-my)*(ly-my)) * 15 ;

        dy = sqrt((ly-my)*(ly-my)) / sqrt((lx-mx)*(lx-mx) + (ly-my)*(ly-my)) * 15 ;





        if(lx - mx<=1 && lx-mx>=-1 && ly-my<=1 && ly - my >=-1) { dx = 0; dy = 0;}

        if(lx>=mx) dx*=-1;
        if(ly>=my) dy*=-1;

        RockGoX = (int) dx;
        RockGoY = (int) dy;

        RockTime = 0; RockGo = 1; RockCount = 0;






    }
    }



    //движение ракеты, вектора движения заданы в RockTime
    if(!pausa)
    {
    if(RockGo)
    {
        ++RockGoCount;
        if(RockGoCount%5 == 0)
        {
            ui->Rocket1->setGeometry(ui->Rocket1->x() + 2*RockGoX, ui->Rocket1->y() + 2*RockGoY, ui->Rocket1->width(), ui-> Rocket1->height());
            RockGoCount = 0;
        }


       //если в полете есть касание то урон от ракеты
        int  bod_x = ui->Rocket1->x() + ui->Rocket1->width()/2 - ui->me->x() - ui->me->width()/2;
        int bod_y = ui->Rocket1->y() + ui->Rocket1->height()/2 - ui->me->y() - ui->me->height()/2;

        int storona = 60;

        if(bod_x>=-storona&&bod_x<=storona && bod_y>=-storona && bod_y<=storona)
        {
            rocket_dmg = 1; RockGo = 0;
            ui->Rocket1->setVisible(false);  RockCount = 0; fireboom = 1;
            boomX = ui->me->x();
            boomY = ui->me->y();
            if(!achOshib){++achv; achOshib = 1;}
            m_player2->setSource(QUrl("qrc:/snd/sfxRocketBoom.mp3"));
            audiooutput2->setVolume(tr2);
            m_player2->play();
        }



        //если ракета промахнулась
        if(ui->Rocket1->x()<=0 || ui->Rocket1->y()<=0 || ui->Rocket1->x()>=width() || ui->Rocket1->y()>=height()) {RockGo = 0; ui->Rocket1->setVisible(false); RockCount = 0;}

    }
    }


    if(!pausa)
    {
    //полет пули
    if(vistrelGo)
    {
        ++bullgocount;
        if(bullgocount%5 == 0)
        {
            ui->bullet->setGeometry(ui->bullet->x() + bullgox, ui->bullet->y() + bullgoy, ui->bullet->width(), ui->bullet->height());
            bullgocount = 0;
        }


        //если есть попадание в Левакова
        int  bod_x = ui->bullet->x() + ui->bullet->width()/2 - ui->Levakov->x() - ui->Levakov->width()/2;
        int bod_y = ui->bullet->y() + ui->bullet->height()/2 - ui->Levakov->y() - ui->Levakov->height()/2;

        int storona = 50;

        if(bod_x>=-storona&&bod_x<=storona && bod_y>=-storona && bod_y<=storona)
        {
            bull_dmg = 1; vistrelGo = 0;

            ui->bullet->setVisible(false);
            if(!achKennedy) {achKennedy = 1; ++achv;}

        }



        //если пуля промахнулась
        if(ui->bullet->x()<=0 || ui->bullet->y()<=0 || ui->bullet->x()>=width() || ui->bullet->y()>=height()) {vistrelGo = 0; ui->bullet->setVisible(false); if(!achPromah){achPromah = 1; ++achv;};}

    }
    }




    //полет второй ракеты
    if(!pausa)
    {
    if(rock2)
    {
        ui->Rocket2->setGeometry(ui->Levakov->x(), ui->Levakov->y(), ui->Rocket2->width(), ui->Rocket2->height());
        ui->Rocket2->setVisible(true);

        m_player2->setSource(QUrl("qrc:/snd/sfxRocketFly.mp3"));
        audiooutput2->setVolume(tr2);
        m_player2->play();

        //изменение рисунка ракеты

        int chetv = 0;
        int nom = 0;

        if(ui->me->x()>=ui->Rocket2->x() && ui->me->y()<= ui->Rocket2->y() && chetv == 0) chetv = 1;
        if(ui->me->x()<=ui->Rocket2->x() && ui->me->y()<= ui->Rocket2->y() && chetv == 0) chetv = 2;
        if(ui->me->x()<=ui->Rocket2->x() && ui->me->y()>= ui->Rocket2->y() && chetv == 0) chetv = 3;
        if(ui->me->x()>=ui->Rocket2->x() && ui->me->y()>= ui->Rocket2->y() && chetv == 0) chetv = 4;

        if(chetv==1)
        {
            double Xc = (double)(ui->me->x() - ui->Rocket2->x());
            double Yc = (double)(ui->Rocket2->y() - ui->me->y());
            if (Xc == 0) Xc = 1;
            if(Yc == 0) Yc = 1;
            double Dc = Yc / Xc;
            if(Dc < 0.414213) nom = 3;
            if(Dc>=0.414213 && Dc< 2.414213) nom = 2;
            if(Dc>=2.414213) nom = 1;
        }

        if(chetv==2)
        {
            double Xc = (double)(ui->me->x() - ui->Rocket2->x());
            double Yc = (double)(ui->Rocket2->y() - ui->me->y());
            if (Xc == 0) Xc = -1;
            if(Yc == 0) Yc = 1;
            double Dc = Yc / Xc;
            if(Dc > -0.414213) nom = 7;
            if(Dc<= - 0.414213 && Dc> - 2.414213) nom = 8;
            if(Dc<=-2.414213) nom = 1;
        }

        if(chetv==3)
        {
            double Xc = (double)(ui->me->x() - ui->Rocket2->x());
            double Yc = (double)(ui->Rocket2->y() - ui->me->y());
            if (Xc == 0) Xc = -1;
            if(Yc == 0) Yc = -1;
            double Dc = Yc / Xc;
            if(Dc < 0.414213) nom = 7;
            if(Dc>=0.414213 && Dc< 2.414213) nom = 6;
            if(Dc>=2.414213) nom = 5;
        }

        if(chetv==4)
        {
            double Xc = (double)(ui->me->x() - ui->Rocket2->x());
            double Yc = (double)(ui->Rocket2->y() - ui->me->y());
            if (Xc == 0) Xc = 1;
            if(Yc == 0) Yc = -1;
            double Dc = Yc / Xc;
            if(Dc > -0.414213) nom = 3;
            if(Dc<= - 0.414213 && Dc> - 2.414213) nom = 4;
            if(Dc<=-2.414213) nom = 5;
        }

        if(nom == 1){ui->Rocket2->setPixmap(QPixmap(":/fts/Rocket1.png"));}
        if(nom == 2){ui->Rocket2->setPixmap(QPixmap(":/fts/Rocket2.png"));}
        if(nom == 3){ui->Rocket2->setPixmap(QPixmap(":/fts/Rocket3.png"));}
        if(nom == 4){ui->Rocket2->setPixmap(QPixmap(":/fts/Rocket4.png"));}
        if(nom == 5){ui->Rocket2->setPixmap(QPixmap(":/fts/Rocket5.png"));}
        if(nom == 6){ui->Rocket2->setPixmap(QPixmap(":/fts/Rocket6.png"));}
        if(nom == 7){ui->Rocket2->setPixmap(QPixmap(":/fts/Rocket7.png"));}
        if(nom == 8){ui->Rocket2->setPixmap(QPixmap(":/fts/Rocket8.png"));}




        X1 = ui->me->x();
        Y1 = ui->me->y();
        X2 = ui->Rocket2->x();
        Y2 = ui->Rocket2->y();


        mx = (double)X1;
        my = (double)Y1;
        lx = (double)X2;
        ly = (double)Y2;

        dx = sqrt((lx-mx)*(lx-mx)) / sqrt((lx-mx)*(lx-mx) + (ly-my)*(ly-my)) * 15 ;

        dy = sqrt((ly-my)*(ly-my)) / sqrt((lx-mx)*(lx-mx) + (ly-my)*(ly-my)) * 15 ;





        if(lx - mx<=1 && lx-mx>=-1 && ly-my<=1 && ly - my >=-1) { dx = 0; dy = 0;}

        if(lx>=mx) dx*=-1;
        if(ly>=my) dy*=-1;

        Rock2GoX = (int) dx;
        Rock2GoY = (int) dy;

        rock2 = 0; Rock2go = 1;
    }
    }


    if(!pausa)
    {
    if(Rock2go)
    {
        ++Rock2GoCount;
        if(Rock2GoCount%5 == 0)
        {
            ui->Rocket2->setGeometry(ui->Rocket2->x() + 2*Rock2GoX, ui->Rocket2->y() + 2*Rock2GoY, ui->Rocket2->width(), ui-> Rocket2->height());
            Rock2GoCount = 0;
        }


        //если в полете есть касание то урон от ракеты
        int  bod_x = ui->Rocket2->x() + ui->Rocket2->width()/2 - ui->me->x() - ui->me->width()/2;
        int bod_y = ui->Rocket2->y() + ui->Rocket2->height()/2 - ui->me->y() - ui->me->height()/2;

        int storona = 60;

        if(bod_x>=-storona&&bod_x<=storona && bod_y>=-storona && bod_y<=storona)
        {
            rocket2_dmg = 1; Rock2go = 0;
            ui->Rocket2->setVisible(false); fireboom2 = 1;
            boomX2 = ui->me->x();
            boomY2 = ui->me->y();
            if(!achOshib){++achv; achOshib = 1;}

            m_player2->setSource(QUrl("qrc:/snd/sfxRocketBoom.mp3"));
            audiooutput2->setVolume(tr2);
            m_player2->play();
        }



        //если ракета промахнулась
        if(ui->Rocket2->x()<=0 || ui->Rocket2->y()<=0 || ui->Rocket2->x()>=width() || ui->Rocket2->y()>=height()) {Rock2go = 0; ui->Rocket2->setVisible(false); }
    }
    }


    //создание кольца огня
    if(!pausa)
    {
    if(fring)
    {
        ui->ring->setGeometry(ui->Levakov->x() - ui->Levakov->width()*3/2, ui->Levakov->y() - ui->Levakov->height()*3/2 , ui->ring->width(), ui->ring->height());
        ui->ring->setVisible(1); levakstay = 1; fring = 0; fringgo = 1;
        m_player2->setSource(QUrl("qrc:/snd/fire1.mp3"));
        audiooutput2->setVolume(tr2*0.2);
        m_player2->play();


    }
    }


    //кольцо огня взрыввается
    if(!pausa)
    {
    if(fringgo)
    {
        ++fringcount;
        if(fringcount == 200)
        {
            X1 = ui->me->x() + ui->me->width()/2 - ui->ring->x() - ui->ring->width()/2;
            Y1 = ui->me->y() + ui->me->height()/2 - ui->ring->y() - ui->ring->height()/2;
            if(X1<0) X1*=-1;
            if(Y1<0) Y1*=-1;
            if(X1*X1 + Y1*Y1 <= ui->ring->width() * ui->ring->width() /4) {fringdmg = 1; }
            fringgo = 0;
            fringcount = 0;
            ui->ring->setVisible(0);
            levakstay = 0;
            fringfire = 1;

            m_player2->setSource(QUrl("qrc:/snd/fire2.mp3"));
            audiooutput2->setVolume(tr2*0.2);
            m_player2->play();

        }







    }
    }

    if(!pausa)
    {
    //огненный взрыв
    if(fringfire)
    {
        ++fringfirecount;
        ui->Fire6->setGeometry(ui->ring->x(), ui->ring->y(), ui->ring->width(), ui->ring->height());
        ui->Fire6->setVisible(1);
        if(fringfirecount == 150) {fringfire = 0; fringfirecount = 0; ui->Fire6->setGeometry(1,1,ui->Fire1->width(), ui->Fire1->height()); ui->Fire6->setVisible(0);}
    }
    }



    //достижения

    if(achv && !achvgo && !pausa)
    {
        //текст и фото для Пригожина
        if(achPrigogin == 1 && !achvgo)
        {
            ui->achfoto->setPixmap(QPixmap(":/fts/prigogin.png"));
            ui->achtext->setText(QString("У нас нехватка боеприпасов 70%"));
            ui->achtext2->setText(QString("Попытка выстрелить без энергии  "));
            achvgo = 1; achPrigogin = 2; --achv;

            m_player4->setSource(QUrl("qrc:/snd/ach70Perc.mp3"));
            audiooutput4->setVolume(tr4);

        }

        //текст и фото для Кеннеди
        if(achKennedy == 1 && !achvgo)
        {
            ui->achfoto->setPixmap(QPixmap(":/fts/kennedy.png"));
            ui->achtext->setText(QString("Ох уж этот Кеннеди"));
            ui->achtext2->setText(QString("Попадание из снайперки  "));
            achvgo = 1; achKennedy = 2; --achv;

            m_player4->setSource(QUrl("qrc:/snd/achKennedy.mp3"));
            audiooutput4->setVolume(tr4);
        }

        //текст и фото для Ошибки Тинькова
        if(achOshib == 1 && !achvgo)
        {
            ui->achfoto->setPixmap(QPixmap(":/fts/oshibka.png"));
            ui->achtext->setText(QString("Я могу один раз ошибиться? "));
            ui->achtext2->setText(QString("Попадание ракетой  "));
            achvgo = 1; achOshib = 2; --achv;

            m_player4->setSource(QUrl("qrc:/snd/achTinkoff.mp3"));
            audiooutput4->setVolume(tr4*0.6);
        }


        //текст и фото при попадании в огонь
        if(achFire == 1 && !achvgo)
        {
            ui->achfoto->setPixmap(QPixmap(":/fts/hole.png"));
            ui->achtext->setText(QString("Fire In The Hole! "));
            ui->achtext2->setText(QString("Сожжён Адским пламенем  "));
            achvgo = 1; achFire = 2; --achv;

            m_player4->setSource(QUrl("qrc:/snd/achFireHole.mp3"));
            audiooutput4->setVolume(tr4);
        }


        //текст и фото для Промаха
        if(achPromah == 1 && !achvgo)
        {
            ui->achfoto->setPixmap(QPixmap(":/fts/promah.png"));
            ui->achtext->setText(QString("Надо больше заниматься! "));
            ui->achtext2->setText(QString("Промах при выстреле  "));
            achvgo = 1; achPromah = 2; --achv;

            m_player4->setSource(QUrl("qrc:/snd/levStudyMore.mp3"));
            audiooutput4->setVolume(tr4);
        }




        //текст и фото при вампиризме
        if(achVampire == 1 && !achvgo)
        {
            ui->achfoto->setPixmap(QPixmap(":/fts/vampirka.png"));
            ui->achtext->setText(QString("Это минус, но на самом деле плюс! "));
            ui->achtext2->setText(QString("Кража здоровья  "));
            achvgo = 1; achVampire = 2; --achv;

            m_player4->setSource(QUrl("qrc:/snd/levOooooo.mp3"));
            audiooutput4->setVolume(tr4);
        }



        ui->achfone->setVisible(1);
        ui->achfoto->setVisible(1);
        ui->achtext->setVisible(1);
        ui->achtext2->setVisible(1);
        m_player4->play();
    }

    //прсмотр доски достижений
    if(achvgo &&!pausa)
    {
        ++achvcount;
        if(achvcount>=1600)
        {
            achvgo = 0; achvcount = 0;

            ui->achfone->setVisible(0);
            ui->achfoto->setVisible(0);
            ui->achtext->setVisible(0);
            ui->achtext2->setVisible(0);
        }
    }



   // QPainter painter;
   // painter.begin(this);

    //рисовка радуги из синусоид
    /*painter.setRenderHint(QPainter::Antialiasing, true);
    painter.translate(width()/2,height()/2 + 50);
    QPoint point;
    painter.save();


           for(double j = -width()/60, i = -width() / 60; i < width() / 60; i += 0.01)

    {

        // будем растягивать ось Х в 30 раз поэтому делим на 30 значения
        j += 0.01;


        point.setX(j*30);
        QPen linepen(Qt::red);

        linepen.setWidth(2);
        painter.setPen(linepen);
        point.setY(a0*a1*sin(-(i)*2*M_PI/33)*60);
        painter.drawPoint(point);

        linepen.setColor(QColor(255,140,0));
        painter.setPen(linepen);
        point.setY(a0*a2*sin(-(i)*2*M_PI/33)*60);
        painter.drawPoint(point);

        linepen.setColor(Qt::yellow);
        painter.setPen(linepen);
        point.setY(a0*a3*sin(-(i)*2*M_PI/33)*60);
        painter.drawPoint(point);

        linepen.setColor(Qt::green);
        painter.setPen(linepen);
        point.setY(a0*a4*sin(-(i)*2*M_PI/33)*60);
        painter.drawPoint(point);

        linepen.setColor(Qt::blue);
        painter.setPen(linepen);
        point.setY(a0*a5*sin(-(i)*2*M_PI/33)*60);
        painter.drawPoint(point);

        linepen.setColor(QColor(0, 0, 139));
        painter.setPen(linepen);
        point.setY(a0*a6*sin(-(i)*2*M_PI/33)*60);
        painter.drawPoint(point);

        linepen.setColor(QColor(128, 0, 128));
        painter.setPen(linepen);
        point.setY(a0*a7*sin(-(i)*2*M_PI/33)*60);
        painter.drawPoint(point);

    }


    painter.restore();

*/






   // painter.end();

}








void MainWindow::on_continuebutton_clicked()
{
    escbutton_off = 1; pausa = 0;
    escbutton_off = 0;
    ui->pause_fon->setVisible(0);
    pausa = 0;

    ui->continuebutton->setVisible(0);

    ui->menubutton->setVisible(0);
    ui->continuebutton->setEnabled(0);

    ui->menubutton->setEnabled(0);
    ui->pausetext->setVisible(0);

    m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
    audiooutput3->setVolume(tr3);
    m_player3->play();

}


void MainWindow::on_menubutton_clicked()
{
    m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
    audiooutput3->setVolume(tr3);
    m_player3->play();

    menu2on =1;
    menu3on = 0;
    menu4on=0;
    pausa = 1;

    ui->menu2fone->setGeometry(0,0,width(), height());
    ui->menu2fone->setVisible(1);
    ui->version->setVisible(1);
    ui->menu2button->setVisible(1);
    ui->nameg1->setVisible(1);
    ui->nameg2->setVisible(1);
    ui->nameg3->setVisible(1);
    ui->testers->setVisible(1);
    ui->apenkicon->setVisible(1);
    ui->paraxicon->setVisible(1);
    ui->authoricon->setVisible(1);
    ui->iconfon1->setVisible(1);
    ui->iconfon2->setVisible(1);
    ui->vadimicon->setVisible(1);
    ui->iconfon3->setVisible(1);
    ui->booster->setVisible(1);
    ui->danikicon->setVisible(1);
    ui->iconfon4->setVisible(1);
    ui->exitbutton->setVisible(1);

    ui->version->setGeometry(width() * 99/100 - ui->version->width(), height() * 99/100 - ui->version->height(), ui->version->width(), ui->version->height());




    ui->menu2button->setGeometry(width() *45/100, height()*60/100, width() * 10/100, width() * 10/100 );




    ui->nameg1->setGeometry(width()/2 - ui->nameg1->width()/2, height() * 5/100, ui->nameg1->width(), ui->nameg1->height());
    ui->nameg2->setGeometry(width()/2 - ui->nameg2->width()/2, ui->nameg1->y() + ui->nameg1->height()*12/10, ui->nameg2->width(), ui->nameg2->height());
    ui->nameg3->setGeometry(width()/2 - ui->nameg3->width()/2, ui->nameg2->y() + ui->nameg1->height()*9/10, ui->nameg3->width(), ui->nameg3->height());







    ui->testers->setGeometry(width()*1/100,height()*55/100 , ui->testers->width(), ui->testers->height());



    ui->paraxicon->setGeometry(width()*3/100, height()*65/100, height()/10, height()/10);
    ui->iconfon1->setGeometry(ui->paraxicon->x() - 10, ui->paraxicon->y() - 10, ui->paraxicon->width()+20, ui->paraxicon->height() + 20);

    ui->apenkicon->setGeometry(ui->paraxicon->x() + height()/20 + height()/10, ui->paraxicon->y(), ui->paraxicon->width(), ui->paraxicon->height());
    ui->iconfon2->setGeometry(ui->apenkicon->x()-10, ui->apenkicon->y() - 10, ui->iconfon1->width(), ui->iconfon1->height());


    ui->booster->setGeometry(width() *3/100, height() *3/100, ui->booster->width(), ui->booster->height());
    ui->authoricon->setGeometry(width()*3/100 , height()*13/100, height()*3/10, height()*3/10);






    ui->vadimicon->setGeometry(ui->paraxicon->x(), height()  * 80/100, ui->paraxicon->width(), ui->paraxicon->height());
    ui->iconfon3->setGeometry(ui->vadimicon->x() - 10, ui->vadimicon->y() - 10, ui->vadimicon->width() + 20, ui->vadimicon->height() + 20);




    ui->danikicon->setGeometry(ui->apenkicon->x(), ui->vadimicon->y(), ui->vadimicon->width(), ui->vadimicon->height());
    ui->iconfon4->setGeometry(ui->danikicon->x()-10, ui->danikicon->y()-10, ui->danikicon->width()+20, ui->danikicon->height()+20);


    ui->exitbutton->setGeometry(width()*99/100-ui->exitbutton->width(), width() /100, ui->exitbutton->width(), ui->exitbutton->height());

     ui->menu2button->setIconSize(QSize(ui->menu2button->width(), ui->menu2button->width()));



}





void MainWindow::on_menu2button_clicked()
{
    menu2on = 0;
    menu3on = 1;

    ui->menu2fone->setVisible(0);

    m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
    audiooutput3->setVolume(tr3);
    m_player3->play();




    ui->menu2button->setVisible(0);
    ui->version->setVisible(0);
    ui->apenko->setVisible(0);
    ui->testers->setVisible(0);
    ui->apenkofone->setVisible(0);
    ui->authoricon->setVisible(0);
    ui->apenkicon->setVisible(0);
    ui->paraxicon->setVisible(0);
    ui->iconfon1->setVisible(0);
    ui->iconfon2->setVisible(0);
    ui->vadimicon->setVisible(0);
    ui->iconfon3->setVisible(0);
    ui->booster->setVisible(0);
    ui->danikicon->setVisible(0);
    ui->iconfon4->setVisible(0);
    ui->exitbutton->setVisible(0);
    ui->nameg1->setVisible(0);
    ui->nameg2->setVisible(0);
    ui->nameg3->setVisible(0);

    ui->bossicon->setVisible(1);
    ui->playericon->setVisible(1);
    ui->speedicon->setVisible(1);
    ui->healthicon->setVisible(1);
    ui->manaicon->setVisible(1);
    ui->vampireicon->setVisible(1);
    ui->gamego->setVisible(1);
    ui->menu3fone->setVisible(1);
    ui->ukaz->setVisible(1);
    ui->ukaz2->setVisible(1);
    ui->playericonfone->setVisible(1);
    ui->vers->setVisible(1);
    ui->buff->setVisible(1);
    ui->buff2->setVisible(1);
    ui->leftarrow->setVisible(1);
    ui->rightarrow->setVisible(1);

    ui->menu3fone->setGeometry(0,0,width(), height());
    ui->playericon->setGeometry(width() * 5/100, height() * 5/100, height() * 4/10, height() * 4/10);
    ui->speedicon->setGeometry(width()*2/100, height() /2, height()*10/100, height()*10/100);
    ui->healthicon->setGeometry(width() * 7/100 + ui->speedicon->width(), ui->speedicon->y(), ui->speedicon->width(), ui->speedicon->height());
    ui->manaicon->setGeometry(width()*12/100 + 2*ui->speedicon->width(), ui->speedicon->y(), ui->speedicon->width(), ui->speedicon->height());
    ui->ukaz->setGeometry(ui->speedicon->x(), ui->speedicon->y() + ui->speedicon->height()*12/10, ui->speedicon->width(), ui->speedicon->height()/2);
    ui->bossicon->setGeometry(width()*95/100 - height()*4/10, height()*5/100, height() * 4/10, height() * 4/10);
    ui->vampireicon->setGeometry(ui->bossicon->x(), ui->speedicon->y(), ui->speedicon->width(), ui->speedicon->height());
    ui->ukaz2->setGeometry(ui->vampireicon->x(), ui->ukaz->y(), ui->vampireicon->width(), ui->ukaz->height());
    ui->gamego->setGeometry(width()*9/10, height() - width()/10, width()/10,width()/10);
    ui->gamego->setIconSize(QSize(ui->gamego->width(), ui->gamego->height()));
    ui->playericonfone->setGeometry(ui->playericon->x() - 5, ui->playericon->y() - 5, ui->playericon->width()+10, ui->playericon->height()+10);
    ui->vers->setGeometry(width()*3/10, 0, width()*4/10, height());

    ui->buff->setGeometry(width()*2/100, height()*67/100, ui->buff->width(), ui->buff->height());

    ui->buff2->setGeometry(ui->vampireicon->x() - ui->buff2->width()*3/10 + ui->vampireicon->width()/2, ui->buff->y(), ui->buff2->width(), ui->buff2->height());

    ui->leftarrow->setGeometry(width()*2/100, ui->playericon->height()*3/10 + ui->playericon->y(), width()*2/100, ui->playericon->height()*4/10);
    ui->rightarrow->setGeometry(ui->playericon->x() +ui->playericon->x() - ui->leftarrow->x() - ui->leftarrow->width() + ui->playericon->width(), ui->leftarrow->y(), ui->leftarrow->width(), ui->leftarrow->height());

    if(ability == 1)
    {
        ui->ukaz->setGeometry(ui->speedicon->x(), ui->ukaz->y(), ui->ukaz->width(), ui->ukaz->height());
    }

    if(ability == 2)
    {
        ui->ukaz->setGeometry(ui->healthicon->x(), ui->ukaz->y(), ui->ukaz->width(), ui->ukaz->height());
    }

    if(ability == 3)
    {
        ui->ukaz->setGeometry(ui->manaicon->x(), ui->ukaz->y(), ui->ukaz->width(), ui->ukaz->height());
    }
}


void MainWindow::on_exitbutton_clicked()
{
    MainWindow::close();
}


void MainWindow::on_gamego_clicked()
{
    menu1on = 0;
    menu2on = 0;
    menu3on = 0;
    menu4on = 1;

    m_player3->setSource(QUrl("qrc:/snd/sfxClick.mp3"));
    audiooutput3->setVolume(tr3);
    m_player3->play();

    ui->bossicon->setVisible(0);
    ui->playericon->setVisible(0);
    ui->speedicon->setVisible(0);
    ui->healthicon->setVisible(0);
    ui->manaicon->setVisible(0);
    ui->vampireicon->setVisible(0);
    ui->gamego->setVisible(0);
    ui->menu3fone->setVisible(0);
    ui->ukaz->setVisible(0);
    ui->ukaz2->setVisible(0);
    ui->playericonfone->setVisible(0);
    ui->vers->setVisible(0);
    ui->buff->setVisible(0);
    ui->buff2->setVisible(0);
    ui->leftarrow->setVisible(0);
    ui->rightarrow->setVisible(0);


    if(iconnom == 1) {ui->me->setPixmap(QPixmap(":/fts/ic1.png"));}
    if(iconnom == 2) {ui->me->setPixmap(QPixmap(":/fts/ic2.png"));}
    if(iconnom == 3) {ui->me->setPixmap(QPixmap(":/fts/ic3.png"));}
    if(iconnom == 4) {ui->me->setPixmap(QPixmap(":/fts/ic4.png"));}
    if(iconnom == 5) {ui->me->setPixmap(QPixmap(":/fts/ic5.png"));}
    if(iconnom == 6) {ui->me->setPixmap(QPixmap(":/fts/ic6.png"));}
    if(iconnom == 7) {ui->me->setPixmap(QPixmap(":/fts/ic7.png"));}
    if(iconnom == 8) {ui->me->setPixmap(QPixmap(":/fts/ic8.png"));}
    if(iconnom == 9) {ui->me->setPixmap(QPixmap(":/fts/ic9.png"));}
    if(iconnom == 10) {ui->me->setPixmap(QPixmap(":/fts/ic10.png"));}
    if(iconnom == 11) {ui->me->setPixmap(QPixmap(":/fts/ic11.png"));}
    if(iconnom == 12) {ui->me->setPixmap(QPixmap(":/fts/ic12.png"));}
    if(iconnom == 13) {ui->me->setPixmap(QPixmap(":/fts/ic13.png"));}
    if(iconnom == 14) {ui->me->setPixmap(QPixmap(":/fts/ic14.png"));}
    if(iconnom == 15) {ui->me->setPixmap(QPixmap(":/fts/ic15.png"));}
    if(iconnom == 16) {ui->me->setPixmap(QPixmap(":/fts/ic16.png"));}
    if(iconnom == 17) {ui->me->setPixmap(QPixmap(":/fts/ic17.png"));}
    if(iconnom == 18) {ui->me->setPixmap(QPixmap(":/fts/ic18.png"));}
    if(iconnom == 19) {ui->me->setPixmap(QPixmap(":/fts/ic19.png"));}
    if(iconnom == 20) {ui->me->setPixmap(QPixmap(":/fts/ic20.png"));}

    ui->me->setGeometry(width()*1/100, height()*99/100, ui->me->width(), ui->me->height());
    ui->Levakov->setGeometry(width() - ui->Levakov->width(), 0, ui->Levakov->width(), ui->Levakov->height());




    FrCount = 0; //кадровка движений левакова
    RockCount = 0;//событие ракета
    verh = 0;
    vpravo = 0;
    najato = 0;



     RockTime = 0; //начало обстрел ракетами
     RockGo = 0; //ракеты летят
     RockGoX = 0;
     RockGoY = 0;//вектора изменения координаты ракеты в полете
     RockGoCount = 0; //кадровка ракеты

    health = 100;
    health_regen = 0;
     levakov_health = 150;
     mana_count = 0;
     mana = 100;
     life = 1;

     body_dmg = 0;
     rocket_dmg = 0;
     fireboom = 0;
     boomcount = 0;
     boomX = 0;
     boomY = 0;
     immune = 0;


     vistrelGo = 0;
     bullgox = 0;
     bullgoy = 0;
     bullgocount = 0;
    bull_dmg = 0;
    pricel_vis = 0;

     rock2 = 0;
     Rock2go = 0;
     Rock2GoCount = 0;
     Rock2GoX = 0;
     Rock2GoY = 0;
     boomX2 = 0;
     boomY2 = 0;
     fireboom2 = 0;
     boomcount2 = 0;
     rocket2_dmg = 0;

     fring = 0;
     fringgo = 0;
     fringcount = 0;
     fringdmg = 0;
     levakstay = 0;
     fringfire = 0;
     fringfirecount = 0;

     achv = 0;
     achvgo = 0;
     achvcount = 0;

     achPrigogin = 0;
     achKennedy = 0;
     achOshib = 0;
     achPromah = 0;
     achFire = 0;
     achVampire = 0;

     escbutton = 0;
     escbutton_off = 0;
     pausa = 0;
     vampire = 1;

     ui->pause_fon->setVisible(0);


     ui->continuebutton->setVisible(0);
     //ui->Exitbutton->setVisible(0);
     ui->menubutton->setVisible(0);
     ui->continuebutton->setEnabled(0);
     //ui->Exitbutton->setEnabled(0);
     ui->menubutton->setEnabled(0);
     //MainWindow::showFullScreen();
     ui->pausetext->setVisible(0);

     ui->Fire1->setVisible(0);
     ui->Fire2->setVisible(0);
     ui->Fire3->setVisible(0);
     ui->Fire4->setVisible(0);
     ui->Fire5->setVisible(0);
     ui->Fire6->setVisible(0);
     ui->bullet->setVisible(0);
     ui->Rocket2->setVisible(0);
     ui->ring->setVisible(0);
     ui->pause_fon->setVisible(0);
     ui->menu2fone->setVisible(0);
     ui->menu2button->setVisible(0);
     ui->version->setVisible(0);

     ui->pricel->setVisible(0);

     ui->achfone->setVisible(0);
     ui->achfoto->setVisible(0);
     ui->achtext->setVisible(0);
     ui->achtext2->setVisible(0);

     ui->continuebutton->setVisible(0);

     ui->menubutton->setVisible(0);
     ui->continuebutton->setEnabled(0);


}

