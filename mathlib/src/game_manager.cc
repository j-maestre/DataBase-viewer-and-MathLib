#include "game_manager.h"

GameManager* GameManager::instance_ = nullptr;

GameManager::GameManager(){
  score_ = 0;
}

GameManager::~GameManager(){
  
}