//�ּҷ� ����� ������Ʈ
//1. �̸�
//2. �̸���
//3. ��ȭ��ȣ
//4. �ѽ���ȣ
//5. �޸�
//6. ������� �˻� �� (#include <ctime>) , ���� �����̶�� "Happy Birthday!"
//7. �����	   �˻� �� (#include <ctime>) , ������ D-day  "D-xx"
//
//========================================================================
//1. �ּҷ� �Է��ϱ�
//2. �˻� --------------------> 1.�̸� 2. ��ȭ��ȣ �˻�
//							  ���� ----> ���������ؿ�
//							  ����� --> ���� ����� , D-xx
//							  �̸� , �̸��� , ��ȭ��ȣ , �ѽ���ȣ , �޸� �� Show

#include "Address.h"

Address::Address()										// Ŭ������ ������
{
	this->name = std::string("");
	this->email = std::string("");
	this->homeAddress = std::string("");
	this->FaxAddress = std::string("");
	this->memo = std::string("");
	this->BirthDay = uint32_t(0U);
	this->Anniversary = std::string("");
}

Address::~Address()										// Ŭ������ �Ҹ���
{

}

std::string Address::gethomeAddress() const
{
	return this->homeAddress;
}
void Address::sethomeAddress(std::string Home_Address)
{
	this->homeAddress = Home_Address;
}

std::string Address::getFaxAddress() const
{
	return this->FaxAddress;
}
void Address::setFaxAddress(std::string Fax_Address)
{
	this->FaxAddress = Fax_Address;
}

uint32_t Address::getBirthDay() const
{
	return this->BirthDay;
}
void Address::setBirthDay(uint32_t birthDay)
{
	this->BirthDay = birthDay;
}

std::string Address::getAnniversary() const
{
	return this->Anniversary;
}
void Address::setAnniversary(std::string anniversary)
{
	this->Anniversary = anniversary;
}

std::string Address::getname() const
{
	return this->name;
}
void Address::setname(std::string Name)
{
	this->name = Name;
}

std::string Address::getemail() const
{
	return this->email;
}
void Address::setemail(std::string Email)
{
	this->email = Email;
}

std::string Address::getmemo() const
{
	return this->memo;
}
void Address::setmemo(std::string Memo)
{
	this->memo = Memo;
}



void Address::ShowAddress()										// �ּҷ� ��¹��� �����ֱ� ���� �Լ� 
{
	std::cout << "������ �̸��� : " << this->name << std::endl;
	std::cout << "������ �̸����� : " << this->email << std::endl;
	std::cout << "������ ��ȭ��ȣ�� : " << this->homeAddress << std::endl;
	std::cout << "������ �ѽ���ȣ�� : " << this->FaxAddress << std::endl;
	std::cout << "������ �ۼ��޸�� : " << this->memo << std::endl;
	std::cout << "������ ������ : " << this->BirthDay << std::endl;
}

void Address::DeleteAddress()									// �ּҷ� ���� �Լ�
{
	std::string delete_{ " " };
	uint32_t delete__{ 0U };

	this->name = delete_;
	this->email = delete_;
	this->homeAddress = delete_;
	this->FaxAddress = delete_;
	this->memo = delete_;
	this->BirthDay = delete__;
	this->Anniversary = delete_;
}

void Address::Delete_Address()
{
	std::string delete1{ "" };
	std::cout << "������ �����Ǿ����ϴ�. " << std::endl;
}

void Address::calculator_BirthDDAY()
{
	time_t start, end;
	struct tm user_time;
	int timer_day, timer_hour, timer_min, timer_sec;
	double different;
	int my_year, my_month, my_day;

	std::cout << "����ϴ� �� �⵵ : ";
	std::cin >> my_year;

	std::cout << "����ϴ� �� �� : ";
	std::cin >> my_month;

	std::cout << "����ϴ� �� �� : ";
	std::cin >> my_day;

	user_time.tm_year = my_year - 1900;
	user_time.tm_mon = my_month - 1;
	user_time.tm_mday = my_day;
	user_time.tm_hour = 0;
	user_time.tm_min = 0;
	user_time.tm_sec = 0;
	user_time.tm_isdst = { 0 };

	start = mktime(&user_time);
	time(&end);

	different = difftime(end, start);

	timer_day = different / (60 * 60 * 24);
	different = different - (timer_day * 60 * 60 * 24);

	timer_hour = different / (60 * 60);
	different = different - (timer_hour * 60 * 60);

	timer_min = different / 60;
	different = different - (timer_min * 60);

	timer_sec = different;

	std::cout << "���� D-day�� : " << my_year << "��" << my_month << "��" << my_day << "�� ���� ������� " << timer_day << "��" << "���ҽ��ϴ�.";
}