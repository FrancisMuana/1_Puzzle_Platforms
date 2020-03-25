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
