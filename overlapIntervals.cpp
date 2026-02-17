function overlapInt(arr) {

    // coordinate → change in active count
    let mp = new Map();

    // mark +1 at start, -1 at end+1
    for (let [start, end] of arr) {
        // start
        mp.set(start, (mp.get(start) || 0) + 1);
        // just after end
        mp.set(end + 1, (mp.get(end + 1) || 0) - 1);
    }

    let ans = 0, count = 0;
    // traverse in sorted coordinate order
    let keys = Array.from(mp.keys()).sort((a, b) => a - b);
    for (let key of keys) {
        count += mp.get(key);
        ans = Math.max(ans, count);
    }

    return ans;
}

// Driver Code
let arr = [
    [1, 8], [2, 5], [5, 6], [3, 7], [6, 10]
];
console.log(overlapInt(arr));
