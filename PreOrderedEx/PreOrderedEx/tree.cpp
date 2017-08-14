#include "treeH.h"

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	int levelN;
	int nodeNum;
	int nodeResult=0;
	cout<<"레벨을 입력해 주세요"<<endl;
	cin >> levelN;
	cout <<endl;
	cout <<"***************************"<<endl;
	for(int i=0; i<levelN; i++)
	{
		nodeNum = (int)pow(2,i);
		nodeResult += nodeNum;
		cout <<"Level:"<<i+1 <<"," <<"node 수:"<<nodeResult <<endl;
	}
	cout <<"***************************"<<endl;
	LinkTreeEntity(MakeTreeEntity(nodeResult), nodeResult,levelN);
	

}