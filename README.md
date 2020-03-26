# Puzzle Platforms

Under the Hood:
* Unreal loads the map
* The map specifies a GameMode
* The PlayerController joins the map
* It ask the GameMode to spawn a Pawn
* The Pawn is linked to the PlayerController

Types of Multiplayer Game:
  * Turn-based
    ->  Not Synchronous
    ->  Session Length(Variable)
    ->  Indie Suitability(Excellent)
    ->  Unreal Support(Minimal)

  * Real-time session-based
    ->  Synchronous
    ->  Session Length(< 1 hour)
    ->  Indie Suitability(Good)
    ->  Unreal Support(Excellent)

  * MMO and Persistent World
    ->  Synchronous
    ->  Session Length(Potentially infinite)
    ->  Indie Suitability(Poor)
    ->  Unreal Support(Minimal)

Session-Based Stages:
  * Discovery
    ->  Finding who else is online
    ->  Finding a session that we can play with

  * Connection
    ->  Joining the session from a client to a server

  * Synchronization
    ->  We need to make sure that what player1 sees is the same as what player2 sees.

# Input and State:
  * State -> is everything in your world and its positions, its velocities, anything that can basically affect what you see.
  * State -> is what rendered by the engine
  * Input/Action -> We add to the state
  * During the Tick -> we combine the current state with the current input and the result will be the next State

To have a good multiplayer game, you've got to have the different players agree what the "State" of the game is.

# Peer-to-Peer:
  * When I make a change to my input, I'm gonna broadcast it to everybody.

  * All the players are gonna update their State based on the input they have received.

  * One crucial thing to note about Peer-to-Peer, in order to correctly update my State, I need to wait and listen to everybody else's input before I update my State. Before we can move on to the next frame(tick).

  * It means we have to wait for the slowest person:
    * in terms of their network Connection
    * the time it takes for their message to reach my computer
    * This can lead to an incredibly slow game.

  * Another big problem for this architecture is the security.
    * You could easily have one of these players just cheating. Sending out inputs that are false.

  * One of the easiest ways of solving this problem is to use a Client-Server architecture.

# Client-Server
  * Instead of connecting them to each other, you connect them to a central server.
  * If we have an Input, we tell the server. Then that server updates its notion of the State.
  * Its notion of the State is authoritative.
  * The server will send its State to the Clients(Players)

  Steps to Load The Game from the Command Prompt:
  * Copy/Paste path of UE4Editor.exe
  * Copy/Paste path of .uproject
  * To load a specific map -> /Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap
  * You also has the option of putting an IP address to connect instead of a map. (192.168.0.106:7777)
  * -game in the end to launch the Game
  * -log to show verbose log of the Game
  * This doesn't work for 4.24: swap -game to -server to launch a server
  * for UE4 4.24 this is how you launch a server:
    * Copy/Paste path of UE4Editor.exe
    * Copy/Paste path of .uproject
    * Copy/Paste /Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen -game -log

# Detecting Where Code is Running

  * In this commit, See MovingPlatform.cpp and .h codes to detect if it is the Client or the Server

# Authority and Replication
  * In AMovingPlatform::Tick
    * if has authority update property(ies)
  * In AMovingPlatform::BeginPlay
    * if has authority replicates property(ies) to the Clients
  * In APuzzlePlatformsGameMode::BeginPlay
    * if playercontroller index 0:
      * remove PlayerController
      * and its linked pawn
