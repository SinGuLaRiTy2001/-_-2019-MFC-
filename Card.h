// Card.h: interface for the CCard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARD_H__8F32DC02_B4CF_4CFE_96DF_C51EDA634070__INCLUDED_)
#define AFX_CARD_H__8F32DC02_B4CF_4CFE_96DF_C51EDA634070__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCard  
{
public:
	CCard();
	virtual ~CCard();
	int Suit;              //��ɫ 
    char Number;            //���� 
    double Num;               //��Ϸ�еĵ��� 
	void operator=(CCard);

};

#endif // !defined(AFX_CARD_H__8F32DC02_B4CF_4CFE_96DF_C51EDA634070__INCLUDED_)
