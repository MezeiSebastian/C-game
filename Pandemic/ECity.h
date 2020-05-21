#pragma once
#include<string>

enum class ECity
{
	SanFrancisco,
	Chicago,
	Atlanta,
	Montreal,
	NewYork,
	London,
	Paris,
	StPetersburg,
	Milan,
	Essen,
	Madrid,
	Washington,

	LosAngeles,
	MexicoCity,
	Miami,
	Bogota,
	Lima,
	SaoPaulo,
	BuenosAries,
	Santiago,
	Lagos,
	Khartoum,
	Kinshasa,
	Johannesburg,

	Algiers,
	Istanbul,
	Moscow,
	Cairo,
	Tehran,
	Karachi,
	Kolkata,
	Delhi,
	Mumbai,
	Riyadh,
	Chennai,
	Baghdad,


	Bangkok,
	Beijing,
	HoChiMinhCity,
	HongKong,
	Jakarta,
	Manila,
	Osaka,
	Seoul,
	Shanghai,
	Sydney,
	Taipei,
	Tokyo,

	None
};

const char* ProvideStringFromECity(const ECity& city);
const ECity& ProvideECityFromString(const std::string& city);
