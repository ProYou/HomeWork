#include<iostream>
#include <fstream>
#include <sstream>
#include <string>//�ı����󣬴����ȡ������
using namespace std;

//�����������
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
//�ҳ���������Ķ����� 0/1/2��
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

// �ж�Ϊ 2-����/4-����
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

// �ж�Ϊ3-����/8-��֧
int liangdui_or_tiezhi(int num[],int pair_num) {
	if (pair_num == 2) {
		if ((num[0] == num[1]&& num[1] == num[2]&& num[2] == num[3])|| (num[1] == num[2]&& num[2] == num[3]&& num[3] == num[4]))
			return 8;
		else
			return 3;
	}
	return 0;
}

// �ж�Ϊ5-˳��
int shunzi(int num[]) {
	if (num[4] == (num[3] + 1) && (num[3] + 1)==(num[2] + 2)&& (num[2] + 2) == (num[1] + 3)&& (num[1] + 3)== (num[0] + 4))
		return 5;
	else
		return 0;
}

// �ж�Ϊ6-ͬ��
int color_same(char color[]) {
	if (color[0] == color[1] && color[0] == color[2] && color[0] == color[3] && color[0] == color[4])
		return 6;
	else
		return 0;
}

// �ж�Ϊ7-��«
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

// �ж�Ϊ9ͬ-��˳
int tonghuashun(char color[], int num[]) {
	if (color_same(color) == 6 && shunzi(num) == 5)
		return 9;
	else
		return 0;
}

// �ж����������������� 9-ͬ��˳ 8-��֧ 7-��« 6-ͬ�� 5-˳�� 4-���� 3-���� 2-���� 1-ɢ��
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

//�������ƶ�Ӧ��ֵ 1-13 ������5�����Ƶ�ֽ�浽��������
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
// ����5������ ���� value-color-numһһ��Ӧ
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

//ɢ�ƹ���Ƚ�
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

// ��������Ϊ���� ˳��洢����ӡ�С���ӡ�������
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
//��������Ϊ���� ˳��洢���ӡ��������ŵ���
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
// ͬΪ 2-���� ���͵��ƵıȽ�
void compare_2(int num1[], int num2[]) {
	int num1_4[4];
	int num2_4[4];
	find_2(num1, num1_4);
	find_2(num2, num2_4);
	sanpai_compare(num1_4, num2_4,4);
}
// ͬΪ 3-���� ���͵��ƵıȽ�
void compare_3(int num1[], int num2[]) {
	int num1_3[3];
	int num2_3[3];
	find_3(num1, num1_3);
	find_3(num2, num2_3);
	sanpai_compare(num1_3, num2_3,3);
}

//����ɢ�ƹ�����бȽ�
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
// ͬΪ 4-�������͵��ƵıȽ�
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
// ͬΪ 8-��֧���͵��ƵıȽ�
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
// ����Ϊͬ���� ��Ƚ�
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
    //color:��ɫ DSHC
	//num��value��Ӧ��ֵ1-13
	char value1[5] = {}, color1[5] = {};
	char value2[5] = {}, color2[5] = {};
	int num1[5];
	int num2[5];

	//��input.txt��ȡ����
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

	//�������ƶ�Ӧ��ֵ
	jisuan_value(value1, num1);
	jisuan_value(value2, num2);

	//�����Ƶ�ֵ���������С����value-color-numһһ��Ӧ
	paixu(value1, color1, num1);
	paixu(value2, color2, num2);

	//�ҳ����������м�������
	int pair_num1 = pair_num(num1);
	int pair_num2 = pair_num(num2);

	//�ó����ƶ�Ӧ������
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
	in.close();//�ر�������
	return 0;
}
