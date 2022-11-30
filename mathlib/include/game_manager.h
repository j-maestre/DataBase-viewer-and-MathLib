#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

class GameManager{
    public:
    ~GameManager();

    static GameManager& Instance(){
      if(GameManager::instance_ == nullptr){
        GameManager::instance_ = new GameManager();
      }

      return *GameManager::instance_;
    }

    //TODO Declare some variables...
    int score_;

  private:
    GameManager();
    GameManager(const GameManager& ) {};

    static GameManager* instance_;
};

#endif