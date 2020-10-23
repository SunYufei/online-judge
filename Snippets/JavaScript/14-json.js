const book = new Object({
    title: "1984",
    author: "George Orwell"
});
console.log(typeof book);
console.log(book);

// You can also have a collection of these objects
const myBooks = [
    new Object({ title: "1984", author: "George Orwell" }),
    new Object({ title: "Becoming", author: "Michelle Obama" }),
    new Object({ title: "Snow Crash", author: "Neal Stephenson" }),
    new Object({ title: "Predictably Irrational", author: "Dan Ariely" })
];
console.log(typeof myBooks);    // object
console.log(myBooks);

// JSON.stringify - object input
let bookJSON = JSON.stringify(book);
console.log(typeof bookJSON);   // string
console.log(bookJSON);  // {"title":"1984","author":"G. Orwell","isAvailable":false}

// JSON.stringify - collection input
let myBooksJSON = JSON.stringify(myBooksJSON);
console.log(myBooksJSON);   // [{"title":"1984","author":"George Orwell"},{"title":"Becoming","author":"Michelle Obama"},{"title":"Snow Crash","author":"Neal Stephenson"},{"title":"Predictably Irrational","author":"Dan Ariely"}]

// JSON.parse - string input
let data = bookJSON;
let parsed = JSON.parse(data);
console.log(parsed);    // {title: "1984", ...} (object)
console.log(Array.isArray(parsed)); // false
console.log(`Num items: ${parsed.length}`); // undefined

// JSON.parse - string input
data = myBooksJSON;
parsed = JSON.parse(data);
console.log(parsed);    // (4) [{...}, {...}, ...] (array)
console.log(Array.isArray(parsed)); // true
console.log(`Num items: ${parsed.length}`); // 4
console.log(`Author of 2nd book: ${parsed[1].author}`); // Michelle Obama