//converts number to roman numeral

function convertToRoman(num) {

    var rome = {
      "M": 1000,
      "CM": 900,
      "D": 500,
      "CD": 400,
      "C": 100,
      "XC": 90,
      "L": 50,
      "XL": 40,
      "X": 10,
      "IX": 9,
      "V": 5,
      "IV": 4,
      "I": 1
    };
    var log = "";
    
      for (var romans in rome){
        while(num >= rome[romans]){
          log += romans;
          num-= rome[romans];
        }
      }
    return log;
    }
    
    console.log(convertToRoman(num));