# Ping-Pong-game
The provided code is a simple console-based game written in C++ that simulates a classic paddle-ball game.

Here’s a breakdown of its functionality and features:

- **Game Setup**: The game initializes the console window size and displays instructions for the player, including how to move the paddle and how to exit the game. The play area is bordered by walls, and the game uses ASCII characters to represent the paddle, ball, and walls.

- **Gameplay Mechanics**: Players control a horizontal paddle at the bottom of the screen, moving it left or right to bounce a ball back toward the top of the screen. The objective is to keep the ball from passing the paddle, as this results in losing a life. The ball bounces off the walls and the paddle, with the direction of the bounce depending on the angle of impact.

- **Scoring and Lives**: Each successful bounce off the paddle increases the player's score by one point. The player starts with three lives, and a life is lost each time the ball passes the paddle and hits the bottom wall. The game keeps track of and displays the player's score and remaining lives.

- **Controls**: The game uses keyboard input for controls. The left and right arrow keys move the paddle left and right, respectively, while the Esc key allows the player to exit the game at any time.

- **Optimization for Reduced Flickering**: The code includes optimizations to minimize screen flickering, a common issue in console-based animation. Instead of clearing and redrawing the entire screen each frame, it selectively updates only the parts of the screen that change (such as the paddle and ball positions, score, and lives), thereby reducing flickering and providing a smoother gameplay experience.

- **End Game**: The game concludes when the player loses all lives. It then clears the screen, displays a "Game Over" message along with the final score, and prompts the player to press any key to exit.

The code uses several Windows-specific functions (`_kbhit()`, `_getch()`, `system("cls")`, `Sleep()`) for input detection, screen clearing, and timing, making it tailored for execution in a Windows command prompt environment. It showcases basic game development concepts such as game loops, input handling, collision detection, and screen drawing in a low-level programming context.

 Enjoy your game !!!
**OUTPUT CONSOLE **
![image](https://github.com/angelvino/Ping-Pong-game/assets/109471128/897f3bf8-2f03-498e-91aa-8a4408966f3b)

![image](https://github.com/angelvino/Ping-Pong-game/assets/109471128/9696e512-d709-485f-ba69-fce1056d5b4c)

![image](https://github.com/angelvino/Ping-Pong-game/assets/109471128/1a9cd358-c713-4787-ae29-b8245cf2e759)


