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

#include <iostream>
#include "Address.h"

int main()
{
	uint32_t client{ 0U };											// �Է��� ��� �� �ʱ�ȭ
	std::cout << "������ ������ ����� ���ڸ� �Է��ϼ��� : ";
	std::cin >> client;
	Address* clients  = { new Address[client] };					// Ŭ������ �����͸� �޴� ���� �����Ҵ��� �ϰ� �ʱ�ȭ
	uint32_t index{ 0U };											// ��¹� �ε��� �ʱ�ȭ
	

	for (;;)
	{
		while (index < client)
		{
			std::cout << "�̸��� �Է��ϼ��� : ";
			char client_name[100];
			std::cin >> client_name;
			clients[index].setname(client_name);
			std::cout << std::endl;

			std::cout << "������ �Է��ϼ��� : ";
			uint32_t client_birthday = { 0U };
			std::cin >> client_birthday;
			clients[index].setBirthDay(client_birthday);
			std::cout << std::endl;

			std::cout << "�̸����� �Է��ϼ��� : ";
			char client_email[100];
			std::cin >> client_email;
			clients[index].setemail(client_email);
			std::cout << std::endl;

			std::cout << "��ȭ��ȣ�� �Է��ϼ��� : ";
			std::string client_home_address = { 0 };
			std::cin >> client_home_address;
			clients[index].sethomeAddress(client_home_address);
			std::cout << std::endl;

			std::cout << "�ѽ���ȣ�� �Է��ϼ��� : ";
			std::string client_Fax_address = { 0 };
			std::cin >> client_Fax_address;
			clients[index].setFaxAddress(client_Fax_address);
			std::cout << std::endl;

			std::cout << "�޸� �Է��ϼ��� : ";
			char client_memo[100];
			std::cin >> client_memo;
			clients[index].setmemo(client_memo);
			std::cout << std::endl;

			index++;

			std::cout << " >> ������ ����Ǿ����ϴ�. " << std::endl << std::endl;
		}
		std::cout << "�ءءءءءءءءءءءءءءءءءءءءءءء�" << std::endl;
		std::cout << "1.�̸� �˻��� ���� ��� , ������ �׸�" << std::endl;
		std::cout << "2.��ȭ��ȣ �˻�" << std::endl;
		std::cout << "3.���� Ȯ��" << std::endl;
		std::cout << "4.�̴��� ����� Ȯ��" << std::endl;
		std::cout << "5.����" << std::endl;
		std::cout << "�ءءءءءءءءءءءءءءءءءءءءءءء�" << std::endl;
		
		// switch_case���� ���� ������ �ʱ�ȭ
		uint32_t select_menu{ 0U };			// �Է¸޴�
		std::cin >> select_menu;
		char name[100];						// �Է��� �迭�� ũ��
		std::string Address{ 0U };
		uint32_t Birthday{ 0U };
		uint32_t Anniversary{ 0U };
		std::string delete_name{""};
		std::string delete_num{ "" };
		uint32_t menu{ 0U };				// switch case 1���� ���ǹ� �޴� �Է� �ʱ�ȭ
		uint32_t Menu_select{ 0U };

		switch (select_menu)
		{
		case 1:
			std::cout << "������ �޴��� ���ʽÿ�. 1:������� 2:�̸����� 3:��ȣ����" << std::endl;
			std::cin >> menu;

			if (menu == 1)										// ������ �˻��ϰ� ����� ����
			{
				std::cout << "�����˻��� ���" << std::endl;
				std::cout << "�̸��� �Է��ϼ��� : ";
				std::cin >> name;
				for (int i = 0; i < client; i++)
				{
					if (clients[i].getname() == name)
					{
						clients[i].ShowAddress();
					}
					std::cout << "�ش��ϴ� ������ �����ϴ�." << std::endl;
				}
			}
			else if (menu == 2)									// �̸��� ������ ����
			{
				std::cout << "�̸�����" << std::endl;
				std::cout << "������ �̸��� �Է��ϼ��� : ";
				std::cin >> delete_name;
				for (int i = 0; i < client; i++)
				{
					if (clients[i].getname() == delete_name)
					{
						clients[i].Delete_Address();
						clients[i].DeleteAddress();
						std::cout << "�ش� ������ �����ϴ� . " << std::endl << std::endl;
					}
				}
			}

			else if (menu == 3)									// ��ȣ�� ������ ����
			{
				std::cout << "��ȣ����" << std::endl;
				std::cout << "������ ��ȣ�� �Է��ϼ��� : " << std::endl;
				std::cin >> delete_num;
				for (int i = 0; i < client; i++)
				{
					if (clients[i].gethomeAddress() == delete_num)
					{
						clients[i].Delete_Address();
						clients[i].DeleteAddress();
						std::cout << "�ش� ������ �����ϴ� . " << std::endl << std::endl;
					}
				}
			}
			break;

		case 2:
			std::cout << "��ȭ��ȣ�� �˻��մϴ� : " << std::endl;
			std::cin >> Address;
			for (int i = 0; i < client; i++)
			{
				if (clients[i].gethomeAddress() == Address)
				{
					clients[i].ShowAddress();
				}
				else if (clients[i].gethomeAddress() != Address)
				{
					std::cout << "�˻��Ͻ� ��ȭ��ȣ�� ã�� �� �����ϴ�." << std::endl;
				}
			}
			break;


		case 3:
			std::cout << "������ ������ �Է��ϼ��� : " << std::endl;
			std::cin >> Birthday;
			for (int i = 0; i < client; i++)
			{
				if (clients[i].getBirthDay() == Birthday)
				{
					std::cout << "������ ������ �����Դϴ�. ���� ���ϵ����!" << std::endl;
				}
				else if (clients[i].getBirthDay() != Birthday)
				{
					clients[i].calculator_BirthDDAY();
				}
			}
			break;

		case 4:
			std::cout << "�� ���� ������� Ȯ���մϴ�. , 1���� 12�������߿� �Ѵ��� �Է��ϼ��� : " << std::endl;
			std::cin >> Anniversary;
			for (int i = 0; i < client; i++)
			{
				if (Anniversary == 1)
				{
					std::cout << "�̴��� �����Դϴ�. �������� �Ͻʽÿ�." << std::endl;
				}
				else if (Anniversary == 2)
				{
					std::cout << "�̴��� 28�ϱ��� �ֽ��ϴ�." << std::endl;
				}
				else if (Anniversary == 3)
				{
					std::cout << "�̴��� ���� ���нĳ��� �ֽ��ϴ�." << std::endl;
				}
				else if (Anniversary == 4)
				{
					std::cout << "�̴��� ������ ��ȥ ������� �ֽ��ϴ�." << std::endl;
				}
				else if (Anniversary == 5)
				{
					std::cout << "�� ���� ������ ���� ź���� �Դϴ�." << std::endl;
				}
				else if (Anniversary == 6)
				{
					std::cout << "�� ���� ������ �θ���߿� ������ �ֽ��ϴ�." << std::endl;
				}
				else if (Anniversary == 7)
				{
					std::cout << "�� ���� ������ �ް� �Ⱓ�� �ֽ��ϴ�." << std::endl;
				}
				else if (Anniversary == 8)
				{
					std::cout << "�� ���� ������ ���� ������ �ֽ��ϴ�." << std::endl;
				}
				else if (Anniversary == 9)
				{
					std::cout << "�� ���� �߼��� �ֽ��ϴ�. ������ ���������� ���ϴ�." << std::endl;
				}
				else if (Anniversary == 10)
				{
					std::cout << "�� ���� ������ ���������� �ϴ� ���Դϴ�." << std::endl;
				}
				else if (Anniversary == 11)
				{
					std::cout << "�� ���� ������ �������Դϴ� , ���ϵ帳�ϴ�." << std::endl;
				}
				else if (Anniversary == 12)
				{
					std::cout << "�� ���� ���ϴ� ������ ������ �ֽ��ϴ�. ������ �ٳ������." << std::endl;
				}
				else
				{
					std::cout << "�� ���� ������� �����ϴ�. 4�� ���� 12������ �Է��Ͻʽÿ�." << std::endl;
				}
			}
			break;

		case 5:
			std::cout << "���α׷��� �����մϴ�." << std::endl;
			goto EXIT;
			break;

		default:
			std::cout << "�߸� �Է��ϼ̽��ϴ�." << std::endl;
			break;
		}
	}
	EXIT:
	delete[] clients;																		// 25���ο����� �����Ҵ��� ����
}