// simple object
const blank = {};
console.log(`black type: ${typeof blank}`); // object
console.log(`black value: ${blank}`);   // {}

// object with properties
const book = {
    title: '1984',
    author: 'Georage Orwell',
    isAvailable: false
};
console.log(`Book type: ${typeof book}`);   // object
console.log(`book value:\n${book}`);    // {title: ...}

// object with function properties
const book = {
    title: "1984",
    author: "George Orwell",
    isAvailable: false,
    checkIn: function () { this.isAvailable = true; },
    checkOut: function () { this.isAvailable = false; }
};
console.log(`Book type: ${typeof book}`);
console.log(`Book value:\n${book}`);

// create object using object literals
const book = new Object();
console.log(`Book type: ${typeof book}`);
console.log(`Book value:\n${book}`);

const data = { title: "1984", author: "George Orwell" };
const newBook = new Object(data);

console.log(book.author);
console.log(book['author']);

book.author = "G. Orwell";
console.log(book);

book.checkIn();
console.log(book.isAvailable);

// this
const bookObj = {
    checkIn: function () {
        return this;
    }
}
console.log(`this is: ${bookObj.checkIn()}`);   // this is: {checkIn: f}
console.log(bookObj.checkIn() === bookObj); // true

function anotherCheckIn() {
    return this;
}
console.log(`this is: ${anotherCheckIn()}`);    // this is: [object Window]
console.log(anotherCheckIn() === globalThis);   // true
