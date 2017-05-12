#include <iostream>
#include <vector>
#include <string>

#define CATCH_CONFIG_MAIN
#include "catch.h"

#include "subtitles.h"
#include "audios.h"
#include "factories.h"
#include "language.h"
#include "movie.h"
#include "moviestore.h"

TEST_CASE("Subtitles") {
	Subtitle* en_sub = new EN_Sub;
	REQUIRE( en_sub->lang == "English" );
	delete en_sub;
	
	Subtitle* de_sub = new DE_Sub;
	REQUIRE( de_sub->lang == "Deutsch" );
	delete de_sub;
	
	Subtitle* ukr_sub = new UKR_Sub;
	REQUIRE( ukr_sub->lang == "Українська" );
	delete ukr_sub;
}

TEST_CASE("Audios") {
	Audio* en_aud = new EN_Aud;
	REQUIRE( en_aud->lang == "English" );
	delete en_aud;
	
	Audio* de_aud = new DE_Aud;
	REQUIRE( de_aud->lang == "Deutsch" );
	delete de_aud;
	
	Audio* ukr_aud = new UKR_Aud;
	REQUIRE( ukr_aud->lang == "Українська" );
	delete ukr_aud;
}

TEST_CASE("Factories") {
	AbstractFactory* en_factory = new EN_Factory;
	REQUIRE(en_factory->getAud()->lang == "English");
	REQUIRE(en_factory->getSub()->lang == "English");
	
	AbstractFactory* de_factory = new DE_Factory;
	REQUIRE(de_factory->getAud()->lang == "Deutsch");
	REQUIRE(de_factory->getSub()->lang == "Deutsch");
	
	AbstractFactory* ukr_factory = new UKR_Factory;
	REQUIRE(ukr_factory->getAud()->lang == "Українська");
	REQUIRE(ukr_factory->getSub()->lang == "Українська");
}

TEST_CASE( "Deutsch Cinderella") {
    MovieStore NYC;
    
    Movie* newOrder = NYC.order("Cinderella", "DE");
    
    REQUIRE( newOrder->title == "Cinderella" );
    REQUIRE( newOrder->sub->lang  == "Deutsch");
    REQUIRE( newOrder->aud->lang == "Deutsch" );
	delete newOrder;
}

TEST_CASE( "Ukrainian Cinderella") {
	MovieStore NYC;
	
	Movie* newOrder = NYC.order("Cinderella", "UKR");
	
	REQUIRE( newOrder->title == "Cinderella" );
	REQUIRE( newOrder->sub->lang  == "Українська");
	REQUIRE( newOrder->aud->lang == "Українська" );
	delete newOrder;
}


