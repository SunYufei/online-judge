const people = ["Aaron", "Mel", "John"];
// const one = 1;
const one = new Number(1);
const str = "Hello World";
const b = true;
const person = {
    firstName: "Aaron",
    lastName: "Powell",
};

function sayHello(person) {
    console.log("Hello " + person.firstName);
}

console.log("-- typeof --");
console.log(typeof people); // object
console.log(typeof one);    // object
console.log(typeof str);    // string
console.log(typeof b);  // boolean
console.log(typeof person); // object
console.log(typeof sayHello);   // function

console.log("-- instanceof --");
console.log(people instanceof Array);   // true
console.log(one instanceof Number); // true
console.log(str instanceof String); // false
console.log(b instanceof Boolean);  // false
console.log(person instanceof Object);  // true
console.log(sayHello instanceof Function);  // true