#include <iostream>

using namespace std;

int commonchild(string s1, string s2){
    // complete this function
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
    let commonchars = {};
    for (var k in h1) {
        if (h2[k]) {
            commonchars[k] = h1[k];
        }
    }

    let r1 = '';
    let r2 = '';

    for (let i = 0; i < s1.length; i++) {
        if (commonchars[s1[i]]) {
            r1 += s1[i];
        }
    }
    for (let i = 0; i < s2.length; i++) {
        if (commonchars[s2[i]]) {
            r2 += s2[i];
        }
    }

    console.log('s1:', r1);
    console.log('s2:', r2);

    let matr = [];
    for (let i = 0; i < r1.length; i++) {
        matr.push([]);
        for (let j = 0; j < r2.length; j++) {
            if (r1[i] === r2[j]) {
                if (i === 0 || j === 0) {
                    matr[i].push(1);
                } else {
                    let sum = 0;
                    matr[i].push(1);
                }
            } else {
                matr[i].push(0);
            }
        }
    }
    
    let max = 0;
    var recursivemax = function (starti, startj) {
        settimeout(function () {
            if (starti === r1.length-1 || startj === r2.length-1) {
                return matr[i][j];
            }
            for (var i = starti; i < r1.length; i++) {
                for (var j = startj; j < r2.length; j++) {
                    if (matr[i][j] === 1) {
                        return 1 + recursivemax(i, j);
                    }
                }
            }
        }, 0);
    };
    let ret = recursivemax(0, 0);
    console.log('length:', ret);

}
