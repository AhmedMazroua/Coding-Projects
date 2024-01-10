//Constructs a list of questions
const questions = [
    {
        question: 'Who sings "Billie Jean?"',
        answers: [
            {text:"James Brown", correct:false},
            {text:"Aretha Franklin", correct:false},
            {text:"Prince", correct:false},
            {text:"Michael Jackson", correct:true}
        ]
    },
    {
        question: "Stevie Wonder sang which song?",
        answers: [
            {text:"Total eclipse of the heart", correct:false},
            {text:"Ribbon in the sky", correct:true},
            {text:"Detroit Rockcity", correct:false},
            {text:"P.Y.T", correct:false}
        ]
    },
    {
        question: "Prince's '1999' was apart of what album? ",
        answers: [
            {text:"Purple Rain", correct:true},
            {text:"Bad", correct:false},
            {text:"Diamonds and Pearls", correct:false},
            {text:"Whitney", correct:false}
        ]
    },
    {
        question: "Who is commonly referred to as 'The Queen of Soul?'",
        answers: [
            {text:"Gladus Knight", correct:false},
            {text:"Sade", correct:false},
            {text:"Aretha Franklin", correct:true},
            {text:"Anita Baker", correct:false}
        ]
    },
    {
        question: "Who is commonly referred to as 'The King of Pop?'",
        answers: [
            {text:"Drake", correct:false},
            {text:"Chris Brown", correct:false},
            {text:"Michael Jackson", correct:true},
            {text:"Tpain", correct:false}
        ]
    }
];

const questionElement = document.getElementById("question");
const answerButtons = document.getElementById("answer-buttons");
const nextButton = document.getElementById("next-btn");

let currentQuesIndex = 0;
let score = 0;

// creaates snack bar
function notify(msg, color) {
    // Print message into notification
    var x = document.getElementById("snackbar");
    document.getElementById("snackbar").style.backgroundColor = color;

    x.innerHTML = `${msg}`;

    // Add the "show" class to DIV
    x.className = "show";

    // After 3 seconds, remove the show class from DIV
    setTimeout(function(){ x.className = x.className.replace("show", ""); }, 3000);
  }

  // function to initiate quiz
function startQuiz(){
currentQuesIndex = 0;
 score = 0;
nextButton.innerHTML = "Next";
showQuestion();
}

// lists questions
function showQuestion(){
    resetState();
    let currentQuestion = questions[currentQuesIndex];
    let questionNo = currentQuesIndex + 1;
    questionElement.innerHTML = questionNo + ". " + currentQuestion.question;

    currentQuestion.answers.forEach(answer => {
        const button = document.createElement("button");
        button.innerHTML = answer.text;
        button.classList.add("btn");
        answerButtons.appendChild(button);
        if (answer.correct){
            button.dataset.correct = answer.correct;
        }
        button.addEventListener("click", selectAnswer)
    });
}

// Cleans Slate
function resetState(){
    nextButton.style.display = "none";
    while(answerButtons.firstChild){
        answerButtons.removeChild(answerButtons.firstChild);
    }
}

function selectAnswer(n){
    const selectedBtn = n.target;
    const isCorrect = selectedBtn.dataset.correct === "true";
    if(isCorrect){
        selectedBtn.classList.add("correct");
        score++;
        notify("Correct!", "rgb(47, 139, 52)");
    } else{
        selectedBtn.classList.add("incorrect");
        notify("Incorrect :(", "rgb(182, 42, 42)")
    } Array.from(answerButtons.children).forEach(button => {
        if(button.dataset.correct === "true"){
            button.classList.add("correct");
        }
        button.disabled = "true";
    })
    nextButton.style.display = "block";

}

// Gives score on quiz
function showScore(){
    resetState();
    questionElement.innerHTML = `You scored ${score} out of ${questions.length}!`;
    nextButton.innerHTML = "Play again?";
    nextButton.style.display = "block";
}

// Determines when next button to be shown and when the show score
function handleNextButton(){
    currentQuesIndex++;
    if(currentQuesIndex < questions.length){
        showQuestion();
    }else{
        showScore();
    }
}

nextButton.addEventListener("click", ()=>{
    if (currentQuesIndex < questions.length){
        handleNextButton();
    }else{
        startQuiz();
    }
})
// begins quiz
startQuiz();