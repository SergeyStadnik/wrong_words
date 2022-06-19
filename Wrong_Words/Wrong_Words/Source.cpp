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
	int summ = 0;
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
	cout << "Перед вами оригинальный текст." << endl<<"______________________________________"<<endl;
	cout << textOrig << endl;

	while (getline(WrongText, in_strWrong))
	{
		textWrong += in_strWrong + "\n";

	}
	cout << "А это слова, которые нужно удалить: ";
	cout << textWrong << endl;

	for (int i = 0; i < textOrig.length(); i++)

	{
		examO += textOrig[i];
		if (textOrig[i] == ' ')
		{
			for (int j = 0; j < textWrong.length(); j++)
			{examW += textWrong[j];
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
                 }
				else
				{
					
					summ++;
				}
				if (j == textWrong.length() - 1)
			{
					newText += examO;
					examO = "";
		    }
			}
			
		}
		
		
			
		 
		
        
		
		
	}
cout << newText;
	system("pause");
	return 0;
}