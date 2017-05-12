#include "Salateria.h"
#include <gtest\gtest.h>

TEST(decorator, test1)
{
	GreenSalad* salad = new GreenSalad;
	ASSERT_EQ(salad->getPrice(), 13.00);
}

TEST(decorator, test2)
{
	Salad* salad = new Garlic(new PotatoSalad);
	ASSERT_EQ("potato salad, garlic", salad->getDescription());
}

TEST(decorator, test3)
{
	Salad* salad = new CherryTomatoes(new CherryTomatoes(new GreenSalad));
	ASSERT_EQ("green salad, cherry tomatoes, cherry tomatoes", salad->getDescription());
}

TEST(decorator, test4)
{
	Salad* salad = new CherryTomatoes(new CherryTomatoes(new GreenSalad));
	ASSERT_EQ(19, salad->getPrice());
}

TEST(decorator, test5)
{
	Salad* salad = new CherryTomatoes(new Garlic(new GreenSalad));
	ASSERT_EQ(18, salad->getPrice());
}
