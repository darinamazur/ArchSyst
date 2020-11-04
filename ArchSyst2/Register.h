#pragma once
#include <iostream>
#include <vector>
#include <string>

class Register{
public:
	int N;
	std::string name_;
	std::vector<int> value_vec;
	std::vector<int> Add(std::vector<int>, std::vector<int>);
	void Set(int&,std::string,int);
	void Update(int&);
	char GetSign();
	void copy(Register&, const Register&);
	void OutputVec();
	std::vector<int> Convert(int&);
private:
	std::vector<int> Add_vectors(std::vector<int>, std::vector<int>);
	std::vector<int> Inverse(std::vector<int>);
};

