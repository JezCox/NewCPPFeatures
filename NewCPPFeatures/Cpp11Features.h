#pragma once

// This is C++ - we'll have no camel-casing here...

#include "CppFeaturesBase.h"

#include <iostream>
#include <future>
#include <string>
#include <map>

class Cpp11Features :
	public CppFeaturesBase
{
private:

public:
	Cpp11Features() = default;
	Cpp11Features(const Cpp11Features&) = delete;				// no copying
	Cpp11Features& operator=(const Cpp11Features&) = delete;	// no reassignment

	virtual void RunAllFeatures() const;

	void RunAutoTypes() const;
	void RunLambdas() const;
	void RunUniformInitialisationSyntax() const;
	void RunNullPtr() const;
	void RunDelegatingConstructors() const;
	void RunRValueReferences() const;
	void RunNewContainerClassesDemo() const;
	void RunNewThreadingFeatures() const;
	void RunNewSmartPointersDemo() const;
	void RunNewAlgos() const;
	void RunUsingTuples() const;
	void RunScopedEnumsDemo() const;
	void RunVariadicTemplatesDemo() const;

private:
	static void SimpleSMethod();
	static void SomeCalculation(int n, std::promise<int>* pPromise);
	static int CalculationForAsync(int n);
	static std::map<std::string, long> MockCreateSomeData(std::string strIn);

};

// could make these inner classes to above (?)
class DelegatingCtorClass {
private:
	int _iVal1, _iVal2;
	double _dblVal3;
	int _anArr[5];	// init of this is new to C++11 (see below)
public:
	DelegatingCtorClass(int val1Only) : _iVal1(val1Only), _iVal2(12), _dblVal3(4.7), _anArr{2,4,6,8,10} {}
	DelegatingCtorClass() : DelegatingCtorClass(5) { std::cout << "Default calling delegated" << std::endl; }
};


class Announcing {
private:
	int _nId;
public:
	Announcing(int nId) : _nId(nId) { std::cout << "Announcing ctor..[id:" << _nId << "]" << std::endl; }
	Announcing(const Announcing& an) = delete;
	void DoSomething() const { std::cout << "Saying hello [id:" << _nId << "]" << std::endl; }
	virtual ~Announcing() { std::cout << "Announcing dtor..[id:" << _nId << "]" << std::endl; }
};