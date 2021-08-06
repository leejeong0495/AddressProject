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

#include "Address.h"

Address::Address()										// 클래스의 생성자
{
	this->name = std::string("");
	this->email = std::string("");
	this->homeAddress = std::string("");
	this->FaxAddress = std::string("");
	this->memo = std::string("");
	this->BirthDay = uint32_t(0U);
	this->Anniversary = std::string("");
}

Address::~Address()										// 클래스의 소멸자
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



void Address::ShowAddress()										// 주소록 출력문을 보여주기 위한 함수 
{
	std::cout << "귀하의 이름은 : " << this->name << std::endl;
	std::cout << "귀하의 이메일은 : " << this->email << std::endl;
	std::cout << "귀하의 전화번호는 : " << this->homeAddress << std::endl;
	std::cout << "귀하의 팩스번호는 : " << this->FaxAddress << std::endl;
	std::cout << "귀하의 작성메모는 : " << this->memo << std::endl;
	std::cout << "귀하의 생일은 : " << this->BirthDay << std::endl;
}

void Address::DeleteAddress()									// 주소록 삭제 함수
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
	std::cout << "정보가 삭제되었습니다. " << std::endl;
}

void Address::calculator_BirthDDAY()
{
	time_t start, end;
	struct tm user_time;
	int timer_day, timer_hour, timer_min, timer_sec;
	double different;
	int my_year, my_month, my_day;

	std::cout << "희망하는 몇 년도 : ";
	std::cin >> my_year;

	std::cout << "희망하는 몇 월 : ";
	std::cin >> my_month;

	std::cout << "희망하는 몇 일 : ";
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

	std::cout << "생일 D-day는 : " << my_year << "년" << my_month << "월" << my_day << "일 부터 현재까지 " << timer_day << "일" << "남았습니다.";
}