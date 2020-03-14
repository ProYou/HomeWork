#include<iostream>
#include <fstream>
#include <sstream>
#include <string>//文本对象，储存读取的内容
using namespace std;

//定义最终输出
void out_put(int num) {
	if (num == 1) {
		ofstream out("output.txt");
		out << "Black wins";
	}
	else {
		if (num == -1) {
			ofstream out("output.txt");
			out << "White wins";
		}
		else {
			ofstream out("output.txt");
			out << "Tie";
		}
	}
}
//找出手牌里面的对子数 0/1/2对
int pair_num(int num[]) {
	int num_pair = 0;
	for (int i = 0; i < 5; i++) {
		if (num[i] == num[i + 1]) {
			num_pair++;
			i++;
		}
	}
	if (num_pair == 0) {
		return 0;
	}
	else {
		if (num_pair == 1) {
			return 1;
		}
		else {
			return 2;
		}
	}
}

// 判断为 2-对子/4-三条
int duizi_or_santiao(int num[],int pair_num) {
	if (pair_num == 1) {
		for (int i = 0; i < 3; i++) {
			if (num[i] == num[i + 1]&& num[i + 1] == num[i + 2])
				return 4;
		}
		return 2;
	}
	else
		return 0;
}

// 判断为3-两对/8-铁支
int liangdui_or_tiezhi(int num[],int pair_num) {
	if (pair_num == 2) {
		if ((num[0] == num[1]&& num[1] == num[2]&& num[2] == num[3])|| (num[1] == num[2]&& num[2] == num[3]&& num[3] == num[4]))
			return 8;
		else
			return 3;
	}
	return 0;
}

// 判断为5-顺子
int shunzi(int num[]) {
	if (num[4] == (num[3] + 1) && (num[3] + 1)==(num[2] + 2)&& (num[2] + 2) == (num[1] + 3)&& (num[1] + 3)== (num[0] + 4))
		return 5;
	else
		return 0;
}

// 判断为6-同花
int color_same(char color[]) {
	if (color[0] == color[1] && color[0] == color[2] && color[0] == color[3] && color[0] == color[4])
		return 6;
	else
		return 0;
}

// 判断为7-葫芦
int hulu(int num[],int pair_num) {
	if (pair_num == 2 && liangdui_or_tiezhi(num,pair_num)!= 8) {
		//cout << num[0] << num[1] << num[2] << num[3] << num[4] << endl;
		if ((num[0] == num[1]&& num[0] == num[2]) || (num[2] == num[3]&& num[2] == num[4])) {
			return 7;
		}
		return 3;
	}
	else 
		return 0;
}

// 判断为9同-花顺
int tonghuashun(char color[], int num[]) {
	if (color_same(color) == 6 && shunzi(num) == 5)
		return 9;
	else
		return 0;
}

// 判断手牌属于哪种类型 9-同花顺 8-铁支 7-葫芦 6-同花 5-顺子 4-三条 3-两对 2-对子 1-散牌
int type(char color[], int num[],int pair_num) {
	//int tp = 0;
	for (int i = 9; i > 1; i--) {

		switch (i){

		case 2:
			if (duizi_or_santiao(num,pair_num) == 2) {
				return 2;
			}
			break;
		case 3:
			if (liangdui_or_tiezhi(num, pair_num) == 3) {
				return 3;
			}
			break;
		case 4:
			if (duizi_or_santiao(num, pair_num) == 4) {
				return 4;
			}
			break;
		case 5:
			if (shunzi(num) == 5) {
				return 5;
			}
			break;
		case 6:
			if (color_same(color) == 6) {
				return 6;
			}
			break;
		case 7:
			if (hulu(num,pair_num) == 7) {
				return 7;
			}
			break;
		case 8:
			if (liangdui_or_tiezhi(num, pair_num) == 8) {
				return 8;
			}
			break;
		case 9:
			if(tonghuashun(color,num) == 9)
			{
				return 9;
			}
			break;
		}

	}
	return 0;
}

//计算手牌对应的值 1-13 并把这5张手牌的纸存到数组里面
void jisuan_value(char value1[], int num[]) {
	for (int i = 0; i < 5; i++) {

		switch (value1[i])
		{
		case '2':
			num[i] = 1;
			break;
		case '3':
			num[i] = 2;
			break;
		case '4':
			num[i] = 3;
			break;
		case '5':
			num[i] = 4;
			break;
		case '6':
			num[i] = 5;
			break;
		case '7':
			num[i] = 6;
			break;
		case '8':
			num[i] = 7;
			break;
		case '9':
			num[i] = 8;
			break;
		case 'T':
			num[i] = 9;
			break;
		case 'J':
			num[i] = 10;
			break;
		case 'Q':
			num[i] = 11;
			break;
		case 'K':
			num[i] = 12;
			break;
		case 'A':
			num[i] = 13;
			break;
		default:
			break;
		}

	}
}
// 给这5张手牌 排序 value-color-num一一对应
void paixu(char value1[], char color1[], int num1[]) {
	int temp_num;
	char temp_value, temp_color;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4 - j; i++) {
			if (num1[i] > num1[i + 1]) {
				temp_num = num1[i];
				num1[i] = num1[i + 1];
				num1[i + 1] = temp_num;

				temp_value = value1[i];
				value1[i] = value1[i + 1];
				value1[i + 1] = temp_value;

				temp_color = color1[i];
				color1[i] = color1[i + 1];
				color1[i + 1] = temp_color;
			}
		}
	}
}

//散牌规则比较
void sanpai_compare(int num1[], int num2[],int i) {
	
	//cout << sizeof(num1) << endl;
	//cout << sizeof(num1[0]) << endl;
	//int i = sizeof(num1) / sizeof(num1[0]);
	//int temp;
	while (i >= 0 && (num1[i] == num2[i])) {
		i--;
	}
	if (i == -1) {
		out_put(0);
	}
	else {
		if (num1[i] > num2[i]) {
			out_put(1);
		}
		else {
			out_put(-1);
		}
	}
}

// 手牌类型为两对 顺序存储大对子、小对子、单张牌
void find_3(int num1[], int num1_3[]) {
	if (num1[0] != num1[1]) {
		num1_3[0] = num1[3];
		num1_3[1] = num1[2];
		num1_3[2] = num1[0];
	}
	else {
		if (num1[4] != num1[3]) {
			num1_3[0] = num1[2];
			num1_3[1] = num1[1];
			num1_3[2] = num1[4];
		}
		else {
			num1_3[0] = num1[3];
			num1_3[1] = num1[1];
			num1_3[2] = num1[2];
		}
	}
}
//手牌类型为对子 顺序存储对子、其余三张单牌
void find_2(int num1[], int num1_4[]) {
	//int num1_4[4];
	if (num1[0] == num1[1]) {
		num1_4[0] = num1[1];
		num1_4[1] = num1[4];
		num1_4[2] = num1[3];
		num1_4[3] = num1[2];
	}
	else {
		if (num1[1] == num1[2]) {
			num1_4[0] = num1[1];
			num1_4[1] = num1[4];
			num1_4[2] = num1[3];
			num1_4[3] = num1[0];
		}
		else {
			if (num1[2] == num1[3]) {
				num1_4[0] = num1[2];
				num1_4[1] = num1[4];
				num1_4[2] = num1[1];
				num1_4[3] = num1[0];
			}
			else {
				num1_4[0] = num1[3];
				num1_4[1] = num1[2];
				num1_4[2] = num1[1];
				num1_4[3] = num1[0];
			}
		}
	}
}
// 同为 2-对子 类型的牌的比较
void compare_2(int num1[], int num2[]) {
	int num1_4[4];
	int num2_4[4];
	find_2(num1, num1_4);
	find_2(num2, num2_4);
	sanpai_compare(num1_4, num2_4,4);
}
// 同为 3-两对 类型的牌的比较
void compare_3(int num1[], int num2[]) {
	int num1_3[3];
	int num2_3[3];
	find_3(num1, num1_3);
	find_3(num2, num2_3);
	sanpai_compare(num1_3, num2_3,3);
}

//按照散牌规则进行比较
void max_compare(int num1[], int num2[]) {
	if (num1[4] > num2[4]) {
		out_put(1);
	}
	else {
		if (num1[4] < num2[4]) {
			out_put(-1);
		}
		else {
			out_put(0);
		}
	}
}
// 同为 4-三条类型的牌的比较
int compare_4(int num1[], int num2[]) {
	int temp1, temp2;
	temp1 = num1[2];
	temp2 = num2[2];
	if (temp1 == temp2) {
		return 0;
	}
	else {
		if (temp1 < temp2) {
			return -1;
		}
		else {
			return 1;
		}
	}
}
// 同为 8-铁支类型的牌的比较
int compare_8(int num1[], int num2[]) {
	int temp1, temp2;
	temp1 = num1[1];
	temp2 = num2[1];


	if (temp1 == temp2) {
		return 0;
	}
	else {
		if (temp1 < temp2) {
			return -1;
		}
		else {
			return 1;
		}
	}

}
// 手牌为同类型 相比较
void same_num(int type_num,int num1[],int num2[]) {
	switch (type_num)
	{
	case 1:
		sanpai_compare(num1, num2,5);
		break;
	case 2:
		compare_2(num1, num2);
		break;
	case 3:
		compare_3(num1, num2);
		break;
	case 4:
		out_put(compare_4(num1, num2));
		break;
	case 5:
		max_compare(num1, num2);
		break;
	case 6:
		sanpai_compare(num1, num2,5);
		break;
	case 7:
		out_put(compare_4(num1, num2));
		break;
	case 8:
		out_put(compare_8(num1, num2));
		break;
	case 9:
		max_compare(num1, num2);
		break;
	default:
		break;
	}
}
int main() {
	//value: 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A
    //color:花色 DSHC
	//num：value对应的值1-13
	char value1[5] = {}, color1[5] = {};
	char value2[5] = {}, color2[5] = {};
	int num1[5];
	int num2[5];

	//从input.txt读取数据
	ifstream in("input.txt");
	string str[2][6];
	if (!in.is_open())
	{
		cout << "can not open this file" << endl;
		return 0;
	}
	int count = 0;
	int i = -1;
	int j = -1;
	string str_temp;
	for (int m = 0; m < 2; m++)
	{
		for (int n = 0; n < 6; n++)
		{
			in >> str[m][n];
		}
	}
	for (int m = 0; m < 2; m++)
	{
		for (int n = 1; n < 6; n++)
		{
			count++;
			if (count < 6) {
				str_temp = str[m][n];
				i++;
				value1[i] = str_temp[0];
				color1[i] = str_temp[1];
			}
			else {
				str_temp = str[m][n];
				j++;
				value2[j] = str_temp[0];
				color2[j] = str_temp[1];
			}
		}
	}

	//计算手牌对应的值
	jisuan_value(value1, num1);
	jisuan_value(value2, num2);

	//对手牌的值进行排序从小到大，value-color-num一一对应
	paixu(value1, color1, num1);
	paixu(value2, color2, num2);

	//找出手牌里面有几个对子
	int pair_num1 = pair_num(num1);
	int pair_num2 = pair_num(num2);

	//得出手牌对应的类型
	int type_num1 = type(color1, num1, pair_num1);
	int type_num2 = type(color2, num2, pair_num2);
	
	if (type_num1 > type_num2) {
		out_put(1);
	}
	else {
		if (type_num1 < type_num2) {
			out_put(-1);
		}
		else {
			int type_num = type_num1;
			same_num(type_num, num1, num2);
		}
	}
	in.close();//关闭数据流
	return 0;
}
