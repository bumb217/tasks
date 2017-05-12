#ifndef OBSERVER_H
#define OBSERVER_H
#include<gtest\gtest.h>
#include "Observer.h"

TEST(POST, adding)
{
	Post New_Orleans;
	Reader Kate("Kate", { "Cosmopolitan" });
	New_Orleans.addObserver(Kate);
	EXPECT_EQ(1, New_Orleans.getObservers().size());

	Reader Bob("Bob", { "Today" });
	New_Orleans.addObserver(Bob);
	EXPECT_EQ(2, New_Orleans.getObservers().size());
}

TEST(POST, adding_same)
{
	Post NYC;
	Reader Kate("Kate", { "Cosmopolitan" });
	NYC.addObserver(Kate);
	NYC.addObserver(Kate);
	EXPECT_EQ(1, NYC.getObservers().size());
}

TEST(POST, deleting)
{
	Post New_Orleans;
	Reader Kate("Kate", { "Cosmopolitan" });
	New_Orleans.addObserver(Kate);
	Reader Bob("Bob", { "Today" });
	New_Orleans.addObserver(Bob);
	New_Orleans.deleteObserver(Bob);

	EXPECT_EQ(1, New_Orleans.getObservers().size());
}

TEST(POST, deleting_from_empty)
{
	Post NYC;
	Reader Kate("Kate", { "Cosmopolitan" });
	NYC.deleteObserver(Kate);
	EXPECT_EQ(0, NYC.getObservers().size());
}

TEST(POST, receive_a_copy)
{
	Post NYC;
	Reader Kate("Kate", { "Cosmopolitan", "Today" });
	NYC.addObserver(Kate);
	vector<string> new_press = { "Today", "Cosmopolitan"};
	NYC.getNewPress(new_press);
	EXPECT_EQ("Kate: Got a new copy of: Today Cosmopolitan ", Kate.getTodaysResult());
}

TEST(POST, no_new_copy)
{
	Post NYC;
	Reader Kate("Kate", { "Cosmopolitan" });
	NYC.addObserver(Kate);
	vector<string> new_press = { "Today" };
	NYC.getNewPress(new_press);
	EXPECT_EQ("Kate: No new copies for me this time..", Kate.getTodaysResult());
}

#endif
