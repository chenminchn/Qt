#include "mycreatelistwid.h"
#include <QVBoxLayout>
#include "switchpagebutton.h"
#include "leftdownwid.h"

MyCreateListWid::MyCreateListWid(QWidget *parent)
	: BaseWidget(parent)
{
	pWid = dynamic_cast<LeftDownWid*>(parent);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	QVBoxLayout *vMyCreateLayout = new QVBoxLayout;
	vMyCreateLayout->setSpacing(10);
	setLayout(vMyCreateLayout);
}

MyCreateListWid::~MyCreateListWid()
{
}

void MyCreateListWid::slot_createList()
{
	SongListButton* newList = new SongListButton(this);
	m_myCreateList.push_front(newList);
	for (int i = 0; i < m_myCreateList.count(); i++)
	{
		layout()->addWidget(m_myCreateList[i]);
		connect(m_myCreateList[i], SIGNAL(clicked()), this, SLOT(oneBtnClicked()));
		connect(m_myCreateList[i], SIGNAL(clicked()), pWid, SLOT(setPressedButton()));
	}
	update();

}

void MyCreateListWid::slot_foldingLists()
{
	if (isHidden())
	{
		show();
		update();
	}
	else
		hide();
}

void MyCreateListWid::oneBtnClicked()
{
	SongListButton *button = qobject_cast<SongListButton*>(sender());
	for (int i = 0; i < m_myCreateList.count(); i++)
	{
		if (button == m_myCreateList[i])
			m_myPressedBtn = button;
	}
}
