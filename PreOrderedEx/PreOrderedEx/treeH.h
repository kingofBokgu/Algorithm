#include<iostream>
#include<math.h>
#include<crtdbg.h>

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

	int index=0;
	//left side 
	int midNum = levelN+2;

	while(index <=midNum)
	{
		cout << "index: "<< index <<endl;
		nodes[index].m_leftH = &nodes[leftCnt[index]];




		index++;
	}

	//right side
	


	delete [] leftCnt;
	delete [] rightCnt;
	delete [] nodes;
}

//3. 만들어진 노드를 서치하는 함수

//4. 결과를 출력해주는 함수 