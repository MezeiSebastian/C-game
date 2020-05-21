#include "PieceReserve.h"

PieceReserve::PieceReserve()
{
}

PieceReserve::~PieceReserve()
{
}



uint16_t PieceReserve::getNumberOfYellowCubes()
{
	return numberOfYellowCubes;
}

void PieceReserve::setNumberOfYellowCubes(uint16_t numberOfYellowCubes)
{
	this->numberOfYellowCubes = numberOfYellowCubes;
}



uint16_t PieceReserve::getNumberOfRedCubes()
{
	return numberOfRedCubes;
}

void PieceReserve::setNumberOfRedCubes(uint16_t numberOfRedCubes)
{
	this->numberOfRedCubes = numberOfRedCubes;
}



uint16_t PieceReserve::getNumberOfBlueCubes()
{
	return numberOfBlueCubes;
}

void PieceReserve::setNumberOfBlueCubes(uint16_t numberOfBlueCubes)
{
	this->numberOfBlueCubes = numberOfBlueCubes;
}



uint16_t PieceReserve::getNumberOfBlackCubes()
{
	return numberOfBlackCubes;
}

void PieceReserve::setNumberOfBlackCubes(uint16_t numberOfBlackCubes)
{
	this->numberOfBlackCubes = numberOfBlackCubes;
}



uint16_t PieceReserve::getNumberOfResearchStations()
{
	return numberOfResearchStations;
}

void PieceReserve::setNumberOfResearchStations(uint16_t numberOfResearchStations)
{
	this->numberOfResearchStations = numberOfResearchStations;
}
