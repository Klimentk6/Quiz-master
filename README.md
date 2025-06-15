# QuizMaster

<img src="images/quiz.jpg" alt="" width="300"/>

**QuizMaster** is a console-based C++ application for creating and managing quizzes, inspired by platforms like **Kahoot**, **Quizizz**, and others.

## Technologies & Concepts

-  Written in **C++**
-  Custom implementations of `MyString` and `MyVector<T>`
-  Uses the **Command Pattern**
-  Specialized heterogeneous containers for managing quizzes and users
-  Persistent data storage in **binary files**

## Features

- Create quizzes with various question types:
  - `TrueOrFalseQuestion`
  - `SingleChoiceQuestion`
  - `MultipleChoiceQuestion`
  - `ShortAnswerQuestion`
  - `MatchingPairsQuestion`
- Two quiz modes:
  - `Test Mode`: shows correct answers, but does not assign points
  - `Normal Mode`: hides correct answers and calculates total score
- Optional shuffle of questions
- Users can:
  - Take quizzes and receive scores
  - Save favorite quizzes
  - Complete challenges
- All data is saved to binary files and automatically restored on next launch
