function rot13(str) {


    let cipher = "";
    
    for(let index = 0; index < str.length; index++){
      let ascii = str[index].charCodeAt();
      if(ascii >= 65 && ascii <= 77){
        cipher += String.fromCharCode(ascii + 13)
      } else if(ascii >= 78 && ascii <= 90){
              cipher += String.fromCharCode(ascii - 13)
      } else{
        cipher += str[index];
      }
    }
      return cipher
    }
    
    console.log(rot13(str))