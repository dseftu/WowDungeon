#include "pch.h"
#include "Condition.h"
#include "EqualityCondition.h"
#include "StringEqualityCondition.h"
#include <string>

using namespace std;
using namespace WowDungeon;

int main()
{
	
	cout << "Whats your name? >";
	shared_ptr<string> command = make_unique<string>();
	
	shared_ptr<Condition> ConditionGoNorth = make_shared<StringEqualityCondition>(make_shared<string>("north"), command);
	shared_ptr<Condition> ConditionGoSouth = make_shared<StringEqualityCondition>(make_shared<string>("south"), command);
	shared_ptr<Condition> ConditionGoEast = make_shared<StringEqualityCondition>(make_shared<string>("east"), command);
	shared_ptr<Condition> ConditionGoWest = make_shared<StringEqualityCondition>(make_shared<string>("west"), command);

	while (true)
	{
		cin >> *command;


		cout << "Heard: " << *command << endl;
		cout << "Went north: " << ConditionGoNorth->Evaluate() << endl;
		cout << "Went south: " << ConditionGoSouth->Evaluate() << endl;
		cout << "Went east: " << ConditionGoEast->Evaluate() << endl;
		cout << "Went west: " << ConditionGoWest->Evaluate() << endl;
		//game.Update();
	}
	return 0;
}