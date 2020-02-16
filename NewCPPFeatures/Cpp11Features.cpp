#include "Cpp11Features.h"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <thread>
#include <future>

void Cpp11Features::RunAllFeatures() const
{
	// and run all new features...
	std::cout << "Running CPP11 features.." << std::endl;
	RunAutoTypes();
	RunLambdas();
	RunUniformInitialisationSyntax();
	RunNullPtr();
	RunDelegatingConstructors();
	RunRValueReferences();
	RunNewContainerClassesDemo();
	RunNewThreadingFeatures();
	RunNewSmartPointersDemo();
	RunNewAlgos();
	RunUsingTuples();
	RunScopedEnumsDemo();
	RunVariadicTemplatesDemo();

}

void Cpp11Features::RunAutoTypes() const
{
	std::cout << "runAutoTypes()..." << std::endl;

	auto someInt = 1;
	std::cout << "someInt:" << someInt << std::endl;
	auto someChar = 'b';
	std::cout << "someChar:" << someChar << std::endl;
	auto someDouble = 0.5;
	std::cout << "someDouble:" << someDouble << std::endl;
	auto someLong = 234234L;
	std::cout << "someLong:" << someLong << std::endl;

	// decltype usefulness (??)
	typedef decltype (someChar) whatIsThis;
	whatIsThis something{};
	std::cout << something << std::endl;
	std::cout << std::endl;

}

void Cpp11Features::RunLambdas() const
{
	std::cout << "runLambdas()..." << std::endl;

	// sorting 
	auto lambdaForSort = [](const int& x, const int& y) -> bool
	{
		return x < y;
	};

	std::vector<int> vToSort = { 2, 10, 6, 34, 12 };
	std::cout << "Before sort: " << std::endl;
	for (int i = 0; i < static_cast<int>(vToSort.size()); ++i)
		std::cout << vToSort[i] << std::endl;

	sort(vToSort.begin(), vToSort.end(), lambdaForSort);
	std::cout << "After sort: " << std::endl;
	for (int i = 0; i < vToSort.size(); ++i)
		std::cout << vToSort[i] << std::endl;

	auto lambdaForAccumulate = [](int i, int j) -> int {return i + j; };
	int sum = std::accumulate(vToSort.begin(), vToSort.end(), 0, lambdaForAccumulate);
	std::cout << "Result of accumulate:" << sum << std::endl;

	// e.g of use of a capture clause lambda (& = capture external by ref)
	auto lambdaToAddNumToVect = [&](int num) -> void
	{
		vToSort.push_back(num);
	};
	lambdaToAddNumToVect(400);
	std::cout << "After lambda vector add: " << std::endl;
	for (int i = 0; i < vToSort.size(); ++i)
		std::cout << vToSort[i] << std::endl;
	std::cout << std::endl;

}

void Cpp11Features::RunUniformInitialisationSyntax() const
{
	std::cout << "runUniformInitialisationSyntax()..." << std::endl;
	int m = int();
	int arr[4] = { 5, 4, 3, 2 };

	std::cout << "m:" << m << std::endl;
	std::cout << "arr:" << arr << std::endl;

	// couldn't do this before
	std::vector<std::string> languages = { "C++", "Java", "Scala" };
	std::cout << "languages1:" << languages.at(1) << std::endl;

	//nor this
	std::map<std::string, int> players =
	{
		{"Woodman", 27},
		{"Roberts", 23},
		{"Borja", 9},
		{"Routledge", 11},
		{"Dhanda", 21}
	};
	std::cout << "players: Roberts is no " << players.at("Roberts") << std::endl;
	for (const auto& entry : players)	//  nor this !
	{
		std::cout << "Player:" << entry.first << "-->" << entry.second << std::endl;
	}
	std::cout << std::endl;
}

void Cpp11Features::RunNullPtr() const
{
	std::cout << "RunNullPtr()..." << std::endl;

	// no more 0, no more NULL
	int* myIntPtr = nullptr;
	char* myCharPtr(nullptr);

	if (!myCharPtr)
	{
		std::cout << "CharPtr is null" << std::endl;
	}

	std::cout << "Cpp11Features::RunNullPtr() - attempting null ptr delete" << std::endl;
	delete myIntPtr;
	delete myCharPtr;
	std::cout << "Cpp11Features::RunNullPtr() - was safe" << std::endl;
	std::cout << std::endl;

}

void Cpp11Features::RunDelegatingConstructors() const
{
	std::cout << "RunDelegatingConstructors()..." << std::endl;

	DelegatingCtorClass dcClass;
	std::cout << std::endl;
}

void Cpp11Features::RunRValueReferences() const
{
	// how to demo this ??
}

void Cpp11Features::RunNewContainerClassesDemo() const
{
	std::cout << "RunNewContainerClassesDemo()..." << std::endl;

	//unordered_set, unordered_map, unordered_multiset, and unordered_multimap
	std::unordered_set<long> unorderedSet = { 1, 4, 7, 2, 12, 2 };
	std::for_each(unorderedSet.begin(), unorderedSet.end(), [](long const& el) -> void { std::cout << "UOS element: " << el << std::endl; });

	std::unordered_map<std::string, long> unorderedMap = {
		{"One", 1},
		{"Ten", 10},
		{"Four", 4},
		{"Three", 3},
		{"Seven", 7},
		{"Ten", 10},
		{"Three", 3}
	};
	std::for_each(unorderedMap.begin(), unorderedMap.end(), [](auto const& pair) -> void { std::cout << "UOM element: " << pair.first << "-->" << pair.second  << std::endl; });

	std::unordered_multiset<long> unorderedMultiset = { 4, 3, 5, 1, 1, 4, 7, 3, 2, 3 };
	std::for_each(unorderedMultiset.begin(), unorderedMultiset.end(), [](long const& el) -> void { std::cout << "UOMS element: " << el << std::endl; });

	std::unordered_multimap<std::string, long> unorderedMultimap = {
		{"One", 1},
		{"Ten", 10},
		{"Four", 4},
		{"Three", 3},
		{"Seven", 7},
		{"Ten", 10},
		{"Three", 3}
	};
	std::for_each(unorderedMultimap.begin(), unorderedMultimap.end(), [](auto const& pair) -> void { std::cout << "UOMM element: " << pair.first << "-->" << pair.second << std::endl; });

	std::cout << std::endl;
}

void Cpp11Features::RunNewThreadingFeatures() const
{
	std::cout << "RunNewThreadingFeatures()..." << std::endl;

	// simple execution thread 
	std::cout << "Main thread [" << std::this_thread::get_id() << "] about to launch SimpleSMethod on seperate thread" << std::endl;
	std::thread thrd(Cpp11Features::SimpleSMethod);
	thrd.join();

	// promise
	std::promise<int> aPromise;
	std::future<int> aFuture = aPromise.get_future();
	std::thread thrdFut(Cpp11Features::SomeCalculation, 10, &aPromise);
	std::cout << "Future value retrieved from Cpp11Features::SomeCalculation = " << aFuture.get() << std::endl;
	thrdFut.join();

	// async
	std::future<int> aFuture2 = std::async(Cpp11Features::CalculationForAsync, 120);
	std::cout << "Value retrieved from Cpp11Features::CalculationForAsync = " << aFuture2.get() << std::endl;


	// packaged_task
	std::packaged_task<std::map<std::string, long>(std::string)> task(Cpp11Features::MockCreateSomeData);
	std::future<std::map<std::string, long> > result = task.get_future();
	std::thread thrdPT(std::move(task), "Hello");
	thrdPT.join();
	std::map <std::string, long> dataGenerated = result.get();
	std::for_each(dataGenerated.begin(), dataGenerated.end(), [](auto const& pair) -> void { std::cout << "packaged_task element: " << pair.first << "-->" << pair.second << std::endl; });

	// use of thread local storage - see Cpp11Features::SimpleSMethod

	std::cout << std::endl;
}

void Cpp11Features::RunNewSmartPointersDemo() const
{
	// LOOK - no new/deletes !!!
	std::cout << "RunNewSmartPointersDemo()..." << std::endl;

	// unique_ptr, shared_ptr, weak_ptr
	{
		// (got a vague feeling std::make_unique<> might be C++14 ?)
		std::unique_ptr<Announcing> pAnnouncing = std::make_unique<Announcing>(1);
		pAnnouncing->DoSomething();

		std::unique_ptr<Announcing> pMovedToAnnouncing = std::move(pAnnouncing);
		pMovedToAnnouncing->DoSomething();
	}

	std::cout << std::endl;

	{
		std::shared_ptr<Announcing> spAnnouncing = std::make_shared<Announcing>(2);
		std::cout << "spAnnouncing usecount=" << spAnnouncing.use_count() << std::endl;
		spAnnouncing->DoSomething();
		std::shared_ptr<Announcing> spAnnouncing2(spAnnouncing);
		std::cout << "(after spAnnouncing2) spAnnouncing usecount=" << spAnnouncing.use_count() << std::endl;
		spAnnouncing2->DoSomething();
		{
			std::shared_ptr<Announcing> spAnnouncing3 = spAnnouncing;
			std::cout << "(after spAnnouncing3) spAnnouncing use count=" << spAnnouncing.use_count() << std::endl;
			spAnnouncing3->DoSomething();
		}
		std::cout << "(outside spAnnouncing3 scope) spAnnouncing use count=" << spAnnouncing.use_count() << std::endl;

		// weak_ptr: no ref count increase + no dtor delete
		std::weak_ptr<Announcing> wpAnnouncing(spAnnouncing);
		std::cout << "(after weak_ptr wpAnnouncing) spAnnouncing use count=" << spAnnouncing.use_count() << std::endl;
	}

	std::cout << std::endl;
}

void Cpp11Features::RunNewAlgos() const
{
	std::cout << "RunNewAlgos()..." << std::endl;

	std::vector<long> vNums = {-1, 2, 6, 4, 2, 7, -3 };
	std::vector<long> vNums2 = {10, 20, 30, 40, 50};
	std::vector<long> vNums3 = {-20, -40, -5, -32 };

	// all_of()
	auto isPositive = [](int n) -> bool{ return n > 0; };
	bool isVNumsAllPositive = std::all_of(vNums.cbegin(), vNums.cend(), isPositive);
	bool isVNums2AllPositive = std::all_of(vNums2.cbegin(), vNums2.cend(), isPositive);
	bool isVNums3AllPositive = std::all_of(vNums3.cbegin(), vNums3.cend(), isPositive);
	std::cout << "isVNumsAllPositive = " << isVNumsAllPositive << ", isVNums2AllPositive = " << isVNums2AllPositive 
		<< ", isVNums3AllPositive = " << isVNums3AllPositive << std::endl;
	
	// any_of()
	bool isVNumsAnyPositive = std::any_of(vNums.cbegin(), vNums.cend(), isPositive);
	bool isVNums2AnyPositive = std::any_of(vNums2.cbegin(), vNums2.cend(), isPositive);
	bool isVNums3AnyPositive = std::any_of(vNums3.cbegin(), vNums3.cend(), isPositive);
	std::cout << "isVNumsAnyPositive = " << isVNumsAnyPositive << ", isVNums2AnyPositive = " << isVNums2AnyPositive
		<< ", isVNums3AnyPositive = " << isVNums3AnyPositive << std::endl;

	//none_of()
	bool isvNumsNonePositive = std::none_of(vNums.cbegin(), vNums.cend(), isPositive);
	bool isVNums2NonePositive = std::none_of(vNums2.cbegin(), vNums2.cend(), isPositive);
	bool isVNums3NonePositive = std::none_of(vNums3.cbegin(), vNums3.cend(), isPositive);
	std::cout << "isvNumsNonePositive = " << isvNumsNonePositive << ", isVNums2NonePositive = " << isVNums2NonePositive
		<< ", isVNums3NonePositive = " << isVNums3NonePositive << std::endl;

	
	//copy_n()
	int arrSource[8] = {10, 20, 30, 40, 50, 60, 70, 80};
	int arrTarget[7];
	std::copy_n(arrSource, 7, arrTarget);
	for (const auto& n : arrTarget)
	{
		std::cout << "n(of arrTarget after copy_n) = " << n << std::endl;
	}
	
	//iota()
	int arrInts[5] = {0};
	std::iota(arrInts, arrInts+5, 11);
	for (const auto& n : arrInts)
	{
		std::cout << "n(of arrInts after iota) = " << n << std::endl;
	}

	char arrChars[10] = { 0 };
	std::iota(arrChars, arrChars + 10, 'x');
	for (const auto& ch : arrChars)
	{
		std::cout << "ch(of arrChars after iota) = " << ch << std::endl;
	}

	std::cout << std::endl;
}

void Cpp11Features::RunUsingTuples() const
{
	std::cout << "RunUsingTuples()..." << std::endl;
	std::tuple<long, double, std::string> aTuple = std::make_tuple(240L, 4.6, "ahoy there");
	std::cout << "aTuple: " << std::get<0>(aTuple) << "," << std::get<1>(aTuple) << "," << std::get<2>(aTuple) << std::endl;

	// better still
	auto anotherTuple = std::make_tuple(3.6, 'x', 'c', 100'000'000);
	std::cout << "anotherTuple: " << std::get<0>(anotherTuple) << "," << std::get<1>(anotherTuple) << "," << std::get<2>(anotherTuple)
		<< std::get<3>(anotherTuple) << std::endl;

	// unlike in e.g. Python - can mod
	std::get<2>(aTuple) = "over here";
	std::cout << "aTuple (after change): " << std::get<0>(aTuple) << "," << std::get<1>(aTuple) << "," << std::get<2>(aTuple) << std::endl;

	std::cout << "size of aTuple:" << std::tuple_size<decltype(aTuple)>::value << std::endl;

	//unpack
	long l;
	double dbl;
	std::string aString;
	std::tie(l,dbl,aString) = aTuple;
	std::cout << "Unpacked l:" << l << ", dbl:" << dbl << ", aString:" << aString << std::endl;

	// concat
	auto tupConcat = std::tuple_cat(aTuple, anotherTuple);
	std::cout << "tupConcat: " << std::get<0>(tupConcat) << "," << std::get<1>(tupConcat) << "," << std::get<2>(tupConcat)
		<< "," << std::get<3>(tupConcat) << "," << std::get<4>(tupConcat) << "," << std::get<5>(tupConcat) << std::endl;

	std::cout << std::endl;
}

void Cpp11Features::RunScopedEnumsDemo() const
{
	std::cout << "RunScopedEnumsDemo()..." << std::endl;
	enum class Position {
	Goalkeeper,
	Defender,
	Midfielder,
	Striker };

	Position thisPlayerPosition = Position::Defender;
	if (thisPlayerPosition == Position::Midfielder)
		std::cout << "They're a midfielder" << std::endl;
	else if (thisPlayerPosition == Position::Defender)
		std::cout << "They're a defender" << std::endl;
	else
		std::cout << "Don't know" << std::endl;
	std::cout << "thisPlayerPosition = " << static_cast<int>(thisPlayerPosition) << std::endl;
	std::cout << std::endl;
}


// no params function to break the recursion chain
void logOut()
{
}
// now variadic definition for "general" case
template <typename T, typename...Args>
void logOut(T first, Args...args) 
{
	std::cout << "\tLogged:" << first << std::endl;;
	logOut(args...);
}
void Cpp11Features::RunVariadicTemplatesDemo() const
{
	std::cout << "RunVariadicTemplatesDemo()..." << std::endl;
	logOut(4, 3.56, "kelp forest", 'h');
	std::cout << std::endl;
}

/////////////////////////////////////////////

void Cpp11Features::SimpleSMethod()
{
	thread_local std::string strThreadUnique = "unique is this";	// this will be unique to this thread, a diff thread running the same could change without any effect here...
	std::cout << "Cpp11Features::SimpleSMethod being called on threadid:[" << std::this_thread::get_id() << "]" << std::endl;
}

void Cpp11Features::SomeCalculation(int n, std::promise<int> * pPromise) 
{
	std::cout << "Cpp11Features::SomeCalculation being called on threadid:[" << std::this_thread::get_id() << "]" << std::endl;
	int nResult = 1;
	for (int i = n; i > 0; i--) {
		nResult *= i;
	}

	pPromise->set_value(nResult);
}

int Cpp11Features::CalculationForAsync(int n) {

	std::cout << "Cpp11Features::CalculationForAsync being called on threadid:[" << std::this_thread::get_id() << "]" << std::endl;
	int nResult = 0;
	for (int i = 1; i <= n; ++i) {
		nResult += i;
	}
	return nResult;
}

std::map<std::string, long> Cpp11Features::MockCreateSomeData(std::string strIn) 
{
	std::cout << "Cpp11Features::MockCreateSomeData being called on threadid:[" << std::this_thread::get_id() << "]" << std::endl;
	std::map<std::string, long> mapRet = {
		{"This", 5},
		{"That", 10},
		{"TheOther", 15}
	};

	mapRet.insert(std::pair<std::string, long>(strIn, 100));
	return mapRet;
}

