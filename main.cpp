//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
//          Rooms in the maze are described by separate functions.
//          The user finds gold/food as they travel, fights a
//          variety of creatures, and eventually finds the exit.
//
// Author1: John Gauch
// Author2: Andrew Murphy
//------------------------------------------------------------

#include <cstdlib>
#include <iostream>
using namespace std;

// Food constants
const int CANDY = 0;
const int STEAK = 1;
const int POTION = 2;
const int CANDY_RESTORE = 10;
const int STEAK_RESTORE = 20;
const int POTION_RESTORE = 40;

// Creature constants
const int BUNNY = 0;
const int DWARF = 1;
const int TROLL = 2;
const int BUNNY_DAMAGE = 5;
const int DWARF_DAMAGE = 10;
const int TROLL_DAMAGE = 20;

// Other constants
const int TUITION = 50;
const int BEER = 10;

// Function prototypes
void PrintStatus (int gold, int health);
int FindTreasure (const int max_gold);
void EatFood (const int food, int &health);
int FightBattle (const int creature);
char GetDirection ();
void Exit (int &gold, int &health);
void Room1 (int &gold, int &health);
void RoomSpecial (int &gold, int &health);
void RoomSpecial2 (int &gold, int &health);
void Room2 (int &gold, int &health);
void Room3 (int &gold, int &health);
void Room4 (int &gold, int &health);
void Room5 (int &gold, int &health);
void Room6 (int &gold, int &health);
void Room7 (int &gold, int &health);
void Room8 (int &gold, int &health);
// ADD FUNCTION PROTOTYPES HERE

//------------------------------------------------------------
// Purpose: To print the player's status
// Input:   Gold amount, health value
// Output:  None
//------------------------------------------------------------
void
PrintStatus (int gold, int health)
{
  if (gold > 2 * health)
    cout << endl << "You are rich with " << gold
      << " gold, but your health is only " << health << endl;
  else if (health > 2 * gold)
    cout << endl << "You are strong with " << health
      << " health, but you only have " << gold << " gold" << endl;
  else
    cout << endl << "Your health is " << health
      << " and you have " << gold << " gold" << endl;
}

//------------------------------------------------------------
// Purpose: To calculate how much treasure is found
// Input:   Maximum amount of gold possible
// Output:  Actual amount of gold found
//------------------------------------------------------------
int
FindTreasure (const int max_gold)
{
  int gold = 1 + random () % max_gold;
  if (gold < max_gold / 2)
    cout << "\nYou find " << gold << " gold pieces on the floor.\n";
  else
    cout << "\nYou find a huge mound of " << gold << " gold pieces!\n";
  return gold;
}

//------------------------------------------------------------
// Purpose: To eating food item to restore health.
// Input:   Food item number between [0..2]
// Output:  Health value after eating food.
//------------------------------------------------------------
void
EatFood (const int food, int &health)
{
  switch (food)
    {
    case CANDY:
      health = health + CANDY_RESTORE;
      cout << "\nYou find a half eaten energy bar on the floor "
	<< "which restores your health by " << CANDY_RESTORE << endl;
      break;
    case STEAK:
      health = health + STEAK_RESTORE;
      cout << "\nYou find a warm and jucy steak on the table "
	<< "which restores your health by " << STEAK_RESTORE << endl;
      break;
    case POTION:
      health = health + POTION_RESTORE;
      cout << "\nYou find a green glowing potion on a shelf "
	<< "which restores your health by " << POTION_RESTORE << endl;
      break;
    default:
      cout << "\nYour stomach is rumbling, but there is nothing to eat\n";
      break;
    }

  // Check maximum value for health
  if (health > 100)
    health = 100;
}

//------------------------------------------------------------
// Purpose: To simulate battle with a creature
// Input:   Creature number between [0..3]
// Output:  Amount of damage done to your health.
//------------------------------------------------------------
int
FightBattle (const int creature)
{
  int damage = 0;
  switch (creature)
    {
    case BUNNY:
      damage = 1 + random () % BUNNY_DAMAGE;
      cout << "\nYou trip over a cute bunny and do "
	<< damage << " damage to your health.\n";
      break;
    case DWARF:
      damage = 1 + random () % DWARF_DAMAGE;
      cout << "\nA drunken dwarf hits you with a beer mug and does "
	<< damage << " damage to your health.\n";
      break;
    case TROLL:
      damage = 1 + random () % TROLL_DAMAGE;
      cout << "\nAn angry troll kicks you in the rear and does "
	<< damage << " damage to your health.\n";
      break;
    default:
      cout << "\nIt is ghostly quiet here, you must be alone\n";
      break;
    }
  return damage;
}

//------------------------------------------------------------
// Purpose: To get direction from user
// Input:   None
// Output:  Character code for N,S,E,W direction
//------------------------------------------------------------
char
GetDirection ()
{
  cout << "\nWhat direction would you like to go (N,S,E,W): ";
  char direction;
  cin >> direction;
  direction = toupper (direction);
  while ((direction != 'N') && (direction != 'S') &&
	 (direction != 'E') && (direction != 'W'))
    {
      cout << "Sorry, You can not go that way...\n";
      cout << "What direction would you like to go (N,S,E,W): ";
      cin >> direction;
      direction = toupper (direction);
    }
  return direction;
}

//------------------------------------------------------------
// Purpose: To find the cave exit
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void
Exit (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout << "\nYou crawl out of the cave and blink your eyes to\n";
  cout << "adjust to the bright sunshine. Congratulations,\n";
  cout << "you made it out of the cave with " << health << " health!\n";

  if (gold >= TUITION)
    {
      cout << "\nYou empty your pockets and discover " << gold <<
	" gold coins.\n";
      cout << "This will pay for tuition next semester!!!\n";
    }
  else if (gold >= BEER)
    {
      cout << "\nYou notice that you have " << gold <<
	" gold coins in your pocket.\n";
      cout << "This will pay for beer and pizza next semester!!!\n";
    }
  else
    {
      cout << "\nYou check your pocket and find " << gold << " gold coins.\n";
      cout << "Exploring caves sure is a hard way to make money!!!\n";
    }

  // Leave program
  exit (0);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  Players gold and health
//------------------------------------------------------------
void
Room1 (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout << "\nYou just stumbled into a hole in the ground. When you\n";
  cout << "shake off the dirt and leaves you realize you are in\n";
  cout << "the entrance to a cave that looks man made. As you\n";
  cout << "take a look around, you decide it might be fun to explore.\n";

  // ADD CODE HERE
  int treasure = FindTreasure (15);
  gold = gold + treasure;
  int damage = FightBattle (BUNNY);
  health = health - damage;
  PrintStatus (gold, health);
  char direction = GetDirection ();
  while (direction == 'N')
    {
      cout << "Sorry, You can not go that way...\n";
      direction = GetDirection ();
    }
  if (direction == 'S')
    {
      Room2 (gold, health);
    }
  else if (direction == 'E')
    {
      Room3 (gold, health);
    }
  else if (direction == 'W')
    {
      RoomSpecial (gold, health);
    }

}

//------------------------------------------------------------
// Purpose: To visit a tunnel in the cave
// Input:   The gold and health variables
// Output:  Players health and gold
//------------------------------------------------------------

void
RoomSpecial (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout << "You have entered a secret tunnel. All along the walls\n";
  cout << "you see glistening gold. This room seems to have never\n";
  cout << "been found before.\n";

  int damage = FightBattle (4);
  int treasure = FindTreasure (20);
  gold = gold + treasure;
  PrintStatus (gold, health);
  char direction = GetDirection ();

  while ((direction == 'N') || (direction == 'S') || (direction == 'W'))
    {
      cout << "Sorry, You can not go that way...\n";
      direction = GetDirection ();
    }
  if (direction == 'E')
    {
      Room1 (gold, health);
    }
}

//------------------------------------------------------------
// Purpose: To visit a secret room in the cave
// Input:   The gold and health variables
// Output:  Players gold and health
//------------------------------------------------------------

void
RoomSpecial2 (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout <<
    "You have entered a secret room with a ladder. You start to climb\n";
  cout << "the ladder and see an opening at the top. You go through the\n";
  cout <<
    "opening and find a tiny room with a treasure chest in the back corner.\n";

  int damage = FightBattle (4);
  int treasure = FindTreasure (20);
  gold = gold + treasure;
  EatFood (STEAK, health);
  PrintStatus (gold, health);
  char direction = GetDirection ();

  while ((direction == 'N') || (direction == 'E') || (direction == 'W'))
    {
      cout << "Sorry, You can not go that way...\n";
      direction = GetDirection ();
    }
  if (direction == 'S')
    {
      Room6 (gold, health);
    }
}

//------------------------------------------------------------
// Purpose: To visit a throne room in the cave
// Input:   The gold and health variables
// Output:  Players gold and health
//------------------------------------------------------------
void
Room2 (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout << "\nYou have entered the throne room. In the middle\n";
  cout << "of the room there is a giant wooden throne with\n";
  cout << "intricate carvings. As you take a closer look at the\n";
  cout << "carvings, you see that they show trolls chasing humans.\n";
  cout << "Hmmm, maybe this is not a great place to stop for a rest.\n";

  int damage = FightBattle (TROLL);
  health = health - damage;
  int treasure = FindTreasure (15);
  gold = gold + treasure;
  PrintStatus (gold, health);
  char direction = GetDirection ();

  while (direction == 'W')
    {
      cout << "Sorry, You can not go that way...\n";
      direction = GetDirection ();
    }
  if (direction == 'E')
    {
      Room5 (gold, health);
    }
  else if (direction == 'S')
    {
      Room4 (gold, health);
    }
  else if (direction == 'N')
    {
      Room1 (gold, health);
    }

}

//------------------------------------------------------------
// Purpose: To visit a abandoned pub in the cave
// Input:   The gold and health variables
// Output:  Players health and gold
//------------------------------------------------------------
void
Room3 (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout << "\nYou have entered an abandoned pub. There are piles\n";
  cout << "of dirty dishes and empty beer mugs all over the place.\n";
  cout << "You hear someone coming and duck behind a table to hide.\n";

  int damage = FightBattle (DWARF);
  health = health - damage;
  int damage1 = FightBattle (DWARF);
  health = health - damage1;
  int treasure = FindTreasure (15);
  gold = gold + treasure;
  PrintStatus (gold, health);
  char direction = GetDirection ();

  while (direction == 'N')
    {
      cout << "Sorry, You can not go that way...\n";
      direction = GetDirection ();
    }
  if (direction == 'W')
    {
      Room1 (gold, health);
    }
  else if (direction == 'E')
    {
      Room6 (gold, health);
    }
  else if (direction == 'S')
    {
      Room5 (gold, health);
    }

}

//------------------------------------------------------------
// Purpose: To visit a storage room in the cave
// Input:   The gold and health variables
// Output:  Players health and gold
//------------------------------------------------------------
void
Room4 (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout << "\nYou have entered a huge storage room filled with empty boxes.\n";
  cout << "Looking at the side of one box, you see 'ACME troll food'.\n";
  cout << "You better get out of here before you end up on the menu.\n";

  int damage = FightBattle (TROLL);
  health = health - damage;
  int damage1 = FightBattle (TROLL);
  health = health - damage1;
  EatFood (STEAK, health);
  PrintStatus (gold, health);
  char direction = GetDirection ();

  while ((direction == 'W') || (direction == 'S'))
    {
      cout << "Sorry, You can not go that way...\n";
      direction = GetDirection ();
    }
  if (direction == 'N')
    {
      Room2 (gold, health);
    }
  else if (direction == 'E')
    {
      Room8 (gold, health);
    }
}

//------------------------------------------------------------
// Purpose: Visit a basketball court
// Input:   The gold and health variables
// Output:  Players gold and health
//------------------------------------------------------------
void
Room5 (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout << "\nYou have entered a strange basketball court with\n";
  cout << "one troll shooting hoops. You challenge him to a 1 on 1\n";
  cout << "game and you make a 3 pointer and he gets angry and starts\n";
  cout << "to attack you!\n";

  EatFood (CANDY, health);
  int damage = FightBattle (TROLL);
  health = health - damage;
  PrintStatus (gold, health);
  char direction = GetDirection ();

  while (direction == 'E')
    {
      cout << "Sorry, You can not go that way...\n";
      direction = GetDirection ();
    }
  if (direction == 'N')
    {
      Room3 (gold, health);
    }
  else if (direction == 'S')
    {
      Room8 (gold, health);
    }
  else if (direction == 'W')
    {
      Room2 (gold, health);
    }
}

//------------------------------------------------------------
// Purpose: Visit a convenience store 
// Input:   The gold and health variables
// Output:  Players health and gold
//------------------------------------------------------------
void
Room6 (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout << "You enter a vibrant convenience store with rainbow colors all\n";
  cout << "over the walls and ceiling. There are remainders of carrots\n";
  cout << "and candy bits scattered all over the floor. All of a sudden\n";
  cout << "a horde of bunnies attack!\n";


  int damage = FightBattle (BUNNY);
  health = health - damage;
  int damage1 = FightBattle (BUNNY);
  health = health - damage1;
  int damage2 = FightBattle (BUNNY);
  health = health - damage2;
  int treasure = FindTreasure (15);
  gold = gold + treasure;
  EatFood (CANDY, health);
  PrintStatus (gold, health);
  char direction = GetDirection ();

  while (direction == 'E')
    {
      cout << "Sorry, You can not go that way...\n";
      direction = GetDirection ();
    }
  if (direction == 'N')
    {
      RoomSpecial2 (gold, health);
    }
  else if (direction == 'S')
    {
      Room7 (gold, health);
    }
  else if (direction == 'W')
    {
      Room3 (gold, health);
    }

}

//------------------------------------------------------------
// Purpose: Visit a dark arena
// Input:   The gold and health variables
// Output:  Players gold and health
//------------------------------------------------------------
void
Room7 (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout << "You enter a dark arena with a huge crowd of bunnies cheering\n";
  cout << "you on. There are carrot and steak chunks all over the floor.\n";
  cout << "You see a light at the end of the arena. The exit must be near.\n";
  cout << "The only problem is there are two massive trolls and one dwarf\n";
  cout << "standing in your way. It is fight or flight.\n";
  int damage = FightBattle (TROLL);
  health = health - damage;
  int damage1 = FightBattle (TROLL);
  health = health - damage1;
  int damage2 = FightBattle (DWARF);
  health = health - damage2;
  int treasure = FindTreasure (5);
  gold = gold + treasure;
  EatFood (POTION, health);
  PrintStatus (gold, health);
  char direction = GetDirection ();

  while (direction == 'E')
    {
      cout << "Sorry, You can not go that way...\n";
      direction = GetDirection ();
    }
  if (direction == 'N')
    {
      Room6 (gold, health);
    }
  else if (direction == 'S')
    {
      Exit (gold, health);
    }
  else if (direction == 'W')
    {
      Room8 (gold, health);
    }
}

//------------------------------------------------------------
// Purpose: Visit a musty movie theater
// Input:   The gold and health variables
// Output:  Players gold and health
//------------------------------------------------------------
void
Room8 (int &gold, int &health)
{
  cout << "\n------------------------------------------------------------\n";
  cout << "You enter a musty movie theater but you do not have a ticket.\n";
  cout << "The dwarf acting as a ticket collector will not let you in, but\n";
  cout << "you persist and the dwarf starts to get angry and calls in his\n";
  cout << "manager and things are heating up. They gang up on you and the\n";
  cout << "fight is on!\n";

  int treasure = FindTreasure (5);
  gold = gold + treasure;
  int damage = FightBattle (DWARF);
  health = health - damage;
  int damage2 = FightBattle (DWARF);
  health = health - damage2;
  EatFood (CANDY, health);
  PrintStatus (gold, health);
  char direction = GetDirection ();

  while (direction == 'S')
    {
      cout << "Sorry, You can not go that way...\n";
      direction = GetDirection ();
    }
  if (direction == 'N')
    {
      Room5 (gold, health);
    }
  else if (direction == 'E')
    {
      Room7 (gold, health);
    }
  else if (direction == 'W')
    {
      Room4 (gold, health);
    }
}

//------------------------------------------------------------
// Purpose: The main program
// Input:   Room1
// Output:  None
//------------------------------------------------------------
int
main ()
{
  // Initialize game
  int gold = 0;
  int health = 100;
  srandom (time (NULL));
  Room1 (gold, health);

  // ADD CODE HERE

  return 0;
}

