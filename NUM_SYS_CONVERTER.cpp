#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#include<conio.h>
#include<iomanip>
using namespace std;
class non_Decimal_Funct
{
private: 
	vector<long> ans;
	string s;
protected:
	string D_to_B_O_H(string n,int num)
	{
		long n1 = stol(n);
		for (int i = 0; n1; i++, n1 /= num)
		{
			if (num == 16) switch (n1%num)
							{
							case 10:s = "A" + s;
								break;
							case 11:s = "B" + s;
								break;
							case 12:s = "C" + s;
								break;
							case 13:s = "D" + s;
								break;
							case 14:s = "E" + s;
								break;
							case 15:s = "F" + s;
								break;
							default:s = to_string(n1 % num) + s;
							}
			else s = to_string(n1 % num) + s;
		}
		return s;
	}
	long B_O_H_to_D(string n,int num)
	{
		int n1=0;
		for (int i=n.length()-1;i>=0;i--)
		{
			if(num==16)
			switch (n[i])
			{
			case 'A':n1 = 10;
				break;
			case 'B':n1 = 11;
				break;
			case 'C':n1 = 12;
				break;
			case 'D':n1 = 13;
				break;
			case 'E':n1 = 14;
				break;
			case 'F':n1 = 15;
				break;
			default:n1 = int(n[i]) - 48;
			}
			else n1 = int(n[i])-48;
			ans.push_back(n1*pow(num,n.length()-1-i));
		}
		n1 = 0;
		for (int i = 0; i < ans.size(); i++) n1 += ans[i];
		return n1;
	}
	string B_to_O_H(string str, int num)
	{
		vector<char> ans;
		map<string, string> data;
		string temp,new_str;
		if (num == 8) { data = { {"000","0"},{"001","1"} ,{"010","2"} ,{"011","3"} ,{"100","4"} ,{"101","5"} ,{"110","6"} ,{"111","7"} }; num = 3; }
		else { data = { {"0000","0"},{"0001","1"} ,{"0010","2"} ,{"0011","3"} ,{"0100","4"} ,{"0101","5"} ,{"0110","6"} ,{"0111","7"},{"1000","8"},{"1001","9"},{"1010","A"},{"1011","B"},{"1100","C"},{"1101","D"},{"1110","E"},{"1111","F"}}; num = 4; }
		while (str.length() % num != 0) str = "0" + str;
		for (int i =0; i <str.length(); i += num)
		{
			temp.clear();
			for (int j = i; temp.length() < num; j++) temp += str[j];
			auto ptr=data.find(temp);
			new_str+=(ptr->second);
		}
		return new_str;
	}
	string O_H_to_B(string n,int num)
	{
		string temp="";
		map<char,string> data;
		if (num == 8) data = { {'0',"000"},{'1',"001"} ,{'2',"010"} ,{'3',"011"} ,{'4',"100"} ,{'5',"101"} ,{'6',"110"} ,{'7',"111"} };
		else data = { {'0',"0000"},{'1',"0001"} ,{'2',"0010"} ,{'3',"0011"} ,{'4',"0100"} ,{'5',"0101"} ,{'6',"0110"} ,{'7',"0111"},{'8',"1000"},{'9',"1001"},{'A',"1010"},{'B',"1011"},{'C',"1100"},{'D',"1101"},{'E',"1110"},{'F',"1111"} };
		for(int i=n.length()-1;i>=0;i--)
		{
			if (num == 8) if (n[i] == '9' || n[i] == '8') { cout << "\nInvalid number for Octal number system."; exit(0); }
			auto ptr = data.find(n[i]);
			temp=ptr->second+temp;
		}
		return temp;
	}
	friend class Decimal_Funct;
};
class Decimal_Funct
{
private:
	vector<float> ans;
	string s;
protected:
	non_Decimal_Funct o;
	string Decimal_D_to_B_O_H(string str1,string str2, int num)
	{
		str1=o.D_to_B_O_H(str1, num);
		float n1 = stof(str2);
		float n1_cpy = n1;
		int n;
		str2.clear();
		while (n1 >= 1 || n1 <= 0) n1 /= 10;
		for (int i = 0;i<20&&n1!=0; i++)
		{
			n = n1 * num;
			n1 *= num;
			n1 -= n;
			if (num == 16) switch (n)
			{
			case 10:str2 += "A";
				break;
			case 11:str2 += "B";
				break;
			case 12:str2 += "C";
				break;
			case 13:str2 += "D";
				break;
			case 14:str2 += "E";
				break;
			case 15:str2 += "F";
				break;
			default:str2 += to_string(n);
			}
			else str2 += to_string(n);
		}
		return str1+"."+str2;
	}
	string Decimal_B_O_H_to_D(string str1, string str2, int num)
	{
		float n1 = 0;
		for (int i = 1; i <=str2.length(); i++)
		{
			if (num == 16)
				switch (str2[i-1])
				{
				case 'A':n1 = 10;
					break;
				case 'B':n1 = 11;
					break;
				case 'C':n1 = 12;
					break;
				case 'D':n1 = 13;
					break;
				case 'E':n1 = 14;
					break;
				case 'F':n1 = 15;
					break;
				default:n1 = int(str2[i-1]) - 48;
				}
			else n1 = int(str2[i-1]) - 48;
			ans.push_back(n1 / pow(num, i));
		}
		n1 = 0;
		for (int i = 0; i < ans.size(); i++) n1 += ans[i];
		return to_string(o.B_O_H_to_D(str1, num)+n1);
	}
	string Decimal_B_to_O_H(string str1, string str2, int num)
	{
		str1 = o.B_to_O_H(str1, num);
		map<string, char> data;
		string temp,new_str;
		if (num == 8) { data = { {"000",'0'},{"001",'1'} ,{"010",'2'} ,{"011",'3'} ,{"100",'4'} ,{"101",'5'} ,{"110",'6'} ,{"111",'7'} }; num = 3; }
		else { data = { {"0000",'0'},{"0001",'1'} ,{"0010",'2'} ,{"0011",'3'} ,{"0100",'4'} ,{"0101",'5'} ,{"0110",'6'} ,{"0111",'7'},{"1000",'8'},{"1001",'9'},{"1010",'A'},{"1011",'B'},{"1100",'C'},{"1101",'D'},{"1110",'E'},{"1111",'F'} }; num = 4; }
		while (str2.length() % num != 0) str2 += "0";
		for (int i = 0; i <str2.length(); i += num)
		{
			temp.clear();
			for (int j = i; temp.length() < num; j++) temp += str2[j];
			auto ptr = data.find(temp);
			new_str+=(ptr->second);
		}
		return str1+"."+new_str;
	}
	void Decimal_O_H_to_B(string& str1,string& str2, int num)
	{
		str1 = o.O_H_to_B(str1, num);
		string temp = "";
		map<char, string> data;
		if (num == 8) data = { {'0',"000"},{'1',"001"} ,{'2',"010"} ,{'3',"011"} ,{'4',"100"} ,{'5',"101"} ,{'6',"110"} ,{'7',"111"} };
		else data = { {'0',"0000"},{'1',"0001"} ,{'2',"0010"} ,{'3',"0011"} ,{'4',"0100"} ,{'5',"0101"} ,{'6',"0110"} ,{'7',"0111"},{'8',"1000"},{'9',"1001"},{'A',"1010"},{'B',"1011"},{'C',"1100"},{'D',"1101"},{'E',"1110"},{'F',"1111"} };
		for (int i = str2.length() - 1; i >= 0; i--)
		{
			if (num == 8) if (str2[i] == '9' ||	str2[i] == '8') { cout << "\nInvalid number for Octal number system."; exit(0); }
			auto ptr = data.find(str2[i]);
			temp = ptr->second + temp;
		}
		str2 = temp;
	}
};
class Converter :public non_Decimal_Funct, public Decimal_Funct
{
private:
	int from=1, to=2;
	string num="";
	string str1 = "", str2 = "";
public:
	void setdata()
	{
		cout << "Enter a number : \n\t1) ";
		cin >> num;
	}
	void choose()
	{
		cout << "\nConvert form a)_______ to b)_______ : ";
		cout << "\n\n\ta)\n\t\t1 -----> Decimal\n\t\t2 -----> Binary\n\t\t3 -----> Octal\n\t\t4 -----> Hexadecimal\n\t\t";
		cin >> from;
		cout << "\n\t2)\n\t\t1 -----> Decimal\n\t\t2 -----> Binary\n\t\t3 -----> Octal\n\t\t4 -----> Hexadecimal\n\t\t";
		cin >> to;
		switch (from)
		{
		case 1:from = 10;
			break;
		case 2:
			break;
		case 3:from = 8;
			break;
		case 4:from = 16;
			break;
		}
		switch (to)
		{
		case 1:to = 10;
			break;
		case 2:
			break;
		case 3:to = 8;
			break;
		case 4:to = 16;
			break;
		}
	}
	void select()
	{
		switch (this->from)
		{
		case 10: cout << "\n" << D_to_B_O_H(this->num, this->to);
			break;
		case 2:switch (this->to)
		{
			case 10: cout << "\n" << B_O_H_to_D(this->num, this->from);
				break;
			case 8: cout << "\n" << B_to_O_H(this->num, this->to);
				break;
			case 16: cout << "\n" << B_to_O_H(this->num, this->to);
				break;
			default:cout << "\nInvaid 'to' parameter. ";
				_getch();
				exit(0);
		}
			  break;
		case 8:switch (this->to)
		{
		case 10: cout << "\n" << B_O_H_to_D(this->num, this->from);
			break;
		case 2: cout << "\n" << O_H_to_B(this->num, this->from);
			break;
		case 16: cout << "\n" << B_to_O_H(O_H_to_B(this->num, this->from), this->to);
			break;
		default:cout << "\nInvaid 'to' parameter. ";
			_getch();
			exit(0);
		}
			  break;
		case 16:switch (this->to)
		{
		case 10: cout << "\n" << B_O_H_to_D(this->num, this->from);
			break;
		case 2: cout << "\n" << O_H_to_B(this->num, this->from);
			break;
		case 8: cout << "\n" << B_to_O_H(O_H_to_B(this->num, this->from), this->to);
			break;
		default:cout << "\nInvaid 'to' parameter. ";
			_getch();
			exit(0);
		}
			   break;
		default:cout << "\nInvaid 'from' parameter. ";
			_getch();
			exit(0);
		}
	}
	void Decimal_select()
	{
		switch (this->from)
		{
		case 10: cout << "\n" << Decimal_D_to_B_O_H(this->str1,this->str2, this->to);
			break;
		case 2:switch (this->to)
		{
		case 10: cout << "\n" << Decimal_B_O_H_to_D(this->str1,this->str2, this->from);
			break;
		case 8: cout << "\n" << Decimal_B_to_O_H(this->str1, this->str2, this->to);
			break;
		case 16: cout << "\n" << Decimal_B_to_O_H(this->str1, this->str2, this->to);
			break;
		default:cout << "\nInvaid 'to' parameter. ";
			_getch();
			exit(0);
		}
			  break;
		case 8:switch (this->to)
		{
		case 10: cout << "\n" << Decimal_B_O_H_to_D(this->str1, this->str2, this->from);
			break;
		case 2: Decimal_O_H_to_B(this->str1,this->str2, this->from);
			cout<<str1+"."+str2;
			break;
		case 16: Decimal_O_H_to_B(this->str1, this->str2, this->from);
			cout << "\n" << Decimal_B_to_O_H(this->str1, this->str2, this->to);
			break;
		default:cout << "\nInvaid 'to' parameter. ";
			_getch();
			exit(0);
		}
			  break;
		case 16:switch (this->to)
		{
		case 10: cout << "\n" << Decimal_B_O_H_to_D(this->str1, this->str2, this->from);
			break;
		case 2: Decimal_O_H_to_B(this->str1,this->str2, this->from);
			cout << str1 + "." + str2;
			break;
		case 8: Decimal_O_H_to_B(this->str1, this->str2, this->from);
			cout << "\n" << Decimal_B_to_O_H(this->str1, this->str2, this->to);
			break;
		default:cout << "\nInvaid 'to' parameter. ";
			_getch();
			exit(0);
		}
			   break;
		default:cout << "\nInvaid 'from' parameter. ";
			_getch();
			exit(0);
		}
	}
	void getdata(vector<long> ans)
	{
		cout << "\n";
		for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
	}
	bool decimal_checker()
	{
		if (num.find('.') == -1) return false;
		int i = 0;
		while (num[i] != '.')
		{
			str1 += num[i];
			i++;
		}
		i = num.find('.')+1;
		while (i < num.length())
		{
			str2 += num[i];
			i++;
		}
		return true;
	}
};
int main()
{
	Converter obj;
	obj.setdata();
	obj.choose();
	if(obj.decimal_checker()==true)
	{
		obj.Decimal_select();
		_getch();
		return 0;
	}
	obj.select();
	_getch();
	return 0;
}