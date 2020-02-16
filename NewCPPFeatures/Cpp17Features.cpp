#include "Cpp17Features.h"
#include <iostream>
#include <tuple>
#include <map>
#include <variant>
#include <optional>
#include <any>
#include <vector>
#include <algorithm>
#include <functional>
#include <execution>
#include <numeric>
#include <array>

void Cpp17Features::RunAllFeatures() const
{
	std::cout << "Running CPP17 features.." << std::endl;

	RunAutoInitWithBraces();
	RunStructuredBindings();
	RunFoldExpressions();
	RunTemplateArgumentDeduction();
	RunForIfSwitchInitialisers();

	RunNewLibDataTypesAdditions();
	RunNewLibInvokeAdditions();
	RunNewAlgos();

}

void Cpp17Features::RunAutoInitWithBraces() const
{
	// actually a restriction on prior usage !
	std::cout << "RunAutoInitWithBraces()..." << std::endl;

	auto a = { 42 };   // std::initializer_list<int>
	auto b{ 42 };     // int
	auto c = { 1, 2 }; // std::initializer_list<int>
	//auto d{ 1, 2 };   // error, too many E2263

	std::cout << "a:" << typeid(a).name() << std::endl;
	std::cout << "b:" << typeid(b).name() << std::endl;
	std::cout << "c:" << typeid(c).name() << std::endl;

	std::cout << std::endl;
}


void Cpp17Features::RunStructuredBindings() const
{
	std::cout << "RunStructuredBindings()..." << std::endl;
	auto tuple = std::make_tuple(4, 3.1, 'v', "carrot");

	// no need to use std::tie() anymore...
	auto [i, d, c, str] = tuple;

	std::cout << "i:" << i << "; d:" << d << "; c:" << c << "; str:" << str << std::endl;
	std::cout << std::endl;
}


template<typename ...Args> 
auto multiply(Args ...args)
{
	return (args * ...);
}
template<typename ...Args>
void FoldPrint(Args&&... args) 
{
	(std::cout << ... << std::forward<Args>(args)) << '\n';
}
void Cpp17Features::RunFoldExpressions() const
{

	std::cout << "RunFoldExpressions()..." << std::endl;
	int x = multiply(4, 5, 3);
	std::cout << x << std::endl;
	x = multiply(10, 20, 30, 40);
	std::cout << x << std::endl;
	FoldPrint("hello", 33, 76.5, "badger");

	std::cout << std::endl;
}

void Cpp17Features::RunTemplateArgumentDeduction() const
{
	std::cout << "RunTemplateArgumentDeduction()..." << std::endl;

	std::cout << std::endl;
}

void Cpp17Features::RunForIfSwitchInitialisers() const
{
	std::cout << "RunForIfSwitchInitialisers()..." << std::endl;
	std::map<std::string, int> animals {
		{"tigers", 4},
		{"lions", 10},
		{"bears", 15},
	};

	// note "result"'s scope only within the if block
	if (auto result = animals.find("tigers"); result != cend(animals))
	{
		// found tigers
		std::cout << "tigers = " << result->second << std::endl;
	}

	// similarly with "present" for the switch block
	switch (auto present = animals.find("bears"); present->second)
	{
		case 15:
			std::cout << "As expected" << std::endl;
			break;
		default:
			std::cout << "Not as expected" << std::endl;
			break;
	}

	std::cout << std::endl;
}


void Cpp17Features::RunNewLibDataTypesAdditions() const
{
	std::cout << "RunNewLibDataTypesAdditions()..." << std::endl;

	// std::variant (a type-safe union)
	std::variant<int, double> var;
	var = 12;
	std::cout << "var:" << std::get<int>(var) << std::endl;
	//std::cout << "var:" << std::get<double>(var) << std::endl;		// this would cause a bad_variant_access exception
	var.emplace<1>(1345.723487);
	std::cout << "var:" << std::get<double>(var) << std::endl;		// now it's ok

	// std::optional
	std::optional<std::string> optContaining("hello");
	std::optional<std::string> optNotContaining;
	std::cout << "optContaining:" << optContaining.value_or("empty") 
		<< ", optNotContaining:" << optNotContaining.value_or("empty") << std::endl;

	// std::any
	std::any val = 25;
	std::cout << "val:" << std::any_cast<int>(val) << std::endl;
	val = 34.6;
	std::cout << "val:" << std::any_cast<double>(val) << std::endl;
	
	// don't do this though !
	//val = "some string";
	//std::cout << "val:" << std::any_cast<std::string>(val) << std::endl;
	std::any sval{ std::string("somestring") };
	std::cout << "sval:" << std::any_cast<std::string>(sval) << std::endl;

	// std::string_view
	// (cheaper than using string::substr() - which returns a new string)
	std::string aString = "some unnecessarily verbose string";
	std::string_view view = aString;
	std::cout << view.substr(7, 11) << std::endl;

	// std::byte (pretty much what you'd expect - inspired by Java?)
	std::byte aByte{ 0b0011 };
	std::cout << "aByte before:" << std::to_integer<int>(aByte) << std::endl;
	aByte <<= 2;
	std::cout << "aByte after:" << std::to_integer<int>(aByte) << std::endl;

	std::cout << std::endl;
}


void Cpp17Features::RunNewLibInvokeAdditions() const
{
	std::cout << "RunNewLibInvokeAdditions()..." << std::endl;

	auto averagingLambda = [](auto first, auto second, auto third, auto fourth) {return (first + second + third + fourth) / 4; };

	// std::apply
	std::array<int, 4> anArray = { 2, 4, 6, 8};
	int resApply = std::apply(averagingLambda, anArray);
	std::cout << "resApply:" << resApply << std::endl;

	// std::invoke
	double resInvoke = std::invoke(averagingLambda, 1.0, 2.0, 3.0, 4.0);
	std::cout << "resInvoke:" << resInvoke << std::endl;
	
	// std::make_from_tuple (allows an object to be made directly from a tuple !)
	IntIntDoubleClass intintDoubleObj = std::make_from_tuple<IntIntDoubleClass>
															(std::make_tuple(7, 19, 256.332) );
	intintDoubleObj.displayContents();
	
	std::cout << std::endl;
}

void Cpp17Features::RunNewAlgos() const
{
	std::cout << "RunNewAlgos()..." << std::endl;

	//std::for_each_n (same as for_each - but only for the first n
	std::vector<int> vNums{ 10, 20, 30, 40, 50 };
	auto plus5Lambda = [](auto& x) {x += 5; };
	std::for_each_n(vNums.begin(), 3, plus5Lambda);
	std::cout << "vNums(post): {";
	for (auto& num : vNums)
	{
		std::cout << num << " ";
	}
	std::cout << "}" << std::endl;


	// std::reduce - can run sequentially, in parallel (and otherwise)
	vNums = { 1,2,3,4,5 };
	auto add5AndSumLambda = [](int x, int y) -> int {return (x + 5) + y; };		// will do as a BinaryOp 
	auto t1 = std::chrono::high_resolution_clock::now();
	int result = std::reduce(std::execution::seq, vNums.begin(), vNums.end(), 0, add5AndSumLambda);	// would default to summing per std::accumulate()
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> rrSeq = t2 - t1;

	t1 = std::chrono::high_resolution_clock::now();
	result = std::reduce(std::execution::par, vNums.begin(), vNums.end(), 0, add5AndSumLambda);
	t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> rrPar = t2 - t1;
	std::cout << "Result of std::reduce():" << result		// (1+5)+(2+5)+... + (5+5)
		<< " (seq took " << rrSeq.count() << ", par took " << rrPar.count() << ")" << std::endl;


	// std::transform_reduce (compound algo of transform and reduce obv)
	vNums = { 1,2,3,4,5 };
	auto magnifyingLambda = [](int x) -> int {return x * 10; };	// our UnaryOp		
	auto summingLambda = [](int x, int y) -> int {return x + y; };	// our BinaryOp
	int trResult = std::transform_reduce(std::execution::seq, vNums.begin(), vNums.end(), 0, summingLambda, magnifyingLambda);
	std::cout << "trResult:" << trResult << std::endl;	// 150 !! ({1,2,3,4,5}*10) then summed

	// std::exclusive_scan
	std::vector<int> voutExc(5);
	auto exclScanResult = std::exclusive_scan(vNums.begin(), vNums.end(), voutExc.begin(), 0);
	std::cout << "std::exclusive_scan() output: ";
	for (auto val : voutExc)
	{
		std::cout << val << ",";
	}
	std::cout << std::endl;


	// std::inclusive_scan (defaults to using std::plus())
	std::vector<int> voutInc(5);
	auto inclScanResult = std::inclusive_scan(vNums.begin(), vNums.end(), voutInc.begin());
	std::cout << "std::inclusive_scan() output: ";
	for (auto val : voutInc)
	{
		std::cout << val << ",";
	}
	std::cout << std::endl;


	// std::transform_exclusive_scan (combo of exclusive_scan and transform of course)
	std::vector<int> vExIn = { 1,2,3,4,5,6,7,8,9};
	std::vector<int> vExOut(vExIn.size());
	auto binaryOpLambda = [](auto el1, auto el2) {return el1 + el2; };
	auto unaryOpLambda = [](auto el) {return el*=3; };
	std::transform_exclusive_scan(std::execution::par,
		vExIn.begin(), vExIn.end(),
		vExOut.begin(), 0,
		binaryOpLambda,
		unaryOpLambda);
	std::cout << "std::transform_exclusive_scan() output: ";
	for (auto str : vExOut)
	{
		std::cout << str << ", ";
	}
	std::cout << std::endl;


	// std::transform_inclusive_scan
	std::vector<std::string> vIncIn = { "The cat", "sat on", "the mat" };
	auto unaryOpLambda2 = [](auto el) {return el + "!"; };
	std::vector<std::string> vIncOut(vIncIn.size());
	std::transform_inclusive_scan(vIncIn.begin(), vIncIn.end(),
		vIncOut.begin(),
		binaryOpLambda,
		unaryOpLambda2);
	std::cout << "std::transform_inclusive_scan() output:";
	for (auto str : vIncOut)
	{
		std::cout << str << ", ";
	}


	std::cout << std::endl;

}
