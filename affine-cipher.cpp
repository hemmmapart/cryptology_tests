/*1����C\C++����ʵ�ֵ�����䣨Affine����/�����㷨��
2����C\C++����ʵ��ͳ��26��Ӣ����ĸ����Ƶ�ʵĳ���
3�����õ�������/���ܳ����һ�νϳ���Ӣ�����½��м��ܣ��ٶ����ĺ���������ĸ���ֵ�Ƶ�ʽ���ͳ�Ʋ����Աȣ��۲���ʲô���ɡ�
    ����任��
���ܣ� 
���ܣ� 
���У�k1��k2Ϊ��Կ��k1��Zq��k2��Zq*��
ʵ��Ҫ�󣺼�/���ܳ������������������k1��k2���ܹ�����

*/ 
#include<iostream>
#include<string>
#include<cstring>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    char ko,kw;		//��Կ k1��k2�������� 
	int cint,koint,kwint,counter=0;
	int choo; 
	vector<int>cipher;
	vector<int>temp;
	cipher.reserve(1000);
	temp.reserve(1000);
	int a[25]={0};
	char c,save;
	bool choose=false;
    cout<<"��������Կ K1��K2 ��ֵ��"<<endl;
    cin >> ko >>kw;
	cout<<ko<<" "<<kw<<endl;
		
    fstream infile;
    
    infile.open("test.txt",ios::in);
        if (! infile.is_open())
        { cout << "Error opening file"; exit (1); }
        while (!infile.eof() )
        {
            infile>>c;			//�����ַ�����
			 
            //temp.push_back(c);
            if(c>='a' && c<='z')
				a[c-'a']++;
			else if(c>='A' && c<='Z')
				a[c-'A']++;
            //counter++;
            koint=(int)ko, kwint=(int)kw, cint=(int)c; 
            save = (koint+kwint*cint)%26;  //���ܹ��̣�ʹ�����������ȡ�����,�������� 
			cipher.push_back(save);  
            
        }
    
    for(int i=0;i<cipher.size();i++){
    	cout << cipher[i]<<" ";
	}
   
   for(int i=0;i<26;i++)
		{
			cout<<char(i+'a')<<"������Ϊ��"<<a[i]<<endl;
		}
    infile.close();
	cout<<"��ѡ���Ƿ�Ҫ���ܣ���Ҫ���ܣ�������1����������0"<<endl;
	cin>>choo;
	if(choo == 1)
		{
			for(int i=0;i<cipher.size();i++)
			{
				
				temp.push_back(((26-kwint)*(cipher.at(i)-koint))%26);
			}
		}
	for(int i=0;i<temp.size();i++){
		char set;
		set= char(temp.at(i)+'a');
    	cout << set<<" ";
	}
    return 0;
}













