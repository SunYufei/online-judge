// concatenation
let str1 = "Hello";
let str2 = "World";

// using the + operator
console.log(str1 + str2);   // HelloWorld
console.log(str1 + "Big" + str2);   // HelloBigWorld

// adding space
str1 = "Hello ";

console.log(str1 + str2);   // Hello World
console.log(str1 + "Big " + str2);  // Hello Big World

// be careful with numbers
let num1 = 1;
let num2 = "1";

console.log(num1 + num2);   // 11
console.log(num1 + 1);  // 2

// concatenation with template literals
let str1 = "JavaScript";
let str2 = "fun";

console.log(`I am writing code in ${str1}`);
console.log(`Formatting in ${str1} is ${str2}`);

let bool1 = true;
console.log(`1 + 1 is ${1 + 1}`);
console.log(`The opposite of true is ${!bool1}`);