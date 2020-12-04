let num = '150';
let float = '1.50';

// converting strings to integers
console.log(parseInt('100'));   // 100
console.log(parseInt(num1));    // 1
console.log(parseInt('ABC'));   // NaN
console.log(parseInt('0xF')); // 15 (Hex)

// Converting strings to float
console.log(parseFloat('1.00'));    // 1
console.log(parseFloat(float)); // 1.5
console.log(parseFloat('ABC')); // NaN

// Numbers after special characters are ignored
console.log(parseInt('1.5'));   // 1
console.log(parseInt('1 + 1')); // 1

// Using Template Literals
console.log(parseInt(`${1 + 1}`));  // 2

// Converting numbers to strings
console.log(num.toString());    // 150
console.log(float.toString());  // 1.50
console.log((100).toString());  // 100