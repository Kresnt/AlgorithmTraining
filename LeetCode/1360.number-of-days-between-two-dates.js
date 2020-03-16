/**
 * @param {string} date1
 * @param {string} date2
 * @return {number}
 */
var daysBetweenDates = function(date1, date2) {
    let s = new Date(date1);
    let t = new Date(date2);
    let tim = t-s;
    return  Math.abs(Math.floor(tim/(24*3600*1000)));
};