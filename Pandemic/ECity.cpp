#include "ECity.h"
#include<string>


const char* ProvideStringFromECity(const ECity& city)
{
	if (city == ECity::Algiers)
		return "Algiers";
	else if (city == ECity::Atlanta)
		return "Atlanta";
	else if (city == ECity::Baghdad)
		return "Baghdad";
	else if (city == ECity::Bangkok)
		return "Bangkok";
	else if (city == ECity::Beijing)
		return "Beijing";
	else if (city == ECity::Bogota)
		return "Bogota";
	else if (city == ECity::BuenosAries)
		return "BuenosAries";
	else if (city == ECity::Cairo)
		return "Cairo";
	else if (city == ECity::Chennai)
		return "Chennai";
	else if (city == ECity::Chicago)
		return  "Chicago";
	else if (city == ECity::Delhi)
		return  "Delhi";
	else if (city == ECity::Essen)
		return "Essen";
	else if (city == ECity::HoChiMinhCity)
		return "HoChiMinhCity";
	else if (city == ECity::HongKong)
		return ("HongKong");
	else if (city == ECity::Istanbul)
		return "Instanbul";
	else if (city == ECity::Jakarta)
		return "Jakarta";
	else if (city == ECity::Johannesburg)
		return "Johannesburg";
	else if (city == ECity::Karachi)
		return "Karachi";
	else if (city == ECity::Khartoum)
		return "Khartoum";
	else if (city == ECity::Kinshasa)
		return "Kinshasa";
	else if (city == ECity::Kolkata)
		return "Kolkata";
	else if (city == ECity::Lagos)
		return "Lagos";
	else if (city == ECity::Lima)
		return "Lima";
	else if (city == ECity::London)
		return "London";
	else if (city == ECity::LosAngeles)
		return "LosAngeles";
	else if (city == ECity::Madrid)
		return "Madrid";
	else if (city == ECity::Manila)
		return "Manila";
	else if (city == ECity::MexicoCity)
		return "MexicoCity";
	else if (city == ECity::Miami)
		return "Miami";
	else if (city == ECity::Milan)
		return "Milan";
	else if (city == ECity::Montreal)
		return "Montreal";
	else if (city == ECity::Moscow)
		return "Moscow";
	else if (city == ECity::Mumbai)
		return "Mumbai";
	else if (city == ECity::NewYork)
		return "NewYork";
	else if (city == ECity::Osaka)
		return "Osaka";
	else if (city == ECity::Paris)
		return "Paris";
	else if (city == ECity::Riyadh)
		return "Riyadh";
	else if (city == ECity::SanFrancisco)
		return "SanFrancisco";
	else if (city == ECity::Santiago)
		return "Santiago";
	else if (city == ECity::SaoPaulo)
		return "SaoPaulo";
	else if (city == ECity::Seoul)
		return "Seoul";
	else if (city == ECity::Shanghai)
		return "Shanghai";
	else if (city == ECity::StPetersburg)
		return "StPetesburg";
	else if (city == ECity::Sydney)
		return "Sidney";
	else if (city == ECity::Taipei)
		return "Taipei";
	else if (city == ECity::Tehran)
		return "Tehran";
	else if (city == ECity::Tokyo)
		return "Tokyo";
	else if (city == ECity::Washington)
		return "Washington";
	else if (city == ECity::None)
		return "";
}

const ECity& ProvideECityFromString(const std::string& city_name)
{
	if (city_name == "Algiers")
		return ECity::Algiers;
	else if (city_name == "Atlanta")
		return ECity::Atlanta;
	else if (city_name == "Baghdad")
		return ECity::Baghdad;
	else if (city_name == "Bangkok")
		return ECity::Bangkok;
	else if (city_name == "Beijing")
		return ECity::Beijing;
	else if (city_name == "Bogota")
		return ECity::Bogota;
	else if (city_name == "BuenosAries")
		return ECity::BuenosAries;
	else if (city_name == "Cairo")
		return ECity::Cairo;
	else if (city_name == "Chennai")
		return ECity::Chennai;
	else if (city_name == "Chicago")
		return ECity::Chicago;
	else if (city_name == "Delhi")
		return ECity::Delhi;
	else if (city_name == "Essen")
		return ECity::Essen;
	else if (city_name == "HoChiMinhCity")
		return ECity::HoChiMinhCity;
	else if (city_name == "HongKong")
		return ECity::HongKong;
	else if (city_name == "Istanbul")
		return ECity::Istanbul;
	else if (city_name == "Jakarta")
		return ECity::Jakarta;
	else if (city_name == "Johannesburg")
		return ECity::Johannesburg;
	else if (city_name == "Karachi")
		return ECity::Karachi;
	else if (city_name == "Khartoum")
		return ECity::Khartoum;
	else if (city_name == "Kinshasa")
		return ECity::Kinshasa;
	else if (city_name == "Kolkata")
		return ECity::Kolkata;
	else if (city_name == "Lagos")
		return ECity::Lagos;
	else if (city_name == "Lima")
		return ECity::Lima;
	else if (city_name == "London")
		return ECity::London;
	else if (city_name == "LosAngeles")
		return ECity::LosAngeles;
	else if (city_name == "Madrid")
		return ECity::Madrid;
	else if (city_name == "Manila")
		return ECity::Manila;
	else if (city_name == "MexicoCity")
		return ECity::MexicoCity;
	else if (city_name == "Miami")
		return ECity::Miami;
	else if (city_name == "Milan")
		return ECity::Milan;
	else if (city_name == "Montreal")
		return ECity::Montreal;
	else if (city_name == "Moscow")
		return ECity::Moscow;
	else if (city_name == "Mumbai")
		return ECity::Mumbai;
	else if (city_name == "New York")
		return ECity::NewYork;
	else if (city_name == "Osaka")
		return ECity::Osaka;
	else if (city_name == "Paris")
		return ECity::Paris;
	else if (city_name == "Riyadh")
		return ECity::Riyadh;
	else if (city_name == "SanFrancisco")
		return ECity::SanFrancisco;
	else if (city_name == "Santiago")
		return ECity::Santiago;
	else if (city_name == "SaoPaulo")
		return ECity::SaoPaulo;
	else if (city_name == "Seoul")
		return ECity::Seoul;
	else if (city_name == "Shanghai")
		return ECity::Shanghai;
	else if (city_name == "StPetersburg")
		return ECity::StPetersburg;
	else if (city_name == "Sydney")
		return ECity::Sydney;
	else if (city_name == "Taipei")
		return ECity::Taipei;
	else if (city_name == "Tehran")
		return ECity::Tehran;
	else if (city_name == "Tokyo")
		return ECity::Tokyo;
	else if (city_name == "Washington")
		return ECity::Washington;

	else return ECity::None;
}
