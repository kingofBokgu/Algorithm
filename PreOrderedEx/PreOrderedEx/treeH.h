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

//3. ������� ��带 ��ġ�ϴ� �Լ�

//4. ����� ������ִ� �Լ� 