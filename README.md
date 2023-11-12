# Snake Game Using OOP in C++
                             
# Introduction:
OOP is a programming paradigm that allows developers to create modular and reusable code by organizing data and functions into objects. The C++ Snake project is a classic game that has been implemented using object-oriented programming (OOP) principles. It shows how the player can control the snake tthat eat food and avoid obstacles. The purpose of this report is to provide an overview of the C++ Snake project, its OOP design, and its features.

# Project Overview:
The C++ Snake project is a console-based game that is designed using OOP principles. The project is implemented by using main concepts of OOP polymorphism, Inheritance and encapsulation. The code of project has following four classes: 
Game class - this class is responsible for managing the game state, updating the score, and handling user input.
Level class - this class is responsible for managing different levels of game. It shows next level while first complete.
Snake class - this class is responsible for handling the movement of the snake, growing the snake when it eats food, and detecting collisions between the snake and obstacles.
Fruit class - this class is responsible for creating food items on the game board and ensuring that they do not overlap with obstacles or the snake.

# Project Description:
The C++ Snake project is a console-based game that challenges players to control a snake to eat fruit for growth while avoiding obstacles and its own tail. The game is implemented using object-oriented programming (OOP) principles, with each class representing a specific aspect of the game.

The game starts with a snake positioned in the center of the game board, with food randomly placed on the board. The player must control the snake using A, S, D, and W keys to move it around the board, with the snake not automatically moving forward unless the player changes its direction. The snake grows in size as it eats food, and the game ends if the snake collides with an obstacle or its own tail.

The game includes 10 levels, with each level increasing in difficulty. As the player progresses through the levels, the snake moves faster, and Board Size Variation.

The project is organized into several classes, each representing a specific aspect of the game. The Game class manages the game state and flow, show board, updating the score as the game progresses, and handling user input. The level class which increment in level. The Snake class handles the movement of the snake in different direction. The Fruit class creates fruit items on the game board and ensures that they do not overlap with obstacles or the snake.
The project demonstrates several features of OOP. Overall, the C++ Snake project is a classic game that demonstrates the power of OOP principles. Its multiple levels, high score tracking and random appearance of fruit make it a fun and engaging game to play, while its OOP design makes it a great example of how OOP can be used to create modular and reusable code.

# Design and Implementation:
The C++ Snake project is designed using object-oriented programming (OOP) principles. The project is organized into several classes, each representing a specific aspect of the game. The main classes include the Game, level, Snake, and Fruit classes. Each class has its own member functions to implement the concept of polymorphism for different functionalities. 

# Functionality and Features:
The C++ Snake project has several features that demonstrate its OOP design and make it a fun and engaging game to play. Some of these features include encapsulation its data and functions, allowing for better modularity and code reuse. Operator overloading is used in a class for copying values. And different functions for movement of snake and random appearance of fruit.
Game Class:
The Game class is responsible for managing the game state, updating the score, and handling user input. The Game class has several public member functions include show board(), game flow(), which updates the game state on each frame, game_over(), which ends the game when the snake collides with an obstacle or its own tail, and flow_after_gameover(), which ask user either to play again or to exit when snake strike an obstacle.

# Level Class:
The Level class is responsible for creating the incrementing level, initializing the game. It contains private member variables such as lev and max_level. The level class has a public member functions incr_level(), which display next level when one completed.

# Snake Class:
Snake class is mainly responsible for movement of snake in different direction. It contains private variables including headX, headY, size, *tailX, *tailY, direction. And public member functions get_move(), which inputs the specified movement of snake, move_snake(), which move the snake in its respective entered direction such as ‘ w’ for upward movement, ‘s’ for downward, ‘a’ for left and ‘d’ for right movement.

# Fruit Class:
The fruit class is responsible for handling the movement of the fruit an growing the snake when it eats fruit.It contains private member variables such as fruitX, fruitY, score, max_score. The Snake class has several public member functions, including fruit_random_pos(), which is responsible for random positioning of fruit, fruit_eat(), which increases the length of the snake when it eats food.


# Documentation and Comments:
The code for the Snake game is thoroughly documented with comments which explains the functionality of certain features. These functions enhance code readability, clarify the structure and algorithm applied for code implementation.  

# Testing and Validation:
Testing and validation are crucial steps in any software project, as they help to ensure that the code is working correctly and meets the specified requirements. In the C++ Snake project, testing and validation were done at various stages of development.
Unit testing was performed to ensure that each function and class in the project worked as intended. This involved writing test cases for each function and verifying that the output matched the expected output. Integration testing was done to ensure that the different components of the project worked correctly together.
User acceptance testing (UAT) was also performed to ensure that the project met the needs of the end-users. This involved selecting a group of users and having them test the software to ensure that it met their needs and was easy to use. The feedback from UAT was used to make improvements to the project.
Furthermore, the project was validated against coding standards and best practices to ensure that it was of high quality. Code reviews were performed to catch errors early on and provide feedback for code improvements. 
Overall, testing and validation played an important role in the C++ Snake project by ensuring that the project met the specified requirements, was of high quality, and was usable for its intended purpose.

# Conclusion:
In conclusion, the C++ Snake project is a classic game that is designed using OOP principles. The project is well-organized, with each class representing a specific aspect of the game. The project demonstrates several features of OOP. The game has several features that make it a fun and engaging game to play, and its OOP design makes it a great example of how OOP can be used to create modular and reusable code.