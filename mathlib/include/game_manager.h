#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

class GameManager{
    public:
    ~GameManager();

    /**
     * \brief get the unique instance of the game manager
     * 
     * \return GameManager& instance of the game manager
     */
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