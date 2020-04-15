#include "../FiniteStateMachine.h"

#include <iostream>
#include <memory>

int main()
{
	gal::State chaseGhosts("CHASE_GHOSTS");
	gal::FiniteStateMachine fsm(3);
	fsm.AddState(std::move(chaseGhosts));

	std::cout << fsm["CHASE_GHOSTS"] << std::endl;
	std::cout << fsm["SEEK_PELLETS"] << std::endl;

	return 0;
}