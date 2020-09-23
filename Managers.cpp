// Managers.cpp: implementation of the CManagers class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Legend.h"
#include "Managers.h"
#include "player.h"
#include"People.h"
#include"Sign.h"
#ifdef _DEBUG
#undef THIS_FILE

#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Managers::Managers()
{
	count=0;
	int i,temp;
	int suit1;
	suit1=1;
    for(i=0;i<52;i++)                //����52���� 
    {
        if(i%13==0)
            suit1++;                //�ı仨ɫ 
        card1[i].Suit=suit1;           //���滨ɫ 
        temp=i%13;
        if(temp==0)
            card1[i].Number='A';
        else if(temp==9)
            card1[i].Number='T';
        else if(temp==10)
            card1[i].Number='J';
        else if(temp==11)
            card1[i].Number='Q';
        else if(temp==12)
            card1[i].Number='K';
        else 
            card1[i].Number=temp+'1';//����û������
        if(temp>=9)                      //�Ƶ�
            card1[i].Num=0.5;
        else
            card1[i].Num=temp+1.0;
    }

	for(i=0;i<4;i++)
		play[i].add=i;
	Player=0;

}

Managers::~Managers()
{

}



//////////////////////////////////////////////////////////////////////
// Managers Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void Managers::GameStart(){
//	if(ready)
//	{
	Shuffle();
//	Deal();
//	RankShow();

//	}
}

void Managers::Shuffle()               //ϴ��
{ 
    int i,j;
    CCard tempcard;
    srand(time(NULL));
    for(i=0;i<52;i++)
    {
        j=rand()%52;              
        tempcard=card1[j];
        card1[j]=card1[i];
        card1[i]=tempcard;        //�����������ƣ�ִ��52�Σ��൱��ϴ��
    }
}
bool Managers::Deal(){              //��˳���� 
	int i,j;
	      //��52����û�����һֱ����
		CSign sign;
		sign.DoModal();           //�����Ի���
		play[0].num=sign.Num;
		j=(count+play[0].num);
		if(j<=52){  //�ж�һ����Ҫ��������������ʣ�µ�������
			for(i=0;i<play[0].num;i++){
				j=i+count;
				play[0].a[i]=card1[j];
			}
			count=count+play[0].num;
			for(;i<5;i++){
				play[0].a[i].Num =0;
				play[0].a[i].Number='0';
				play[0].a[i].Suit=0;
			}
			play[0].Dian();
		}
		else {
			MessageBox(NULL,TEXT("�Ʋ���������Ϸ�����ˣ�"),TEXT("HALF PAST TEN"),MB_OK);//MessageBox("�Ʋ���������Ϸ�����ˣ�");
			//MessageBox(NULL,"�Ʋ���������Ϸ�����ˣ�","OK",MB_ABORTRETRYIGNORE);              //�Ʋ�������Ϸ����
			int flag=MessageBox(NULL,TEXT("�Ƿ�����һ��"),TEXT("HALF PAST TEN"),MB_OKCANCEL);
			if(flag==IDOK){
				count=0;
				return 1;
				//DoPreparePrinting(pInfo);
			}//�˴�����Ƿ�����һ��
			else return 0;
		}
		sign.DoModal();           //�����Ի���
		play[1].num=sign.Num;
		j=(count+play[1].num);
		if(j<=52){
			for(i=0;i<play[1].num;i++){
				j=i+count;
				play[1].a[i]=card1[j];
			}
			count=count+play[1].num;
			for(;i<5;i++){
				play[1].a[i].Num =0;
				play[1].a[i].Number='0';
				play[1].a[i].Suit=0;
			}
			play[1].Dian();

		}
		else {
			MessageBox(NULL,TEXT("�Ʋ���������Ϸ�����ˣ�"),TEXT("HALF PAST TEN"),MB_OK);
		//MessageBox(NULL,"�Ʋ���������Ϸ�����ˣ�","OK",MB_ABORTRETRYIGNORE);             //�Ʋ�������Ϸ����;
			int flag=MessageBox(NULL,TEXT("�Ƿ�����һ��"),TEXT("HALF PAST TEN"),MB_OKCANCEL);
			if(flag==IDOK){
				count=0;
				return 1;
				//DoPreparePrinting(pInfo);
			}
			//�˴�����Ƿ�����һ��
			else return 0;
		}

		if(Player>=3){ 		
			sign.DoModal();           //�����Ի���
			play[2].num=sign.Num;
			j=(count+play[2].num);
			if(j<=52){
				for(i=0;i<play[2].num;i++){
					j=i+count;
					play[2].a[i]=card1[j];
				}
				count=count+play[2].num;
				for(;i<5;i++){
					play[2].a[i].Num =0;
					play[2].a[i].Number='0';
					play[2].a[i].Suit=0;
				}
				play[2].Dian();

			}
			else {
				MessageBox(NULL,TEXT("�Ʋ���������Ϸ�����ˣ�"),TEXT("HALF PAST TEN"),MB_OK);
				//MessageBox(NULL,"�Ʋ���������Ϸ�����ˣ�","OK",MB_ABORTRETRYIGNORE);              //�Ʋ�������Ϸ����
				int flag=MessageBox(NULL,TEXT("�Ƿ�����һ��"),TEXT("HALF PAST TEN"),MB_OKCANCEL);
				if(flag==IDOK){
					count=0;
					return 1;
					//DoPreparePrinting(pInfo);
				}
				//�˴�����Ƿ�����һ��
				else return 0;
			}
		}

		if(Player>=4){            
			CSign dlg;                          //�����Ի���
			dlg.DoModal();
			play[3].num=dlg.Num;
			j=(count+play[3].num);
			if(j<=52){
				for(i=0;i<play[3].num;i++){
					j=i+count;
					play[3].a[i]=card1[j];
				}
				count=count+play[3].num;
				for(;i<5;i++){
					play[3].a[i].Num=0;
					play[3].a[i].Number='0';
					play[3].a[i].Suit=0;
				}
				play[3].Dian();
			}
			else {
				MessageBox(NULL,TEXT("�Ʋ���������Ϸ�����ˣ�"),TEXT("HALF PAST TEN"),MB_OK);
			//MessageBox(NULL,"�Ʋ���������Ϸ�����ˣ�","OK",MB_ABORTRETRYIGNORE);             //�Ʋ�������Ϸ����
				int flag=MessageBox(NULL,TEXT("�Ƿ�����һ��"),TEXT("HALF PAST TEN"),MB_OKCANCEL);
				if(flag==IDOK){
					count=0;
					return 1;
					//DoPreparePrinting(pInfo);
				}
				//�˴�����Ƿ�����һ��
				else return 0;
			}
		}

		if(count==52)
		{
			MessageBox(NULL,"�Ʋ���������Ϸ�����ˣ�","HALF PAST TEN",MB_OK);              //�Ʋ�������Ϸ����
			int flag=MessageBox(NULL,TEXT("�Ƿ�����һ��"),TEXT("HALF PAST TEN"),MB_OKCANCEL);
				if(flag==IDOK){
					count=0;
					return 1;
					//DoPreparePrinting(pInfo);
				}
				//�˴�����Ƿ�����һ��
				else return 0;
		}
		Calculate();            //ÿһ�ֶ�ʵʱ����÷�
		//MessageBox(NULL,"��ʾ�ƣ�","HALF PAST TEN",MB_OK); 
	//	CardShow();
	//	RankShow();
}
//����

void Managers::BubbleSort(){                   
	bool noswap;
	int i,j;
	player temp;
	for(i=0;i<Player-1;i++){
		noswap=true;
		for(j=Player-1;j>i;j--){
			if(play[j].Power>play[j-1].Power){
				temp=play[j];
				play[j]=play[j-1];
				play[j-1]=temp;
				noswap=false;
			}
		}
		if(noswap)break;
	}
}

void Managers::Add_BubbleSort(){
	bool noswap;
	int i,j;
	player temp;
	for(i=0;i<Player-1;i++){
		noswap=true;
		for(j=Player-1;j>i;j--){
			if(play[j].add<play[j-1].add){
				temp=play[j];
				play[j]=play[j-1];
				play[j-1]=temp;
				noswap=false;
			}
		}
		if(noswap)break;
	}
}

void Managers::Ranking(){
	int rank1 = 1;	
	//�����һ�� 
	play[0].rank=rank1;
	for(int i = 1;i< Player;i++){		
		if( i>=1 && play[i].Power == play[i-1].Power){
			play[i].rank=rank1;
		}
		else{
			rank1 = i+1;
			play[i].rank=rank1;
		}
	} 
}

void Managers::Calculate(){
	if(Player==2){//��������Ϸ
		double aa=0,bb=0;
		if(play[1] <10.5&&play[0]<10.5 ){//����������10.5
			if(play[1]  >play[0]  ) { aa =2;bb=1;}
			else if(play[1]==play[0] ) { 
				aa =0.5;
				bb =0.5;
			}
			else  {aa =1;bb=2;}
		}
		else if(play[1]>=10.5&&play[0]<10.5){
			if(play[1]==10.5){aa=3;
			bb=1;}
			else {aa=0;bb=2;}
		}
		if(play[0]>=10.5&&play[1]<10.5){
			if(play[0]==10.5) {bb=3;
			aa=1;}
			else {bb=0;aa=2;}
		}//ֻ��һ������10.5
		if(play[1].num==5&&play[1]==2.5)
			aa=5;
		if(play[0].num==5&&play[0]==2.5)
			bb=5;
		if(play[1]>10.5&&play[0]>10.5){
			aa=0;
			bb=0;
		}
		if(play[1]==10.5&&play[0]==10.5){
			aa=3;
			bb=3;
		}
		play[1].Power+=aa;
		play[0].Power+=bb;
		play[1].score=aa;
		play[0].score=bb;
	}
	if(Player>=3){
		bool noswap;
		int i,j;
		player temp;
		for(i=0;i<Player;i++)
		{
			if(play[i].dian>10.5)
				play[i].dian=-1;
		}
		for(i=0;i<Player-1;i++){
			noswap=true;
			for(j=Player-1;j>i;j--){
				if(play[j].dian>play[j-1].dian){
					temp=play[j];
					play[j]=play[j-1];
					play[j-1]=temp;
					noswap=false;
				}
			}
			if(noswap)break;
		}

		int rank1 = 1;	
		play[0].rank=rank1;
		for(i = 1;i< Player;i++){
			if( i>=1 && play[i].dian == play[i-1].dian){
				play[i].rank=rank1;
			}
			else{
				rank1 = i+1;
				play[i].rank=rank1;
			}
		} 

	for(i=0;i<Player;i++){
			play[i].score=4-play[i].rank;
			if(play[i].dian==-1){
				play[i].score=0;
			}
			play[i].Power+=play[i].score;
			
		}

		BubbleSort();
		Ranking();
		Add_BubbleSort();
	}
}

