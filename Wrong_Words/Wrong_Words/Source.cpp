#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include <fstream>
using namespace std;


int main() {

	setlocale(0, "");
	srand(time(NULL));

	string in_strOrig = "Original.txt";
	string in_strWrong = "Wrong.txt";
	string textOrig;
	string textWrong;
	string examO;
	string examW;
	string newText;
	string newText1 = "new.txt";
	
	ifstream OriginText(in_strOrig);
	ifstream WrongText(in_strWrong);
	 
	if (OriginText.fail() || WrongText.fail())
	{
		cout << "Error";
		return 404;
    }

	while (getline(OriginText, in_strOrig))
	{
		textOrig += in_strOrig + "\n";

	}
	cout << "ѕеред вами оригинальный текст." << endl<<"///////////////////////////////////////////////////////"<<endl;
	cout << textOrig << endl;

	OriginText.close();
	while (getline(WrongText, in_strWrong))
	{
		textWrong += in_strWrong + "\n";

	}
	cout << "/////////////////////////////////////////////////////////////" << endl;
	cout << "ј это слова, которые нужно удалить: "<<endl;
	cout << "/////////////////////////////////////////////////////////////" << endl;
	cout << textWrong << endl;
	cout << "////////////////////////////////////////////////////////////" << endl;

	WrongText.close();
	for (int i = 0; i < textOrig.length(); i++)

	{
		
		if (textOrig[i] == ' '|| textOrig[i] == ',' || textOrig[i] == '"' || textOrig[i] == '?')
		{
			for (int j = 0; j < textWrong.length(); j++)
			{
				if (textWrong[j] == ' ')
				{
					if (examO == examW)
					{
						examO = "";
						examW = "";
						break;
					}
					else
					{
						examW = "";
					}
                 }examW += textWrong[j];
				
				if (j == textWrong.length() - 1)
			{
					newText += examO;
					examO = "";
		    }
			}
			
		}examO += textOrig[i];
		}
	cout << "Ёто текст после переработки: " << endl;
	cout << "/////////////////////////////////////////////////////////////" << endl;
     cout << newText<<endl<<endl;
	 ofstream out_text;
	 out_text.open(newText1);
	 if (out_text.fail())
	 {
		 cout << "Error";
		 return 404;
	 }
	 out_text << newText;
	 out_text.close();
	
	return 0;
}