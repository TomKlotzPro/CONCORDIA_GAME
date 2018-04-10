/* File: clockhandler.cpp
 * Author: Klotz Tom
 */

#include "Concordia_Game/concrete/clockhandler.hpp"

ClockHandler::ClockHandler() {}

void ClockHandler::restartClock() { this->elapsedTime = this->clock.restart(); }

void ClockHandler::restartTimeHandler(TimeHandler *genericTimeHandler) {
  genericTimeHandler->restart(this->elapsedTime);
}
