#pragma once

#include <iostream>

#include "CppFeaturesBase.h"
class Cpp17Features :
	public CppFeaturesBase
{
private:

public:
	Cpp17Features() = default;
	Cpp17Features(const Cpp17Features&) = delete;
	Cpp17Features& operator=(const Cpp17Features&) = delete;

	virtual void RunAllFeatures() const;

	void RunAutoInitWithBraces() const;
	void RunStructuredBindings() const;
	void RunFoldExpressions() const;
	void RunTemplateArgumentDeduction() const;
	void RunForIfSwitchInitialisers() const;

	void RunNewLibDataTypesAdditions() const ;
	void RunNewLibInvokeAdditions() const ;
	void RunNewAlgos() const;


};

class IntIntDoubleClass {
private:
	int i1;
	int i2;
	double d;

public:
	IntIntDoubleClass(int i1, int i2, double d)
		: i1(i1), i2(i2), d(d) {}
	void displayContents() { std::cout << i1 << "-" << i2 << "-" << d; }
};

