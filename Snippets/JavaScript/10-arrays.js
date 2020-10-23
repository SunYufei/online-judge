// creating an array
let arrayLength = 5;
let arr1 = [];
let arr2 = Array(arrayLength);

console.log(arr1.length);   // 0
console.log(arr2.length);   // 5

// adding data during creation
let arr1 = ["A", true, 2];
console.log(arr1[0]);   // A
console.log(arr1[1]);   // true

// adding data after creation
let arrayLength = 2;
let arr2 = Array(arrayLength);
arr2[0] = "Value at index 0";
console.log(arr2[0]);   // Value at index 0
console.log(arr2[1]);   // undefined, No value present at index

// length and index
console.log(arr1.length);   // 3
console.log(arr1[3]);   // undefined, Doesn't exist
console.log(arr1[2]);   // 2, Last index of array
console.log(arr1[arr1.length - 1]); // Equals 2

let arr3 = Array(3);    // Empty array of length 3
arr3[2] = "Adding a value!";
console.log(arr3[2]);   // Last index of array 
console.log(arr3[arr3.length - 1]); // Index: 2
console.log(arr3[0]);   // undefined, No value yet
console.log(arr3[1]);   // undefined, No value yet

let arr1 = ["A", true, 2];

// push and pop
console.log(arr1.push("new value"));    // 4
console.log(arr1);  // (4) ["A", true, 2, "new value"]
console.log(arr1.pop()); // new value, Remove last value
console.log(arr1);  // (3) ["A", true, 2]

// shift and unshift
console.log(arr1.unshift("new value")); // 4
console.log(arr1);  // (4) ["A", true, 2, "new value"]
console.log(arr1.shift()); // new value, Remove first value
console.log(arr1);  // (3) ["A", true, 2]

// concat
let arr2 = ["B", false, 3];
let newArr = arr1.concat(arr2);
let newArr2 = arr2.concat([1, 2, 3]);
console.log(newArr);    // (6) ["A", true, 2, "B", false, 3]
console.log(newArr2);   // (6) ["B", false, 3, 1, 2, 3]