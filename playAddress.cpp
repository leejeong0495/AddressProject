//주소록 만들기 프로젝트
//1. 이름
//2. 이메일
//3. 전화번호
//4. 팩스번호
//5. 메모
//6. 생년월일 검색 시 (#include <ctime>) , 현재 생일이라면 "Happy Birthday!"
//7. 기념일	   검색 시 (#include <ctime>) , 생일의 D-day  "D-xx"
//
//========================================================================
//1. 주소록 입력하기
//2. 검색 --------------------> 1.이름 2. 전화번호 검색
//							  생일 ----> 생일축하해요
//							  기념일 --> 현재 기념일 , D-xx
//							  이름 , 이메일 , 전화번호 , 팩스번호 , 메모 다 Show

#include <iostream>
#include "Address.h"

int main()
{
	uint32_t client{ 0U };											// 입력할 사람 수 초기화
	std::cout << "정보를 저장할 사람의 숫자를 입력하세요 : ";
	std::cin >> client;
	Address* clients  = { new Address[client] };					// 클래스의 포인터를 받는 변수 동적할당을 하고 초기화
	uint32_t index{ 0U };											// 출력문 인덱스 초기화
	

	for (;;)
	{
		while (index < client)
		{
			std::cout << "이름을 입력하세요 : ";
			char client_name[100];
			std::cin >> client_name;
			clients[index].setname(client_name);
			std::cout << std::endl;

			std::cout << "생일을 입력하세요 : ";
			uint32_t client_birthday = { 0U };
			std::cin >> client_birthday;
			clients[index].setBirthDay(client_birthday);
			std::cout << std::endl;

			std::cout << "이메일을 입력하세요 : ";
			char client_email[100];
			std::cin >> client_email;
			clients[index].setemail(client_email);
			std::cout << std::endl;

			std::cout << "전화번호를 입력하세요 : ";
			std::string client_home_address = { 0 };
			std::cin >> client_home_address;
			clients[index].sethomeAddress(client_home_address);
			std::cout << std::endl;

			std::cout << "팩스번호를 입력하세요 : ";
			std::string client_Fax_address = { 0 };
			std::cin >> client_Fax_address;
			clients[index].setFaxAddress(client_Fax_address);
			std::cout << std::endl;

			std::cout << "메모를 입력하세요 : ";
			char client_memo[100];
			std::cin >> client_memo;
			clients[index].setmemo(client_memo);
			std::cout << std::endl;

			index++;

			std::cout << " >> 정보가 저장되었습니다. " << std::endl << std::endl;
		}
		std::cout << "※※※※※※※※※※※※※※※※※※※※※※※※" << std::endl;
		std::cout << "1.이름 검색과 정보 출력 , 삭제할 항목" << std::endl;
		std::cout << "2.전화번호 검색" << std::endl;
		std::cout << "3.생일 확인" << std::endl;
		std::cout << "4.이달의 기념일 확인" << std::endl;
		std::cout << "5.종료" << std::endl;
		std::cout << "※※※※※※※※※※※※※※※※※※※※※※※※" << std::endl;
		
		// switch_case문에 들어가는 변수들 초기화
		uint32_t select_menu{ 0U };			// 입력메뉴
		std::cin >> select_menu;
		char name[100];						// 입력할 배열의 크기
		std::string Address{ 0U };
		uint32_t Birthday{ 0U };
		uint32_t Anniversary{ 0U };
		std::string delete_name{""};
		std::string delete_num{ "" };
		uint32_t menu{ 0U };				// switch case 1번의 조건문 메뉴 입력 초기화
		uint32_t Menu_select{ 0U };

		switch (select_menu)
		{
		case 1:
			std::cout << "선택할 메뉴를 고르십시오. 1:정보출력 2:이름삭제 3:번호삭제" << std::endl;
			std::cin >> menu;

			if (menu == 1)										// 정보를 검색하고 출력할 조건
			{
				std::cout << "정보검색과 출력" << std::endl;
				std::cout << "이름을 입력하세요 : ";
				std::cin >> name;
				for (int i = 0; i < client; i++)
				{
					if (clients[i].getname() == name)
					{
						clients[i].ShowAddress();
					}
					std::cout << "해당하는 정보가 없습니다." << std::endl;
				}
			}
			else if (menu == 2)									// 이름을 삭제할 조건
			{
				std::cout << "이름삭제" << std::endl;
				std::cout << "삭제할 이름을 입력하세요 : ";
				std::cin >> delete_name;
				for (int i = 0; i < client; i++)
				{
					if (clients[i].getname() == delete_name)
					{
						clients[i].Delete_Address();
						clients[i].DeleteAddress();
						std::cout << "해당 정보가 없습니다 . " << std::endl << std::endl;
					}
				}
			}

			else if (menu == 3)									// 번호를 삭제할 조건
			{
				std::cout << "번호삭제" << std::endl;
				std::cout << "삭제할 번호를 입력하세요 : " << std::endl;
				std::cin >> delete_num;
				for (int i = 0; i < client; i++)
				{
					if (clients[i].gethomeAddress() == delete_num)
					{
						clients[i].Delete_Address();
						clients[i].DeleteAddress();
						std::cout << "해당 정보가 없습니다 . " << std::endl << std::endl;
					}
				}
			}
			break;

		case 2:
			std::cout << "전화번호를 검색합니다 : " << std::endl;
			std::cin >> Address;
			for (int i = 0; i < client; i++)
			{
				if (clients[i].gethomeAddress() == Address)
				{
					clients[i].ShowAddress();
				}
				else if (clients[i].gethomeAddress() != Address)
				{
					std::cout << "검색하신 전화번호를 찾을 수 없습니다." << std::endl;
				}
			}
			break;


		case 3:
			std::cout << "귀하의 생일을 입력하세요 : " << std::endl;
			std::cin >> Birthday;
			for (int i = 0; i < client; i++)
			{
				if (clients[i].getBirthDay() == Birthday)
				{
					std::cout << "오늘은 귀하의 생일입니다. 생일 축하드려요!" << std::endl;
				}
				else if (clients[i].getBirthDay() != Birthday)
				{
					clients[i].calculator_BirthDDAY();
				}
			}
			break;

		case 4:
			std::cout << "이 달의 기념일을 확인합니다. , 1부터 12월까지중에 한달을 입력하세요 : " << std::endl;
			std::cin >> Anniversary;
			for (int i = 0; i < client; i++)
			{
				if (Anniversary == 1)
				{
					std::cout << "이달은 설날입니다. 안전운행 하십시오." << std::endl;
				}
				else if (Anniversary == 2)
				{
					std::cout << "이달은 28일까지 있습니다." << std::endl;
				}
				else if (Anniversary == 3)
				{
					std::cout << "이달은 딸의 입학식날이 있습니다." << std::endl;
				}
				else if (Anniversary == 4)
				{
					std::cout << "이달은 귀하의 결혼 기념일이 있습니다." << std::endl;
				}
				else if (Anniversary == 5)
				{
					std::cout << "이 달은 귀하의 딸의 탄생월 입니다." << std::endl;
				}
				else if (Anniversary == 6)
				{
					std::cout << "이 달은 귀하의 부모님중에 생신이 있습니다." << std::endl;
				}
				else if (Anniversary == 7)
				{
					std::cout << "이 달은 귀하의 휴가 기간이 있습니다." << std::endl;
				}
				else if (Anniversary == 8)
				{
					std::cout << "이 달은 귀하의 부인 생일이 있습니다." << std::endl;
				}
				else if (Anniversary == 9)
				{
					std::cout << "이 달은 추석이 있습니다. 귀하의 안전운행을 빕니다." << std::endl;
				}
				else if (Anniversary == 10)
				{
					std::cout << "이 달은 귀하의 연말정산을 하는 달입니다." << std::endl;
				}
				else if (Anniversary == 11)
				{
					std::cout << "이 달은 귀하의 승진일입니다 , 축하드립니다." << std::endl;
				}
				else if (Anniversary == 12)
				{
					std::cout << "이 달은 귀하님 가족의 여행이 있습니다. 조심히 다녀오세요." << std::endl;
				}
				else
				{
					std::cout << "이 달은 기념일이 없습니다. 4월 부터 12월까지 입력하십시오." << std::endl;
				}
			}
			break;

		case 5:
			std::cout << "프로그램을 종료합니다." << std::endl;
			goto EXIT;
			break;

		default:
			std::cout << "잘못 입력하셨습니다." << std::endl;
			break;
		}
	}
	EXIT:
	delete[] clients;																		// 25라인에서의 동적할당을 해제
}