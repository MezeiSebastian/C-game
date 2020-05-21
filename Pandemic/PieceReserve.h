#pragma once
#include<stdint.h>

class PieceReserve
{
private:
	uint16_t numberOfYellowCubes;
	uint16_t numberOfRedCubes;
	uint16_t numberOfBlueCubes;
	uint16_t numberOfBlackCubes;
	uint16_t numberOfResearchStations;
public:
	PieceReserve();
	~PieceReserve();
	uint16_t getNumberOfYellowCubes();
	void setNumberOfYellowCubes(uint16_t numberOfYellowCubes);

	uint16_t getNumberOfRedCubes();
	void setNumberOfRedCubes(uint16_t numberOfRedCubes);

	uint16_t getNumberOfBlueCubes();
	void setNumberOfBlueCubes(uint16_t numberOfBlueCubes);

	uint16_t getNumberOfBlackCubes();
	void setNumberOfBlackCubes(uint16_t numberOfBlackCubes);

	uint16_t getNumberOfResearchStations();
	void setNumberOfResearchStations(uint16_t numberOfResearchStations);
};

