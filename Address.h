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


#pragma once
#include <iostream>
#include <string>
#include <ctime>

class Address
{
private:
	std::string name;										// �̸�
	std::string email;										// �̸���
	std::string homeAddress;								// ��ȭ ��ȣ
	std::string FaxAddress;									// �ѽ� ��ȣ
	std::string memo;										// �޸�
	uint32_t BirthDay{ 0U };								// ���� ���
	std::string Anniversary;								// �����
public:
	Address();
	~Address();

	std::string gethomeAddress() const;
	void sethomeAddress(std::string homeAddress);

	std::string getFaxAddress() const;
	void setFaxAddress(std::string FaxAddress);

	uint32_t getBirthDay() const;
	void setBirthDay(uint32_t BirthDay);

	std::string getAnniversary() const;
	void setAnniversary(std::string Anniversary);

	std::string getname() const;
	void setname(std::string name);

	std::string getemail() const;
	void setemail(std::string Email);

	std::string getmemo() const;
	void setmemo(std::string Memo);

	void ShowAddress();
	void DeleteAddress();
	void Delete_Address();
	void calculator_BirthDDAY();

};

