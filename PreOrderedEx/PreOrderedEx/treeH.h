#include<iostream>
#include<math.h>
#include<crtdbg.h>
#include"setting.h"

#ifndef _DEBUG
#define new new(_CLIENT_BLOCK,_FILE_,_LINE)
#endif
using namespace std;

class Node{
public:
	char  m_data;
	Node* m_leftH;
	Node* m_rightH;
public:
	Node();
};

Node::Node()
{
	m_data ='\0';
	m_leftH = nullptr;
	m_rightH = nullptr;
}


//���� �Լ��� �����?
//1. ��带 ����� �����͸� ä��
Node* MakeTreeEntity(int nodeNumber)
{
	Node *idxNode = new Node[nodeNumber];
	//data ���� ���� 
	for(int i=0;i<nodeNumber;i++)
	{
		idxNode[i].m_data = 'A'+i;
		
	}
	return idxNode;
}

//2. ������� ������ �������ִ� �Լ�
void LinkTreeEntity(Node *nodes, int nodeN, int levelN)
{
	int *leftCnt = new int[levelN];
	int *rightCnt= new int[levelN];
	//�� ������ ���� ���� �ش�.
	for(int i=0; i<nodeN;i++)
	{
		if(i<levelN-1)
		{
			leftCnt[i] = (int)pow(2,i);
			rightCnt[i]= (int)pow(2,i+1);
		}
	}

	int gCMax=1;
	for(int i=1; i<levelN-1; i++)
	{
		gCMax += (int)pow(2,i);
		
	}
	cout << "gCMax :" << gCMax <<endl;
	
	int *gapArray = new int[gCMax];
	//gap array
	for(int i=0; i<gCMax-1;i++)
	{
		if(i%2)
		{
			gapArray[i] = 1;
		}else{
			gapArray[i] =0;
		}
	}


	//������ ��������
	for(int i=0;i<levelN;i++)
	{
		switch(i)
		{
		case 0:
			//���� ��� ����
			nodes[i].m_leftH = &nodes[leftCnt[i]];
			nodes[i].m_rightH= &nodes[rightCnt[i]];
			break;

		case 1:
			//���� ��� ����
			//cout <<"lectCnt :" <<leftCnt[i]<<endl;
			//cout <<"rightCnt:" <<rightCnt[i]<<endl;
			for(int in=0; in<levelN-1;in++)
			{
				//1,2,4,8
				cout << "index: "<< leftCnt[in] <<endl;
				
			//	nodes[leftCnt[in]].m_leftH = &nodes[leftCnt[in]+i];
			//	nodes[leftCnt[in]].m_rightH= &nodes[leftCnt[in]+i+gapArray[in]];
				



			}


			break;

		case 2:
			//������ ��� ���� 
			break;
		}
	}





	//right side : 2,4,8,...
	

	delete [] gapArray;
	delete [] leftCnt;
	delete [] rightCnt;
	delete [] nodes;
}

//3. ������� ��带 ��ġ�ϴ� �Լ�

//4. ����� ������ִ� �Լ� 