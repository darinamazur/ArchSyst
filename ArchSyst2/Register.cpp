#include "Register.h"

std::vector<int> Register::Inverse(std::vector<int>vec) {
	std::vector<int> res; res.resize(12);
	vec[0] = 0;
	for (int i(0); i < 12; i++) {
		res[i] = (vec[i] + 1) % 2;
	}
	std::vector<int> one; one.resize(12); one[11] = 1;
	return Add_vectors(res,one);
}

std::vector<int> Register::Add_vectors(std::vector<int>first, std::vector<int>second) {
	std::vector<int> res; res.resize(12);
	for (int i(11); i >= 0; i--) {
		res[i] = (first[i] + second[i]) % 2;
		if (i >= 1) first[i - 1] += (first[i] + second[i]) / 2;
	}
	return res;
}
std::vector<int> Register::Add(std::vector<int> first, std::vector<int> second) {
	if (first[0] == 1) first = Inverse(first);
	if (second[0] == 1)second = Inverse(second);
	return Add_vectors(first,second);
	
}
std::vector<int> Register::Convert(int& value) {
	std::vector<int> res; res.resize(12);
	int index(0);
	int temp = abs(value);
	for (int i(11); i >= 0; i--) {
		res[i] = temp % 2;
		temp /= 2;
		if (temp == 0) {
			index = i;
			break;
		}
	}

	for (size_t i(0); i < index; i++)
		res[i] = 0;
	if (value < 0) res[0] = 1;
	return res;
}

void Register::Set(int&N_,std::string name,int value) {
	N = N_;
	name_ = name;
	value_vec = Convert(value);
}

void Register::Update(int& value) {
	value_vec = Convert(value);
}

char Register::GetSign() {
	return (value_vec[0] == 1) ? '-' : '+';
}

void Register::copy(Register& to, const Register& from) {
	for (int i(0); i < from.value_vec.size(); i++) {
		to.value_vec[i] = from.value_vec[i];
	}
}

void Register::OutputVec() {
	for (int i(0); i < N; i++)
		std::cout << value_vec[i];
	std::cout << std::endl;

}