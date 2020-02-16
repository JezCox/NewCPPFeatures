#include "Cpp14Features.h"
#include <iostream>

void Cpp14Features::RunAllFeatures() const
{
	std::cout << "Running CPP14 features.." << std::endl;

	RunFunctionTypeDeductionDemo();
	RunGenericLambdas();
	RunExtendedCapturingInLambdas();
	RunNewConstExprFunctionality();
	RunDeprecatedAttribute();
	RunLiteralSyntacticImprovements();
	RunConstExprVariableTemplatesDemo();
}

auto someFunctionReturnTypeNotTypeStated() {
	return 6.5;
};

void Cpp14Features::RunFunctionTypeDeductionDemo() const
{
	std::cout << "RunFunctionTypeDeductionDemo()..." << std::endl;
	auto ret = someFunctionReturnTypeNotTypeStated();
	std::cout << "ret=" << ret << std::endl;
	std::cout << std::endl;
}



void Cpp14Features::RunGenericLambdas() const
{
	std::cout << "RunGenericLambdas()..." << std::endl;

	auto aGenericLambda = [](auto x, auto y) {return x * y; };
	std::cout << "inputs 4 and 5 --> " << aGenericLambda(4, 5) << std::endl;
	std::cout << "inputs 3.6 and 10.2 --> " << aGenericLambda(3.6, 10.2) << std::endl;

	std::cout << std::endl;

}

void Cpp14Features::RunExtendedCapturingInLambdas() const
{
	std::cout << "RunExtendedCapturingInLambdas()..." << std::endl;

	auto lambdaWithVariableCapture = [val = std::string("MyString")]{ return val.size(); };
	std::cout << "val string was size " << lambdaWithVariableCapture() << std::endl;

	std::cout << std::endl;
}

constexpr int factorial(int n) {
	// constexpr functions run very quickly - they existed in C++11 but were restrictive e.g. only one return statement
	// recursion can now be used in C++14 (factorial is a hackneyed cliche, granted)
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

void Cpp14Features::RunNewConstExprFunctionality() const
{
	std::cout << "RunNewConstExprFunctionality()..." << std::endl;
	std::cout << "factorial(9) = " << factorial(9) << std::endl;
	std::cout << std::endl;
}

void Cpp14Features::RunDeprecatedAttribute() const
{
	std::cout << "RunNewConstExprFunctionality()...[or rather am not]" << std::endl;

	/* commenting the below out - as c4996 is enabled as an error with the /sdl switch
	see https://docs.microsoft.com/en-us/cpp/build/reference/sdl-enable-additional-security-checks?redirectedfrom=MSDN&view=vs-2019
	Uncomment to see for yourself */
	//std::cout << "ADeprecatedMethod() returns" << ADeprecatedMethod() << std::endl;

	std::cout << std::endl;
}

void Cpp14Features::RunLiteralSyntacticImprovements() const
{
	std::cout << "RunLiteralSyntacticImprovements()..." << std::endl;

	long long someBigNumber = 3'000'000'000'000;
	int someBinaryLiteral = 0b0001'0010'0100'1000;
	std::cout << "someBigNumber:" << someBigNumber << std::endl;
	std::cout << "someBinaryLiteral:" << someBinaryLiteral << std::endl;

	std::cout << std::endl;

}


template<typename T>
constexpr T plancksconstant = T(6.626e-34);

template<typename T>
T freqToEnergy(T freq)
{
	return plancksconstant<T> * freq;
}

void Cpp14Features::RunConstExprVariableTemplatesDemo() const
{
	// again
	std::cout << "RunConstExprVariableTemplatesDemo()..." << std::endl;

	float fFreq = 5.7;
	double dblFreq = 42100.543;
	std::cout << "freqToEnergy(float) = " << freqToEnergy(fFreq) << std::endl;
	std::cout << "freqToEnergy(double) = " << freqToEnergy(dblFreq) << std::endl;

}


int Cpp14Features::ADeprecatedMethod() const
{
	std::cout << "I've been deprecated - did you not notice ?" << std::endl;
	return 5;
}




