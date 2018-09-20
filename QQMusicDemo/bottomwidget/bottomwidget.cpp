#pragma execution_character_set("utf-8")

#include "bottomwidget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include "basewidget.h"
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QGridLayout>
#include "mybutton.h"
#include <QDebug>


BottomWidget::BottomWidget(QWidget *parent):BaseWidget(parent)
{
	setMinimumHeight(69);
	//setMinimumWidth(1010);
	setMouseTracking(true);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	setStyleSheet(
		"BaseWidget{background:rgb(247,247,248);}"
		"QPushButton,QLabel{color:rgb(73,73,73);font-family:'Microsoft YaHei';}"
	);
	//setStyleSheet("QPushButton,QLabel{color:rgb(73,73,73);}");

	QHBoxLayout *mainLayout = new QHBoxLayout;

	BaseWidget *leftWid = new BaseWidget(this);
	leftWid->setMinimumWidth(200);
	leftWid->setMaximumWidth(234);
	leftWid->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
	QHBoxLayout *leftLayout = new QHBoxLayout;

	QPushButton *btnPreSong = new QPushButton(leftWid);
	QPushButton *btnPlay = new QPushButton(leftWid);
	QPushButton *btnNextSong = new QPushButton(leftWid);

	btnPreSong->setFixedSize(35, 35);
	btnPlay->setFixedSize(45, 45);
	btnNextSong->setFixedSize(35, 35);

	btnNextSong->setFlat(true);
	btnPlay->setFlat(true);
	btnNextSong->setFlat(true);

	btnPreSong->setStyleSheet(
		"QPushButton{background:transparent;border-image:url(:/images/bottomwidget/btn_presong(1).png);}"
		"QPushButton::hover,QPushButton::pressed{border-image:url(:/images/bottomwidget/btn_presong(2).png);}"
	);
	btnPlay->setStyleSheet(
		"QPushButton{background:transparent;border-image:url(:/images/bottomwidget/btn_play(1).png);}"
		"QPushButton::hover,QPushButton::pressed{border-image:url(:/images/bottomwidget/btn_play(2).png);}"
	);
	btnNextSong->setStyleSheet(
		"QPushButton{background:transparent;border-image:url(:/images/bottomwidget/btn_nextsong(1).png);}"
		"QPushButton::hover,QPushButton::pressed{border-image:url(:/images/bottomwidget/btn_nextsong(2).png);}"
	);

	leftLayout->addWidget(btnPreSong);
	leftLayout->addWidget(btnPlay);
	leftLayout->addWidget(btnNextSong);
	leftWid->setLayout(leftLayout);

	BaseWidget *rightWid = new BaseWidget(this);
	//rightWid->setMinimumWidth(810);
	QHBoxLayout *rightLayout = new QHBoxLayout;

	SongDetailButton *btnSongDetail = new SongDetailButton(this);

	QPushButton *btnQuality = new QPushButton(this);
	btnQuality->setFixedSize(46, 20);
	btnQuality->setFlat(true);
	btnQuality->setStyleSheet(
		"QPushButton{background:transparent;border-image:url(:/images/bottomwidget/btn_standard(1).png);}"
		"QPushButton::hover{border-image:url(:/images/bottomwidget/btn_standard(2).png);}"
	);


	QPushButton *btnSoundEffect = new QPushButton(this);
	btnSoundEffect->setFixedSize(46, 20);
	btnSoundEffect->setFlat(true);
	btnSoundEffect->setStyleSheet(
		"QPushButton{background:transparent;border-image:url(:/images/bottomwidget/btn_soundeffect(1).png);}"
		"QPushButton::hover{border-image:url(:/images/bottomwidget/btn_soundeffect(2).png);}"
	);

	MyPushButton *btnSongName = new MyPushButton(this);
	btnSongName->setFlat(true);
	btnSongName->setText("Î÷ºþ");
	btnSongName->setStyleSheet("QPushButton{margin-left:0px;margin-right:0px;}");


	QLabel *symbol = new QLabel("-", this);
	symbol->setFixedSize(10, 10);
	symbol->setAlignment(Qt::AlignCenter);

	MyPushButton *btnPlayer = new MyPushButton(this);
	btnPlayer->setFlat(true);
	btnPlayer->setText("Í´ÑöÀÖ¶Ó");
	btnPlayer->setStyleSheet("QPushButton{margin-left:0px;margin-right:0px;}");

	QLabel *btnMV = new QLabel("MV");

	QLabel *label_playedTime = new QLabel(this);
	label_playedTime->setFixedSize(35, 15);
	label_playedTime->setText("01:58");

	QLabel *label_Slash = new QLabel("/", this);
	label_Slash->setFixedSize(5, 15);

	QLabel *totalTime = new QLabel("03:00", this);
	label_playedTime->setFixedSize(35, 15);
	label_playedTime->setText("01:58");

	QProgressBar *playProgress = new QProgressBar(this);
	//playProgress->setMinimumWidth(0);
	playProgress->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	playProgress->setStyleSheet(
		"QProgressBar{border:none;max-height:2px;background:rgb(222,222,222);color:rgb(49,194,124);}"
		"QProgressBar::chunk{background-color:rgb(49,194,124);border:none;width:2px;}"
	);

	QPushButton *btnILike = new QPushButton(this);
	QPushButton *btnDownLoad = new QPushButton(this);
	QPushButton *btnMore = new QPushButton(this);
	QPushButton *btnLyrics = new QPushButton(this);
	QPushButton *btnRepeatMode = new QPushButton(this);
	QPushButton *btnVolume = new QPushButton(this);
	QPushButton *btnPlayingList = new QPushButton(this);

	btnILike->setFixedSize(20, 20);
	btnDownLoad->setFixedSize(20, 20);
	btnMore->setFixedSize(20, 20);
	btnLyrics->setFixedSize(20, 20);
	btnRepeatMode->setFixedSize(20, 20);
	btnVolume->setFixedSize(20, 20);
	btnPlayingList->setFixedSize(40, 20);

	btnILike->setFlat(true);
	btnDownLoad->setFlat(true);
	btnMore->setFlat(true);
	btnLyrics->setFlat(true);
	btnRepeatMode->setFlat(true);
	btnVolume->setFlat(true);
	btnPlayingList->setFlat(true);

	btnILike->setStyleSheet(
		"QPushButton{border-image:url(:/images/bottomwidget/btn_ilike(1).png);}"
		"QPushButton::hover{border-image:url(:/images/bottomwidget/btn_ilike(2).png);}"
	);
	btnDownLoad->setStyleSheet(
		"QPushButton{border-image:url(:/images/bottomwidget/btn_download(1).png);}"
		"QPushButton::hover{border-image:url(:/images/bottomwidget/btn_download(2).png);}"
	);
	btnMore->setStyleSheet(
		"QPushButton{border-image:url(:/images/bottomwidget/btn_more(1).png);}"
		"QPushButton::hover{border-image:url(:/images/bottomwidget/btn_more(2).png);}"
	);
	btnLyrics->setStyleSheet(
		"QPushButton{border-image:url(:/images/bottomwidget/btn_lyrics(1).png);}"
		"QPushButton::hover{border-image:url(:/images/bottomwidget/btn_lyrics(2).png);}"
	);
	btnRepeatMode->setStyleSheet(
		"QPushButton{border-image:url(:/images/bottomwidget/btn_repeatmode(1).png);}"
		"QPushButton::hover{border-image:url(:/images/bottomwidget/btn_repeatmode(2).png);}"
	);
	btnVolume->setStyleSheet(
		"QPushButton{border-image:url(:/images/bottomwidget/btn_volume(1).png);}"
		"QPushButton::hover{border-image:url(:/images/bottomwidget/btn_volume(2).png);}"
	);
	
	btnPlayingList->setStyleSheet(
		"QPushButton{border-image:url(:/images/bottomwidget/btn_playinglist(1).png);color:#6A6A6A;text-align:right;}"
		"QPushButton::hover{border-image:url(:/images/bottomwidget/btn_playinglist(2).png);color:#31C27C;}"
	);
	btnPlayingList->setText("16");
	//btnPlayingList->

	rightWid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QGridLayout *gLayout = new QGridLayout;
	gLayout->addWidget(btnSongDetail, 0, 0, 2, 1);
	gLayout->addWidget(btnQuality, 0, 1, 1, 1);
	gLayout->addWidget(btnSoundEffect, 1, 1, 1, 1);
	gLayout->setSpacing(0);
	gLayout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout *hLayout1 = new QHBoxLayout;
	hLayout1->addWidget(btnSongName);
	hLayout1->addWidget(symbol);
	hLayout1->addWidget(btnPlayer);
	hLayout1->addStretch();
	hLayout1->addWidget(label_playedTime);
	hLayout1->addWidget(label_Slash);
	hLayout1->addWidget(totalTime);
	hLayout1->setSpacing(0);
	hLayout1->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout *vLayout2 = new QVBoxLayout;
	vLayout2->addLayout(hLayout1);
	vLayout2->addWidget(playProgress);
	vLayout2->addSpacing(10);
	vLayout2->setSpacing(0);
	vLayout2->setContentsMargins(0, 0, 0, 10);

	QHBoxLayout *hLayout2 = new QHBoxLayout;
	hLayout2->addWidget(btnILike);
	hLayout2->addWidget(btnDownLoad);
	hLayout2->addWidget(btnMore);
	hLayout2->addWidget(btnLyrics);
	hLayout2->addWidget(btnRepeatMode);
	hLayout2->addWidget(btnVolume);
	hLayout2->addWidget(btnPlayingList);
	hLayout2->setSpacing(10);
	hLayout2->setContentsMargins(0, 0, 0, 0);

	rightLayout->addLayout(gLayout);
	rightLayout->addSpacing(20);
	rightLayout->addLayout(vLayout2);
	rightLayout->addSpacing(30);
	rightLayout->addLayout(hLayout2);
	rightLayout->setSpacing(0);
	rightLayout->setContentsMargins(0, 0, 0, 0);
	rightWid->setLayout(rightLayout);

	mainLayout->addWidget(leftWid);
	mainLayout->addWidget(rightWid);
	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 20, 0);
	setLayout(mainLayout);
}