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


#pragma once
#include <iostream>
#include <string>
#include <ctime>

class Address
{
private:
	std::string name;										// 이름
	std::string email;										// 이메일
	std::string homeAddress;								// 전화 번호
	std::string FaxAddress;									// 팩스 번호
	std::string memo;										// 메모
	uint32_t BirthDay{ 0U };								// 생일 계산
	std::string Anniversary;								// 기념일
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

