function palindrome(str) {
    str =  str
        .toLowerCase()
        .replace(/\W|_/ig, "")
if (str === str
            .split("")
            .reverse()
            .join("")
                
                  ){
    return true
} else{
return false
}

}

console.log(palindrome(str));