#include "AI.h"
#include "EVirus.h"

void AI::MakePrediction(BoardData& board,  Player& player,Deck& infectionDeck)
{
	FitnessFunction(board, player,infectionDeck);
	SmartSearch();


}

void AI::FitnessFunction(BoardData& board, Player& player,Deck& infectionDeck)
{
	if (board.GetOutbreaks() > 3) {
		predictions[0] = 1;
	}
	else if (board.GetOutbreaks() > 5) {
		predictions[0] = 2;
	}

	if (board.GetPiecies(EVirus::BlackVirus) < 9 || board.GetPiecies(EVirus::BlueVirus)<9 || board.GetPiecies(EVirus::RedVirus)<9 || board.GetPiecies(EVirus::YellowVirus)<9) {
		predictions[1] = 1;
	}
	else if (board.GetPiecies(EVirus::BlackVirus) < 4 || board.GetPiecies(EVirus::BlueVirus) < 4 || board.GetPiecies(EVirus::RedVirus) < 4 || board.GetPiecies(EVirus::YellowVirus) < 4) {
		predictions[1] = 1;
	}

	if (infectionDeck.GetNumberOfCards() < 16) {
		predictions[2] = 1;
	}
	else if (infectionDeck.GetNumberOfCards() < 10) {
		predictions[2] = 2;
	}

	

	if (board.GetNumOfResearchStations() < 4) {
		predictions[3] = 2;
	}
	else if (board.GetNumOfResearchStations() < 2) {
		predictions[3] = 1;
	}

	if (board.GetInfectionRate() > 3) {
		predictions[4] = 1;
	}
	else if (board.GetInfectionRate() > 5) {
		predictions[4] = 2;
	}

	if (board.GetOutbreaks() > 4) {
		predictions[5] = 1;
	}
	else if (board.GetOutbreaks() > 5) {
		predictions[5] = 2;
	}
	if (board.GetInfectionRate() < 2) {
		predictions[6] = 2;
	}
	else if (board.GetInfectionRate() < 4) {
		predictions[6] = 1;
	}

}

void AI::SmartSearch()
{
	auto repeatCheck = std::array<int, 7>{};
	auto maxFitness = 0;
	auto predictionNumber = 0;
	for (auto i = 0; i < predictions.size();++i) {
		if (predictions[i] > maxFitness&& repeatCheck[i] == 0) {
			maxFitness = predictions[i];
			predictionNumber = i;
		}
	}
	GenerateText(2-maxFitness,predictionNumber);
}

void AI::GenerateText(int level,int predictionNumber)
{
	auto dangerLevel = std::array<std::string, 3>{
	"There is a great chance",
	"There is a moderate chance",
	"There is a slight change"
	};

	auto actionRequested = std::array<std::string, 7>{
		"for a heavy outbreak to happen",
		"for you to run out of virus pieces",
		"for you to run out of cards",
		"to fall behind because you don't place reasearch stations",
		"for a masive infection to happen",
		"for you to lose because you have reached the maxim number of outbreaks",
		"for an infection to happen"
	};

	auto outbreakAdvice = std::array<std::string, 3>{
		"try to prevent that by clearing the cities that are heavily infected, we would suggest to make that you main priority for now!",
		"try to prevent that by clearing the cities that are heavily infected, we would suggest to take care of that but not to make it your full priority.",
		"because of that we suggest that you play agresive in this part of the game but you should always keep an eye out for heavy infected cities.",
	};

	auto virusAdvice = std::array<std::string, 3>{
		",you should see wich area is the most infected and spend most of your efforts trying to clear it!",
		",you should keep an eye out for that, we recommend that all the players should be well spreaded across the map to make sure that you have this under control.",
		",because of that we suggest that you try and move along the map to prevent viruses to get out of control."
	};

	auto cardsAdvice = std::array<std::string, 3>{
		",you should focus on finishing the game as soon as possible,look at what viruses need to be cured and use the share knowledge to pass cards around.",
		",because of that this is probably a good time to start tinking about how you wan't to close the game and win.",
		",you shoud alwayes be thinking about the next virus you wan't to cure, think about saving some cards instead of spending the early on."
	};

	auto stationsAdvice = std::array<std::string, 3>{
		", you should start placing them as soon as possible and try placing them as far from each other as possible",
		", you should try to place more research station to facilitate movement across the board.",
		", you have a decent amoung of research stations placed, remember that you can replace a station when you run out."
	};

	auto infectionsAdvice = std::array<std::string, 3>{
		", rush to end the game before things spiral out of control",
		", you should make a plan of how you should win the game, use the resources you have sparred throw the game the make a final push and win!",
		", which means you are still in an early stage of the game, try to spread all the players across the map because the is great chance for you to draw an infection card."
	};

	auto outbreaksAdvice = std::array<std::string, 3>{
		", you should try and prevent any further outbreaks as your main priority, if you have a doctor on your team make sure the make good use of his special ability.",
		", outbreaks are the shortest path to losing the game so you should always kepp an eye out for them",
		", outbreaks are the shortest path to losing the game so you should always kepp an eye out for them",

	};

	auto infectionsChanceAdvice = std::array<std::string, 3>{
		", there is a great chance that you will draw an infection card soon try to prevent any outbreaks that may occur.",
		", you should start thinking about how you should win the game at this stage, start using share knowledge to cure diseases.",
		", you should rush to end the game because you are in a late stage and infections are not that important at this point."
	};
	std::array<std::array<std::string, 3>, 7> allChances{
		outbreakAdvice,
		virusAdvice,
		cardsAdvice,
		stationsAdvice,
		infectionsAdvice,
		outbreaksAdvice,
		infectionsChanceAdvice,
	};

	std::string finalMessage = dangerLevel[level] + actionRequested[predictionNumber] + allChances[predictionNumber][level];
	PrintOutput(finalMessage);
}

void AI::PrintOutput(std::string& finalMessage)
{
	std::cout << finalMessage<<"\n";
}


