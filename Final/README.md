# Spotifyish Quiz
#### Video Demo:  <https://youtu.be/X8ky0Gnm05Y>
#### Description:



### 1   |   What is it?
![](/project/static/photos/Quiz.png)
This project is a quiz built to test the musical knowledge of its participants. Utilizing a front end of `Javascript`,`HTML` and `css`.

`Flask` and `python` is utilized for the back-end.



### 2   |   Inspiration
The inspiration behind the project is Spotify!

Spotify, the music streaming juggernaut, has revolutionized the way we groove to our favorite tunes. With an extensive library boasting millions of songs across genres, it's a digital playground for music lovers. Whether you're into chart-topping hits or obscure indie gems, Spotify's got you covered. Its user-friendly interface and personalized playlists, like Discover Weekly and Daily Mixes, serve up a constant stream of music tailored to individual tastes. The ability to create and share playlists adds a social element to the music experience, turning Spotify into a virtual DJ booth where friends can vibe together. With offline listening options and seamless integration across devices, Spotify has become an indispensable companion for the soundtrack of our lives, offering an endless melody of choices at our fingertips.

 While the amazing platform is vast, I decided to hone inspiration from two key areas. Music as the topic of discussion and its notable color scheme to create an engaging trivia quiz.

 keeping UX (User Experience)in mind, the aesthetics of the application incorporate colors that inform the user of correct and incorrect responses, as well as visual feedback from any clickable element of the application; while keeping with Spotify's color pallet. The result is a questionnaire paired with an appealing dark-mode UI with a focus on client-side usablility.



### 3   |   Visuals
![](/project/static/photos/setup.png)
![](/project/static/photos/hover.png)
Hovering over a button will trigger `css` elements to further stimulation between site and user.


![](/project/static/photos/correct.png)
Upon selection of a correct answer the button will remain `rgb(47, 139, 52)` green. The user will no longer be able to make any additional selections, and a snack bar in `rgb(47, 139, 52)` green will alert the user that their answer indeed was correct. This will trigger their score to be incremented by 1.

![](/project/static/photos/incorrect.png)
Upon selection of an incorrect answer the button will remain the highlited color of `rgb(58, 58, 58)` grey. The user will no longer be able to make any additional selections, and a snack bar in `rgb(182, 42, 42)` red will alert the user that their answer unfortunatlly was incorrect. This will trigger no increment or decrement to their score.



## Paths-
* /static: Contains CSS, Javascript code scripts, and photos for project.

* /templates: Contains all HTML templates for project.

* /app.py: Generates the server side elements to host the project.

* /read.md: Instructional use and information on project.




## Tech Stack-

* Python
* Flask
* HTML/CSS
* Javascript

## Installation-

1) Star and clone the repository to your machine.

2) Run the command: `pip install flask`

3) Once all the dependancies have been installed(flask, python, code files), run the command `flask run`

4) This should start a local server to grant you access to the quiz on your browser.