const now = new Date();
const win95Launch = new Date(1995, 7, 24);

console.log(now);   // Fri Oct 23 2020 20:07:04 GMT+0800 (中国标准时间)
console.log(win95Launch);   // Thu Aug 24 1995 00:00:00 GMT+0800 (中国标准时间)

const demoDate = new Date();
demoDate.setMonth(0);   // month start from 0
console.log(demoDate);  // Thu Jan 23 2020 20:07:04 GMT+0800 (中国标准时间)

console.log(`Day of week: ${demoDate.getDay()}`);   // 4
console.log(`Date: ${demoDate.getDate()}`); // 23