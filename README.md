Tech stack:
- C++17
- SFML
- Object-oriented design
- Real-time update loop
- Manual memory/resource handling

Wow You're looking at my Github! 
Anyways here is the main crux of the program: The game is built with sfml-library providing an easy access API to the graphics card by being an OpenGL wrapper.
The games main components are enemies which run into the player, and a player character which is controlled by the WASD buttons. 
In this version the enemies are just circles, encapsulated in the class EvilCircle, which inherits from the base class Enemy. In further development of the game more Enemy
subclasses will be implemented that can easily be switched during levels by integrating a strategy pattern.
