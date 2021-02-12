function commonChild(s1, s2){
    // Complete this function
    let h1 = {};
    let h2 = {};
    for (let i = 0; i < s1.length; i++) {
        if (!h1[s1[i]]) {
            h1[s1[i]] = 0;
        }
        h1[s1[i]] += 1;
    }
    for (let i = 0; i < s2.length; i++) {
        if (!h2[s2[i]]) {
            h2[s2[i]] = 0;
        }
        h2[s2[i]] += 1;
    }
    let commonChars = {};
    for (var k in h1) {
        if (h2[k]) {
            commonChars[k] = h1[k];
        }
    }

    let r1 = '';
    let r2 = '';

    for (let i = 0; i < s1.length; i++) {
        if (commonChars[s1[i]]) {
            r1 += s1[i];
        }
    }
    for (let i = 0; i < s2.length; i++) {
        if (commonChars[s2[i]]) {
            r2 += s2[i];
        }
    }

    console.log('S1:', r1);
    console.log('S2:', r2);
    r1 = ' ' + r1;
    r2 = ' ' + r2;

    let matr = new Array(r1.length);
    for (let i = 0; i < r1.length; i++) {
        matr[i] = new Array(r2.length);
        matr[i].fill(0);
    }
    let max = 0;

    for (let i = 1; i < r1.length; i++) {
        for (let j = 1; j < r2.length; j++) {
            if (r1[i] === r2[j]) {
                if (i === 1 || j === 1) {
                    matr[i][j] = 1;
                } else {
                    matr[i][j] = matr[i-1][j-1] + 1;
                }
                if (matr[i][j] > max) {
                    max = matr[i][j];
                }
            } else {
                matr[i][j] = Math.max(matr[i-1][j], matr[i][j-1]);
            }
        }
    }
    console.log(matr);
    return max;
}
var s1 = 'ABCDEF';
var s2 = 'FBDAMN';
var result = commonChild(s1, s2);
process.stdout.write("" + result + "\n");
