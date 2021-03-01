#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <numeric>
#include <chrono>
#include <iomanip>
#include <time.h>
using namespace std;

class Hero
{
public:
	int Id, HP, Damage;
	string Name;
	Hero(int _Id = 0, string _Name = "", int _HP = 0, int _Damage = 0)
		: Id(_Id), Name(_Name), HP(_HP), Damage(_Damage)
	{
	}
};

class Player
{
public:
	int Id, Rank;
	string Name;
	Hero hero;
	Player(int _Id = 0, string _Name = "", int _Rank = 0)
		: Id(_Id), Name(_Name), Rank(_Rank)
	{
	}
};

class PlayerManager
{
public:
	vector<Player> players;
	void CreatePlayer(int pId, string pName, int pRank)
	{
		Player new_player(pId, pName, pRank);
		players.push_back(new_player);
	}
	void AssignHero(int Id, Hero hero)
	{
		this->players;
		for (auto& elem : players)
		{
			if (Id = elem.Id)
				elem.hero = hero;
		}
	}
	Player GetPlayerByName(string pName)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (pName == players[i].Name)
				return players[i];
		}
		Player empty_player(0, "This player does not exist", 0);
		return empty_player;
	}

	Player GetPlayerById(int pId)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (pId == players[i].Id)
				return players[i];
		}
		Player empty_player(0, "This player does not exist", 0);
		return empty_player;
	}
	void DeletePlayer(string pName = "", int pId = 0)
	{
		this->players;
		for (int i = 0; i < players.size(); i++)
		{
			if (pName == players[i].Name || pId == players[i].Id)
			{
				players.erase(players.begin() + i);
				break;
			}
		}
	}
	void ChangeRank(int pId, int rank_change = 0)
	{
		this->players;

		players[pId - 1].Rank += rank_change;
	}
	void AllPlayersInfo()
	{
		for (const auto& elem : players)
		{
			cout << "Name: " << elem.Name <<
				"\tId: " << elem.Id <<
				"\tRank: " << elem.Rank << endl;
		}
	}
	void ShowPlayerInfo(string pName, int pId = 0)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (pName == players[i].Name || pId == players[i].Id)
			{
				cout << "Name: " << players[i].Name <<
					"\tId: " << players[i].Id <<
					"\tRank: " << players[i].Rank << endl;
				break;
			}
		}
	}
};
class HeroManager
{
public:
	vector<Hero> heroes;
	void CreateHero(int Id, string Name, int HP, int Damage)
	{
		Hero new_hero(Id, Name, HP, Damage);
		heroes.push_back(new_hero);
	}

	Hero GetHeroByName(string Name)
	{
		for (int i = 0; i < heroes.size(); i++)
		{
			if (Name == heroes[i].Name)
				return heroes[i];
		}
		Hero empty_hero(0, "This player does not exist", 0, 0);
		return empty_hero;
	}

	Hero GetHeroById(int Id)
	{
		for (int i = 0; i < heroes.size(); i++)
		{
			if (Id == heroes[i].Id)
				return heroes[i];
		}
		Hero empty_hero(0, "This player does not exist", 0, 0);
		return empty_hero;
	}
	void DeleteHero(string Name = "", int Id = 0)
	{
		this->heroes;
		for (int i = 0; i < heroes.size(); i++)
		{
			if (Name == heroes[i].Name || Id == heroes[i].Id)
			{
				heroes.erase(heroes.begin() + i);
				break;
			}
		}
	}
	void AllHeroesInfo()
	{
		for (const auto& elem : heroes)
		{
			cout << "Name: " << elem.Name <<
				"\tId: " << elem.Id <<
				"\tHP: " << elem.HP <<
				"\tDamage: " << elem.Damage << endl;
		}
	}
	void ShowHeroInfo(string Name, int Id = 0)
	{
		for (int i = 0; i < heroes.size(); i++)
		{
			if (Name == heroes[i].Name || Id == heroes[i].Id)
			{
				cout << "Name: " << heroes[i].Name <<
					"\tId: " << heroes[i].Id <<
					"\tHP: " << heroes[i].HP <<
					"\tDamage: " << heroes[i].Damage << endl;
				break;
			}
		}

	}
};

class Team
{
public:
	string Name;

	struct PlayerHero
	{
		Player player;
		Hero hero;
		PlayerHero() : player(), hero()
		{
		}
	};

	vector<PlayerHero> players;
};

class TeamManager
{
public:

	vector<Team> teams;
	void GenerateNewTeams(PlayerManager players, HeroManager heroes)
	{
		this->teams;
		teams.clear();

		int p_iterator;
		int random_player;
		vector<int> random_players(players.players.size());
		iota(random_players.begin(), random_players.end(), 0);

		int h_iterator;
		int random_hero;
		vector<int> random_heroes(heroes.heroes.size());
		iota(random_heroes.begin(), random_heroes.end(), 0);

		for (int t = 0; t < 2; t++)
		{
			teams.resize(t + 1);
			for (int i = 0; i < 5; i++)
			{
				p_iterator = rand() % random_players.size();
				random_player = random_players[p_iterator];
				random_players.erase(random_players.begin() + p_iterator);

				h_iterator = rand() % random_heroes.size();
				random_hero = random_heroes[h_iterator];
				random_heroes.erase(random_heroes.begin() + h_iterator);

				teams[t].players.resize(i + 1);
				teams[t].players[i].player = players.players[random_player];
				teams[t].players[i].hero = heroes.heroes[random_hero];
			}
		}
	}
	void GetTeamInfo(PlayerManager players, HeroManager heroes)
	{
		for (const auto& elem : teams)
		{
			for (int i = 0; i < 5; i++)
			{
				cout << "Player " << i + 1 << ": ";
				players.ShowPlayerInfo(elem.players[i].player.Name);
				cout << "Hero: ";
				heroes.ShowHeroInfo(elem.players[i].hero.Name);
			}
			cout << "\n\n\n";
		}
	}
};

class Session
{
public:
	string start_time;
	Team team_one;
	Team team_two;
	Team winner;

	Session(Team _team_one, Team _team_two)
		: team_one(_team_one), team_two(_team_two)
	{
		auto start = chrono::system_clock::now();
		time_t time = chrono::system_clock::to_time_t(start);
		start_time = ctime(&time);
		winner = CalculateWinner(_team_one, _team_two);
	}

	Team CalculateWinner(Team _team_one, Team _team_two)
	{
		int team_one_damage = 0, team_two_damage = 0;
		int team_one_health = 0, team_two_health = 0;
		for (int i = 0; i < _team_one.players.size(); i++)
		{
			team_one_damage = _team_one.players[i].hero.Damage;
			team_one_health = _team_one.players[i].hero.HP;
		}
		for (int i = 0; i < _team_two.players.size(); i++)
		{
			team_two_damage = _team_two.players[i].hero.Damage;
			team_two_health = _team_two.players[i].hero.HP;
		}

		if (team_one_health - team_two_damage < team_two_health - team_one_damage)
			return _team_two;
		return _team_one;
	}
	void ShowSession()
	{
		cout << start_time << "Winner: " << endl;
		for (auto& elem : winner.players)
			cout << elem.player.Name << "  " << elem.player.Rank << endl;
	}
};

class GameManager
{
	vector<Session> GameSessions;
	PlayerManager players;
	HeroManager heroes;
	TeamManager teams;
public:

	GameManager(PlayerManager _players, HeroManager _heroes)
		: players(_players), heroes(_heroes)
	{
	}

	void PerformGameSession(PlayerManager& players)
	{
		teams.GenerateNewTeams(players, heroes);

		for (int i = 0; i < teams.teams.size() - 1; i++)
		{
			Session temp(teams.teams[i], teams.teams[i + 1]);

			for (int i = 0; i < temp.team_one.players.size(); i++)
			{
				players.ChangeRank(temp.team_one.players[i].player.Id, -25);
				players.ChangeRank(temp.team_two.players[i].player.Id, -25);
				players.ChangeRank(temp.winner.players[i].player.Id, 50);
				temp.winner.players[i].player.Rank += 25;
			}
			GameSessions.push_back(temp);
		}
		teams.GetTeamInfo(players, heroes);
	}
	void ShowSessions()
	{
		for (auto& elem : GameSessions)
		{
			elem.ShowSession();
			cout << endl;
		}
	}
};

void InitializeUnits(PlayerManager& players, HeroManager& heroes)
{
	vector<string> player_names = { "Christopher-Jay Garcia", "Cjay Jones", "Colby-Jay Johnson", "C-Jay Smith","Chasey Rodriguez", "Cary Miller","Coady Davis","Cally Jackson","Cassidy Thompson","Carter-Jay Anderson","Cortney Thomas","Cauley Moore","Chesley White","Charlie-Jay Martinez","Chaudry Martin", "Chankoowashtay Hall" };
	vector<string> hero_names = { "Terrifying-Man", "Professor Terri", "Howling-Man", "Captain How","Alarming","Struthio-Camelus-Man", "Alligator-Man", "Angora","Wonderful-Man","Agent Ant","The Lucky Sage","Glorious Daggers", "Remix", "Karma", "Starlight", "Electron Swan", "Dark Slayer", "Armed", "Phantom Archer", "Doctor Gentle Hawk", "Ace" };
	int random;
	string temp_name;
	for (int i = 0; i < 10; i++)
	{
		random = rand() % player_names.size();
		temp_name = player_names[random];
		player_names.erase(player_names.begin() + random);

		players.CreatePlayer(i + 1, temp_name, 0);
	}
	for (int i = 0; i < 15; i++)
	{
		random = rand() % hero_names.size();
		temp_name = hero_names[random];
		hero_names.erase(hero_names.begin() + random);

		heroes.CreateHero(i + 1, temp_name, rand() % 60 + 10, rand() % 60 + 10);
	}
}

int main()
{
	srand(time(NULL));

	PlayerManager players;
	HeroManager heroes;
	InitializeUnits(players, heroes);
	GameManager game_manager(players, heroes);
	for (int i = 0; i < 5; i++)
		game_manager.PerformGameSession(players);
	game_manager.ShowSessions();

	return 0;
}
