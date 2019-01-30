/*1）用C\C++语言实现单表仿射（Affine）加/解密算法；
2）用C\C++语言实现统计26个英文字母出现频率的程序；
3）利用单表仿射加/解密程序对一段较长的英文文章进行加密，再对明文和密文中字母出现的频率进行统计并作对比，观察有什么规律。
    仿射变换：
加密： 
解密： 
其中，k1和k2为密钥，k1∈Zq，k2∈Zq*。
实验要求：加/解密程序对任意满足条件的k1和k2都能够处理。

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
    char ko,kw;		//密钥 k1、k2及计数器 
	int cint,koint,kwint,counter=0;
	int choo; 
	vector<int>cipher;
	vector<int>temp;
	cipher.reserve(1000);
	temp.reserve(1000);
	int a[25]={0};
	char c,save;
	bool choose=false;
    cout<<"请输入密钥 K1、K2 的值："<<endl;
    cin >> ko >>kw;
	cout<<ko<<" "<<kw<<endl;
		
    fstream infile;
    
    infile.open("test.txt",ios::in);
        if (! infile.is_open())
        { cout << "Error opening file"; exit (1); }
        while (!infile.eof() )
        {
            infile>>c;			//单个字符读入
			 
            //temp.push_back(c);
            if(c>='a' && c<='z')
				a[c-'a']++;
			else if(c>='A' && c<='Z')
				a[c-'A']++;
			else if(c == ' ')
				a[c-' ']++;
            //counter++;
            koint=(int)ko, kwint=(int)kw, cint=(int)c; 
            save = (koint+kwint*cint)%26;  //加密过程，使用整数来完成取余操作,存入数字 
			cipher.push_back(save);  
            
        }
    
    for(int i=0;i<cipher.size();i++){
    	cout << cipher[i]<<" ";
	}
   
   for(int i=0;i<26;i++)
		{
			cout<<char(i+'a')<<"的数量为："<<a[i]<<endl;
		}
    infile.close();
	cout<<"请选择是否要解密，若要解密，请输入1，否则输入0"<<endl;
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













