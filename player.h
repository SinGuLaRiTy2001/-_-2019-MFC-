// player.h: interface for the player class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYER_H__21C4760F_44E4_46A1_B229_37D06DF304C1__INCLUDED_)
#define AFX_PLAYER_H__21C4760F_44E4_46A1_B229_37D06DF304C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Card.h"

class player  
{
public:
	player();
	virtual ~player();
	CString  name;
	CCard a[5];
	double score;     //�÷�
	double dian;     //�Ƶ�
	int num;        //������
	double Power;        //�ܵ÷�
	int rank;
	int add;
	void Dian();        //�����Ƶ�
	bool operator>(player a);       //>����
	bool operator>(double a);
	bool operator<(player a);          //<����
	bool operator<(double a);
	bool operator==(player a);        //==����
	bool operator==(double a);
	bool operator>=(double a);
	void operator=(player);

};

#endif // !defined(AFX_PLAYER_H__21C4760F_44E4_46A1_B229_37D06DF304C1__INCLUDED_)
