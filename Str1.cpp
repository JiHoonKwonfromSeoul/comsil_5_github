#include "Str.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

Str::Str(int leng){ //길이 입력받아서 해당 길이만큼의 문자열 만들기
	len=leng;
	str=new char[len+1];
	str[0]='\0';
}

Str::Str(char *neyong){ //neyong에 초기화할 내용이 기입된다. 
	len=strlen(neyong); //len이 neyong의 길이를 받음.
	str=new char[len+1]; //str 생성
	strcpy(str, neyong); //str으로 copy
	str[len]='\0'; //끝맺음
}

Str::~Str(){ //Free 기능 수행.
	delete[] str; //명령어인 delete
}

int Str::length(){ //string 길이 return
	return len; //위에서 표시됐듯이 len이 길이다.
}

char* Str::contents(){ //string 내용return
	return str; //str이 내용이다.
}

int Str::compare(class Str &a){ //a의 내용과 비교. a의 클라스에 접근.
	return strcmp(str, a.contents()); //a.contents와 str비교.
}

int Str::compare(char *a){ //이것은 a의 내용과 비교.
	return strcmp(str, a); //비교.
}

void Str::operator=(char *a){ //string의 값 입력하기.
	if (a==NULL){ //a가 내용이 없으면
		len=0; //길이 0으로 입력.
		delete[] str; //메모리 free
		str=new char[1]; //하나짜리로.
		str[0]='\0'; //사실상 NULL
		return;
	}
	else{ //a 내용 있으면
		delete[] str; //메모리 free
		len=strlen(a); //a의 길이 복사.
		str=new char[len+1]; //str길이 설정.
		strcpy(str, a); //str으로 복사.
		return;
	}
}

void Str::operator=(class Str &a){ //Str의 내용 입력.
	delete[] str; //메모리 free
	len=a.length(); //class a의 길이.
	str=new char[len+1]; //str길이 설정.
	strcpy(str,a.contents()); //str으로 a.contents의 내용 복사
}

