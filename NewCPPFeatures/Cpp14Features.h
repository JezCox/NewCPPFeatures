#pragma once

#include "CppFeaturesBase.h"

class Cpp14Features :
	public CppFeaturesBase
{
private:

public:
	Cpp14Features() = default;
	Cpp14Features(const Cpp14Features&) = delete;
	Cpp14Features& operator=(const Cpp14Features&) = delete;

	virtual void RunAllFeatures() const;

	void RunFunctionTypeDeductionDemo() const;
	void RunGenericLambdas() const;
	void RunExtendedCapturingInLambdas() const;
	void RunNewConstExprFunctionality() const;
	void RunDeprecatedAttribute() const;
	void RunLiteralSyntacticImprovements() const;
	void RunConstExprVariableTemplatesDemo() const;

private:	
	[[deprecated("You really shouldn't be using this")]]
	int ADeprecatedMethod() const;

};

auto someFunctionReturnTypeNotTypeStated();
constexpr int factorial(int n);
