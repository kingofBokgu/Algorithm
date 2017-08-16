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


//전역 함수로 만들어?
//1. 노드를 만들어 데이터를 채움
Node* MakeTreeEntity(int nodeNumber)
{
	Node *idxNode = new Node[nodeNumber];
	//data 먼저 대입 
	for(int i=0;i<nodeNumber;i++)
	{
		idxNode[i].m_data = 'A'+i;
		
	}
	return idxNode;
}

//2. 만들어진 노드들을 연결해주는 함수
void LinkTreeEntity(Node *nodes, int nodeN, int levelN)
{
	int *leftCnt = new int[levelN];
	int *rightCnt= new int[levelN];
	//각 노드들을 연결 시켜 준다.
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


	//인위로 지정하자
	for(int i=0;i<levelN;i++)
	{
		switch(i)
		{
		case 0:
			//선두 노드 지정
			nodes[i].m_leftH = &nodes[leftCnt[i]];
			nodes[i].m_rightH= &nodes[rightCnt[i]];
			break;

		case 1:
			//왼쪽 노드 지정
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
			//오른쪽 노드 지정 
			break;
		}
	}





	//right side : 2,4,8,...
	

	delete [] gapArray;
	delete [] leftCnt;
	delete [] rightCnt;
	delete [] nodes;
}

//3. 만들어진 노드를 서치하는 함수

//4. 결과를 출력해주는 함수 