
// Number.MAX_SAFE_INTEGER
// 9007199254740991
module.exports = function calculate(str1, operation, str2) {

  if (str1.length < 16 && str2.length < 16) {
    return operation === '-' 
      ? String((Number(str1) - Number(str2)))
      : String((Number(str1) + Number(str2)))
  }

  // 分段相加，低位分组在前
  const SAFE_LENGTH = 15
  let carry = 0
  let num1 = str2Array(str1, SAFE_LENGTH)
  let num2 = str2Array(str2, SAFE_LENGTH)
  let summary = []

  while (num1.length || num2.length) {
    let temp1 = num1.length ? num1.shift() : 0
    let temp2 = num2.length ? num2.shift() : 0

    switch (operation) {
      case '-':
        [carry, summary[summary.length]] = minusCale(temp1, temp2, carry, SAFE_LENGTH)
        break
      case '+':
        [carry, summary[summary.length]] = plusCale(temp1, temp2, carry, SAFE_LENGTH)
        break
    }
  }

  if (carry && operation === '+') {
    summary.push(1)
  }

  return summary.reduce((prev, next) => {
    return next + (typeof prev === 'undefined' ? '' : prev)
  }, '')
}

/**
 * 
 * @param {String} str
 * @param {Number} len 
 * @returns {Array<String>}
 */
function str2Array(str, len) {
  let times = Math.ceil(str.length / len)
  let arr = []

  for (let i = 1; i <= times; i++) {
    
    arr.push(
      str.slice(
        (str.length - i * len) < 0
          ? 0
          : (str.length - i * len),

        str.length - i * len + len
      )
    )

  }

  return arr
}

/**
 * @typedef CalculateResultParams
 * @property {Number} 0
 * @property {String} 1
 * 
 * 
 * @param {String} a 
 * @param {String} b 
 * @param {Number} carry 
 * @param {Number} len 
 * @returns {CalculateResultParams}
 */
function minusCale(a, b, carry, len) {

  let result = Number(a) - Number(b) - carry

  carry = result < 0 ? 1 : 0
  result = carry ? result + 10 ** len : result

  return [carry, result === 0 ? '0'.repeat(len) : result + '']
}

/**
 * 
 * @param {String} a 
 * @param {String} b 
 * @param {Number} carry 
 * @param {Number} len 
 * @returns {CalculateResultParams}
 */
function plusCale(a, b, carry, len) {
  let result = Number(a) + Number(b) + carry

  carry = (result >= 10 ** len) ? 1 : 0
  result = (result >= 10 ** len) ? (result - 10 ** len) : result

  return [carry, result === 0 ? '0'.repeat(len) : (result + '')]
}
