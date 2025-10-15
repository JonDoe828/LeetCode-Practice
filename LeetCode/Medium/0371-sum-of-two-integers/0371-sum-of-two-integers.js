/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function (a, b) {
    while (b !== 0) {
        const carry = (a & b) << 1; // 进位
        a = a ^ b;                  // 无进位和
        b = carry;                  // 把进位继续相加
    }
    return a;
};