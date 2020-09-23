// Managers.h: interface for the CManagers class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGERS_H__146340EA_9401_403F_AFAF_09AB1C0559DA__INCLUDED_)
#define AFX_MANAGERS_H__146340EA_9401_403F_AFAF_09AB1C0559DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"player.h"
#include "stdafx.h"

#include"People.h"
#include"Sign.h"
#include"LegendDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

class Managers  
{
public:
	Managers();
	int Player;
	virtual ~Managers();
	CCard card1[52];
	void GameStart();   //��Ϸ��ʼ�������ơ�
	player play[4];
	void Shuffle();               //ϴ�� 
	bool Deal();                   //��˳����
	void BubbleSort();       //����
	void Add_BubbleSort();    //��ԭ˳��
	void Ranking();          //����
	void Calculate();         //����÷�
	int count;
	

};

#endif // !defined(AFX_MANAGERS_H__146340EA_9401_403F_AFAF_09AB1C0559DA__INCLUDED_)
